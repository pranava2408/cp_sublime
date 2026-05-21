/*
  Author: Pranava
  scholar id -> 2312177
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

#define pranav                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define be begin()
#define en end()
#define rbe rbegin()
#define ren rend()
#define asort(vec) sort(vec.begin(), vec.end())
#define dsort(vec) sort(vec.begin(), vec.end(), greater<long long>())
#define vll vector<long long>
#define vpll vector<pair<long long, long long>>
#define pll pair<long long, long long>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define rep(var, start, end) for (long long var = start; var < end; var++)
#define ff first
#define ss second
#define vi vector<int>
#define apriority \
  priority_queue<long long, vector<long long>, greater<long long>>
#define dpriority priority_queue<long long>
#define input(vec, n)                 \
  for (long long i = 0; i < n; i++) { \
    cin >> vec[i];                    \
  }
#define lcm(a, b) ((a * b) / (__gcd(a, b)))
#define lpow(a, b) (ll) pow(a, b)
#define minel *min_element
#define maxel *max_element

// Debugging helpers
#define debug(x) cerr << #x << " = " << (x) << endl;

vector<bool> primesieve(ll n) {
    vector<bool> ans(n + 1, true);
    ans[0] = false;
    ans[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (ans[i]) {
            for (ll j = i * i; j <= n; j += i) {
                ans[j] = false;
            }
        }
    }
    return ans;
}

vector<ll> spf(ll n) {
    vector<ll> ret(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        ret[i] = i;
    }

    for (ll i = 2; i * i <= n; i++) {
        if (ret[i] == i) {
            for (ll j = i * i; j <= n; j += i) {
                if (ret[j] == j) {
                    ret[j] = i;
                }
            }
        }
    }
    return ret;
}

void factorisation(ll n) {
    vll factors = spf(n);
    while (n != 1) {
        cout << factors[n] << ' ';
        n /= factors[n];
    }
    cout << endl;
}

void print(vll a) {
    for (auto pos : a) {
        cout << pos << ' ';
    }
}

/****TEMPLATE ENDS*******/

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
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
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }

    const Type& operator()() const { return value; }
    template <typename U>
    explicit operator U() const {
        return static_cast<U>(value);
    }
    constexpr static Type mod() { return T::value; }

    Modular& operator+=(const Modular& other) {
        value += other.value;
        value -= (value >= mod()) * mod();
        return *this;
    }
    Modular& operator-=(const Modular& other) {
        value -= other.value;
        value += (value < 0) * mod();
        return *this;
    }
    template <typename U>
    Modular& operator+=(const U& other) {
        return *this += Modular(other);
    }
    template <typename U>
    Modular& operator-=(const U& other) {
        return *this -= Modular(other);
    }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    Modular operator++(int) {
        Modular result(*this);
        *this += 1;
        return result;
    }
    Modular operator--(int) {
        Modular result(*this);
        *this -= 1;
        return result;
    }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value,
             Modular>::type &
    operator*=(const Modular& rhs) {
        value = normalize(static_cast<int64_t>(value) *
                          static_cast<int64_t>(rhs.value));
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value,
             Modular>::type &
    operator*=(const Modular& rhs) {
        int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if < !is_integral<typename Modular<U>::Type>::value,
             Modular >::type &
    operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular& operator/=(const Modular& other) {
        return *this *= Modular(inverse(other.value, mod()));
    }

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

template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
    return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
    return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
    return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
    return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
    return lhs.value < rhs.value;
}

template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
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

constexpr int md = 1e9;
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

ll noOperation = -1;

Mint P = inverse(27, md);
ll n, q, x, y, z;
struct nd {
    Mint answer = 0;
    Mint d_3[3] = {0};
    Mint d_2[3] = {0};
    Mint cnt[3] = {0};
    Mint d[3] = {0};
    ll operation = noOperation;
};



nd merge(nd left, nd right) {
    nd cur;
    cur.answer = left.answer + right.answer;
    for (ll i = 0; i < 3; i++) {
        cur.d_3[i] += left.d_3[i] + right.d_3[i];
        cur.d_2[i] += left.d_2[i] + right.d_2[i];
        cur.d[i] += left.d[i] + right.d[i];
        cur.cnt[i] += left.cnt[i] + right.cnt[i];
    }

    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 3; j++) {
            ll parity = (i + j) % 3;

            Mint val = left.cnt[i] * right.cnt[j];

            Mint D = (left.d[i] * right.cnt[j]) + (right.d[j] * left.cnt[i]);

            Mint D_2 =
                (2 * left.d[i] * right.d[j]) +
                ((left.d_2[i] * right.cnt[j]) + (right.d_2[j] * left.cnt[i]));
            Mint D_3 = (left.d_3[i] * right.cnt[j]) + (right.d_3[j] * left.cnt[i]) +
                       (3 * left.d_2[i] * right.d[j]) +
                       (3 * left.d[i] * right.d_2[j]);

            cur.cnt[parity] += val;
            cur.d[parity] += D;
            cur.d_2[parity] += D_2;
            cur.d_3[parity] += D_3;

            if (parity == 0)
                cur.answer += D_3 * P;
            else if (parity == 1)
                cur.answer += (D_3 - 3 * D + 2 * val) * P;
            else
                cur.answer += (D_3 - 3 * D - 2 * val) * P;
        }
    }

    return cur;
}


