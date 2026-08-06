#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1775/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<vector<int>>bin;
        for(int i=0;i<n;i++){
            int k;cin>>k;
            vector<int>b(0);
            for(int p=0;p<k;p++){
                int a;cin>>a;
                b.push_back(a);
            }
            bin.push_back(b);
        }
        map<int,int>seen;
        for(auto &b:bin){
            for (int i = 0; i < b.size(); i++) {
                seen[b[i]]++;
            }
        }
        map<int,int>unique;
        for(auto &x:seen){
            if(x.second == 1){
                unique[x.first]++;
            }
        } 
        vector<bool>valid(n,true);
        for (int i = 0; i < n; i++) {
            if (!valid[i]) continue;
            auto &b = bin[i];
            for (int j = 0; j < b.size(); j++) {
                if (unique[b[j]]) {
                    valid[i] = false;
                    break;
                }
            }
        }
        if(*max_element(valid.begin(),valid.end())){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        N();    
    }

    // void solve(){
    //     int n;cin>>n;
    //     vector<vector<int>>bin;
    //     for(int i=0;i<n;i++){
    //         int k;cin>>k;
    //         vector<int>b(50001,-1);
    //         for(int p=0;p<k;p++){
    //             int a;cin>>a;
    //             b[a]=1;
    //         }
    //         bin.push_back(b);
    //     }
    //     map<int,int>seen;
    //     for(auto b:bin){
    //         for (int i = 0; i < b.size(); i++) {
    //             if (b[i] == 1)
    //                 seen[i]++;
    //         }
    //     }
    //     map<int,int>unique;
    //     for(auto x:seen){
    //         if(x.second == 1){
    //             unique[x.first]++;
    //         }
    //     } 
    //     vector<bool>valid(n,true);
    //     for(auto [val,one] : unique){
    //         for(int i=0;i<n;i++){
    //             if(!valid[i])continue;
    //             if(bin[i][val] == -1){
    //                 valid[i] = false;
    //             }
    //         }
    //     }
    //     if(*max_element(valid.begin(),valid.end())){
    //         cout<<"Yes";
    //     }else{
    //         cout<<"No";
    //     }
    //     N();    
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
