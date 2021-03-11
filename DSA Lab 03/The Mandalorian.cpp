#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
	ll n;
	cin >> n;

	string s1, s2;
	cin >> s1 >> s2;

	unordered_map<char, int> m;

	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		s1[i] = tolower(s1[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		m[s2[i]]++;
		if (m[s1[i]])
		{
			m[s1[i]]--;
		}
		else
		{
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}