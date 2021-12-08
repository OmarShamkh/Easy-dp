#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define inf (int)1e12+5
const int N = 1e2+9, M = 100009;
 
ll n, W, w[M] , v[M], mem[N][M];
ll dp(int idx, int weight){
    
    if(weight < 0) return -1e18;
    if(idx == n) return 0;

    if(mem[idx][weight] !=-1) return mem[idx][weight];
    ll ans = max(dp(idx+1 , weight-w[idx])+v[idx] , dp(idx+1 , weight));

    return mem[idx][weight] = ans;
    
}
 
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(mem, -1, sizeof mem);
    cin >> n >> W;
    for(int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    cout << dp(0,W) << "\n";
    return 0;
}