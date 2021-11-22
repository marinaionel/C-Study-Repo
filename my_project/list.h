//
// Created by Marina Ionel on 25/02/2020.
//

#ifndef MY_PROJECT_LIST_H
#define MY_PROJECT_LIST_H

typedef struct node Node;

typedef struct list List;

List * makelist();
void add(int data, List * list);
void delete(int data, List * list);
void display(List * list);
void reverse(List * list);
void destroy(List * list);

#endif //MY_PROJECT_LIST_H
