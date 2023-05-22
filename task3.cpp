#include <iostream>
#include <stack>

using namespace std;

void printStack(const stack<int>& s) {
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void testTask3() {
    stack<int> allNumbersStack;
    stack<int> evenNumbersStack;
    stack<int> oddNumbersStack;

    int num = 0;
    char choice;

    while(num != -1) {
        cin >> num;
        if (num != -1)
            allNumbersStack.push(num);
    };

    stack<int> temp = allNumbersStack;

    while (!temp.empty()) {
        int currentNum = temp.top();
        temp.pop();

        if (currentNum % 2 == 0) {
            evenNumbersStack.push(currentNum);
        } else {
            oddNumbersStack.push(currentNum);
        }
    }

    cout << "All Numbers Stack: ";
    printStack(allNumbersStack);

    cout << "Even Numbers Stack: ";
    printStack(evenNumbersStack);

    cout << "Odd Numbers Stack: ";
    printStack(oddNumbersStack);
}