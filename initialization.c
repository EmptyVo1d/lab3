//
// Created by evgen on 20.11.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"
#include "input.h"
int *initialization(int *col){
    printf("enter the number of elements\n");
    *col = input();
    int *pointer = malloc(*col * sizeof(int));
    printf("enter the array elements\n");
    for(int i=0; i<*col; i++){
        pointer[i] = input();
}
    return pointer;
}
