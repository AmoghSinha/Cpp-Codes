#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void showQueue(queue<ll> q)
{
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
}

int main()
{
	queue<ll> q;

	q.push(10);
	q.push(30);

	showQueue(q);

	return 0;
}