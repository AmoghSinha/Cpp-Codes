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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	ll in[n], pre[n];
	vector<ll> v;

	string s;
	cin >> s;

	stringstream check1(s);

	string temp;

	while (getline(check1, temp, ','))
	{
		stringstream convert(temp);

		ll x = 0;
		convert >> x;

		v.push_back(x);
	}

	for (auto i = 0; i < n; ++i)
	{
		in[i] = v[i];
	}

	v.clear();

	cin >> s;

	stringstream check2(s);

	while (getline(check2, temp, ','))
	{
		stringstream convert(temp);

		ll x = 0;
		convert >> x;

		v.push_back(x);
	}

	for (auto i = 0; i < n; ++i)
	{
		pre[i] = v[i];
	}

	Node *root = buildTreeFromPreOrder(in, pre, 0, n - 1);

	if (isHeightBalanced(root).first)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}

	return 0;
}
