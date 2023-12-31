#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int binsearch(char ele, int low, int high, char* arr)
{
    if(low>high)
    {
        return -1;
    }
    int mid = low + (high-low)/2;
    if (arr[mid] == ele)
    return mid;
    else if (arr[mid] > ele)
    return binsearch(ele, low, mid-1, arr);
    else 
    return binsearch(ele, mid+1, high, arr);
}

int main(void)
{
    int s;
    printf("Enter the size of the array: ");
    scanf("%d", &s);
    char* arr = (char*)malloc(s*sizeof(char));
    printf("Enter the elements of the array in sorted order: ");
    for(int i = 0; i<s;i++)
    {
        scanf(" %c",&arr[i]);
    }
    char ele;
    printf("Enter the element whose array index is to be determined: ");
    scanf(" %c",&ele);
    printf("The element %c is found at index %d of the array.\n", ele, binsearch(ele, 0, s-1, arr));
    free(arr);
}