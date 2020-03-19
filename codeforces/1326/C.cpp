#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int mod = 998244353;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    unordered_map <int,int> pos;
    for(int i=0,temp;i<n;i++) {
    	cin >> temp;
    	pos[temp] = i + 1;
    }
    vector <int> count;
    ll answer = 1;
    int p = 0;
    ll maxval = 0;
    while(k--) {
    	int ele = n-p;
    	count.pb(pos[ele]);
    	p++;
    	maxval+=ele;
    }
    sort(count.begin(),count.end());
    for(int i=0;i<count.size()-1;i++) {
    	answer = (answer * (count[i+1] - count[i]))%mod;
    }
    cout << maxval << " " << answer << '\n';
}