//
// Created by evgen on 21.11.2022.
//
#include <stdio.h>
#include "input.h"

int input(){
    int num;
    int err = scanf("%d", &num);
    while (err != 1) {
        printf("error\n");
        err = scanf("%*s%d", &num);
    }
    return num;
}