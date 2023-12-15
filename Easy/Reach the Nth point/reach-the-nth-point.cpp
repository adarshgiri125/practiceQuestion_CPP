//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    if(n==1) return 1;
		    if(n==2) return 2;
		    int pre1=1,pre2=2, temp, mod=1e9+7;;
		    for(int i=3; i<=n; ++i){
		        temp=pre2;
		        pre2=(pre2%mod+pre1%mod)%mod;
		        pre1=temp;
		    }
		    return pre2;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends