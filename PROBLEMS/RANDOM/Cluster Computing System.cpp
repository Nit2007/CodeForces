#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int n;cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int>edge_costs;
    for(int i=0;i<n;i++)
    { //Compute GCD of all contiguous sub arrays ending at i
        int current_gcd = 0; // gcd(0,a) = a;
        int last_gcd = -1;//Only store when GCD changes
        for(int j=i;j>=0;j--){
            current_gcd = gcd(nums[j],current_gcd);
           // if(current_gcd != last_gcd){
                edge_costs.push_back(current_gcd);
             //   last_gcd = current_gcd;
            //}
            if(current_gcd == 1){
                break;
            }
        }
    }
    sort(edge_costs.begin(),edge_costs.end());
    ll cost = 0;
    for(int i = 0; i < n - 1; i++) {
        cost += edge_costs[i];
    }
    
    cout<<cost;
}
