#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int answer = 1000 * (n/500) + ((n%500)/5)*5;
	cout << answer << '\n';
	return 0;
}