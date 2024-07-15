#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char buffer[256];
    int lines = 0, words = 0, chars = 0;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        lines++;
        chars += strlen(buffer);
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == ' ' || buffer[i] == '\n') {
                words++;
            }
        }
    }

    fclose(file);

    // Adjusting for the last word
    if (chars > 0) words++;

    printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);

    return 0;
}