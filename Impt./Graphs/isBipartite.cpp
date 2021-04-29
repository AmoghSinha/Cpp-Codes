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

	bool dfs_helper(T src, map<T, ll> &visited, ll color)
	{
		visited[src] = color;

		for (auto nbr : adj[src])
		{
			if (!visited[nbr])
			{
				bool temp = dfs_helper(nbr, visited, 3 - color);
				if (!temp)
				{
					return false;
				}
			}
			else if (color == visited[nbr])
			{
				return false;
			}
		}

		return true;
	}
	bool dfs()
	{
		map<T, ll> visited; // 0 - Not Visited; 1 - Color 1; 2 - Color 2

		for (auto e : adj)
		{
			visited[e.first] = 0;
		}

		for (auto e : adj)
		{
			if (!visited[e.first])
			{
				bool temp = dfs_helper(e.first, visited, 1);
				if (!temp)
				{
					return false;
				}
			}
		}

		return true;
	}
};

int main()
{
	Graph<ll> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);

	cout << g.dfs();

	return 0;
}
