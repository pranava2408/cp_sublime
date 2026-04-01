#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;


void solve() {
  ll n;cin>>n;
  ll winners = n, losers =0 ;
  ll answer = 0;
  while(winners>=2||losers>=2){
  	answer += (winners>>1);
  	answer += (losers>>1);
  	losers -=(losers>>1);
  	losers += (winners>>1);
  	winners -=(winners>>1);
  }	answer++;
  cout<<answer<<endl;
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