#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

const int mxm = 1e5 + 100;

vector <int> adj[mxm],vis(mxm),in(mxm),low(mxm);
int timer;
bool exists;
vector <pair<int,int>> path;

void dfs(int node, int par) {
	vis[node] = 1;
	in[node] = low[node] = timer++;
	
	for(auto child: adj[node]) {
		if(child == par) {
			continue;
		}
		if(vis[child] == 1) {
			
			low[node] = min(low[node],low[child]);
			
			if(in[node] > in[child]) {
				path.pb(mp(node,child));
			}
		}
		else {
			dfs(child, node);
			if(low[child] > in[node]) {
				exists = false;
				return;
			}
			path.pb(mp(node,child));
			low[node] = min(low[node], low[child]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,a,b;
	cin >> n >> m;
	path.clear();
	for(int i=1;i<=n;i++) {
		vis[i] = 0;
		in[i] = 0;
		low[i] = 0;
		adj[i].clear();
	}
	for(int i=0;i<m;i++) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	timer = 0;
	exists = true;
	dfs(1,-1);
	
	if(!exists) {
		cout << 0;
	}
	else {
		for(auto u: path) {
			cout << u.first << " " << u.second << '\n';
		}
	}
	return 0;
}