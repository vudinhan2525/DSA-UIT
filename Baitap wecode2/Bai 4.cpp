
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void insert_node(SinglyLinkedList *a,int x){
	if(a->head == NULL){
		a->head = a->tail = new SinglyLinkedListNode(x);
	}
	else{
		SinglyLinkedListNode *newnode = new SinglyLinkedListNode(x);
		newnode->next = a->head;
		a->head = newnode;
	}
}
void reverseLinkedList(SinglyLinkedList *a){
	
}
void printLinkedList(SinglyLinkedList *a){
	SinglyLinkedListNode *tmp = a->head;
	while(tmp != NULL){
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}
int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}