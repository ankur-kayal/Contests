#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M = 998244353, mxM=2e5;
int n,m;
ll iv[mxM+1];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	iv[1] = 1;
	for(int i=2; i <= mxM;++i) {
		iv[i] = M -M/i*iv[M%i]%M;
	}
	cin >> n >> m;
	ll ans = 1;
	for(int i=0;i<n-2;++i) 
		ans = ans*2%M;
	for(int i=1;i<=m;i++) 
		ans = ans*i%M;
	for(int i=1;i<=n-1;++i)
		ans = ans*iv[i]%M;
	for(int i=1;i<=m-(n-1);++i)
		ans = ans*iv[i]%M;
	ans = ans*(n-2)%M;
	ans=ans*iv[2]%M;
	cout << ans << '\n';

}