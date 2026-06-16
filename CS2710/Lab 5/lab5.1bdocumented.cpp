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
    stack <long long int> v;
    //a stack for sstoring operands.
    for(size_t i=0;i<s.size();i++) {
        if(s[i]==' ') continue; // if character is a space then jumping to next iteration.
        if((s[i]>='0' && s[i]<='9')){ // if the character is a digit of a operand
            string temp;
            size_t j=i;//reading the string untill its not a digit.
            while(s[j]>='0'&&s[j]<='9'&&j<s.size()) {
               temp.push_back(s[j]);
               j++;
            }
            // now temp stores the value of a operand.
            int t=stoi(temp);
            //converting the string operand into integer.
            v.push(t);
            // pushing the integer to the operands stack. 
            i=j-1;// adjusting the index i such that we skip this integer.
        }
        else if (s[i]=='(') op.push('(');
        // if the character is open paranthesis push it into the op stack.
        else if (s[i]==')') {
            // if the character is a closed parenthesis then we need to perform the opeartions.
            while(op.top()!='(') { //do operations untill you encounter a open parenthesis.
                long long int a=v.top();
                v.pop();
                long long int b=v.top();
                v.pop();
                // take the top two elements from the operands stack v and pop them.
                if(op.top()=='*') {
                    v.push(a*b);
                }
                //if the operation is *, multiply and push it back into v.
                if 
                else if(op.top()=='-') {
                    v.push(b-a);
                }
                 //if the operation is -,subtract and push it back into v.
                else {
                    v.push(a+b);
                }
                 //if the operation is +, add and push it back into v.
                op.pop();
                // every time you do the  operation pop out the operator.
            }
            op.pop();
            // finally pop out the open parenthesis.
        }
        else if(s[i]=='*'||s[i]=='+'||s[i]=='-') {
            //if the character is a operator then we need to perform operation base on precedence.
            while((op.empty()!=true)) {
                if(precedence(op.top())==-1) break;
                //perform opeartions untill you encounter a character of less priority.
                else if(precedence(s[i])<=precedence(op.top()) ){
                long long int a=v.top();
                v.pop();
               long long int b=v.top();
                v.pop();
                //pop the top two operands from the stack v and store them.
                if(op.top()=='*') {
                    v.push(a*b);
                }
                 //if the operation is *, multiply and push it back into v.
                else if(op.top()=='-') {
                    v.push(b-a);
                }
                 //if the operation is -,subtract and push it back into v.
                else {
                    v.push(a+b);
                }
                 //if the operation is +, add and push it back into v.
                op.pop();
                 // every time you do the  operation pop out the operator.
                }
                else break;
            }
            op.push(s[i]);
            //finally push the current operator into the  op stack.
        }
    }
    // after iterating through the expression check whether op stack is empty or not
    // if empty we are done.
    while(op.empty()!=true) {
        // if op stack is non empty then we need to perform operations from the top untill stack becomes empty.
                long long int a=v.top();
                v.pop();
                long long int b=v.top();
                v.pop();
                //pop the top two operands from the stack v and store them.
                if(op.top()=='*') {
                    v.push(a*b);
                }
                //if the operation is *, multiply and push it back into v.
                else if(op.top()=='-') {
                    v.push(b-a);
                }
                //if the operation is -,subtract and push it back into v.
                else {
                    v.push(a+b);
                }
                //if the operation is +, add and push it back into v.
        op.pop();
        // every time you do the  operation pop out the operator.
    }
    cout<<v.top()<<endl;
    //finally v contains single element that is result of the expression so,print it.
}