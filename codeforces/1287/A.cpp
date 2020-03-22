#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
int main() {
    ll test,n,i,j,x,y,c;
    cin>>test;
    string s;
    while(test--)
    {
        cin>>n;
        cin>>s;
        ll answer = 0;
        ll start = 0;
        while(s[start] != 'A' and start < n) start++;
        int last = start;
        ll i;
        for(i=start+1;i<n;i++) {
        	if(s[i] == 'A') {
        		c = i - last - 1;
        		answer = max(answer,c);
        		last = i;
        	}
        }
        answer = max(answer,i-last-1);
        cout << answer << '\n';
    }
    return 0;
}