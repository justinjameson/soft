#include <stdio.h>
#include "list.h"

int main()
{
	list results;
	
	addNode(&results, newNode('A', 100));
	addNode(&results, newNode('B', 89));
	addNode(&results, newNode('D', 65));
	addNode(&results, newNode('F', 50));
	
	addNodeAt(&results, newNode('C', 77), 1);
	
	setCursor(&results, getHead(&results));
	
	//Print List
	printf("<RESULTS LIST>\n\n");
	printf("\tNumber of entries: %i\n\n", getEntries(&results));
	
	int e = 0;
	do
	{
		printf("\t------------------\n");
		printf("\t\tResult %i:\n", e++);
		printf("\t\tGrade: %c\n", getGrade(getCursor(&results)));
		printf("\t\tScore: %i\n", getScore(getCursor(&results)));
		printf("\t------------------\n");
		
		forward(&results);
	}
	while(e < getEntries(&results));
}