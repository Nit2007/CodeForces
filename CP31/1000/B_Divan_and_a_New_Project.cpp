#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1614/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<pair<int,int>>time = readVector<pair<int,int>>(n);
        sort(time.begin(),time.end(),greater<pair<int,int>>());
        ll minTime = 0;
        for(int i=0;i<n;i++){
            minTime += (1LL * time[i].first) * ((i+2)/2);
        }
        minTime *= 2;
        cout<<minTime;N();

        int pos = 1 ,i = 0;
        deque<int>build;
        build.push_back(0);
        while(i<n){
            if(i%2 == 0){
                build.push_back(pos);
            }else{
                build.push_back(-pos);
                pos++;
            }
            i++;
        }//Computing the dist mat 
        vector<int>greedyAns(build.begin(),build.end());
        vector<int>ans(n);
        for(int i=0;i<n;i++){//Assigining the dist_mat to the most visited building
            ans[time[i].second] = greedyAns[i+1];
       }
        cout<<"0 ";
        PRINT(ans);
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
        int i=0;
        for(auto &x : v) {cin >> x.first;
        x.second = i++;}
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
