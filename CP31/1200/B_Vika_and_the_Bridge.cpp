#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1848B
        int n,k;cin>>n>>k;
        vector<int>nums = readVector<int>(n);
        map<int,vector<int>>colorIndex;
        for(int i=0;i<n;i++){
            colorIndex[nums[i]].push_back(i);
        }
        vector<int>jumps(0);
        int j = 1;
        while(j<=k){
            vector<int>index = colorIndex[j];
            index.insert(index.begin(), -1);
            index.push_back(n);
            vector<int>diff(0);
            int prev = INF;
            for(int i:index){
                if(prev != INF){
                    diff.push_back(i - prev - 1);
                    prev = i;
                }else{
                    prev = i;
                }
            }
            sort(diff.begin(),diff.end());
            int largest = diff.back();
            int secondLargest = (diff.size() >= 2 ? diff[diff.size()-2] : 0);
            jumps.push_back( max(secondLargest, largest/2) );
            j++;
        }
        cout<<*min_element(jumps.begin(),jumps.end());N();
    }
    //WA at testcase 2 => the problem is about minimiziing the max jump ,not having a constant jump
    // void solve(){//1848B
    //     int n,k;cin>>n>>k;
    //     vector<int>nums = readVector<int>(n);

    //     int i = 0;
    //     while(i<n){
    //         set<int>color = {};
    //         for(int j=i;j<n;j+=i+1){
    //             color.insert(nums[j]);
    //         }
    //         if(color.size() <= 2){
    //             cout<<i<<endl;
    //             break;
    //         }
    //         i++;
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
