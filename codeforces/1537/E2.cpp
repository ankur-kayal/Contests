#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

// Also known as "extended KMP"
template<typename T>
vector<int> z_algorithm(const T &pattern) {
    // Z[i] = for the suffix [i, n) of pattern, the longest prefix that is also a prefix of pattern.
    int n = int(pattern.size());
    vector<int> Z(n, 0);
    Z[0] = n;
    int loc = 1;
 
    for (int i = 1; i < n; i++) {
        if (i < loc + Z[loc])
            Z[i] = min(Z[i - loc], loc + Z[loc] - i);
 
        while (i + Z[i] < n && pattern[Z[i]] == pattern[i + Z[i]])
            Z[i]++;
 
        // Find the location with the furthest-reaching umbrella.
        if (i + Z[i] > loc + Z[loc])
            loc = i;
    }
 
    return Z;
}

void run_cases() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    vector<int> Z = z_algorithm(S);

    int x = 1;
    for(int end = 2; end <= N; end++) {
        int y = end - x;
        // Let x_str = S.substr(0, x) and y_str = S.substr(x, y). 
        // Determine whether y_str + x_str < x_str + y_str.
        if (Z[x] < y) {
            if (S[x + Z[x]] < S[Z[x]])
                x = end;
        } else if (Z[y] < x) {
            if (S[Z[y]] < S[y + Z[y]])
                x = end;
        }
    }
    string pattern = S.substr(0, x);
    string ans = "";
    while(ans.length() < K) {
        ans += pattern;
    }
    while(ans.length() > K) {
        ans.pop_back();
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}