//
// Created by Marina Ionel on 25/04/2020.
//
#include "../linked_list/list.h"
#include <stdio.h>

main() {
    list_t list = list_create();
    char *la = "lala";
    list_addItem(list, la);
    printf("%d", list_noOfItems(list));

    list_destroy(list);
}