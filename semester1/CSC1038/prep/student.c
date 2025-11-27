# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// week 7 student struct task using dynamic memory allocation and a doubly linked list to store information!!!

// initialise a struct: include a pointer to previous and next node
typedef struct Student {
    char *name;
    char *programme;
    float grade;
    struct Student *prev; // pointer to the previous student
    struct Student *next; // pointer to the next student
} Student;

// function prototypes
Student* createStudent(char *name, char *programme, float grade);
void appendStudent(Student **head, Student **tail, Student *newStudent);
void printStudents(Student *head, float average);
void freeStudents(Student *head);
float CSCEaverage(Student *head);


int main(int argc, char *argv[]){
    
    // initialise a head and a tail pointer
    Student *head = NULL;
    Student *tail = NULL;

    // loop to get the data from the command line - then pass it to functions
    for (int i = 1; i < argc; i += 3){
        char *name = argv[i];
        char *programme = argv[i + 1];
        float grade = atof(argv[i + 2]);

        // make a new node and append a node to a doubly linked list
        Student *newStudent = createStudent(name, programme, grade);
        appendStudent(&head, &tail, newStudent);
    }

    // calculate the average of CSCE grades and print the students
    float average = CSCEaverage(head);
    printStudents(head, average);
    freeStudents(head);

    return 0;
}

// create a new student node
Student* createStudent(char *name, char *programme, float grade){
    
    // allocate memory for a new node, and handle a case where there is no data
    Student *newStudent = malloc(sizeof(Student));
    if (!newStudent){
        printf("Memory allocation for a student failed!\n");
    }

    // allocate memory for name and programme based on their length
    // this has to be done for strings
    // handle the case where there's no data
    newStudent->name = malloc(strlen(name) + 1);
    newStudent->programme = malloc(strlen(programme) + 1);

    if(!newStudent->name || !newStudent->programme){
        printf("Memory allocation for name and/or programme failed!\n");
    }

    // copy the values
    strcpy(newStudent->name, name);
    strcpy(newStudent->programme, programme);

    // get the value for grade and set prev and next to NULL
    newStudent->grade = grade;
    newStudent->prev = NULL;
    newStudent->next = NULL;

    // return the node
    return newStudent;
}

// append a student node to the doubly linked list
// pass a double pointer of head and tail since they were originally pointers
void appendStudent(Student **head, Student **tail, Student *newStudent){

    // the previous node of a new node is the tail of the list
    // the next node of a new node is NULL
    newStudent->prev = *tail;
    newStudent->next = NULL;

    // set the pointer of the previous tail to point to the new node
    // if there is no tail, then the new node is both head and the tail
    if(*tail){
        (*tail)->next = newStudent;
    }else{
        *head = newStudent;
    }

    // in both cases, the new node becomes the new tail of the list
    *tail = newStudent;
}

// first print all students
// then print students who do CSCE
// print the average grade of CSCE students
void printStudents(Student *head, float average){
    
    // iterate through the list and print all students
    Student *current = head;
    
    while(current){
        printf("%s, %s, %.2f\n", current->name, current->programme, current->grade);
        current = current->next;
    }

    printf("\n");

    // iterate again and print names and grade for each student that does CSCE
    Student *current2 = head;
    while(current2){
        if(strcmp(current2->programme, "CSCE") == 0){
            printf("%s, %.2f\n", current2->name, current2->grade);
            current2 = current2->next;
        }
        current2 = current2->next;
    }

    // print the average grade
    printf("\n");
    printf("Average CSCE grade: %.2f\n", average);
}

// free the memory used for a linked list
// free each element of the node separately
// and then free any remaining memory
void freeStudents(Student *head){
    Student *current = head;
    while(current){
        Student *temp = current;
        current = current->next;
        free(temp->name);
        free(temp->programme);
        free(temp);
    }
}

// calculate average of CSCE grades
float CSCEaverage(Student *head){
    
    // keep track of the count and the sum because average = sum/count
    int count = 0;
    float sum = 0.0;

    // iterate through the list, if the student did CSCE, add that value to the sum and increment the count
    Student *current = head;
    while(current){
        if(strcmp(current->programme, "CSCE") == 0){
            sum += current->grade;
            count++;
        }
        current = current->next;
    }

    // avoid division by 0
    if (count == 0){
        return 0.0;
    }

    // return the average
    return sum / count;
}
