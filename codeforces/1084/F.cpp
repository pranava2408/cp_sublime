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
	/*	i was thinking of this
		dp[i][j] = maximum answer that we can get so far
		dp[i][j] = max(dp[k][j - 1] + (prefix[i] - prefix[k]) / (i - k));
		to eliminate the fraction we can store 
		n ^ 3 is straight forward to solve right ? 
		n^2 logn is a great optimization ? 
		we have to look for that 
		i mean what should we do ? 
		well not sure  ? 
		we can use the long double to solve this problem right ? 
		what about the precision ? 
		it will be precise enough ?
		we have to solve proving something  
		
	*/
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