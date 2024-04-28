//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void printPat(int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
    printPat(n);
    cout<<endl;
	}
}
// } Driver Code Ends


/*You are required to complete this method*/
void printPat(int n)
{
//Your code here
int p = n ;
while(p>0){
    int x = n;
    
    for(int i = 0; i < n ;i++){
        for(int j =0 ; j < p ; j++){
            cout <<x<<" ";
        }
        x--;
    }
    cout << "$";
    
    p--;
    
}
}