#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

template <typename T>
class Graph
{
	map<T, list<pair<T, ll>>> adj; //  map<Node, list<Node, weight>>>

public:
	void addEdge(T a, T b, ll weight)
	{
		adj[a].push_back({b, weight});
		adj[b].push_back({a, weight});
	}

	ll primsMST()
	{
		priority_queue<pair<ll, T>, vector<pair<ll, T>>, greater<pair<ll, T>>> q;

		map<T, bool> visited;

		for (auto e : adj)
		{
			visited[e.first] = false;
		}

		q.push({0, 0}); // Weight, Node

		ll ans = 0;
		while (!q.empty())
		{
			pair<ll, T> best = q.top();
			q.pop();

			ll weight = best.first;
			ll node = best.second;

			if (visited[node])
			{
				continue;
			}

			ans += weight;
			visited[node] = true;

			for (auto x : adj[node])
			{
				if (!visited[x.first])
				{
					q.push({x.second, x.first});
				}
			}
		}

		return ans;
	}
};

// Algo for finding Minimum Spanning Tree
int main()
{
	Graph<ll> g;
	g.addEdge(0, 1, 1);
	g.addEdge(0, 2, 2);
	g.addEdge(0, 3, 2);
	g.addEdge(2, 3, 3);
	g.addEdge(2, 1, 2);
	g.addEdge(1, 3, 3);

	// ll n, m;
	// cin >> n >> m;

	// while (m--)
	// {
	// 	ll x, y, w;
	// 	cin >> x >> y >> w;

	// 	g.addEdge(x, y, w);
	// }

	cout << g.primsMST();

	return 0;
}
