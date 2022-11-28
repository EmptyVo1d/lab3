#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"
#include "change.h"
#include "SUM.h"
#include "input.h"
#include "view.h"
#include "easterEgg.h"


int main() {
    int col, flag = 1;
    int *arr;
    int *arr2;
    int **pointer = &arr;
    int **pointer2 = &arr2;
    while (flag) {
        printf("if you want to initialize an array, press 1\nif you want to change the array, press 2\nif you want to find the amount, press 3\nif you want to view array, press 4\nif you want to exit, press 0");
        flag = input();
        if (flag == 0) break;
        if (flag == 1) arr = initialization(&col);
        if (flag == 2) *arr = change(pointer, &col, arr);
        if (flag == 3) *arr = SUM(pointer, &col, arr, arr2, pointer2);
        if (flag == 4) view(arr, &col);
        if (flag == 404) easterEgg();
    }
    for (int i = 0; i < col; i++) {
        printf("%d", arr[i]);
    }
    if (arr != NULL) {
        free(arr);
        arr = NULL;
    }
    if (arr2 != NULL) {
        free(arr2);
        arr2 = NULL;
    }
    return 0;
}
