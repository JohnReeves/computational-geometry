/************************
   build with:
     gcc another_polygon.c -o yap
   run with:
     ./yap
*************************/

#include <stdio.h>
#include <stdlib.h>

// what passes for truthiness in c
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

//display the list
void print_forward() {
  for (tVertex ptr = head; ptr != NULL; ptr = ptr->next)
    printf(" %d (%d %d) \n",\
    ptr->vnum, ptr->v[X], ptr->v[Y]);
}

void print_backward() {
  for (tVertex ptr = last; ptr != NULL; ptr = ptr->prev) 
    printf(" %d (%d %d) \n",\
    ptr->vnum, ptr->v[X], ptr->v[Y]);
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
   int x, y;

   printf("Hello, Geometry afficionados!\n\n");
   printf("type pairs of numbers; \n");
   printf("'-1' to stop \n");

   while (scanf("%d %d", &x, &y))
      if (x>0 && y>0)
         insert((tPointi){x,y});
      else
         break;

   printf("Your poligon is: \n");
   print_forward();

   printf("area of the polygon is %d \n", AreaPolygon2D());
   
   return 0;
}