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


void calculate_bmi(Patient *head)
{
    Patient *p = NULL;
    for(p = head; p != NULL; p = p->next)
    {
        p->bmi = p->weight / (p->height * p->height);
    }
}

Patient* get_patients(int argc, char *argv[])
{
    int numPatients = (argc - 1) / 4;
    Patient *head = NULL;
    Patient *current = NULL;

    for (int i = 0; i < numPatients; i++) {
        Patient *new_patient = calloc(1, sizeof(Patient));
        if (!new_patient) exit(1);

        int base = 1 + i*4;  // starting index for this patient's argv
        strcpy(new_patient->firstName, argv[base]);
        strcpy(new_patient->lastName, argv[base+1]);
        new_patient->weight = atoi(argv[base+2]);
        new_patient->height = atof(argv[base+3]);
        new_patient->next = NULL;

        if (!head) {
            head = new_patient;
            current = new_patient;
        } else {
            current->next = new_patient;
            current = new_patient;
        }
    }

    return head;
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