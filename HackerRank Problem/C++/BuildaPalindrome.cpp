#include <bits/stdc++.h>

using namespace std ;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define plii pair<pair<ll, int>, int>
#define piii pair<pii, int>
#define viii vector<pair<pii, int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)
#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)
#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)
#define ASST(x, l, r) assert( x <= r && x >= l )

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const int mod = 1e9 + 7;

int ADD(int a, int b, int m = mod) {
    int s = a;
    s += b;
    if( s >= m )
      s -= m;
    return s;
}

int MUL(int a, int b, int m = mod) {
    return (1LL * a * b % m);
}

int power(int a, int b, int m = mod) {
    int res = 1;
    while( b ) {
        if( b & 1 ) {
            res = 1LL * res * a % m;
        }
        a = 1LL * a * a % m;
        b /= 2;
    }
    return res;
}

ll nC2(ll x) {
    return ( x * ( x - 1 ) / 2 );
}

const int maxn = 1e6 + 5;
char s1[ maxn ], s2[ maxn ], s[ maxn ];
int p1[ maxn ], p2[ maxn ];
int n, m, len, num, suff, fd[ maxn ], bd[ maxn ]; // node 1 - root with len -1, node 2 - root with len 0 ,  max suffix palindrome
char txt[ maxn ];
int iSA[maxn], SA[maxn]; //output
int cnt[maxn], next_gen[maxn], lcp[maxn], LCP[maxn][22], sa1[ maxn ], sa2[ maxn ]; //internal
bool bh[maxn], b2h[maxn];

void reset( int len ) {
    int i; fr(i, 0, len) {
        iSA[i] = 0;
        SA[i] = 0;
        cnt[i] = 0;
        next_gen[i] = 0;
        lcp[i] = 0;
        bh[i] = 0;
        b2h[i] = 0;
        int j;
        fr(j, 0, 20)
            LCP[i][j] = 0;
    }
}

bool smaller_first_char(int a, int b){
    return txt[a] < txt[b];
}

