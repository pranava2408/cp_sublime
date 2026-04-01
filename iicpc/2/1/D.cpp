#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;

struct Node {
	ll mini = 1e18;
	ll idx = 0;
};
Node id;
struct Stree {
	vector<Node> segtree;
	vector<ll> arr;
	void init(ll n, vector<ll> A) {
		arr = A;
		segtree.resize(4 * (n + 1));
	}

	Node merge(Node left, Node right) {
		Node cur;
		cur.mini = min(left.mini, right.mini);
		if (left.mini <= right.mini)cur.idx = left.idx;
		else cur.idx = right.idx;
		return cur;
	}

	void propagate(ll tl, ll tr, ll node) {}

	void build(ll l, ll r, ll node) {
		if (l > r) return;
		if (l == r) {
			segtree[node].mini = arr[l];
			segtree[node].idx = l;
			return;
		}
		ll mid = (l + r) >> 1;
		build(l, mid, 2 * node);
		build(mid + 1, r, 2 * node + 1);
		segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
	}

	Node query(ll l, ll r, ll tl, ll tr, ll node) {
		propagate(tl, tr, node);
		if (l > r || tl > tr || tl > r || tr < l) return id;

		if (tl >= l && tr <= r) {
			return segtree[node];
		}

		ll mid = (tl + tr) >> 1;
		return merge(query(l, r, tl, mid, 2 * node) ,
		             query(l, r, mid + 1, tr, 2 * node + 1));
	}


	// ll query(ll idx, ll tl, ll tr, ll node)
	// {
	// 	propagate(tl, tr, node);
	// 	if (tr <= idx || tl > tr || segtree[node].mini > arr[idx]) return -1;

	// 	if (tl == tr) {
	// 		// return segtree[node].sum;
	// 		return tl;
	// 	}

	// 	ll mid = (tl + tr) >> 1;
	// 	// if (idx <= mid) {
	// 	ll val =  query(idx, tl, mid, 2 * node);
	// 	if (val != -1)return val;
	// 	// }

	// 	return query(idx, mid + 1, tr, 2 * node + 1);

	// }


	// void update(ll l, ll r, ll type, ll tl, ll tr, ll node) {
	//   propagate(tl, tr, node);
	//   ll mid = (tl + tr) >> 1;
	//   if (tl > tr || tr < l || tl > r || l > r) return;

	//   if (tl >= l && tr <= r) {
	//     return;
	//   }
	//   update(l, r, type, tl, mid, 2 * node);
	//   update(l, r, type, mid + 1, tr, 2 * node + 1);

	//   segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
	// }
};

void solve() {
	ll n, b, c; cin >> n >> b >> c;
	vector<ll> idxs(n);
	// for (auto &pos : idxs)cin >> pos;
	vector<ll> cost(n);
	// for (auto &pos : cost)cin >> pos;
	for (ll i = 0; i < n; i++)cin >> idxs[i] >> cost[i];
	stack<ll> mono;
	mono.push(n - 1);
	vector<ll> less(n, -1);
	for (ll i = n - 2; i >= 0; i--) {
		while (mono.size() && cost[mono.top()] > cost[i])mono.pop();
		if (mono.size())less[i] = mono.top();
		mono.push(i);
	}

	ll cur = 0;
	ll answer = idxs[0];
	ll have = 0;
	while (true) {
		// cerr<<cur<<" "<<have<<" "<<b<<endl;
		ll nex = less[cur];
		ll cos = cost[cur];
		ll can = b / cos;
		if (can == 0) {
			answer = idxs[cur] +  have;
			break;
		}
		if (nex != -1) {
			ll need = idxs[nex] - idxs[cur];
			ll tot = have + can;
			tot = min(tot, c);
			if (tot >= need) {
				ll take = max(0ll, need - have);
				b -= cos * take ;
				// have -= need;
				have += take;
				have -= need;
				cur =  nex;
				continue;
			}
			// else if (nex == cur + 1) {
			// 	have += can ;
			// 	have = min(have, c);
			// 	answer = idxs[cur] + have;
			// 	b=0;
			// 	break;
			// }
			else {
				ll ne = min(can, c - have);
				have += ne ;
				// have = min(have, c)

				b -= ne * cos;
				ll aage = (idxs[cur + 1] - idxs[cur]);
				if (aage <= have)have -= aage, cur ++;
				else {answer = idxs[cur] + have; break;}
			}
		}

		else if (cur == n - 1) {
			have += can;
			have = min(have, c);
			answer = idxs[cur] + have;
			b = 0;
			break;
		}
		else {
			ll need = c - have;
			ll take = min(need, can);
			have += take ;
			b -= take * cos;	// cur++ ;
			ll aage = (idxs[cur + 1] - idxs[cur]);
			if (aage <= have)have -= aage, cur ++;
			else {answer = idxs[cur] + have; break;}
		}
	}
	cout << answer << endl;
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