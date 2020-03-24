#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	int hcf = __gcd(a,b);
	vector <int> factors;
	for(int i=1;i*i<=hcf;i++) {
		if(hcf % i == 0) {
			if(hcf / i == i) {
				factors.push_back(i);
			}
			else {
				factors.push_back(i);
				factors.push_back(hcf/i);
			}
		}
	}
	// for(auto i: factors) {
	// 	cout << i << " ";
	// }
	// cout << '\n';
	sort(begin(factors),end(factors));
	int n;
	cin >> n;
	while(n--) {
		int low,high;
		cin >> low >> high;
		int ans = -1;
		for(auto i: factors) {
			if(low <= i and i <= high) {
				ans = i;
			}
			else if(i > high) {
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}