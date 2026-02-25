#include <iostream> //object oriented alternative to stdio.h in C
#include <queue>

using namespace std;

int main() {
    //queue of integers
    queue<int> numbers;

    numbers.push(20);
    numbers.push(12);
    
    cout << "Front element: " <<numbers.front() << endl; //cout displays output to the console, the c in cout stands for character
    cout << "Rear element: " <<numbers.back() << endl;

    //remove elements from the queue (dequeue)
    numbers.pop();
    cout << "Front element after pop: " << numbers.front() << endl; //endl inserts a newline character and flushes the buffer

    cout << "Queue size: " << numbers.size() << std::endl;
    cout << "Is the queue empty? " << (numbers.empty() ? "Yes" : "No") << endl;

    return 0;




}

