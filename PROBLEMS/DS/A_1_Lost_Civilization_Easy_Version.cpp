#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
void solve(){//2201A1
    int n;cin>>n;
    vector<int>nums = readVector<int>(n);
    
    int count = 1;
    int x=nums[0],y=nums[0];//[x...a[i]...y]
    for(int i=1;i<n;i++){
        if(x+1 <= nums[i] && nums[i] <= y+1){//The window contains all consecutive nos forming a segment,else it would break
            y = nums[i];
        }else{
            count++;//New subSeg -> Reset window
            x = nums[i];
            y = nums[i];
        }
    }
    cout<<count;N();
    //Every new element is after its parent or next to its sibling
    //Hence we can say that each subSegement is divided ,so the previous sub_segements,
    // dont contribute to the current value
        // [1]
        // [1,2]
        // [1,2,2]
        // [1,2,2,3]
        // [1,2,2,2,3]
    }
    // void solve(){//2201A1
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);

    //     map<int,int>lastSeen = { {nums[0],0} };
    //     int count = 1;
    //     for(int i=1;i<n;i++){
    //         lastSeen[nums[i]] = i;
    //         if(lastSeen.find(nums[i]-1) == lastSeen.end()){
    //             count++;//if(n == 7){cout<<i<<" ";ND();}
    //             continue;
    //         }else continue;
    //         // if(lastSeen.find(nums[i]) != lastSeen.end()){
    //         //     continue;
    //         // }
    //         // // if(nums[i-1] + 1 == nums[i] )continue; 
    //         count++;
    //     }

    //     cout<<count;N();

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
        vector<T> v(n);
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