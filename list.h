#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define DEL_NODE(node_ptr) free(node_ptr->data);\
                           free(node_ptr);

typedef struct _node {
    void *data;
    struct _node *prev;
    struct _node *next;
} ts_node;

typedef struct _list {
    int size;
    ts_node *head;
    ts_node *tail;
} ts_list;

ts_list *create_list(void);
void delete_list(ts_list *);

void push_front(ts_list *list, void *data);
void push_back(ts_list *list, void *data);
void insert_node(ts_list *list, int n, void *data);
ts_node *get_node(ts_list *list, int n);
void delete_node(ts_list *list, int n);

#endif // LIST_H_INCLUDED
