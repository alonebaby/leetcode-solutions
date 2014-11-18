/*
 Author:     JIFANG FAN
 Date:       Nov 18, 2014
 Problem:   numDistinct
 Source:     https://oj.leetcode.com/problems/distinct-subsequences/
 Notes:
 Implement decode ways solution
 Method1: Time Complexity O(n^2), Space Complexity O(n)
 Method2: Time Complexity O(n^2), Space Complexity O(n^2)
 */


class Solution {
public:

    int numDistinct(string S, string T) {
         if(T.length() > S.length())
            return 0;
         vector<int> m(T.length()+1);
         m[0]=1;

         for(int i=1; i<=S.length(); i++)
            for(int j=T.length(); j>=1; j--)
                if(S[i-1] == T[j-1])
                    m[j]=m[j-1]+m[j];

         return m[T.length()];
    }
    
    //method2 dp Time O(n^2),Space O(n^2)
    int numDistinct2(string& S, string& T){
         if(T.length() > S.length())
            return 0;
         vector<vector<int> >  match(S.length()+1,vector<int>(T.length()+1,0));
         match[0][0]=1;
         for(int i=1; i<=S.length(); i++)
            for(int j=1; j<=T.length(); j++)
            {
                if(S[i-1] == T[j-1])
                   match[i][j] = match[i-1][j-1] + match[i-1][j];
                else
                   match[i][j] = match[i-1][j];
             }
    
          return match[S.length()][T.length()];
    }
};
