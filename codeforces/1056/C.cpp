#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;

void solve() {
	ll n; cin >> n;

	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;

	// ll val = (n + 1) >> 1;
	// ll cnt = count(a.begin(), a.end(), val);
	// if (cnt == n) {
	// 	cout << 2 << endl;
	// 	return;
	// }

	ll looking = (n + 1) >> 1;
	ll ct = count(a.begin(), a.end(), looking);
	if (n & 1) {
		if (ct == n) {
			cout << 2 << endl;
			return;
		}
	}
	else {
		// ll looking = n
		ll other  = looking + 1;
		ll cnt = count(a.begin(), a.end(), other);

		if(ct==n||cnt==n){
			cout<<1<<endl;
			return;
		}
	}


	// ll left = 0;
	// ll right =0 ;
	vector<ll> answer(n, -1);
	ll prev = 0;
	for (ll i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			answer[i] = 0;
			answer[i - 1] = 0;
			for (ll j = i - 2; j >= prev; j--) {
				answer[j] = (!answer[j + 1]);
			}
			prev = i + 1;
		}
		else if (a[i] < a[i - 1]) {
			answer[i] = 1;
			answer[i - 1] = 1;
			for (ll j = i - 2; j >= prev; j--) {
				answer[j] = (!answer[j + 1]);
			}
			prev = i + 1;
		}
		else if (answer[i - 1] != -1)answer[i] = !answer[i - 1], prev = i + 1;
	}
	if (prev != n) {
		cout << 0 << endl;
		return;
	}
	ll tot = count(answer.begin(), answer.end(), 1);
	// for (auto pos : answer) {
	// 	cout << pos << ' ';
	// } cout << endl;
	ll left = 0 ;
	for (ll i = 0; i < n; i++) {
		if (i != 0) {
			left += answer[i - 1];
		}
		ll right = tot - left - answer[i];

		ll shouldBe = i - left + 1 + right;
		if (shouldBe != a[i]) {
			// cerr << shouldBe << endl;
			// cerr << i << endl;
			cout << 0 << endl;
			return;
		}
	}
	cout << 1 << endl;
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