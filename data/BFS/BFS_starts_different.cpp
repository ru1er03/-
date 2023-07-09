/*多数始点、それぞれ距離違う(木)*/
void bfs(Graph &g, set<P> &s, vector<bool> &his){//set<距離, 座標>、his(通ったか)

  while(!s.empty()){
    int y = (*rbegin(s)).first; //距離最大から
    int x = (*rbegin(s)).second;
    s.erase({y,x});

    if(his[x] == 1){//先に通ってるならスルー
      continue;
    }else{
      his[x] = 1;
    }

    if(y == 0){//距離0もスルー
      continue;
    }

    for(auto p : g[x]){ //次の場所に距離-1
      s.insert({y-1, p});
    }
  }
}