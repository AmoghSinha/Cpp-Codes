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

Node *buildTree()
{
	ll data;
	cin >> data;

	if (data == -1)
	{
		return NULL;
	}

	Node *root = new Node(data);

	root->left = buildTree();
	root->right = buildTree();

	return root;
}

ll height(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return max(height(root->left), height(root->right)) + 1;
}

void printPostorder(Node *node)
{
	if (node == NULL)
		return;

	printPostorder(node->left);

	printPostorder(node->right);

	cout << node->data << " ";
}

void printInorder(Node *node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	cout << node->data << " ";

	printInorder(node->right);
}

void printPreorder(Node *node)
{
	if (node == NULL)
		return;

	cout << node->data << " ";

	printPreorder(node->left);

	printPreorder(node->right);
}

void printKthLevel(Node *root, ll k)
{
	if (root == NULL)
	{
		return;
	}

	if (k == 0)
	{
		cout << root->data << " ";
		return;
	}

	printKthLevel(root->left, k - 1);
	printKthLevel(root->right, k - 1);
}

void printRightView(Node *root, ll level, ll &maxLevel)
{
	if (root == NULL)
	{
		return;
	}

	if (level > maxLevel)
	{
		cout << root->data << " ";
		maxLevel = level;
	}

	printRightView(root->right, level + 1, maxLevel);
	printRightView(root->left, level + 1, maxLevel);
}

// Complexity: O(n^2)
void printLevelOrder(Node *node)
{
	ll h = height(node);

	for (auto i = 1; i <= h; ++i)
	{
		printKthLevel(node, i);
	}
}

// Complexity: O(n)
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

ll count(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + count(root->left) + count(root->right);
}

ll sum(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return root->data + sum(root->left) + sum(root->right);
}

// Complexity: O(n^2)
ll diameter(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}

	ll d1 = height(root->left) + height(root->right);
	ll d2 = diameter(root->left);
	ll d3 = diameter(root->right);

	return max(d1, max(d2, d3));
}

// Complexity: O(n)
pair<ll, ll> fastDiameter(Node *root)
{
	if (root == NULL)
	{
		return make_pair(0, 0);
	}

	pair<ll, ll> p;

	pair<ll, ll> left = fastDiameter(root->left);
	pair<ll, ll> right = fastDiameter(root->right);

	p.first = max(left.first, right.first) + 1;
	p.second = max(left.first + right.first, max(left.second, right.second));

	return p;
}

// Complexity: O(n)
pair<bool, ll> isHeightBalanced(Node *root)
{
	if (root == NULL)
	{
		return make_pair(true, 0);
	}

	pair<bool, ll> p;

	pair<bool, ll> left = isHeightBalanced(root->left);
	pair<bool, ll> right = isHeightBalanced(root->right);

	p.first = (abs(left.second - right.second) <= 1) && left.first && right.first;
	p.second = max(left.second, right.second) + 1;

	return p;
}

Node *buildBalancedTreeFromArray(ll *a, ll start, ll end)
{
	if (start > end)
	{
		return NULL;
	}

	ll mid = start + (end - start) / 2;

	Node *root = new Node(a[mid]);

	root->left = buildBalancedTreeFromArray(a, start, mid - 1);
	root->right = buildBalancedTreeFromArray(a, mid + 1, end);

	return root;
}

Node *buildTreeFromPreOrder(ll *in, ll *pre, ll start, ll end)
{
	static ll i = 0;

	if (start > end)
	{
		return NULL;
	}

	Node *root = new Node(pre[i]);

	ll index = -1;
	for (auto j = start; j <= end; ++j)
	{
		if (in[j] == pre[i])
		{
			index = j;
			break;
		}
	}

	++i;

	root->left = buildTreeFromPreOrder(in, pre, start, index - 1);
	root->right = buildTreeFromPreOrder(in, pre, index + 1, end);

	return root;
}

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

