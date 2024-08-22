#include <iostream>
#include <mutex>
#include <thread>
/*
    withdraw: withdraw take 10 units of money from amount .
    deposit: adds 10units of money to account.

    Run Withdraw and Deposit BOTH for 100Times Each On an initial amount of 1000

    what will be the final amount after 200 trasactions are completed?
*/

int amount = 1000;
std::mutex m1;

void withdraw()
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        m1.lock();
        amount -= 10;
        m1.unlock();
    }
}

void deposit() {
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        m1.lock();
        amount += 10;
        m1.unlock();
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(&withdraw);
    std::thread t2(&deposit);

    t1.join();
    t2.join();

    std::cout << "Amount is: " << amount << "\n";
    return 0;
}

