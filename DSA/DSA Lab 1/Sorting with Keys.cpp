#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int merge(vector<ll> &v, int start, int mid, int end)
{
	int invCount = 0;

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
			invCount += (mid - p + 1);
			temp[k++] = v[q++];
		}
	}

	for (int i = 0; i < k; i++)
		v[start++] = temp[i];

	return invCount;
}

int merge_sort(vector<ll> &v, int start, int end)
{
	int invCount = 0;

	if (start < end)
	{
		int mid = start + (end - start) / 2;

		invCount += merge_sort(v, start, mid);
		invCount += merge_sort(v, mid + 1, end);
		invCount += merge(v, start, mid, end);
	}

	return invCount;
}

bool customCompare(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

int main()
{
	int i, n;
	cin >> n;

	pair<ll, ll> p[n];

	for (i = 0; i < n; i++)
	{
		cin >> p[i].first;
	}

	for (i = 0; i < n; i++)
	{
		cin >> p[i].second;
	}

	sort(p, p + n, customCompare);

	vector<ll> v;
	for (int i = 0; i < n; i++)
		v.push_back(p[i].first);

	int ans = merge_sort(v, 0, n - 1);

	cout << ans;
}