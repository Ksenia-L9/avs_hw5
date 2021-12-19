#ifndef AVS_HW5_CUSTOMER_H
#define AVS_HW5_CUSTOMER_H

#include <string>
#include "Department.h"

// Customer - сущность, отражающая покупателя.
// В покупателе хранится список продуктов в виде массива строк.
struct Customer {
public:
    std::string *shoppingList;
    int numberOfItems;
    int counter;

    Customer();
    explicit Customer(int numberOfItems);

    // Метод для генерации случайного списка продуктов.
    void generateRandomList();

    // Метод для осуществления покупки.
    static void buy(Department *vegDepartment, Department *frDepartment, Customer *current) {
        while (current->counter != current->numberOfItems) {
            if (current->shoppingList[current->counter] == "fruit") {
                frDepartment->sells(current->counter);
                ++current->counter;
            }

            if (current->shoppingList[current->counter] == "vegetable") {
                vegDepartment->sells(current->counter);
                ++current->counter;
            }
        }
    }

    ~Customer();
};

#endif //AVS_HW5_CUSTOMER_H
