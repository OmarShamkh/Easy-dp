#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define INGZzz  cin.tie(0);cin.sync_with_stdio(0);
const int INF = 0x3f3f3f3f;
const int N = 1e2+10 , M = 1e5+10;
ll n,W , v[N] , w[N], dp[N][M];
/*
ll dp(int idx, int val){
    if(val <= 0) return 0;
    if(idx == n) return INF;
    ll &ret = mem[idx][val];
    if(~ret) return ret;
    ret = INF;
    ret = min(dp(idx+1, val-v[idx])+w[idx], dp(idx+1 , val));
    return ret;
}*/
int main()
{
    INGZzz
    //memset(dp,-1,sizeof dp);
    cin >> n >> W;
    for(int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    int max_Val = 1e5;
    for(int i=0; i<n; i++){
        for(int j=0; j<=max_Val; j++){
            if(j >= v[i]) dp[i+1][j] = min(dp[i][j] , dp[i][j-v[i]]+w[i]);
            else dp[i+1][j] = dp[i][j];
        }
    }
    for(int i=max_Val; i>=0; i--){
        if(dp[n][i] <= W) return cout << i << "\n",0;
    }
    return 0;
}