/*マップ(関数version)縦横*/
int h, w, n;
int ans = 0;

void bfs(vector<vector<char>> &g,P goal,int sx,int sy){
  Graph route(h,vector<int>(w,-1));
  route[sx][sy]=0;//スタート地点sx,sy
  queue<P> q;
  q.push(make_pair(sx,sy));

  while(!q.empty()){
    int x=q.front().first,y=q.front().second;
    q.pop();
    if(x-1>=0&&g[x-1][y]!='#'&&route[x-1][y]==-1){//上
      q.push(make_pair(x-1,y));
      route[x-1][y]=route[x][y]+1;
    }
    if(x+1<h&&g[x+1][y]!='#'&&route[x+1][y]==-1){//下
      q.push(make_pair(x+1,y));
      route[x+1][y]=route[x][y]+1;
    }
    if(y+1<w&&g[x][y+1]!='#'&&route[x][y+1]==-1){//右
      q.push(make_pair(x,y+1));
      route[x][y+1]=route[x][y]+1;
    }
    if(y-1>=0&&g[x][y-1]!='#'&&route[x][y-1]==-1){//左
      q.push(make_pair(x,y-1));
      route[x][y-1]=route[x][y]+1;
    }
    if(route[goal.first][goal.second]!=-1){//goalに到達したら終わり
      ans+=route[goal.first][goal.second];
      return;
    }
  }
}