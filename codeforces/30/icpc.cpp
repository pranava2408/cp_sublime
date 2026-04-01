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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll uid(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }


void solve() {
    ll t = uid(1, 100);
    ll val = 200000 / t;
    ll q = 200000 / t;
    cout << t << "\n";
    for (ll i = 0; i < t; i++) {
        // cout << val << " ";
        // ll l = uid(1, 1e18);
        // ll r = uid(1, 1e18);
        // if (l > r)swap(l, r);
        cout << val << ' ' << q << ' ' << uid(1, 1e9) << '\n';
        // cout << uid(1e9, 1e9) << " ";
        for (ll j = 0; j < val - 1; j++) {
            cout << uid(1, 1e9) << " \n"[j == val - 1];
        }

        for (ll j = 0; j < q; j++) {
            ll type = uid(1, 3);
            if (type == 1 || type == 2) {
                ll l = uid(1, val);
                ll r = uid(1, val);
                // l = 1 , r = val;
                if (l > r)swap(l, r);
                ll val = uid(1, 1e9);
                cout << type << ' ' << l << ' ' << r << ' ' << val << '\n';
            } else {
                ll idx = uid(1, val);
                cout << type << ' ' << idx << ' ' << uid(1, 1e9) << '\n';
            }
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
    // cin >> tt;
    while (tt--)
        solve();
}