#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    ll pos;
    while(t--) {
    	int n,k;
    	cin >> n >> k;
    	for(ll i=1;i<n;i++) {
    		int val = i * (i + 1) / 2;
    		if(val >= k) {
    			pos = i;
    			break;
    		}
    	}
    
	    ll p1 = pos + 1;
	    ll p2 = k - pos * (pos - 1) / 2;
	    
	    string s = "";
	    for(int i=1;i<=n;i++) {
	    	if(i == p1 or i == p2) {
	    		s = 'b' + s;
	    	}
	    	else {
	    		s = 'a' + s;
	    	}
	    }
	    cout << s << '\n';
    }
}