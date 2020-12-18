#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;


void setIO(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    freopen("input.txt", "rt" , stdin);
    freopen("output.txt" , "wt" , stdout);
}

const int N = 610;
const int SMALLINF = 1e9;
const long long BIGINF = 1e18;
int flow[N][N] , cap[N][N], p[N] , used[N], S , T;
long long cost[N][N] , Poten[N] ,  d[N];

void add_edge(int u , int v , int capci , int price){
    cap[u][v] = capci;
    cap[v][u] = 0;
    cost[u][v] = price;
    cost[v][u] = -price;
}

void Potential(){
    fill(Poten , Poten + N , BIGINF);
    Poten[S] = 0;
    bool found = 1;
    while(found){
        found  = 0;
        for(int i = 0 ;  i < N; ++i){
            if(Poten[i] == BIGINF)
                continue;
            for(int j = 0 ;  j < N; ++j){
                if(cap[i][j] - flow[i][j] > 0 && Poten[j] > Poten[i] + cost[i][j])
                    Poten[j] = Poten[i] + cost[i][j] , found = 1;
            }
        }

    }
}

void Djkstra(){
    fill(d , d + N , BIGINF);
    fill(p , p + N , -1);
    fill(used , used + N , 0);
    d[S] = 0;
    for(int i =  0 ; i < N; ++i){
        int u = -1 , mn = SMALLINF;
        for(int j = 0 ;  j < N; ++j){
            if(!used[j]){
                if(d[j] < mn){
                    mn = d[j];
                    u = j;
                }
            }
        }
        if(mn == SMALLINF)
            break;
        used[u] = 1;
        for(int j = 0 ; j < N; ++j){
            if(Poten[j] == BIGINF)
              continue;
            if(cap[u][j] - flow[u][j] <= 0)
                continue;

            if(cap[u][j] - flow[u][j] > 0 && d[j] > d[u] + Poten[u] - Poten[j] + cost[u][j]){
                d[j] = d[u] + cost[u][j] + Poten[u] - Poten[j];
                p[j] = u;
            }
        }
    }
}

long long maxflow(){

    long long price = 0;

    Potential();
    Djkstra();
    while(true){
        if(d[T] == BIGINF)
            break;
        int u = T , nxt = -1;
        int mn = SMALLINF;
        while(u != -1){
            if(nxt != -1){
                mn = min(mn , cap[u][nxt] - flow[u][nxt]);
            }
            nxt = u;
            u = p[u];
        }
        u = T , nxt = -1;
        while(u != -1){
            if(nxt != -1){
                flow[u][nxt] += mn;
                flow[nxt][u] -= mn;
                price += cost[u][nxt] * mn;
            }
            nxt = u;
            u = p[u];
        }
        Djkstra();
        for(int i = 0 ; i< N; ++i)
            if(Poten[i] != BIGINF)
                Poten[i] += d[i];

    }
    return price;
}

int main(){
    setIO();
    int n , m;
    cin >> n >> m;
    S = n + m + 1 , T = n + m + 2;
    for(int i = 0 ; i < n; ++i){
        int a;
        cin >> a;
        add_edge(S , i , a , 0);
    }
    for(int i = 0 ; i < m; ++i){
        int b;
        cin >> b;
        add_edge(i + n , T , b , 0);
    }
    for(int i = 0 ; i < n; ++i)
    for(int j = 0 ; j < m; ++j){
        int cost;
        cin >> cost;
        add_edge(i , j + n , SMALLINF , cost);
    }
    cout << maxflow();
    return 0;
}