#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define NEW_NODE_CALLOC ts_node *new_node = calloc(1, sizeof(ts_node));


ts_list *create_list(void){
    ts_list *new_list = calloc(1, sizeof(ts_list)); // calloc или malloc?
    return new_list;
}

void delete_list(ts_list *list){
    while(list->size)
        delete_node(list, 1);
    free(list);
}

void push_front(ts_list *list, void *data){
    if(!list->size)
        insert_first(list, data);
    else {
        NEW_NODE_CALLOC;
        ts_node *first = list->head;
        list->head = new_node;
        first->prev = new_node;
        new_node->next = first;
        new_node->data = data;
        list->size++;
    }
}

void push_back(ts_list *list, void *data){
    if(!list->size)
        insert_first(list, data);
    else {
        NEW_NODE_CALLOC;
        ts_node *last = list->tail;
        list->tail = new_node;
        last->next = new_node;
        new_node->prev = last;
        new_node->data = data;
        list->size++;
    }
}

void insert_first(ts_list *list, void *data){
    NEW_NODE_CALLOC;
    list->head = list->tail = new_node;
    new_node->data = data;
    list->size++;
}

void insert_node(ts_list *list, int n, void *data){ // нет проверки для n
    if(!list->size)
        insert_first(list, data);
    else if(n == 1)
        push_front(list, data);
    else if(n == list->size + 1)
        push_back(list, data);
    else {
        ts_node *tmp = list->head;
        for(int i = 1; i < n; i++)
            tmp = tmp->next;
        NEW_NODE_CALLOC;
        new_node->next = tmp;
        new_node->prev = tmp->prev;
        tmp->prev->next = new_node;
        tmp->prev = new_node;
        new_node->data = data;
        list->size++;
    }
}

ts_node *get_node(ts_list *list, int n){
    ts_node *tmp = list->head;
    for(int i = 1; i < n; i++)
        tmp = tmp->next;
    return tmp;
}

void delete_node(ts_list *list, int n){
    if(list->size = 1){
        free(list->head->data);
        free(list->head);
        list->head = list->tail = NULL;
    }
    else if(n == 1){
        ts_node *tmp = list->head;
        list->head = list->head->next;
        list->head->next->prev = NULL;
        DEL_NODE(tmp);
    }
    else if(n == list->size){
        ts_node *tmp = list->tail;
        list->tail = list->tail->prev;
        list->tail->prev->next = NULL;
        DEL_NODE(tmp);
    }
    else {
        ts_node *tmp = list->head;
        for(int i = 1; i < n; i++)
            tmp = tmp->next;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        DEL_NODE(tmp);
    }
    list->size--;
}

