#include <bits/stdc++.h> /*https://codeforces.com/contest/2233/problem/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n,k;cin>>n>>k;
        string b;cin>>b;
        string ans(n,'0');
        int mini = INT_MAX;
        for(int i=0;i<=n;i++){
            int flip = k ,bal = 0 , cost = 0;
            string build(n,'0') , t = b;
            for(int j=0;j<i;j++){
                if(t[j] == '(' && flip > 0){
                    build[j]= '1';
                    t[j] = '#';
                    flip--;
                }
            }
            for(int j=n-1;j>i;j--){
                if(t[j] == ')' && flip > 0){
                    build[j]= '1';
                    t[j] = '#';
                    flip--; 
                }
                
            }
            for(int j=0;j<n;j++){
                if(t[j] == ')' && bal > 0){
                    cost += 2;
                    bal--;
                }else if(t[j] == '('){
                    bal++;
                }
            }
            if(cost < mini){
                mini = cost;
                ans = build;
            }
        }
        cout<<ans;
        N();
    }
    // void solve(){
    //     int n,k;cin>>n>>k;
    //     vector<char>b = readVector<char>(n);
    //     string ans(n,'0');
    //     int cost = INT_MAX;
    //     for(int left =0;left<=k;left++){
    //         string build(n,'0');
    //         int l =left , r = k-left;
    //         for(int i=0;i<n;i++){
    //             if(b[i] == '(' && l > 0){
    //                 build[i] = '1';
    //                 l--;
    //             }
    //         }
    //         for(int i=n-1;i>=0;i--){
    //             if(b[i] == ')' && r > 0){
    //                 build[i] = '1';
    //                 r--;
    //             }
    //         }
    //         if(RBS(build,b) <= cost){
    //             cost = RBS(build,b);
    //             ans = build;
    //         }
    //     }
    //     cout<<ans;
    //     N();
    // }
    // int RBS(string build,vector<char>b){
    //     int cost = 0;
    //     int bal = 0;
    //     for(int i=0;i<b.size();i++){
    //         if(build[i] == '0')continue;
    //         if(bal > 0 && b[i] == ')'){
    //             cost += 2;
    //             bal--;
    //         }
    //         if(b[i] == '('){
    //             bal++;
    //         }

    //     }
    //     return cost;
    // }
// (()())())(
// --)-))())(
// (-)-))-))(
// 0101001000

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
