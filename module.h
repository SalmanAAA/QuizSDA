#ifndef MODULE_H
#define MODULE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Node { //ADT NODE
    int data;
    struct Node* next;
} Node;

typedef struct { //ADT LINKEDLIST
    Node* head;
} LinkedList;

Node* createNode(int value);
void displayList(LinkedList *list);
void insertFirst(LinkedList *list, int value);
void insertLast(LinkedList *list, int value);
void insertAfter(LinkedList *list,int target, int value);
void deleteLast(LinkedList *list);
void deletFirst(LinkedList *list);
void deleteValue(LinkedList *list,int value);
void clearList(LinkedList *list);

#endif