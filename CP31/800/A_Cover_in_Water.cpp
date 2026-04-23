#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1900A
        int n;cin>>n;
        vector<char>nums = readVector<char>(n);

        int threeConsecutive = 0;
        int totalEmpty = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == '.')totalEmpty++;
            if(i >= 1 && i < n-1){
                if(nums[i-1] == '.' && nums[i] == '.'  && nums[i+1] == '.' ){
                    threeConsecutive++;
                }
            }
        }
        
        if(threeConsecutive != 0){
            cout<<2;
        }else{
            cout<<totalEmpty;
        }
        N();
    }
    // Assumming that water cannot be moved across blocks
    // void solve(){//1900A
    //     int n;cin>>n;
    //     vector<char>nums = readVector<char>(n);

    //     int type_1 = 0;
    //     int block = 0;
    //     for(int i=0;i<n;i++){
    //             if(nums[i] == '.')block++;
    //             else{
    //                 if(block != 0 && block < 2 ){// cout<<i<<" ";
    //                     type_1++;
    //                 }else if(block >= 2){
    //                     type_1 += 2;
    //                 }
    //                 block = 0;
    //             }
    //     }
    //     if(block != 0 && block < 2 ){
    //         type_1++;
    //     }else if(block >= 2){
    //         type_1 += 2;
    //     }
    //     cout<<type_1;N();
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
