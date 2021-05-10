#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> positions(n, vector<int>(k));
    for(int i=0;i<k;i++) {
        for(int j=0;j<n;j++) {
            int u;
            cin >> u;
            --u;
            positions[u][i] = j;
        }
    }

    vector<vector<int>> adj(n);

    vector<int> indeg(n, 0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i == j) continue;
            bool ok = true;
            for(int kk=0;kk<k;kk++) {
                if(positions[i][kk] < positions[j][kk]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                adj[i].push_back(j);
                indeg[j]++;
            }
        }
    }


    // LCS now is finding the longest path in the acyclic graph, do with tree dp
    vector<int> path_length(n, 1);
    vector<int> q;
    for(int i=0;i<n;i++) {
        if(indeg[i] == 0) {
            q.push_back(i);
        }
    }

    for(int i=0;i<q.size();i++) {
        int u = q[i];
        for(auto child: adj[u]) {
            path_length[child] = max(path_length[child], path_length[u] + 1);
            indeg[child]--;
            if(indeg[child] == 0) {
                q.push_back(child);
            }
        }
    }

    cout << *max_element(path_length.begin(), path_length.end());
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}