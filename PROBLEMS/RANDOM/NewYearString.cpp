#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//g++ Target_Practice.cpp -o target.exe
//del *.exe
void solve(string s){
    int n=s.length();
    bool new_year=false;
    if(s.find("2026") != string::npos){
        new_year = true;
    } 
    if(s.find("2025") == string::npos){
        new_year = true;
    }
    if(new_year){cout<<0;return;}
    if(s.find("2025") !=string::npos){
        cout<<1;
    }

}
int main() {//2182A
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--)
    {
        int n;cin>>n;
        string s;
        cin>>s;
        solve(s);
        cout<<endl;
    }
}
