#include<stack>
#include<iostream>
using namespace std;

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        if(n == 0)
            return true;
        if(A[0] == ')')
            return false;
        stack<char> s;
        for(int i = 0;i<n;i++)
        {
            if(A[i] != '(' && A[i] != ')')
                return false;
            else if(A[i] == '(')
                s.push(A[i]);
            else
            {
                if(s.empty())
                    return false;
                s.pop();
            }
        }
        if(!s.empty())
            return false;
        return true;
    }
};