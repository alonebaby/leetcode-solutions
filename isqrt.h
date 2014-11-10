/*
 Author:     JIFANG FAN
 Date:       Nov 10, 2014
 Problem:    Sqrt(n)
 Source:     http://leetcode.com/onlinejudge#question_69
 Notes:
 Implement int sqrt(int n).
 Compute and return the square root of n.
 Solution: newton iteration method
           g(x+1)=(g(x)+n/g(x))/2
           g(x0) = 2^s >= √n
 time complexity O(1), space complexity O(1)
 */
class Solution {
public:
    int isqrt(int n) {
        int i=n;
        int s=1;
        if(i>65535)
        {
           s += 8;
           i = i>>16;
        }
        if(i>255)
        {
           s +=4;
           i = i>>8;
        }
        
        if(i>15)
        {
           s +=2;
           i = i>>4;
        }
        
        if(i>3)
        {
           s +=1;
        }
        
        int g0 = 1<<s;
        int g1 = (g0 +(n>>s))>>1;
        while(g1 < g0)
        {
            g0 = g1;
            g1 = (g0 + (n/g0))>>1;
         }

        return g0;
    }
};
