#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &allocation, vector<vector<int>> &need, vector<int> &available) {
    int numProcesses = allocation.size();
    int numResources = available.size();

    vector<bool> finish(numProcesses, false);
    vector<int> work = available;
    vector<int> safeSequence;

    for (int count = 0; count < numProcesses; count++) {
        bool found = false;

        for (int i = 0; i < numProcesses; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < numResources; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int j = 0; j < numResources; j++) {
                        work[j] += allocation[i][j];
                    }
                    safeSequence.push_back(i);
                    finish[i] = true;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "The system is not in a safe state.\n";
            return false;
        }
    }

    cout << "The system is in a safe state. Safe sequence: ";
    for (int i : safeSequence) {
        cout << i << " ";
    }
    cout << endl;

    return true;
}

int main() {
    int numProcesses, numResources;

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    cout << "Enter the number of resources: ";
    cin >> numResources;

    vector<vector<int>> allocation(numProcesses, vector<int>(numResources));
    vector<vector<int>> maximum(numProcesses, vector<int>(numResources));
    vector<vector<int>> need(numProcesses, vector<int>(numResources));
    vector<int> available(numResources);

    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter the maximum matrix:\n";
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> maximum[i][j];
        }
    }

    cout << "Enter the available resources:\n";
    for (int i = 0; i < numResources; i++) {
        cin >> available[i];
    }

    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    isSafe(allocation, need, available);

    return 0;
}
