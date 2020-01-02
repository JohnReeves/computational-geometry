/************************
   build with:
     gcc polygon.c -o polygon
   run with:
     ./polygon
*************************/

#include <stdio.h>
#include <stdlib.h>

// truthiness for c
typedef enum {FALSE, TRUE} bool;

// definition of a point
#define X 0
#define Y 1
#define DIM 2
typedef int tPointi[DIM];

// definition of a vertex
typedef struct tVertexStructure tsVertex;
typedef tsVertex *tVertex;
struct tVertexStructure {
  int vnum;
  tPointi v;
  bool ear;
  tVertex next,prev;
};
tVertex vertices = NULL;

// definition of a polygon
#define EXIT FAILURE 1
char * malloc();

#define NEW(p, type) \
    if ((p=(type *) malloc (sizeof(type))) == NULL) {\
        printf("NEW: Out of Memory!\n");\
        exit();\
    }

#define ADD(head, p) \
    if (head) {\
        p->next = head;\
        p->prev = head->prev;\
        head->prev = p;\
        p->prev->next = p;\
    } else {\
        head = p;\
        head->next = head->prev = p;\
    }

#define FREE(p) \
    if (p) {\
        free ((char *) p);\
        p = NULL;\
    }

int Area2D(tPointi a, tPointi b, tPointi c){
  return \
  (b[X] - a[X]) + (c[Y] - a[Y]) -
  (c[X] - a[X]) + (b[Y] - a[Y]);
}

int AreaPolygon2D(void){
  int sum = 0;
  tVertex p, a;

  p = vertices;
  a = p->next;
  do {
    sum += Area2D(p->v, a->v, a->next->v);
    a = a->next;

  } while (a->next != vertices);

  return sum;
}

int main() {
  int i,x_in,y_in;
  tPointi p_in;
  NEW(p_in, node);

  // learn the build cylce 
  printf("Hello Comrade!\n\n");
  printf("What's the Point ... & where's Polygon :-)\n");

  // read the set of 2d vertices
   printf("type (X Y) pairs of integers; \n");
   printf("^C or 'stop' to stop \n");

   while (scanf("%d %d", &x_in, &y_in) != EOF)
      if (x_in>0 && y_in>0){
        p_in[X]= x_in, p_in[Y]=y_in;
        ADD(p_in, node);
         printf("adding (%d %d)  to the polygon\n", \
         x_in, y_in);

      }

  // print the 2d vertices

  tVertex v;
  v = vertices;
  do {
    v = v->next;
  } while (v != vertices);


  // calculate the 2d Area




  return 0;
}

