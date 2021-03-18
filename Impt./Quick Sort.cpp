#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll partition(vector<ll> &v, ll low, ll high)
{
	ll pivot = v[high];

	vector<ll> temp;

	for (auto i : v)
	{
		if (i < pivot)
		{
			temp.push_back(i);
		}
	}

	ll pivotIndex = temp.size();
	temp.push_back(pivot);

	for (auto i : v)
	{
		if (i > pivot)
		{
			temp.push_back(i);
		}
	}

	for (auto i = low; i <= high; ++i)
	{
		v[i] = temp[i];
	}

	return pivotIndex;
}

void quick_sort(vector<ll> &v, ll low, ll high)
{
	if (low < high)
	{
		ll part = partition(v, low, high);
		quick_sort(v, low, part - 1);
		quick_sort(v, part + 1, high);
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

	quick_sort(v, 0, n - 1);

	for (auto i : v)
	{
		cout << i << " ";
	}
	return 0;
}