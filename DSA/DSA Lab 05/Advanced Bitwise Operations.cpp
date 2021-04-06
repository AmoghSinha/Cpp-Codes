#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class Node
{
public:
	int data;
	Node *next;
	Node *prev;
};

void printList(Node *head)
{
	string s = "";
	while (head != NULL)
	{
		s += to_string(head->data);
		head = head->next;
	}

	reverse(s.begin(), s.end());
	cout << s;
}

void push(Node **head, ll val)
{
	Node *temp = new Node();
	temp->data = val;
	temp->next = *head;
	temp->prev = NULL;

	if ((*head) != NULL)
	{
		(*head)->prev = temp;
	}

	*head = temp;
}

void rotateLeft(Node **head)
{
	Node *temp = *head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *head;
	(*head)->prev = temp;

	*head = temp;
	temp = (*head)->prev;

	(*head)->prev = NULL;
	temp->next = NULL;
}

void rotateRight(Node **head)
{
	Node *temp = *head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *head;
	(*head)->prev = temp;

	temp = *head;
	*head = temp->next;

	(*head)->prev = NULL;
	temp->next = NULL;
}

void shiftLeft(Node **head)
{
	rotateLeft(head);

	(*head)->data = 0;
}

void shiftRight(Node **head)
{
	rotateRight(head);

	Node *temp = *head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	(temp)->data = 0;
}

void incrementOne(Node **head)
{
	int carry = 1;

	Node *temp = *head;

	while (temp != NULL)
	{
		temp->data += carry;
		if (temp->data == 2)
		{
			carry = 1;
			temp->data = 0;
		}
		else
		{
			carry = 0;
		}
		temp = temp->next;
	}
}

void decrementOne(Node **head)
{
	int carry = 1;

	Node *temp = *head;

	while (temp != NULL)
	{
		temp->data -= carry;
		if (temp->data == -1)
		{
			carry = 1;
			temp->data = 1;
		}
		else
		{
			carry = 0;
		}
		temp = temp->next;
	}
}

int main()
{
	string b, q;
	ll t;

	cin >> b >> t;

	Node *head = NULL;

	for (auto i = 0; i < b.size(); ++i)
	{
		push(&head, b[i] - '0');
	}

	while (t--)
	{
		cin >> q;

		if (q == "LR")
			rotateLeft(&head);
		else if (q == "RR")
			rotateRight(&head);
		else if (q == "LS")
			shiftLeft(&head);
		else if (q == "RS")
			shiftRight(&head);
		else if (q == "INC")
			incrementOne(&head);
		else if (q == "DEC")
			decrementOne(&head);
	}

	printList(head);

	return 0;
}