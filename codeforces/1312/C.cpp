#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n,k;
		cin >> n >> k;
		vector <ll> arr(n);
		vector <ll> c(60);
		for(int i=0;i<n;i++) {
			cin >> arr[i];
		}
		for(int i=0;i<n;i++) {
			ll ele = arr[i];
			int j=0;
			while(ele > 0) {
				c[j] = c[j] + (ele % k);
				ele = ele / k ;
				j++;
			}
		}
		bool exists = true;
		for(int i=0;i<60;i++) {
			if(c[i] > 1) {
				exists = false;
				break;
			}
		}
		cout << (exists ? "YES" : "NO") << '\n';
	}
}