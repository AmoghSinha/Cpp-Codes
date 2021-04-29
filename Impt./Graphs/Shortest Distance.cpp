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

	// Shortest Distance from src to dest
	ll shortestDist(T src, T dest)
	{
		map<T, ll> distance;
		queue<T> q;

		for (auto e : adj)
		{
			distance[e.first] = INT_MAX;
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
		return distance[dest];
	}
};

// Shortest Distance between any two nodes
int main()
{
	Graph<ll> g;
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(7, 6, 1);
	g.addEdge(6, 5, 2);
	g.addEdge(5, 4, 10);
	g.addEdge(7, 8, 7);
	g.addEdge(6, 8, 6);
	g.addEdge(3, 5, 14);
	g.addEdge(3, 4, 9);

	cout << "Shortest distance : " << g.shortestDist(0, 6);

	return 0;
}
