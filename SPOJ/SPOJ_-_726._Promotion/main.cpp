#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>

using namespace std;

const char infile[] = "input.in";
const char outfile[] = "output.out";

ifstream fin(infile);
ofstream fout(outfile);

const int MAXN = 100005;
const int oo = 0x3f3f3f3f;

typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;

const inline int min(const int &a, const int &b) { if( a > b ) return b;   return a; }
const inline int max(const int &a, const int &b) { if( a < b ) return b;   return a; }
const inline void Get_min(int &a, const int b)    { if( a > b ) a = b; }
const inline void Get_max(int &a, const int b)    { if( a < b ) a = b; }

int main() {
    cin.sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    #endif
    int N, M;
    multiset<int> S;
    cin >> N;
    long long Ans = 0;
    for(int i = 1 ; i <= N ; ++ i) {
        cin >> M;
        for(int j = 1 ; j <= M ; ++ j) {
            int x;
            cin >> x;
            S.insert(x);
        }
        Ans += (*S.begin() - *S.rbegin());
        S.erase(S.begin());
        multiset<int> :: iterator it = S.end();
        -- it;
        S.erase(it);
    }
    cout << -Ans << '\n';
    fin.close();
    fout.close();
    return 0;
}
