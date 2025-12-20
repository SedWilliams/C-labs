#include <unistd.h>
#include <stdio.h>

void main() {
    write(1, "Hello, World!\n", 14);
    printf("Hello, World!\n");
}

