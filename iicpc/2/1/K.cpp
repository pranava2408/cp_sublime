#include <bits/stdc++.h>


#define ll long long
#define ld long double
using namespace std;

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
	ll n , m; cin >> n >> m;
	// if (n == 1 || m == 1) {
	// 	cout << Mint(n * m) << endl;
	// 	return;
	// }
	// ll have = 2 * n + 2 * m - 4;
	// vector<ll> level;
	// ll N = n , M = m;
	// while (have >= 1 && M >= 0 && N >= 0) {
	// 	level.push_back(have);
	// 	// have -= 7;
	// 	N -= 2, M -= 2;
	// 	// cerr<<N<<" "<<M<<endl;
	// 	if (N == 1 || M == 1) {
	// 		have = N * M;
	// 	}
	// 	else have = 2 * N + 2 * M - 4;
	// }
	// // for(auto pos:level){
	// // 	cout<<pos<<" ";
	// // }
	// // cout<<endl;
	// Mint answer = 0;
	// ll tot = level.size();
	// vector<ll> prefix(tot + 1, 0);
	// for (ll i = 0; i < tot; i++) {
	// 	prefix[i + 1] = prefix[i] + level[i];
	// }
	// vector<vector<Mint>> ways(tot + 1, vector<Mint>(tot + 1, Mint(0)));
	// ways[0][0] = Mint(1);
	// vector<vector<Mint>> dp_sum(tot + 1, vector<Mint>(tot + 1, Mint(0)));

	// for (ll i = 1; i <= tot; i++) {
	// 	for (ll j = 1; j <= i; j++) {
	// 		for (ll k = 1; k <= i; k++) {
	// 			ways[i][j] += ways[k - 1][j - 1];
	// 			dp_sum[i][j] += (ways[k - 1][j - 1] * Mint(prefix[i] - prefix[k - 1]) * Mint(j) + dp_sum[k - 1][j - 1]);
	// 		}
	// 		// cout<<ways[i][j]<<endl;
	// 	}
	// }

	// for (ll j = 1; j <= tot; j++)answer += dp_sum[tot][j];
	// // cout<<answer<<endl;

	// for (ll i = 1; i <= n - 2; i++) {
	// 	for (ll j = 1; j <= m - 2; j++) {
	// 		Mint tot = (n - 2 - i + 1) * (m - 2 - j + 1);
	// 		Mint cur = tot;
	// 		cur *= i;
	// 		cur *= j;
	// 		cur *= Mint(2);
	// 		Mint other = Mint(n * m);
	// 		other -= Mint(i * j);
	// 		cur += (other * tot);
	// 		answer += cur;
	// 	}
	// }
	// // cout<<answer<<endl;
	// // cout<<dp_sum[tot][2]<<endl;
	// if (tot >= 2)
	// 	answer -= dp_sum[tot][2];
	// cout << answer << endl;
	vector<vector<Mint>> cnt(n + 1, vector<Mint>(m + 1, Mint(0)));
	vector<vector<Mint>> cnt_sum(n + 1, vector<Mint>(m + 1, Mint(0)));
	vector<vector<Mint>> cnt_i(n + 1, vector<Mint>(m + 1, Mint(0)));
	vector<vector<Mint>> cnt_j(n + 1, vector<Mint>(m + 1, Mint(0)));
	vector<vector<Mint>> cnt_ij(n + 1, vector<Mint>(m + 1, Mint(0)));
	for (ll i = 1; i <= n; i++) {
		cnt[i][1] = 1;
		cnt[1][i] = 1;
	}
	cnt_i[1][1] = cnt_j[1][1] = cnt_ij[1][1] = cnt_sum[1][1] = Mint(1);

	for (ll i = 2; i <= n; i++) {
		cnt_sum[i][1] += cnt[i][1];
		cnt_sum[i][1] += cnt_sum[i - 1][1];
		cnt_sum[1][i] += cnt_sum[1][i - 1];
		cnt_sum[1][i] += cnt[1][i];
		// cnt_[i][j]

		cnt_i[i][1] += (cnt_i[i-1][1] + cnt_i[i][0]-cnt_i[i-1][0] + i*cnt[i][1]);
		cnt_i[i][1] += (cnt_i[i-1][1] + cnt_i[i][0]-cnt_i[i-1][0] + i*cnt[i][1]);
		cnt_i[i][1] += (cnt_i[i-1][1] + cnt_i[i][0]-cnt_i[i-1][0] + i*cnt[i][1]);
		cnt_i[i][1] += (cnt_i[i-1][1] + cnt_i[i][0]-cnt_i[i-1][0] + i*cnt[i][1]);
 
	}
	for (ll i = 2; i <= n; i++) {
		for (ll j = 2; j <= m; j++) {
			cnt[i][j] = Mint(1) + (i - 1) * (j - 1) * cnt_sum[i - 1][j - 1]
		}
	}
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