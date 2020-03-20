#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		bool exists = false;
		int n;
		cin >> n;
		vector <int> a(n);
		for(int i=0;i<n;i++) {
			cin >> a[i];
		}
		vector <int> b[2];
		for(int i=0;i<n;i++) {
			int index = a[i] % 2;
			// cout << index << '\n';
			b[index].push_back(i+1);
			if(b[0].size() == 1) {
				cout << 1 << '\n';
				for(auto v : b[0]) {
					cout << v << " ";
				}
				cout << '\n';
				exists = true;
				break;
			}
			if(b[1].size() == 2) {
				cout << 2 << '\n';
				for(auto v : b[1]) {
					cout << v << " ";
				}
				cout << '\n';
				exists = true;
				break;
			}
		}
		if(!exists) {
			cout << -1 << '\n';
		}
	}
	return 0;
}