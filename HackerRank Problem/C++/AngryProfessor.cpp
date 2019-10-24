#include<bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while(test) {
        int n, m, a, count = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> a;
            if(a <= 0) count++;
        }
        if(count >= m) cout << "NO" << endl;
        else cout << "YES" << endl;
        test--;
    }
    return 0;
}