#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//局部变量  函数执行完就么了  可以把变量放入heap
int* add(int* a ,int *b){
    //int* c = *a+*b;

    int *c = (int *)malloc(sizeof(int));
   *c = *a + *b;
    printf("add Address%d\n", c);
    return c;
}


int main()
{  
   int a,b;
   a=1;b=2;
   int* d=add(&a,&b);
   printf("main Address%d Value%d\n", d,*d);
}