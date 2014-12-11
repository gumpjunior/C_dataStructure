/*
 * heap_display.c

 *
 *  Created on: Nov 27, 2014
 *      Author: djiao

 *  NOTE:
 *      Organize the heap according rulls in <introduction to
 *      Algorithms> 3rd edition
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "heap_display.h"

/***************************************************************
 * coz tab size for different compiler is different
 * for someone compiler tab = 8 spaces
 * but "%d\t" is used below, so sometimes use "%d  " instead
 * The original version is to use "\t"
 **************************************************************/

// #define TAB "\t"
#define TAB "    "
#define heap_parent(npos) ((int)(npos/2))

/***************************************************************
 * return heap height = total row nums
 * NOT TOTAL ROW NUMS OF A HEAP
 * bot heap height count and row count starting from 0
 * heap(10 nodes) has height = 3, but the first row is row 0,
 * with a height value 3;
 **************************************************************/

#define heap_height(size) ((int)(log(size)/log(2)))
// return current row number, where npos exists
#define row(npos) ((int)(log(npos)/log(2)))
// return height of current row, where npos exists
#define height(npos, size) heap_height(size)-row(npos)
// min/max index of current row, where npos exists
#define minidx(row) (int)pow(2, row)
int maxidx(int row, int size){
    int idx = ((int)pow(2, row+1))-1;
    idx = (idx>size)?size:idx;
    return idx;
}

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

/***************************************************************
 * return empty spaces before first node of current row;
 * escntlh = empty spaces count at left hand
 **************************************************************/

int escntlh(int npos, int size){
    int spacenum;
    if( height(npos, size) != 0){
        // node npos NOT in last row must have left kid
        spacenum = 2*escntlh(heap_left(npos, size), size) + 1;
    }
    else{
        spacenum = 0;
    }
    return spacenum;
}
/***************************************************************
 * esbtw = empty spaces between two nodes at the same row
 **************************************************************/

int esbtw(int escntlh){
    return (2*escntlh + 1);
}

/***************************************************************
 * heap_last_line_display:
 *      one "tab" btw each node, coz each num is less than 1000;
 *      '-1' coz heap array index starting from 0;
 **************************************************************/

void heap_display(int *heap, int size){
    int rowidx;
    int aheadsnum;      // spaces num before 1st node of each row
    int spacebtw;       // spaces num between two nodes
    int minindex;
    int maxindex;
    for(rowidx=0;rowidx<=heap_height(size);rowidx+=1){
        int tabidx, nodeidx;
        minindex  = minidx(rowidx);
        maxindex  = maxidx(rowidx, size);
        aheadsnum = escntlh(minindex, size);
        spacebtw  = esbtw(aheadsnum);
        // print all spaces before the 1st node
        for(tabidx=0;tabidx<aheadsnum;tabidx+=1){
            //printf("\t");
            printf(TAB);
        }
        // print nodes and spaces btw them
        for(nodeidx=minindex;nodeidx<=maxindex;nodeidx+=1){
            //printf("%d\t", *(heap+nodeidx-1));
            printf("%d", *(heap+nodeidx-1));
            if(*(heap+nodeidx-1)<10){
                printf("   ");
            }
            else if(*(heap+nodeidx-1)>9 && *(heap+nodeidx-1)<100){
                printf("  ");
            }
            else if(*(heap+nodeidx-1)>99 && *(heap+nodeidx-1)<1000){
                printf(" ");
            }
            //for(tabidx=0;tabidx<spacebtw;tabidx+=1){printf("\t");}
            for(tabidx=0;tabidx<spacebtw;tabidx+=1){printf(TAB);}
        }
        printf("\n\n");
    }
}

/***************************************************************
 * test the macros and funcs defined above
 **************************************************************/

void func_test_in_heap_display__c(int npos, int size, int row){
    int startidxoflastline;
    startidxoflastline = (int)pow(2, heap_height(size)) - 1;

    printf("npos = %d\n", npos);
    printf("size = %d\n", size);
    printf("row  = %d\n", row);
    printf("================================\n");
    //==========================================

    printf("the heap_parent index of %dth node is %d\n",
            npos, heap_parent(npos));
    printf("node count starting from 0");
    printf("the heap_height is %d\n", heap_height(size));
    printf("TOTAL ROW NUM IS %d\n", heap_height(size)+1);
    printf("current row # where %dth node exists is : %d\n",
            npos, row(npos));
    printf("height # where %dth node exists is : %d\n",
            npos, height(npos, size));
    printf("minidx of row %d is %d\n", row, minidx(row));
    printf("maxidx of row %d is %d\n", row, maxidx(row, size));

    printf("the first node index of last line is %d\n", startidxoflastline);
    printf("the count of last line first node is %d\n", startidxoflastline+1);

    printf("the heap_left of %dth node is %d\n",
            npos, heap_left(npos, size));
    printf("the heap_right of %dth node is %d\n",
            npos, heap_right(npos, size));
    printf("================================\n");
    //==========================================
}
void func_test2_in_heap_display__c(int npos, int size, int *heap){
    int aheadsnum = escntlh(npos, size);

    printf("npos = %d\n", npos);
    printf("size = %d\n", size);
    printf("================================\n");
    //==========================================

    printf("total number of empty spaces before the first node ");
    printf("at row %d is %d\n", row(npos), aheadsnum);
    printf("total number of empty spaces between two nodes ");
    printf("at row %d is %d\n", row(npos), esbtw(aheadsnum));
    printf("================================\n");
    //==========================================

    heap_display(heap, size);
}
