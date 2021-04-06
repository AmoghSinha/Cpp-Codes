#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class Node
{
public:
	ll data;
	Node *next;

	Node(ll val)
	{
		data = val;
		next = NULL;
	}
};

void printList(Node *head)
{
	Node *temp = head;

	if (head == NULL)
	{
		return;
	}

	while (temp->next != head)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << temp->data;
}

void insert(Node *&head, ll val)
{
	Node *n = new Node(val);

	if (head == NULL)
	{
		n->next = n;
		head = n;
		return;
	}

	n->next = head;

	Node *temp = head;

	while (temp->next != head)
	{
		temp = temp->next;
	}

	temp->next = n;
	head = n;
}

Node *getNode(Node *head, ll val)
{
	if (head == NULL)
	{
		return NULL;
	}

	Node *temp = head;

	while (temp->next != head)
	{
		if (temp->data == val)
		{
			return temp;
		}

		temp = temp->next;
	}

	if (temp->data == val)
	{
		return temp;
	}

	return NULL;
}

void deleteNode(Node *&head, ll val)
{
	Node *del = getNode(head, val);

	if (del == NULL)
	{
		return;
	}

	if (del == head)
	{
		head = head->next;
	}

	Node *temp = head;

	while (temp->next != del)
	{
		temp = temp->next;
	}

	temp->next = del->next;

	delete del;
}

int main()
{
	Node *head = NULL;

	insert(head, 10);
	insert(head, 30);
	insert(head, 20);
	insert(head, 40);

	printList(head);
	cout << endl;

	deleteNode(head, 20);

	printList(head);

	return 0;
}