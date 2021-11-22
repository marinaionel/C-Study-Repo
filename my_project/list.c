//
// Created by Marina Ionel on 25/02/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node {
    int data;
    struct node *next;
};

struct list {
    Node *head;
};

Node *create_node(int data);

Node *create_node(int data) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

List *makelist() {
    List *list = malloc(sizeof(List));
    if (!list) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

void display(List *list) {
    Node *current = list->head;
    if (list->head == NULL)
        return;

    for (; current != NULL; current = current->next) {
        printf("%d\n", current->data);
    }
}

void add(int data, List *list) {
    Node *current = NULL;
    if (list->head == NULL) {
        list->head = create_node(data);
    } else {
        current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = create_node(data);
    }
}

void delete(int data, List *list) {
    Node *current = list->head;
    Node *previous = current;
    while (current != NULL) {
        if (current->data == data) {
            previous->next = current->next;
            if (current == list->head)
                list->head = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void reverse(List *list) {
    Node *reversed = NULL;
    Node *current = list->head;
    Node *temp = NULL;
    while (current != NULL) {
        temp = current;
        current = current->next;
        temp->next = reversed;
        reversed = temp;
    }
    list->head = reversed;
}

void destroy(List *list) {
    Node *current = list->head;
    Node *next = current;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}