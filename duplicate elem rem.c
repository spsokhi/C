#include <stdio.h>

int main()
{
    printf("Enter the size: ");
    int size;
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
        if (count == 0)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
