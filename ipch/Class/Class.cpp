#include "stdafx.h"
#include <iostream>

using namespace std;

class DoublyLinkedListNode
{
public:
	int data;
    DoublyLinkedListNode* next;
	DoublyLinkedListNode* prev;
	DoublyLinkedListNode(int node_data)
	{
		this->next=NULL;
		this->prev=NULL;
		this->data=node_data;
	}

};
class DoublyLinkedList
{
public:
	DoublyLinkedListNode* head;
	DoublyLinkedListNode* tail;
	DoublyLinkedList()
	{
		this->head=NULL;
		this->tail=NULL;
	}
	void inser_node(int data)
	{
	   DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
	   if (!this->head)
	   {
		   this->head = node;

	   }
	   else
	   {
		   this->tail->next=node;
		   node->prev=this->tail;
	   }
	   this->tail=node;


	}

};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head)
{
	if (head==NULL || head->next== NULL)
	{
		return head;
	}
	
	DoublyLinkedListNode* current = head;
	DoublyLinkedListNode* temp = NULL;
	while(current!=NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;

	}
	if (temp!=NULL)
	{
		head=temp->prev;
	}
	return head;
}

void frind(DoublyLinkedListNode* head)
{
	DoublyLinkedListNode* p = head;
	while(p->next!=NULL)
	{
		cout << p->data << " ";
		p=p->next;
	}

}


 int main()
{
	int n;
	cin >> n;
	for (int i=0; i< n; i++)
	{
		DoublyLinkedList* list_count = new DoublyLinkedList();
		int  a;
		cin >>a;
		for (int j =0; j<a; j++)
		{
			int b;
			cin >> b;
			list_count->inser_node(b);

		}
		DoublyLinkedListNode* list = reverse(list_count->head);
		frind(list);
	}
	return 0;
}