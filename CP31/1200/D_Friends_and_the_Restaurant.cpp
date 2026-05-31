#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
    void solve(){//1729D
        int n;cin>>n;
        vector<int>x = readVector<int>(n);
        vector<int>y = readVector<int>(n);
        multiset<int>diff;
        for(int i=0;i<n;++i){
            diff.insert((y[i]-x[i]));
        }
        int pairs = 0;
        while(diff.size() > 1){
            auto small = diff.begin();
            int left = *small;
            diff.erase(small);
            auto large = diff.lower_bound(-left);// -3.......2.[3]..4.6
            if(large == diff.end()){
                continue;
            }
            diff.erase(large);
            pairs++;
        }
        cout<<pairs;N();
    }
    //Wrong attempt - assuming 3 or more elements could be an optimal soln but pairs are optimal
    // void solve(){//1729D
    //     int n;cin>>n;
    //     vector<int>x = readVector<int>(n);
    //     vector<int>y = readVector<int>(n);
    //     vector<pair<int,int>>yx(0);
    //     for(int i=0;i<n;++i){
    //         yx.push_back(make_pair(y[i],x[i]));
    //     }
    //     sort(yx.begin(),yx.end(),[](const auto&a, const auto&b){
    //          if (a.first != b.first) {
    //             return a.first > b.first; 
    //         }
    //         return a.second > b.second;
    //     });
    //     // for(auto a:yx){cout<<a.first<<" ";}N();
    //     // for(auto a:yx){cout<<a.second<<" ";}N();
    //     int l = 0 ,r = n-1;
    //     int pairs = 0;
    //     while(l<r){
    //         ll sum_y = yx[l].first + yx[r].first ;
    //         ll sum_x = yx[l].second + yx[r].second ;
    //         while(sum_x > sum_y){
    //             r--;
    //             if(r < 0 || r <= l)break;
    //             sum_y += yx[r].first;
    //             sum_x += yx[r].second;
    //         }
    //         if(sum_x <= sum_y){
    //             pairs++;
    //         }
    //         l++;
    //         r--;
    //     }
    //     cout<<pairs;N();
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
