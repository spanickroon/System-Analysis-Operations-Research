#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iterator>
#include<queue>

using namespace std;

const long long inf = 1e18;
const int N = 1e5 + 10;
vector < pair < int , int > > g[N];

long long dist[N];
bool used[N];

void setIO() {
    ios_base::sync_with_stdio(0) , cin.tie(0), cout.tie(0);
    freopen("input.txt" , "rt", stdin);
    freopen("output.txt" , "wt", stdout);
}

void input_graph(int m) {
    for(int i = 0; i < m; ++i){
        int u , v , w;
        cin >> u >> v >> w;
        --u , --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}

long long dijkstra(int s , int t) {
    fill(dist , dist + N , inf);
    dist[s] = 0;
    priority_queue < pair < int , int > > dj;
    dj.push({-dist[s] , s});
    while(!dj.empty()){
        pair < int , int > head = dj.top();
        
        dj.pop();
        
        if(used[head.second])
            continue;
        
        used[head.second] = 1;
        
        for(int i = 0 ; i < g[head.second].size(); ++i){
            if(dist[g[head.second][i].first] > dist[head.second] + g[head.second][i].second){
                dist[g[head.second][i].first] = dist[head.second] + g[head.second][i].second;
                dj.push({-dist[g[head.second][i].first] , g[head.second][i].first});
            }
        }
    }
    return dist[t];
}

int main() {
    setIO();
    int n , m;
    cin >> n >> m;
    input_graph(m);
    cout << dijkstra(0 , n-1);

    return 0;
}