#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1907/D*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<int>l(n,0);
        vector<int>r(n,0);
        for(int i=0;i<n;i++){
            cin>>l[i]>>r[i];
        }
        int low  = -1, high= 1e9;
        int jump = low + (high - low) / 2;
        int ans = low;
        while(low<=high){
            jump = low + (high - low) / 2;
            // cout<<jump;ND();
            if(Valid(l,r,jump)){
                ans = jump;
                high = jump-1;
            }else{
                low = jump+1; 
            }
        }
        cout<<ans;N();
    }
    bool Valid(vector<int>l,vector<int>r,int k){
        int possible_l = 0 , possible_r = 0 , n = l.size();
        for(int i=0;i<n;++i){
            possible_l = max(possible_l - k , l[i]);
            possible_r = min(possible_r + k , r[i]);
            if(possible_l > possible_r)return false;//Flip in possibilty suggest that there is no chance
        }
        return true;
    }


    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve();}
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
