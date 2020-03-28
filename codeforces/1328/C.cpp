#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

void solve() {
	string a,b,s;
	int n;
	cin >> n >> s;
	a = "",b="";
	bool ok = true;
	for(int i=0;i<n;i++) {
		if(s[i] == '2') {
			if(ok) {
				a+='1';
				b+='1';
			}
			else {
				a+='2';
				b+='0';
			}
		}
		else if(s[i] == '1') {
			a+='1';
			b+='0';
			if(ok){
				ok = !ok;
				swap(a,b);
			}
		}
		else {
			a+='0';
			b+='0';
		}
	}
	cout << a << '\n' << b << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
}