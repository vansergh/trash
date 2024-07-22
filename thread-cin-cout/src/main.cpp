#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

using namespace std;

class Task {
public:
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;
    Task& operator=(Task&&) = delete;

    Task() :
        started_{ false }
    {

    }

    Task(std::function<void()>&& operation) :
        started_{ false },
        operation_{ std::move(operation) }
    {

    }

    ~Task() {
        Stop();
    }

    void Start(bool async = false) {
        if (!started_) {
            started_ = true;
            task_ = std::thread(
                [&]() {
                    while (started_) {
                        operation_();
                    }
                }
            );
            if (async) {
                task_.detach();
            }
            else {
                task_.join();    
            }
            
        }
    }

    void RunOnce() {
        operation_();
    }

    void Stop() {
        started_ = false;
    }

    void Assign(std::function<void()>&& operation) {
        operation_ = std::move(operation);
    }

private:
    std::atomic<bool> started_{ false };
    std::thread task_;
    std::function<void()> operation_;
};

void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

int main() {
    int i{ 0 };


    Task display;
    display.Assign(
        [&]() {
            Clear();
            cout << "--------------\n";
            cout << "i = " << i << '\n';
            cout << "--------------\n";
            cout << "1. Start counting...\n";
            cout << "2. Stop counting!\n";
            cout << "3. Refresh\n";
            cout << "4. Exit\n";
            cout << "--------------\n";
            cout << "cmd> ";
        }
    );

    Task work;
    work.Assign(
        [&]() {
            display.RunOnce();
            ++i;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    );    

    Task input;
    input.Assign(
        [&]() {
            char cmd;
            bool read = true;
            display.RunOnce();
            while ((cin >> cmd) && read) {
                display.RunOnce();
                switch (cmd) {
                    case '1':
                    {
                        work.Start(true);
                    }
                    break;
                    case '2':
                    {
                        work.Stop();
                    }
                    break;
                    case '3':
                    {
                        display.RunOnce();   
                    }
                    break;                    
                    case '4':
                    {
                        read = false;
                        work.Stop();
                        input.Stop();
                    }
                    break;
                }
                if (!read) {
                    break;
                }
            }
        }
    );

    input.Start();


    return 0;
}