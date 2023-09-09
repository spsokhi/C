#include <stdio.h>
#include <math.h>

int main()
{
    int start, end, i, am, num;
    scanf("%d %d", &start, &end);
    for (int i = start; i <= end; i++)
    {
        int count = 0;
        num = i;
        am = 0;
        int temp1 = num;
        while (temp1 != 0)
        {
            temp1 = temp1 / 10;
            count++;
        }

        while (num != 0)
        {
            int temp = num % 10;
            am += pow(temp, count);
            num = num / 10;
        }
        if (i == am)
        {
            printf("amstrong %d ", i);
        }
    }
    return 0;
}
