#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    printf("enter the size:");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
