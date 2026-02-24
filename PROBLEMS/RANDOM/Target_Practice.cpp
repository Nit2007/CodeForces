#include <bits/stdc++.h>
using namespace std;
//1873C
int main() {
	int n;cin>>n;
	
	for(int i=0;i<n;i++){
	    int ans = 0;
	    for(int j=0;j<10;j++){
	        for(int k=0;k<10;k++){
	            char CHAR;cin>>CHAR;
                if(CHAR == 'X'){
                    int r = j; int c = k;
                    int left = c;
                    int right = 9-c;
                    int top = r;
                    int down = 9 - r;
                    ans +=1+min({left,right,top,down});
                }
	        }
	    }
	    cout<<ans<<endl;
	}
    
}
