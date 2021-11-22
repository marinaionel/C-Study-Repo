//
// Created by Marina Ionel on 23/03/2020.
//

#pragma once

#include <stdint.h>

typedef enum ListReturnCode {
    LIST_OK, LIST_EMPTY, LIST_NOT_FOUND, LIST_NULL, LIST_ERROR
} ListReturnCode;

typedef struct list *list_t;

ListReturnCode list_destroy(list_t self);

list_t list_create();

ListReturnCode list_addItem(list_t self, void *item);

ListReturnCode list_removeItem(list_t self, void *item);

ListReturnCode list_getItem(list_t self, void **item, uint16_t index);

uint16_t list_noOfItems(list_t list);
