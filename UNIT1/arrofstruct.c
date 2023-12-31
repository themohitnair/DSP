#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
typedef struct {
    char* name;
    int roll;
} STUDENT;

STUDENT* get_data()
{
    printf("Enter the number of students whose data is to be entered: ");
    scanf("%d",&n);
    STUDENT* s = (STUDENT*)malloc(n*sizeof(STUDENT));
    s->name = (char*)malloc(50*sizeof(char));
    for(int i = 0; i<n; i++)
    {
        (s+i)->name = (char*)malloc(50*sizeof(char));
        printf("Student %d: \n", (i+1));
        printf("Enter the name of the student: ");
        scanf("%s",(s+i)->name);
        printf("Enter the roll number of the student: ");
        scanf("%d",&(s+i)->roll);
    }
    return s;
}

void display(STUDENT* s)
{
    for(int i = 0; i < n; i++)
    {
        printf("-----STUDENT %d-----\n",(i+1));
        printf("Name: %s\n",(s+i)->name);
        printf("Roll Number: %d\n",(s+i)->roll);
    }
}


int main(void)
{
    STUDENT* s = get_data();
    display(s);
}
