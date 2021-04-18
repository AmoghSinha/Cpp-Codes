//maxsum subarray of a given array
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i, j, k, currentsum, maxsum = INT_MIN, n;
	cin >> n;
	int a[1000];
	int cumsum[1000] = {0};

	cin >> a[0];

	cumsum[0] = a[0];
	for (i = 1; i < n; i++)
	{
		cin >> a[i];
		cumsum[i] = cumsum[i - 1] + a[i];
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			currentsum = cumsum[j] - cumsum[i] + a[i];

			if (currentsum > maxsum)
			{
				maxsum = currentsum;
			}
		}
	}
	cout << "maxsum is " << maxsum;
	return 0;
}