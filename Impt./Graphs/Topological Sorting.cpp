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

	void bfs()
	{
		map<T, ll> inDegree;

		for (auto e : adj)
		{
			inDegree[e.first] = 0;
		}

		for (auto e : adj)
		{
			for (auto node : e.second)
			{
				inDegree[node]++;
			}
		}

		queue<T> q;

		for (auto e : adj)
		{
			if (inDegree[e.first] == 0)
			{
				q.push(e.first);
			}
		}

		while (!q.empty())
		{
			T node = q.front();
			q.pop();

			cout << node << endl;

			for (auto nbr : adj[node])
			{
				inDegree[nbr]--;

				if (inDegree[nbr] == 0)
				{
					q.push(nbr);
				}
			}
		}
	}

	void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering)
	{
		visited[src] = true;

		for (auto nbr : adj[src])
		{
			if (!visited[nbr])
			{
				dfs_helper(nbr, visited, ordering);
			}
		}

		ordering.push_front(src);
	}
	void dfs()
	{
		map<T, bool> visited;
		list<T> ordering;

		for (auto e : adj)
		{
			visited[e.first] = false;
		}

		for (auto e : adj)
		{
			if (!visited[e.first])
			{
				dfs_helper(e.first, visited, ordering);
			}
		}

		for (auto node : ordering)
		{
			cout << node << "\n";
		}
	}
};

int main()
{
	Graph<string> g;
	g.addEdge("Python", "Data Pre-Processing");
	g.addEdge("Python", "PyTorch");
	g.addEdge("Python", "ML Basics");
	g.addEdge("Data Pre-Processing", "ML Basics");
	g.addEdge("PyTorch", "Deep Learning");
	g.addEdge("ML Basics", "Deep Learning");
	g.addEdge("Deep Learning", "Face-Recognition AI");
	g.addEdge("Data Set", "Face-Recognition AI");

	g.dfs();

	cout << endl;

	g.bfs();

	return 0;
}
