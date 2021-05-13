#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl "\n"

ll res = INT_MAX;

bool all_visit(vector<ll> &visited)
{
	for (auto e : visited)
	{
		if (!e)
		{
			return false;
		}
	}

	return true;
}

void helper(vector<double> &weights, vector<ll> &visited, double w, ll temp, double maximum)
{
	if (temp > res)
	{
		return;
	}

	if (all_visit(visited))
	{
		res = min(res, temp);
		return;
	}

	for (int i = 0; i < weights.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = true;

			if (w + weights[i] <= maximum)
				helper(weights, visited, w + weights[i], temp, maximum);
			else
				helper(weights, visited, weights[i], temp + 1, maximum);
			visited[i] = false;
		}
	}
}

ll solve(vector<double> &weights, double maximum)
{
	vector<ll> visited(weights.size());

	helper(weights, visited, 0.0, 1, maximum);

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;

	vector<double> w(n);

	for (auto i = 0; i < n; ++i)
	{
		cin >> w[i];
	}

	cout << solve(w, 3);

	return 0;
}