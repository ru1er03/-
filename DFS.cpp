int h, w;

void dfs(Graph &g,vector<vector<bool>> &his,int x,int y,int res){//足場の数res
  if(x<0||y<0||x>h-1||y>w-1||his[x][y]==1||g[x][y]==0){
    return;
  }else{
    his[x][y]=1;
  }
  dfs(g,his,x+1,y,res+1);
  dfs(g,his,x,y+1,res+1);
  dfs(g,his,x-1,y,res+1);
  dfs(g,his,x,y-1,res+1);
  his[x][y]=0;
  ans=max(ans,res);
}