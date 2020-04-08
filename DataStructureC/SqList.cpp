#include "SqList.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int InitSqList(SqList* L, int max)
{
    L->elem = (ElemType*)malloc(sizeof(ElemType) * max); 
    if (!L->elem)
    {
        printf("the list create failed\n"); 
        return 0; 
    }
    else
    {
        L->length = 0; 
        L->listsize = max; 
        return 1;
    }
}

int InsertSqList(SqList* L, int i, ElemType s)
{
    if (i < 1 || i > L->length + 1)
    {
        return 0; 
    }

    if (L->length >= L->listsize)
    {
        L->listsize += 10;
        L->elem = (ElemType*)realloc(L->elem, sizeof(ElemType) * L->listsize);
        if (!L->elem)
            return 0;
    }

    for (int k = L->length; k >= i; k--)
    {
        L->elem[k] = L->elem[k-1];
    }

    L->elem[i - 1] = s; 

    L->length += 1; 

    return 1; 
}

int DeleteSqList(SqList* L, int i, ElemType* s)
{
    if (i < 1 || i > L->length)
    {
        return 0;
    }

    *s = L->elem[i - 1]; 

    for (int k = i; k < L->length; k++)
    {
        L->elem[k - 1] = L->elem[k]; 
    }

    L->length -= 1; 

    return 1; 
}

int UpdateSqList(SqList* L, int i, ElemType s)
{
    if (i < 1 || i > L->length)
    {
        return 0;
    }

    L->elem[i - 1] = s;

    return 1; 
}

int GetSqList(SqList* L, int i, ElemType* s)
{
    if (i < 1 || i > L->length)
    {
        return 0;
    }

    *s = L->elem[i - 1];

    return 1;
}

void FreeSqList(SqList* L)
{
    if (L->elem)
    {
        free(L->elem);
    }
}

void testSqList()
{
    SqList L; 
    if (InitSqList(&L, 10))
    {
        printf("the list create success\n"); 
    }

    for (int k = 0; k < 11; k++)
    {
        ElemType e;
        strcpy_s(e.name, "zhaog1");
        e.score = 10.0f * k;

        if (InsertSqList(&L, L.length + 1, e))
        {
            printf("insert success\n");
        }
        else
        {
            printf("insert failed\n");
        }
    }

    ElemType s; 
    strcpy_s(s.name, "zhangliyuan");
    s.score = 100.0f; 
    UpdateSqList(&L, 5, s);

    ElemType f;
    GetSqList(&L, 5, &f); 

    if (DeleteSqList(&L, 5, &f))
    {
        printf("delete success\n"); 
    }
    else
    {
        printf("delete failed\n"); 
    }

    FreeSqList(&L);

    printf("testSqList\n"); 
}
