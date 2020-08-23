/* Ashley Troske
 * Coen 12L- W5:15
 * 6/5/19
 * Tests college data type-set. APP2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "set.h"

int main(void)
{
	int maxElts=3000;
	int i, age, id=0;
	SET *sp =createSet(maxElts);
	srand(time(NULL));

	for(i=0; i<1000; i++)
	{
		id+=1+rand()%2;
		age=(rand()%13+18);
		addStudent(sp, age, id);
	}

	id=(rand()%2001)+1;
	searchID(sp, id);
	id=(rand()%2001)+1;
	removeStudent(sp, id);
	
	destroySet(sp);
	
	return 0;
}
