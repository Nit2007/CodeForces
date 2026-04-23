#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1883C
        int n,k;cin>>n>>k; //k - [2,5]
        vector<int>nums = readVector<int>(n);

        int operations = INT_MAX;
        int evenCount = 0;
        for(int i=0;i<n;i++){
            if(nums[i] % 2 == 0)evenCount++;
            if(nums[i] % k == 0){
                operations = 0;
            }else{
                int nearest = k - (nums[i]%k);
                operations = min(operations,nearest);
            }
        }

        if(k == 4){
            if(evenCount == 0){//Push 2 odd_numbers to even 
                operations = min(2,operations);
            }
            if(evenCount == 1){//Push 1 odd_number to even
                operations = min(1,operations);
            }
            if(evenCount >= 2){// 2a * 2b = 4 * ab which is divisible by k
                operations = min(0,operations);
            }
        }
        cout<<operations<<endl;
    }
    // ll product = 1;
    // for(int i: nums){
    //     product *= i;
    // }
    // ll nextDivisible = k;
    // while(product >= nextDivisible){
    //     nextDivisible *= ((product)/k)+k;
    // }
    // cout<<nextDivisible<<" "<<product;ND();

    




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
