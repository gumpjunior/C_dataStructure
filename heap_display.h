/*
 * heap_display.h
 *
 *  Created on: Nov 27, 2014
 *      Author: djiao
 */

#ifndef HEAP_DISPLAY_H_
#define HEAP_DISPLAY_H_

int maxidx(int row, int size);
int heap_left(int npos, int size);
int heap_right(int npos, int size);
int escntlh(int npos, int size);
int esbtw(int escntlh);
void heap_display(int *heap, int size);

void func_test_in_heap_display__c(int npos, int size, int row);
void func_test2_in_heap_display__c(int npos, int size, int *heap);



#endif /* HEAP_DISPLAY_H_ */
