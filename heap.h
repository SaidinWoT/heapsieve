#ifndef __HEAP_H
#define __HEAP_H

#define HEAP_INIT_SIZE 8

typedef struct _HNode HNode;
typedef struct _Heap Heap;

HNode *makeNode(unsigned long long);
Heap *makeHeap();
void freeHeap();

void insert(Heap *, HNode *);
void incHead(Heap *);
unsigned long long peek(Heap *);

#endif /* !__HEAP_H */
