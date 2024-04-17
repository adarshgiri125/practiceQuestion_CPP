//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int merge(vector<int> &v, int s, int mid, int e){
    int size1 = mid - s + 1;
    int size2 = e - mid;
    vector<int> a(size1);
    vector<int> b(size2);
    
    for(int i = 0; i < size1; i++){
        a[i] = v[s + i]; 
    }
    for(int i = 0; i < size2; i++){
        b[i] = v[mid + 1 + i]; 
    }
    
    int i = 0;
    int j = 0;
    int k = s; 
    int pairs = 0; 
    
    while(i < size1 && j < size2){
        if(a[i] <= b[j]){ 
            v[k] = a[i];
            i++;
        }
        else{
            v[k] = b[j];
            j++;
            pairs += size1 - i; 
        }
        k++;
    }
    while(i < size1){
        v[k] = a[i];
        i++;
        k++;
    }
    while(j < size2){
        v[k] = b[j];
        j++;
        k++;
    }
    return pairs; 
}

int mergeSort(vector<int> &v, int s, int e){
    int pairs = 0;
    if(s < e){
        int mid = s + (e - s) / 2;
        pairs += mergeSort(v, s, mid);
        pairs += mergeSort(v, mid + 1, e);
        pairs += merge(v, s, mid, e);
    }
    return pairs;
}

int countPairs(int arr[], int n) {
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int val = i * arr[i];
        v[i] = val;
    }
    
    return mergeSort(v, 0, n - 1); 
}

};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends