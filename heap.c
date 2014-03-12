#include <stdlib.h>
#include "heap.h"

struct _HNode {
    unsigned long long p;
    unsigned long long v;
};

struct _Heap {
    HNode *head;
    unsigned int tail;
    unsigned int size;
};

void resize(Heap *h) {
    HNode *old = h->head;
    unsigned int s = h->size;
    unsigned int i;
    h->size *= 2;
    h->head = calloc(h->size, sizeof(HNode));
    for(i = 0; i < s; ++i) {
        h->head[i] = old[i];
    }
    free(old);
}

void swap(Heap *h, unsigned int in, unsigned int dex) {
    HNode tmp = h->head[in];
    h->head[in] = h->head[dex];
    h->head[dex] = tmp;
}

void insert(Heap *h, HNode *n) {
    unsigned int ix = h->tail;
    unsigned int iy = (ix-1)/2;
    h->head[h->tail++] = *n;
    if(h->tail == h->size-1) {
        resize(h);
    }
    while(ix > 0 && h->head[ix].v < h->head[iy].v) {
        swap(h, ix, iy);
        ix = iy;
        iy = (ix-1)/2;
    }
}

void reheap(Heap *h) {
    HNode *a = h->head;
    unsigned int ix = 0;
    unsigned int iy = ix*2+1;
    unsigned int iz = iy+1;
    while(ix <= h->tail && (a[ix].v > a[iy].v || a[ix].v > a[iz].v)) {
        if(a[iy].v && a[iy].v < a[iz].v) {
            swap(h, ix, iy);
            ix = iy;
        } else if(a[iz].v) {
            swap(h, ix, iz);
            ix = iz;
        }
        iy = ix*2+1;
        iz = iy+1;
    }
}

unsigned long long peek(Heap *h) {
    return h->head[0].v;
}

void incHead(Heap *h) {
    h->head[0].v += 2*h->head[0].p;
    reheap(h);
}

Heap *makeHeap() {
    Heap *h = malloc(sizeof(Heap));
    h->size = HEAP_INIT_SIZE;
    h->head = calloc(HEAP_INIT_SIZE, sizeof(HNode));
    h->tail = 0;
    return h;
}

HNode *makeNode(unsigned long long p) {
    HNode *n = malloc(sizeof(HNode));
    n->p = p;
    n->v = p*p;
    return n;
}

void freeHeap(Heap *h) {
    free(h->head);
    free(h);
}
