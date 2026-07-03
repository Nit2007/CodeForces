#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/2217/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        ll n,m,a,b;cin>>n>>m>>a>>b;
        if(gcd(n,a) == 1 && gcd(m,b) == 1 && gcd(n,m) <= 2){
            cout<<"YES";N();return;
        }
        cout<<"NO";N();return;
    }
    // for all [i,j] in [n,m]:
    //     [(1+xa)%n,(1+yb)%m]; where x,y could be any number
    // i-1 = xa %n
    // j-1 = yb %m
    // in 1D => (7/3) , (8/3) works but (9/3),(9,6) wont cause it loops on the same path
    // Potential of A : {0, a, 2a, 3a, ...} mod n , there are ( n / gcd(n,a) ) states possible
    // as we need to visit all nos from 1 to n, (n/gcd(n,a)) = n --> gcd(n,a) = 1

    // to return back to the start(0,0) where k is the smallest number 
    // ka = 0 mod n        if n divides (k*a) , but gcd(n,a) = 1 ,then n divides k
    // kb = 0 mod m        if m divides (k*b) , but gcd(n,b) = 1 ,then m divides k
    // as both n & m divides k , 
    // k = LCM(n,m) 
    // max no of states is 2 * LCM(n,m)

    // 2·lcm(n,m) ≥ n·m
    // 2·lcm(n,m) ≥ gcd(n,m)·lcm(n,m)          {n * m = gcd(n,m) * lcm(n,m)}
    // 2 ≥ gcd(n,m)



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
