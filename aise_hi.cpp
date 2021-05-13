#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int ll;

bool check(vector<ll> v, ll k, ll mid)
{
	ll temp = mid;
	int i = 0;

	for (i = 0; i < v.size(); ++i)
	{
		if (k == 0 or mid < v[i])
		{
			break;
		}

		if (v[i] <= temp)
		{
			temp -= v[i];
		}
		else
		{
			temp = mid - v[i];
			--k;
		}
	}

	if (i == v.size())
	{
		return true;
	}

	return false;
}

int main()
{
	ll k, n;
	cin >> k >> n;

	vector<ll> v(n);

	for (auto i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	ll start = 0, end = k * (1e8), mid;

	ll ans = 0;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		if (check(v, k, mid))
		{
			end = mid - 1;
			ans = mid;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << ans;

	return 0;
}