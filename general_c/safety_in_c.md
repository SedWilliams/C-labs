
# Safety or lack therof in C

## Intro

Consider the following C code snippet:

```c

#include <stdio.h>

void unsafe_type_mismatch() {

    int num1 = 42;
    int num2 = 67;

    printf("These are totally two strings: (%s, %s)", num1, num2);
}
```

When put into GCC this code will compile run even though there is an obvious type mismatch error.

The C compiler will spit out a warning but will not terminate the program during compilation
even if that means the program will certainly crash during runtime.

This is due to C philosophy which really believes in leaving things up to the programmer, and 
not providing any tight guardrails.

While __undefined__ behavior is considered an error, __unspecified__ behavior is left up to the programmer.

## Expect all input to be dangerous (program safely)
