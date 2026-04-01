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
	ll n, q; cin >> n >> q;
	vector<ll> a(n);
	for (auto &pos : a) {cin >> pos; pos--;}

	debug(n, q, a);
	vector<vector<ll>> paths;
	vector<pair<ll, ll>> idxs(n , { -1, -1});
	for (ll i = 0; i < n; i++) {
		if (idxs[i].first == -1) {

			debug(i);
			ll val = paths.size();
			vector<ll> cur ;
			cur.push_back(i);
			idxs[i] = {val, 0};
			ll I = a[i];
			while (idxs[I].first == -1) {
				idxs[I] = {val, cur.size()};
				cur.push_back(I);
				I = a[I];
			}

			cur.push_back(I);
			debug(cur);

			ll tot = cur.size();
			for (ll k = 1; k < tot - 1; k ++) {
				if (cur[k] == cur[tot - 1]) {
					vector<ll> newcur;
					for (ll j = tot - 1; j > k; j--) {
						newcur.push_back(cur[j]);
					}
					newcur.push_back(cur[k]);

					reverse(newcur.begin(), newcur.end());

					ll Le = newcur.size();
					for (ll j = 0; j < Le - 1; j++) {
						idxs[newcur[j]] = {val + 1ll, j};
					}

					while ((cur.size() + newcur.size()) != tot + 1)cur.pop_back();
					paths.push_back(cur);

					paths.push_back(newcur);
					break;
				}
			}

			if (paths.size() == val)paths.push_back(cur);
		}
	}


	debug(paths);

	ll Len = paths.size();
	vector<vector<ll>> pref(Len);

	for (ll i = 0; i < Len; i++) {
		ll L = paths[i].size();
		vector<ll> prefix(L, 0);
		prefix[0] = paths[i][0];
		for (ll j = 1; j < L; j++)prefix[j] += (prefix[j - 1] + paths[i][j]);
		pref[i] = prefix;
	}

	debug(pref);

	debug(idxs);

	function<ll(ll, ll)> query = [&](ll ops, ll idx)->ll{

		debug(ops, idx);
		if (ops == 0)return 0;
		auto [u, v] = idxs[idx];
		ll len = paths[u].size();
		if (paths[u][0] == paths[u].back()) {
			ll sum = pref[u][len - 2];
			ll need = ops / (len - 1);
			ll ans = need * sum;
			ll left = ops % (len - 1);
			if (left != 0) {
				ll nex = v + left - 1;
				if (nex < len - 1) {
					ans += pref[u][nex];
					if (v)ans -= pref[u][v - 1];
				}
				else {
					ans += pref[u][len - 2];
					if (v)ans -= pref[u][v - 1];
					ans += pref[u][nex - len];
				}


			}
			debug(ans, sum);
			return ans;
		}

		ll have = len - 1 - v;
		debug(have, len);
		ll mini = min(ops, have);
		ll left = ops - mini;
		ll ans = pref[u][v + mini - 1];
		if (v != 0) {
			ans -= pref[u][v - 1];
		}
		debug(ans);
		if (left) {
			ans += query(left, paths[u].back());
		}

		return ans;


	};

	while (q--) {
		ll op , idx;
		cin >> op >> idx;
		idx --;
		ll ans = query(op, idx) + op;
		cout << ans << "\n";

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