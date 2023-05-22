#include <iostream>
#include <stack>

using namespace std;

bool isMatching(char opening, char closing) {
    return (opening == '(' && closing == ')') || (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool isBalanced(const string& expression) {
    stack<char> parenthesesStack;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            parenthesesStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (parenthesesStack.empty() || !isMatching(parenthesesStack.top(), c)) {
                return false;
            }
            parenthesesStack.pop();
        }
    }

    return parenthesesStack.empty();
}

void testTask5() {
    string expression;
    cout << "Enter an expression with different types of parentheses: ";
    getline(cin, expression);

    if (isBalanced(expression)) {
        cout << "Parentheses are balanced." << endl;
    } else {
        cout << "Parentheses are not balanced." << endl;
    }
}
