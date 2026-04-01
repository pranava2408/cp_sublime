#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
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
  vector<ll> a(n);
  for (auto & pos : a)cin >> pos;
  vector<ll> maxi(n + 1, -1e18);
  maxi[0] = 0;
  for (ll i = 0; i < n; i++) {
    ll ma = -1e18;
    for (ll j = n; j >= 0; j--) {
      if (j >= (a[i] - 1))maxi[max(j, a[i])] = max(maxi[max(j, a[i])], maxi[j] + 1);
    }
  }
  cout << *max_element(maxi.begin(), maxi.end()) << "\n";
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