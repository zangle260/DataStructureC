#pragma once

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10

typedef struct
{
    char name[20];
    float score; 
}Stu;

typedef Stu ElemType; 

typedef struct
{
    ElemType* elem; 
    int length; 
    int listsize; 
}SqList;

int InitSqList(SqList* L, int max); 
void FreeSqList(SqList* L);

int InsertSqList(SqList* L, int i, ElemType s);
int DeleteSqList(SqList* L, int i, ElemType* s); 
int UpdateSqList(SqList* L, int i, ElemType s); 
int GetSqList(SqList* L, int i, ElemType* s); 

void testSqList();





