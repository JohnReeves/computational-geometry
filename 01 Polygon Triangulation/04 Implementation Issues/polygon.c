/************************
   build with:
     gcc polygon.c -o polygon
   run with:
     ./polygon
*************************/

#include <stdio.h>

// truthiness for c
typedef enum {FALSE, TRUE} bool;

// definition of a point
#define x 0
#define y 1
#define DIM 2
typedef int tPointi[DIM];

// definition of a vertex
typedef struct tVertexStructure tsVertex;
typedef tsVertex *tVertex;
struct tVertexStructure {
  int vnum;
  tPoint v;
  bool ear;
  tVertex next.prev;
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
  (c[X] - a[X]) + (b[Y] - a[Y])
}

int AreaPolygon2D(void){
  int sum = 0;
  tVertex p, a;

  p = vertices;
  a = p->next;
  do {
    sum += Area2(p->v, a->v, a->next->v);
    a = a->next;

  } while (a->next != vertices)

  return sum;
}

int main() {
  // learn the build cylce 
  printf("Hello, Mate!\n\n");
  printf("Points & Polygons \n");

  // dealing with vertices
  tVertex v;
  v = vertices;
  do {
    v = v->next;
  } while (v != vertices);

  return 0;
}

