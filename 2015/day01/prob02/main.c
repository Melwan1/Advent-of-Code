#include <stdio.h>

int get_parenthesis_conversion(char c) {
    if (c == ')')
        return -1;
    if (c == '(')
        return 1;
    return 0;
}

int main(void) {
    FILE* file = fopen("../input.txt", "r");
    if (!file)
        return 1;
    char current_char;
    int current_position = 1; // indexed at 1...
    int current_floor = 0;
    while ((current_char = fgetc(file)) != EOF) {
        current_floor += get_parenthesis_conversion(current_char);       
        if (current_floor < 0) {
            printf("Attained basement at position %d\n", current_position);
            break;
        }
        current_position++;
    }
    fclose(file);
    printf("Attained floor %d\n", current_floor);
    return 0;
}
