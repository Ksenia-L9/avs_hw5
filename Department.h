#ifndef AVS_HW5_DEPARTMENT_H
#define AVS_HW5_DEPARTMENT_H

#include <mutex>
#include <iostream>

// Department - сущность, отражающая отдел магазина.
struct Department {
private:
    std::mutex *mutex;
    std::string name;
public:
    Department(std::string string);

    // Функция олицетворяет продавца.
    void sells(int counter);

    ~Department();
};

#endif //AVS_HW5_DEPARTMENT_H
