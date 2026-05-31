#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1624B
        int a,b,c;cin>>a>>b>>c;
        bool found = false;
        int new_a = (2*b - c);
        if((new_a/a) > 0 && (new_a%a) == 0)  { // a*m b c -> b-c == a*m - b -> (2b -c)/a >0 as m is +ve & INT
            found = true;
        }
        int new_b = (a+c)/2;
        if( (new_b/b) > 0 && (new_b%b) == 0 && (c-a)%2 == 0)  { // a b*m c -> b*m-c == a - b*m -> (a+c)/2 > 0 as m is +ve & INT
            found = true;
        }
        int new_c = (2*b-a);
        if( (new_c/c) > 0 && (new_c%c) == 0)  { // a b c*m -> b-c*m == a - b -> (2b-a)  {as m is +ve & INT}
            found = true;
        }
        if(found){
            cout<<"YES\n";
        }else{
            cout<<"NO";N();
        }
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
