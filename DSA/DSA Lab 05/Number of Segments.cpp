#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	vector<ll> v(n);

	for (auto i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	stack<ll> s;
	ll j = 0;

	unordered_map<ll, vector<ll>> rightMap, leftMap;

	s.push(0);

	for (auto i = 1; i < n; ++i)
	{
		while (!s.empty() and v[i] > v[s.top()])
		{
			for (j = 0; j < rightMap[v[s.top()]].size(); ++j)
			{
				if (rightMap[v[s.top()]][j] == i - 1)
				{
					break;
				}
			}

			if (j == rightMap[v[s.top()]].size())
			{
				rightMap[v[s.top()]].push_back(i - 1);
			}
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty())
	{
		for (j = 0; j < rightMap[v[s.top()]].size(); ++j)
		{
			if (rightMap[v[s.top()]][j] == n - 1)
			{
				break;
			}
		}

		if (j == rightMap[v[s.top()]].size())
		{
			rightMap[v[s.top()]].push_back(n - 1);
		}
		s.pop();
	}

	// for (auto e : rightMap)
	// {
	// 	cout << e.first << " -> " << e.second << endl;
	// }

	s.push(n - 1);

	for (auto i = n - 2; i >= 0; --i)
	{
		while (!s.empty() and v[i] > v[s.top()])
		{
			for (j = 0; j < leftMap[v[s.top()]].size(); ++j)
			{
				if (leftMap[v[s.top()]][j] == i + 1)
				{
					break;
				}
			}

			if (j == leftMap[v[s.top()]].size())
			{
				leftMap[v[s.top()]].push_back(i + 1);
			}

			s.pop();
		}

		s.push(i);
	}

	while (!s.empty())
	{
		for (j = 0; j < leftMap[v[s.top()]].size(); ++j)
		{
			if (leftMap[v[s.top()]][j] == 0)
			{
				break;
			}
		}

		if (j == leftMap[v[s.top()]].size())
		{
			leftMap[v[s.top()]].push_back(0);
		}
		s.pop();
	}

	// for (auto e : leftMap)
	// {
	// 	cout << e.first << " -> " << e.second << endl;
	// }

	ll t;
	cin >> t;

	while (t--)
	{
		ll temp;
		cin >> temp;

		ll ans = 0;

		for (auto i = 0; i < rightMap[temp].size(); ++i)
		{
			ans += rightMap[temp][i] - leftMap[temp][i] + 1;
		}

		cout << ans << endl;
	}

	return 0;
}