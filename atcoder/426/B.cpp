#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve() {
	string str;cin>>str;
	vector<ll> cnt(26,0);
	for(auto pos:str)cnt[pos-'a']++;
	for(ll i=0;i<26;i++){
		if(cnt[i]==1){
			cout<<(char)('a'+i)<<endl;
			return;
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