/*  Ashley Troske
 *  Coen12L - W5:15
 *  6/6/19
 *  List ADT, dequeue implemented with a doubly linked list and dummy node. Stores id numbers and ages, used in college.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

typedef struct node
{
	int ages;
	int data; //stores id numbers
	struct node*next;
	struct node*prev;
}NODE;

typedef struct list
{
	int count;
	struct node *head;
}LIST;

LIST *lp;


// runtime: O(n)
LIST *createList(void)
{
	LIST *lp=malloc(sizeof(LIST));
	  assert(lp!=NULL);
	lp->count=0;
	lp->head=malloc(sizeof(NODE));
	  assert(lp->head!=NULL);
	lp->head->prev=lp->head;
	lp->head->next=lp->head;
	return lp;
}

// runtime: O(1)
void destroyList(LIST *lp)
{
	assert(lp!=NULL);
	NODE *pDel, *pNext;
	pDel=lp->head;
	do
	{
		pNext=pDel->next;
		free(pDel);
		pDel=pNext;
	}while(pDel!=lp->head);
	free(lp);
	return;
}


// runtime: O(1)
void addStudent(LIST *lp,  int age, int id)
{
	assert(lp!=NULL);
	NODE *pNew = malloc(sizeof(NODE));
 	  assert(pNew!=NULL);
 	  pNew->ages=age;
	  pNew->data=id;
	pNew->next=lp->head->next; 
	pNew->prev=lp->head;
	lp->head->next->prev=pNew;
	lp->head->next=pNew;
	lp->count++;
	return;
}


// runtime: O(n)
void removeStudent(LIST *lp, int id)
{
	assert(lp!=NULL);
	NODE *pCur;
	pCur=lp->head->next;
	while(pCur!=lp->head)
	{
		if(pCur->data==id)
		{
			pCur->prev->next=pCur->next;
			pCur->next->prev=pCur->prev;
			printf("Removing... Age: %d\tID:%d\n", pCur->ages, pCur->data);
			free(pCur);
			lp->count--;
		}
		pCur=pCur->next;
	}
	return; 
}

// runtime: O(n)
void searchAge(LIST *lp, int age)
{
	printf("Searching for people with age: %d\n", age);
	assert(lp!=NULL);
	NODE *pCur;
	pCur=lp->head->next;
	while(pCur!=lp->head)
	{	
		if(pCur->ages==age)
			printf("FIYBDAge: %d\tID number: %d\n", pCur->ages, pCur->data);
		pCur=pCur->next;
	}
	return;
}

// runtime: O(n)
void searchID(LIST *lp, int idnum)
{
	printf("Searching for people with ID number: %d\n", idnum);
	assert(lp!=NULL);
	NODE *pCur;
	pCur=lp->head->next;
	while(pCur!=lp->head)
	{
		if(pCur->data==idnum)
		{	printf("\tFOUND: Age: %d\tID number: %d\n", pCur->ages, pCur->data); return; }
		pCur=pCur->next;
	}
	printf("/tID not found\n");
	return;
}

// runtime: O(n)
int maxAgeGap(LIST *lp)
{
	NODE *pCur=lp->head->next;
	int min=pCur->ages;
	int max=pCur->ages;

	while(pCur!=lp->head)
	{
		if(pCur->ages<min)
			min=pCur->ages;
		else if(pCur->ages>max)
			max=pCur->ages;
		pCur=pCur->next;
	}
	printf("Maximum age gap is %d\n", max-min);
	return max-min;
}
