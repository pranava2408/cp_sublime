#include <bits/stdc++.h>

// #ifndef ONLINE_JUDGE
// #include "../../debug.h"
// #else
// #define debug(...)
// #endif

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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> idxs;

    auto query = [&](ll idx, ll val) -> ll
    {
        cout << "? " << idx << " " << val << endl;
        ll va;
        cin >> va;
        return va;
    };

    ll mask = 0;

    // vector<ll> idxs;
    for (ll i = 0; i < n; i++)
        idxs.push_back(i + 1);

    ll val = 0;
    ll pre = 1;
    while (idxs.size() > 1)
    {
        vector<ll> g[2];

        for (auto pos : idxs)
        {
            if (pos == n)
                break;

            ll va = query(pos, (1LL << mask));
            g[va].push_back(pos);
        }

        ll have = g[pre].size();
        ll looking = (idxs.size()) / 2 + (idxs.size() % 2);

        if (have == looking)
        {
            idxs = g[!pre];
            if (pre == 0)
            {
                val |= (1LL << mask);
                pre = 0;
            }else{
                pre = 1;
            }
        }
        else
        {
            idxs = g[pre];
            if (pre)
            {
                val |= (1LL << mask);
                // pre = 0;
            }

            pre = 0;
            // else pre = 1;
            // else?
        }

        mask++;
        idxs.push_back(n);
        // cout<<mask<<" "<<pre<<endl;
    }
    if(pre)
    val |= (1LL << mask);
    cout << "! " << val << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // 	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
    // 	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
    // 	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
    // #endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
}