#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1582/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        string s;cin>>s;
        int ans = INT_MAX;
        for(char remove='a';remove<='z';remove++){
            int l=0 , r=n-1 , op = 0, valid = true;
            while(l<r){
                if(s[l] == s[r]){
                    l++;
                    r--;
                }else{
                    if(s[l] == remove){
                        l++;
                        op++;
                    }else if(s[r] == remove){
                        r--;
                        op++;
                    }else{
                        valid = false;
                        break;
                    }
                }
            }
            if(valid){
                ans = min(ans,op);
            }
        }
        if(ans == INT_MAX)ans = -1;
        cout<<ans;N();
    }

    // void solve(){
    //     int n;cin>>n;
    //     string s;cin>>s;
    //     int l=0 , r=n-1 , op = 0;
    //     char remove = '#';
    //     while(l<r){
    //         if(s[l] == s[r]){
    //             l++;
    //             r--;
    //         }else{
    //             if(remove == '#'){
    //                 if(s[l] == s[r-j]){
    //                     remove = s[r];
    //                     op++;
    //                     r--;
    //                 }else if(s[r] == s[l+1]){
    //                     remove = s[l];
    //                     op++;
    //                     l++;
    //                 }else{
    //                     cout<<-1;N();return;
    //                 }
    //             }else{
    //                 if(s[l] == remove){
    //                     op++;
    //                     l++;
    //                 }else if(s[r] == remove){
    //                     op++;
    //                     r--;
    //                 }else{
    //                     op += 2;
    //                     l++;
    //                     r--;
    //                 }
    //             }
    //         }
    //     }
    //     cout<<op;N();
    // }


    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve(); }
        return 0;
    }

    


    template<typename T>
    void PRINT(const vector<T>& v){
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }

    template<typename T>
    void PRINTS(const string& s,const vector<T>& v){
        cout<<s<<" : ";
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }
    void N(){cout<<"\n";}
    void ND(){cout<<"---DEBUG___";cout<<"\n";}
    template<typename... Args>
    void debugPrint(const string& raw, Args&&... args){
        vector<string> keys;
        stringstream ss(raw);
        string tok;
        while(getline(ss, tok, ',')){
            while(!tok.empty() && tok.front()==' ') tok.erase(tok.begin());
            while(!tok.empty() && tok.back() ==' ') tok.pop_back();
            keys.push_back(tok);
        }
        int i=0;
        cout << " [DEBUG] ";
        ([&](auto&& arg){ cout << keys[i++] << " : " << arg << "  |  "; }(args), ...);
        cout << "\n";
    }

    template<typename T>
    vector<T> readVector(int n){
        vector<T> v((unsigned int)n);
        for(auto &x : v) cin >> x;
        return v;
    }
    template<typename T>
    vector<T> makeUnique(vector<T>& v){
        unordered_set<T>seen;
        vector<T>unique;
        for(auto &x:v){
            if(seen.insert(x).second)unique.push_back(x);
        }return unique;
    }
};

signed main(){
    Main OBJ;
    return OBJ.run();
}
