#include <iostream>
#include <cmath>

bool validation() {
    if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid entry." << std::endl;
        return false;
    } else {
        return true;
    }
}


int atomic_number_input() {
    bool checker = false;
    int atomic_number;
    while (checker == false) {
        std::cout << "Please enter the atomic number." << std::endl;
        std::cin >> atomic_number;
        checker = validation();
    }
    return atomic_number;
}


int main() {

    int atomic_number = atomic_number_input();
    std::cout << "The atomic number is " << atomic_number << std::endl;
}