ll printAtDistanceK(Node *root, Node *target, ll k)
{
	if (root == NULL)
	{
		return -1;
	}

	if (root == target)
	{
		printKthLevel(target, k);
		return 0;
	}

	ll distFromLeft = printAtDistanceK(root->left, target, k);

	if (distFromLeft != -1)
	{
		// Check whether to print ancestor / Make a call to right subtree
		if (distFromLeft + 1 == k)
		{
			cout << root->data << " ";
		}
		else
		{
			printKthLevel(root->right, k - 2 - distFromLeft);
		}

		return distFromLeft + 1;
	}

	ll distFromRight = printAtDistanceK(root->right, target, k);

	if (distFromRight != -1)
	{
		// Check whether to print ancestor / Make a call to right subtree
		if (distFromRight + 1 == k)
		{
			cout << root->data << " ";
		}
		else
		{
			printKthLevel(root->left, k - 2 - distFromRight);
		}

		return distFromRight + 1;
	}

	return -1;
}

Node *lowestCommonAncestor(Node *root, ll a, ll b)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == a || root->data == b)
	{
		return root;
	}

	Node *left = lowestCommonAncestor(root->left, a, b);
	Node *right = lowestCommonAncestor(root->right, a, b);

	if (left != NULL && right != NULL)
	{
		return root;
	}

	if (left != NULL)
	{
		return left;
	}

	return right;
}

ll maxSum(Node *root, ll &maximum)
{
	if (root == NULL)
	{
		return 0;
	}

	ll leftSum = maxSum(root->left, maximum);
	ll rightSum = maxSum(root->right, maximum);

	ll op1 = root->data;
	ll op2 = root->data + max(leftSum, rightSum);
	ll op3 = root->data + leftSum + rightSum;

	// Sum of left right and node
	ll temp = max(max(op1, op2), op3);
	maximum = max(maximum, temp);

	// Max between sum of left and right branch
	return max(op1, op2);
}

ll getNodeLevel(Node *root, ll key, ll level)
{
	if (root == NULL)
	{
		return -1;
	}

	if (root->data == key)
	{
		return level;
	}

	ll left = getNodeLevel(root->left, key, level + 1);

	if (left != -1)
	{
		return left;
	}

	return getNodeLevel(root->right, key, level + 1);
}

ll shortestDistance(Node *root, ll a, ll b)
{
	Node *temp = lowestCommonAncestor(root, a, b);

	return getNodeLevel(temp, a, 0) + getNodeLevel(temp, b, 0);
}

int main()
{
	Node *root = buildTree();

	cout << "Pre-order traversal : \n";
	printPreorder(root);

	cout << "\n\nIn-order traversal : \n";
	printInorder(root);

	cout << "\n\nPost-order traversal : \n";
	printPostorder(root);

	cout << "\n\nLevel-order traversal : \n";
	printLevelOrder(root);

	cout << "\n\nHeight : " << height(root);

	cout << "\n\nKth Level : ";
	printKthLevel(root, 2);

	cout << "\n\nCount : " << count(root);

	cout << "\n\nSum : " << sum(root);

	cout << "\n\nDiameter : " << fastDiameter(root).second;

	cout << "\n\nHeight Balanced? : " << isHeightBalanced(root).first;

	cout << "\n\nBFS Traversal :- \n";
	breadthFirstSearch(root);

	ll maxLevel = -1;
	cout << "\nRight View : ";
	printRightView(root, 0, maxLevel);

	ll a[] = {1, 2, 3, 4, 5, 6, 7};
	Node *balRoot = buildBalancedTreeFromArray(a, 0, 6);

	cout << "\n\nBFS Traversal :- \n";
	breadthFirstSearch(balRoot);

	ll in[] = {3, 2, 8, 4, 1, 6, 7, 5};
	ll pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	ll post[] = {3, 8, 4, 2, 7, 6, 5, 1};

	Node *preRoot = buildTreeFromPreOrder(in, pre, 0, 7);

	cout << "\nBFS Traversal :- \n";
	breadthFirstSearch(preRoot);

	Node *postRoot = buildTreeFromPostOrder(in, post, 8, 0, 7);

	cout << "\nBFS Traversal :- \n";
	breadthFirstSearch(postRoot);

	cout << "\nNodes at distance k : ";
	printAtDistanceK(root, root->left, 4);

	cout << "\n\nLowest Common Ancestor : " << lowestCommonAncestor(root, 7, 9)->data;

	ll maximum = INT_MIN;
	maxSum(root, maximum);
	cout << "\n\nMax Sum : " << maximum;

	cout << "\n\nShortest Distance : " << shortestDistance(root, 6, 13);

	return 0;
}
