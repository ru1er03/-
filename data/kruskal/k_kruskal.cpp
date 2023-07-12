/*k本の木での全域木探索*/
long long kruskal(vector<tuple<int,int,int>> &g,int n, int k){ //g<重さ,点1,点2>はsort済,辺数n
  long long res = 0; //最小全域木の重み
  dsu d(n); //Union Find
  int num=0; //追加した辺の本数

  for(auto e:g){
    int w = get<0>(e);
    int x = get<1>(e), y = get<2>(e);

    if(num == n - k){ //k本なのでn-k本追加で終了
      break;
    }

    if(!d.same(x, y)){ //非連結なら重さ追加
      d.merge(x,y);
      res += w;
      num++;
    }
  }
  
  return res;
}