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

	void bfs_helper(T src, map<T, bool> &visited)
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

			cout << node << " ";

			for (auto nbr : adj[node])
			{
				if (!visited[nbr])
				{
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = node;
				}
			}
		}
	}
	void bfs(T src)
	{
		map<T, bool> visited;

		for (auto e : adj)
		{
			visited[e.first] = false;
		}

		for (auto e : adj)
		{
			if (!visited[e.first])
			{
				bfs_helper(e.first, visited);
				cout << " ";
			}
		}
	}

	void dfs_helper(T src, map<T, bool> &visited)
	{
		cout << src << " ";
		visited[src] = true;

		for (auto nbr : adj[src])
		{
			if (!visited[nbr])
			{
				dfs_helper(nbr, visited);
			}
		}
	}
	void dfs()
	{
		map<T, bool> visited;

		for (auto e : adj)
		{
			visited[e.first] = false;
		}

		for (auto e : adj)
		{
			if (!visited[e.first])
			{
				dfs_helper(e.first, visited);
				cout << " ";
			}
		}
	}
};

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

	g.bfs(0);

	cout << endl;

	g.dfs();

	return 0;
}
