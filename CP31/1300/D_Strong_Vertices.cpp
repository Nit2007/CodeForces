#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1857/D*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<int>a = readVector<int>(n);
        vector<int>b = readVector<int>(n);
        vector<int>diff(n,0);
        for(int i=0;i<n;i++){
            diff[i] = -a[i] + b[i];
        }
        // PRINT(diff);
        int mini = *min_element(diff.begin(),diff.end());
        vector<int>ans(0);
        for(int i=0;i<n;i++){
            if(diff[i] == mini) ans.push_back(i+1);
        }
        cout<<ans.size();N();
        PRINT(ans);
    }
    // a=[3,1,2,4]
    // b=[4,3,2,1]
    // From 4 => 1 3 2
    //          -3-2-1
    //           4 5 6   >= 0 --> Strong Vertex
    //  a[0] - a[1] >= b[0] - b[1]
    //  a[0] - b[0] >= a[1] - b[1]
    //  diff[0] >= diff[1] -> There exist a path from 0 to 1


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
