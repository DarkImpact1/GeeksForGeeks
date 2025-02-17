//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int count(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    unordered_map<char, int> lastIndex; // Stores last occurrence of each character

    dp[0] = 1; // Empty string has one subsequence ("")

    for (int i = 1; i <= n; i++) {
        char ch = s[i - 1];
        
        // Every new character doubles the previous count
        dp[i] = 2 * dp[i - 1];

        if (lastIndex.find(ch) != lastIndex.end()) {
            dp[i] -= dp[lastIndex[ch] - 1];
        }

        // Update last occurrence of current character
        lastIndex[ch] = i;
    }

    return dp[n] - 1; // Exclude empty subsequence
    }
    
    
    string betterString(string str1, string str2) {
        if(count(str1) >= count(str2)) return str1;
        return str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends