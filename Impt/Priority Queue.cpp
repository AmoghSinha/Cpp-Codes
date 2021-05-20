#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, pair<ll, ll>> customPair; // <Element, <row, column>>

class CustomCompare
{
public:
	ll operator()(ll a, ll b)
	{
		return a > b;
	}
};

void displayMedians()
{
	priority_queue<ll> maxH;
	priority_queue<ll, vector<ll>, greater<ll>> minH;

	ll n, temp;
	cin >> n;

	double ans = INT_MAX;

	while (n--)
	{
		cin >> temp;

		if (temp < ans)
		{
			maxH.push(temp);
		}
		else
		{
			minH.push(temp);
		}

		if (minH.size() > maxH.size())
		{
			if (minH.size() - maxH.size() == 2)
			{
				maxH.push(minH.top());
				minH.pop();

				ans = (double)(minH.top() + maxH.top()) / 2;
				cout << ans << " ";
			}
			else
			{
				ans = minH.top();
				cout << ans << " ";
			}
		}
		else if (maxH.size() > minH.size())
		{
			if (maxH.size() - minH.size() == 2)
			{
				minH.push(maxH.top());
				maxH.pop();

				ans = (double)(minH.top() + maxH.top()) / 2;
				cout << ans << " ";
			}
			else
			{
				ans = maxH.top();
				cout << ans << " ";
			}
		}
		else
		{
			ans = (double)(minH.top() + maxH.top()) / 2;
			cout << ans << " ";
		}
	}
}

vector<ll> mergeKSortedArrays(vector<vector<ll>> v)
{
	vector<ll> ans;
	priority_queue<customPair, vector<customPair>, greater<customPair>> pq;

	// Inserting 0th element of each array
	for (auto i = 0; i < v.size(); ++i)
	{
		pq.push({v[i][0], {i, 0}});
	}

	while (!pq.empty())
	{
		customPair p = pq.top();
		pq.pop();

		ll element = p.first;
		ll row = p.second.first;
		ll column = p.second.second;

		ans.push_back(element);

		if (column + 1 < v[row].size())
		{
			pq.push({v[row][column + 1], {row, column + 1}});
		}
	}

	return ans;
};

int main()
{
	vector<ll> v = mergeKSortedArrays({{2, 6, 12, 15}, {1, 3, 14, 20}, {3, 5, 8, 10}});

	for (auto e : v)
	{
		cout << e << " ";
	}

	return 0;
}