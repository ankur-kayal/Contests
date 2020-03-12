#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for(int i=0;i<n;i++) {
			cin >> a[i];
		}
		int m= *max_element(a.begin(),a.end());
		bool exists = true;
		for(int i=0;i<n;i++) {
			if((m - a[i]) % 2 != 0){
				
			exists = false;
			break;
			}
		}
		cout << (exists ? "YES" : "NO") << '\n';
	}
	
}