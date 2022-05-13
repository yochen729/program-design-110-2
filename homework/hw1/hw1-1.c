#include <stdio.h>

int main()
{
    int input;
    scanf("%d",&input);
    int i=0,j=0,num=0;
    num =input;
    for(i=1;i<=input;i++)
    {
        for(j=i+1;num%j==0&&j<=input;)
        {
            num = num/j;
            printf("%d ",j);
        }
    }
    return 0;
}