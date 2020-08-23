/* 
* Ashley Troske
* Coen12L - W5:15
* 6/7/19
* ADT for students enrolled in a College. 
*/

#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define EMPTY 0
#define DELETED 1
#define FILLED 2

typedef struct set
{
	int *data;
	int *ages;
	char *flag;
	int length;
	int count;
}SET;

SET *sp;

// Creates an empty array for the amount of students enrolled that year
// runtime: O(n)
SET *createSet (int maxElts)
{
	int i;
	SET * sp= malloc(sizeof(SET));
       	  assert(sp!=NULL);
	sp->length=1009;
	sp->count=0;

	sp->flag=malloc(sizeof(char)*sp->length);
	  assert(sp->flag!=NULL);
	  for(i=0; i<sp->length; i++)
	  {
		sp->flag[i]=EMPTY;
	  }
	sp->data=malloc(sizeof(int*)*sp->length);
	  assert(sp->data!=NULL);
	sp->ages=malloc(sizeof(int*)*maxElts);
	  assert(sp->ages!=NULL);
	return sp;
}

//Destroys the list of students enrolled in college
// runtime: O(n)
void destroySet(SET *sp)
{
	assert(sp!=NULL);
	int i;
	free(sp->flag);
	free(sp->data);
	free(sp->ages);
	free(sp);
	return;
}

// Function to hash using id number and linear probing
// runtime: O(n) [expected: O(1)]
static int hashsearch(SET *sp, int id, bool *found)
{
	assert(sp!=NULL);
	int i, pos, idx, del=-1;
	pos=(id % 1009);
  
	for(i=0; i<sp->length; i++)
	{
		idx=(pos+i)%(sp->length); // lets us traverse whole array instead of only traversing from the position given to end

		if(sp->flag[idx]==EMPTY)
		{
			if(del!=-1) //returns a deleted spot before an empty spot
				return del;
			return idx;
		}
		else if(sp->flag[idx]==DELETED)
		{	
			if(del==-1)
				del=idx; //returns where the elt should be if it ends up not being found
		}
		else if(sp->data[idx]==id)
		{
			*found=true;
			return idx;
		}	
	}
	return -1;
}	

// Function to remove a student given their id number
// runtime: O(n) [expected: O(1)]
void addStudent(SET*sp, int age, int id)
{
	assert(sp!=NULL);
	int i;
	bool found = false; //bool doesn't change in search function
	i = hashsearch(sp, id, &found);
	if(found==true) // if the word is already in the set
		return;
	
	sp->data[i]=id;
	sp->ages[i]=age;
	sp->flag[i]=FILLED; //update flag
	sp->count++;

	return;
}

// Function to remove a student given their id number
// runtime: O(n) [expected: O(1)]
void removeStudent(SET *sp, int id)
{
	assert(sp!=NULL);
	int i;
	bool found=false; //bool doesn't change to false in search function
	printf("Removing for student ID:%d\n", id);
	i = hashsearch(sp, id, &found);
	if(found==false) // if the word wasn't found in the set
	{	printf("ID number not found\n");
		return;
	}
	printf("Deleted: ID - %d Age - %d\n", sp->data[i], sp->ages[i]);
	sp->flag[i]=DELETED; //update flag
	sp->count--;
	return;
}

// Function to search for a student given their id number
// runtime: O(n)
int searchID(SET *sp, int id)
{
	assert(sp!=NULL);
	int idx;
	bool found=false; //bool doesn't change in search function
	printf("Searching for student ID:%d\n", id);
	idx = hashsearch(sp, id, &found);
	if(found==false) // if the word wasn't found in the set
	{	printf("ID number not found\n");
		return 1;
	}
	printf("Found: ID - %d  Age - %d\n", sp->data[idx], sp->ages[idx]);
	return sp->data[idx]; // return the element with index found in search function
} 

