//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
        int first = 0, second = 0;
        for(char x : S) {
            int y = x-'a';
            if(((first>>y) & 1)) 
                second |= (1<<y);
            first |= (1<<y);
        }
        
        for(char x:S) {
            int y = second>>(x-'a');
            if((y&1) == 0) 
                return x;
        }
        return '$';
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends
