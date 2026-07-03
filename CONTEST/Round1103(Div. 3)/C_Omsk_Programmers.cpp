#include <bits/stdc++.h> /*https://codeforces.com/contest/2236/problem/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int a,b,x;cin>>a>>b>>x;
        map<int,int>a_list, b_list;
        int op = 0;
        while(a > 0){
            a_list[a] = op++;
            a /= x;
        }
        a_list[a/x] = op;

        op = 0;
        while(b > 0){
            b_list[b] = op++;
            b /= x;
        }
        b_list[b/x] = op;

        int ans = INT_MAX;  
        for(auto a_op : a_list){
            for(auto b_op:b_list){
                ans = min(ans, a_op.second + b_op.second + abs(b_op.first - a_op.first));
            }
        }
        cout<<ans;N();
    }
    //7 0 
    //3 0

    //  17 5 1 0
    //  3  1 0

    // a < x ,b  
    // a,b < x
    // x < a,b
    // int op = min({abs(a-b) ,abs((a/x) - b)+1,abs((b/x) - a) +1, abs(a/x - b/x)+2});
    
    
    // if(b_list.count(a_op.first)){
    //     ans = min(ans,a_list[a_op.first] + b_list[a_op.first]);
    // }else{
    //     ans = min(ans, abs(a_list[a_op.first] - ) );
    // }
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
