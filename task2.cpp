#include <iostream>
#include <list>
using namespace std;
void swapElements(list<int>& list1, list<int>& list2, int k) {
    if (k < 0 || k >= distance(list1.begin(), list1.end()) || k >= distance(list2.begin(), list2.end())) {
        cout << "Invalid index" << endl;
        return;
    }

    list<int>::iterator it1 = list1.begin();
    list<int>::iterator it2 = list2.begin();
    advance(it1, k);
    advance(it2, k);

    if (*it1 != *it2) {
        iter_swap(it1, it2);
    }

    cout << "Lists after swapping: " << endl;
    cout << "List 1: ";
    for (int num : list1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "List 2: ";
    for (int num : list2) {
        cout << num << " ";
    }
    cout << endl;
}

list<int> combineLists(const list<int>& list1, const list<int>& list2) {
    list<int> combinedList = list1;
    combinedList.insert(combinedList.end(), list2.begin(), list2.end());
    return combinedList;
}

pair<list<int>, list<int>> splitList(const list<int>& list) {
    int size = distance(list.begin(), list.end());
    int mid = size / 2;

    ::list<int> list1(list.begin(), next(list.begin(), mid));
    ::list<int> list2(next(list.begin(), mid), list.end());

    return make_pair(list1, list2);
}

list<int> copyList(const list<int>& list) {
    return ::list<int>(list);
}

void testTask2(){
    list<int> list1 = {1, 2, 3, 4, 5};
    list<int> list2 = {6, 7, 8, 9, 10};

    int k = 2;

    swapElements(list1, list2, k);
    list<int> combinedList = combineLists(list1, list2);
    cout << "Combined List: ";
    for (int num : combinedList) {
        cout << num << " ";
    }
    cout << endl;

    pair<list<int>, list<int>> splitLists = splitList(combinedList);
    cout << "Split List 1: ";
    for (int num : splitLists.first) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Split List 2: ";
    for (int num : splitLists.second) {
        cout << num << " ";
    }
    cout << endl;

    list<int> copiedList = copyList(list1);
    cout << "Copied List: ";
    for (int num : copiedList) {
        cout << num << " ";
    }
    cout << endl;
}

