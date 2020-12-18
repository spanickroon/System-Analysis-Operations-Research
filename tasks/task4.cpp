#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iterator>
#include<queue>
#include<map>

using namespace std;


const int N = 17 , inf = 1e9;
int g[N][N];
int dp[1<<N][N][N];

int main(){

    int n , m , k;
    cin >> n >> m >> k;

    vector < string > name(n);

    map < string , int > ind;
    for(int i = 0 ; i < n; ++i){
        cin >> name[i];
        ind[name[i]] = i;
    }
    for(int i = 0 ; i < N; ++i)
        fill(g[i] , g[i] + N , inf);

    for(int i = 0 ; i < m; ++i){
        string from , to;
        int len;
        cin >> from >> to >> len;
        g[ind[from]][ind[to]] = min(g[ind[from]][ind[to]] , len);
        g[ind[to]][ind[from]] = min(g[ind[from]][ind[to]] , len);
    }

    for(int i = 0 ; i < (1<<N); ++i)
        for(int j = 0 ; j < N; ++j)
            for(int k = 0 ;  k < N; ++k)
                dp[i][j][k] = inf;

    for(int i = 0 ; i < n; ++i)
        dp[(1<<i)][i][0] = 0;

    for(int msk = 0 ; msk < (1<<n); ++msk){
        for(int lst = 0 ; lst < n; ++lst){
            if(((1<<lst)&msk) == 0)
                continue;
            for(int tel = 0 ; tel <= k; ++tel){

                for(int nxt = 0; nxt < n; ++nxt){
                    if((1<<nxt)&msk)
                        continue;
                    if(g[lst][nxt] == inf)
                        continue;
                    dp[msk|(1<<nxt)][nxt][tel] = min(dp[msk|(1<<nxt)][nxt][tel], dp[msk][lst][tel] + g[lst][nxt]);
                }

                if(tel + 1 <= k){
                    for(int nxt = 0 ; nxt < n; ++nxt){
                        if((1<<nxt)&msk)
                            continue;
                        dp[msk|(1<<nxt)][nxt][tel+1] = min(dp[msk|(1<<nxt)][nxt][tel+1], dp[msk][lst][tel]);
                    }
                }
            }
        }
    }

    int ans = inf;
    for(int lst = 0 ; lst < n; ++lst)
        for(int j = 0 ; j <= k; ++j)
            ans = min(ans , dp[(1<<n)-1][lst][j]);
    cout << (ans == inf ? -1 : ans);
    return 0;
}