void SuffixSort(int n) {
    for (int i=0; i<n; ++i){
        SA[i] = i;
    }
    sort(SA, SA + n, smaller_first_char);
    for (int i=0; i<n; ++i){
        bh[i] = i == 0 || txt[SA[i]] != txt[SA[i-1]];
        b2h[i] = false;
    }
    for (int h = 1; h < n; h <<= 1){
        int buckets = 0;
        for (int i=0, j; i < n; i = j){
            j = i + 1;
            while (j < n && !bh[j]) j++;
            next_gen[i] = j;
            buckets++;
        }
        if (buckets == n) break;
        for (int i = 0; i < n; i = next_gen[i]){
            cnt[i] = 0;
            for (int j = i; j < next_gen[i]; ++j){
                iSA[SA[j]] = i;
            }
        }
        cnt[iSA[n - h]]++;
        b2h[iSA[n - h]] = true;
        for (int i = 0; i < n; i = next_gen[i]){
            for (int j = i; j < next_gen[i]; ++j){
                int s = SA[j] - h;
                if (s >= 0){
                int head = iSA[s];
                iSA[s] = head + cnt[head]++;
                b2h[iSA[s]] = true;
                }
            }
            for (int j = i; j < next_gen[i]; ++j){
                int s = SA[j] - h;
                if (s >= 0 && b2h[iSA[s]]){
                    for (int k = iSA[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                }
            }
        }
        for (int i=0; i<n; ++i){
            SA[iSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i=0; i<n; ++i){
        iSA[SA[i]] = i;
    }
}

void InitLCP(int n) {
    for (int i=0; i<n; ++i) 
        iSA[SA[i]] = i;
    lcp[0] = 0;
    for (int i=0, h=0; i<n; ++i)
    {
        if (iSA[i] > 0)
        {
            int j = SA[iSA[i]-1];
            while (i + h < n && j + h < n && txt[i+h] == txt[j+h]) 
                h++;
            lcp[iSA[i]] = h;
            if (h > 0) 
                h--;
        }
    }
}

void ConstructLCP() {
    InitLCP( len );
    for(int i = 0;i<len;++i)
        LCP[i][0] = lcp[i];
    for(int j = 1;(1<<j)<=len;++j){
        for(int i = 0;i+(1<<j)-1<len;++i){
            if(LCP[i][j-1]<=LCP[i+ ( 1<<(j-1) )][j-1])
                LCP[i][j] = LCP[i][j-1];
            else
                LCP[i][j] = LCP[i+(1<<(j-1))][j-1];
        }
    }
}

int GetLCP(int x, int y) {
    if(x == y) return len-SA[x];
    if(x > y) swap(x,y);
    int log = 0;
    while((1<<log)<=(y-x)) ++log;
    --log;
    return min(LCP[x+1][log],LCP[y-(1<<log)+1][log]);
}

struct node {
    int next[26];
    int len;
    int sufflink;
};

node tree[maxn];

bool addLetter(int pos) {
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';
    while (true) {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])        
            break;    
        cur = tree[cur].sufflink;
    }        
    if (tree[cur].next[let]) {    
        suff = tree[cur].next[let];
        return false;
    }
    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[cur].next[let] = num;
    if (tree[num].len == 1) {
        tree[num].sufflink = 2;
        return true;
    }
    while (true) {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }        
    }
    return true;
}

void initTree() {
    num = 2; suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
}

void solve() {
    scanf("%s", s1);
    scanf("%s", s2);
    n = strlen( s1 );
    m = strlen( s2 );
    int i;
    len = n;
    reset( len );
    fr(i, 0, n-1) txt[i] = s1[i];
    SuffixSort( len );
    fr(i, 0, n-1) sa1[i] = iSA[i];
    len = m;
    reset( len );
    fr(i, 0, m-1) txt[i] = s2[m-1-i];
    SuffixSort( len );
    fr(i, 0, m-1) sa2[m-1-i] = iSA[i];
    fr(i, 0, n-1) 
        s[i] = s1[n-1-i];
    initTree();
    fr(i, 0, n-1) {
        addLetter( i );
        p1[n-1-i] = tree[suff].len;
    }
    p1[ n ] = 0;
    fr(i, 1, num) {
        tree[i].len = 0;
        tree[i].sufflink = 0;
        ms(tree[i].next, 0);
    }
    fr(i, 0, m-1) 
        s[i] = s2[i];
    initTree();
    fr(i, 0, m-1) {
        addLetter( i );
        p2[i] = tree[suff].len;
    }
    fr(i, 1, num) {
        tree[i].len = 0;
        tree[i].sufflink = 0;
        ms(tree[i].next, 0);
    }
    len = n + m + 1;
    reset( len );
    fr(i, 0, n-1) txt[i] = s1[n-1-i];
    txt[n] = '$';
    fr(i, n+1, n+m) txt[i] = s2[i-n-1];
    SuffixSort( len );
    ConstructLCP();
    int pos1, pos2;
    pos1 = pos2 = -1;
    fr(i, 0, len - 1) {
        if( SA[i] > n ) {
            bd[SA[i]] = pos1;
            pos2 = SA[i];
        } else if( SA[i] < n ){
            bd[SA[i]] = pos2;
            pos1 = SA[i];
        }
    }
    pos1 = pos2 = -1;
    fb(i, len - 1, 0) {
        if( SA[i] > n ) {
            fd[SA[i]] = pos1;
            pos2 = SA[i];
        } else if( SA[i] < n ) {
            fd[SA[i]] = pos2;
            pos1 = SA[i];
        }
    }
    int l, r, currlen = 0;
    l = r = -1;
    currlen = 0;
    fr(i, 0, n-1) {
        int temp = 0;
        if( fd[n-1-i] != -1 ) temp = max( temp, GetLCP(iSA[n-1-i], iSA[fd[n-1-i]]) );
        if( bd[n-1-i] != -1 ) temp = max( temp, GetLCP(iSA[n-1-i], iSA[bd[n-1-i]]) );
        if( temp && currlen < temp * 2 + p1[i+1] ) {
            l = i - temp + 1;
            r = i + p1[i+1];
            currlen = temp * 2 + p1[i+1];
        } else if( temp && currlen == temp * 2 + p1[i+1] ) {
            if(sa1[i-temp+1] < sa1[l]) {
                l = i - temp + 1;
                r = i + p1[i+1];
            }
        }
    }
    if( currlen == 0 ) {
        cout << -1 << "\n";
        return;
    }
    string f1, f2;
    f1.resize(currlen);
    int j;
    i = 0; j = currlen  - 1;
    while( l <= r ) {
        f1[i] = f1[j] = s1[l];
        l ++;
        i ++; j --;
    }
    l = r = -1;
    currlen = 0;
    fr(i, 0, m-1) {
        int temp = 0, p = 0;
        p = (i ? p2[i-1]: 0);
        if( fd[n+i+1] != -1 ) temp = max( temp, GetLCP(iSA[n+i+1], iSA[fd[n+i+1]]) );
        if( bd[n+i+1] != -1 ) temp = max( temp, GetLCP(iSA[n+i+1], iSA[bd[n+i+1]]) );
        if( temp && currlen < temp * 2 + p ) {
            r = i+temp-1;
            l = i-p;
            currlen = temp * 2 + p;
        } else if( temp && currlen == temp * 2 + p ) {
            if(sa2[i+temp-1] < sa2[r]) {
                r = i+temp-1;
                l = i-p;
            }
        }
    }
    f2.resize( currlen );
    i = 0; j = currlen - 1;
    while( l <= r ) {
        f2[i] = f2[j] = s2[r];
        r --; i ++; j --;
    }
    if( f1.length() != f2.length() ) {
        if( f1.length() < f2.length() ) cout << f2 << "\n";
        else cout << f1 << "\n";
    } else {
        if( f1 < f2 ) cout << f1 << "\n";
        else cout << f2 << "\n";
    }
}

int main() {
    int t; sc1( t );
    while( t-- ) solve();
    return 0;
}