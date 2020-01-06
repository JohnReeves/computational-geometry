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

  for (p = head, a = p->next;a->next != NULL; a = a->next) 
    sum += Area2D(p->v, a->v, a->next->v);

  return sum;
}

bool Left(tPointi a, tPointi b, tPointi c){
  return Area2D(a, b, c) > 0;
}

bool LeftOn(tPointi a, tPointi b, tPointi c){
  return Area2D(a, b, c) >= 0;
}

bool Collinear(tPointi a, tPointi b, tPointi c){
  return Area2D(a, b, c) == 0;
}

bool Xor(bool x, bool y){
  return !x ^ !y;
}

bool IntersectProp(tPointi a, tPointi b, tPointi c, tPointi d){
  
  if (
    Collinear(a,b,c) ||
    Collinear(a,b,d) ||
    Collinear(c,d,a) ||
    Collinear(c,d,b)
  ) 
  return FALSE;

  // else 
  return 
    Xor( Left(a, b, c), Left(a, b, d) ) &&
    Xor( Left(c, d, a), Left(c, d, b) );
}

bool Between(tPointi a, tPointi b, tPointi c){
  tPointi ba, ca;

  if ( !Collinear(a,b,c) ) 
  return FALSE;

  if ( a[X] != b[X] ) 
  return \
    (a[X] <= c[X]) && (c[X] <= b[X]) ||
    (a[X] >= c[X]) && (c[X] >= b[X]);

  // else 
  return \
    (a[Y] <= c[Y]) && (c[Y] <= b[Y]) ||
    (a[Y] >= c[Y]) && (c[Y] >= b[Y]);
}

bool Intersect(tPointi a, tPointi b, tPointi c, tPointi d){

  if ( IntersectProp(a,b,c,d) )
    return TRUE;
  // else 
  if ( Between(a,b,c) || Between(a,b,d) ||
       Between(c,d,a) || Between(c,d,b) ) 
    return TRUE;
  // else 
  return FALSE;
}

bool Diagonalie(tVertex a, tVertex b){
  tVertex c, c1;

  for (c = head, c1=c->next; c!=head; c=c->next){
    if ( (c != a) && (c1 != a) &&
         (c != b) && (c1 != b) )
    return FALSE;
  }
  return TRUE;
}

bool InCone(tVertex a, tVertex b){
  tVertex a0, a1;

  a0 = a->prev;
  a1 = a->next;

  if ( LeftOn(a->v, a1->v, a0->v) )
  return \
    Left(a->v, b->v, a0->v) &&
    Left(b->v, a->v, a1->v);
  // else
  return \
    !( LeftOn(a->v, b->v, a0->v) &&
       LeftOn(b->v, a->v, a1->v) );
}

bool Diagonal(tVertex a, tVertex b){
  return InCone(a, b) && InCone(b, a) && Diagonalie(a, b);
}

void EarInit( void ){
  tVertex v0, v1, v2;

  for (v1=head; v1!=head; v1=v1->next){
    v0 = v1->prev;
    v2 = v1->next;
    v1->ear = Diagonal( v0, v2 );
  }
}

void Triangulate( void ){
  tVertex v0, v1, v2, v3, v4;
  // int n = nvertices;

  EarInit();
  for (int n=nverticrs; n>3; n--){
    for (v2=head; v2!=head; v2=v2->next){
      if (v2->ear){
        v3 = v2->next; v4 = v3->next;
        v1 = v2->prev; v0 = v1->prev;

        PrintDiagonal(v1, v2);

        v1->ear = Diagonal(v0, v3);
        v3->ear = Diagonal(v1, v4);

        v1->next = v3;
        v3->prev = v1;
        head = v3;
      }
    }

  }
}

int main() {
  int x, y;

  // learn the build cylce 
  printf("Hello Comrade!\n\n");
  printf("What's the Point ... & where's Polygon :-)\n");

  printf("type pairs of numbers: \n");
  printf("'-1 -1' to stop \n");

  while (scanf("%d %d", &x, &y))
    if (x>0 && y>0)
      insert((tPointi){x,y});
    else
      break;

  printf("Your polygon is: \n");
  print_forward();

  printf("area of the polygon is %d \n", AreaPolygon2D());
   
  return 0;
}
