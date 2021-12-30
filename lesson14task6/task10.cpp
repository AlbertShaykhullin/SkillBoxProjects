#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>


std::vector<std::string> history;
std::mutex history_access;

void wait_for_Call(int time, std::string name){
    std::this_thread::sleep_for(std::chrono::seconds(time));
    std::cout << "Id:" << std::this_thread::get_id() << std::endl;

    std::cout << "RING ("<< name << ")" << std::endl;
    history_access.lock();
    history.push_back(name);
    history_access.unlock();
}

int main() {
    int time;
    std::cin >> time;
    std::string name;
    std::cin >> name;
    std::cout << "Id:" << std::this_thread::get_id() << std::endl;
    std::thread call(wait_for_Call,time, name);
    std::thread call2(wait_for_Call, 4, "Albert");
    call.detach();
    call2.detach();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    if(call.joinable())call.join();
    if(call2.joinable())call2.join();

    history_access.lock();
    std::cout << "Missed calls:\n";
    for (int i = 0; i < history.size(); i++)
    {
        std::cout << history[i] << std::endl;
    }
    history_access.unlock();
}