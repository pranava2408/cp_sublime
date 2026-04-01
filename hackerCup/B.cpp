#include <bits/stdc++.h>
#include <queue>

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

ll cnt[1000001];

void solve(ll test) {
	ll n, m; cin >> n >> m;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	for (auto pos : a)cnt[pos]++;
	sort(a.begin(), a.end());
	vector<ll> idxs;
	idxs.push_back(0);
	for (ll i = 1; i < n; i++) {
		if (a[i] != a[i - 1])idxs.push_back(i);
	}
	vector<ll> b(m);
	for (auto &pos : b)cin >> pos;
	sort(b.begin(), b.end());
	auto ck = [&](ll mid)->bool{
		ll L = idxs[mid];
		ll need = n - L;
		priority_queue<ll> jus;
		for (ll i = 0; i < m; i++)jus.push(b[i]);
		while (L < n && jus.size()) {
			if (jus.top() >= need) {
				ll val = jus.top();
				jus.pop();
				val -= need;
				if (val != 0 && need != (n - L)) {
					jus.push(val);
				}
				need = 0 ;
				ll fuck = a[L];
				while (L < n && a[L] == fuck)L++;
				need = n - L;
			}
			else {
				need -= jus.top();
				jus.pop();
			}
		}
		return L == n;
	};
	// debug(idxs);
	// debug(ck(2));
	// debug(ck(1));
	ll ans = 0 ;
	ll low = 0 , high = idxs.size() - 1;
	while (low <= high) {
		ll mid = (low + high) >> 1;
		if (ck(mid)) {
			ans = n - idxs[mid];
			// low = mid + 1;
			high = mid - 1;
		} else low = mid + 1;
	}
	cout << ans << '\n';
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