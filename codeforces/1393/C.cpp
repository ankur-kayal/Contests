#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100009;
int cnt[MAXN];
vector<int> a;
int n;

bool check(int x) {
    for (int i = 1; i <= n; i ++) cnt[i] = 0;
    for (int i = 0; i < n; i ++) cnt[a[i]]++;

    set<pair<int, int>, greater<pair<int, int>>> ss; //use greater comparator to sort set in descending order
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] > 0) ss.insert({cnt[i], i});
    }

    vector<int> b;
    for (int i = 0; i < n; i ++) {
        if (i >= x && cnt[b[i - x]]) {
            ss.insert({cnt[b[i - x]], b[i - x]});
        }

        if (ss.empty()) return 0;
        b.push_back(ss.begin()->second);
        ss.erase(ss.begin());
        cnt[b.back()]--;
    }

    return 1;
}

signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int ttt;
	cin >> ttt;

	while (ttt--) {
        cin >> n;

        a.resize(n);
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
        }

        int l = 0, r = n;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (check(m)) {
                l = m;
            }

            else {
                r = m;
            }
        }

        cout << l - 1 << "\n";
	}

	return 0;
}