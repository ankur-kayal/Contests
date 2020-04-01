 #include <bits/stdc++.h>
using namespace std;
const long long inf=1e10;
long long n, w, V=0, dp[100005], wi[105], vi[105];
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin >> n >> w;
	for(int i=1;i<=n;i++){
		cin >> wi[i] >> vi[i];
		V+=vi[i];
	}
	for(int i=0;i<=V;i++){
		dp[i]=inf;
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=V;j>=vi[i];j--){
			dp[j]=min(dp[j], dp[j-vi[i]]+wi[i]);
		}
	}
	for(int i=V;i>=0;i--){
		if(dp[i]<=w){
			cout << i << endl;
			return 0;
		}
	}
}
