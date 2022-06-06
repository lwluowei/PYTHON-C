#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//局部变量  函数执行完就么了  可以把变量放入heap
int add(int* a ,int *b){
    //int* c = *a+*b;

    return *a +*b;
}


int main()
{  int a,b,c;
   int (*p)(int*,int*);
   //int *p(int *, int *);
   a=2;b=3;
   p=&add;
  
   printf("%d",p(&a,&b));
}