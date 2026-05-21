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
	ll n, m; cin >> n >> m;
	vector<string> mat(n);
	for (ll i = 0; i < n; i++) {
		cin >> mat[i];
	}

	debug(mat);
	vector<vector<vector<vector<ll>>>> par(n, vector<vector<vector<ll>>>(m, vector<vector<ll>>(4)));


	queue<vector<ll>> bfs;

	ll is = 0 , js = 0, I, J;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (mat[i][j] == 'S')
			{
				is = i, js = j;
			}
			if (mat[i][j] == 'G') {
				I = i, J = j;
			}
		}
	}
	vector<pair<ll, ll>> dir = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
	string pat = "RLDU";
	// map<pair<ll, ll>, ll> marker;
	// for (ll i = 0; i < 4; i++) {
	// 	marker[dir[i]] = i;
	// }


	for (ll i = 0; i < 4; i++) {
		bfs.push({is, js, i});
	}


	while (bfs.size()) {
		auto tp = bfs.front();
		debug(tp);
		bfs.pop();
		for (ll i = 0; i < 4; i++) {
			auto pos = dir[i];
			ll nex = tp[0] + pos.first;
			ll nexy = tp[1] + pos.second;
			if (nex >= 0 && nexy >= 0 && nex < n && nexy < m && par[nex][nexy][i].size() == 0 && mat[nex][nexy] != '#') {
				if (mat[tp[0]][tp[1]] == 'o' && i != tp[2]) {
					continue;
				}
				if (mat[tp[0]][tp[1]] == 'x' && i == tp[2]) {
					continue;
				}


				par[nex][nexy][i] = tp;

				bfs.push({nex, nexy, i});
			}
		}



		if (tp[0] == I && tp[1] == J) {
			cout << "Yes\n";
			string path ;


			while (tp[0] != is || tp[1] != js) {
				path.push_back(pat[tp[2]]);
				tp = par[tp[0]][tp[1]][tp[2]];
			}
			reverse(path.begin(), path.end());

			cout << path << endl;
			return;
		}
	}

	cout << "No\n";
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