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
		adj[b].push_back(a);
	}

	// Number of Connected Components in a Graph
	void noOfConnComp_helper(T src, map<T, bool> &visited)
	{
		visited[src] = true;

		for (auto nbr : adj[src])
		{
			if (!visited[nbr])
			{
				noOfConnComp_helper(nbr, visited);
			}
		}
	}
	ll noOfConnComp()
	{
		map<T, bool> visited;

		for (auto e : adj)
		{
			visited[e.first] = false;
		}

		ll count = 0;
		for (auto e : adj)
		{
			if (!visited[e.first])
			{
				++count;
				noOfConnComp_helper(e.first, visited);
			}
		}

		return count;
	}
};

// Find total number of Connected Components
int main()
{
	Graph<ll> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(7, 9);

	cout << "Connected Components : " << g.noOfConnComp() << endl;

	return 0;
}
