#ifndef HEAP__H
#define HEAP__H

typedef struct _Heap{
    int         size;
    void        ** tree;
    int     (*compare)(const void *node1, const void *node2);
    // "destroy" below is for individual item in heap, diff from
    // "heap_destroy" to delete all the nodes in the heap;
    void    (*destroy)(void *data);
}sHeap;

void heap_init(
    //_Heap *heap,
	sHeap *heap,
    int  (*compare)(const void *node1, const void *node2),
    void (*destroy)(void *data)
    );
void heap_destroy(sHeap *heap);
int heap_insert(sHeap *heap, const void *data);
int heap_extract(sHeap *heap, void **data);
//#define heap_size(_Heap *heap)  heap->size;
//data type definition in macro is not required;
#define heap_size(heap) (heap->size)

int heap_left(int npos, int size);
int heap_right(int npos, int size);
int compare (const void *node1, const void *node2);

void test_func1(void);

#endif
