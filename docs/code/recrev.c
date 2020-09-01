#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void recur();

int main( ) {
        recur();
        putchar('\n');
        return 0;
}

void recur() {
        char c = getchar();
        if (c != EOF) {
                recur();
                putchar(c);
        }
}

