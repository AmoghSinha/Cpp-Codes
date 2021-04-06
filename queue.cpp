#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	priority_queue<ll, vector<ll>, greater<ll>> minH;

	for (int i = 0; i < 5; ++i)
	{
		ll temp;
		cin >> temp;
		minH.push(temp);

		if (minH.size() > 2)
		{
			minH.pop();
		}
	}

	cout << minH.top();

	return 0;
}