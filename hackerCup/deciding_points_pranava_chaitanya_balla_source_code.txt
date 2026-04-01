#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../debug.h"
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



void solve(ll test) {
  ll n , m; cin >> n >> m;
  // if (m == 1) {
  //   cout << "NO" << '\n';
  //   return;
  // }
  // m += (m - 2);
  // cout << (m <= n ? "YES" : "NO") << '\n';

  if (n % 2 == 0) {
    // cout << "YES\n";
    // return;

    ll val = n + 2;
    val >>= 1;
    if (val >= m && val >= 2) {
      cout << "YES\n";
      return;
    }
  }
  ll left = n - m;
  if (left >= 0 && left <= m - 2) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

void main_() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("F:\\cp_sublime\\input.txt", "r", stdin);
  freopen("F:\\cp_sublime\\output.txt", "w", stdout);
  freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
#endif
  int tt = 1;
  cin >> tt;
  for (ll i = 1; i <= tt; i++) {
    cout << "Case #" << i << ": ";
    solve(i);
  }
}

static void run_main() {
  main_();
  exit(0);
}
int main() {
  size_t stsize = 1024 * 1024 * 1024; // run with a 1 GiB stack
  char *stack, *send;
  stack = (char *)malloc(stsize);
  send = stack + stsize;
  send = (char *)((uintptr_t)send / 16 * 16);
  asm volatile(
    "mov %0, %%rsp\n"
    "call *%1\n"
    :
    : "r"(send), "r"(run_main));
  return 0;
}