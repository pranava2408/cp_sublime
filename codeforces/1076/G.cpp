#include <bits/stdc++.h>
#include <functional>
#include <valarray>

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
	// cout << "reached\n";
	vector<ll> graph[n + 1];
	debug(n);
	for (ll i = 0; i < n - 1; i++) {
		ll u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	// ll timer = 0;
	// vector<ll> tin(n + 1, -1), tout(n + 1, -1);
	// function<void(ll)> dfs = [&](ll node)->void{
	// 	tin[node] = timer ++;
	// 	for (auto pos : graph[node]) {
	// 		if (tin[pos] == -1) {
	// 			dfs(pos);
	// 		}
	// 	}
	// 	tout[node] = timer ++;
	// };
	// dfs(1);
	// ll root = -1;
	// vector<ll> leafs;
	// for (ll i = 1; i <= n; i++) {
	// 	if (graph[i].size() == 1) {
	// 		if (root == -1) {
	// 			root = i ;
	// 		} else {
	// 			leafs.push_back(i);
	// 		}
	// 	}
	// }
	// debug(root);
	vector<ll> parent(n + 1, -1);
	vector<ll> height(n + 1, 0);
	parent[1] = 1;
	function<void(ll)> dfs = [&](ll node)->void{
		for (auto pos : graph[node]) {
			if (parent[pos] == -1) {
				height[pos] = height[node] + 1;
				parent[pos] = node;
				dfs(pos);
			}
		}
	};
	dfs(1);


	// ll len = leafs.size();
	// debug(leafs);
	// ll looking = -1;
	auto query = [&](ll A , ll B)->ll{
		cout << "? " << A << " " << B << endl;
		ll val ; cin >> val;
		return val;
	};
	// sort(leafs.begin(), leafs.end(), [&](ll _1, ll _2) {
	// 	return height[_1] > height[_2];
	// });
	// for (ll i = 0; i < len; i += 2) {
	// 	if (i == len - 1) {
	// 		looking = leafs[i];
	// 		break;
	// 	}
	// 	else if (i == len - 2) {
	// 		if (query(leafs[i], root)) {
	// 			looking = leafs[i];
	// 		} else {
	// 			looking = leafs[i + 1];
	// 		}
	// 		break;
	// 	}
	// 	else if (query(leafs[i], leafs[i + 1])) {
	// 		if (query(leafs[i], root)) {
	// 			looking = leafs[i];
	// 		} else looking = leafs[i];

	// 		break;
	// 	}
	// }
	// debug(looking);

	// vector<ll> total;
	// ll va = looking;
	// while (looking != root) {
	// 	total.push_back(looking);
	// 	looking = parent[looking];
	// }
	// // if (va == leafs[0])
	// 	total.push_back(root);
	// ll ans = total[0];

	// ll low = 1, high = total.size() - 1;
	// while (low <= high) {
	// 	ll mid = (low + high) >> 1;
	// 	ll val = total[mid];

	// 	if (query(root, val)) {
	// 		ans = val;
	// 		low = mid + 1;
	// 	} else high = mid - 1;
	// }

	// cout << "! " << ans << endl;

	set<ll> temp;
	for (ll i = 1; i <= n; i++)temp.insert(i);

	vector<ll> left;

	while (temp.size()) {
		ll val = *temp.begin();
		temp.erase(val);
		// temp.erase(temp.begin());
		bool ck = false;
		for (auto pos : graph[val]) {
			if (temp.count(pos)) {
				if (query(val, pos)) {
					if (query(val, val)) {
						cout << "! " << val << endl;
						return;
					}
					cout << "! " << pos << endl;
					return;
				}
				ck = true;


				temp.erase(pos);
				break;
			}
		}
		if (!ck) {
			left.push_back(val);
		}
	}
	// auto ispar = [&](ll a,ll b)->bool{
	// return tin[a]<=tin[b] && tout[b]>=tout
	// };
	sort(left.begin(), left.end(), [&](ll a, ll b) {return height[a] < height[b];});
	// sort(left.begin(), left.end(), [&](ll a, ll b) {
	// 	return ispar(a, b);
	// });

	ll len = left.size();
	for (ll i = 0; i < len; i += 2) {
		if (i == len - 1) {
			cout << "! " << left[i] << endl;
			return;
		}

		if (query(left[i], left[i + 1])) {
			if (query(left[i], left[i])) {
				cout << "! " << left[i] << endl;
				return;
			}
			cout << "! " << left[i + 1] << endl;
			return;
		}
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