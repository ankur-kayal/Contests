#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		long long a,b;
		cin >> a >> b;
		if(a > b) {
			swap(a,b);
		}
		if((a+b) % 3 == 0 and 2 * a >= b) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}