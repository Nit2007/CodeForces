#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1927D
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        int q;cin>>q;
        vector<pair<int,int>>queries ;
        int l , r ;
        for(int i=0;i<q;i++){
            cin>>l>>r;
            queries.push_back(make_pair(l,r));
        }
        vector<int>last_diff(n,-1);
        for(int i=1;i<n;i++){
            if(nums[i-1] == nums[i]){
                last_diff[i] = last_diff[i-1];
            }else{
                last_diff[i] = i-1;
            }
        }
        for(auto p:queries){
            int l = p.first , r = p.second;
            l--,r--;
            int R = last_diff[r];
            if(l>R){//No change
                cout<<"-1 -1";
            }else{
                cout<<(R+1)<<" "<<(R+2);
            }
            N();
        }N();
    }
    string key(int i,int j){    return to_string(i) + " " + to_string(j) ;    }
    //O(n^2) - PreComputation
    // void solve(){//1927D
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     int q;cin>>q;
    //     vector<pair<int,int>>queries ;
    //     int l , r ;
    //     for(int i=0;i<q;i++){
    //         cin>>l>>r;
    //         queries.push_back(make_pair(l,r));
    //     }
    //     map<string,string>score;
    //     for(int i=0;i<n;i++){
    //         int diff = -1;
    //         for(int j=i+1;j<n;j++){
    //             string curr = key(i+1,j+1);
    //             if(nums[j-1] != nums[j]){
    //                 diff = j;
    //             }
    //             if(nums[i] != nums[j]){
    //                 score[curr] = curr;
    //             }else if(diff != -1){
    //                 score[curr] = key(i+1,diff+1);
    //             }
    //             else score[curr] = "-1 -1";
    //         }
    //     }
    //     for(auto p:queries){
    //         int l = p.first , r = p.second;
    //         string Key = key(l,r);
    //         cout<<score[Key];N();
    //     }N();
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
