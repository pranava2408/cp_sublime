#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;

struct Node {
	ll maxi = 0;
	ll mini = 1e18;
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
		cur.maxi = max(left.maxi, right.maxi);
		cur.mini = min(left.mini, right.mini);
		return cur;
	}

	void propagate(ll tl, ll tr, ll node) {}

	void build(ll l, ll r, ll node) {
		if (l > r) return;
		if (l == r) {
			// segtree[node].W = 1;
			segtree[node].maxi = segtree[node].mini = arr[l];
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
		return merge (query(l, r, tl, mid, 2 * node) ,
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

	// void update(ll l, ll r, ll type, ll tl, ll tr, ll node) {
	// 	propagate(tl, tr, node);
	// 	ll mid = (tl + tr) >> 1;
	// 	if (tl > tr || tr < l || tl > r || l > r) return;

	// 	if (tl >= l && tr <= r) {
	// 		return;
	// 	}
	// 	update(l, r, type, tl, mid, 2 * node);
	// 	update(l, r, type, mid + 1, tr, 2 * node + 1);

	// 	segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
	// }
};


void solve() {
	ll n; cin >> n;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	sort(a.begin(), a.end());
	vector<ll> temp(n);
	for (ll i = 0; i < n; i++) {
		temp[i] = a[i] + a[n - 1 - i];
	}
	// for(auto pos:temp){
	// 	cout<<pos<<endl;
	// }

	vector<ll> pref(n);
	pref[0] = temp[0];
	vector<ll> prefMin(n);
	prefMin[0] = temp[0];
	for (ll i = 1; i < n; i++) {
		pref[i] = max(pref[i - 1], temp[i]);
		prefMin[i] = min(prefMin[i - 1], temp[i]);
	}
	// cerr<<prefMin[1]<<endl;
	ll answer = 1e18;
	vector<ll> A(n);
	vector<ll> A1(n);
	for (ll i = 0; i < n; i++) {
		ll looking = n - 1 - i + 1;
		ll val = 1e18;
		if (looking < n) {
			val = a[i] + a[looking];
		}
		looking -= 2;
		ll va = 1e18;
		if (looking >= 0) {
			va = a[i] + a[looking];
		}
		A[i] = val;
		A1[i] = va;
	}
	Stree just;
	just.init(n, A);
	just.build(0, n - 1, 1);


	Stree just1;
	just1.init(n, A1);
	just1.build(0, n - 1, 1);
	// for(auto pos: A1){
	// 	cout<<pos<<endl;
	// }
	for (ll i = 0; i < n; i++) {

		ll cur = min(i, n - i - 1);
		ll maxi = 0;
		ll mini = 1e18;
		if (cur > 0) {
			maxi = pref[cur - 1];
			mini = prefMin[cur - 1];
		}
		// cerr << maxi << ' ' << mini << endl;
		// ll left = min(i,n-1-i);
		// ll right = max(i,n-1-i);
		// ll len=(right - left)/2;
		// ll other = left + (len/2) - 1;
		// Node jus= just.query(left+1,other,0,n-1,1);
		ll right = n - 1 - i;
		ll left = i;
		Node jus;
		ll have = abs(right - left);
		have >>= 1;
		if (right >= left) {
			// cerr<<left+1<<" "<<left+have<<endl;;
			jus = just.query(left + 1, left + have, 0, n - 1, 1);
		}
		else {
			// cerr<<right<<" "<<right+have-1<<endl;
			jus = just1.query(right, right + have-1 , 0, n - 1, 1);

		}
		// cerr<<jus.maxi<<" "<<jus.mini<<endl;
		// if (jus.maxi != 0) {
			maxi = max(maxi, jus.maxi);
			mini = min(mini, jus.mini);
		// }
		// cerr<<maxi<<" "<<mini<<endl;
		if(maxi>=mini)
		answer = min(answer, maxi -  mini);
	} cout << answer << endl;
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