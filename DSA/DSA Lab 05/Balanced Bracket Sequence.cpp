#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	ll count = 0, ans = 0, maximum = 0, temp = 0;
	bool flag = false;

	stack<ll> s;

	for (auto i : str)
	{
		if (s.empty() || i == '(')
		{
			if (i == '(')
			{
				s.push(i);

				if (flag)
				{
					flag = false;
					if (count == maximum)
					{
						ans++;
					}
					else if (count > maximum)
					{
						ans = 1;
					}
					maximum = max(maximum, count);
				}
			}
		}
		else if (i == ')')
		{
			if (s.top() == '(')
			{
				if (flag)
				{
					count += 2;
				}
				else
				{
					flag = true;
					count = 2;
				}
				s.pop();
			}
		}
	}

	if (flag)
	{
		flag = false;
		if (count == maximum)
		{
			ans++;
		}
		else if (count > maximum)
		{
			ans = 1;
		}
		maximum = max(maximum, count);
	}

	if (!ans)
	{
		ans = 1;
	}

	cout << maximum << " " << ans;
	return 0;
}