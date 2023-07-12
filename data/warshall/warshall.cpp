/*O(N^3)*/
void warshall(vector<vector<long long>> &g, int n){ //g(経路なしは1e18)、対角成分は0
    for(int i = 0; i < n; i++){ //経由地
        for(int j = 0; j < n; j++){ //始点
            for(int k = 0; k < n; k++){ //終点
                if(g[j][i]!=1e18 && g[i][k]!=1e18){ //経路ない時次へ
                    chmin(g[j][k], g[j][i] + g[i][k]); //自身か、j→i,i→kの小さいほう入れる
                }
            }
        }
    }
}