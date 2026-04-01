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
const ll NEG = (ll)-4e18;

vector<int> to_base3(ll x, int D) {
    vector<int> v(D, 0);
    for (int i = D - 1; i >= 0; --i) {
        v[i] = x % 3;
        x /= 3;
    }
    return v;
}

ll dp_dfs(int pos, bool tightL, bool tightR, bool started,
           const vector<int>& low, const vector<int>& high,
           vector<array<array<array<ll,2>,2>,64>>& memo) {
    if (pos == (int)low.size()) {
        return started ? 0 : 1;
    }
    ll &mem = memo[pos][tightL][tightR][started];
    if (mem != NEG) return mem;

    int lo = tightL ? low[pos] : 0;
    int hi = tightR ? high[pos] : 2;
    ll best = NEG;

    for (int d = lo; d <= hi; ++d) {
        bool nTightL = tightL && (d == lo);
        bool nTightR = tightR && (d == hi);
        bool nStarted = started || (d != 0);
        ll add = 0;
        if (nStarted) add = d + 1;
        ll sub = dp_dfs(pos + 1, nTightL, nTightR, nStarted, low, high, memo);
        if (sub == NEG) continue;
        best = max(best, add + sub);
    }
    mem = best;
    return mem;
}

ll solve_one(ll L, ll R) {
    int D = 1;
    {
        __int128 p = 3;
        while (p <= R) {
            p *= 3;
            ++D;
        }
    }
    vector<int> low = to_base3(L, D);
    vector<int> high = to_base3(R, D);

    vector<array<array<array<ll,2>,2>,64>> memo;
    memo.resize(D);
    for (int i = 0; i < D; ++i) {
        for (int a = 0; a < 2; ++a)
            for (int b = 0; b < 2; ++b)
                for (int s = 0; s < 2; ++s)
                    memo[i][a][b][s] = NEG;
    }

    return dp_dfs(0, true, true, false, low, high, memo);
}

void solve() {
    long long l, r;
    cin >> l >> r;
    cout << solve_one(l, r) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("F:\\cp_sublime\\input.txt", "r", stdin);
    freopen("F:\\cp_sublime\\output.txt", "w", stdout);
    freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
