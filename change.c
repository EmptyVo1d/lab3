//
// Created by evgen on 20.11.2022.
//
#include "change.h"
#include <stdlib.h>
#include <stdio.h>
#include "input.h"

int change(int **pointer, int *col, int *arr) {
    int flag, id;
    int len = *col;
    printf("press 1 if you want to add an item\npress 0 if you want to delete an item\n");
    flag = input();
    printf("enter id\n");
    id = input();
    if (flag == 1) {
        if (id <= len) {
           len++;
            *pointer = realloc(arr, len * sizeof(int));
            arr = *pointer;
            printf("enter elements\n");
            for (int i = len; i >= id - 1; i--) {
                arr[i+1] = arr[i];
            }
            arr[id-1] = input();
            for (int i = 0; i < len; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        if (id > len) {
            len ++;
            *pointer = realloc(arr, len * sizeof(int));
            printf("enter elements\n");
            arr[len-1] = input();
            for (int i = 0; i < len; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
    if (flag == 0) {
        if (id > len) {
            printf("you are deleting a non-existent element");
            return 0;
        }
        for (int i = id-1; i < (len); i++) {
            arr[i] = arr[i + 1];
        }
        len= len - 1;
        *pointer = realloc(arr, len * sizeof(int));
        arr = *pointer;
        for (int i = 0; i < len; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    *col = len;
    return *arr;
}