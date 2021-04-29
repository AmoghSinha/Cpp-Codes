#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> bellmanFord(ll V, ll src, vector<vector<ll>> &edges)
{
	vector<ll> dist(V + 1, INT_MAX);
	dist[src] = 0;

	// Relax all edges V-1 times
	for (auto i = 0; i < V - 1; ++i)
	{
		for (auto edge : edges)
		{
			ll u = edge[0];
			ll v = edge[1];
			ll weight = edge[2];

			if (dist[u] != INT_MAX and dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
			}
		}
	}

	// Check for -ve weight cycle
	for (auto edge : edges)
	{
		ll u = edge[0];
		ll v = edge[1];
		ll weight = edge[2];

		if (dist[u] != INT_MAX and dist[u] + weight < dist[v])
		{
			cout << "Negative Edge Cycle Found!";
			exit(0);
		}
	}

	return dist;
}

// Algo for finding Shortest Path between two nodes
int main()
{
	ll n = 3, m = 3;		  // n = nodes; m = edges
	vector<vector<ll>> edges; // Node1; Node2; Weight

	// edges.push_back({1, 2, 3});
	// edges.push_back({2, 3, 4});
	// edges.push_back({3, 1, -10});

	edges.push_back({1, 2, 3});
	edges.push_back({2, 3, 4});
	edges.push_back({1, 3, -10});

	vector<ll> distances = bellmanFord(n, 1, edges);

	for (auto i = 1; i <= n; ++i)
	{
		cout << "Node " << i << " is at a distance of : " << distances[i] << endl;
	}

	return 0;
}
