# t617
0-1
#ifndef __NODE_H__
#define __NODE_H__
typedef struct node {
    int value;
    struct node* prev;
    struct node* next;
}node;
#endif
#include<stdio.h>
#include"func.h"
node* add(node* first, int value) {
    if (first == NULL) {
        first = (node*)malloc(sizeof(node));
        first->prev = first->next = first;
        first->value = value;
        return first;
    }
    node* p = first->prev;
    node* q = first;
    node* tmp = (node*)malloc(sizeof(node));
    tmp->value = value;
    tmp->next = q;
    tmp->prev = p;
    p->next = tmp;
    q->prev = tmp;
    first = tmp;
    return first;
}
int main() {
    int n;
    int y, i;
    scanf("%d", &n);
    node* first = NULL;
    for (i = 1; i <= n; i++) {
        scanf("%d", &y);
        first = add(first, y);
    }
    print(first);
    return 0;
}
#include"node.h"
#include<malloc.h>
void print(node* first) {
    if (first == NULL) return;
    node* p = first->prev;
    p->next = NULL;
    p = first;
    while (p != NULL) {
        printf("%d\n", p->value);
        node* tmp = p;
        p = p->next;
        free(tmp);
    }
}
