#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct status
{
    char name[32];
    char elts[16];
    int attack;
    int hp;
};
struct status** pokemon;

int compare_n (const void *a, const void *b);
int compare_e (const void *a, const void *b);
int compare_a (const void *a, const void *b);
int compare_h (const void *a, const void *b);
int get_elt (char *a);
void print_data (int time,int n,int o[]);

int main()
{
    int num_of_data,num_of_queries;
    scanf("%d %d",&num_of_data,&num_of_queries);
    pokemon = (struct status**)malloc(sizeof(struct status*)*num_of_data);
    int *order = (int *)malloc(sizeof(int)*num_of_data);
    for(int i = 0 ; i < num_of_data ; i++)
    {   //get input data
        pokemon[i] = (struct status*)malloc(sizeof(struct status));
        scanf("%s %s %d %d",pokemon[i]->name,pokemon[i]->elts,&pokemon[i]->attack,&pokemon[i]->hp);
        order[i] = i;
    }
    char fcn[10];
    for(int j = 0;j < num_of_queries;j++)
    {   //go query
        scanf("%s",fcn);
        if(!strcmp(fcn,"NAME"))  qsort(order,num_of_data,sizeof(int),compare_n);
        else if (!strcmp(fcn,"ATTRIBUTE"))  qsort(order,num_of_data,sizeof(int),compare_e);
        else if (!strcmp(fcn,"ATTACK"))  qsort(order,num_of_data,sizeof(int),compare_a);
        else if (!strcmp(fcn,"HP"))  qsort(order,num_of_data,sizeof(int),compare_h);
        print_data(j+1,num_of_data,order);
    }
    return 0;
}

void print_data (int time,int n,int o[])
{   //use order to print results
    printf("Case #%d:\n",time);
    
    for(int i=0;i<n;i++)
    {
        printf("%s %s %d %d\n",pokemon[o[i]]->name,pokemon[o[i]]->elts,pokemon[o[i]]->attack,pokemon[o[i]]->hp);
    }
}

int compare_n (const void *a, const void *b)
{   //compare pokemon's name
    return (strcmp(pokemon[*(int*)a]->name,pokemon[*(int*)b]->name));
}
int compare_e (const void *a, const void *b)
{   //compare pokemon's attribute
    if(!strcmp(pokemon[*(int*)a]->elts,pokemon[*(int*)b]->elts)) return (pokemon[*(int*)a]->hp) > (pokemon[*(int*)b]->hp);
    int elt_a,elt_b;
    elt_a = get_elt(pokemon[*(int*)a]->elts);
    elt_b = get_elt(pokemon[*(int*)b]->elts);
    return elt_a > elt_b;
}
int compare_a (const void *a, const void *b)
{   //compare pokemon's attack
    return (pokemon[*(int*)a]->attack) < (pokemon[*(int*)b]->attack);
}
int compare_h (const void *a, const void *b)
{   //compare pokemon's hp
    return (pokemon[*(int*)a]->hp) > (pokemon[*(int*)b]->hp);
}

int get_elt (char *a)
{
    if(!strcmp(a,"WATER"))  return 1;
    if(!strcmp(a,"FIRE"))   return 2;
    if(!strcmp(a,"EARTH"))  return 3;
    if(!strcmp(a,"LIGHT"))  return 4;
    if(!strcmp(a,"DARK"))   return 5;
    return -1;
}