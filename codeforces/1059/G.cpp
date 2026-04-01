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
	ll n ; cin >> n;
	if (n == 2) {
		cout << -1 << endl;
		return;
	}
	if (n >= 7) {
		ll val = n - 4;
		cout << 1 << " " << val << '\n';
		ll prod = val;
		for (ll i = 1; i <= n; i++) {
			if (i != 2 && i != val) {
				cout << 2 << " " << i << '\n';
				// prod += (i << 1);
			}
		}
		return;
	}
	if (n == 3) {
		cout << "1 3\n3 2\n"; return;
	}
	if (n == 4) {
		// cout<<
		cout << "1 2\n3 1\n4 1\n"; return;
	}
	if (n == 5) {
		cout<<"2 1\n2 3\n2 4\n4 5\n";return;
	}
	
	if(n==6){
		cout<<"1 2\n1 3\n1 4\n1 6\n2 5\n";return;
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