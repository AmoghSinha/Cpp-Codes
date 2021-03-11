#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> pivotAns;
ll k;

int partition(vector<ll> &v, ll low, ll high)
{
	ll pivotIndex = low + (k % (high - low + 1));
	ll pivot = v[pivotIndex];

	vector<ll> temp;

	for (auto i : v)
	{
		if (i < pivot)
		{
			temp.push_back(i);
		}
	}

	temp.push_back(pivot);
	pivotIndex = temp.size() - 1;

	for (auto i : v)
	{
		if (i > pivot)
		{
			temp.push_back(i);
		}
	}

	v = temp;

	pivotAns.push_back(pivot);

	return pivotIndex;
}

void moronicSort(vector<ll> &v, ll low, ll high)
{
	if (low < high)
	{
		int part = partition(v, low, high);
		moronicSort(v, low, part - 1);
		moronicSort(v, part + 1, high);
	}
}

// Driver Code
int main()
{
	ll n;
	cin >> n >> k;

	vector<ll> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	moronicSort(v, 0, n - 1);

	for (auto i : pivotAns)
	{
		cout << i << " ";
	}

	return 0;
}