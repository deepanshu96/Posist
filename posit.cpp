//DOVE BATMAN
/*
               _,    _   _     ,_
          .-'` /     \'-'/     \ `'-.
         /    |      |   |      |    \
        ;      \_  _/     \_  _/      ;
       |         ``         ``         |
       |                               |
        ;    .-.   .-.   .-.   .-.    ;
         \  (   '.'   \ /   '.'   )  /
          '-.;         V         ;.-'
              `                 `
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <climits>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
#include<time.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, b, sizeof a)
#define FOR(i, j, k, in) for ( i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for ( i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 100000000
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long ll;
typedef pair<int, int> pii;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct node
{
    time_t timestamp;
    set<string> data;
    long int nodeNumber;
    string nodeId;
    string referenceNodeId;
    string childReferenceNodeId;
    string genesisReferenceNodeId;
    set<string> HashValue;
};
class graph{
private:
    map<string, vector<struct node> > m;
    map<string, struct node> m2;
    int chk;
    struct node Genesis;
public:
graph()
{
    chk = -1;
}
void createGenesis(struct node dped)
{
    if(chk==-1)
    {
        dped.referenceNodeId.clear();
        Genesis = dped;
        m2[dped.nodeId] = dped;
    }
    else
    {
        cout<<endl<<"Genesis Node has already been created "<<endl;
    }
}
void createnode(struct node dped)
{
    long int t = dped.nodeNumber;
    long int temp = 0;
    for(int i=0;i<m[dped.referenceNodeId].size();i++)
    {
        temp+= m[dped.referenceNodeId][i].nodeNumber;
    }
    if(temp+t<=m2[dped.referenceNodeId].nodeNumber)
    {
     dped.genesisReferenceNodeId = Genesis.nodeId;
     m2[dped.referenceNodeId].childReferenceNodeId = dped.nodeId;
     this->m[dped.referenceNodeId].push_back(dped);
     this->m[dped.nodeId].push_back(m2[dped.referenceNodeId]);
    }
    else
    {
        cout<<"The nodeNumber is not acceptable"<<endl;
    }
}
void encrypt(struct node &dped, string own, string val, string own_name, string id)
{
    dped.data.insert(own);
    dped.data.insert(val);
    dped.data.insert(own_name);
    dped.data.insert(id);
    string temp = own+val+own_name+id;
    dped.HashValue.insert(temp);
}
void decrypt(struct node &dped)
{
 set<string>::iterator it;
 cout<<"Decrypted data"<<endl;
 for(it=dped.data.begin();it!=dped.data.end();it++)
 {
     cout<<(*(it))<<endl;
 }
}
void longest_genesis(struct node depd, map< string,int> &vis, int ht, int &mx, struct node &tt)
{

    if(vis[depd.nodeId]==9)
    return ;
    vis[depd.nodeId] = 9;
    if(mx<ht)
    tt = depd;
    mx = max(ht, mx);

    for(int i=0;i<m[depd.nodeId].size();i++)
    {
        longest_genesis(m[depd.nodeId][i], vis, ht+1, mx, tt);
    }
}
void longest_node()
{
 struct node temp;
map< string,int> vis;
int mx = 0;
 longest_genesis(Genesis, vis, 0, mx, temp);
 vis.clear();
 mx = 0;
 struct node tt;
 longest_genesis(temp, vis, 0, mx, tt);
 cout<<mx<<endl;
}

};
int main()
{
    graph obj;
  return 0;
}
