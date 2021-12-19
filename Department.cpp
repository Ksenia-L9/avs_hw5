#include <string>
#include "Department.h"

Department::Department(std::string string) {
    name = string;
    mutex = new std::mutex();
}

void Department::sells(int counter) {
    mutex->lock();
    std::cout << name + " salesperson is serving a customer.\n";
    std::cout << "Customer is getting product " << counter + 1 << ".\n";
    mutex->unlock();
}

Department::~Department() {
    delete mutex;
}