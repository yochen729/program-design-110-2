#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define maxword 100

int find_lcp(char words[][maxword],char **lcp_string,int type,int num);
int minlen(char words[][maxword],int num);
char lower(char c);

int main()
{
    char *lcp_string;
    char words[maxword][maxword];
    int type,num,i,lcp=0;
    scanf("%d",&type);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {   //輸入字串
        scanf("%s",words[i]);
    }
    lcp = find_lcp(words,&lcp_string,type,num);
    if(lcp>0)
    {   //輸出lcp
        printf("%s\n",lcp_string);
    }
    else
    {
        printf("No longest common prefix\n");
    }
    return 0;
}

int find_lcp(char words[][maxword],char **lcp_string,int type,int num)
{
    int i,j,lcpcnt=0,allupper=1;
    char character;
    char *save = (char*)malloc(maxword * sizeof(char));
    int len = minlen(words,num);
    for(i=0;i<len;i++)
    {
        allupper = 1;
        character = words[0][i];
        for(j=0;j<num;j++)
        {
            if(islower(words[j][i]))
            {
                allupper = 0;
            }
            if(type == 1 && character != words[j][i])
            {
                *lcp_string = save;
                return lcpcnt;
            }
            else if(type == 2 && lower(character) != lower(words[j][i]))
            {
                *lcp_string = save;
                return lcpcnt;
            }
            if(j==(num-1))
            {
                if(allupper==0)
                {
                    character = lower(character);
                }
                save[lcpcnt] = character;
                save[lcpcnt+1] = '\0';
                lcpcnt++;
            }
        }
    }
    *lcp_string = save;
    return lcpcnt;
}

int minlen(char words[][maxword],int num)
{   //找最小字串長度
    int i,len;
    int min = strlen(words[0]);
    for(i=1;i<num;i++)
    {
        len = strlen(words[i]);
        if(len<min)
        {
            min = strlen(words[i]);
        }
    }
    return min;
}

char lower(char c)
{
    if(c>='A'&&c<='Z')
    {
        c = c-'A'+'a';
    }
    return c;
}