#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "SeqList.h"

bool InitList(SqList *L)
{
	L->data = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if (L->data==NULL)return FALSE;
	L->length = 0;
	L->listSize = LIST_INIT_SIZE;
	return TRUE;
}

bool ListInsert(SqList * L, int pos, ElemType value)
{
	ElemType *newbase;
	ElemType *insert;
	ElemType *current;
	if (pos<1||pos>L->length+1)	return FALSE;
	
	if (L->length>=L->listSize)
	{
		newbase = (ElemType*)realloc(L->data, (L->listSize+LIST_STEP_SIZE)*sizeof(ElemType));
		if(newbase == NULL) return FALSE;
		L->data = newbase;
		L->listSize += LIST_STEP_SIZE;
	}
	
	insert = &(L->data[pos-1]);
	for (current = &(L->data[L->length-1]); current >= insert; --current)
			*(current+1) = *current;
	*insert = value;
	++L->length;
	return TRUE;
	return FALSE;
}

bool ListDelete(SqList * L, int pos, ElemType * value)
{
	ElemType * del;
	ElemType * q;
	if (pos<1 || pos>L->length) return FALSE;
	
	*value = L->data[pos-1];
	del = &L->data[pos-1];
	q = L->data+L->length-1;
	for (++del; del<=q; ++del) *(del-1) = *del;
	--L->length;
	return TRUE;
}

int Length(const SqList * L)
{
	return L->length;
}

int LocateElem(const SqList * L, ElemType value)
{
	return 0;
}

ElemType GetElem(const  SqList * L, int pos)
{
	//return ElemType();
	if (L->length == 0) return 0;
	if (pos<1 || pos>L->length)
	return 0;
	return L->data[pos-1];
}

void PrintList(const SqList * L)
{
	int i;
	if (L->length == 0) return;
	for (i = 0; i < L->length; i++)
	printf("%d ",L->data[i]);
}

bool DestroyList(SqList * L)
{
	if (L->data == NULL ) return TRUE;
	else
		free(L->data);
	L->data = NULL;
	return TRUE;
}

bool Empty(const SqList * L)
{
	return  (L->length == 0)? TRUE:FALSE;
}

int main()
{
	SqList list;
	int i;
	int del;
	InitList(&list);
	
	for( i = 1; i < 15; i++)
	ListInsert(&list,i,i);
	
	PrintList(&list);
	printf("%d",list.listSize);
//	puts("\n");
//	ListDelete(&list,2,&del);
//	printf("del = %d\n",del);
//	PrintList(&list);


	return 0;
}