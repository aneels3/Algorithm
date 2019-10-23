#include <bits/stdc++.h>

using namespace std;

string gameOfStones(int n) {
    if(n%7==0 || n%7==1)
        return("Second");
    return("First");
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        string result = gameOfStones(n);
        cout << result << endl;
    }
    return 0;
}
