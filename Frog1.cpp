#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
typedef long long ll;
#define INGZzz  	cin.tie(0);cin.sync_with_stdio(0);
const int N = 1e5+5;
int n,dp[N],h[N];
int main()
{
    INGZzz
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    dp[2] = abs(h[1] - h[2]);
    for (int i = 3; i <= n; i++) {
        int op1 = dp[i - 1] + abs(h[i] - h[i - 1]);
        int op2 = dp[i - 2] + abs(h[i] - h[i - 2]);
        dp[i] = min(op1, op2);
    }
    cout << dp[n];

    return 0;
}