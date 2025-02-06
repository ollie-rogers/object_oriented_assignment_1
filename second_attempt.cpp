#include <iostream>
#include <cmath>

bool validation(int value) {
    if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid entry." << std::endl;
        return false;
    } else { 
        if (value < 1) {
            std::cout << "Invalid entry." << std::endl;
            return false;
        }
        else {
            return true;
         }
    }
}


int atomic_number_input() {
    bool checker = false;
    int atomic_num;
    while (checker == false) {
        std::cout << "Please enter the atomic number." << std::endl;
        std::cin >> atomic_num;
        checker = validation(atomic_num);
    }
    return atomic_num;
}

int initial_qn_input() {
    bool checker_2 = false;
    int initial_num;
    while (checker_2 == false) {
        std::cout << "Please enter the initial quantum number." << std::endl;
        std::cin >> initial_num;
        checker_2 = validation(initial_num);
    }
    return initial_num;
}

int final_qn_input() {
    bool checker_3 = false;
    int final_num;
    while (checker_3 == false) {
        std::cout << "Please enter the final quantum number." << std::endl;
        std::cin >> final_num;
        checker_3 = validation(final_num);
    }
    return final_num;
}


int main() {
    int atomic_number = atomic_number_input();
    int initial_number = initial_qn_input();
    int final_number = final_qn_input();
    std::cout << "The atomic number is " << atomic_number << std::endl;
    std::cout << "The initial quantum number is " << initial_number << std::endl;
    std::cout << "The final quantum number is " << final_number << std::endl;
}