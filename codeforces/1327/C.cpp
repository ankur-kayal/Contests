#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	string s="";
	cin >> n >> m;
	for(int i=0;i<n-1;i++)
		s+='U';
	for(int i=0;i<m-1;i++)
		s+='L';
	for(int i=0;i<n;) {
		for(int j=0;j<m-1;j++) 
			s+='R';
		i++;
		if(i>=n) break;
		s+='D';
		for(int j=0;j<m-1;j++) 
			s+='L';
		++i;
		if(i>=n) break;
		s+='D';
	}
	cout << s.size() << '\n' << s;
}