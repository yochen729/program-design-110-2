#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max_bytes 128

typedef struct data *listPointer;
typedef struct data
{   //雙向鏈結串列
    char name[32];
    listPointer pre;
    listPointer next;
}name_data;

void clockwise(name_data *head,int value,int people);
void counter_clockwise(name_data *head,int value,int people);
void insert(name_data *head,char name[],int position);
void kill(name_data **list);
void kill_conter(name_data **list);

int main()
{
    int times;
    scanf("%d",&times);
    name_data *head = (name_data*)malloc(sizeof(name_data));
    head->next = head;
    head->pre = head;
    //初始化
    char input[max_bytes];
    int wordcnt = 0;
    for(int i = 0;i<times ;i++)
    {
        scanf("%s",input);
        //插入名字到串列
        insert(head,input,wordcnt);
        wordcnt++;
    }

    int value;
    char clock[max_bytes];
    scanf("%d",&value);//跳值
    scanf("%s",clock);//順逆
    if(!strcmp(clock,"CLOCKWISE"))
    {
        clockwise(head,value,wordcnt);
    }
    else if(!strcmp(clock,"COUNTERCLOCKWISE"))
    {
        counter_clockwise(head,value,wordcnt);
    }
    else printf("What?\n");
    return 0;
}

void insert(name_data *head,char name[],int position)
{
    if(position == 0)
    {
        strcpy(head->name,name);
        return;
    }
    name_data *list = head->pre;
    //到最後的節點
    name_data *cache = head->pre;
    list->next = (name_data*)malloc(sizeof(name_data));
    //新節點
    list = list->next;
    strcpy(list->name,name);
    list->next = head;
    list->pre = cache;
    head->pre = list;
    //頭尾接起來
}

void clockwise(name_data *head,int value,int people)
{
    name_data *list = head;
    int people_cnt = people;
    int i;
    while (people_cnt != 1)
    {
        for(i=0;i<value;i++)
        {
            list = list->next;
        }
        printf("%s KILLED\n",list->name);
        kill(&list);
        people_cnt --;
    }
    printf("%s SURVIVE\n",list->name);
}

void counter_clockwise(name_data *head,int value,int people)
{
    name_data *list = head;
    int people_cnt = people;
    int i;
    while (people_cnt != 1)
    {
        for(i=0;i<value;i++)
        {
            list = list->pre;
        }
        printf("%s KILLED\n",list->name);
        kill_conter(&list);
        people_cnt --;
    }
    printf("%s SURVIVE\n",list->name);
}

void kill_conter(name_data **list)
{
    name_data *cache_next = (*list)->next;
    cache_next->pre = (*list)->pre;
    //後面接起來
    name_data *cache_pre = (*list)->pre;
    cache_pre->next = (*list)->next;
    //前面接起來
    free ((*list));
    *list = cache_pre;
}

void kill(name_data **list)
{
    name_data *cache_next = (*list)->next;
    cache_next->pre = (*list)->pre;
    //後面接起來
    name_data *cache_pre = (*list)->pre;
    cache_pre->next = (*list)->next;
    //前面接起來
    free ((*list));
    *list = cache_next;
}