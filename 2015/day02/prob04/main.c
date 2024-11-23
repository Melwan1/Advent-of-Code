#include <stdio.h>

int min2(int arg1, int arg2) {
    if (arg1 < arg2)
        return arg1;
    return arg2;
}

int min3(int arg1, int arg2, int arg3) {
    return min2(arg1, min2(arg2, arg3));
}

int get_prism_area(int length, int width, int height) {
    return 2 * (length * width + length * height + width * height);
}

int get_paper_size(char* dimensions) {
    int length;
    int width;
    int height;
    sscanf(dimensions, "%dx%dx%d", &length, &width, &height);
    return get_prism_area(length, width, height) + min3(length * width, length * height, width * height);
}

int get_ribbon_wrapper_size(char* dimensions) {
    // size to wrap the present and of the perfect bow
    int length;
    int width;
    int height;
    sscanf(dimensions, "%dx%dx%d", &length, &width, &height);
    return 2 * (min3(length + width, length + height, width + height)) + length * width * height;
}

int main(void) {
    FILE* file = fopen("../input.txt", "r");
    if (!file) { 
        fprintf(stderr, "Could not load file.\n");
        return 1;
    }
    char line[10];
    int total_ribbon_size = 0;
    while (fgets(line, 10, file)) {
        total_ribbon_size += get_ribbon_wrapper_size(line);
    }
    printf("Total ribbon size: %d\n.", total_ribbon_size); 
    return 0;
}
