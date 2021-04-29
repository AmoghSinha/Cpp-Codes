#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool check(ll mid, ll a[], ll n, ll g)
{
	for (int i = 0; i < (n - mid + 1); ++i)
	{
		if (i == 0)
		{
			if (a[mid - 1] == (a[n - 1] - g))
			{
				return true;
			}
		}
		else if (a[i + mid - 1] - a[i - 1] == (a[n - 1] - g))
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ll t, i, j;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;

		ll a[n], b[n];

		cin >> b[0];
		a[0] = b[0];

		for (i = 1; i < n; ++i)
		{
			cin >> b[i];
			a[i] = b[i] + a[i - 1];
		}

		ll g;
		cin >> g;

		ll ans = 0;
		if (a[n - 1] != g)
		{
			for (i = 0, j = 0; i < n, j < n;)
			{
				if (a[j] - a[i] + b[i] >= a[n - 1] - g)
				{
					if (a[j] - a[i] + b[i] == a[n - 1] - g)
					{
						ans = max(j - i + 1, ans);
					}
					++i;
				}
				else
				{
					++j;
				}
			}

			if (ans == 0)
			{
				ans = n;
			}
		}

		cout << n - ans << endl;
	}
}