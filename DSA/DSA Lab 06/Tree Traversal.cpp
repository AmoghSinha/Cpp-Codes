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

Node *buildTreeFromPostOrder(ll *in, ll *post, ll size, ll start, ll end)
{
	static ll i = size - 1;

	if (start > end)
	{
		return NULL;
	}

	Node *root = new Node(post[i]);

	ll index = -1;
	for (auto j = start; j <= end; ++j)
	{
		if (in[j] == post[i])
		{
			index = j;
			break;
		}
	}

	--i;

	root->right = buildTreeFromPostOrder(in, post, size, index + 1, end);
	root->left = buildTreeFromPostOrder(in, post, size, start, index - 1);

	return root;
}

void printPreorder(Node *node)
{
	if (node == NULL)
		return;

	cout << node->data << " ";

	printPreorder(node->left);

	printPreorder(node->right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	ll in[n], post[n];

	for (auto i = 0; i < n; ++i)
	{
		cin >> in[i];
	}

	for (auto i = 0; i < n; ++i)
	{
		cin >> post[i];
	}

	Node *root = buildTreeFromPostOrder(in, post, n, 0, n - 1);

	printPreorder(root);

	return 0;
}