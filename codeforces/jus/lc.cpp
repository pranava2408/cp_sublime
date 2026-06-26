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

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    
    ll div(ll a, ll b) { // Floored division
        return a / b - ((a ^ b) < 0 && a % b); 
    }
    
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    
    pair<ll,ll> query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return {l.k * x + l.m,l.k};
    }
};

void solve() {
  	ll n,k;cin>>n>>k;
  	vector<ll> calorie(n);
  	vector<ll> spoil(n);
  	for(auto &pos:calorie)cin>>pos;
  	for(auto &pos:spoil)cin>>pos;
  	LineContainer cht;
  	for(ll i=0;i<n;i++){
  		cht.add(-spoil[i],calorie[i]);
  	}
  	ll answer = 0;
  	for(ll i=0;i<k;i++){
  		auto [val,dec] = cht.query(i);
  		if(val<=0)break;
  		ll low = i + 1, high = k - 1;
  		ll ans = i;
  		auto ck = [&](ll mid)->bool{
  			auto [cur,slope] = cht.query(mid);
  			if(cur<=0)return false;
  			if(cur==(val + (mid-i) * dec)){
  				return true;
  			}	
  			return false;
  		};
  		while(low<=high){
  			ll mid = (low+high)>>1;
  			
  			if(ck(mid)){
  				ans = mid;
  				low = mid + 1;
  			}else high = mid - 1;
  		}
  		
  		ll terms = ans - i + 1;
  		debug(terms,val,dec);
  		
  		ll sum = 2 * val + (terms-1) * dec;
  		sum *= terms;
  		sum >>=1;
  		
  		answer += sum;
  		i = ans;
  	}
  	cout<<answer<<"\n";
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