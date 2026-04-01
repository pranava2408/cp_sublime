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
	ll a, b, c; cin >> a >> b >> c;
	ll n; cin >> n;
	debug(n);
	// cout<<n<<endl;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ll other = n / i;
			for (ll j = 1; j * j <= other; j++) {
				if (other % j == 0) {
					ll val = other;
					ll other1 = other / j;
					other = j;
					// debug(i,other,other1);
					if (a % i == 0 && b % other == 0 && c % other1 == 0) {
						cout << i - 1 << " " << other - 1 << " " << other1 - 1 << "\n";
						return ;

					} if (a % i == 0 && c % other == 0 && b % other1 == 0) {
						cout << i - 1 << " " << other1 - 1 << " " << other - 1 << "\n";
						return ;
					} if (b % i == 0 && a % other == 0 && c % other1 == 0) {
						cout << other - 1 << " " << i - 1 << " " << other1 - 1 << "\n";
						return ;
					}
					if (b % i == 0 && c % other == 0 && a % other1 == 0) {
						cout << other1 - 1 << " " << i - 1 << " " << other - 1 << "\n";
						return ;
					} if (c % i == 0 && a % other == 0 && b % other1 == 0) {
						cout << other - 1 << " " << other1 - 1 << " " << i - 1 << "\n";
						return ;
					} if (c % i == 0 && b % other == 0 && a % other1 == 0) {
						cout << other1 - 1 << " " << other - 1 << " " << i - 1 << "\n";
						return ;
					}
					other = val;
				}
			}
		}
	}
	cout<<-1<<"\n";
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