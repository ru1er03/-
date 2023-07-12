/*逆ワーシャル*/
long long warshall(vector<vector<long long>> &g, int n){ //g(経路なしは1e18)、対角成分は0
  long long res = 0; //本来の辺の合計

    for(int i = 0; i < n; i++){ //始点
        for(int j = i + 1; j < n; j++){ //終点
          bool ex = 0;
            for(int k = 0; k < n; k++){ //経由地
              if(i == k || j == k)continue; //自己ループなし
                  
                  if(g[i][j] == g[i][k] + g[k][j]){ //既にあるので
                    ex = 1;
                  }else if(g[i][j] > g[i][k] + g[k][j]){ //たどりつけない
                    return -1;
                  }else{} //スルー
            }
            if(!ex){ //まだ存在しないなら追加
              res += g[i][j];
            }
        }
    }

    return res; 
}