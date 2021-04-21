#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	ll ans = 1, maximum = 0;
	bool flag = false;

	stack<int> s;
	s.push(-1);

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.push(i);
		}
		else
		{
			s.pop();
			if (s.size())
			{
				if (i - s.top() > maximum)
				{
					maximum = i - s.top();
					ans = 1;
				}
				else if (i - s.top() == maximum)
				{
					ans++;
				}
			}
			else
			{
				s.push(i);
			}
		}
	}

	cout << maximum << " " << ans;

	return 0;
}