#include <stdio.h>
#include <stdlib.h>

typedef 
	struct node {
		int num ;
		struct node * next ;
	} 
	Node ;

Node list ;

int
is_contained(int num)
{
	Node * itr = list.next ;
	while (itr != 0x0) {
		if (itr->num == num)
			return 1 ;
		itr = itr->next ;
	}
	return 0 ;
}

void
insert_number(int num)
{
	if (is_contained(num))
		return ;

	Node * n = (Node *) malloc(sizeof(Node)) ;
	n->num = num ;
	n->next = list.next ;
	list.next = n ;
}

void
print_numbers() 
{
	Node * itr = list.next ;
	while (itr != 0x0) {
		printf("%d ", itr->num) ;
		itr = itr->next ;
	}
	printf("\n") ;
}

void 
remove_number(int num)
{
	Node * itr ;
	for (itr = &list ; itr->next != 0x0 ; itr = itr->next) {
		if (itr->next->num == num) {
			Node * nextnext = itr->next->next ;
			free(itr->next) ;
			itr->next = nextnext ;
			break ;
		}
	}
}

int
to_array(int ** arr) 
{
	//TODO: impelement here
}

int 
main() 
{
	int input ;
	list.next = 0x0 ;

	while (1) {
		scanf("%d", &input) ;
		if (input == 0) {
			break ;
		}
		else if (input > 0) {
			insert_number(input) ;
		}
		else /* input < 0 */ {
			remove_number(input * -1) ;
		}
	}
	print_numbers() ;

	/* added code */
	int n_arr, i ;
	int * arr ;
	n_arr = to_array(&arr) ;
	for (i = 0 ; i < n_arr ; i++)
		printf("%d ", arr[i]) ;
	printf("\n") ;
	free(arr) ;

	exit(0) ;
}