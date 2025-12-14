#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    const char spinner[] = {'|', '/', '-', '\\'};

    for (int i = 0; i < 100; i++) {
        cout << "\rLoading " << spinner[i % 4] << flush;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "\rDone!     \n";
}
