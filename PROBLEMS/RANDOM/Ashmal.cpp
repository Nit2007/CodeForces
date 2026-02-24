#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//2180B
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>words(n);
        for(int i=0;i<n;i++){
            cin>>words[i];
        }
        
        string s="";
        for(int i=0;i<n;i++){
            string front = words[i] + s;
            string back = s + words[i] ;
            if(front > back){
                s = back;
            }else s = front;
        }
        cout<<s<<endl;
    }
}
/*HERE SORTING ALONE DOESNT WORK CAUSE :
Consider the strings: ["c", "cb", "cba"].
Alphabetical Sort: ["c", "cb", "cba"] → Concatenates to ccbcba.
Optimal Order: ["cba", "cb", "c"] → Concatenates to cbacbc.
Comparison: cbacbc is lexicographically smaller than ccbcba.  */