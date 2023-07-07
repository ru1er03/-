void dijkstra(vector<vector<pair<int,int>>> &g, vector<ll> &res, int start){ //startからの距離(重さ付き)

    set<pair<ll,int>> s; //<距離, 座標>
    s.insert({0,start}); //最初の要素追加
    res[start] = 0;

    while(!s.empty()){
        auto p = *begin(s); //最短距離取得
        ll d = p.first;
        int x = p.second;
        s.erase(p);

        for(int i = 0; i < g[x].size(); i++){ //隣を検索
            if(res[g[x][i].first] > d+g[x][i].second){ //更新があればinsert 
                res[g[x][i].first] = d+g[x][i].second;
                s.insert({res[g[x][i].first], g[x][i].first});
            }
        }
    }
}