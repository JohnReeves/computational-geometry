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
typedef struct vertex tsVertex;
typedef tsVertex *tVertex;

struct vertex {
  int vnum;
  tPointi v;
  bool ear;
  tVertex next, prev;
};

tVertex head = NULL;
tVertex last = NULL;

tVertex current = NULL;

//display the list from the beginning
void printList() {
   tVertex ptr = head;

   printf("\n[head] <=>");
   while(ptr != NULL) {        
      printf(" %d (%d %d) <=>",\
               ptr->vnum, ptr->v[X], ptr->v[Y]);
      ptr = ptr->next;
   }

   printf(" [tail]\n");
}

//display the list from the end
void print_backward() {
   tVertex ptr = last;

   printf("\n[last] <=>");
   while(ptr != NULL) {        
      printf(" %d (%d %d) <=>",\
               ptr->vnum, ptr->v[X], ptr->v[Y]);
      ptr = ptr->prev;
   }

   printf(" [head]\n");
}

//Create Linked List
void insert(tPointi v) {
   // Allocate memory for new node;
   tVertex link = (tVertex) malloc(sizeof(tsVertex));

   link->vnum = vertexCount++;
   for (int i = 0; i < DIM; i++) link->v[i] = v[i];
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

int Area2D(tPointi a, tPointi b, tPointi c){
  return \
  (b[X] - a[X]) + (c[Y] - a[Y]) -
  (c[X] - a[X]) + (b[Y] - a[Y]);
}

int AreaPolygon2D(void){
  int sum = 0;
  tVertex p, a;

  p = head;
  a = p->next;
  do {
    sum += Area2D(p->v, a->v, a->next->v);
    a = a->next;

  } while (a->next != NULL);

  return sum;
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

   printf("area of the polygon is %d \n", AreaPolygon2D());
   
   return 0;
}