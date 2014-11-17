/*
 Author:     JIFANG FAN
 Date:       Nov 17, 2014
 Problem:    Sqrt(n)
 Source:     https://oj.leetcode.com/problems/decode-ways/
 Notes:
 Implement decode ways solution
 Time Complexity O(n), Space Complexity O(1)
 */
 
 class Solution {
public:
    int numDecodings(string s) {
         if(s.length() == 0)
            return 1;

          int position;
          int cache0=1,cache1=0,cache2=0;

          for(position=s.length()-1; position>=0; position--)
          {
             cache2=cache1;
             cache1=cache0;
             cache0 = 0;
             if(position + 0 < s.length())
             {
               char ch = s.at(position);
               if((ch >='1')&&(ch<='9'))
                 cache0 += cache1;
             }

            if(position + 1 < s.length())
            {
               char ch1 = s.at(position+0);
               char ch2 = s.at(position+1);
               if(ch1 == '1')
                  cache0 += cache2;
               else if ((ch1 == '2')&&(ch2 >='0' && ch2 <= '6'))
                  cache0 += cache2;
             }
          }

         return cache0;
    }
};
