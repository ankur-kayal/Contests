#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	if(n == 1) {
    		cout << -1 << '\n';
    	}
    	else{
    		for(int i=0;i<n-1;i++) {
    			cout << 9;
    		}
    		cout << 8 << '\n';
    	}
    }
}