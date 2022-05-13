#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxsize 4096
#define maxstring 128

/*
*1.讀取輸入
*2.處理字串
*3.比對字串
*4.
*5.
*/

char *get_word(char *text, char *word);
int getinputs(char **from,char **to,int *imode);
void getarticle(char *from,char *to,int *imode);
void replace(char *word, char *from, char *to, int imode);

int main()
{
    int imode=0;
    char *from, *to;
    fprintf(stderr, "Enter pattern, replacement, and at most one parameter:");
    int iscorrect = getinputs(&from,&to,&imode);
    //printf("form %s to %s\nimode = %d\n",from,to,imode);
    fprintf(stderr, "Enter the article:\n");
    if(!iscorrect)
    {   //看是不是正確的輸入
        printf("The input format: string1 string2 [parameter]\n");
        return 0;
    }
    getarticle(from,to,&imode);
    return 0;
}

char *get_word(char *text, char *word)
{
    char *ptr = text;//字來源位址
    char *qtr = word;//放字串的位址
    while((*ptr && isspace (*ptr))||(*ptr&&!isdigit(*ptr)&&!isalpha(*ptr)&&*ptr!='-'))
    {   //跳過空格
        ptr++;
    }
    while( *ptr && !isspace (*ptr) &&(isdigit(*ptr)||isalpha(*ptr)||*ptr=='-'))
    {   //複製字元
        *qtr++ = *ptr++;
    }
    *qtr = '\0'; 
    //在字元尾加上\0
    if(qtr - word == 0)
    {   //沒字回傳NULL
        return NULL;  
    }
    return ptr;//回傳下一個ptr起始值
}

int getinputs(char **from,char **to,int *imode)
{
    int i=0;
    char input[maxsize], word[maxstring], *array[maxstring];
    char *ptr;
    fgets(input,maxsize,stdin);
    ptr = input;
    while(ptr=get_word(ptr,word))
    {
        array[i] = strdup(word);
        i++;
    }
    *from = array[0];
    *to = array[1];
    if(i>2)
    {
        if(strcmp(array[2],"-i")==0 && i==3)
        {
            *imode = 1;
        }
        else
        {
            return 0;
        }
    }
    else if(i<2)
    {
        return 0;
    }
    return 1;
}

void getarticle(char *from,char *to,int *imode)
{
    char article[maxsize], word[maxsize];
    char *ptr;
    while(fgets(article,maxsize,stdin)!=NULL)
    {   //讀取文章
        ptr = article;
        while(ptr=get_word(ptr,word))
        {
            replace(word,from,to,*imode);
        }
    }
}

void replace(char *word, char *from, char *to, int imode)
{
    char string[maxsize*2] = "\0";
    int len, ischange = 0 ,sublen;
    char *ptr, *qtr, *rtr, *temp;
    if(imode)
    {
        char *lowerword = strdup(word);
        char *lowerfrom = strdup(from);
        ptr = word, qtr = lowerword;
        while(*ptr)
        {
            *qtr++ = tolower(*ptr++);
        }
        ptr = from, qtr = lowerfrom;
        while(*ptr)
        {
            *qtr++ = tolower(*ptr++);
        }
        ptr = lowerword;
        qtr = lowerfrom;
    }
    else
    {
        ptr = word;
        qtr = from;
    }
    rtr = word;
    while(temp = strstr(ptr,qtr))
    {
        ischange = 1;
        len = strlen(ptr);
        sublen = strlen(temp);
        strncat(string,rtr,len-sublen);
        ptr = ptr +len - sublen + strlen(qtr);
        rtr = rtr +len - sublen + strlen(qtr);
        strcat(string,to);
        break;//只要做一次，所以就break
    }
    if(ischange)
    {
        strcat(string,rtr);
        printf("%s\n",string);
    }
    return;
}