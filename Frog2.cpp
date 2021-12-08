#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
typedef long long ll;
#define INGZzz  	cin.tie(0);cin.sync_with_stdio(0);
const int N = 1e5+5;
int n,k,dp[N],h[N];
int main()
{
    INGZzz
    
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> h[i];
    for(int i=2; i<=n; i++){
        int mi = 1e9;
        for(int j=i-1; j>=max(1,i-k); j--){
            mi = min(mi, dp[j]+abs(h[j]-h[i]));
        }
        dp[i] = mi;
    }
    
    cout << dp[n];
    return 0;
}