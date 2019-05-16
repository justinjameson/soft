#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Node Functions
node* newNode(char g, int s)
{
	node* n = (node*)malloc(sizeof(node));
	n->grade = g;
	n->score = s;
	
	return n;
}

void  setGrade(node* n, char g)
{
	n->grade = g;
}

void  setScore(node* n, int s)
{
	n->score = s;
}

void  setNext(node* n, node* nx)
{
	n->next = (struct node*)nx;
}

char  getGrade(node* n)
{
	return n->grade;
}

int   getScore(node* n)
{
	return n->score;
}

node* getNext(node* n)
{
	return (node*)n->next;
}

//List Functions
void setHead(list* l, node* n)
{
	l->head = n;
}

void setTail(list* l, node* n)

{
	l->tail = n;
}

void setCursor(list* l, node* n)
{
	l->cursor = n;
}

void addNode(list* l, node* n) //Push
{
	if(getEntries(l) == 0)
	{
		setHead(l, n);
		setTail(l, n);
		l->entries++;
		return;
	}
	
	setNext(getTail(l), n);
	setTail(l, n);
	l->entries++;
}

void addNodeAt(list* l, node* n, int i) //Insert after i
{
	if(i == 0)
	{
		setNext(n, getHead(l));
		setHead(l, n);
		l->entries++;
		return;
	}
	
	setCursor(l, getHead(l));
	for(int e = 0; e < i; e++)
	{
		forward(l);
	}
	
	setNext(n, getNext(getCursor(l)));
	setNext(getCursor(l), n);
	l->entries++;
}

node* getHead(list* l)
{
	return l->head;
}

node* getTail(list* l)
{
	return l->tail;
}

node* getCursor(list* l)
{
	return l->cursor;
}

unsigned int getEntries(list* l)
{
	return l->entries;
}

void forward(list* l)
{
	if(getNext(getCursor(l)))
	{
		l->cursor = getNext(getCursor(l));
	}
}