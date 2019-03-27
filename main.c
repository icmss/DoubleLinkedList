#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    ts_list *list1 = create_list();
    test_ts_list(list1);
    push_front(list1, "677uyg");
    test_ts_list(list1);
    push_front(list1, "trhrthrt");
    test_ts_list(list1);
    push_front(list1, "trtr");
    test_ts_list(list1);
    push_front(list1, "ggg");
    test_ts_list(list1);
   delete_node(list1, 4);
   test_node_n(list1, 3);
    for(int i = 1; i <= list1->size; i++)
        test_node_n(list1, i);
    while(list1->size)
        delete_node(list1, 1);
    test_ts_list(list1);
    printf("Hello world!\n");
    return 0;
}

void test_ts_list(ts_list *list){
    printf("list size: %d\n"
           "head: %x\n"
           "tail: %x\n\n",
           list->size,
           list->head,
           list->tail);

}

void test_node_n(ts_list *list, int n){
    ts_node *node = get_node(list, n);
    printf("node %d date: %x\n"
           "next: %x\n"
           "prev: %x\n\n",
           n,
           node->data,
           node->next,
           node->prev);
}
