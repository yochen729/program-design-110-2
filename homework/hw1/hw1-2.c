#include <stdio.h>
#define maxstring 100000

void change_case(char *input,int type);
void printupper(char ptr);
void printlower(char ptr);

int main()
{
    char input[maxstring];
    int type;
    scanf("%s",input);
    scanf("%d",&type);
    change_case(input,type);
    return 0;
}

void change_case(char *input,int type)
{
    char *ptr=input;
    int i;
    switch(type)
    {
        case 1:
            while(*ptr)
            {
                printupper(*ptr++);
            }
            break;
        case 2:
            while(*ptr)
            {
                printlower(*ptr++);
            }
            break;
        case 3:
            for(i=1;*ptr;i++)
            {
                if(i%2==0)
                {
                    printlower(*ptr++);
                }
                else
                {
                    printupper(*ptr++);
                }
            }
            break;
    }

}

void printupper(char ptr)
{
    if(ptr>='a'&&ptr<='z')
    {
        ptr = ptr-'a'+'A';
    }
    printf("%c",ptr);
}

void printlower(char ptr)
{
    if(ptr>='A'&&ptr<='Z')
    {
        ptr = ptr-'A'+'a';
    }
    printf("%c",ptr);
}