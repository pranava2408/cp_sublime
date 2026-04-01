#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;


struct Node {

};

struct Stree {
	vector<Node> segtree;
	vector<ll> arr;
	void init(ll n, vll A) {
		arr = A;
		segtree.resize(4 * (n + 1));
	}

	Node merge(Node left, Node right) {
		Node cur;
		cur.cnt = left.cnt;
		for (auto &pos : right.cnt) {
			cur.cnt[pos.first] += pos.second;
		}
		return cur;
	}

	void propagate(ll tl, ll tr, ll node) {}

	void build(ll l, ll r, ll node) {
		if (l > r) return;
		if (l == r) {
			segtree[node].W = 1;
			return;
		}
		ll mid = (l + r) >> 1;
		build(l, mid, 2 * node);
		build(mid + 1, r, 2 * node + 1);
		segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
	}

	ll query(ll l, ll r, ll tl, ll tr, ll node) {
		propagate(tl, tr, node);
		if (l > r || tl > tr || tl > r || tr < l) return 0LL;

		if (tl >= l && tr <= r) {
			return segtree[node].sum;
		}

		ll mid = (tl + tr) >> 1;
		return query(l, r, tl, mid, 2 * node) +
		       query(l, r, mid + 1, tr, 2 * node + 1);
	}

	/*
	ll query(ll idx,ll tl, ll tr, ll node)
	{
	    propagate(tl,tr,node);

	    if(tl==tr){
	            return segtree[node].sum;
	    }

	    ll mid=(tl+tr)>>1;
	    if(idx<=mid){
	            return query(idx,tl,mid,2*node);
	    }

	    return query(idx,mid+1,tr,2*node+1);

	}
	*/

	void update(ll l, ll r, ll type, ll tl, ll tr, ll node) {
		propagate(tl, tr, node);
		ll mid = (tl + tr) >> 1;
		if (tl > tr || tr < l || tl > r || l > r) return;

		if (tl >= l && tr <= r) {
			return;
		}
		update(l, r, type, tl, mid, 2 * node);
		update(l, r, type, mid + 1, tr, 2 * node + 1);

		segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
	}
};

void solve() {
	ll n, q; cin >> n >> q;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	
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