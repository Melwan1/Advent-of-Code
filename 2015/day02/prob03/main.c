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

int main(void) {
    FILE* file = fopen("../input.txt", "r");
    if (!file) { 
        fprintf(stderr, "Could not load file.\n");
        return 1;
    }
    char line[10];
    int total_paper_sqft = 0;
    while (fgets(line, 10, file)) {
        total_paper_sqft += get_paper_size(line);
    }
    printf("Total paper: %d sqft.", total_paper_sqft); 
    return 0;
}
