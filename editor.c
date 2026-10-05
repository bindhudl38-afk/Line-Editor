#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

void display() {
    int i;

    if (lineCount == 0) {
        printf("Document is empty.\n");
        return;
    }

    printf("\n----- Document -----\n");

    for (i = 0; i < lineCount; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

void insertLine(int position, char text[]) {
    int i;

    if (lineCount >= MAX_LINES) {
        printf("Document is full.\n");
        return;
    }

    if (position < 1 || position > lineCount + 1) {
        printf("Invalid line number.\n");
        return;
    }

    for (i = lineCount; i >= position; i--) {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[position - 1], text);
    lineCount++;

    printf("Line inserted successfully.\n");
}

void deleteLine(int position) {
    int i;

    if (position < 1 || position > lineCount) {
        printf("Invalid line number.\n");
        return;
    }

    for (i = position - 1; i < lineCount - 1; i++) {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

void showHelp() {
    printf("\n----- HELP -----\n");
    printf("I <line> <text> : Insert a line\n");
    printf("D <line>        : Delete a line\n");
    printf("P               : Display document\n");
    printf("H               : Show help\n");
    printf("E               : Exit editor\n");
    printf("----------------\n");
}

int main() {
    char command;
    int position;
    char text[MAX_LENGTH];

    printf("===== SIMPLE LINE EDITOR =====\n");
    printf("Type H for help.\n");

    while (1) {
        printf("\n> ");

        scanf(" %c", &command);

        if (command == 'I' || command == 'i') {

            scanf("%d", &position);
            getchar();

            fgets(text, MAX_LENGTH, stdin);
            text[strcspn(text, "\n")] = '\0';

            insertLine(position, text);
        }

        else if (command == 'D' || command == 'd') {

            scanf("%d", &position);

            deleteLine(position);
        }

        else if (command == 'P' || command == 'p') {

            display();
        }

        else if (command == 'H' || command == 'h') {

            showHelp();
        }

        else if (command == 'E' || command == 'e') {

            printf("Exiting editor...\n");
            break;
        }

        else {
            printf("Unknown command. Type H for help.\n");
        }
    }

    return 0;
}