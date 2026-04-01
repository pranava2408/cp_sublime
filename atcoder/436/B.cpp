#include <bits/stdc++.h>
#include <limits>

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


void solve() {
	ll n; cin >> n;

	vector<vector<ll>> mat(n, vector<ll>(n, -1));
	ll val = n * n  - 1;
	// for(ll i=0;i<val;i++)
	mat[0][(n - 1) / 2] = 1;
	ll i = 0, j = (n - 1) / 2;
	while (val--) {
		debug(i,j);
		ll I = (i - 1 + n) % n, J = (j + 1) % n;
		if (mat[I][J] == -1) {
			mat[I][J] = mat[i][j] + 1;
            i = I , j = J;
		}
		else {
			mat[(i + 1) % n][j] = mat[i][j] + 1;
			i = (i+1)%n;
		}
		debug(val);
	}
	for (auto pos : mat) {
		for (auto posi : pos)cout << posi << " ";
		cout << '\n';
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
	// cin >> tt;
	while (tt--)
		solve();
}