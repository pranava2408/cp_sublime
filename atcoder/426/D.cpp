#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve() {
	ll n;cin>>n;
	string str ;cin>>str;
	// cerr<<str<<endl;
	ll prev = 0;
	vector<ll> ct(2,0);
	for(auto pos:str)
		ct[pos-'0']++;
	// cerr<<ct[0]
	vector<ll> cur(2,0);
	ll answer = 1e18;
	for(ll i=0;i<n;i++){
		ct[str[i]-'0']--;
		if(i!=0 && str[i]!=str[i-1]){
			for(ll j=prev;j<i;j++)cur[str[j]-'0']++;
			prev = i;
		}
		ll val = str[i]-'0';
		answer  = min(answer,(cur[val]+ct[val])*2 + cur[!val]+ct[!val]);
		// cout<<answer<<endl;
		// cur[str[i]-'a']++;
	}cout<<answer<<endl;
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