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


bool mat[8001][8001];
bool mat1[8001][8001];

struct DSU {
	vector<ll> parent;
	vector<ll> rank;
	ll N;

	void init(ll n) {
		N = n;
		parent.resize(n + 1);
		rank.resize(n + 1, 1);
		for (ll i = 1; i <= n; i++) {
			parent[i] = i;
		}
	}
	ll get(ll node) {
		return (parent[node] == node ? node : parent[node] = get(parent[node]));
	}

	bool unite(ll a, ll b) {
		ll A = get(a);
		ll B = get(b);
		if (rank[A] < rank[B]) swap(B, A);
		if (A == B) return false;

		parent[B] = A;
		rank[A] += rank[B];
		return true;
	}
};

void solve() {
	ll n; cin >> n;
	vector<ll> adj[n + 1];
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			mat[i][j] = false;
			mat1[i][j] = false;
		}
	}
	bool ck = true;
	for (ll i = 1; i <= n; i++) {
		string str ; cin >> str;
		// debug(str);
		for (ll j = 0; j < n; j++) {
			if (str[j] == '1' && j != (i - 1)) {
				mat[i][j + 1] = true;
				adj[i].push_back(j + 1);
			}
		}

		if (str[i - 1] == '0') {
			ck = false;
		}

		// debug(adj[i]);
	}

	if (!ck) {
		cout << "No\n";
		return;
	}

	vector<ll> indegree(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		for (auto pos : adj[i]) {
			indegree[pos]++;
		}
	}
	// debug(indegree);
	queue<ll> temp;
	for (ll i = 1; i <= n; i++) {
		if (indegree[i] == 0)temp.push(i);
	}

	vector<ll> list;
	while (temp.size()) {
		ll val = temp.front();
		temp.pop();
		list.push_back(val);
		for (auto pos : adj[val]) {
			indegree[pos]--;
			if (indegree[pos] == 0)temp.push(pos);
		}
	}



	// debug(list );

	if (list.size() != n) {
		cout << "No\n";
		return;
	}



	// cout << "Yes\n";

	// vector<> ans(n + 1);

	debug(list);
	// reverse(list.begin(), list.end());
	// debug(list);
	vector<ll> adj1[n + 1];
	for (ll i = n - 1; i >= 0; i--) {
		ll val = list[i];

		for (ll j = i + 1; j < n; j++) {
			if (mat[val][list[j]]) {
				if (mat1[val][list[j]] == false)
					adj1[val].push_back(list[j]);
				mat1[val][list[j]] = true;
				for (auto pos : adj1[list[j]]) {
					mat1[val][pos] = true;
				}
			}
			// }
		}


		debug(adj1[val]);
	}

	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			if (mat[i][j] != mat1[i][j]) {
				cout << "No\n";
				return;
			}
		}
	}

	vector<pair<ll, ll>>ans;
	for (ll i = 1; i <= n; i++) {
		for (auto pos : adj1[i])ans.push_back({i, pos});
	}

	if (ans.size() != (n - 1)) {
		cout << "No\n";
		return;
	}

	DSU cur;
	cur.init(n);
	for (auto pos : ans)
	{
		cur.unite(pos.first, pos.second);
	}

	ll par = cur.get(1);
	for (ll i = 2; i <= n; i++) {
		if (par != cur.get(i)) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
	for (auto pos : ans) {
		cout << pos.first << " " << pos.second << "\n";
	}
	// cout << "No\n";
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