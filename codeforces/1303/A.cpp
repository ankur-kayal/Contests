#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	string s;
	while(t--) {
		cin >> s;
		int answer = 0;
		int count = 0;
		int flag = 0;
		for(int i=0;i<s.size();i++) {
			if(s[i] == '1') {
				flag = 1;
				answer += count;
				count = 0;
			}
			if(s[i] == '0' and flag == 1) {
				count++;
			}
		}
		cout << answer << '\n';
	}
	return 0;
}