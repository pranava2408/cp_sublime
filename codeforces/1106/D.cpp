#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../../debug.h"
#else
#define debug(...)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld long double

const ld eps = 1e-12;

vector<bool> primesieve(ll n)
{
	vector<bool> ans(n + 1, true);
	ans[0] = false;
	ans[1] = false;
	for (ll i = 2; i * i <= n; i++)
	{
		if (ans[i])
		{
			for (ll j = i * i; j <= n; j += i)
			{
				ans[j] = false;
			}
		}
	}
	return ans;
}

vector<ll> spf(ll n)
{
	vector<ll> ret(n + 1, 0);
	for (ll i = 1; i <= n; i++)
	{
		ret[i] = i;
	}

	for (ll i = 2; i * i <= n; i++)
	{
		if (ret[i] == i)
		{
			for (ll j = i * i; j <= n; j += i)
			{
				if (ret[j] == j)
				{
					ret[j] = i;
				}
			}
		}
	}
	return ret;
}

void factorisation(ll n)
{
	vector<ll> factors = spf(n);
	while (n != 1)
	{
		cout << factors[n] << ' ';
		n /= factors[n];
	}
	cout << endl;
}

vector<ll> dp;
vector<ll> sp;

void solve() {
	ll n; cin >> n;
	cout << dp[n] << "\n";
}




int main() {
	dp.resize(1e6 + 1, 0);
	sp = spf(1e6);
	for (int i = 2; i <= 1e6; i++) {
		dp[i] = dp[i / sp[i]] + 1;
		int left = i / sp[i];

		if (left % sp[i] == 0 || left == 1) {

		} else {
			dp[i]++;
		}
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
#endif
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}