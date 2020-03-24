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
		int lb = 0;
		int rb = factors.size() - 1;
		while(lb <= rb) {
			int mid = (lb + rb+1) / 2;
			if(low <= factors[mid] and factors[mid] <= high) {
				ans = factors[mid];
				lb = mid + 1;
			}
			else if(factors[mid] < low){
				lb = mid + 1;
			}
			else {
				rb = mid - 1;
			}
			// cout << lb << " " << rb << " " << mid  << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}