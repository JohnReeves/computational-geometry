#include <stdio.h>
#include <stdlib.h>

// truthiness for c
typedef enum {FALSE, TRUE} bool;

// definition of a point
#define X 0
#define Y 1
#define DIM 2
typedef int tPointi[DIM];

// definition of a list node
int vertexCount=0;
typedef struct node tsNode;
typedef tsNode *tNode;

struct node {
  int vnum;
  tPointi data;
  bool ear;
  tNode next, prev;
};

tNode head = NULL;
tNode last = NULL;

tNode current = NULL;

//display the list from the beginning
void printList() {
   tNode ptr = head;

   printf("\n[head] <=>");
   while(ptr != NULL) {        
      printf(" %d %d %d <=>",\
               ptr->vnum, ptr->data[X], ptr->data[Y]);
      ptr = ptr->next;
   }

   printf(" [last]\n");
}

//display the list from the end
void print_backward() {
   tNode ptr = last;

   printf("\n[head] <=>");
   while(ptr != NULL) {        
      printf(" %d %d %d <=>",\
               ptr->vnum, ptr->data[X], ptr->data[Y]);
      ptr = ptr->prev;
   }

   printf(" [last]\n");
}

//Create Linked List
void insert(tPointi data) {
   // Allocate memory for new node;
   tNode link = (tNode) malloc(sizeof(tsNode));

   link->vnum = vertexCount++;
   for (int i = 0; i < DIM; i++) link->data[i] = data[i];
   link->prev = NULL;
   link->next = NULL;

   // If head is empty, create new list
   if (head == NULL) {
      head = link;
      return;
   }

   current = head;
   
   // move to the end of the list
   while (current->next != NULL)
      current = current->next;

   // Insert link at the end of the list
   current->next = link;
   last = link;
   link->prev = current;
}

int main() {
   insert((tPointi){10,10});
   insert((tPointi){10,20});
   insert((tPointi){10,30});
   insert((tPointi){10,1});
   insert((tPointi){10,40});
   insert((tPointi){10,56}); 

   printList();
   print_backward();
   
   return 0;
}