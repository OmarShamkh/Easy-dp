#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define INGZzz  cin.tie(0);cin.sync_with_stdio(0);
const int N = 3e3+10;
string s,t;
int n ,m, dp[N][N];

int solve(int idx1 , int idx2){
    if(idx1 == n || idx2 == m) return 0;
    
    int &ret = dp[idx1][idx2];
    if(~ret) return ret;
    if(s[idx1] == t[idx2]){
        return ret = solve(idx1 +1 , idx2 +1) +1;
    }
    ret = max(solve(idx1 + 1 , idx2) , solve(idx1 , idx2 + 1));
    return ret;
}
void print(int idx1 , int idx2){
    if(idx1 == n || idx2 == m) return;
    
    if(s[idx1] == t[idx2]){
        cout << s[idx1];
        print(idx1 +1 , idx2 +1);   
        return;
    }
    if(solve(idx1 + 1 , idx2) > solve(idx1 , idx2 + 1)){
        print(idx1+1 , idx2);
    }
    else print(idx1 , idx2 +1 );
}

int main()
{
    INGZzz
    memset(dp,-1,sizeof dp);
    cin >> s >> t;
    n = s.size() , m = t.size();
    solve(0,0);
    print(0,0);
    
    return 0;
}