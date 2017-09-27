
/* linked - linked list functions
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

static struct node* head = NULL;

/************************************************************
 length - return length of a list
 ************************************************************/
int length(){
	int size = 0;//variable to keep track of the size
	struct node* curr = head;//sets an iterator to the head of the list
	if(curr == NULL){//immediately returns zero if the head is null
		return size;
	}
	while(curr != NULL){
		size++;
		curr = curr->next;
	}
	return size;
}


/************************************************************
 push - add new node at beginning of list
 ************************************************************/
void push(int data){
	struct node* n;//creates a new node
	n = malloc(sizeof(struct node));// allocates memory for the node
	n->data = data;//sets the nodes data to the parameter
	n->next = head;//sets the next to the head
	head = n;//resets the head as the new node
}

/************************************************************
 pop - delete node at beginning of non-empty list and return its data
 ************************************************************/
int pop()
{
	struct node* curr = head;// sets an iterator to the head
	int data = curr->data;//sets the variable to the first elements data
	head = curr->next;//sets the head to the next element
	curr->next = NULL;//sets the current next to null
	free(curr);//frees the memory locations
	return data;
}

/************************************************************
 appendNode - add new node at end of list
 ************************************************************/
void appendNode(int data)
{
	struct node* curr = head;//sets an iterator to the head
	struct node* new_node = malloc(sizeof(struct node));//allocates the memory for a new node
	new_node-> data = data;//sets the new nodes data
	if(curr == NULL){//if the curr == NULL then it sets the head to the new node, and sets its next as none
		head = new_node;
		new_node->next = NULL;
	}
	while(curr->next != NULL){//iterates through the list to get to the last element
		curr = curr->next;
	}
	new_node->next = NULL;//sets the new node's next to none
	curr->next = new_node;//sets the curr nodes next to the new node
}

/************************************************************
 copyList - return new copy of list
 ************************************************************/
struct node* copyList()
{
	struct node* new_head = NULL;// sets the copied list's head to null
	struct node* cpyNode = malloc(sizeof(struct node));//allocates memory for the new node
	struct node* curr = head; //sets an iterator to the original list
	struct node* currCpy = new_head; //sets an iterator to the copied list

	//These next three lines are to set up the head of the copied list before it goes into the while loop
	//I chose to do this because you only set the head of a list once,
	cpyNode->data = curr->data; 
	cpyNode->next = NULL;
	new_head = cpyNode;
	currCpy = new_head;
	//increases the iterator to the next node
	curr = curr->next;
	//this while loop will go through each node and copy the data into the copied node
	while(curr != NULL){
		cpyNode = malloc(sizeof(struct node));//allocates more memory for the nodes
		cpyNode->data = curr->data; //copies the data from the original node to the copied node
		cpyNode->next = NULL;//sets the next to null
		currCpy->next = cpyNode;//sets the next of the iterator to the the new node
		currCpy = currCpy->next;//increments it so the current iterator is equal to the node just created
		curr = curr->next;//increments to the next node
	}
  return new_head;//returns the head of the copied list
}

/************************************************************
 freeList - release all memory you allocated for the linked list.
 NOTE -- add a unit test that calls this function and observes
 that you returned 1 for success on freeing all memory.
 The instructor will verify that you correctly freed all
 allocated memory.
 ************************************************************/
int freeList() {

 	struct node* curr = head;//sets an iterator to the head of the list
	while(curr){
		free(curr);//frees the space of the current node
		curr = curr->next;//sets the current node to the next node
	}
	if(curr == NULL){
		return 1;//returns one if all space is freed
	}

  return 0 ;
}

//***********************************************************
int compareList(struct node* copy){
	struct node* curr = head;//sets an iterator to the head of the original list
	struct node* currCopy = copy;//sets an interator to the head of the passed in list
	while(currCopy && curr){ // while both lists don't equal null
		if( currCopy->data == curr->data ){ //if they equal each other then it will increment both
			currCopy = currCopy->next;
			curr = curr->next;
		}
		else{//if it doesn't it will return 0
			return 0;
		}
	}
	return 1;//will return 1 if it makes it throught the while loop
}
