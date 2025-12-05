# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct Patient Patient;

struct Patient
{
    char firstName[10];
    char lastName[10];
    unsigned int weight;
    float height;
    float bmi;
    Patient *next;
};

Patient* get_patients(int argc, char *argv[]);
void calculate_bmi(Patient *head);
void print_patient(Patient *head);

int main(int argc, char *argv[])
{
    Patient *head = NULL;
    head = get_patients(argc, argv);
    calculate_bmi(head);
    print_patient(head);
    return 0;
}

Patient* get_patients(int argc, char *argv[])
{
    int size = (argc - 1) / 4;
    Patient *current, *head;

    head = calloc(1, sizeof(Patient));
    current = head;
    strcpy(current->firstName, argv[1]);
    strcpy(current->lastName, argv[2]);
    current->weight = atoi(argv[3]);
    current->height = atof(argv[4]);

    int index = 0;

    for (int i = 1; i < size; i++)
    {
        current->next = calloc(1, sizeof(Patient));
        current = current->next;
        strcpy(current->firstName, argv[index+5]);
        strcpy(current->lastName, argv[index+6]);
        current->weight = atoi(argv[index+7]);
        current->height = atof(argv[index+8]);
        index += 4;
    }
    current->next = NULL;
    return head;
}

void calculate_bmi(Patient *head)
{
    Patient *p = NULL;
    for(p = head; p != NULL; p = p->next)
    {
        p->bmi = p->weight / (p->height * p->height);
    }
}

void print_patient(Patient *head)
{
    Patient *p = NULL;
    for(p = head; p != NULL; p = p->next)
    {
        printf("%s %s, ", p->firstName, p->lastName);
        if(p->bmi > 25.0)
        {
            printf("overweight\n");
        }
        else if(p->bmi > 18 && p->bmi < 25)
        {
            printf("normal\n");
        }
        else
        {
            printf("underweight\n");
        }
    }
}