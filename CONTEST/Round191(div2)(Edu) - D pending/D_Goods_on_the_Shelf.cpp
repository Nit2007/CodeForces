#include <bits/stdc++.h> /*https://codeforces.com/contest/2233/problem/D*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
    public:  
    
    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        if(n <= 3){
            cout<<"YES\n";return;
        }
        bool ans = true;
        map<int,int>valueBlock;
        for(int i=0;i<n;){
            int first = i;
            while(i<n && nums[i] == nums[first]){
                i++;
            } 
            if(i<n)valueBlock[nums[i]]++;
        }
        vector<int>block(0);
        for(auto [v,rep]:valueBlock){
            if(rep > 4){
                ans = false;
            }
            block.push_back(rep);
        }
        sort(block.begin(),block.end(),greater<int>());
        PRINT(block);
        if(block.size() > 2 && block[2] > 1){
            ans = false;
        }
        if(ans){
            cout<<"YES\n";
        }
        else {cout<<"NO\n";}
    }
// {x x} y {x} y y {x} y y  - There could be no more than 3 blocks of 2 distinct numbers after a successful swap
    // void solve(){
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     if(n <= 3){
    //         cout<<"YES\n";return;
    //     }
    //     map<int,int>seen = { {nums[0],1} };
    //     vector<pair<int,int>>mismatch;
    //     bool jump = false;
    //     for(int i=1;i<n;i++){
    //         // if(jump){
    //         //     jump = false;
    //         //     continue;
    //         // }
    //         if(nums[i-1] != nums[i] && seen.count(nums[i]) > 0){
    //             mismatch.push_back(make_pair(nums[i-1],nums[i]));
    //             jump = true;
    //         }
    //         seen[nums[i]]++;
    //     }
    //     if(mismatch.size() == 2){
    //         if(mismatch[0] == mismatch[1]){cout<<"YES\n";return;}
    //     }
    //     cout<<"NO";N();
    //     PRINT(nums);
    //     for(auto x:mismatch){
    //             cout<<x.first<<" "<<x.second;ND();
    //         }
    //     } 
        
        // set<int>s;
        //     for(int i=0;i<mismatch.size();i++){
        //         s.insert(mismatch[i].first);
        //         s.insert(mismatch[i].second);
        //     }
        //     if(s.size() <= 2){
        //         cout<<"YES\n";return;
        //     }

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
