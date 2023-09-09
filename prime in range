#include <stdio.h>

int main()
{
    int start, end, factor;
    scanf("%d %d", &start, &end);

    for (int i = start; i <= end; i++)
    {
        if (i == 1)
            continue;
        factor = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                factor++;
            }
        }
        if (factor == 0)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
