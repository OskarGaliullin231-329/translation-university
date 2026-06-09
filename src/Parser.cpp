#include "../include/Parser.h"

#include <algorithm>
#include <array>
#include <string>

Parser::Parser(std::shared_ptr<ASTNode> root_node) {
    _root_node = root_node;
}

bool Parser::parse(const std::list<std::pair<std::string, TokenType>>& tokens_list) {
    if (!_root_node) {
        return false;
    }

    bool result = true;
    _tkns_vctr.reserve(tokens_list.size());
    for (const auto& pr : tokens_list) { _tkns_vctr.push_back(pr); }

    std::array<std::string, 5> types {
        "void", "int", "float", "double", "char"
    };
    std::array<std::string, 4> type_specifiers {
        "long", "short", "signed", "unsigned"
    };
    std::array<std::string, 5> variable_specifiers {
        "const", "static", "volatile", "extern", "register"
    };
    std::array<std::string, 2> type_wrapers {
        "union", "auto"
    };
    std::array<std::string, 3> switch_case_keywords {
        "switch", "case", "default"
    };
    std::array<std::string, 2> condition_keywords {
        "if", "else"
    };
    std::array<std::string, 3> loop_keywords {
        "for", "while", "do"
    };
    std::array<std::string, 2> loop_management_keywords {
        "break", "continue"
    };
    std::array<std::string, 3> type_declaration_keywords {
        "struct", "typedef", "enum"
    };
    std::array<std::string, 3> other_keywords {
        "return", "goto", "sizeof"
    };
    std::array<std::string, 5> arith_operators {
        "+", "-", "*", "/", "%"
    };
    std::array<std::string, 3> logic_operators {
        "!", "&&", "||"
    };
    std::array<std::string, 6> bitwise_operators {
        "&", "|", "^", "~", "<<", ">>"
    };
    std::array<std::string, 2> inc_dec_operators {
        "++", "--"
    };
    std::array<std::string, 5> assign_arithmetic_operators {
        "+=", "-=", "*=", "/=", "%="
    };
    std::array<std::string, 5> assign_bitwise_operators {
        "&=", "|=", "^=", "<<=", ">>="
    };
    std::array<std::string, 2> ternary_operators {
        "?", ":"
    };
    std::array<std::string, 2> struct_operators {
        ".", "->"
    };

    auto isAny = [&](const std::string& value, const auto& set) {
        return std::find(set.begin(), set.end(), value) != set.end();
    };

    auto createTypeNode = [&](std::size_t first_index, std::size_t last_index) {
        auto node = std::make_shared<BaseTp>();
        node->setFirstTokenIndex(first_index);
        node->setLastTokenIndex(last_index);
        return node;
    };

    auto createIDExpr = [&](std::size_t index) {
        auto node = std::make_shared<IDExpr>();
        node->setTokenIndex(index);
        return node;
    };

    auto createLITExpr = [&](std::size_t index) {
        auto node = std::make_shared<LITExpr>();
        node->setTokenIndex(index);
        return node;
    };

    auto createOperatorExpr = [&](const std::string& op, std::size_t /*index*/) {
        if (isAny(op, arith_operators)) {
            return std::static_pointer_cast<Expression>(std::make_shared<ArithExpr>());
        }
        if (isAny(op, logic_operators)) {
            return std::static_pointer_cast<Expression>(std::make_shared<LogicExpr>());
        }
        if (isAny(op, bitwise_operators)) {
            return std::static_pointer_cast<Expression>(std::make_shared<BitwiseExpr>());
        }
        if (isAny(op, inc_dec_operators) || op == "*") {
            return std::static_pointer_cast<Expression>(std::make_shared<PointerExpr>());
        }
        if (isAny(op, assign_arithmetic_operators) || isAny(op, assign_bitwise_operators) || op == "=") {
            return std::static_pointer_cast<Expression>(std::make_shared<AssignExpr>());
        }
        if (isAny(op, struct_operators)) {
            return std::static_pointer_cast<Expression>(std::make_shared<StructExpr>());
        }
        return std::make_shared<Expression>();
    };

    auto createExpressionStatement = [&](std::shared_ptr<Expression> expression) {
        auto statement = std::make_shared<ExprStat>();
        if (expression) {
            statement->addChild(expression);
        }
        return statement;
    };

    auto attachNode = [&](std::shared_ptr<ASTNode> node) {
        if (!_root_node) {
            return;
        }
        if (node) {
            _root_node->addChild(node);
        }
    };

    std::vector<std::shared_ptr<ASTNode>> block_stack;
    block_stack.push_back(_root_node);
    std::shared_ptr<ASTNode> last_statement = nullptr;

    auto currentBlock = [&]() {
        return block_stack.empty() ? _root_node : block_stack.back();
    };

    auto pushBlock = [&](std::shared_ptr<CodeBlock> block) {
        if (!block) {
            return;
        }
        if (last_statement) {
            last_statement->addChild(block);
            last_statement.reset();
        } else {
            currentBlock()->addChild(block);
        }
        block_stack.push_back(block);
    };

    auto popBlock = [&]() {
        if (block_stack.size() > 1) {
            block_stack.pop_back();
        }
    };

    auto parseTypePrefix = [&](std::size_t index) {
        std::size_t type_end = index;
        while (type_end < _tkns_vctr.size()) {
            const auto& token_value = _tkns_vctr[type_end].first;
            const auto token_type = _tkns_vctr[type_end].second;
            if (token_type != TokenType::KEY) {
                break;
            }
            if (isAny(token_value, types)
                || isAny(token_value, type_specifiers)
                || isAny(token_value, variable_specifiers)
                || isAny(token_value, type_wrapers)) {
                ++type_end;
                continue;
            }
            break;
        }
        return type_end;
    };

    for (std::size_t i = 0; i < _tkns_vctr.size(); ++i) {
        const auto& token = _tkns_vctr[i].first;
        const auto token_type = _tkns_vctr[i].second;

        if (token_type == TokenType::DEL) {
            if (token == "{") {
                pushBlock(std::make_shared<CodeBlock>());
                continue;
            }
            if (token == "}") {
                popBlock();
                continue;
            }
            continue;
        }

        if (token_type == TokenType::KEY) {
            if (token == "if") {
                auto statement = std::make_shared<IfStat>();
                statement->setTokenIndex(i);
                currentBlock()->addChild(statement);
                last_statement = statement;
                continue;
            }
            if (token == "else") {
                if (i + 1 < _tkns_vctr.size() && _tkns_vctr[i + 1].first == "if") {
                    auto statement = std::make_shared<ElseIfStat>();
                    statement->setIfIndex(i);
                    statement->setElseIndex(i + 1);
                    currentBlock()->addChild(statement);
                    last_statement = statement;
                    ++i;
                    continue;
                }
                auto statement = std::make_shared<ElseStat>();
                statement->setTokenIndex(i);
                currentBlock()->addChild(statement);
                last_statement = statement;
                continue;
            }
            if (isAny(token, loop_keywords)) {
                if (token == "for") {
                    auto statement = std::make_shared<ForStat>();
                    statement->setTokenIndex(i);
                    currentBlock()->addChild(statement);
                    last_statement = statement;
                    continue;
                }
                if (token == "while") {
                    auto statement = std::make_shared<WhileStat>();
                    statement->setTokenIndex(i);
                    currentBlock()->addChild(statement);
                    last_statement = statement;
                    continue;
                }
                if (token == "do") {
                    auto statement = std::make_shared<DoWhileStat>();
                    statement->setDoIndex(i);
                    currentBlock()->addChild(statement);
                    last_statement = statement;
                    continue;
                }
            }
            if (isAny(token, type_declaration_keywords)) {
                if (token == "struct") {
                    auto decl = std::make_shared<StructDecl>();
                    decl->setTokenIndex(i);
                    currentBlock()->addChild(decl);
                    last_statement = decl;
                    continue;
                }
                if (token == "typedef") {
                    auto decl = std::make_shared<TypeDecl>();
                    decl->setTokenIndex(i);
                    currentBlock()->addChild(decl);
                    last_statement = decl;
                    continue;
                }
                if (token == "enum") {
                    auto decl = std::make_shared<Declaration>();
                    currentBlock()->addChild(decl);
                    last_statement = decl;
                    continue;
                }
            }
            if (isAny(token, types) || isAny(token, type_specifiers)
                || isAny(token, variable_specifiers) || isAny(token, type_wrapers)) {
                const auto type_end = parseTypePrefix(i);
                if (type_end < _tkns_vctr.size() && _tkns_vctr[type_end].second == TokenType::ID) {
                    auto decl = std::make_shared<VarDecl>();
                    auto type_node = createTypeNode(i, type_end - 1);
                    decl->addChild(type_node);
                    decl->addChild(createIDExpr(type_end));
                    currentBlock()->addChild(decl);
                    last_statement = decl;
                    i = type_end;
                    continue;
                }
                currentBlock()->addChild(std::make_shared<Declaration>());
                last_statement = nullptr;
                i = type_end > 0 ? type_end - 1 : i;
                continue;
            }
            if (isAny(token, other_keywords)) {
                auto statement = std::make_shared<ExprStat>();
                statement->addChild(createIDExpr(i));
                currentBlock()->addChild(statement);
                last_statement = statement;
                continue;
            }
        }

        if (token_type == TokenType::ID) {
            std::shared_ptr<Expression> expression;
            if (i + 1 < _tkns_vctr.size() && _tkns_vctr[i + 1].first == "(") {
                auto call = std::make_shared<CallExpr>();
                call->setTokenIndex(i);
                expression = call;
            } else {
                expression = createIDExpr(i);
            }
            currentBlock()->addChild(createExpressionStatement(expression));
            last_statement = nullptr;
            continue;
        }

        if (token_type == TokenType::LIT) {
            currentBlock()->addChild(createExpressionStatement(createLITExpr(i)));
            last_statement = nullptr;
            continue;
        }

        if (token_type == TokenType::OP) {
            currentBlock()->addChild(createExpressionStatement(createOperatorExpr(token, i)));
            last_statement = nullptr;
            continue;
        }

        if (token_type == TokenType::DEL) {
            continue;
        }

        currentBlock()->addChild(std::make_shared<Statement>());
        last_statement = nullptr;
    }

    return result;
}
