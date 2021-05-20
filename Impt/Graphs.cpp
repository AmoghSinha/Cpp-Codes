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

	void bfs(T src)
	{
		map<T, bool> visited;
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
			}
		}
	}

	// Shortest Distance from src to dest
	ll shortestDist(T src, T dest)
	{
		map<T, ll> distance;
		queue<T> q;

		for (auto e : adj)
		{
			distance[e.first] = -1;
		}

		q.push(src);
		distance[src] = 0;

		while (!q.empty())
		{
			T node = q.front();
			q.pop();

			for (auto nbr : adj[node])
			{
				if (distance[nbr] == -1)
				{
					q.push(nbr);
					distance[nbr] = distance[node] + 1;
				}
			}
		}
		return distance[dest];
	}

	// Number of Connected Components in a Graph
	void noOfConComp_helper(T src, map<T, bool> &visited)
	{
		visited[src] = true;

		for (auto nbr : adj[src])
		{
			if (!visited[nbr])
			{
				noOfConComp_helper(nbr, visited);
			}
		}
	}
	ll noOfConComp()
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
				noOfConComp_helper(e.first, visited);
			}
		}

		return count;
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

	cout << "\nShortest distance : " << g.shortestDist(0, 5) << endl;

	g.dfs();

	cout << "\nConnected Components : " << g.noOfConComp() << endl;

	return 0;
}
