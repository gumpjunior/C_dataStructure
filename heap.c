#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

#define heap_parent(npos) ((int)(npos/2))
/***************************************************************
 * before call "heap_left", the caller should make sure the
 * left node eixst.
 **************************************************************/

//#define heap_left(npos) ((int)(npos*2))
int heap_left(int npos, int size){
    int leftnode = (int)(npos*2);
    if( leftnode > size ){
        exit(EXIT_FAILURE);
    }
    return leftnode;
}

/***************************************************************
 * before call "heap_right", the caller should make sure the
 * right node eixst.
 **************************************************************/

//#define heap_right(npos) ((int)(npos*2+1))
int heap_right(int npos, int size){
    int rightnode = (int)(npos*2+1);
    if(rightnode > size){
        exit(EXIT_FAILURE);
    }
    return rightnode;
}
/**********************************************************
 * Compare
 *********************************************************/
int compare (const void *node1, const void *node2){
//int compare (void *node1, void *node2){
// incorrect, coz in heap_init declaration, "const" keyword is required
    int newnode1;
    int newnode2;

    if(node1 == NULL){
        return -1;
    }
    if(node2 == NULL){
        return 1;
    }
    newnode1 = *(int *)node1;
    newnode2 = *(int *)node2;

    //if( *(int *)node1>*(int *)node2 ){
    if( newnode1 > newnode2 ){
        return 1;
    }
    else if( newnode1 < newnode2 ){
        return -1;
    }
    else{
        return 0;
    }
}
//int heap_compare(void *data1, void *data2){
/*int compare (const void *node1, const void *node2){
    if(*node1>*node2){
        return 1;
    }
    else if(*node1<*node2){
        return -1;
    }
    else{
        return 0;
    }
}
*/

/**********************************************************
 *
 *********************************************************/
void destroy(void *data){
	// de-allocate the last item space of the whole arr;
	free(data);
	/* NOT possible to modify the value of pointer in this way.
	 * Two-level tranfer required. Refer <C pointer> P68.
	 * So statement below is incorrect.*/
	// data = NULL;
}

/**********************************************************
*
**********************************************************/

void heap_init(
    //_Heap *heap,
	sHeap *heap,
    int  (*compare)(const void *node1, const void *node2),
    void (*destroy)(void *data)
    ){
	heap->size = 0;
	heap->tree = NULL;
	heap->compare = compare;
	heap->destroy = destroy;
}

/**********************************************************
*
**********************************************************/

void heap_destroy(sHeap *heap){
	int i;
	//for(i=0;i<heap->size;i++){
	for(i=0;i<heap_size(heap);i++){
		heap->destroy(heap->tree[i]);
	}
	heap->size = 0;
	heap->tree = NULL;
	heap->compare = NULL;
	heap->destroy = NULL;
}

/**********************************************************
*
**********************************************************/

int heap_insert(sHeap *heap, const void *data){

    void **temp;
    int ipos, ppos;

    temp = (void **)realloc(heap->tree, (heap_size(heap)+1)*sizeof(void *));
    if(temp == NULL){
        return -1;
    }
    heap->tree = temp;

    heap->tree[heap_size(heap)+1] = (void *)data;

    // heapify the tree
    ipos = heap_size(heap)+1;
    ppos = heap_parent(ipos);
    while( ipos != 0 ){     // node index starting from 0
        if( heap->compare(heap->tree[ipos], heap->tree[ppos]) ){
            temp = heap->tree[ipos];
            heap->tree[ipos] = heap->tree[ppos];
            heap->tree[ppos] = temp;
        }
        ipos = ppos;
        ppos = heap_parent(ipos);
    }

    heap->size++;

    return 0;
}



/**********************************************************
*
**********************************************************/

//int heap_extract(sHeap *heap, void **data);
//#define heap_size(_Heap *heap)  heap->size;
//data type definition in macro is not required;

/**********************************************************
*
**********************************************************/

void test_func1(void){
    printf("pos mark 3");
    int var = 13;
    int var2 = 7;
    sHeap *heap;
    heap = (sHeap *)malloc(sizeof(heap));

    printf("pos mark 1");

    heap_init(heap, compare, destroy);
    heap_insert(heap, &var);
    printf("heap->size      = %d\n", heap->size);
    printf("heap-size(heap) = %d\n", heap_size(heap));
    heap_insert(heap, &var2);
}













