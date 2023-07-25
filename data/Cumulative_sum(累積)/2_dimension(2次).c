--包除原理--
sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1]
長方形2個分足して、被ったとこを引く


--高速メビウス変換--

まずは、ただの配列用意
1 1 1
1 1 1
1 1 1
次は、次元ごとに累積を出す

for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
        sum[i][j] += sum[i-1][j];
    }
}
for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
        sum[i][j] += sum[i][j-1];
    }
}