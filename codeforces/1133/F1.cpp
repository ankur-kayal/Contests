#include <bits/stdc++.h>
using namespace std;

const int mxM = 2e5+10;

vector <int> adj[mxM];
vector <int> vis(mxM);

int main() {
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int md = 1;
	int mdn = 1;
	for(int i=1;i<=n;i++) {
		int td = adj[i].size();
		if(td > md) {
			mdn = i;
			md = td;
		}
		vis[i] = 0;
	}
	queue <int> q;
	q.push(mdn);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 1;
		for(auto u: adj[v]) {
			if(vis[u] == 0) {
				vis[u] = 1;
				cout << v << " " << u << '\n';
				q.push(u);
			}
		}
	}
}