#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> customPair;

#define endl "\n";

template <typename T>
class Graph
{
	vector<pair<T, ll>> *adj;

public:
	Graph(ll n)
	{
		adj = new vector<customPair>[n + 1];
	}

	void addEdge(T a, T b, ll weight)
	{
		adj[a].push_back({b, weight});
		adj[b].push_back({a, weight});
	}

	void solve(vector<ll> &distances)
	{
		priority_queue<customPair, vector<customPair>, greater<customPair>> pq;
		pq.push({0, 0});

		distances[0] = 0;

		while (!pq.empty())
		{
			customPair v = pq.top();
			pq.pop();

			for (auto nbr : adj[v.second])
			{
				if (distances[v.second] != INT_MAX && distances[nbr.first] > distances[v.second] + nbr.second)
				{
					distances[nbr.first] = distances[v.second] + nbr.second;
					pq.push({distances[nbr.first], nbr.first});
				}
			}
		}
	};
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin >> t;

	while (t--)
	{
		ll n, m;
		cin >> n >> m;

		vector<ll> distances(n + 1);

		Graph<ll> g(n + 1);

		while (m--)
		{
			ll a, b, c;
			cin >> a >> b >> c;

			g.addEdge(a, b, c);
		}

		ll b;
		cin >> b;

		for (auto i = 0; i < b; i++)
		{
			ll temp;
			cin >> temp;

			g.addEdge(0, temp, 0);
		}

		for (auto i = 0; i <= n; i++)
		{
			distances[i] = INT_MAX;
		}

		g.solve(distances);

		ll count = 0;
		for (auto e : distances)
		{
			++count;
			if (count == 1)
			{
				continue;
			}
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}