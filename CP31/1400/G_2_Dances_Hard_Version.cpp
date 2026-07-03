#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1883/G2*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){ // O(n logn logm)  - Insertion + sort(n logn) , BinSearch on m
        int n,m;cin>>n>>m;
        vector<int>a = readVector<int>(n-1);
        vector<int>b = readVector<int>(n);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        // PRINT(a);
        // PRINT(b);ND();
        ll low = 1, high = m, Elevation = 0;
        int base = match(a,b);
        while(low <= high){
            ll v = low + (high - low)/2;
            if(match(v,a,b) == base+1){
                low = v+1;
                Elevation = v;
            }
            else{
                high = v-1;
            }
        }
        ll cost = n - base;
        cout<< (Elevation * (cost-1LL)) + ( (m-Elevation) * (cost)) ;N();          
    }
    int match(int v,vector<int>&A,vector<int>&b){
        int i=0,j=0,pairs = 0;
        vector<int>a = A;
        a.insert(a.begin(),v);
        sort(a.begin(),a.end());
        while(i<(int)a.size() && j<(int)b.size()){
            if(a[i] < b[j]){
                pairs++;
                i++;
            }
            j++;
        }
        return pairs;
    }
    int match(vector<int>&a,vector<int>&b){
        int i=0,j=0,pairs = 0;
        while(i<(int)a.size() && j<(int)b.size()){
            if(a[i] < b[j]){
                pairs++;
                i++;
            }
            j++;
        }
        return pairs;
    }

    void BRUTE(){
        int n,m;cin>>n>>m;
        vector<int>a = readVector<int>(n-1);
        vector<int>b = readVector<int>(n);
        sort(b.begin(),b.end());
        // PRINT(a);
        // PRINT(b);ND();
        int  j=0 , ans = 0;
        for(int M=1;M<=m;M++){
            j=0;
            a.push_back(M);
            sort(a.begin(),a.end());
            for(int i=0;i<n;i++){
                if(b[i] > a[j]){
                    j++;
                }
            }
            a.erase(find(a.begin(), a.end(), M)); 
            ans += n-j;
        }
        cout<<ans;N();
    }


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
