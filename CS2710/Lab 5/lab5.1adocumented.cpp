#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
//a precedence function which takes input as a character and gives its precedence
int precedence( char c) {
    if(c=='*') return 2; //among *,-,+ * has higher precedence so returning 2.
    if(c=='-'||c=='+') return 1;//if it is a -,+ then returning 1.
    return -1;// if it is some other character returning -1.
}
int main() {
    string s;
    getline(cin,s);
    // taking infix expression as a string using getline
    stack <char> op;
    //a stack for storing operators and parenthesis. 
    for(size_t i=0;i<s.size();i++) {
        if(s[i]==' ') continue; // if the character is a space just move to next character
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) cout<<s[i];
        // if the character is a operand print it.
        else if (s[i]=='(') op.push('(');
        // if the character is open paranthesis push it into the stack.
        else if (s[i]==')') {
            while(op.top()!='(') {
                cout<<op.top();
                op.pop();
            }
            op.pop();
        }
        // if character is a closed parenthesis then pop and print the top elements of stack untill you encounter a open parenthesis.
        else if(s[i]=='*'||s[i]=='+'||s[i]=='-') {
            //if the character is a operator then we need to check for precedence.
            while((op.empty()!=true)) {
                if(precedence(op.top())==-1) break;
                //if the top of the element of stack is not a operator then we need to just push the current operator
                else if(precedence(s[i])<=precedence(op.top()) ){
                    //if precedence of top element is greater than current operator then we need to print and pop it.
                cout<<op.top();
                op.pop();
                //repeat this untill you find a parenthesis or untill stack becomes empty
                }
                else break;
            }
            op.push(s[i]);// pushing the current operator.
        }
    } 
    //after iterating through the infix expression check whether stack is empty
    // if stack is empty then postfix expression is obtained.
    while(op.empty()!=true) {
        cout<<op.top();
        op.pop();
    }
    //if stack is not empty then pop and print the top elements untill stack becomes empty.
    cout<<endl;
}