#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<vector<ll>> floydWarshall(vector<vector<ll>> &graph)
{
	vector<vector<ll>> d(graph);

	ll V = graph.size();

	// In kth phase we include (1, 2, ..., k) as intermediate vertices
	for (auto k = 0; k < V; ++k)
	{
		// Iterate over 2D matrix
		for (auto i = 0; i < V; ++i)
		{
			for (auto j = 0; j < V; ++j)
			{
				// If k is included, can we minimize distance?
				if (d[i][k] < INT_MAX && d[k][j] < INT_MAX)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	return d;
}

// Algo for finding Shortest Path between two nodes
int main()
{
	vector<vector<ll>> graph = {{0, INT_MAX, -2, INT_MAX},
								{4, 0, 3, INT_MAX},
								{INT_MAX, INT_MAX, 0, 2},
								{INT_MAX, -1, INT_MAX, 0}};

	vector<vector<ll>> distances = floydWarshall(graph);

	for (auto i = 0; i < distances.size(); ++i)
	{
		for (auto j = 0; j < distances.size(); ++j)
		{
			cout << distances[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
