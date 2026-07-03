#include <bits/stdc++.h> /*https://codeforces.com/contest/2234/problem/D*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        ll n,k;cin>>n>>k;
        string first,last;
        cin>>first>>last;
        string mid = XOR(first,last,n);
        ll element = (1<<k)+1;
        if(k%2){
            cout<<element/3 * (Score(first) + Score(last) + Score(mid));
        }else{
            cout<<(element+1)/3 * (Score(first) + Score(last)) + (element-1)/3 * Score(mid);
        }
        N();   
    }
    ll Score(string s){
        ll one = 0, zero{};
        for(char x:s){
            if(x == '1')one++;
            if(x == '0')zero++;
        }
        return one * zero;
    }
    string XOR(string a,string b,int n){
        string ans = "";
        for(int i=0;i<n;i++){
            if(a[i] == b[i])ans += '0';
            else ans += '1';
        }
        return ans;
    }
// a . . . . . . . b
// a . . . a^b . . . b
// a . b . a^b . a . b
// a a^b b a a^b b a a^b b - pow(2,3)+1
// a = 3
// b = 3
// a^b = 3

// cout<<(Score(first) *k) + (Score(last) * k )+ (Score(mid) * (k-(k+1)%2)); N();

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
