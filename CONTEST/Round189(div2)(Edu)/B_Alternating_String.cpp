#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//2225B
        string s;cin>>s;
        int n = (int)s.length();

        int r = 0;
        for(int i=1;i<n;i++){
            if(s[i-1] == s[i] ){
                r++;
            }
        }
        if(r<=2){cout<<"YES";N();return;}
        else {cout<<"NO";N();return;}
        //one bad rep can be fixed , 2 bad reps can be fixed by selecting them as boudary
        //But 3 bad reps cannot be fixed in a single operation because ,internal bad either gets flipped
        //or rotated but not correct ,hence 3 or more bads => NO
    }
    // rep = max(rep,temp);
    // if(rep >= 4){
    //     cout<<"NO";N();return;
    // }
    // vector<string>seq;
    // string t = {s[0]};
    // int i=1;
    // for(int i=1;i<n;i++){
    //     if(s[i-1] == s[i] ){
    //         t += s[i];
    //     }else{
    //         seq.push_back(t);
    //         t = {s[i]};
    //     }
        
    // }
    // seq.push_back(t);
    // // PRINT(seq);
    
    // int singles = 0;
    // int doubles = 0;
    // for(auto x:seq){
    //     if(x.size() == 1){
    //         singles++;
    //     }
    //     if(x.size() == 2){
    //         doubles++;
    //     }
    // }
    // if(singles == seq.size()){
    //     cout<<"YES";N();return;
    // }else if (doubles >= 3){
    //     cout<<"NO";N();return;
    // }else{
    //     cout<<"YES";N();return;
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
        cout << "[P] ";
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
