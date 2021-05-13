#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	cin >> n >> m;

	priority_queue<ll> pq;

	for (auto i = 0; i < n; ++i)
	{
		ll temp;
		cin >> temp;

		pq.push(temp);
	}

	ll ans = 0;
	while (!pq.empty())
	{
		ll temp = pq.top();

		if (m)
		{
			temp /= 2;
			--m;
			pq.pop();
			pq.push(temp);
		}
		else
		{
			ans += temp;
			pq.pop();
		}
	}

	cout << ans;

	return 0;
}