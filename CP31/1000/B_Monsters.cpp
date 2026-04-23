#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1849B
        int n,k;cin>>n>>k;
        vector<int>nums = readVector<int>(n);
        vector<pair<int,int>>numsIndex (0);
        for(int i=0;i<n;i++){
            int health = (nums[i]%k == 0)? k :  nums[i]%k;
            numsIndex.push_back(make_pair(health,i));
        }
        sort(numsIndex.begin(),numsIndex.end(),[](const pair<int,int>&a ,const pair<int,int>&b){
            if(a.first == b.first)return a.second < b.second;
            return a.first > b.first;
        });
        
        for(auto &p :numsIndex){
            cout<<p.second+1<<" ";
        }
        N();
    }
    //TLE at testCase 4
    // void solve(){//1849B
    //     int n,k;cin>>n>>k;
    //     vector<int>nums = readVector<int>(n);
    //     vector<pair<int,int>>numsIndex (0);
    //     for(int i=0;i<n;i++){
    //         numsIndex.push_back(make_pair(nums[i],i));
    //     }
    //     sort(numsIndex.begin(),numsIndex.end(),[](const pair<int,int>&a ,const pair<int,int>&b){
    //         if(a.first == b.first)return a.second < b.second;
    //         return a.first > b.first;
    //     });
    //     while(true){
    //         if(numsIndex[0].first <= 0)break;
    //         numsIndex[0].first -= k;
    //         if(numsIndex[0].first <= 0)cout<<numsIndex[0].second+1<<" ";
    //         sort(numsIndex.begin(),numsIndex.end(),[](const pair<int,int>&a ,const pair<int,int>&b){
    //             if(a.first == b.first)return a.second < b.second;
    //             return a.first > b.first;
    //         });
    //     }
    //     N();
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
