#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl "\n"

const ll NOT_EXISTS = -9999999;

class Node
{
public:
	ll data;
	Node *left, *right;

	Node(ll val)
	{
		data = val;
		left = right = NULL;
	}
};

void breadthFirstSearch(Node *root)
{
	queue<Node *> q;

	q.push(root);
	q.push(NULL);

	while (!q.empty())
	{
		Node *temp = q.front();

		if (temp == NULL)
		{
			cout << endl;

			q.pop();

			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{

			cout << temp->data << " ";

			if (temp->left)
			{
				q.push(temp->left);
			}

			if (temp->right)
			{
				q.push(temp->right);
			}

			q.pop();
		}
	}
}

Node *insertNode(Node *root, int data)
{
	if (root == NULL)
	{
		root = new Node(data);
		return root;
	}

	queue<Node *> q;
	q.push(root);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		if (temp->left != NULL)
		{
			q.push(temp->left);
		}
		else
		{
			temp->left = new Node(data);
			return root;
		}

		if (temp->right != NULL)
		{
			q.push(temp->right);
		}
		else
		{
			temp->right = new Node(data);
			return root;
		}
	}
}

bool isBST(Node *root, ll minimum = INT_MIN, ll maximum = INT_MAX)
{
	if (root == NULL)
	{
		return true;
	}

	return root->data >= minimum && root->data <= maximum && isBST(root->left, minimum, root->data) && isBST(root->right, root->data, maximum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin >> t;

	Node *root = NULL;

	while (t--)
	{
		ll temp;
		cin >> temp;
		root = insertNode(root, temp);
	}

	breadthFirstSearch(root);

	return 0;
}