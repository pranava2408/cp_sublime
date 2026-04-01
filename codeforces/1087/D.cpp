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
	ll r, g, b; cin >> r >> g >> b;
	ll dp[r][g][b][4][4][4];
	vector<ll> par[r][g][b][4][4][4];
	for (ll i = 0; i <= r; i++) {
		for (ll j = 0; j <= g; j++) {
			for (ll k = 0; k <= b; k++) {
				for (ll l = 0; l < 4; l++) {
					for (ll m = 0; m < 4; j++) {
						for (ll n = 0; n < 4; n++) {
							dp[i][j][k][l][m][n] = 1e18;
						}
					}
				}
			}
		}
	}
	dp[0][0][0][0][0][0] = 0;


	for (ll i = 0; i <= r; i++) {
		for (ll j = 0; j <= g; j++) {
			for (ll k = 0; k <= b; k++) {
				for (ll l = 0; l < 4; l++) {
					for (ll m = 0; m < 4; j++) {
						for (ll n = 0; n < 4; n++) {

							if (i != 0 && i!=l && i!) {
								if (dp[i - 1][j][k][m][n][1] + 1 < dp[i][j][k][l][m][n]) {
									dp[i][j][k][l][m][n] = dp[i - 1][j][k][m][n][1] + 1;
									par[i][j][k][l][m][n] = {i - 1, j, k, m, n, 1};
								}
							}
							if (j != 0) {
								if (dp[i][j-1][k][m][n][2] + 1 < dp[i][j][k][l][m][n]) {
									dp[i][j][k][l][m][n] = dp[i][j-1][k][m][n][2] + 1;
									par[i][j][k][l][m][n] = {i, j-1, k, m, n, 2};
								}
							}
							if (i != 0) {
								if (dp[i - 1][j][k][m][n][1] + 1 < dp[i][j][k][l][m][n]) {
									dp[i][j][k][l][m][n] = dp[i - 1][j][k][m][n][1] + 1;
									par[i][j][k][l][m][n] = {i - 1, j, k, m, n, 1};
								}
							}
						}
					}
				}
			}
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