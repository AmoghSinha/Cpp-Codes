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

	bool cycle_helper(T src, map<T, bool> &visited, map<T, bool> &curr)
	{
		visited[src] = true;
		curr[src] = true;

		for (auto nbr : adj[src])
		{
			if (curr[nbr] == true)
			{
				return true;
			}

			if (!visited[nbr])
			{
				bool cyclePresent = cycle_helper(nbr, visited, curr);

				if (cyclePresent)
				{
					return true;
				}
			}
		}

		curr[src] = false;
		return false;
	}
	bool hasCycle()
	{
		map<T, bool> visited;
		map<T, bool> curr;

		for (auto e : adj)
		{
			visited[e.first] = false;
			curr[e.first] = false;
		}

		return cycle_helper(0, visited, curr);
	}
};

// Check if directed graph has a cycle - DFS
int main()
{
	Graph<ll> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 2); // Back Edge (Leads to Cycle)

	cout << g.hasCycle();

	return 0;
}
