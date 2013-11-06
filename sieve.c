#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


int main(int argc, char **argv) {
    unsigned long long n, limit;
    Heap *h;
    HNode *p;
    if(argc != 2) {
        printf("Usage: ./primes <limit>\n");
        return 0;
    }
    limit = atoll(argv[1]);
    h = makeHeap();
    p = makeNode(3);
    insert(h, p);
    /* printf("2, 3, "); */
    for(n = 5; n < limit; n += 2) {
        if(n != peek(h)) {
            free(p);
            p = makeNode(n);
            insert(h, p);
            /* printf("%d, ", n); */
        } else {
            while(n == peek(h)) {
                incHead(h);
            }
        }
    }
    /* printf("ad infinitum.\n"); */
    freeHeap(h);
    free(p);
    return 0;
}
