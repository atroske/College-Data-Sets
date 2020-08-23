/* Ashley Troske
 * Coen 12L- W5:15
 * 6/5/19
 * Tests college data type-list. APP3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "list.h"

int main(void)
{
	int i, age, id=0;
	LIST *lp = createList();
	srand(time(NULL));
	
	for(i=0; i<1000; i++)
	{
		id+=1+rand()%2;
		age=(rand()%13+18);
		addStudent(lp, age, id);
	}

	
	id=(rand()%2001)+1;
	searchID(lp, id);
	removeStudent(lp, id);
	
	maxAgeGap(lp);

	destroyList(lp);

	return 0;
}
