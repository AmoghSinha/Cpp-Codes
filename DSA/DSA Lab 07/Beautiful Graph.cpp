#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

template <typename T>
class Graph
{
	unordered_map<T, set<T>> adj;

public:
	void addEdge(T a, T b)
	{
		adj[a].insert(b);
		adj[b].insert(a);
	}

	void solve(ll n)
	{
		for (auto i = 0; i < n; ++i)
		{
			vector<T> v;

			for (auto e : adj)
			{
				if (e.second.size() == 1)
				{
					v.push_back(e.first);
				}
			}

			if (v.size() == 0)
			{
				cout << i << endl;
				break;
			}

			for (auto e : v)
			{
				adj.erase(e);

				for (auto &j : adj)
				{
					j.second.erase(e);
				}
			}
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin >> t;

	while (t--)
	{
		ll n, m;
		cin >> n >> m;

		Graph<ll> g;

		while (m--)
		{
			ll a, b;
			cin >> a >> b;

			g.addEdge(a, b);
		}

		g.solve(n);
	}

	return 0;
}
