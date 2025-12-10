#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *nxt;
	
	Node(int d){
		this->data = d;
		nxt = NULL;
	}
};

//Add at beginning

Node *addBeginning(Node *head, int data){
	Node *newNode = new Node(data);
	
	if(head == NULL){
		head = newNode;
	}
	
	newNode->nxt = head;
	head = newNode; 
	
	return head;
}

Node *addTail(Node *head, int data){
	Node *temp = head;
	Node *newNode = new Node(data);
	
	if(head == NULL){
		return newNode;
	}
	
	while(temp->nxt != NULL){
		temp = temp->nxt;
	}
	
	temp->nxt = newNode;
	return head;
}


// add at position
Node *addAtPosition (Node *head, int data,int position){
	Node *newNode = new Node(data);
	Node *temp = head;
	
	if (position == 0){
		newNode->nxt = head;
		return newNode;
	}
	
	for(int i=0; i<position; i++){
		temp = temp->nxt;
	}
	newNode->nxt = temp->nxt;
	temp->nxt = newNode;
	
	return head;
}

// delete first element
Node *deleteFirstElement(Node *head){
	if(head == NULL){
		return NULL;
	}
	
	Node *temp = head;
	
	// (1)-> (2)->(3)->(4)->(5)
	
	//The head was pointing to (1)
	head = temp->nxt;
	// Now it points to (2)
	delete temp;
	// And temp we delete was pointing to (1)
	return head;
}

Node *deleteLastNode(Node *head){
	if(head == NULL){
		return NULL;
	}
	
	if(head->nxt == NULL){
		delete head;
		return NULL;
	}
	
	Node *second_last = head;
	
	while(second_last->nxt->nxt != NULL){
		second_last = second_last->nxt;
	}
	
	delete (second_last->nxt);
	second_last->nxt = NULL;
	return head;
}

Node *reversingList(Node *head){
	Node *current = head;
	Node *nextNode = NULL;
	Node *previous = NULL;
	
	while(current){
		nextNode = current->nxt;
		current->nxt = previous;
		previous = current;
		current = nextNode;
	}
	
	return previous;
}

void display(Node *head){
	if(head == NULL){
		cout << "No element in linked list";
		return;
	}
	
	while(head != NULL){
		cout << head->data;
		head = head->nxt;
	}
}

Node *merge(Node *a, Node *b){
	// base case
	
	if(a == NULL){
		return b;
	}
	
	if(b== NULL){
		return a;
	}
	
	//recursive case
	// take a head pointer
	
	Node *c;
	
	if(a->data < b->data){
		c=a;
		c->next = merge(a->nxt,b);
	}else{
		c=b;
		c->next = merge(a,b->nxt);
	}
	
	return c;
}

Node* getMid(Node* head) {
    if (head == NULL || head->nxt == NULL) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->nxt;

    while (fast != NULL && fast->nxt != NULL) {
        slow = slow->nxt;
        fast = fast->nxt->nxt;
    }

    return slow;
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->nxt == NULL) {
        return head;     // already sorted (0 or 1 element)
    }

    // Step 1: Split list into two halves
    Node* mid = getMid(head);
    Node* secondHalf = mid->nxt;
    mid->next = NULL;

    // Step 2: Sort each half
    Node* left = mergeSort(head);
    Node* right = mergeSort(secondHalf);

    // Step 3: Merge sorted halves
    return merge(left, right);
}