/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;

void dijkstra(const Graph &G, int s, vector<long long> &dis) {//webサイトのやつ
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

void dijkstra(vector<vector<pair<int,int>>> &g,int start,vector<ll> &res){ //自作

    set<pair<int,int>> s; //<距離, 座標>
    s.insert({0,start}); //最初の要素追加
    res[sgart] = 0;

    while(!s.empty()){
        auto p = *begin(s); //最短距離取得
        int d = p.first, x = p.second;
        s.erase(p);

        for(int i = 0, i < g[x].size(); i++){ //隣を検索
            if(res[g[x][i].first] > d+g[x][i].second){ //更新があればinsert 
                res[g[x][i].first] = d+g[x][i].second;
                s.insert({res[g[x][i].first], g[x][i].first});
            }
        }
    }
}