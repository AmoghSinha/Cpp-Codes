#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

template <typename T>
class Graph
{
	map<T, list<T>> adj;

public:
	void addEdge(T a, T b)
	{
		adj[a].push_back(b);
	}

	bool cycle_helper(T src, map<T, bool> &visited, T parent)
	{
		visited[src] = true;

		for (auto nbr : adj[src])
		{
			if (!visited[nbr])
			{
				bool cyclePresent = cycle_helper(nbr, visited, src);

				if (cyclePresent)
				{
					return true;
				}
			}
			else if (nbr != parent)
			{
				return true;
			}
		}

		return false;
	}
	bool hasCycle()
	{
		map<T, bool> visited;

		for (auto e : adj)
		{
			visited[e.first] = false;
		}

		return cycle_helper(0, visited, -1);
	}
};

// Check if gundirected graph has a cycle - DFS
int main()
{
	Graph<ll> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);

	cout << g.hasCycle();

	return 0;
}
