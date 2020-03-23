#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxm = 1e9+7;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	vector <int> h(n);
	for(int i=0;i<n;i++) {
		cin >> h[i];
	}
	vector <int> dp(n,mxm);
	dp[0] = 0;
	for(int j=0;j<n-1;j++) {
		for(int l=1;l<=k;l++) {
			int i1 = j+l;
			if(i1 < n) {
				dp[i1] = min(dp[i1],dp[j] + abs(h[j] - h[i1]));
			}
		}
	}
	cout << dp[n-1] << '\n';
	return 0;
}