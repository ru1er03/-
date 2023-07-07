/*マップ(縦横)*///0からの距離
  Graph ans(h,vector<int>(w,-1));
  ans[sx][sy]=0;//スタート地点sx,sy
  queue<P> q;
  q.push(make_pair(sx,sy));

  while(!q.empty()){
    int x=q.front().first,y=q.front().second;
    q.pop();
    if(x-1>=0&&g[x-1][y]=='.'&&ans[x-1][y]==-1){//上
      q.push(make_pair(x-1,y));
      ans[x-1][y]=ans[x][y]+1;
    }
    if(x+1<h&&g[x+1][y]=='.'&&ans[x+1][y]==-1){//下
      q.push(make_pair(x+1,y));
      ans[x+1][y]=ans[x][y]+1;
    }
    if(y+1<w&&g[x][y+1]=='.'&&ans[x][y+1]==-1){//右
      q.push(make_pair(x,y+1));
      ans[x][y+1]=ans[x][y]+1;
    }
    if(y-1>=0&&g[x][y-1]=='.'&&ans[x][y-1]==-1){//左
      q.push(make_pair(x,y-1));
      ans[x][y-1]=ans[x][y]+1;
    }
  }