#include <stdio.h>

void some_function() {
    prinrf("some_function was called.\n");
}

typedef struct {
    int id;
} SomeStruct;

// entry point of the program
int main() {
    /* 
    let's declare some variables
    */
    int a=2;
    int b=3;
    int result;

    result = a + b; // and let's see summation result
    
    printf("%d", result==a+b);

    some_function();

    SomeStruct s_s;
    s_s.id = 0;

    return 0;
}
