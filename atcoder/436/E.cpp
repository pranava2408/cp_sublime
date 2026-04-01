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

// Template for modular arithmetic (modular addition, subtraction,
// multiplication)
const ll MOD = 1e9 + 7;
ll mod_add(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return (((a % m) - (b % m)) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }

// Function to perform modular exponentiation
ll mod_exp(ll base, ll exp, ll mod) {
  ll result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = mod_mul(result, base, mod);
    }
    base = mod_mul(base, base, mod);
    exp /= 2;
  }
  return result;
}

// Function to compute modular inverse
ll mod_inv(ll a, ll mod) { return mod_exp(a, mod - 2, mod); }

bool isPrime(long long n) {
  return n > 1 &&
         (n == 2 ||
          (n % 2 && none_of(begin(array<int, 5>{3, 5, 7, 11, 13}),
                            end(array<int, 5>{3, 5, 7, 11, 13}),
                            [n](int i) { return i * i <= n && n % i == 0; })));
}

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

pair<ll, ll> prod(ll val) {
  if ((val & 1) == 0) {
    return mp((val >> 1), (val >> 1));
  }
  return mp((val >> 1), ((val >> 1) + 1));
}

/****TEMPLATE ENDS*******/

struct Node {
  ll B = 0;
  ll L = 0;
  bool Bprefix = false;
  bool Bsuffix = false;

  ll W = 0;
  ll L1 = 0;

  ll operation = -1;
};

struct Stree {
  vector<Node> segtree;
  vll arr;
  void init(ll n, vll A) {
    arr = A;
    segtree.resize(4 * (n + 1));
  }

  Node merge(Node left, Node right) {
    Node cur;

    cur.B = left.B + right.B - (left.Bsuffix && right.Bprefix);
    cur.L = left.L + right.L;
    cur.W = left.W + right.W - ((!left.Bsuffix) && (!right.Bprefix));
    cur.L1 = left.L1 + right.L1;
    cur.Bprefix = left.Bprefix;
    cur.Bsuffix = right.Bsuffix;

    return cur;
  }

  void propagate(ll tl, ll tr, ll node) {
    if (tl >= tr || segtree[node].operation == -1) return;

    ll mid = (tl + tr) >> 1;

    ll left = (mid - tl + 1);

    ll right = (tr - mid);

    ll op = segtree[node].operation;
    if (op == 0) {
      // we set the entire thing white

      segtree[2 * node].operation = 0;
      segtree[2 * node + 1].operation = 0;

      segtree[2 * node].B = segtree[2 * node].L = segtree[2 * node].Bprefix =
          segtree[2 * node].Bsuffix = 0;
      segtree[2 * node].L1 = left;

      segtree[2 * node + 1].B = segtree[2 * node + 1].L =
          segtree[2 * node + 1].Bprefix = segtree[2 * node + 1].Bsuffix = 0;
      segtree[2 * node + 1].L1 = right;

      segtree[2 * node].W = 1;
      segtree[2 * node + 1].W = 1;

    }

    else {
      // we set everthing black here

      segtree[2 * node].operation = 1;
      segtree[2 * node + 1].operation = 1;

      segtree[2 * node].B = segtree[2 * node].Bprefix =
          segtree[2 * node].Bsuffix = 1;
      segtree[2 * node].L1 = 0;
      segtree[2 * node].L = left;

      segtree[2 * node + 1].B = segtree[2 * node + 1].Bprefix =
          segtree[2 * node + 1].Bsuffix = 1;
      segtree[2 * node + 1].L1 = 0;
      segtree[2 * node + 1].L = right;

      segtree[2 * node].W = 0;
      segtree[2 * node + 1].W = 0;
    }

    segtree[node].operation = -1;
  }

  void build(ll l, ll r, ll node) {
    if (l > r) return;
    if (l == r) {
      segtree[node].W = 1;
      return;
    }
    ll mid = (l + r) >> 1;
    build(l, mid, 2 * node);
    build(mid + 1, r, 2 * node + 1);
    segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
  }

  /*
  ll query(ll l, ll r, ll tl, ll tr, ll node)
  {
      propagate(tl,tr,node);
      if (l > r || tl > tr || tl > r || tr < l)
          return 0LL;



      if (tl >= l && tr <= r)
      {
          return segtree[node].sum;
      }

      ll mid = (tl + tr) >> 1;
      return query(l,r,tl,mid,2*node)+query(l,r,mid+1,tr,2*node+1);
  }

  */

  /*
  ll query(ll idx,ll tl, ll tr, ll node)
  {
      propagate(tl,tr,node);

      if(tl==tr){
              return segtree[node].sum;
      }

      ll mid=(tl+tr)>>1;
      if(idx<=mid){
              return query(idx,tl,mid,2*node);
      }

      return query(idx,mid+1,tr,2*node+1);

  }
  */

  void update(ll l, ll r, ll type, ll tl, ll tr, ll node) {
    propagate(tl, tr, node);
    ll mid = (tl + tr) >> 1;
    if (tl > tr || tr < l || tl > r || l > r) return;

    if (tl >= l && tr <= r) {
      if (type == 0) {
        segtree[node].operation = type;
        segtree[node].B = segtree[node].L = segtree[node].Bprefix =
            segtree[node].Bsuffix = 0;
        segtree[node].L1 = tr - tl + 1;
        segtree[node].W = 1;
      } else {
        segtree[node].operation = type;
        segtree[node].B = segtree[node].Bprefix = segtree[node].Bsuffix = 1;
        segtree[node].L = tr - tl + 1;
        segtree[node].L1 = 0;
        segtree[node].W = 0;
      }
      return;
    }

    update(l, r, type, tl, mid, 2 * node);
    update(l, r, type, mid + 1, tr, 2 * node + 1);

    segtree[node] = merge(segtree[2 * node], segtree[2 * node + 1]);
  }
};

struct DSU {
  vll parent;
  vll rank;
  ll N;

  void init(ll n) {
    N = n;
    parent.resize(n + 1);
    rank.resize(n + 1, 1);
    for (ll i = 1; i <= n; i++) {
      parent[i] = i;
    }
  }
  ll get(ll node) {
    return (parent[node] == node ? node : parent[node] = get(parent[node]));
  }

  bool unite(ll a, ll b) {
    ll A = get(a);
    ll B = get(b);
    if (rank[A] < rank[B]) swap(B, A);
    if (A == B) return false;

    parent[B] = A;
    rank[A] += rank[B];
    return true;
  }
};

void solve() {
  ll n;
  cin >> n;
  ll val = mod_exp(10, 100, n);
  // cout<<val<<endl;
  vll a(n);
  for (auto &pos : a) cin >> pos;

  for (ll i = 0; i < n; i++) {
    cout << (a[(i + val-1) % n]) << " ";
  }
  cout<<endl;
}

int main() {
  pranav ll tt = 1;  // cin>>tt;
  while (tt--) {
    solve();
  }
}
