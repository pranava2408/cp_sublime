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


const ll MOD = 1e9 + 7;
ll mod_add(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return (((a % m) - (b % m)) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }

// Function to perform modular exponentiation
ll mod_exp(ll base, ll exp, ll mod)
{
	ll result = 1;
	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			result = mod_mul(result, base, mod);
		}
		base = mod_mul(base, base, mod);
		exp /= 2;
	}
	return result;
}

// Function to compute modular inverse
ll mod_inv(ll a, ll mod)
{
	return mod_exp(a, mod - 2, mod);
}

ll md;
ll val(ll digit, ll ct) {
	if (ct == 1)return digit;
	ll half = val(digit, ct >> 1);
	half = mod_add(half, mod_mul(half, mod_exp(10, ct >> 1, md), md), md);
	if (ct & 1) {
		half = mod_mul(half, 10, md);
		half = mod_add(half, digit, md);
	}
	return half;
}

void solve() {
	ll k, m; cin >> k >> m;
	md = m * 10007;
	vector<pair<ll, ll>> arr;
	for (ll i = 0; i < k; i++) {
		ll a, b; cin >> a >> b;
		arr.push_back({a, b});
	}
	debug(arr);
	ll cnt = 0;
	ll ans = 0;
	for (ll i = k - 1; i >= 0; i--) {
		auto [u, v] = arr[i];
		ans = mod_add(ans, mod_mul(val(u, v), mod_exp(10, cnt, md), md), md);
		cnt += v;
	}
	// cout << cnt << endl;
	cout << ans / m << "\n";
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
#endif
	int tt = 1;
	// cin >> tt;
	while (tt--)
		solve();
}