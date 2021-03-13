#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll n, i;
	cin >> n;

	vector<ll> v(n);

	for (i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	ll k;
	cin >> k;

	vector<ll> temp;

	for (i = 0; i < n; ++i)
	{
		while (!temp.empty() && v.size() - i + temp.size() - 1 >= k && temp.back() > v[i])
		{
			temp.pop_back();
		}

		if (temp.size() < k)
		{
			temp.push_back(v[i]);
		}
	}

	for (auto e : temp)
	{
		cout << e << " ";
	}

	return 0;
}