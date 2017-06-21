#include <stdio.h>

// Needed to verify results.
int mac_c(int a, int b, int c) {
    a += b * c; // Semantically, it is "mac"
    return a;
}

// Should not be inlined, because we expect arguments
// in particular registers.
__attribute__((noinline))
int mac_asm(int a, int b, int c) {
    asm __volatile__ (".word 0x02C5856B\n");
    return a;
}

int main(int argc, char** argv) {
    int a = 2;
    int b = 3;
    int c = 4;
    printf("%d =?= %d\n", mac_c(a, b, c), mac_asm(a, b, c));
    return 0;
}
