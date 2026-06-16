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
	ll n; cin >> n;
	vector<ll> graph[n];
	for (int i = 0; i < n - 1; i++) {
		ll u , v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<ll> parent(n, -1);

	// parent[0] =0;

	function<void(ll)> dfs = [&](ll node)-> void{
		for (auto pos : graph[node]) {
			if (pos != parent[node]) {
				parent[pos] = node;
				dfs(pos);
			}
		}
	};
	vector<ll> subtree(n, -1);
	function<ll(ll)> subtreeSize = [&](ll node)->ll{
		if (subtree[node] != -1)return subtree[node];
		ll siz = 1;
		for (auto pos : graph[node]) {
			if (pos != parent[node]) {
				siz += subtreeSize(pos);
			}
		}

		return subtree[node] = siz;
	};
	vector<ll> sums(n, -1);
	function<ll(ll)> sum = [&](ll node)->ll{
		if (sums[node] != -1)return sums[node];
		ll siz = subtreeSize(node);
		for (auto pos : graph[node]) {
			if (pos != parent[node]) {
				siz += sum(pos);
			}
		}

		return sums[node] = siz;
	};
	vector<ll> dp(n, -1);
	function<ll(ll)> dpval = [&](ll node)->ll{
		if (dp[node] != -1)return dp[node];
		if (parent[node] == -1) {
			return dp[node] = 0;
		}

		ll par = dpval(parent[node]);

		ll left = n - subtreeSize(node);

		par += left;

		par += sum(parent[node]);

		par -= subtreeSize(parent[node]);

		par -= sum(node);
		
		return dp[node] = par;
	};
	
	dfs(0);
	cout<<dpval(0) + sum(0) - subtreeSize(0)<<endl;
	for(int i=1;i<n;i++){
		cout<<dpval(i) + sum(i) - subtreeSize(i)<<" ";
	}
	
	
	
	debug(dp);
	
	cout<<"\n";


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