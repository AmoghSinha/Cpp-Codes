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

ll length(Node *head)
{
	ll count = 0;

	while (head != NULL)
	{
		++count;
		head = head->next;
	}

	return count;
}

void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

void insertAtHead(Node *&head, ll val)
{
	if (head == NULL)
	{
		head = new Node(val);
		return;
	}

	Node *temp = new Node(val);
	temp->next = head;
	head = temp;
}

void insertAtTail(Node *&head, ll val)
{
	if (head == NULL)
	{
		head = new Node(val);
		return;
	}

	Node *tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	tail->next = new Node(val);
}

void insertAt(Node *&head, ll val, ll pos)
{
	if (head == NULL || pos == 0)
	{
		insertAtHead(head, val);
	}
	else if (pos > length(head))
	{
		insertAtTail(head, val);
	}
	else
	{
		Node *prev = head;
		while (--pos)
		{
			prev = prev->next;
		}

		Node *temp = new Node(val);
		temp->next = prev->next;
		prev->next = temp;
	}
}

void deleteHead(Node *&head)
{
	if (head == NULL)
	{
		return;
	}

	Node *temp = head->next;
	delete head;
	head = temp;
}

void deleteAt(Node *&head, ll pos)
{
	if (head == NULL || pos == 0)
	{
		deleteHead(head);
	}
	else if (pos >= length(head))
	{
		return;
	}
	else
	{
		Node *prev = head;
		while (--pos)
		{
			prev = prev->next;
		}

		Node *temp = prev->next;
		prev->next = temp->next;
		delete temp;
	}
}

bool searchRecursive(Node *head, ll val)
{
	if (head == NULL)
	{
		return false;
	}

	if (head->data == val)
	{
		return true;
	}

	return searchRecursive(head->next, val);
}

void reverse(Node *&head)
{
	Node *temp = head;
	Node *prev = NULL;
	Node *next = NULL;

	while (temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}

	head = prev;
}

Node *reverseRecursive(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	Node *tHead = reverseRecursive(head->next);

	Node *temp = head->next;
	temp->next = head;
	head->next = NULL;

	return tHead;
}

Node *midPoint(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	Node *slow = head;
	Node *fast = head->next;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

Node *kthFromEnd(Node *head, ll k)
{
	Node *slow = head;
	Node *fast = head;

	while (k--)
	{
		fast = fast->next;
	}

	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}

Node *merge(Node *a, Node *b)
{
	if (a == NULL)
	{
		return b;
	}

	if (b == NULL)
	{
		return a;
	}

	Node *c;

	if (a->data < b->data)
	{
		c = a;
		c->next = merge(a->next, b);
	}
	else
	{
		c = b;
		c->next = merge(a, b->next);
	}

	return c;
}

Node *mergeSort(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	Node *mid = midPoint(head);

	Node *a = head;
	Node *b = mid->next;

	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	return merge(a, b);
}

bool floydCycle(Node *head)
{
	Node *slow = head;
	Node *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (slow == fast)
		{
			return true;
		}
	}

	return false;
}

Node *floydCycleStart(Node *head)
{
	Node *slow = head;
	Node *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (slow == fast)
		{
			slow = head;
			break;
		}
	}

	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

int main()
{
	Node *head = NULL;

	insertAtHead(head, 7);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 10);
	insertAtHead(head, 8);
	insertAtHead(head, 2);

	Node *temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = head->next->next;

	cout << floydCycleStart(head)->data;

	return 0;
}