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
T inverse(T a, T m)
{
	T u = 0, v = 1;
	while (a != 0)
	{
		T t = m / a;
		m -= t * a;
		swap(a, m);
		u -= t * v;
		swap(u, v);
	}
	assert(m == 1);
	return u;
}

template <typename T>
class Modular
{
public:
	using Type = typename decay<decltype(T::value)>::type;

	constexpr Modular() : value() {}
	template <typename U>
	Modular(const U &x)
	{
		value = normalize(x);
	}

	template <typename U>
	static Type normalize(const U &x)
	{
		Type v;
		if (-mod() <= x && x < mod())
			v = static_cast<Type>(x);
		else
			v = static_cast<Type>(x % mod());
		if (v < 0)
			v += mod();
		return v;
	}

	const Type &operator()() const { return value; }
	template <typename U>
	explicit operator U() const { return static_cast<U>(value); }
	constexpr static Type mod() { return T::value; }

	Modular &operator+=(const Modular &other)
	{
		value += other.value;
		value -= (value >= mod()) * mod();
		return *this;
	}
	Modular &operator-=(const Modular &other)
	{
		value -= other.value;
		value += (value < 0) * mod();
		return *this;
	}
	template <typename U>
	Modular &operator+=(const U &other) { return *this += Modular(other); }
	template <typename U>
	Modular &operator-=(const U &other) { return *this -= Modular(other); }
	Modular &operator++() { return *this += 1; }
	Modular &operator--() { return *this -= 1; }
	Modular operator++(int)
	{
		Modular result(*this);
		*this += 1;
		return result;
	}
	Modular operator--(int)
	{
		Modular result(*this);
		*this -= 1;
		return result;
	}
	Modular operator-() const { return Modular(-value); }

	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type & operator*=(const Modular &rhs)
	{
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
		return *this;
	}
	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type & operator*=(const Modular &rhs)
	{
		int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template <typename U = T>
	typename enable_if < !is_integral<typename Modular<U>::Type>::value, Modular >::type & operator*=(const Modular &rhs)
	{
		value = normalize(value * rhs.value);
		return *this;
	}

	Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

	friend const Type &abs(const Modular &x) { return x.value; }

	template <typename U>
	friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

	template <typename U>
	friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

	template <typename V, typename U>
	friend V &operator>>(V &stream, Modular<U> &number);

private:
	Type value;
};

template <typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }
template <typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

template <typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template <typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

template <typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template <typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template <typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b)
{
	assert(b >= 0);
	Modular<T> x = a, res = 1;
	U p = b;
	while (p > 0)
	{
		if (p & 1)
			res *= x;
		x *= x;
		p >>= 1;
	}
	return res;
}

template <typename T>
bool IsZero(const Modular<T> &number)
{
	return number() == 0;
}

template <typename T>
string to_string(const Modular<T> &number)
{
	return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U &operator<<(U &stream, const Modular<T> &number)
{
	return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U &operator>>(U &stream, Modular<T> &number)
{
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

constexpr int md1 = 1e9 + 7;
constexpr int md2 = 1e9 + 9;
using Mint = Modular<std::integral_constant<decay<decltype(md1)>::type, md1>>;
using Mint1 = Modular<std::integral_constant<decay<decltype(md2)>::type, md2>>;

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

struct Hashing
{
	ll p = 31;
	vector<Mint> prefix = {}, inverse = {};
	Hashing(string str, ll P)
	{
		p = P;
		ll len = str.size();
		prefix.resize(len + 1, Mint(0));
		inverse = prefix;
		inverse[0] = Mint(1);
		Mint value = Mint(1);
		Mint inv = Mint(1) / Mint(p);
		Mint temp = Mint(1);
		for (int i = 1; i <= len; i++)
		{
			int val = str[i - 1] - '0' + 1;
			prefix[i] += (prefix[i - 1] + (val * value));
			value *= p;
			temp *= inv;
			inverse[i] = temp;
		}
	}
	Mint getHash(ll i, ll j)
	{
		Mint value = prefix[j] - prefix[i - 1];
		value *= inverse[i - 1];
		return value;
	}
};

struct Hashing1
{
	ll p = 31;
	vector<Mint1> prefix = {}, inverse = {};
	Hashing1(string str, ll P)
	{
		p = P;
		ll len = str.size();
		prefix.resize(len + 1, Mint1(0));
		inverse = prefix;
		inverse[0] = Mint1(1);
		Mint1 value = Mint1(1);
		Mint1 inv = Mint1(1) / Mint1(p);
		Mint1 temp = Mint1(1);
		for (int i = 1; i <= len; i++)
		{
			int val = str[i - 1] - '0' + 1;
			prefix[i] += (prefix[i - 1] + (val * value));
			value *= p;
			temp *= inv;
			inverse[i] = temp;
		}
	}
	Mint1 getHash(ll i, ll j)
	{
		Mint1 value = prefix[j] - prefix[i - 1];
		value *= inverse[i - 1];
		return value;
	}
};

struct CF_String_Hashing
{
	Hashing A, B;
	Hashing1 a, b;

	CF_String_Hashing(const string &str)
		: A(str, 31) // first hash with Mint, base = 31
		,
		  B(str, 257) // second hash with Mint, base = 257
		,
		  a(str, 31) // first hash with Mint1, base = 31
		,
		  b(str, 257) // second hash with Mint1, base = 257
	{
	}

	bool areSame(ll l1, ll r1, ll l2, ll r2)
	{
		return A.getHash(l1, r1) == A.getHash(l2, r2) && a.getHash(l1, r1) == a.getHash(l2, r2) &&

		       B.getHash(l1, r1) == B.getHash(l2, r2) && b.getHash(l1, r1) == b.getHash(l2, r2);
	}
};


void solve() {
	string str, str1;
	cin >> str >> str1;
	if (str == str1) {
		cout << 0 << endl;
		return;
	}
	ll n = str.size();
	str += str1;
	CF_String_Hashing cur(str);


	for (ll i = 0; i < n; i++) {
		if (cur.areSame(1, i + 1, 2 * n - i, 2 * n) && cur.areSame(i + 2, n, n + 1, 2 * n - i - 1)) {
			debug("did");
			string st1 = string(str.begin() + i + 1, str.begin() + n);
			st1 += string(str.begin(), str.begin() + i + 1);
			string st2 = string(str.begin() + n ,str.end());
			if(st1==st2){
				cout<<i+1<<endl;
				return;
			}
		}
	}cout<<-1<<endl;



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