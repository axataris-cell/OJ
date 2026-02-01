#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    const string text = "Loading";

    while (true) {
        for (char c : text) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(150));
        }

        this_thread::sleep_for(chrono::milliseconds(500));

        for (int i = 0; i < text.size(); i++) {
            cout << '\b' << ' ' << '\b' << flush;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
}
