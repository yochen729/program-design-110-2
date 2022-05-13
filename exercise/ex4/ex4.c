#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define fp(x) fprintf(stderr,x);
#define pSign(x,y) (x==y) ? printf("=\n") : printf("+ ")

typedef struct Poly
{
    long Cof;
    int Exp;
}PolyType;

void Get_Terms(PolyType Poly[],int terms);
void Get_and_Out(PolyType Poly[],int Times,int Terms);
int Get_Input(char MSG[]);

int main()
{
    int Number_Of_Term,Times;
    Number_Of_Term = Get_Input("Enter the number of terms:");
    PolyType *Poly = (PolyType*)malloc(Number_Of_Term*sizeof(PolyType));
    Get_Terms(Poly,Number_Of_Term);
    Times = Get_Input("How many times to calculate:");
    Get_and_Out(Poly,Times,Number_Of_Term);
    return 0;
}

void Get_Terms(PolyType Poly[],int terms)
{   //取得係數與次方並輸出
    fp("Enter each term with cof and exp:\n");
    for(int count = 0;count < terms;count++)
    {
        scanf("%ld",&Poly[count].Cof);
        scanf("%d",&Poly[count].Exp);
    }
    for(int count = 0;count < terms;count++)
    {   //CofX^Exp
        printf("%ldx^%d ",Poly[count].Cof,Poly[count].Exp);
        pSign(count,terms-1);
    }
}

int Get_Input(char MSG[])
{
    int input;
    fp(MSG);
    while(scanf("%d",&input)&&input<=0)
    {   //直到不是<=0結束
        printf("The number must be greater than zero!\n");
        fp(MSG);
    }
    return input;
}

void Get_and_Out(PolyType Poly[],int Times,int Terms)
{
    long long Input,Result,Exp,Cof;
    for(int count = 0;count < Times;count++)
    {
        Result = 0;
        Input = Get_Input("The unknown number x is:");
        for(int count2 = 0;count2 < Terms;count2++)
        {   //Cof*X^Exp
            Cof = Poly[count2].Cof;
            Exp = Poly[count2].Exp;
            Result = Result + (long long)(Cof*pow(Input,Exp));
        }
        printf("%lld\n",Result);
    }
}