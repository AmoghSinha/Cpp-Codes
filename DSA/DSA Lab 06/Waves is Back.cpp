#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class Node
{
public:
	ll size;
	Node *left, *right;

	Node()
	{
		size = 0;
		left = right = NULL;
	}
};

void calcSize(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	calcSize(root->left);
	calcSize(root->right);

	ll leftSize = 0, rightSize = 0;

	if (root->left != NULL)
	{
		leftSize = (root->left)->size;
	}

	if (root->right != NULL)
	{
		rightSize = (root->right)->size;
	}

	root->size += 1 + leftSize + rightSize;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;

		vector<Node *> v(n + 1);

		for (auto i = 1; i <= n; ++i)
		{
			v[i] = new Node();
		}

		for (auto i = 1; i <= n; ++i)
		{
			ll a, b, c;
			cin >> a >> b >> c;

			if (b != -1)
			{
				v[a]->left = v[b];
			}

			if (c != -1)
			{
				v[a]->right = v[c];
			}
		}

		// Calculate size of all nodes
		calcSize(v[1]);

		ll maximum = INT_MIN, ans = 0;

		for (ll i = 1; i <= n; ++i)
		{
			ll leftSize = 0, rightSize = 0, remSize = 0;

			// Size of left sub tree
			if (v[i]->left != NULL)
			{
				leftSize = (v[i]->left)->size;
			}

			// Size of right sub tree
			if (v[i]->right != NULL)
			{
				rightSize = (v[i]->right)->size;
			}

			// Size of remaining nodes
			remSize = n - v[i]->size;

			ll temp = leftSize * rightSize + remSize * (leftSize + rightSize);

			if (temp > maximum)
			{
				maximum = temp;
				ans = i;
			}
			else if (temp == maximum)
			{
				ans = min(i, ans);
			}
		}

		cout << ans << endl;
	}

	return 0;
}