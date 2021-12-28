#ifndef __SEQLIST_H
#define __SEQLIST_H

#define LIST_INIT_SIZE 10
#define LIST_STEP_SIZE 10

#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef int bool;
typedef struct {
	ElemType *data;
	int length;
	int listSize;
}SqList;

bool InitList(SqList *L);
bool ListInsert(SqList * L, int pos, ElemType value);
bool ListDelete(SqList * L, int pos, ElemType *value);
int Length(const SqList *L);
int LocateElem(const SqList *L, ElemType value);
ElemType GetElem(const SqList *L, int pos);
void PrintList(const SqList *L);
bool DestroyList(SqList *L);
bool Empty(const SqList *L);

#endif