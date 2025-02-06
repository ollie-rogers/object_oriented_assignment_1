#include <iostream>
#include <cmath>

bool validation_check(int input_value, int i, int saved_value) {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid entry." << std::endl;
        return false;
    } else if (input_value < 1) {
        std::cout << "Invalid entry. Please enter a number greater than zero." << std::endl;
        return false;
    } else if (i == 3 && saved_value <= input_value) {
        std::cout << "Invalid entry. Please enter a quantum number lower than the intial quantum number." << std::endl;
        return false;
    }
    else {
        return true;
    }

    return false;
}

int input_function(int i, int saved_value) {
    
    bool checker = false;
    int input_value;
    std::string input_word;  // creates a string variable
    if (i == 1) {
        input_word = "atomic";
    } else if (i == 2) {
        input_word = "initial quantum";
    } else if (i == 3) {
         input_word = "final quantum";
    } 
    while (checker == false) {  
        std::cout << "Please enter the " << input_word << " number" << std::endl;
        std::cin >> input_value;
        checker = validation_check(input_value, i, saved_value);
    }
    return input_value;
}

std::string choose_units() {
    std::string choice_units;
    std::cout << "Would you like to see the energy in Joules (type J) or electronvolts (type e)?" << std::endl;
    std::cin >> choice_units;
    return choice_units;
}

float calculation_func(int Z, int n_i, int n_f, std::string option) {
    float energy_value;
    if (option == "J") {
        energy_value = 13.6*pow(Z,2)*(1/pow(n_f,2) - 1/pow(n_i,2))*1.6*pow(10,-19);
    } else if (option == "e") {
        energy_value = 13.6*pow(Z,2)*(1/pow(n_f,2) - 1/pow(n_i,2));
    }
    return energy_value;
}

int main() {

    int place_holder = 0;
    int atomic_num = input_function(1, place_holder);
    int initial_num = input_function(2, place_holder);
    int final_num = input_function(3, initial_num);
    std::cout << "You entered:" << std::endl;
    std::cout << "Atomic number: " << atomic_num << std::endl;
    std::cout << "Initial quantum number: " << initial_num << std::endl;
    std::cout << "Final quantum number " << final_num << std::endl;
    std::string choice = choose_units();
    float energy = calculation_func(atomic_num, initial_num, final_num, choice);
    std::cout << "The energy is " << energy << std::endl;
}