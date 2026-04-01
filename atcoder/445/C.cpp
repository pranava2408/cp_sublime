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

void solve() {
	ll n; cin >> n;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	vector<vector<ll>> cycles;
	vector<ll> cycle(n, -1);
	vector<ll> idxs(n, -1);
	vector<ll> dist(n, -1);
	vector<bool> vis(n, false);
	for (ll i = 0; i < n; i++) {
		ll node = i;
		ll dis = 0;
		while (!vis[node]) {
			vis[node] = true;
			node = a[node] - 1;
			dis ++;
		}

		if (cycle[node] != -1) {
			cycle[i] = cycle[node];
			dist[i] = dis;
		} else {
			vector<ll> path;
			path.emplace_back(node);
			ll temp = a[node] - 1;
			ll cnt= 0;
			while (temp != node) {
				idx[]
				path.push_back(node);
				temp = a[node] - 1;
			}
			cycle[i] = cycles.size();
			idxs[i] = 0;
			cycles.push_back(path);

		}
	}
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
	cin >> tt;
	while (tt--)
		solve();
}