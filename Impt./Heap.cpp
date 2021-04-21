#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class Heap
{
	vector<ll> v;
	bool minHeap;

	bool compare(ll a, ll b)
	{
		return minHeap ? a < b : a > b;
	}

public:
	Heap(ll defaultSize = 10, bool type = true)
	{
		v.reserve(defaultSize);

		v.push_back(-1);

		minHeap = type;
	}

	ll top()
	{
		return v[1];
	}

	bool empty()
	{
		return v.size() == 1;
	}

	void heapify(ll index)
	{
		ll left = 2 * index;
		ll right = left + 1;

		ll minIndex = index;

		if (left < v.size() and compare(v[left], v[index]))
		{
			minIndex = left;
		}

		if (right < v.size() and compare(v[right], v[minIndex]))
		{
			minIndex = right;
		}

		if (minIndex != index)
		{
			swap(v[index], v[minIndex]);
			heapify(minIndex);
		}
	}

	void push(ll data)
	{
		v.push_back(data);

		ll index = v.size() - 1;
		ll parent = index / 2;

		while (index > 1 and compare(v[index], v[parent]))
		{
			swap(v[index], v[parent]);

			index = parent;
			parent /= 2;
		}
	}

	void pop()
	{

		ll last = v.size() - 1;
		swap(v[1], v[last]);

		v.pop_back();

		heapify(1);
	}
};

int main()
{
	Heap h1;

	for (auto i = 0; i < 8; ++i)
	{
		h1.push(i);
	}

	while (!h1.empty())
	{
		cout << h1.top() << " ";

		h1.pop();
	}

	cout << endl;

	return 0;
}