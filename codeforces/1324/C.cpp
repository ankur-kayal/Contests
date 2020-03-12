#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int last = -1;
		int answer = 1;
		int i;
		for(i=0;i<s.size();i++) {
			if(s[i] == 'R') {
				answer = max(answer,i-last);
				last = i;
			}
		}
		answer = max(answer,i-last);
		cout << answer << '\n';
	}
	
}