#include <iostream>
#include <cstdlib> 
#include <ctime>  
bool isguessedinput(const std::string& str, int& number);
int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int requiredNumber = std::rand()%100+1;
    int userGuess=0;
    bool Correct= false;
    std::string input;
    std::cout<<"Welcome to the Number Guessing Game!\n";
    std::cout<<"I have already selected a number between 1 and 100. Try to guess it.\n";

    while (!Correct) {
        std::cout << "Enter the guess: ";
        std::getline(std::cin, input);
        if (isguessedinput(input, userGuess)) {
            if (userGuess<requiredNumber) {
                std::cout<<"Too low! Try again.\n";
            } else if (userGuess>requiredNumber) {
                std::cout<<"Too high! Try again.\n";
            } else {
                std::cout<<"Congratulations! You guessed the right one.\n";
                Correct = true;
            }
        } else {
            std::cout<<"Error, Please enter a valid number.\n";
        }
    }
    return 0;
}
bool isguessedinput(const std::string& str, int& number) {
    try {
        size_t pos;
        number = std::stoi(str, &pos);
        return pos == str.length();
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
}
