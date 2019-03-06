class Solution {
public:
    //压栈的操作
    void pushstack(stack<char>& s,string& str)
    {
        for(int i = 0;i<str.size();i++)
        {
            if(str[i] != '#')
                s.push(str[i]);
            else if(!s.empty() && str[i] == '#')
                s.pop();
        }
    }
    bool backspaceCompare(string S, string T) {
        //通过栈将s，t的字符压入栈，如果遇到“#”，栈顶出栈
        stack<char> s;
        stack<char> t;
        pushstack(s,S);
        pushstack(t,T);
        if(s.size() != t.size())
            return false;
        while(!s.empty())
        {
            if(s.top() != t.top())
                return false;
            s.pop();
            t.pop();
        }
        return true;
    }
};