#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f = fopen("studentBinary.bin", "wb");

    // --- Student 1 ---
    char name1[] = "John";
    char college1[] = "DCU";
    int age1 = 22;
    float grade1 = 87.5;

    int n1 = strlen(name1);
    int c1 = strlen(college1);

    fwrite(&n1, sizeof(int), 1, f);
    fwrite(name1, sizeof(char), n1, f);

    fwrite(&c1, sizeof(int), 1, f);
    fwrite(college1, sizeof(char), c1, f);

    fwrite(&age1, sizeof(int), 1, f);
    fwrite(&grade1, sizeof(float), 1, f);
    fclose(f);

    printf("Binary file studentBinary.bin created!\n");
    return 0;
}