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
		set <int> s;
		for(int i=0;i<n;i++) {
			int temp;
			cin >> temp;
			s.insert(temp);
		}
		cout << s.size() << '\n';
	} 
}