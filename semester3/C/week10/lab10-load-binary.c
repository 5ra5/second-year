// Load Binary Data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student struct using dynamic strings
// all of these values fit into one node of a linked list
typedef struct Student {
    char *name;
    char *college;
    char age;
    float grade;
    struct Student *next; // pointer to next student in linked list
} Student;

// Function prototypes
Student* readStudentsFromBinary(const char *filename);
void printStudents(Student *head);
int writeStudentsToBinary(Student *head, const char *filename);
int writeStudentsToTextFile(Student *head, const char *filename);
void freeStudents(Student *head);

int main(){

    // initialising files
    const char *inputFile = "studentBinary.bin";
    const char *binaryOutputFile = "studentBinaryOut.bin";
    const char *textOutputFile = "studentTextOut.txt";

    // read students from binary file into a linked list
    Student *head = readStudentsFromBinary(inputFile);

    // print all students
    printStudents(head);

    // write the data into files
    writeStudentsToBinary(head, binaryOutputFile);
    writeStudentsToTextFile(head, textOutputFile);

    freeStudents(head);

    return 0;

}

// read students from a binary file into a linked list

Student* readStudentsFromBinary(const char *filename){
    FILE *pfile = fopen(filename, "rb");
    if (!pfile) return NULL;

    Student *head = NULL;
    Student *tail = NULL;

    while (!feof(pfile)){
        int name_len = 0, college_len = 0;

        // read name length, allocate memory for name, read name
        if (fread(&name_len, sizeof(int), 1, pfile) != 1) break;
        char *name = malloc(name_len + 1);
        fread(name, 1, name_len, pfile);
        name[name_len] = '\0'; // turning the character array into a proper string

        // read college length, allocate memory for college, read college
        fread(&college_len, sizeof(int), 1, pfile);
        char *college = malloc(college_len + 1);
        fread(college, 1, college_len, pfile);
        college[college_len] = '\0';

        // read age and grade
        int age;
        float grade;
        fread(&age, sizeof(int), 1, pfile);
        fread(&grade, sizeof(float), 1, pfile);

        // allocate memory for a new student node and fill the node with struct elements
        Student *newNode = malloc(sizeof(Student));
        newNode->name = name;
        newNode->college = college;
        newNode->age = age;
        newNode->grade = grade;
        newNode->next = NULL;

        // fill a linked list
        if (!head){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    fclose(pfile);
    return head;
}

// print all students
void printStudents(Student *head){
    
    // iterate through the linked list and print information
    Student *current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("College: %s\n", current->college);
        printf("Age: %d\n", current->age);
        printf("Grade: %.2f\n\n", current->grade);
        current = current->next;
    }
}

// write linked list of students into a binary file
int writeStudentsToBinary(Student *head, const char *filename) {
    
    // open a binary file in write mode
    FILE *bfile = fopen(filename, "wb");

    // start from head and iterate through the linked list
    Student *current = head;
    while (current) {

        // determine the length of name and college using strlen, no need to read it in now
        int name_len = strlen(current->name);
        int college_len = strlen(current->college);

        // write name_len and name
        fwrite(&name_len, sizeof(int), 1, bfile);
        fwrite(current->name, 1, name_len, bfile);
        
        // write college_len and college
        fwrite(&college_len, sizeof(int), 1, bfile);
        fwrite(current->college, 1, college_len, bfile);

        // write age and grade
        fwrite(&current->age, sizeof(int), 1, bfile);
        fwrite(&current->grade, sizeof(float),1, bfile);

        current = current->next;
    }
    fclose(bfile);
    return 1;
}

// write linked list of students into a text file
int writeStudentsToTextFile(Student *head, const char *filename){
    
    // open the file in write mode
    FILE *tfile = fopen(filename, "w");

    // start from head and iterate through the linked list
    Student *current = head;
    while (current) {
        fprintf(tfile, "Name: %s\n", current->name);
        fprintf(tfile, "College: %s\n", current->college);
        fprintf(tfile, "Age: %d\n", current->age);
        fprintf(tfile, "Grade: %.2f\n\n", current->grade);
        current = current->next;
    }
    fclose(tfile);
    return 1;
}

// free all allocated memory in linked list
void freeStudents(Student *head){
    Student *current = head;
    while (current){
        Student *temp = current->next;
        free(current->name);
        free(current->college);
        free(current);
        current = temp;
    }
}