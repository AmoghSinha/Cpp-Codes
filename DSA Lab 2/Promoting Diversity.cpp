#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool check(ll mid, ll a[], ll n, ll d)
{
	if (n == 1)
		return false;

	for (int i = 0; i < (n - mid + 1); ++i)
	{
		if (abs(a[i] - a[i + mid - 1]) < d)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ll t, i;
	cin >> t;

	while (t--)
	{
		ll d, n, ans;
		cin >> n >> d;

		ll a[n];
		for (i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		sort(a, a + n);

		ll start = 1, end = n, mid;

		ans = 0;

		while (start <= end)
		{
			mid = start + (end - start) / 2;
			if (check(mid, a, n, d))
			{
				end = mid - 1;
				ans = mid;
			}
			else
			{
				start = mid + 1;
			}
		}

		cout << ans << endl;
	}
}