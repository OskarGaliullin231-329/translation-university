#include "../include/parser.h"
#include "../include/Expression.h"
#include "../include/Statement.h"
#include "../include/StatementDerivatives.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

typedef std::list<std::pair<std::string, TokenType>> tokens_list;
typedef std::vector<std::pair<std::string, TokenType>> tokens_vector;

static const std::unordered_set<std::string> keys_type_names {
    "void",
    "int",
    "float",
    "double",
    "char"
};
static const std::unordered_set<std::string> keys_type_specs {
    "long",
    "short",
    "signed",
    "unsigned"
};
static const std::unordered_set<std::string> keys_var_specs {
    "const",
    "static",
    "volatile",
    "extern",
    "register"
};
static const std::unordered_set<std::string> keys_type_wraps {
    "union",
    "auto"
};
static const std::unordered_set<std::string> keys_type_decl {
    "struct",
    "typedef",
    "enum"
};
static const std::unordered_set<std::string> keys_statements {
    "switch",
    "case",
    "default",
    "if",
    "else",
    "for",
    "while",
    "do",
    "break",
    "continue",
    "return",
    "goto"
};

class Parser {
public:
    Parser(const tokens_vector& tokens, std::shared_ptr<ASTNode> root)
        : _tokens(tokens), _root(root), _pos(0)
    {}

    void parseTranslationUnit() {
        while (!eof()) {
            if (matchText(";")) {
                continue;
            }
            if (startsDeclaration()) {
                parseDeclaration(_root);
            } else {
                parseStatement(_root);
            }
        }
    }

private:
    const tokens_vector& _tokens;
    std::shared_ptr<ASTNode> _root;
    std::size_t _pos;

    bool eof() const {
        return _pos >= _tokens.size();
    }

    const std::pair<std::string, TokenType>& peek(std::size_t offset = 0) const {
        static const std::pair<std::string, TokenType> empty{"", TokenType::ID};
        return (_pos + offset < _tokens.size()) ? _tokens[_pos + offset] : empty;
    }

    bool matchText(const std::string& text) {
        if (eof()) {
            return false;
        }
        if (peek().first == text) {
            _pos++;
            return true;
        }
        return false;
    }

    bool matchType(TokenType type) {
        if (eof()) {
            return false;
        }
        if (peek().second == type) {
            _pos++;
            return true;
        }
        return false;
    }

    bool startsDeclaration() const {
        if (eof()) {
            return false;
        }
        const auto& token = peek();
        if (token.second != TokenType::KEY) {
            return false;
        }
        if (keys_type_names.count(token.first) > 0
            || keys_type_specs.count(token.first) > 0
            || keys_var_specs.count(token.first) > 0
            || keys_type_wraps.count(token.first) > 0
            || keys_type_decl.count(token.first) > 0
            || token.first == "typedef") {
            return true;
        }
        return false;
    }

    bool isFunctionDeclarator(std::size_t start, std::size_t end) const {
        int depth = 0;
        for (std::size_t i = start; i < end; ++i) {
            const std::string& text = _tokens[i].first;
            if (text == "(") {
                if (depth == 0) {
                    if (i == start) {
                        return false;
                    }
                    const std::string& prev = _tokens[i - 1].first;
                    if (prev == "*" || prev == "," || prev == "(" || prev == "[") {
                        return false;
                    }
                }
                depth++;
            } else if (text == ")") {
                if (depth > 0) {
                    depth--;
                }
            }
        }
        return depth == 0 && end > start && _tokens[end - 1].first == ")";
    }

    std::string collectTokensUntil(const std::unordered_set<std::string>& terminators) {
        std::ostringstream buffer;
        int depth = 0;
        bool first = true;

        while (!eof()) {
            const auto& [text, type] = peek();
            if (text == "(" || text == "[" || text == "{") {
                depth++;
            }
            if (text == ")" || text == "]" || text == "}") {
                depth = std::max(0, depth - 1);
            }
            if (depth == 0 && terminators.count(text) > 0) {
                break;
            }
            if (!first) {
                buffer << ' ';
            }
            buffer << text;
            first = false;
            _pos++;
        }
        return buffer.str();
    }

    std::shared_ptr<Expression> makeExpressionNode(const std::string& value) {
        auto node = std::make_shared<Expression>();
        node->setValue(value);
        return node;
    }

    void parseDeclaration(std::shared_ptr<ASTNode> parent) {
        std::size_t startIndex = _pos;
        std::string declaration = collectTokensUntil({";", "{"});
        if (declaration.empty()) {
            return;
        }

        bool isFunction = isFunctionDeclarator(startIndex, _pos);
        bool isTypedef = (startIndex < _tokens.size() && _tokens[startIndex].first == "typedef");

        if (matchText("{")) {
            auto body = parseCompoundStatement();
            if (isTypedef) {
                auto node = std::make_shared<Typedef>();
                node->setValue(declaration);
                node->appendChild(body);
                parent->appendChild(node);
            } else if (isFunction) {
                auto node = std::make_shared<FuncDef>();
                node->setValue(declaration);
                node->appendChild(body);
                parent->appendChild(node);
            } else {
                auto node = std::make_shared<VarDecl>();
                node->setValue(declaration);
                node->appendChild(body);
                parent->appendChild(node);
            }
            if (matchText(";")) {
                return;
            }
            return;
        }

        if (matchText(";")) {
            std::shared_ptr<Statement> node;
            if (isTypedef) {
                node = std::make_shared<Typedef>();
            } else if (isFunction) {
                node = std::make_shared<FuncDecl>();
            } else if (declaration.find('=') != std::string::npos) {
                node = std::make_shared<VarInit>();
            } else {
                node = std::make_shared<VarDecl>();
            }
            node->setValue(declaration);
            parent->appendChild(node);
            return;
        }
    }

