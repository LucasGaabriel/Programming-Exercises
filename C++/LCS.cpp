#include <iostream>

using namespace std;

string longest_common_subsequence(string s, string t){
    int m = s.size();
    int n = t.size();

    int dp[m+1][n+1] = {0};
    
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs = "";

    int i=m;
    int j=n;

    while(i > 0 and j > 0){
        if(s[i - 1] == t[j - 1]){
            lcs = s[i - 1] + lcs;

            i -= 1;
            j -= 1;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i -= 1;
        }
        else {
            j -= 1;
        }
    }

    return lcs;
}

int main(){
    string s, t;
    cin >> s >> t;
    cout << longest_common_subsequence(s, t) << endl;
    return 0;
}