struct Node {
    ll cnt = 0;
    ll operation = noOperation;
};



vector<nd> initialize;
vector<Mint> p2;

Node temp;
struct Stree {
    vector<Node> segtree;
    vll arr;
    void init(ll n, vll A) {
        arr = A;
        segtree.resize(4 * (n + 1));
    }

    Node merge(Node left, Node right) {
        Node cur;
        cur.cnt = left.cnt + right.cnt;
        return cur;
    }
    void apply(Node &cur, ll op, ll len) {
        if (op == noOperation)return;
        if (op == x || op == y || op == z) {
            cur.cnt = 0;
        } else {
            cur.cnt = len;
        }
        cur.operation = op;
    }
    void propagate(ll tl, ll tr, ll node) {
        if (tl >= tr)return;
        ll mid = (tl + tr) >> 1;
        ll left = 2 * node ;
        ll right = 2 * node + 1;
        apply(segtree[left], segtree[node].operation, mid - tl + 1);
        apply(segtree[right], segtree[node].operation, tr - mid);
        segtree[node].operation = noOperation;
    }


    void build(ll l, ll r, ll node) {
        if (l > r) return;
        if (l == r) {
            if (arr[l] == x || arr[l] == y || arr[l] == z) {

            }
            else segtree[node].cnt = 1;

            return;
        }
        ll mid = (l + r) >> 1;
        build(l, mid, 2 * node);
        build(mid + 1, r, 2 * node + 1);
        segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);

        // cerr<<l<<' '<<r<<' '<<segtree[node].answer<<endl;
    }

    Node query(ll l, ll r, ll tl, ll tr, ll node) {
        propagate(tl, tr, node);
        if (l > r || tl > tr || tl > r || tr < l) return temp;

        if (tl >= l && tr <= r) {
            return segtree[node];
        }

        ll mid = (tl + tr) >> 1;
        return merge(query(l, r, tl, mid, 2 * node),
                     query(l, r, mid + 1, tr, 2 * node + 1));
    }

    // void update(ll l, ll r, ll tl, ll tr, ll node) {
    //   propagate(tl, tr, node);

    //   ll mid = (tl + tr) >> 1;
    //   if (tl > tr || tr < l || tl > l) return;

    //   if (tl == tr) {
    //     arr[l] = r;
    //     segtree[node] = temp;
    //     Mint score = 1LL - ((arr[l] == x) + (arr[l] == y) + (arr[l] == z));

    //     ll abso = abs(score);

    //     abso %= 3;
    //     segtree[node].answer = 0;
    //     segtree[node].d[abso] = score;
    //     segtree[node].d_2[abso] = score * score;
    //     segtree[node].d_3[abso] = score * score * score;

    //     segtree[node].cnt[abso] = 1;
    //     return;
    //   }

    //   update(l, r, tl, mid, 2 * node);
    //   update(l, r, mid + 1, tr, 2 * node + 1);

    //   segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
    // }
    void update(ll l, ll r, ll type, ll tl, ll tr, ll node) {
        propagate(tl, tr, node);
        ll mid = (tl + tr) >> 1;
        if (tl > tr || tr < l || tl > r || l > r) return;

        if (tl >= l && tr <= r) {
            // cout << tl << " " << tr << " " << type << endl;
            // we apply update
            apply(segtree[node], type, tr - tl + 1);
            return;
        }
        update(l, r, type, tl, mid, 2 * node);
        update(l, r, type, mid + 1, tr, 2 * node + 1);

        segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
    }
};

void solve() {
    cin >> n >> q >> x >> y >> z;

    vll A(n + 1);

    for (ll i = 1; i <= n; i++) {
        char te;
        cin >> te;
        A[i] = (te - '0');
    }

    // for (auto pos : A)cerr << pos << " ";
    Stree st;
    st.init(n, A);

    st.build(1, n, 1);
    // return;
    while (q--) {
        ll type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            Node just = st.query(l, r, 1, n, 1);

            cout << initialize[just.cnt].answer * p2[r - l + 1 - just.cnt] << endl;

        } else {
            ll x; cin >> x;
            st.update(l, r, x, 1, n, 1);
        }
    }
}

int main() {
    freopen("F:\\cp_sublime\\input.txt", "r", stdin);
    freopen("F:\\cp_sublime\\output.txt", "w", stdout);
    freopen("F:\\cp_sublime\\debug.txt", "w", stderr);

    // cerr<<"here";
    Stree tem;
    initialize.resize(200001);
    nd cur;
    ll score = 1;
    ll abso = 1;
    cur.answer = 0;
    cur.d[abso] = score;
    cur.d_2[abso] = score * score;
    cur.d_3[abso] = score * score * score;
    cur.cnt[abso] = 1;
    initialize[1] = cur;
    for (ll i = 2; i <= 200000; i++) {
        initialize[i] = merge(initialize[i - 1], cur);
        // cout<<initialize[i].answer<<endl;
    }
    p2.push_back(1);
    Mint va = Mint(2);
    while (p2.size() <= 200000) {
        p2.push_back(p2.back() * va);
    }
    pranav;
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
