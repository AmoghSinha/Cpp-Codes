#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool check(ll n, ll k)
{
	if (n * n * n > k || n > 1000)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	ll k;
	cin >> k;

	ll start = 0, end = k, mid, ans;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (check(mid, k))
		{
			start = mid + 1;
			ans = mid;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << ans;
}