#include <bits/stdc++.h>
#include <climits>

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


struct Node {
	ll mini = LLONG_MAX;
	Node(ll val, ll idx) {
		mini = val;
	}
	Node() {

	}
};

struct Stree {
	vector<Node> segtree;
	vector<ll> arr;
	void init(ll n, vector<ll> A) {
		arr = A;
		segtree.resize(4 * (n + 1));
	}

	Node merge(const Node &left, const Node &right) {
		Node cur;
		cur.mini = min(left.mini, right.mini);
		return cur;
	}

	void propagate(ll tl, ll tr, ll node) {

	}

	void build(ll l, ll r, ll node) {
		if (l > r) return;
		if (l == r) {
			segtree[node] = Node(arr[l], l);
			return;
		}
		ll mid = (l + r) >> 1;
		build(l, mid, 2 * node);
		build(mid + 1, r, 2 * node + 1);
		segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
	}

	Node query(ll l, ll r, ll tl, ll tr, ll node) {
		propagate(tl, tr, node);
		if (l > r || tl > tr || tl > r || tr < l) return Node();

		if (tl >= l && tr <= r) {
			return segtree[node];
		}

		ll mid = (tl + tr) >> 1;
		return merge(query(l, r, tl, mid, 2 * node) ,
		             query(l, r, mid + 1, tr, 2 * node + 1));
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
			// we apply update
			return;
		}
		update(l, r, type, tl, mid, 2 * node);
		update(l, r, type, mid + 1, tr, 2 * node + 1);

		segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
	}


	void update(ll l, ll val, ll tl, ll tr, ll node) {
		propagate(tl, tr, node);
		ll mid = (tl + tr) >> 1;
		if (tl > tr || tr < l || tl > l) return;

		if (tl == l && tr == l) {
			segtree[node] = Node(val, l);
			return;
		}
		update(l, val, tl, mid, 2 * node);
		update(l, val, mid + 1, tr, 2 * node + 1);

		segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
	}
};

void solve() {
	ll n, q; cin >> n >> q;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	Stree just;
	just.init(n, a);
	just.build(0, n - 1, 1);
	while (q--) {
		ll type; cin >> type;
		ll l, r; cin >> l >> r;
		if (type == 1) {
			l--;
			a[l] = r;

			just.update(l, r, 0, n - 1, 1);


		} else {
			ll ans = 0;
			l --, r--;
			ll low = l , high = r;
			while (low <= high) {
				ll mid = (low + high) >> 1;
				ll val = just.query(l, mid, 0, n - 1, 1).mini;
				ll len = mid - l;

				if (val == len) {
					ans = 1;
					break;
				} else if (val > len) low = mid + 1;
				else high = mid - 1;

			}
			cout<<ans<<"\n";
		}
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