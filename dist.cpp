#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(int a[], int size) {
    for (int i = 0; i < size; i++)
        cout << "[" << a[i] << "]";
    cout << endl;
}

int find(int a[], int size, int value) {
    for (int i = 0; i < size; i++)
        if (a[i] == value)
            return i;
    return -1;
}

int main() {
    const int Roll_Count = 1000;
    srand(time(0));
    int tracker[2][11] = { {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, {0} };

    for (int i = 0; i < Roll_Count; i++) {
        int d1 = rand() % 6 + 1;
        int d2 = rand() % 6 + 1;
        int index = find(tracker[0], 11, d1 + d2);
        if (index != -1)
            tracker[1][index]++;
    }

    cout << "Roll: ";
    print(tracker[0], 11);

    cout << "Count: ";
    print(tracker[1], 11);
    return 0;
}
