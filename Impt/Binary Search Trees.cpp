#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

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

Node *insertNode(Node *root, ll val)
{
	if (root == NULL)
	{
		return new Node(val);
	}

	if (val <= root->data)
	{
		root->left = insertNode(root->left, val);
	}
	else
	{
		root->right = insertNode(root->right, val);
	}

	return root;
}

Node *buildTree()
{
	ll temp;
	cin >> temp;

	Node *root = NULL;
	while (temp != -1)
	{
		root = insertNode(root, temp);
		cin >> temp;
	}

	return root;
}

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

void printInorder(Node *node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	cout << node->data << " ";

	printInorder(node->right);
}

bool search(Node *root, ll val)
{
	if (root == NULL)
	{
		return false;
	}

	if (root->data == val)
	{
		return true;
	}

	if (val <= root->data)
	{
		return search(root->left, val);
	}

	return search(root->right, val);
}

Node *deleteNode(Node *root, ll val)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (val < root->data)
	{
		root->left = deleteNode(root->left, val);
		return root;
	}

	if (val > root->data)
	{
		root->right = deleteNode(root->right, val);
		return root;
	}

	// Found the node

	// Case 1: 0 children
	if (root->left == NULL && root->right == NULL)
	{
		delete root;
		return NULL;
	}

	// Case 2: 1 child
	if (root->left != NULL && root->right == NULL)
	{
		Node *temp = root->left;
		delete root;

		return temp;
	}

	if (root->right != NULL && root->left == NULL)
	{
		Node *temp = root->right;
		delete root;

		return temp;
	}

	// Case 3: 2 children
	// Find min. data from right sub-tree to replace root
	Node *temp = root->right;

	while (temp->left != NULL)
	{
		temp = temp->left;
	}

	root->data = temp->data;

	root->right = deleteNode(root->right, temp->data);

	return root;
}

bool isBST(Node *root, ll minimum = INT_MIN, ll maximum = INT_MAX)
{
	if (root == NULL)
	{
		return true;
	}

	return root->data >= minimum && root->data <= maximum && isBST(root->left, minimum, root->data) && isBST(root->right, root->data, maximum);
}

// Convert to LinkedList
pair<Node *, Node *> flatten(Node *root)
{
	// first - Head ; second - Tail
	pair<Node *, Node *> p;

	if (root == NULL)
	{
		p.first = NULL;
		p.second = NULL;

		return p;
	}

	// Leaf Node
	if (root->left == NULL && root->right == NULL)
	{
		return make_pair(root, root);
	}

	// Right sub tree is NULL
	if (root->left != NULL && root->right == NULL)
	{
		pair<Node *, Node *> left = flatten(root->left);

		left.second->right = root;

		p.first = left.first;
		p.second = root;

		return p;
	}

	// Left sub tree is NULL
	if (root->left == NULL && root->right != NULL)
	{
		pair<Node *, Node *> right = flatten(root->right);

		root->right = right.first;

		p.first = root;
		p.second = right.second;

		return p;
	}

	// Sub trees are not NULL
	pair<Node *, Node *> left = flatten(root->left);
	pair<Node *, Node *> right = flatten(root->right);

	left.second->right = root;
	root->right = right.first;

	p.first = left.first;
	p.second = right.second;

	return p;
}

ll buildBSTFromPreOrder(ll *pre, ll n, ll pos, Node *curr, ll minimum, ll maximum)
{
	if (pos == n || pre[pos] < minimum || pre[pos] > maximum)
		return pos;

	// Insert in minimum subtree
	if (pre[pos] < curr->data)
	{
		curr->left = new Node(pre[pos]);
		pos += 1;
		pos = buildBSTFromPreOrder(pre, n, pos, curr->left, minimum, curr->data - 1);
	}

	if (pos == n || pre[pos] < minimum || pre[pos] > maximum)
		return pos;

	// Insert in maximum subtree
	curr->right = new Node(pre[pos]);
	pos += 1;
	pos = buildBSTFromPreOrder(pre, n, pos, curr->right, curr->data + 1, maximum);
	return pos;
}

int main()
{
	Node *root = buildTree();

	cout << "In Order Traversal : ";
	printInorder(root);

	cout << "\n\nBreadth First Search :\n";
	breadthFirstSearch(root);

	root = deleteNode(root, 7);

	cout << "\nBreadth First Search :\n";
	breadthFirstSearch(root);

	cout << "\nSearch : " << search(root, 6);

	cout << "\n\nIs BST : " << isBST(root);

	pair<Node *, Node *> p = flatten(root);

	cout << "\n\nLinked List : ";
	while (p.first != NULL)
	{
		cout << p.first->data << " ";
		p.first = p.first->right;
	}

	ll pre[] = {5, 3, 1, 8, 6};

	Node *preRoot = new Node(pre[0]);

	buildBSTFromPreOrder(pre, 5, 1, preRoot, INT_MIN, INT_MAX);

	cout << "\n\nBFS Traversal :- \n";
	breadthFirstSearch(preRoot);

	return 0;
}