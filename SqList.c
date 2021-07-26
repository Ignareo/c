#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERR 0
#define ElemType int
#define MaxSize 10


/*----------------------------------------------------------------
顺序表SqList

问题：
1. 怎么释放内存 free(?)
2. 用printf输出ElemType时，格式串怎么办

注意：
1. 此版本可增长顺序表，设了常量InitSize为，而MaxSize为结构成员  
----------------------------------------------------------------*/

// 定义顺序表
typedef struct SqList
{
    ElemType *data;
    int length;
}   SqList;

// 初始化
void InitSqList(SqList *L)
{
    L->data = (ElemType *) calloc(MaxSize, sizeof(ElemType));
    L->length = 0;
}

// 打印输出全部data
void PrintSqList(SqList *L)
{
    int i;
    for (i = 0; i < L->length; i++)
        printf("%d: %d\n", i, L->data[i]);
}

// 增加顺序表的长度，传参len为要增加的长度
int IncreaseSqList(SqList *L, int len)
{
    if(len<0)
        return ERR;
    ElemType *p;
    p = L->data;
    L->data = (ElemType *) calloc (MaxSize+len, sizeof(ElemType));
    L->length = MaxSize + len;
    free(p);
    return OK;
}

// 插入元素
int InsertSqList(SqList *L, int i, ElemType e)
{
    int j;
    if(i<1 || i>=L->length+1)
        return ERR;
    for( j=L->length+1; j>i; j-- )
        L->data[j] = L->data[j-1];
    L->length++;
    return OK;
}

// 按位查找，传入位序n，用e接收传回来的值
int GetElem(SqList *L, int n, ElemType *e)
{
    if(n<0 || n>L->length)
        return ERR;
    *e = L->data[n];
    return OK;
}

// 按值查找，传入值e，传回位序n
int LocateElem(SqList *L, ElemType e)
{   
    int i;
    for(i=0; i<L->length, i++)
    {
        if(L->data[i] == e) 
            return i+1;
    }
    return ERR;
}

// 主函数
int main()
{
    SqList L;
    InitSqList(&L);

    int len;
    scanf("%d", &len);
    IncreaseSqList(&L, len);

    PrintSqList(&L);


    return 0;
}