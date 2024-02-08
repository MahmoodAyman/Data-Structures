#include <bits/stdc++.h>
using namespace std;
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
string infix_to_postfix(string input)
{
    string output;
    stack<char> operators;
    for (auto &it : input)
    {
        if (isdigit(it))
        {
            output += it;
        }
        else
        {
            while (!operators.empty() and precedence(it) <= precedence(operators.top()) and precedence(it))
            {

                output += operators.top();
                operators.pop();
            }
            if (it == ')')
            {
                while (!operators.empty() and operators.top() != '(')
                {
                    output += operators.top();
                    operators.pop();
                }
                operators.pop();
                continue;
            }
            operators.push(it);
        }
    }
    // add remaining operators
    while (!operators.empty())
    {
        output += operators.top();
        operators.pop();
    }
    return output;
}
int main()
{
    string output, input;
    cin >> input;
    output = infix_to_postfix(input);
    cout << output << endl;
}