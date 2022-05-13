#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fp(x) fprintf(stderr,x)

void bubblesort (int *a[] ,int n,int o[]);
void swap (int id[] ,int i ,int j);
void print_data (int *a[] ,int n,int o[]);

int main()
{
    int num_of_data;
    fp("Number of records you want to key in:");
    scanf("%d",&num_of_data);
    int **data = (int **)malloc(sizeof(int*)*num_of_data);
    int *order = (int *)malloc(sizeof(int)*num_of_data);
    for(int i = 0 ; i < num_of_data ; i++)
    {
        data[i] = (int *)malloc(sizeof(int)*2);
        fp("Enter ID & score:");
        scanf("%d %d",&data[i][0],&data[i][1]);
        order[i] = i;
    }
    bubblesort(data, num_of_data,order);
    print_data(data, num_of_data,order);
    return 0;
}

void bubblesort (int *a[] ,int n,int o[])
{   //泡沫排序法
    int i, j;
    for(i = 1; i < n; i++)
    {   //在每輪的迴圈，j從0開始，j和j+1的資料倆倆比較，前者若較大就和後者交換位置，直到 j < n-i，因為後面有i-1個項是已經排好的了
        for(j = 0; j < (n - i); j++)
        {   
            if(a[o[j]][0] > a[o[j+1]][0])
            {   //利用order去排順序，order代表的是各個排名所在的ID位置，swap時就不用動到原始資料
                swap(o, j, j+1);
            }
        }
    }
}

void swap (int id[] ,int i ,int j)
{   //swap函式
    int key;
    key = id[i];
    id[i] = id[j];
    id[j] = key;
}

void print_data (int *a[] ,int n,int o[])
{   //利用order印出結果
    printf("ID\tscore\n");
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\n",a[o[i]][0],a[o[i]][1]);
    }
}