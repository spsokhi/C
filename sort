#include<stdio.h>
int main()
{
    int i,j,temp;
    int arr[5]={10,3,5,70,6};
    
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if (arr[j]>arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d\n",arr[i]);
}
return 0;
}
