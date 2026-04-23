#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1859B
        int n;cin>>n;
        vector<vector<int>>nums(0);
        for(int i=0;i<n;i++){
            int m;cin>>m;
            vector<int>arr = readVector<int>(m);
            nums.push_back(arr);
        }
        for(int i=0;i<n;i++){
            sort(nums[i].begin(),nums[i].end());
        }
        int smallSecond = INT_MAX;
        int indexOfSmallSecond = 0;
        for(int i=0;i<n;i++){
            if(smallSecond > nums[i][1]){
                smallSecond = nums[i][1];
                indexOfSmallSecond = i;
            }
        }
        ll mini = nums[indexOfSmallSecond][0];
        for(int i=0;i<n;i++){
            mini = min(mini,(ll)nums[i][0]);
        }//Choose the global_min
        //Move all first to that global_min_array , then all seconds of remaining array would contribute
        for(int i=0;i<n;i++){
            if(indexOfSmallSecond == i)continue;
            mini += nums[i][1];
        }
        cout<<mini;
        N();
    }
    // 5 {7} 1001 1007
    // 6  8  11 
    // 2  9




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
