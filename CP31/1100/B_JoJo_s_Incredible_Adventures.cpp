#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1820/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        string s;cin>>s;
        int n=s.length();
        int maxCons = 0 , cons = 0;
        int zero = count(s.begin(),s.end(),'0');
        int one = count(s.begin(),s.end(),'1');
        int i;
        if(zero == 0){
            cout<<n * 1LL * n;N();return;
        }
        else if(one == 0){
            cout<<0;N();return;
        }
        else{
            for(int j=0;j<n;j++){
                if(s[j] == '0'){
                    i = j;
                    break;
                }
            }
        }
        int loop = 0;
        while(loop<n){
            if(s[i%n] == '0'){
                maxCons = max(maxCons,cons);
                cons = 0;
            }
            if(s[i%n] == '1'){
                cons++;
                maxCons = max(maxCons,cons);
            }
            i++;
            loop++;
        }
        if(maxCons%2 == 0){
            cout<<((maxCons/2)+1) * 1LL * (maxCons/2); //Choosing the mid
        }else{
            cout<<((maxCons+1)/2) * 1LL * ((maxCons+1)/2);//Upper triangle - selecting a sq
        }
        N();
    }
// 101
// 110
// 011

// 11110
// 01111
// 10111
// 11011
// 11101

// 1111
//  1111
//   1111
//    1111
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
