#include <bits/stdc++.h>
#include <numeric>

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


string mergePalindromes(const string &s1, const string &s2) {
    // debug(s1, s2);
    vector<ll> cnt1(26, 0), cnt2(26, 0);
    for (auto pos : s1)cnt1[pos - 'a']++;
    for (auto pos : s2)cnt2[pos - 'a'] ++;
    string ans;
    for (ll i = 0; i < 2; i++) {
        for (ll j = 0; j < 2; j++) {
            ll val = i + j;
            // if (val == 2)break;
            ll I = i, J = j;
            vector<ll> totCnt(26, 0);
            // ll prev = -1, prev1 = -1;
            for (ll k = 0; k < 26; k++) {
                if (val == 2) {
                    totCnt[k] += cnt1[k] + cnt2[k];
                    if ((cnt1[k] % 2) && (cnt2[k] % 2)) {
                    }
                    else {

                        if (cnt1[k] % 2) {
                            totCnt[k]--;
                        } if (cnt2[k] % 2)totCnt[k]--;
                    }
                } else {
                    if (cnt1[k] % 2 == 0)totCnt[k] += cnt1[k];
                    else if (I) {
                        // totCnt[prev] -= cnt1[prev];
                        totCnt[k] += cnt1[k];
                        // prev = k;
                        I = 0;
                    } else {
                        totCnt[k] += (cnt1[k] - 1);
                    }
                    if (cnt2[k] % 2 == 0)totCnt[k] += cnt2[k];
                    else if (J) {
                        // totCnt[prev1] -= cnt2[prev1];
                        totCnt[k] += cnt2[k];
                        // prev1 = k;
                        J = 0;
                    } else {
                        totCnt[k] += (cnt2[k] - 1);
                    }

                }
            }


            ll sum = accumulate(totCnt.begin(), totCnt.end(), 0ll);
            if (sum >= ans.size()) {
                vector<char> cur(sum);
                ll l = 0, r = sum - 1;
                for (ll k = 0; k < 26; k++) {
                    if (totCnt[k] % 2 == 1) {
                        cur[(sum - 1) / 2] = (char)('a' + k);
                        totCnt[k]--;
                    }
                    while (totCnt[k] != 0) {
                        totCnt[k] -= 2;
                        cur[l++] = (char)('a' + k);
                        cur[r--] = (char)('a' + k);
                        // debug(l, r);
                    }
                }
                string current;
                for (auto pos : cur)current += pos;
                // debug(current);
                if (sum > ans.size()) {
                    ans = current;
                } else {
                    ans = min(ans, current);
                }
            }

        }
    }
    return ans;
}


void solve() {
    cout << mergePalindromes("adaab", "cca") << '\n';
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