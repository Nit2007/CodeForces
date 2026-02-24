#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//236A
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
   string s;
   cin>>s;
   set<char>m;
   for(char c:s){
        m.insert(c);
   }
   if(m.size() % 2 != 0){
        cout<<"IGNORE HIM!";
   }else {
        cout<<"CHAT WITH HER!";
   }
}
