#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int increment(int *p)
{
    *p = *p + 1;
}

// const array不用变，只读
void printStr(const char *strlist)
{
    while (*strlist != '\0')
    {
        printf("print string %c\n", *strlist);
        strlist++;
    }
}
int sumOfElements(int A[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        /* code */
        sum += A[i];
    }
    return sum;
}
int main()
{
    int x = 5;
    char i = 'f';
    int *p = &x;
    char *q = &i;
    int **m = &p;
    printf("point address%d", p);
    printf("point address%d", p + 1);
    printf("point address%d", q);
    printf("point address%d", q + 1);

    increment(&x);
    printf("x value%d", x);

    int alist[5] = {1, 2, 3, 4, 5};
    printf("alist [0] address is %d\n", alist);        //-450888848
    printf("alist [1] address is %d\n", *(alist + 1)); // 2

    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("alist %d address is %d\n", i, *(alist + i));
    };
    int size = sizeof(alist) / sizeof(alist[0]);
    //传入soe的是alist的地址，需要size   sizeof->byte
    int sum = sumOfElements(alist, size);
    printf("total %d\n", sum);

    char name[] = "jhon"; //"\0"打底{‘j’,‘h’,‘o’,‘n’,‘\0’}
    printf("jhon bytes %d\n", sizeof(name));
    printf("jhon strSize %d\n", strlen(name));

    printStr(name);

    int B[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    // B 2个 3个"指针（地址）元素"的一维数列 --变量{B[0],B[1]}
    printf("pointFor2DArray:%d\n", **B);
    printf("pointFor2DArray:%d\n", *(*B + 1));       // B[0]
    printf("pointFor2DArray:%d\n", *(*(B + 1) + 1)); // B[0]

    int n;
    scanf("%d",&n);
  
    int* A = (int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        /* code */
        A[i]=i;
    };
   // free(A);
   // A = NULL;

    int *C = (int *)realloc(A,(n/2) * sizeof(int));
    // int *C = (int *)realloc(NULL, 2 * n * sizeof(int)); =MALLOC   不copyA 新建
    // int *A = (int *)realloc(A, 0); =free(A)  
    for (int i = 0; i < 2*n; i++)
    {
        /* code   extend A*/
       printf("malloc %d\n",C[i]);
    };


}