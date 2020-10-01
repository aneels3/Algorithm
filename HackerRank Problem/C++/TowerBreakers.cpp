#include <bits/stdc++.h>

using namespace std;

int towerBreakers(int n, int m) {
    if(m==1)
        return 2;
    else if(n%2==0)
        return 2;
    return 1;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        cin >> n >> m;
        int result = towerBreakers(n, m);
        cout << result << endl;
    }
    return 0;
}
