#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void merge(vector<ll> &v, ll start, ll mid, ll end)
{
	vector<ll> temp(end - start + 1);

	int p = start, q = mid + 1;
	int k = 0;

	for (int i = start; i <= end; i++)
	{
		if (p > mid)
			temp[k++] = v[q++];
		else if (q > end)
			temp[k++] = v[p++];
		else if (v[p] <= v[q])
		{
			temp[k++] = v[p++];
		}
		else
		{
			temp[k++] = v[q++];
		}
	}

	for (int i = 0; i < k; i++)
		v[start++] = temp[i];
}

void merge_sort(vector<ll> &v, ll start, ll end)
{
	if (start < end)
	{
		ll mid = start + (end - start) / 2;

		merge_sort(v, start, mid);
		merge_sort(v, mid + 1, end);
		merge(v, start, mid, end);
	}
}

int main()
{
	ll n;
	cin >> n;

	vector<ll> v(n);

	for (auto i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	merge_sort(v, 0, n - 1);

	for (auto i : v)
	{
		cout << i << " ";
	}
	return 0;
}