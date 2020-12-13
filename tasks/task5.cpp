#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iterator>
#include<queue>
#include<map>

using namespace std;

const int N = 2e5 + 10;
const long long inf = 1e18;
vector < pair < int , int > > g[N];

bool used[N];
long long dp[N];

void calc(int v , int n) {
    if(v == n) {
        used[v] = 1;
        dp[v] = 0;
        return;
    }
    
    used[v] = 1;
    dp[v] = -inf;
    
    for(int i = 0 ; i < g[v].size(); ++i){
        if(!used[g[v][i].first])
            calc(g[v][i].first, n);
        dp[v] = max(dp[v], dp[g[v][i].first] + g[v][i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , m;
    cin >> n >> m;

    for(int i = 0 ; i < m; ++i){
        int u , v , w;
        cin >> u >> v >> w;
        --u , --v;
        g[u].push_back({v , w});
    }
    calc(0 , n-1);
    cout << dp[0];
    return 0;
}