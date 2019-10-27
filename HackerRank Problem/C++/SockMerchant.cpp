#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        if(s.find(x)==s.end())
            s.insert(x);
        else
            s.erase(x);
    }
    cout<<(n-s.size())/2<<endl;
}
