#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
    void solve(){//2228C
        ll a,n,d1,d2;cin>>a>>n>>d1>>d2;
        string s = to_string(a);
        int len = (int)s.length();
        ll c = min(d1,d2);
        ll d = max(d1,d2);
        ll ans = LLONG_MAX;
        ll rep = d;
        for(int i=0;i<len-1;i++){
            ans = min(ans, abs(rep - a));
            rep = rep * 10 + d;
        }
        rep = c;
        for(int i=0;i<len+1;i++){
            ans = min(ans, abs(rep - a));
            rep = rep * 10 + c;
        }
        // 500 - 433 = 67  But 500 - 444 = 56
        string Build = "";//Fix the first Digit greedily , pull other digits(maxmimize/minimze) closer to the number 
        bool minimize = false , maximize = false;
        for(int i=0;i<len;i++){
            ll digit = (s[i] - '0');
            if(minimize){
                Build += to_string(c);
            }
            else if (maximize){
                Build += to_string(d);
            }
            else{
                if(abs(digit - c) <= abs(digit - d)){
                    Build += to_string(c);
                    if(c > digit)minimize = true;
                    if(c < digit)maximize = true;
                }else{
                    Build += to_string(d);
                    if(d > digit)minimize = true;
                    if(d < digit)maximize = true;
                }
            }
        }
        ans = min(ans,abs(a - stoll(Build)));

        Build = "";
        minimize = false , maximize = false;
        for(int i=0;i<len;i++){
            ll digit = (s[i] - '0');
            if(minimize){
                Build += to_string(c);
            }
            else if (maximize){
                Build += to_string(d);
            }
            else{
                if(abs(digit - c) < abs(digit - d)){
                    Build += to_string(c);
                    if(c > digit)minimize = true;
                    if(c < digit)maximize = true;
                }else{
                    Build += to_string(d);
                    if(d > digit)minimize = true;
                    if(d < digit)maximize = true;
                }
            }
        }
        ans = min(ans,abs(a - stoll(Build)));
        cout<<ans;N();
    }

    // void generateCombo(string s,ll c,ll d,int index,vector<string>&doTry,string build){
    //     if(index == s.length()){
    //         doTry.push_back(build);
    //     }
    //     if(index+1 == s.length()){
    //         doTry.push_back(build);
    //     }
    //     if(index-1 == s.length()){
    //         doTry.push_back(build);
    //         return;
    //     }
    //     generateCombo(s,c,d,index+1,doTry,build + to_string(c));
    //     if(c != d)
    //         generateCombo(s,c,d,index+1,doTry,build + to_string(d));
    // }
    // void solve(){//2228C
    //     ll a,n,c,d;cin>>a>>n>>c>>d;
    //     string s = to_string(a);
    //     vector<string>doTry ;
    //     string Build = "";
    //     // generateCombo(s,c,d,-1,doTry,Build);
    //     generateCombo(s,c,d,0,doTry,Build);
    //     // generateCombo(s,c,d,1,doTry,Build);
    //     ll ans = LLONG_MAX;
    //     for(string x:doTry){
    //         // cout<<x;ND();
    //         if(x.empty())continue;
    //         ans = min(ans,abs(a - stoll(x)));
    //     }
    //     cout<<ans;N();
    // }




    // void solve(){//2228C
    //     ll a,n,c,d;cin>>a>>n>>c>>d;
    //     string s = to_string(a);
    //     string big_c = string(s.length(), '0'+c);
    //     string big_d = string(s.length(), '0'+d);
    //     string small_c = string(s.length()-1, '0'+c);
    //     string small_d = string(s.length()-1, '0'+d);
    //     vector<string>doTry ;
    //     ll ans = LLONG_MAX;
    //     for(string x:doTry){
    //         if(x.empty())continue;
    //         ans = min(ans,abs(a - stoll(x)));
    //     }
    //     cout<<ans;N();
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
