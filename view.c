//
// Created by evgen on 27.11.2022.
//

#include "view.h"
#include <stdio.h>
int view(int *arr, int *col){
    printf("arr = ");
    for (int i = 0; i < *col; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}