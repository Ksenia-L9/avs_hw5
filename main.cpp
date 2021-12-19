#include <iostream>
#include <thread>
#include "Customer.h"
#include "Department.h"

int main() {
    std::srand(time(0));

    std::cout << "If random generation is needed, enter -1.\n";
    std::cout << "Enter the number of customers: ";

    // Вводим число покупателей.
    int input = 0;
    std::cin >> input;
    std::cout << std::endl;

    int numberOfCustomers;
    Customer **customers;

    // Валидация числа покупателей.
    if (input == 0) {
        std::cout << "Incorrect input.";
        return 1;
    } else if (input == -1) {
        // Ветка с рандомной генерацией покупателей и их списокв продуктов.
        numberOfCustomers = rand() % 100 + 1;
        customers = new Customer *[numberOfCustomers];

        for (int i = 0; i < numberOfCustomers; ++i) {
            customers[i] = new Customer();
            customers[i]->generateRandomList();
        }
    } else {
        // Ветка, где информацию о покупателях вводит пользователь.
        numberOfCustomers = input;
        customers = new Customer *[numberOfCustomers];

        for (int i = 0; i < numberOfCustomers; ++i) {
            std::cout << "Enter the number of items in the list: ";
            int numberOfItems = 0;
            std::cin >> numberOfItems;

            if (numberOfItems == 0) {
                std::cout << "Incorrect input.";
                return 1;
            } else {
                customers[i] = new Customer(numberOfItems);

                std::cout << "Enter each item of shopping list in a new line. Available items: fruit, vegetable.\n";

                for (int j = 0; j < numberOfItems; ++j) {
                    std::string string;
                    std::cin >> string;

                    if (string != "fruit" && string != "vegetable") {
                        std::cout << "Incorrect input.";
                        return 1;
                    }

                    customers[i]->shoppingList[j] = string;
                }
            }
        }
    }

    // Инициализация потоков.
    auto **processingCustomers = new std::thread*[numberOfCustomers];
    auto *vegetableDepartment = new Department("Vegetable");
    auto *fruitDepartment = new Department("Fruit");
    for (int i = 0; i < numberOfCustomers; ++i) {
        processingCustomers[i] = new std::thread(Customer::buy, vegetableDepartment, fruitDepartment, customers[i]);
    }

    // Закрытие потоков.
    for (int i = 0; i < numberOfCustomers; ++i) {
        processingCustomers[i]->join();
    }

    // Очистка ресурсов программы.
    delete[] processingCustomers;
    delete[] customers;
    delete vegetableDepartment;
    delete fruitDepartment;

    return 0;
}