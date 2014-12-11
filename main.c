/*
 ============================================================================
 Name        : heap_display.c
 Author      : djiao
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "heap_display.h"



int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 77, 888, 9, 109};
    func_test_in_heap_display__c(4, 10, 3);
    func_test2_in_heap_display__c(8, 10, arr);
    return EXIT_SUCCESS;
}
