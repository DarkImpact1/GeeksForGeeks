//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    // vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    // {
    //     unordered_map<long long int, int> mpp;
        
    //     for(int i =0; i<N; i++){
    //         mpp[Arr[i]]++;
    //     }
        
    //     vector<long long int> ans;
    //     for(auto it : mpp){
    //         if(it.second %2 !=0){
    //             ans.push_back(it.first);
    //         }
    //     }
    //     if(ans[0]< ans[1]) swap(ans[0],ans[1]);
    //     return ans;
    // }
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        long long int xoor  = 0;
        for(int i=0 ; i<N; i++){
            xoor = xoor ^ Arr[i];
        }
        
        // let's find out the right most first set bit 
        long long int rightmost = (xoor & (xoor-1)) ^ xoor;
        long long int num1 = 0, num2 =0;
        for(int i=0; i<N; i++){
            if(rightmost & Arr[i]){
                num1 = num1^Arr[i];
            }else{
                num2 = num2^Arr[i];
            }
        }
        
        vector<long long int> ans;
        ans.push_back(num1);
        ans.push_back(num2);
        
        if(ans[0] < ans[1]) swap(ans[0], ans[1]);
        return ans;
        }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends