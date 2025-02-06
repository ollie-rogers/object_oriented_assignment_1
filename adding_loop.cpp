#include <iostream>
#include <cmath>

bool validation_check(int input_value, int i, int saved_value) {
    // if fail to assign the input to the integer variable, input must not be an integer
    if (std::cin.fail()) {
        std::cin.clear(); // reset error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discards invalid input 
        std::cout << "Invalid entry." << std::endl; // prints that the input is not valid
        return false; // returns false such that loop does not break
    } else if (input_value < 1) { // if the atomic, initial or final number is less than one
        std::cout << "Invalid entry. Please enter a number greater than zero." << std::endl;
        return false; // prints that its invalid and states why, returns false so loop doesnt break
    // 3 means its the final number input, and if its less than the initial itll be invalid
    } else if (i == 3 && saved_value <= input_value) {
        std::cout << "Invalid entry. Please enter a quantum number lower than the intial quantum number." << std::endl;
        // prints error message saying that the entry is invalid and why
        return false; // returns false such that loop does not break
    }
    else {
        return true; 
        // if there are none of these errors, the input is a valid integer, breaks loop
    }
    return false;
}

bool all_strings_validator(std::string input_string, int i) {
    // validates any of the string inputs "J", "e", "y" or "n"
    if (i = 1) { // if we are asking for the choice of units
        if (input_string == "J" || input_string == "e") { // if the input is either exactly J or e
            return true; // its valid, will break loop
        } else { // if the input is not either J or e prints error message
            std::cout << "Invalid input. Please make sure your entry is of the form stated." << std::endl;
            return false;  // input isnt valid, won't break loop
        }
    } else if (i=2) { // if we are asking whether to repeat process
        if (input_string == "y" || input_string == "n") { // if the input is either exactly y or n
            return true; // its valid, will break loop
        } else { // if the input is not exaclty y or n prints error message
            std::cout << "Invalid input. Please make sure your entry is of the form stated." << std::endl;
            return false; // its not valid, wont break loop
        }
    }
}

int input_function(int i, int saved_value) { // function to take inputs for atomic, initial and final nums
    bool checker = false; // boolean variable so we keep looping until the input is of the right form
    int input_value; // variable to store the value the user inputs
     // creating a string which is changed depending on which type of number we are inputting
    std::string input_word; 
    if (i == 1) { // if its the atomic number 
        input_word = "atomic"; 
    } else if (i == 2) { // if its the initial quantum number
        input_word = "initial quantum";
    } else if (i == 3) { // if its the final quantum number
         input_word = "final quantum";
    } 
    // loop which keeps asking user for a correct input until a valid input is given
    while (checker == false) { 
        // asking the user to input the desired number
        std::cout << "Please enter the " << input_word << " number" << std::endl; 
        std::cin >> input_value; // storing the input in an integer variable
        // next perform a validation check which breaks loop if pass and doesnt if fail
        checker = validation_check(input_value, i, saved_value); 
    }
    return input_value; // returns the valid input for the desired number
}

std::string choose_units() {
    bool checker_4 = false; // create another checker variable
    std::string choice_units; // create a string variable which will store the users choice of J or eV
    // while loop to repeat inputs until the choice of units is in the right form J or e
    while (checker_4 == false) { 
        std::cout << "Would you like to see the energy in Joules (type J) or electronvolts (type e)?" << std::endl;
        std::cin >> choice_units; // assign input to variable
        // validating the entry, 1 is to know we are validating unit choice not loop choice
        checker_4 = all_strings_validator(choice_units, 1); 
    }
    if (choice_units == "e") {
        choice_units = "eV"; // assigning the choice of units variable to what I actually want to print
    }
    return choice_units; // returns the actual choice in the form we want to print
}

float calculation_func(int Z, int n_i, int n_f, std::string option) {
    float energy_value; // creating a variable to store the result in
    if (option == "J") { // calculating energy in Joules if the choice was J
        energy_value = 13.6*pow(Z,2)*(1/pow(n_f,2) - 1/pow(n_i,2))*1.6*pow(10,-19);
    } else if (option == "eV") { // calculating the energy in eV if the choice was e
        energy_value = 13.6*pow(Z,2)*(1/pow(n_f,2) - 1/pow(n_i,2));
    }
    return energy_value; // returning the calculated energy
}

int main() {
    bool loop = false;
    while (loop == false) {
        int place_holder = 0; // variable for when second variable in input function not needed
        // taking and validating all required numerical inputs. integers are to print the right string
        int atomic_num = input_function(1, place_holder);
        int initial_num = input_function(2, place_holder); 
        int final_num = input_function(3, initial_num); 
        std::cout << "You entered:" << std::endl; // printing what the user input
        std::cout << "Atomic number: " << atomic_num << std::endl; // so the user can check its right
        std::cout << "Initial quantum number: " << initial_num << std::endl;
        std::cout << "Final quantum number " << final_num << std::endl;
        // takes the user input for their choice of units and validates input
        std::string choice = choose_units(); 
        // calculating the energy in J or eV
        float energy = calculation_func(atomic_num, initial_num, final_num, choice);
        // printing final results
        std::cout << "The energy is " << energy << " " << choice << std::endl;
    }
}