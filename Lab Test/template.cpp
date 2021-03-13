#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define loop(i, a, b) for (i = a; i < b; ++i)
#define MOD 1000000007
#define pb push_back
#define PI 3.1415926535897932384626433832795028841971693993751

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{

	return a * b / gcd(a, b);
}

bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

//nCr
ll binomialCoeff(ll n, ll k)
{
	ll res = 1;

	if (k > n - k)
		k = n - k;

	for (int i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}

//Closest element to target in array
ll getClosest(ll val1, ll val2, ll target)
{
	if (target - val1 >= val2 - target)
		return val2;
	else
		return val1;
}
ll findClosest(ll arr[], ll n, ll target)
{
	if (target <= arr[0])
		return arr[0];
	if (target >= arr[n - 1])
		return arr[n - 1];

	ll i = 0, j = n, mid = 0;
	while (i < j)
	{
		mid = (i + j) / 2;

		if (arr[mid] == target)
			return arr[mid];

		if (target < arr[mid])
		{

			if (mid > 0 && target > arr[mid - 1])
				return getClosest(arr[mid - 1], arr[mid], target);

			j = mid;
		}

		else
		{
			if (mid < n - 1 && target < arr[mid + 1])
				return getClosest(arr[mid], arr[mid + 1], target);
			i = mid + 1;
		}
	}

	return arr[mid];
}

//Number of prime factors
ll primeFactors(ll n)
{
	ll answer = 0;
	while (n % 2 == 0)
	{
		cout << 2 << " ";
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			answer++;
			n = n / i;
		}
	}

	if (n > 2)
		answer++;

	return answer;
}

//Integer to String
string intToString(ll n)
{
	ostringstream str;
	str << n;

	return str.str();
}

//No. of 1s in binary representation
ll noOfOnesInBinary(ll n)
{
	ll count = 0;
	while (n != 0)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

//___________________________________________________________________________________________

static ll dp[11][101];

bool subsetSum(ll a[], ll n, ll sum)
{
	if (sum == 0)
		return true;

	if (n == 0)
		return false;

	if (dp[n][sum] != -1)
		return dp[n][sum];

	if (sum - a[n - 1] < 0)
		return dp[n][sum] = subsetSum(a, n - 1, sum);
	else
		return dp[n][sum] = subsetSum(a, n - 1, sum - a[n - 1]) || subsetSum(a, n - 1, sum);
}

bool customCompare(const pair<int, int> &a,
				   const pair<int, int> &b)
{
	return (a.first < b.first);
}

bool check(ll mid, ll a[], ll n, ll d)
{
	if (n == 1)
		return false;

	for (int i = 0; i < (n - mid); ++i)
	{
		if (abs(a[i] - a[i + mid - 1]) < d)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ll t, n, m, i, j, k, l, ans, temp, index, prev, sum, flag, minimum, maximum;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// cin >> t;
	t = 1;

	while (t--)
	{
		cout << "HELLO";
		cout << endl;
	}
	return 0;
}
