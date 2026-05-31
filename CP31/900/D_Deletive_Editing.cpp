#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1666D
        string s,t;
        cin>>s>>t;
        if(s == t){
            cout<<"YES";N();return;
        }
        if(s.length() <= t.length()){
            cout<<"NO";N();return;
        }

        int n = s.length();
        int m = t.length();
        map<char,int>freqT,freqS;
        for(char x:s){
            freqS[x]++;
        }
        for(char x:t){
            freqT[x]++;
        }
        //All the leading characters are removed ,hence iterate backwards
        for(int i = n-1;i>=0;i--){
            if(freqT.count(s[i]) && freqT[s[i]] > 0){
                freqT[s[i]]--;
            }else{
                s[i] = '.';             //REMOVED
            }
        }
        
        string build = "";
       for(int i= 0;i<n;i++){
          if(s[i] == '.')continue;
          build += s[i];
       }

        if(build == t){
            cout<<"YES";N();
        }
        else {
            cout<<"NO";N();
        }
    }
    // void solve(){//1666D
    //     string s,t;
    //     cin>>s>>t;
    //     if(s == t){
    //         cout<<"YES";N();return;
    //     }
    //     if(s.length() <= t.length()){
    //         cout<<"NO";N();return;
    //     }

    //     int i = 0 , j = 0;
    //     map<char,int>freq;
    //     for(char x:t){
    //         freq[x]++;
    //     }
    //     bool valid = false;
    //     while(i<s.length()){
    //         if(j == t.length()){
    //             valid = true;
    //             break;
    //         }
    //         if(s[i] == t[j]){
    //             ++j;
    //         }
    //         i++;
    //     }
    //     for(int k=i+1;k<s.length();k++){
    //         char x = s[k];
    //         if(freq.count(x)){
    //             valid = false;
    //             break;
    //         }
    //     }
    //     if(valid){
    //         cout<<"YES";N();
    //     }
    //     else {
    //         cout<<"NO";N();
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
