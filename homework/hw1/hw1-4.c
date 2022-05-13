#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxword 100000

char *get_word(char *text, char *word);
int getcount(char *word,char *words);

int main()
{
    char *ptr;
    char sentences[maxword],word[maxword],words[maxword];
    int count = 0;
    fgets(sentences,maxword,stdin);//取得句子
    scanf("%s",word);
    ptr = sentences;
    while(ptr=get_word(ptr,words))
    {
        count = count + getcount(word,words);
    }
    printf("%d\n",count);
    return 0;
}

char *get_word(char *text, char *word)
{
    char *ptr = text;//字來源位址
    char *qtr = word;//放字串的位址
    while((*ptr && isspace (*ptr)))
    {   //跳過空格
        ptr++;
    }
    while(*ptr && !isspace (*ptr))
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

int getcount(char *word,char *words)
{
    int len1 = strlen(word);
    int len2 = strlen(words);
    char *ptr = word;
    char *qtr = words;
    int minlen = len1;
    if(len1!=len2)
    {
        return 0;
    }
    int i;
    for(i=0;i<minlen;i++)
    {
        if((*ptr)!=(*qtr))
        {
            return 0;
        }
        ptr++;
        qtr++;
    }
    return 1;
}