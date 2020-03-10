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
		vector <int> arr(n);
		for(int i=0;i<n;i++) {
			cin >> arr[i];
		}
		
		sort(begin(arr),end(arr),greater <int> ());
		for(int i=0;i<n;i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
}