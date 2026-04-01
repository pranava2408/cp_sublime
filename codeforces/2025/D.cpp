#include <bits/stdc++.h>
#include <queue>

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
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	if (m > (n / 2)) {
		cout << "-1\n";
		return;
	}
	map<ll, ll> id;
	for (ll i = 0; i < n; i++)id[a[i]] = i + 1;
	sort(a.begin(), a.end());

	vector<ll> heal = a ;

	vector<bool> died (n, false);
	vector<pair<ll, ll>> answer;
	if (m == 0) {
		set<pair<ll, ll>> jus;
		for (ll i = 0; i < n; i++)jus.insert({a[i], i});

		for (ll i = 0; i <n; i++) {
			if (!died[i]) {
				
				auto it = --jus.end();

				if (it->second == i) {
					if (it == jus.begin()) {
						cout << "-1\n";
						return;
					}
					it--;
				}
				auto [u, v] = *it;
				answer.emplace_back(i , v );

				jus.erase(it);
				jus.erase({heal[i], i});

				heal[v] -= a[i];


				heal[i] -= a[v];



				if (heal[v] > 0) {
					jus.insert({heal[v], v});
				} else {
					died[v] = true;
				}

				if (heal[i] > 0) {
					jus.insert({heal[i], i});
				} else {
					died[i] = true;
				}
				debug(jus);
			}
		}
		

		if (jus.size()) {
			cout << -1 << "\n";
			return;
		}
		debug(a, id, answer);
		cout << answer.size() << "\n";
		for (auto pos : answer) {
			cout << id[a[pos.first]] << " " << id[a[pos.second]] << "\n";
		}
		return;
	}



	ll other = n - m;
	ll diff = other - m ;
	for (ll i = 0; i < diff; i++) {
		answer.emplace_back(i, i + 1);
	}


	for (ll i = n - 1; i >= n - m; i--)answer.emplace_back(i, i - m);
	cout << answer.size() << "\n";
	for (auto pos : answer) {
		cout << id[a[pos.first]] << " " << id[a[pos.second]] << "\n";
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