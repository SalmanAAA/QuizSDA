#include <stdio.h>
#include<stdlib.h>
#include "module.h"


Node* createNode(int value){ // membuat node baru
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    }else{
        printf("Alokasi gagal\n");
        return NULL;
    }
}

void displayList(LinkedList *list){ // menampilkan elemen list yang telah di isi
    Node *temp =list->head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

}

void insertFirst(LinkedList *list, int value){ // memasukkan elemen pertama pada list
    Node* newNode = createNode(value);
    if (newNode == NULL) return;
    newNode -> next = list->head;
    list->head = newNode;
    displayList(list);

}

void insertLast(LinkedList *list,int value){ // memasukkan elemen terakhir pada list
    Node* newNode = createNode(value);
    if (newNode == NULL) return;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    displayList(list);
}

void insertAfter(LinkedList *list,int target ,int value){ // memasukkan elemen setelah dari target elemen(elemen yang ditunjuk)
    Node* temp = list->head;
    while (temp != NULL && temp->data != target){
        temp = temp->next;
    }
    if(temp != NULL){
        Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    displayList(list);

}

void deleteLast(LinkedList *list){ // menghapus elemen terakhir pada list
    if(list->head == NULL){
        printf("underflow!!\n");
        return;
    }
    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
    }else{
        Node* temp = list->head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    displayList(list);
}

void deleteFirst(LinkedList *list){ // menghapus elemen pertama pada list
    if (list->head == NULL){
        printf("underflow!!\n");
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    displayList(list);
}

void deleteValue(LinkedList *list,int value){ // menghapus elemen yang ada pada list
    if(list->head == NULL){
        printf("underflow!!\n");
        return;
    }
    if(list->head->data == value){
        deleteFirst(list);
        return;
    }
    Node *temp = list->head;
    while (temp->next != NULL && temp->next->data != value){
        temp = temp->next;
    }
    if (temp->next != NULL){
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        free(deleteNode);
    }
    displayList(list);
}

void clearList(LinkedList *list) { // menghapus elemen list
    while (list->head != NULL) {
        deleteLast(list);
        deleteFirst(list);
    }
    printf("Linked List kosong\n");
    displayList(list);
}




int main(){

    LinkedList list;
    list.head = NULL;
    
    printf("1.... insert First 7\n");
    insertFirst(&list, 7);

    printf("\n2... insert Last 11\n");
    insertLast(&list, 11);

    printf("\n3... insert after 9 after 7\n");
    insertAfter(&list, 7, 9);

    printf("\n4... insert bilangan 5 di awal list\n");
    insertFirst(&list, 5);

    printf("\n5... masukkan bilangan 13 di akhir list\n");
    insertLast(&list , 13);

    printf("\n6... hapus bilangan 13 di list\n");
    deleteLast(&list);

    printf("\n7... hapus bilangan 7 yang ada didalam list\n");
    deleteValue(&list, 7);

    printf("\n8... hapus bilangan pertama uang ada didalam list\n");
    deleteFirst(&list);

    printf("\n9... delete all elements\n");
    clearList(&list);
    
    return 0;


}