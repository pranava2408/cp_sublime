#include <bits/stdc++.h>
#include <climits>
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

vector<ll> divisors[400501];
ll have[400510];


void solve() {
	ll n; cin >> n;
	vector<ll> a(n), b(n);
	for (auto &pos : a)cin >> pos;
	for (auto &pos : b)cin >> pos;
	debug(a);
	debug(b);
	// set<ll> tot;
	for (ll i = 0; i < n; i++) {
		for (auto pos : divisors[a[i]])have[pos] ++;
	}

	for (ll i = 0; i < n; i++) {
		for (auto pos : divisors[a[i]])have[pos] --;
		for (auto pos : divisors[a[i]]) {
			if (have[pos] && pos > 1) {
				for (auto posi : a) {
					for (auto F : divisors[posi])have[F] = 0;
				}
				cout << 0 << endl;
				return;
			}
		}
		// have[a[i]] ++ ;
		for (auto pos : divisors[a[i]])have[pos] ++;

	}



	ll answer  = LLONG_MAX;
	for (ll i = 0; i < n; i++) {
		for (auto pos : divisors[a[i]])have[pos] --;
		for (auto pos : divisors[a[i] + 1]) {
			if (have[pos] && pos > 1) {
				// for (auto posi : a) {
				// 	for (auto F : divisors[posi])have[F] = 0;
				// }
				// cout << 0 << endl;
				// return;
				answer = min(answer, b[i]);
				break;
			}
		}
		// have[a[i]] ++ ;
		for (auto pos : divisors[a[i]])have[pos] ++;

	}



	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (ll i = 0; i < n; i++) {
		if (a[i] % 2 == 1) {
			pq.push(b[i]);
		}
	}

	if (pq.size() > 1) {
		ll val = pq.top();
		pq.pop();
		ll val1 = pq.top();
		pq.pop();
		answer = min(answer, val + val1);
	}

	debug(answer);

	vector<pair<ll, ll>> jus ;
	for (ll i = 0; i < n; i++) {
		jus.emplace_back(b[i], a[i]);
		
		
		
	} sort(jus.begin(), jus.end());


	for (ll i = 1; i < n; i++) {

		for (auto pos : divisors[jus[i].second]) {
			if (pos == 1)continue;
			ll rem = jus[0].second % pos;
			rem = (pos - rem) % pos;
			answer = min(answer, rem * jus[0].first);
		}

	}


	cout << answer << endl;
	// cout<<(200000)%29<<endl;

	for (auto posi : a) {
		for (auto F : divisors[posi])have[F] = 0;
	}

	return;

}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
#endif
	for (ll i = 1; i <= 400500; i++) {
		for (ll j = i; j <= 400500; j += i) {
			divisors[j].push_back(i);
		}
	}

	for (ll i = 0; i <= 400509; i++)have[i] = 0;
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}