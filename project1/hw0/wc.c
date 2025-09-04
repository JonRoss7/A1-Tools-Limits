#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    if (argc < 2) {
        fp = stdin;  // no file, read from standard input
    } else {
        fp = fopen(argv[1], "r");
        if (!fp) {
            perror("Error opening file");
            return 1;
        }
    }

    int c;
    int lines = 0;
    int words = 0;
    int chars = 0;
    int in_word = 0;

    while ((c = fgetc(fp)) != EOF) {
        chars++;

        if (c == '\n') lines++;

        if (isalpha(c)) {
            if (!in_word) {
                in_word = 1;
                words++;
            }
        } else {
            in_word = 0;
        }
    }

    if (fp != stdin) fclose(fp);

    printf("%d %d %d\n", lines, words, chars);
    return 0;
}
