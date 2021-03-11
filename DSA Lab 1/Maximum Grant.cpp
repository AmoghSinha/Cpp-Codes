#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, i, n;
	cin >> t;

	while (t--)
	{
		cin >> n;

		ll p[n], a[n], sum;

		for (i = 0; i < n; i++)
		{
			cin >> p[i];
		}

		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		sort(p, p + n);
		sort(a, a + n);

		sum = 0;
		for (i = 0; i < n; i++)
		{
			sum += min(a[i], p[i]);
		}

		cout << sum << endl;
	}
	return 0;
}
