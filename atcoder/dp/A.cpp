#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxm = 1e9+7;

int main() {
	int n;
	cin >> n;
	vector <int> h(n);
	for(int i=0;i<n;i++) {
		cin >> h[i];
	}
	vector <int> dp(n,mxm);
	dp[0] = 0;
	for(int j=0;j<n-1;j++) {
		int i1 = j+1;
		int i2 = j+2;
		if(i1 < n) {
			dp[i1] = min(dp[i1],dp[j] + abs(h[j] - h[i1]));
		}
		if(i2 < n) {
			dp[i2] = min(dp[i2],dp[j] + abs(h[j] - h[i2]));
		}
	}
	cout << dp[n-1] << '\n';
	return 0;
}