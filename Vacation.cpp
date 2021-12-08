#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define INGZzz  cin.tie(0);cin.sync_with_stdio(0);
const int N = 1e5+10;
int n, a[N], b[N], c[N] , dp[N][3];

int main()
{
    INGZzz
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i] >> b[i] >> c[i];
    for(int i=1; i<=n; i++){
        dp[i][0] = a[i] + max(dp[i-1][1] , dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0] , dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][1] , dp[i-1][0]);
    }
    cout << max({dp[n][0] , dp[n][1] , dp[n][2]});
    return 0;
}