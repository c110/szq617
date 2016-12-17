#include<stdio.h>
#include"func.h"
#include"node.h"
node* add(node* first, int value) {
	if (first == NULL) {
		first = (node*)malloc(sizeof(node));
        first->prev = first->next = first;
    	first->value = value; return first;
	}
	node* p = first->prev;
	node* q = first;
	node* tmp = (node*)malloc(sizeof(node));
	tmp->value = value;
	tmp->next = q; 
	tmp->prev = p;
	p->next = tmp;
	q->prev = tmp;
    first = tmp; return first;
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

