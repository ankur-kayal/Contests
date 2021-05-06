#include <iostream>
#include <vector>
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace std;
using Modint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;
void chmin(int& a, int b){ if(a > b) a = b; }

int main(){
    string S, T;
    cin >> S >> T;
    reverse(T.begin(), T.end());
    const int N = S.size(), M = T.size();
    vector<Modint> s1(N), s2(N), t1(N), t2(N);
    for(int i = 0; i < N; i++) (S[i] == '0' ? s1 : s2)[i] = 1;
    for(int i = 0; i < M; i++) (T[i] == '0' ? t1 : t2)[i] = 1;
    s1 = atcoder::convolution(s1, t2);
    s2 = atcoder::convolution(s2, t1);
    int ans = INF;
    for(int i = M - 1; i < N; i++) chmin(ans, s1[i].val() + s2[i].val());
    cout << ans << endl;
}
