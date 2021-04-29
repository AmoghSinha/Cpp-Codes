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
	}

	// Shortest Distance from src to dest
	ll shortestDist(T src, ll &n)
	{
		map<T, ll> distance;
		queue<T> q;

		for (auto i = 1; i <= n; ++i)
		{
			distance[i] = LLONG_MAX;
		}

		q.push(src);
		distance[src] = 0;

		while (!q.empty())
		{
			T node = q.front();
			q.pop();

			for (auto nbr : adj[node])
			{
				if (distance[nbr.first] > distance[node] + nbr.second)
				{
					q.push(nbr.first);
					distance[nbr.first] = distance[node] + nbr.second;
				}
			}
		}

		ll ans = 0;
		for (auto e : distance)
		{
			ans = max(ans, e.second);
		}

		if (ans == LLONG_MAX)
		{
			return -1;
		}

		return ans;
	}
};

// Shortest Distance between any two nodes
int main()
{

	ll t;
	cin >> t;

	ll src, m;
	cin >> src >> m;

	Graph<ll> g;

	while (m--)
	{
		ll a, b, c;
		cin >> a >> b >> c;

		g.addEdge(a, b, c);
	}

	cout << g.shortestDist(src, t);

	return 0;
}
