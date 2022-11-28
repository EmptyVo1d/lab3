//
// Created by evgen on 20.11.2022.
//
#include "change.h"
#include <stdlib.h>
#include <stdio.h>
#include "input.h"

int change(int **pointer, int *col, int *arr) {
    int flag, id;
    printf("press 1 if you want to add an item\npress 0 if you want to delete an item\n");
    flag = input();
    printf("enter id\n");
    id = input();
    if (flag == 1) {
        if (id <= *col) {
            *col=*col+1;
            *pointer = realloc(arr, (*col) * sizeof(int));
            arr = *pointer;
            printf("enter elements\n");
            for (int i = *col-1; i >= id-1; i--) {
                arr[i+1] = arr[i];
            }
            arr[id-1] = input();
            for (int i = 0; i < *col; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        if (id > *col) {
            *col = *col + 1;
            *pointer = realloc(arr, (*col) * sizeof(int));
            id = *col;
            printf("enter elements\n");
            arr[id - 1] = input();
            for (int i = 0; i < *col; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
    if (flag == 0) {
        if (id > *col) {
            printf("you are deleting a non-existent element");
            return 0;
        }
        for (int i = id-1; i < (*col - 1); i++) {
            arr[i] = arr[i + 1];
        }
        *col=*col-1;
        *pointer = realloc(arr, *col * sizeof(int));
        arr = *pointer;
        for (int i = 0; i < *col; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return *arr;
}