#include <iostream>
#include <vector>

using namespace std;

void postorder(int left, int right, vector<int> &nodes) {
    if (left > right) //기저조건
        return;


    int idx = right + 1;
    for (int i = left; i <= right; i++) {
        if (nodes[i] > nodes[left]) {
            idx = i;
            break;
        }
    }

    postorder(left + 1, idx - 1, nodes);
    postorder(idx, right, nodes);
    cout << nodes[left] << '\n';
}

int main() {
    int input;
    vector<int> nodes;

    while (cin >> input)
        nodes.push_back(input);

    postorder(0, nodes.size() - 1, nodes);
}