#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next;
};

// :)
ifstream fin;
ofstream fout;

// This function opens your files. 
// It is your choice to use .open() or freopen().
void file_handler(); 

int read_in_numbers(istream &in, int arr[]);

Node *create_linkedlist(int *arr, int size);

void print_linkedlist(ostream &out, Node *head);

void destruct_linkedlist(Node *head); 

// ------------------------------------------------------

int main() {
	
	file_handler(); // Open Your Files Here.
	
	int A[220]; // Array for the integers. There are at most 200 integers.
	
	// ------------------- TASK 1 --------------------
	/* 
		Please fill in the FILL HERE spots with suitable answers.
		This depends on what you did on TASK 2, so I suggest finish 2 first.
	*/
	
	int arr_size = read_in_numbers(fin,A);
	
	fout << arr_size << endl;
	
	Node *head = create_linkedlist(A, arr_size); 
		// Pointer "head" is a pointer to the first Node.
	
	print_linkedlist(fout, head);
	
	// -----------------------------------------------
	
	destruct_linkedlist(head);	

	return 0;
}

// ----------------------- TASK 2 --------------------
/* 
	In this function, you are required to open your files.
	You could either choose freopen() or .open() introduced in the "Notes".
	Notice that your choice here should agree with your choice in TASK 1.
*/
void file_handler() {
	fin.open("input.txt");
	fout.open("output.txt");
	return;
}
// ---------------------------------------------------


// ----------------------- TASK 3 --------------------
/* 
	In this function, you read numbers from "input.txt" to an array.
	The "input.txt" shall already be handled in your file_handler().
	Notice you are also required to return the number of integers you read in.
	Think of this : how could you know if you've already read in all numbers?
	Maybe something in the "Notes" could help you...
*/
int read_in_numbers(istream &in, int arr[]) {
	int temp; int size = 0;
	while (!(in.eof()) && (in >> temp)) {
		arr[size++] = temp;
	}
	return size;
}
// ---------------------------------------------------


/* 
	This function creates the link list and returns the head of a linked list.
	Again, the "head" is the first Node of a linked list.
*/
Node *create_linkedlist(int *arr, int size) {
	if (size <= 0) return NULL;
	Node *head = (Node*) malloc(sizeof(struct Node));
	Node *curr = head;
	for (int i = 0; i < size-1; i++) {
		curr->value = arr[i];
		curr->next = (Node*) malloc(sizeof(struct Node));
		curr = curr->next;
	}
	curr->value = arr[size-1];
	curr->next = NULL;
	return head;	
}

// ----------------------- TASK 4 --------------------
/* 
	In this function, you are required to print the linked list to "out".
	The linked list shall be printed in a REVERSE order.
	Check the "Notes" for formatting requirements.
*/
void print_linkedlist(ostream &out, Node *head) {
	if (head == NULL) return;
	print_linkedlist(out, head->next);
	out << head->value << " ";
	return;
}
// ---------------------------------------------------

/*
	This function destructs the linked list.
	By the term "destruct", we need to release the memory we allocated
	for the linked list Nodes.
*/
void destruct_linkedlist(Node *head) {
	if (head == NULL) return;
	Node *next = head->next;
	free(head);
	destruct_linkedlist(next);
	return;
}
