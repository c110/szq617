#include<stdio.h>
#include"stdlib.h"
#include"node.h"
void print(node* first) {
	if (first == NULL) return; 
	node* p = first->prev; 
	p->next = NULL;
	p = first; 
	while (p != NULL) {
		printf("%d\n", p->value); 
		node* tmp= p;
		p = p->next;
		free(tmp);
	}
}
