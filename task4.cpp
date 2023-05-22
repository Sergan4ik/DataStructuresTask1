#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void printSet(const unordered_set<int>& set) {
    for (int num : set) {
        cout << num << " ";
    }
    cout << endl;
}

unordered_set<int> setUnion(const vector<int>& set1, const vector<int>& set2) {
    unordered_set<int> resultSet(set1.begin(), set1.end());
    resultSet.insert(set2.begin(), set2.end());
    return resultSet;
}

unordered_set<int> setIntersection(const vector<int>& set1, const vector<int>& set2) {
    unordered_set<int> resultSet;
    unordered_set<int> set1Set(set1.begin(), set1.end());

    for (int num : set2) {
        if (set1Set.count(num) > 0) {
            resultSet.insert(num);
        }
    }

    return resultSet;
}

unordered_set<int> setComplement(const vector<int>& universalSet, const vector<int>& set) {
    unordered_set<int> resultSet(universalSet.begin(), universalSet.end());

    for (int num : set) {
        resultSet.erase(num);
    }

    return resultSet;
}

unordered_set<int> setDifference(const vector<int>& set1, const vector<int>& set2) {
    unordered_set<int> resultSet(set1.begin(), set1.end());

    for (int num : set2) {
        resultSet.erase(num);
    }

    return resultSet;
}

unordered_set<int> setSymmetricDifference(const vector<int>& set1, const vector<int>& set2) {
    unordered_set<int> resultSet;

    for (int num : set1) {
        if (resultSet.count(num) == 0 && count(set2.begin() , set2.end() , num) == 0) {
            resultSet.insert(num);
        }
    }

    for (int num : set2) {
        if (resultSet.count(num) == 0 && count(set1.begin() , set1.end() , num) == 0) {
            resultSet.insert(num);
        }
    }

    return resultSet;
}

void testTask4() {
    vector<int> set1 = {1, 2, 3, 4, 5};
    vector<int> set2 = {4, 5, 6, 7, 8};

    // Set Union
    unordered_set<int> unionSet = setUnion(set1, set2);
    cout << "Set Union: ";
    printSet(unionSet);

    // Set Intersection
    unordered_set<int> intersectionSet = setIntersection(set1, set2);
    cout << "Set Intersection: ";
    printSet(intersectionSet);

    vector<int> universalSet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Set Complement
    unordered_set<int> complementSet = setComplement(universalSet, set1);
    cout << "Set Complement (set1): ";
    printSet(complementSet);

    // Set Difference
    unordered_set<int> differenceSet = setDifference(set1, set2);
    cout << "Set Difference (set1 - set2): ";
    printSet(differenceSet);

    // Set Symmetric Difference
    unordered_set<int> symmetricDifferenceSet = setSymmetricDifference(set1, set2);
    cout << "Set Symmetric Difference: ";
    printSet(symmetricDifferenceSet);

}
