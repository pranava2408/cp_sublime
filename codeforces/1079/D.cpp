#include <bits/stdc++.h>

// #ifndef ONLINE_JUDGE
// #include "../../debug.h"
// #else
// #define debug(...)
// #endif

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
	// map<ll, vector<ll>> mp;
	auto query = [&](ll val)->vector<ll> {
		// if (mp.find(val) != mp.end())return mp[val];
		cout << "? " << val << endl;
		ll len = 0;
		cin >> len;
		vector<ll> arr(len);
		for (auto &pos : arr)cin >> pos;
		return arr;
	};

	vector<set<vector<ll>>> paths(n + 1);

	set<pair<ll, ll>> edges;
	ll nex = 1;
	vector<ll> cnt(n + 1, 0);
	vector<bool> done(n + 1, false);
	for (ll i = 1; i <= n; i++) {
		if (!done[i]) {
			cnt[i]++;
			set<ll> tem;
			while (true) {
				vector<ll> temp = query(nex + 1);
				if (temp.size() == 0)break;
				if (temp[0] == i) {

					ll len = temp.size();
					for (ll j = 0; j < len - 1; j++) {
						edges.insert({temp[j], temp[j + 1]});
					}

					ll step = 1;
					if (done[temp.back()])step = cnt[temp.back()];
					vector<ll> jus;
					for (auto pos : temp) {
						jus.push_back(pos);
						if (!done[pos]) {
							if (!paths[pos].count(jus)) {
								paths[pos].insert(jus);
								cnt[pos] += step;
							}
							tem.insert(pos);
						}
					}
					nex += step;
				} else break;
			}
			for (auto pos : tem)done[pos] = true;
			nex ++;
		}
		else
			nex += (cnt[i]);
	}
	// cout << endl;
	// for (ll i = 1; i <= n; i++)cout << cnt[i] << " ";
	// cout << endl;
	cout << "! " << edges.size() << endl;
	for (auto pos : edges) {
		cout << pos.first << " " << pos.second << endl;
	}
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
// 	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
// 	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
// #endif
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}