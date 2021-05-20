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

	bool bfs_helper(T src, map<T, bool> &visited)
	{
		map<T, T> parent;
		queue<T> q;

		q.push(src);
		visited[src] = true;
		parent[src] = src;

		while (!q.empty())
		{
			T node = q.front();
			q.pop();

			for (auto nbr : adj[node])
			{
				if (visited[nbr] == true and parent[node] != nbr)
				{
					return false;
				}
				else if (!visited[nbr])
				{
					visited[nbr] = true;
					parent[nbr] = node;
					q.push(nbr);
				}
			}
		}

		return true;
	}
	bool isTree()
	{
		map<T, bool> visited;

		for (auto e : adj)
		{
			visited[e.first] = false;
		}

		ll count = 0;
		bool ans = false;
		for (auto e : adj)
		{
			if (!visited[e.first])
			{
				++count;
				ans = bfs_helper(e.first, visited);
			}
		}

		if (count > 1)
		{
			return false;
		}

		return ans;
	}
};

// Check if undirected graph is a tree (No Cycles)
int main()
{
	Graph<ll> g;
	g.addEdge(0, 1);
	g.addEdge(3, 2);
	g.addEdge(1, 2);
	// g.addEdge(0, 3);

	cout << g.isTree();

	return 0;
}
