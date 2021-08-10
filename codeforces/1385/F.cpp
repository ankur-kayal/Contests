#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;

    vector<unordered_set<int>> adj(N);
    vector<int> degree(N);
    vector<int> count_leafs(N);
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        degree[u]++;
        degree[v]++;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    deque<int> q;
    for(int i = 0; i < N; i++) {
        if(degree[i] == 1) {
            q.push_back(i);
        }
    }

    vector<vector<int>> leafs(N);

    int ans = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop_front();
        if(adj[x].empty()) {
            continue;
        }
        int parent = *adj[x].begin();
        
        leafs[parent].push_back(x);
        if(leafs[parent].size() >= K) {
            ans++;
            for(int i = 0; i < K; i++) {
                int leaf = leafs[parent].back();
                leafs[parent].pop_back();
                adj[parent].erase(leaf);
                degree[parent]--;
            }
            if(degree[parent] == 1) {
                q.push_back(parent);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}