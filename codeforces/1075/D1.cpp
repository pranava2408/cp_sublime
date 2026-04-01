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


template <typename T>
T inverse(T a, T m) {
	T u = 0, v = 1;
	while (a != 0) {
		T t = m / a;
		m -= t * a; swap(a, m);
		u -= t * v; swap(u, v);
	}
	assert(m == 1);
	return u;
}

template <typename T>
class Modular {
public:
	using Type = typename decay<decltype(T::value)>::type;

	constexpr Modular() : value() {}
	template <typename U>
	Modular(const U& x) {
		value = normalize(x);
	}

	template <typename U>
	static Type normalize(const U& x) {
		Type v;
		if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if (v < 0) v += mod();
		return v;
	}

	const Type& operator()() const { return value; }
	template <typename U>
	explicit operator U() const { return static_cast<U>(value); }
	constexpr static Type mod() { return T::value; }

	Modular& operator+=(const Modular& other) { value += other.value; value -= (value >= mod()) * mod(); return *this; }
	Modular& operator-=(const Modular& other) { value -= other.value; value += (value < 0) * mod(); return *this; }
	template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
	template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
	Modular& operator++() { return *this += 1; }
	Modular& operator--() { return *this -= 1; }
	Modular operator++(int) { Modular result(*this); *this += 1; return result; }
	Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
	Modular operator-() const { return Modular(-value); }

	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type & operator*=(const Modular& rhs) {
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
		return *this;
	}
	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type & operator*=(const Modular& rhs) {
		int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template <typename U = T>
	typename enable_if < !is_integral<typename Modular<U>::Type>::value, Modular >::type & operator*=(const Modular& rhs) {
		value = normalize(value * rhs.value);
		return *this;
	}

	Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

	friend const Type& abs(const Modular& x) { return x.value; }

	template <typename U>
	friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

	template <typename U>
	friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

	template <typename V, typename U>
	friend V& operator>>(V& stream, Modular<U>& number);

private:
	Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
	assert(b >= 0);
	Modular<T> x = a, res = 1;
	U p = b;
	while (p > 0) {
		if (p & 1) res *= x;
		x *= x;
		p >>= 1;
	}
	return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
	return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
	return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
	return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
	typename common_type<typename Modular<T>::Type, int64_t>::type x;
	stream >> x;
	number.value = Modular<T>::normalize(x);
	return stream;
}

// using ModType = int;

// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;

constexpr int md = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

// vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);

// Mint C(int n, int k) {
//   if (k < 0 || k > n) {
//     return 0;
//   }
//   while ((int) fact.size() < n + 1) {
//     fact.push_back(fact.back() * (int) fact.size());
//     inv_fact.push_back(1 / fact.back());
//   }
//   return fact[n] * inv_fact[k] * inv_fact[n - k];
// }


void solve() {
	ll n , c; cin >> n >> c;

	string str; cin >> str;
	if (str[0] == '0' || str[n - 1] == '0') {
		cout << -1 << "\n";
		return;
	}
	vector<Mint> dp(n + 1, 0);
	vector<ll> other(n + 1, 0);
	dp[1] = 2;
	other[1] = 2 % c;
	for (ll i = 2; i <= n - 1; i++) {

		ll val = (str[i - 1] == '0');
		bool ck = str[i - 1] == '?';
		if (val == 0 && (!ck || (ck && i != 2))) {
			dp[i] = dp[i - 1] * Mint(2);
			other[i] = (other[i - 1] * 2) % c;
		} else {
			dp[i] = dp[i - 1] * Mint(i - 1);
			other[i] = (other[i - 1] * ((i - 1) % c)) % c;
		}
	}

	if (other[n - 1] == 0) {
		vector<Mint> dp1(n + 1, 0);
		vector<ll> other1(n + 1, 0);

		ll cnt = 0;
		ll C = c;
		while (C % 2 == 0) {
			cnt++;
			C >>= 1;
		}


		ll have = 1;
		for (ll i = 2; i <= n - 1; i++) {
			if (str[i - 1] == '?')continue;
			ll val = (str[i - 1] == '0');
			if (val == 1) {
				have ++;
			} else {
				// dp[i] = dp[i - 1] * Mint(i - 1);
				// other[i] = (other[i - 1] * ((i - 1) % c)) % c;
				ll temp = i - 1;
				while (temp % 2 == 0) {
					have ++;
					temp >>= 1;
				}
				// have += temp;
			}
		}

		ll can = cnt - have;

		for (ll i = 2; i <= n - 1; i++) {
			if (str[i - 1] == '?') {
				if ((i - 1) % 2 == 0) {
					str[i - 1] = '1';
					can --;
				}
			}
		}

		// cout << can << "\n";


		for (ll i = n - 1; i >= 2; i--) {
			if (str[i - 1] == '?') {
				if (can > 0 && i != 2) {
					str[i - 1] = '1';
				} else str[i - 1] = '0';
			}
		}
		// cout << str << "\n";

		dp1[1] = 2;
		other1[1] = 2 % c;
		for (ll i = 2; i <= n - 1; i++) {

			ll val = (str[i - 1] == '0');
			// cout<<val<<"\"
			if (val == 0) {
				dp1[i] = dp1[i - 1] * Mint(2);
				other1[i] = (other1[i - 1] * 2) % c;
			} else {
				dp1[i] = dp1[i - 1] * Mint(i - 1);
				other1[i] = (other1[i - 1] * ((i - 1) % c)) % c;
			}
		}
		if (other1[n - 1] == 0) {
			cout << -1 << "\n";
		} else cout << dp1[n - 1] << "\n";

		return;
	} cout << dp[n - 1] << "\n";
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