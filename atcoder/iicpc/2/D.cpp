/*
    Author: Rahul Bhuiya
*/
#include<bits/stdc++.h>
using namespace std; 
#define vll            vector<ll>
#define pll            pair<ll,ll>
#define fr(i,s,n)      for(ll i=s;i<n;i++)
#define MOD            1000000007
#define MOD1           998244353
#define endl           "\n"
#define pb             push_back
#define ppb            pop_back
#define mp             make_pair
#define ff             first
#define ss             second
#define set_bits       __builtin_popcountll
#define leading        __builtin_clzll
#define trailing       __builtin_ctzll
#define all(x)         (x).begin(),(x).end()
#define read(a)        for(auto &e:a) cin>>e;
#define put(a)         for(auto &e:a) cout<<e<<" ";
typedef long long            ll;
typedef unsigned long long  ull;
typedef long double         lld;
typedef __int128            ell;
bool isprime(ll n)  {if(n==1) return false; for(int i=2;i*i<=n;i++){if(n%i==0)return false;}return true;}
ll gcd(ll a,ll b)  {if (b>a) {return gcd(b,a);} if(b==0) {return a;} return gcd(b,a%b);}
ll expo(ll a,ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a,ll b,ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
ll mminv(ll a,ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll combination(ll n,ll r, ll m, ll* fact) {ll val1 = fact[n]; ll val2 = mminvprime(fact[r], m); ll val3 = mminvprime(fact[n - r], m); return ((val1 * val2) % m * val3) % m;}
ll mod_add(ll a, ll b, ll m) {a = ((a % m) + m) % m; b = ((b % m) + m) % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = ((a % m) + m) % m; b = ((b % m) + m) % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = ((a % m) + m) % m; b = ((b % m) + m) % m; return (((a - b) % m)+m) % m;}
ll mod_div(ll a, ll b, ll m) {a = ((a % m) + m) % m; b = ((b % m) + m) % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void solve(){
    ll n,m; cin>>n>>m;
    vector<ll> v(n); read(v);
    // vector<vector<ll>> adj(n+1);
    vector<ll> adj[n];
    fr(i,0,m){
        ll a,b; cin>>a>>b;
        if(v[a-1]<v[b-1])
        adj[a].pb(b);
        else if(v[a-1]>v[b-1])
        adj[b].pb(a);
    }
    vector<ll> mx(n,0);
    fr(i,0,n){
        for(auto e:adj[i+1]){
            mx[i]=max((v[e-1]-v[i]),mx[i]);
        }
    }
    // debug(mx)
    ll ans=1;
    map<ll,ll> val[n+1];
    fr(i,1,n+1){
        val[i][1]=0;
    }
    vector<pair<ll,ll>> temp;
    fr(i,0,n){
        temp.pb({v[i],i+1});
    }
    sort(all(temp));
    for(auto [a,b]:temp){
        for(auto it:val[b]){
            ans=max(ans,it.ff);
            for(auto e:adj[b]){
                if(v[e-1]-a>it.ss){
                    if(v[e-1]-a<mx[e-1]){
                        if(val[e].find(it.ff+1)==val[e].end()){
                            val[e][it.ff+1]=v[e-1]-a;
                        }
                        else val[e][it.ff+1]=min(v[e-1]-a,val[e][it.ff+1]);
                    }
                    else{
                        ans=max(ans,it.ff+1);
                    }
                }
            }
        }
        adj[b].clear();
        val[b].clear();
    }
    cout<<ans;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto begin = chrono::high_resolution_clock::now();
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    freopen("Error1.txt", "w", stderr);
#endif
    int t=1;
    // cin>>t;
    fr(i,0,t){
        solve();
        cout<<endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr<< "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
