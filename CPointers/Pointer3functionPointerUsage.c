#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a ,const void *b){
    //int* c = *a+*b;
    int * ap= (int *)a;
    int * bp = (int *)b;

    return *ap -*bp;
}

int compareInt(const int *a, const int *b)
{
    // int* c = *a+*b;
   

    return *a - *b;
}
//函数做变量传入，直接对应多个方法
int Campare(int an,int bn, int (*functionPointer)(const int *a,const int *b))
{
    int c= functionPointer(&an, &bn);
    printf("%dfunctionPointer", c);
}
int main()
    {
        int ls[] = {-1, 2, 4, -9, 9, -10};
        qsort(ls, 6, sizeof(int), compare);
        for (int i = 0; i < 6; i++)
        {
            /* code */
            printf("%d\n", ls[i]);
        }
        Campare(5, 6, compareInt);
}