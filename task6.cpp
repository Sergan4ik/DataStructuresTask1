#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string& infixExpression) {
    stack<char> operatorStack;
    string postfixExpression;

    for (char c : infixExpression) {
        if (isdigit(c) || isalpha(c)) {
            postfixExpression += c;
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();
            }
        } else {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfixExpression += operatorStack.top();
        operatorStack.pop();
    }

    return postfixExpression;
}

double evaluatePostfix(const string& postfixExpression) {
    stack<double> operandStack;

    unordered_map<char, function<double(double, double)>> operators = {
            {'+', [](double a, double b) { return a + b; }},
            {'-', [](double a, double b) { return a - b; }},
            {'*', [](double a, double b) { return a * b; }},
            {'/', [](double a, double b) { return a / b; }},
    };

    for (char c : postfixExpression) {
        if (isdigit(c)) {
            operandStack.push(c - '0');
        } else {
            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();
            double result = operators[c](operand1, operand2);
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

void testTask6() {
    string infixExpression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    double result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;
}
