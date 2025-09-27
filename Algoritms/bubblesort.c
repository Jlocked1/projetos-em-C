#include <stdio.h>

int main(void) 
{
    int array[] = {9, 7, 2, 6, 4, 3, 1, 5, 8};
    int n = 9;

    printf("Array original: ");
    for(int k = 0; k < n; k++)
    {
        printf("%d ", array[k]);
    }
    printf("\n");

    for(int i = 0; i < n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    printf("Array ordenado: ");
    for(int k = 0; k < n; k++)
    {
        printf("%d ", array[k]);
    }
    printf("\n");
}