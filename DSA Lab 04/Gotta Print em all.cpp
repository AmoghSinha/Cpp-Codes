#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool customCompare(pair<ll, ll> &a, pair<ll, ll> &b)
{
	return a.second < b.second;
}

int main()
{
	ll n, k, i;
	cin >> n >> k;

	vector<pair<ll, ll>> p(n, {0, 0});
	for (i = 0; i < n; ++i)
	{
		cin >> p[i].first;
	}
	for (i = 0; i < n; ++i)
	{
		cin >> p[i].second;
	}

	sort(p.begin(), p.end(), customCompare);

	for (i = 0; i < n; ++i) {
		
	}

	return 0;
}