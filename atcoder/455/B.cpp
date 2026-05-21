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


void solve() {
	ll h, w; cin >> h >> w;
	vector<string> mat;
	for (ll i = 0; i < h; i++) {
		string temp; cin >> temp;
		mat.push_back(temp);
	}
	debug(mat);
	ll ans = 0 ;
	for (ll i1 = 0; i1 < h; i1++) {
		for (ll i2 = i1; i2 < h; i2++) {
			for (ll j1 = 0; j1 < w; j1++) {
				for (ll j2 = j1; j2 < w; j2++) {
					// we need to check
					bool ck = true;
					for (ll i = i1; i <= i2; i++) {
						for (ll j = j1; j <= j2; j++) {
							if (mat[i][j] != mat[i1 + i2 - i][j1 + j2 - j]) {
								ck = false;
								break;
							}
						}
					}
					ans += ck;
				}
			}
		}
	}
	cout << ans << endl;
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