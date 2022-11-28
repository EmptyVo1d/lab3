//
// Created by evgen on 20.11.2022.
//
#include <stdio.h>
#include "SUM.h"
#include <stdlib.h>

int SUM(int **pointer, int *col, int *arr, int *arr2, int **pointer2) {
    int sum = 0, sumAns = 0;
    int iAns=0, jAns=0;
    int col2=0;
    for (int i = 0; i < *col; i++) {
        for (int j = 0; j < *col; j++) {
            for (int z = i; z <= j; z++) {
                sum = sum + arr[z];
            }
            if (sumAns < sum) {
                sumAns = sum;
                iAns = i;
                jAns = j;
            }
            sum = 0;
        }
        sum = 0;
    }
    col2 = jAns - iAns;
    col2 ++;
    int iAns1=iAns;
    *pointer2 = malloc(col2 * sizeof(int));
    arr2 = *pointer2;
    for (int i = 0; i < col2; i++) {
       arr2[i]=arr[iAns];
       iAns++;
    }
    printf("arr2 = ");
    for(int i=0; i < col2; i++){
        printf("%d ", arr2[i]);
    }

    printf("\n");
    printf("arr = ");
    while (col2) {
        *col = *col - 1;
        *pointer = realloc(arr, *col * sizeof(int));
        arr = *pointer;
        for (int i = iAns1; i < *col; i++) {
            arr[i] = arr[i + 1];
        }
        col2--;
    }

    for (int i = 0; i < *col; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("sum = %d\n", sumAns);
    return *arr;
}
