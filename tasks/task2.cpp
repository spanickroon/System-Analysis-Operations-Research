#include<bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define pb push_back
#define len(x) (int)(x).size()


using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
const int N = 1e4 + 10;
const int inf = 1e9;

void setIO() {
    ios_base::sync_with_stdio(0) , cin.tie(0), cout.tie(0);
    freopen("flow.in" , "rt", stdin);
    freopen("flow.out" , "wt", stdout);
}

struct edge {
    int u , v , flow , cap;
    edge(int u , int v , int cap) : u(u), v(v) , cap(cap){flow = 0;}
};

vector < edge > edges;
vector < int > g[N];
int d[N] , ptr[N], lst = 0, S , T;

void add_edge(int u , int v , int cap) {
    g[u].push_back(lst);
    g[v].push_back(lst+1);
    edges.push_back(edge{u , v, cap});
    edges.push_back(edge{v , u, 0});
    lst += 2;
}

bool path() {
    fill(d , d + N , inf);
    d[S] = 0;
    deque<int>BFS;
    BFS.pb(S);
    while(!BFS.empty()){
        int head = BFS.front();
        BFS.pop_front();
        
        for(int j = 0 ; j < g[head].size(); ++j){
            int e = g[head][j];
            if(d[edges[e].v] == inf && edges[e].cap - edges[e].flow > 0){
                d[edges[e].v] = d[head] + 1;
                BFS.push_back(edges[e].v);
            }
        }
    }
    if(d[T] == inf)
        return false;
    else
        return true;
}
int dfs(int v , int pushed) {
    if(v == T)
        return pushed;
    
    if(pushed == 0)
        return 0;
    
    for(int j = ptr[v]; j < g[v].size(); ++j){
        int e = g[v][j];
        if(d[edges[e].v] == d[v] + 1){
            int pushflow = dfs(edges[e].v , min(pushed, edges[e].cap - edges[e].flow));
            if(pushflow){
                edges[e].flow += pushflow;
                edges[e^1].flow  -= pushflow;
                return pushflow;
            }
        }
        ++ptr[v];
    }
    return 0;
}
int dinic() {
    fill(ptr , ptr + N , 0);
    int mxflow = 0;
    while(path()){
        fill(ptr , ptr + N , 0);
        int flow = dfs(S , inf);
        while(flow){
            mxflow += flow;
            flow = dfs(S , inf);
        }
    }
    return mxflow;
}

void input_network(int m) {
    for(int i = 0 ; i < m; ++i){
        int u , v , cap;
        cin >> u >> v >> cap;
        add_edge(u , v , cap);
    }
}

void out_edges() {
    for(int i = 0 ; i < edges.size(); ++i){
        if(edges[i].cap > 0)
            cout << edges[i].flow << '\n';
    }
}

int main() {
    setIO();
    int n , m;
    cin >> n >> m;
    cin >> S >> T;
    input_network(m);
    cout << dinic() << '\n';
    out_edges();
    return 0;
}