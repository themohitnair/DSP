#include<stdio.h>
#include<stdlib.h>

int fact(int n)
{
    if (n<0)
    {
        return -1;
    }
    else if (n==0 || n==1)
    {
        return 1;
    }
    else if (n>1)
    {
        return n*fact(n-1);
    }
}

int main(void)
{
    int num;
    printf("Enter the number whose factorial is to be found: ");
    scanf("%d",&num);
    printf("The factorial of %d is %d.\n",num, fact(num));
}