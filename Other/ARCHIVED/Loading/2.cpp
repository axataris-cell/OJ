#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    cout << "Loading";

    for (int i = 0; i < 6; i++) {
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "\nDone!\n";
}
