#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1917B
        int n;cin>>n;
        string s;
        cin>>s;

        vector<int>c(26,0);
        map<char,int>freq;
        for(int i=0;i<n;i++){
            if(!freq.count(s[i])){
                c[s[i] - 'a'] = n-i;
            }
            freq[s[i]]++;
        }
        ll ans = accumulate(c.begin(),c.end(),0LL);
        cout<<ans;N();
    }
    // set<string>uni;
    // BRUTE(s,uni);
    // cout<<uni.size();N();
    // void BRUTE(string s,set<string>&uni){
    //     uni.insert(s);
    //     if(s.length() >= 1){
    //         string a = s.substr(1);
    //         if(!a.empty())
    //             BRUTE(a,uni);
    //     }
    //     if(s.length() >= 2){
    //         string b = s[0] + s.substr(2);
    //         if(!b.empty())
    //             BRUTE(b,uni);
    //     }
    // }



    int run() {
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

int main(){
    Main OBJ;
    return OBJ.run();
}
