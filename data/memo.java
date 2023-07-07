/*
Shift+Alt+F //整列

--変数--
int//-2147483648～2147483647(10桁)
long long//	-9223372036854775808～9223372036854775807(19桁)
unsigned long long int//0～18446744073709551615(20桁)
(int)'A'//65
(char)65//A
isupper(文字)//大文字か判定
islower(文字)//小文字か判定
isdigit(文字)//数字か判定
const int n;//(bit数で使える)
sqrt()//intになる？
round()//四捨五入

--演算子--(計算の優先度が低い)
(条件式)?(真の時の式):(偽の式)//if分岐の書き換え
(条件式1)?(真の式):(真の式)?(真):(偽)//多数分岐

--文字列--
string s1;//文字列
getline(cin, s1);//空白無視で1行入力
名前.size()//文字列長
名前.at(i)//i文字目
s1.erase(0,n)//最初からn文字削除
s1==s2//比較可
s1>s2//辞書順
s1+s2//結合

--配列--
vector<型> 名前;//配列宣言
vector<型> 名前(要素数)//配列宣言(初期化完了)
vector<型> 名前(要素数,初期値)//初期値指定
s1.resize(要素数);//要素数再設定
s1.resize(要素数,vector<型>(要素数));//要素数再設定
s1.push_back(要素)//末尾に追加(O(n))
s1.emplace_back()//上と同じ
count(s1.begin(),s1.end(),値)//値の個数
s1.pop_back()//末尾を削除
s1==s2//比較可
s1 = vector<型>(要素数, 初期値);//上書き可
vector<vector<型>> 変数名(要素数1,vector<型>(要素数2,初期値))//多次元配列
s1.at(i).at(j)
s1.size()//縦の大きさ
s1.at(0).size()//横の大きさ
auto itr=lower_bound(s1.begin(),s1.end(),値)//値以上で最小値(s1:sort済み)(*itrで出力)
auto itr=upper_bound(s1.begin(),s1.end(),値)//値より上で最小(s1:sort済み)
distance(s1.begin(),itr)//距離(配列1スタート)
binary_search(s1.begin(),s1.end(),値)//値があるか調べる(s1:sort済み)
max_element(s1.begin(),s1,end()) //範囲のmaxイテレータを返す(*付ければ値で返せる)
sort(配列変数.begin(), 配列変数.end());
bool compare(string & s1, string& s2) {return s1.size() < s2.size();} //関数(sortの第三引数にcompareと入れる)

//
do {
  // 順列に対する処理
} while (next_permutation(配列変数.begin(), 配列変数.end()));//全列挙(sort先)
//
goto 名前;
名前://間の処理を飛ばす

--ビット演算--
---計算の優先度が低いの注意
& //両方1なら1
| //少なくとも一方
^ //一方のみ
~ //ビットを反転(1-0)
<< //左シフト(切り捨て,0埋め)
>> //右シフト(0埋め,切り捨て)
1<<k //2のk乗

bitset<ビット数> 変数名//全ビットが0で初期化
bitset<ビット数> 変数名(" ")
bitset<ビット数> 変数名(10進数)
変数.to_ulong()//整数へ
変数[位置]//アクセス
変数.set(位置,値)//値変更(位置は右から0)
変数.to_string()//文字列化
変数.set()//全て1に
変数.reset()//全て0に
変数.test(位置)//1か調べる(true/false)
変数.all()//全て1か調べる
変数.any()//1があるか調べる
変数.count()//1の個数
変数.flip()//全て反転
変数.flip(位置)//指定反転

--map--unordered_map(高速版)
map<key型,要素型> mp;//map初期化(初期値0)
mp[key] = 要素//代入
mp.at(key)//アクセス
mp.erase(key)//削除
mp.find(key)==mp.end()//存在確認(trueだとない)
mp.count(x)//存在確認
mp.size()
*begin()/*rbegin()
for(auto p:mp){
    p.second;//要素
  }

---priority_queue<型> 変数名;
mp.push(値)
mp.pop()//先頭削除
mp.front()//先頭アクセス
---priority_queue<型> 変数名;
mp.top()//最大

--set--/unordered_set(高速版)
set<型> 変数名;
変数.insert(値)//追加
変数.erase(値);//削除
変数.empty()// 空ならtrue
*begin(変数)//最小値取得
*rbegin(変数)//最大値取得
for (auto value : 変数名)//小さいものから(中ではvaluを使う)

--pair/tuple--ソート可(辞書順)
pair<型1,型2> 変数名
p.first//一つ目の値
p.second//二つ目の値
p=make_pair(値1, 値2)//作成
tie(分解後の変数1, 変数2,...)=変数名//分解,変数にignoreを入れて捨て
pair >> tuple//複数

--stack--//後から入れ、後ろから出す
stack<型> 変数名;
変数.push(値);
変数.top()//最後の値取得
変数.pop();
変数.empty()  // 空ならtrue

--deque--//前後どちらでも
deque<型> 変数名;
変数.push_back(値);// 末尾へ追加
変数.push_front(値);// 先頭への追加
変数.front()  // 先頭を取得
変数.back()   // 末尾を取得
変数.at(i)  // i番目を取得
変数.pop_front();  // 先頭の削除
変数.pop_back();   // 末尾の削除

--queue--//後ろから挿入、前から取り出す
que.front()//前取得
que.back()//後ろ取得
que.pop()//先頭削除
que.push()//後ろから挿入

--関数--
int name(int)//プロトタイプ宣言
min(a,b) max(a,b) swap(a,b)
sort(s1.begin(), s2.end());//小→大
stable_sort() //安定ソート(同じなら番号順)
reverse(s1.begen(), s2.end())

--for文--
continue;//次まで処理を飛ばす

--ポインタ--
型 *p;//以後p(住所),*p(中身)となる
int x; int *y; y=&x;//同じ値
vector<int>& p;//ポインタ渡し
p=nullptr//指す値なしにする
p=&n;
*p=2;//中身
int &b = a; // bは変数aの参照
関数名(&x)//アドレスを渡して書き換えてもらう

型 *ポインタ1 = new 型;        // 1つ分の領域を確保
型 *ポインタ2 = new 型(引数);   // 1つ分の領域を確保(コンストラクタに引数を渡す)
型 *ポインタ3 = new 型[n];     // 連続したn個分の領域を確保
delete ポインタ1;   //「new 型」や「new 型()」で確保したポインタの解放
delete[] ポインタ3; //「new 型[n]」で確保したポインタの解放

cout<<fixed<<setprecision(桁数)//小数点以下桁数
n*(n-1)/2　//combination(n,n-2)
pow(x,2) //累乗
*/

/*おまけ
#define PI 3.14159265359 //円周率使う時
sin(PI/2) //まんま

setw(文字数) //出力桁数
setfill(""); //指定文字で埋める(出力)

ofstream ofs("ファイル名前");　//ファイル
ofs << //書き込み(coutと一緒)
 */