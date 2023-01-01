// LeetCode 150

class Solution
{
public:
#define ll long long
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<ll> st;
        for (auto i : tokens)
        {
            if (i == "+")
            {
                ll a = st.top();
                st.pop();
                ll b = st.top();
                st.pop();
                st.push(a + b);
            }
            else if (i == "-")
            {
                ll a = st.top();
                st.pop();
                ll b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if (i == "*")
            {
                ll a = st.top();
                st.pop();
                ll b = st.top();
                st.pop();
                st.push(a * b);
            }
            else if (i == "/")
            {
                ll a = st.top();
                st.pop();
                ll b = st.top();
                st.pop();
                st.push(b / a);
            }
            else
                st.push(stoi(i));
        }
        return (int)st.top();
    }
};