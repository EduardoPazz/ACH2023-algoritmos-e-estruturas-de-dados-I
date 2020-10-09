#include <stdio.h>
#include <malloc.h>
#include "linked_list.h"

/* typedef struct aux {

} Element; */

void fixPointers(void* prev, void* actual, void* next) {
    prev->next = actual;

    actual->prev = prev;
    actual->next = next;

    next->prev = actual;
}

int main() {

    

    return 0;
}