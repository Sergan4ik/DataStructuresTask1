#include <iostream>
#include <queue>
#include <random>

using namespace std;

// Function to display the contents of all the queues
void displayQueues(const vector<queue<int>>& queues) {
    for (size_t i = 0; i < queues.size(); ++i) {
        cout << "Queue " << (i + 1) << ": ";
        queue<int> tempQueue = queues[i];
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
    cout << endl;
}

void testTask7() {
    int numQueues;
    cout << "Enter the number of queues: ";
    cin >> numQueues;

    vector<queue<int>> queues(numQueues);

    while (true) {
        // Display the contents of the queues
        displayQueues(queues);

        // Prompt for the number of items in the customer's cart
        int numItems;
        cout << "Enter the number of items in the customer's cart (or -1 to exit): ";
        cin >> numItems;

        if (numItems == -1) {
            break;
        }

        // Find the queue with the minimum length
        size_t minQueueIndex = 0;
        int minQueueSize = queues[0].size();

        for (size_t i = 1; i < queues.size(); ++i) {
            if (queues[i].size() < minQueueSize) {
                minQueueIndex = i;
                minQueueSize = queues[i].size();
            }
        }

        // Add the customer to the queue with the minimum length
        queues[minQueueIndex].push(numItems);

        // Simulate the service time and remove the served customers from the queues
        for (size_t i = 0; i < queues.size(); ++i) {
            if (!queues[i].empty()) {
                int& serviceTime = queues[i].front();
                serviceTime--;

                if (serviceTime == 0) {
                    queues[i].pop();
                }
            }
        }
    }

    cout << "Exiting the program." << endl;
}
