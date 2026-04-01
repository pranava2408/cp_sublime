#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;


void solve() {
	ll n, k; cin >> n >> k;
	vector<vector<ll>> mat(n, vector<ll>(3));
	ll total = 0;
	for (ll i = 0; i < n; i++) {
		for (auto &pos : mat[i])
			cin >> pos, total += pos;
	}
	// for (ll i = 0; i < n; i++) {
	// 	for (ll j = 0; j < 3; j++) {
	// 		cerr << mat[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }
	vector<vector<ll>> prev(8, vector<ll>(k + 1, 1e15));
	vector<ll> setbits(8, 0);
	for (ll i = 0; i < 8; i++) {
		setbits[i] = __builtin_popcountll(i);
	}
	prev[0][0] = mat[0][0] + mat[0][1] + mat[0][2];
	prev[3][1] = mat[0][2];
	prev[6][1] = mat[0][0];
	for (ll i = 1; i < n; i++) {
		// cerr<<i<<endl;
		vector<vector<ll>> cur(8, vector<ll>(k + 1, 1e15));
		for (ll K = 0; K <= k; K++) {
			//no operation here
			// ll sum = mat[i][0]+mat[i][1]+mat[i][1]
			// no horizontal
			for (ll vert = 0; vert < 8; vert++) {
				// cerr<<vert<<endl;
				// ll ct = (vert)
				ll val = setbits[vert] + K;
				if (val > k)continue;
				ll neg = 7 ^ vert;
				ll su = 0;
				for (ll bits = 0; bits < 3; bits++) {
					if ((1LL << bits)&neg)su += mat[i][bits];
					else su -= mat[i - 1][bits];
				}
				// cerr<<su<<endl;
				for (ll pre = 0; pre < 8; pre++) {
					// cerr<<pre<<endl;
					if ((vert & pre) == 0) {
						cur[vert][val] = min(cur[vert][val], prev[pre][K] + su);
						// cerr<<cur[vert][val]<<endl;
					}
				}
				// cerr<<vert<<endl;
			}

			// cerr<<i<<" "<<K<<endl;
			// one horizontal
			for (ll previous = 0; previous < 8; previous++) {
				// if(prev)
				if (K != k) {
					cur[3][K + 1] = min(cur[3][K + 1], prev[previous][K] + mat[i][2]);
					cur[6][K + 1] = min(cur[6][K + 1], prev[previous][K] + mat[i][0]);
					// cerr<<prev
					// cerr << cur[3][K + 1] << endl;
					// cerr << cur[6][K + 1] << endl;
					// cerr<<mat[i][2]<<endl;
					if ((previous & 4) == 0 && K + 2 <= k) {
						cur[7][K + 2] = min(cur[7][K + 2], prev[previous][K] - mat[i - 1][2]);
					}
					if ((previous & 1) == 0 && K + 2 <= k) {
						cur[7][K + 2] = min(cur[7][K + 2], prev[previous][K] - mat[i - 1][0]);
					}

					// cerr << i << " " << cur[7][K + 1] << endl;
					// cerr << previous << " " << K << endl;
				}

			}

		}


		prev = cur;

		// cerr<<prev[0][0]<<endl;

		// for (ll j = 0; j < 8; j++)
		// {
		// 	// cerr<<prev[j][k]<<endl;
		// 	for (ll K = 0; K <= k; K++) {
		// 		// if (prev[j][K] < 0) {
		// 		// cerr << j << " " << K << " " << prev[j][K] << endl;
		// 		// }
		// 	}
		// }
	}
	// cur[6]

	ll answer = 1e18;
	for (ll i = 0; i < 8; i++) {
		answer = min(answer, prev[i][k]);
	}
	// cerr << total << " " << answer << endl;
	// cerr<<answer<<endl;
	cout << total - answer << endl;
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