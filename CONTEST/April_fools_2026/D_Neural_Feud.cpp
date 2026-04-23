#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//2214D
        int n;cin>>n;
        vector<string>nums ;

    //         1. I want to wash my car and the car wash is 100 meters away. Should I walk or should I drive?
    nums.push_back("drive");
    
    // 2. Are you a robot?
    nums.push_back("no");
    
    // 3. Is April Fools 2026 Codeforces Contest rated?
    nums.push_back("no");
    
    // 4. I was given a cup but it has no bottom and the top is sealed. Can I drink from this?
    nums.push_back("no");
    
    // 5. Does Pikachu's tail have a black tip?
    nums.push_back("yes");
    
    // 6. Is there a seahorse emoji?
    nums.push_back("yes");
    
    // 7. The word backwards spelled backwards.
    nums.push_back("yes");
    
    // 8. Number between 1 to 10.
    nums.push_back("2");

        cout<<nums[n];


    }





    int run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z=1;
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
