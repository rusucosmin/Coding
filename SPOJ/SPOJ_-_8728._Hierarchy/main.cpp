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

queue <int> Q;
Graph G;
int deg[MAXN], Father[MAXN];
int N, M;

int main() {
    cin.sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    #endif
    cin >> N >> M;
    for(int i = 1 ; i <= M ; ++ i) {
        int x, y;
        cin >> x;
        for(int j = 1 ; j <= x ; ++ j) {
            cin >> y;
            G[i].push_back(y);
            ++ deg[y];
        }
    }
    for(int i = 1 ; i <= N ; ++ i)
        if(!deg[i])
            Q.push(i);
    int last = 0;
    while(!Q.empty()) {
        int Node = Q.front();
        Q.pop();
        Father[Node] = last;
        last = Node;
        for(It it = G[Node].begin(), fin = G[Node].end(); it != fin ; ++ it) {
            -- deg[*it];
            if(!deg[*it]) {
                Father[*it] = Node;
                Q.push(*it);
            }
        }
    }
    for(int i = 1 ; i <= N ; ++ i)
        cout << Father[i] << '\n';
    fin.close();
    fout.close();
    return 0;
}
