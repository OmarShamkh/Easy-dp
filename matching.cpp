#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define INGZzz  cin.tie(0);cin.sync_with_stdio(0);
const int N = 21 , Mod = 1e9 + 7;
bool a[N][N] ;
int n , mem[N][1<<N];

int sum(int x, int y){
    return (x+y) % Mod;
}

int dp(int idx, int msk){
    if(idx == n) return 1;
    int &ret = mem[idx][msk];
    if(~ret) return ret;
    ret = 0;
    for(int w = 0; w<n; w++){
        if((msk & (1 << w)) == 0 && a[idx][w]){
            ret = sum(ret , dp(idx+1 , msk | (1 << w)));  
        }
    }
    return ret;
}
int main()
{
    INGZzz
    memset(mem, -1, sizeof mem);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    cout << dp(0,0) << "\n";
    return 0;
}