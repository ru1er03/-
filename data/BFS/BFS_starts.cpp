/*いくつかの頂点から、距離s以内をいじる*/
void bfs(vector<vector<int>> &g, vector<int> &c, int s)
{ //cで状況保持 {(-1,本人),(0,関係なし),(1,近く)}  /距離s
  
  queue<int> q;

  rep(i,c.size()){ //本人をすべて入れる
    if(c[i]==-1){
      q.push(i);
    }
  }

  while(!q.empty() && s>0){ //qが空か、距離sに達したら終わり
    s--;
    int q_s = q.size();//増加するから、先にsize入れる
    
    for(int i = 0; i < q_s; i++){
      int x = q.front();
      q.pop();

      for(auto j : g[x]){
        if(c[j] == 0){ //本人もしくは、探索済みならスルー
          c[j] = 1;
          q.push(j);
        }
      }
    }
  }
}