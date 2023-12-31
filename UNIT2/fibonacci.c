#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
    if(n<0)
    {
        printf("Program terminated. ");
        exit(0);
    }
    else if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return fib(n-1)+fib(n-2);
    }
}

int main(void)
{
    int n;
    printf("Enter the number of terms to be printed: ");
    scanf("%d",&n);
    printf("The first %d terms of the Fibonacci series are:\n");
    for(int i = 0; i<n;i++)
    {
        int term = fib(i);
        printf("%d ", term);
    }
    printf("");
}