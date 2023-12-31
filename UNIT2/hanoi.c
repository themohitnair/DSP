#include<stdio.h>
#include<stdlib.h>


int stepcount = 0;

void hanoi(int n, char source, char aux, char dest)
{
    if(n==1)
    {
        stepcount++;
        printf("%d %c -> %c.\n",n,source,dest);
    }
    else
    {
        hanoi(n-1, source, dest, aux);
        stepcount++;
        printf("%d %c -> %c.\n",n,source,dest);
        hanoi(n-1, aux, source, dest);
    }
}

int main(void)
{
    int n;
    printf("Enter the number of disks in the Tower of Hanoi Problem to be solved. ");
    scanf("%d",&n);
    stepcount = 0;
    hanoi(n,'A','B','C');
    printf("The number of steps taken to solve this problem for %d disks is %d.\n",n,stepcount);
}