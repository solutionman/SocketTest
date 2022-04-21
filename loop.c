#include <stdio.h>
#include <string.h>

int main() {
    while (1 == 1) {
        char string[256];
        printf("print something: ");
        scanf("%s", string);
        printf("you entered: %s\n", string);
        char *some = string;
        printf("some string: %s\n", some);
        if (strcmp(string, ":q") == 0) return 0;
    }
}