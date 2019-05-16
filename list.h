#ifndef LIST_H_   /* Include guard */
#define LIST_H_

typedef struct
{
    char grade;
    int  score;
	
	struct node* next;
} node;

typedef struct
{
    node* head;
    node* tail;
	node* cursor;
	
	unsigned int entries;
} list;

//Node Functions
node* newNode(char g, int s);
void  setGrade(node* n, char g);
void  setScore(node* n, int s);
void  setNext(node* n, node* nx);

char  getGrade(node* n);
int   getScore(node* n);
node* getNext(node* n);

//List Functions
void setHead(list* l, node* n);
void setTail(list* l, node* n);
void setCursor(list* l, node* n);
void addNode(list* l, node* n);
void addNodeAt(list* l, node* n, int i);

node* getHead(list* l);
node* getTail(list* l);
node* getCursor(list* l);
unsigned int getEntries(list* l);
void forward(list* l);

#endif 