    std::shared_ptr<ASTNode> parseCompoundStatement() {
        auto block = std::make_shared<Statement>();
        block->setValue("compound");
        while (!eof() && !matchText("}")) {
            if (matchText(";")) {
                continue;
            }
            if (startsDeclaration()) {
                parseDeclaration(block);
            } else {
                parseStatement(block);
            }
        }
        return block;
    }

    std::shared_ptr<Expression> parseParenthesizedExpression() {
        if (!matchText("(")) {
            return makeExpressionNode("");
        }
        std::string expression = collectTokensUntil({")"});
        matchText(")");
        return makeExpressionNode(expression);
    }

    void parseStatement(std::shared_ptr<ASTNode> parent) {
        if (matchText("{")) {
            parent->appendChild(parseCompoundStatement());
            return;
        }

        if (matchText("if")) {
            auto node = std::make_shared<IfCond>();
            node->setValue("if");
            node->appendChild(parseParenthesizedExpression());
            parseStatement(node);
            if (matchText("else")) {
                auto elseNode = std::make_shared<ElseCond>();
                elseNode->setValue("else");
                parseStatement(elseNode);
                node->appendChild(elseNode);
            }
            parent->appendChild(node);
            return;
        }

        if (matchText("switch")) {
            auto node = std::make_shared<Switch>();
            node->setValue("switch");
            node->appendChild(parseParenthesizedExpression());
            parseStatement(node);
            parent->appendChild(node);
            return;
        }

        if (matchText("for")) {
            auto node = std::make_shared<For>();
            node->setValue("for");
            matchText("(");
            std::string init = collectTokensUntil({";"});
            matchText(";");
            std::string cond = collectTokensUntil({";"});
            matchText(";");
            std::string iter = collectTokensUntil({")"});
            matchText(")");
            if (!init.empty()) {
                node->appendChild(makeExpressionNode(init));
            }
            if (!cond.empty()) {
                node->appendChild(makeExpressionNode(cond));
            }
            if (!iter.empty()) {
                node->appendChild(makeExpressionNode(iter));
            }
            parseStatement(node);
            parent->appendChild(node);
            return;
        }

        if (matchText("while")) {
            auto node = std::make_shared<While>();
            node->setValue("while");
            node->appendChild(parseParenthesizedExpression());
            parseStatement(node);
            parent->appendChild(node);
            return;
        }

        if (matchText("do")) {
            auto node = std::make_shared<Do>();
            node->setValue("do");
            parseStatement(node);
            if (matchText("while")) {
                auto expr = parseParenthesizedExpression();
                node->appendChild(expr);
                matchText(";");
            }
            parent->appendChild(node);
            return;
        }

        if (matchText("return")) {
            auto node = std::make_shared<Return>();
            node->setValue("return");
            std::string expression = collectTokensUntil({";"});
            matchText(";");
            if (!expression.empty()) {
                node->appendChild(makeExpressionNode(expression));
            }
            parent->appendChild(node);
            return;
        }

        if (matchText("break") || matchText("continue")) {
            const std::string kind = _tokens[_pos - 1].first;
            auto node = std::make_shared<LoopMngrs>();
            node->setValue(kind);
            matchText(";");
            parent->appendChild(node);
            return;
        }

        if (matchText("goto")) {
            std::string target;
            if (!eof() && peek().second == TokenType::ID) {
                target = peek().first;
                _pos++;
            }
            auto node = std::make_shared<Goto>();
            node->setValue(target);
            matchText(";");
            parent->appendChild(node);
            return;
        }

        if (peek().second == TokenType::ID && peek(1).first == ":") {
            auto label = peek().first;
            _pos += 2;
            auto node = std::make_shared<GTFlag>();
            node->setValue(label);
            parseStatement(node);
            parent->appendChild(node);
            return;
        }

        if (matchText("case")) {
            auto label = collectTokensUntil({":"});
            matchText(":");
            auto node = std::make_shared<SwCase>();
            node->setValue(label);
            parseStatement(node);
            parent->appendChild(node);
            return;
        }

        if (matchText("default")) {
            matchText(":");
            auto node = std::make_shared<SwDefault>();
            node->setValue("default");
            parseStatement(node);
            parent->appendChild(node);
            return;
        }

        if (matchText(";")) {
            return;
        }

        std::string expression = collectTokensUntil({";"});
        matchText(";");
        if (!expression.empty()) {
            auto node = std::make_shared<ExpresStat>();
            node->setValue(expression);
            parent->appendChild(node);
        }
    }
};

void parse(const tokens_list& tkns_lst, std::shared_ptr<ASTNode> ast_root) {
    tokens_vector tokens;
    tokens.reserve(tkns_lst.size());
    std::copy(tkns_lst.begin(), tkns_lst.end(), std::back_inserter(tokens));
    Parser parser(tokens, ast_root);
    parser.parseTranslationUnit();
}
