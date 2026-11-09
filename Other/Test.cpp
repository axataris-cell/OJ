#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <atomic>

// Phan bi?t h? ?i?u hanh ?? ch?n th? vi?n Socket phu h?p
#if defined(_WIN32) || defined(_WIN64)
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
    typedef SOCKET socket_t;
    #define CLOSE_SOCKET closesocket
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    typedef int socket_t;
    #define CLOSE_SOCKET close
#endif

std::atomic<long> success_count(0);
std::atomic<long> fail_count(0);
std::atomic<bool> running(true);

void stress_worker(const std::string& target_ip, int port) {
    while (running) {
        socket_t sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            fail_count++;
            continue;
        }

        sockaddr_in server_addr{};
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        
        if (inet_pton(AF_INET, target_ip.c_str(), &server_addr.sin_addr) <= 0) {
            CLOSE_SOCKET(sock);
            fail_count++;
            continue;
        }

        if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
            success_count++;
            std::string request = "GET / HTTP/1.1\r\nHost: " + target_ip + "\r\nConnection: close\r\n\r\n";
            send(sock, request.c_str(), (int)request.length(), 0);
        } else {
            fail_count++;
        }

        CLOSE_SOCKET(sock);
    }
}

int main() {
    // Kh?i t?o Winsock tren Windows
#if defined(_WIN32) || defined(_WIN64)
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup that bai.\n";
        return 1;
    }
#endif

    std::string target_ip = "192.168.110.247";
    int port = 80;
    int num_threads = 500;

    std::cout << "Dang bat dau stress test toi " << target_ip << ":" << port << " voi " << num_threads << " luong...\n";
    std::cout << "Nhan phim [Enter] de dung lai.\n\n";

    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(stress_worker, target_ip, port);
    }

    std::cin.get();
    running = false;

    for (auto& th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }

    // D?n d?p Winsock tren Windows
#if defined(_WIN32) || defined(_WIN64)
    WSACleanup();
#endif

    std::cout << "\n--- Ket qua thong ke ---\n";
    std::cout << "Tong so ket noi thanh cong: " << success_count << "\n";
    std::cout << "Tong so ket noi that bai: " << fail_count << "\n";
    
    system("pause");

    return 0;
}
