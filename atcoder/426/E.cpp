#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
// using ld = long double;

const ld eps = 1e-12;

template<typename F>
ll binary_search(ll low , ll high , F ck) {
	ll answer = -1;
	while (low <= high) {
		ll mid = (low + high) >> 1;
		if (ck(mid)) {
			answer = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return answer;
}

template<typename F>
ld binary_search_real(ld l, ld r, F ck, int iter = 100) {
	for (ll i = 0; i < iter; i++) {
		ld x = (l + r) / 2;
		(ck(x) ? l : r) = x;
	}
	return (l + r) / 2;
}

template<typename F>
ld ternary_search(ld l, ld r, F f) {
	ld ep = 1e-12;
	while (r - l > ep) {
		ld m1 = l + (r - l) / 3;
		ld m2 = r - (r - l) / 3;
		ld f1 = f(m1);
		ld f2 = f(m2);
		if (f1 > f2)
			l = m1;
		else
			r = m2;
	}
	return l;
}

template<typename F>
ll ternary_search_integers(ll l, ll r, F f) {
	ll lo = l - 1, hi = r;
	while (hi - lo > 1) {
		ll mid = (hi + lo) >> 1;
		if (f(mid) > f(mid + 1))
			hi = mid;
		else
			lo = mid;
	} return lo + 1 ;
}

void solve() {
	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	ll x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
	auto dis = [&](ld a, ld b , ld c, ld d)->ld{
		return sqrtl((a - c) * (a - c) + (b - d) * (b - d));
	};
	ld d1 = dis(x1, y1, x2, y2);
	ld d2 =  dis(x3, y3, x4, y4);
	ld low = 0 , high = max(d1, d2);
	ld sin1 = (ld)(y2 - y1) / d1;
	ld cos1 = (ld)(x2 - x1) / d1;

	ld sin2 = (ld)(y4 - y3) / d2;
	ld cos2 = (ld)(x4 - x3) / d2;
	auto f = [&](ld mid)->ld{
		// return 9;
		ld xn = (ld)x1 + mid * cos1;
		ld yn = (ld)y1 + mid * sin1;

		if (mid >= d1)xn = x2, yn = y2;
		ld xn1 = (ld)x3 + mid * cos2;
		ld yn1 = (ld)y3 + mid * sin2;
		if (mid >= d2)xn1 = x4, yn1 = y4;
		return dis(xn, yn, xn1, yn1);
	};
	ld answer = ternary_search(low , min(d1, d2) , f);
	// cerr << answer << endl;
	// cout << fixed << setprecision(10) << f(answer) << endl;
	ld answer1 = ternary_search(min(d1, d2), max(d1, d2), f);
	cout << fixed << setprecision(10) << min(f(answer), f(answer1)) << endl;
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