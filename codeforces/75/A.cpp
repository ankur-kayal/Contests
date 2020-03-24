#include <bits/stdc++.h>
using namespace std;

int transform(int a) {
	int res = 0;
	int mul = 1;
	while(a > 0) {
		int rem = a % 10;
		if(rem != 0) {
			res = res + mul * rem;
			mul = mul * 10;
		}
		a/=10;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b;
	cin >> a >> b;
	// cout << a + b << '\n';
	// cout << transform(transform(a) + transform(b)) << '\n';
	cout << ((transform(a + b) == transform(a) + transform(b)) ? "YES" : "NO") << '\n';
	return 0;
}