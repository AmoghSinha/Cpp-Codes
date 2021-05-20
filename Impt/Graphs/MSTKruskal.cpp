#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool customCompare(const vector<ll> &a,
				   const vector<ll> &b)
{
	return (a[2] < b[2]);
}

ll kruskalMST(ll V, vector<vector<ll>> &edges)
{
	vector<vector<ll>> result;
	vector<ll> treeId(V);

	for (int i = 0; i < V; i++)
	{
		treeId[i] = i;
	}

	sort(edges.begin(), edges.end(), customCompare);

	ll cost = 0;

	for (auto e : edges)
	{
		if (treeId[e[0]] != treeId[e[1]])
		{
			cost += e[2];

			result.push_back(e);

			ll oldId = treeId[e[0]], newId = treeId[e[1]];

			for (auto i = 0; i < V; i++)
			{
				if (treeId[i] == oldId)
				{
					treeId[i] = newId;
				}
			}
		}
	}

	return cost;
}

// Algo for finding Minimum Spanning Tree
int main()
{
	ll n = 5;				  // n = edges
	vector<vector<ll>> edges; // Node1; Node2; Weight

	// edges.push_back({0, 1, 1});
	// edges.push_back({0, 2, 2});
	// edges.push_back({0, 3, 2});
	// edges.push_back({2, 3, 3});
	// edges.push_back({2, 1, 2});
	// edges.push_back({1, 3, 3});

	edges.push_back({1, 2, 10});
	edges.push_back({2, 3, 15});
	edges.push_back({1, 3, 5});
	edges.push_back({4, 2, 2});
	edges.push_back({4, 3, 40});

	cout << "Cost : " << kruskalMST(n, edges);

	return 0;
}
