#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll a,b;
		cin >> a >> b;
		if(a > b) {
			swap(a,b);
		}
		if(b % a == 0) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
}