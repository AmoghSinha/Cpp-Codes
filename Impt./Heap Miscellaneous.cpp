#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool minHeap = false;

bool compare(ll a, ll b)
{
	return minHeap ? a < b : a > b;
}

void heapify(vector<ll> &v, ll index, ll size)
{
	ll left = 2 * index;
	ll right = left + 1;

	ll minIndex = index;

	if (left < size and compare(v[left], v[index]))
	{
		minIndex = left;
	}

	if (right < size and compare(v[right], v[minIndex]))
	{
		minIndex = right;
	}

	if (minIndex != index)
	{
		swap(v[index], v[minIndex]);
		heapify(v, minIndex, size);
	}
}

void buildHeap(vector<ll> &v)
{
	for (auto i = (v.size() - 1) / 2; i >= 1; --i)
	{
		heapify(v, i, v.size());
	}
}

void heapSort(vector<ll> &v)
{
	buildHeap(v);

	ll n = v.size() - 1;

	while (n)
	{
		swap(v[1], v[n]);

		n--;

		heapify(v, 1, n);
	}
}

int main()
{
	vector<ll> v1 = {-1, 10, 20, 5, 6, 1, 8, 9, 4};

	buildHeap(v1);

	cout << "Heap : ";
	for (auto e : v1)
	{
		cout << e << " ";
	}

	heapSort(v1);

	cout << endl
		 << "Sorted : ";
	for (auto e : v1)
	{
		cout << e << " ";
	}
	return 0;
}