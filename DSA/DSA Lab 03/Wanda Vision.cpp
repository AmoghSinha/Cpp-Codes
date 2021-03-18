#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define MOD 1000000007

int main()
{
	ll n, i, j;

	cin >> n;

	ll c[n][n];
	memset(c, 0, sizeof(c));

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> c[i][j];
		}
	}

	vector<ll> lr(2 * n, 0), rl(2 * n, 0);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			// Left-Right diagonals are indexed from left bottom corner (n-1,0) as 0
			lr[j - i + (n - 1)] += c[i][j];

			// Right-Left diagonals are indexed from left top corner (0,0) as 0
			rl[j + i] += c[i][j];
		}
	}

	ll sum = 0;
	vector<ll> ans(2, 0);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			sum = lr[j - i + (n - 1)] + rl[j + i] - c[i][j];

			if ((i + j) % 2 == 0)
				ans[0] = max(ans[0], sum);
			else
				ans[1] = max(ans[1], sum);
		}
	}

	cout << (ans[0] + ans[1]) % MOD << endl;
}