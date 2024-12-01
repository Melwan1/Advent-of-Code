#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

struct point_list {
    struct point head;
    struct point_list* next;
};

struct point_list* point_list_new() {
    struct point_list* point_list = malloc(sizeof(struct point_list));
    if (!point_list)
        return NULL;
    return point_list;
}

void point_list_free(struct point_list* point_list) {
    if (!point_list)
        return;
    point_list_free(point_list->next);
    free(point_list);
}

struct point_list* point_list_prepend(struct point_list* point_list, struct point element) {
    // if an element in the list is equal to element, then nothing is added!
    if (!point_list)
        return NULL;
    struct point_list* current = point_list;
    while (current) {
        if (current->head.x == element.x && current->head.y == element.y) {
            return point_list;
        }
        current = current->next;
    }
    struct point_list* result = point_list_new();
    result->next = point_list;
    result->head = element;
    return result;
}

int point_list_size(struct point_list* point_list) {
    struct point_list* current = point_list;
    int length = 0;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

struct point get_new_position(struct point old_position, char direction) {
    struct point new_position;
    new_position.x = old_position.x;
    new_position.y = old_position.y;
    switch (direction) {
        case '^': // go north
            new_position.y += 1;
            break;
        case 'v': // go south
            new_position.y -= 1;
            break;
        case '<': // go west
            new_position.x -= 1;
            break;
        case '>': // go east
            new_position.x += 1;
            break;
        default:
            break;
    }
    return new_position;
}

int main(void) {
    FILE* file = fopen("../input.txt", "r");
    if (!file) {
        fprintf(stderr, "Could not load file.");
        return 1;
    }
    int total_seen_houses = 0; // location: (0, 0)
    struct point current_position;
    struct point_list* point_list = point_list_new();
    point_list->head = current_position;
    current_position.x = 0;
    current_position.y = 0;

    char current_char;
    while ((current_char = fgetc(file)) != EOF) {
        current_position = get_new_position(current_position, current_char);
        point_list = point_list_prepend(point_list, current_position);
    }
    printf("Total houses seen: %d.\n", point_list_size(point_list));
    fclose(file);
    return 0;
}
