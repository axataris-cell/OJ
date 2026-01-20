#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    const int width = 30;

	srand(time(nullptr));
    for (int i = 0; i <= 100; i++) {
        int filled = i * width / 100;

        cout << "\r[";
        for (int j = 0; j < width; j++) {
            cout << (j < filled ? '#' : ' ');
        }
        cout << "] " << i << "%" << flush;

        this_thread::sleep_for(chrono::milliseconds(31 + rand() % 67));
    }

    cout << "\nDone!\n";
}
