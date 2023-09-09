#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    printf("enter the size:");
    scanf("%d", &size);
    int *arr2=(int *)calloc(size,sizeof(int));
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr2[i]);
    }

    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("enter the new size:");
    int size2;
    scanf("%d", &size2);
    int *arr1 = realloc(arr, size2);
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
