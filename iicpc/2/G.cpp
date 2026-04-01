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


constexpr int Z = 1000001;
int _trie[Z][26];
int _pre_cnt[Z];
int _cnt[Z];
int _tot;

struct Trie {
	Trie() {
		_tot = 0;
		new_node();
	}

	inline int new_node() {
		int x = _tot++;
		for (auto &c : _trie[x]) c = 0;
		_pre_cnt[x] = 0;
		return x;
	}

	inline void add(string &s, int f = 1, int ptr = 0) {
		for (auto &c : s) {
			int &p = _trie[ptr][c - 'a'];
			if (!p) p = new_node();
			ptr = p;
			_pre_cnt[ptr] += f;
		}
		_cnt[ptr] += f;
	}

	inline pair<int, int> count(string &s, int ptr = 0) {
		for (auto &c : s) {
			if (_pre_cnt[_trie[ptr][c - 'a']]) {
				ptr = _trie[ptr][c - 'a'];
				continue;
			}
			return {0, 0};
		}
		return {_cnt[ptr], ptr};
	}

	inline int pref_count(string &s, int ptr = 0) {
		for (auto &c : s) {
			if (_pre_cnt[_trie[ptr][c - 'a']]) {
				ptr = _trie[ptr][c - 'a'];
				continue;
			}
			return 0;
		}
		return _pre_cnt[ptr];
	}

	inline array<int, 2> lcp(string &s, int ptr = 0) {
		array<int, 2> res {};
		for (auto &c : s) {
			int &p = _trie[ptr][c - 'a'];
			if (!p) break;
			ptr = p;
			res[0] += 1;
		}
		res[1] = _pre_cnt[ptr];
		return res;
	}

	inline ll query(string &s, int ptr = 0, ll res = 0) {
		for (auto &c : s) {
			int &p = _trie[ptr][c - 'a'];
			if (!p) break;
			ptr = p;
			res += _pre_cnt[ptr];
		}
		return res;   // lcp_sum
	}

	inline void remove(string &s, int f = -1) {add(s, f);}
};


void solve() {
	ll n; cin >> n;
	vector<string> a(n);
	Trie cur ;
	for (auto &pos : a)cin >> pos;
	ll maxi = 500;
	// maxi --;
	// debug(maxi);
	for (auto &pos : a) {
		if (pos.size() <= maxi) {
		cur.add(pos);
		debug(cur.count(pos, 0));
		}
	}
	// string tem="c";
	// debug(cur.count(a.back()));

	ll answer = 0;
	for (auto &pos : a)
	{
		ll len = pos.size();
		if (len <= maxi) {
			debug(pos);
			bool ck = true;
			for (ll i = 0; i < len; i++) {
				int prev = 0;
				for (ll j = i; j < len; j++) {
					char cr = pos[j];
					string temp;
					temp += cr;

					auto ct = cur.count(temp, prev);

					if (ct.first == 0) {
						debug(ct);
						debug(temp, prev, i, j);
						ck = false;
						break;
					}
					prev = ct.second;

				}
				if (!ck) {
					break;
				}
			}
			if (ck) {
				answer = max(answer, len)
				         ;
			}
		}
	}
	cout << answer << endl;
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