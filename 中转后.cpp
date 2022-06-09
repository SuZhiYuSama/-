#include<iostream>
#include<string>
#include<stack>
using namespace std;
int prio(char op) {
    int priority;
    if (op == '*' || op == '/')
        priority = 2;
    if (op == '+' || op == '-')
        priority = 1;
    if (op == '(')
        priority = 0;
    if (op == '#')
        priority = -1;
    return priority;
}
bool Trans(string &str,string &str1) {
    stack<char> s;
    int i;
    for (i = 0; i<str.size(); i++) {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
            str1+=str[i];
        }
        else {
            if (s.empty())
                s.push(str[i]);
            else if (str[i] == '(')
                s.push(str[i]);
            else if (str[i] == ')') {
                while (s.top() != '(') {  
                    str1+= s.top();
                    s.pop();
                }
                s.pop();
            }
            else {
                while (prio(str[i]) <= prio(s.top())) {
                    str1+= s.top();
                    s.pop();
                    if (s.empty())
                        break;
                }
                s.push(str[i]);
            }
        }
    }
    while (!s.empty()&&s.top()!='#') {
        str1+= s.top();
        s.pop();
    }
    return true;
}
int main() {
    string infix;
    string postfix;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
    cin >> infix;
    Trans(infix,postfix);
    cout << postfix << endl;
    postfix="\0";
	}
    return 1;
}
