/*木*///0からの距離
vector<int> ans(n,-1);
  ans[0]=0;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int x=q.front();//今見る数字
    q.pop();//見るから削除
    
    for(int i:g[x]){
      if(ans[i]==-1){//更新なかったら
        q.push(i);
        ans[i]=ans[x]+1;//(一つ前の次数)+1
      }
    }
  }