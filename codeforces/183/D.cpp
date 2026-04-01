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

bool dp[31][1000];
array<ll, 2> par[31][1000];

void solve() {
	ll n , k; cin >> n >> k;
	ll left = (n * (n - 1)) / 2  - k ;
	// cout<<left<<endl;
	debug(left);
	if (dp[n][left]) {
		k = left;
		vector<ll>answer(n);
		ll val = 1;
		ll idx = n;

		while (idx > 0) {
			debug(idx);
			auto nex = par[idx][k];
			debug(nex);
			for(ll j = nex[0]+1;j<=idx;j++)answer[j-1]=val++;
			// reverse(answer.begin() + start , answer.begin() + stop);
			idx = nex[0], k = nex[1];
		} for (auto pos : answer)cout << pos << " ";
		cout << endl;
		return;
	}
	cout<<0<<endl;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
#endif

	for (ll i = 0; i < 31; i++)
		for (ll j = 0; j < 1000; j++)
			dp[i][j] = false;
	dp[0][0] = true;
	for (ll i = 1; i <= 30; i++) {
		for (ll j = 1; j <= i; j++) {
			ll len = i- j + 1;
			ll cnt = (len * (len - 1)) >> 1;
			// cout<<cnt<<endl;
			// debug(len,cnt);
			for (ll k = 0; k < 1000; k++) {
				// for (ll l = 0; l < j; l++) {
				// 	if (dp[l][k]) {
				// 		ll val = cnt + k;
				// 		if (val < 1000)dp[i][val] = true, par[i][val] = {l, k, j};
				// 		debug(i,val);
				// 	}
				// }
				if(dp[j-1][k]){
					ll val = cnt + k;
					// debug(j,i);
					// debug(i,val);
					if(val<1000)dp[i][val]=true,par[i][val]={j-1,k};
				}
			}
		}
	}
	// debug(dp);
	// debug(par);
	
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}