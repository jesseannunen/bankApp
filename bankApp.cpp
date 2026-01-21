#include <iostream>
#include <string>

int main () {
    
    // create variables
    const std::string userName = "admin";
    const std::string passWord = "1234";
    std::string tryUserName;
    std::string tryPassWord;
    int choice = 0;
    double balance = 100;
    double deposit;
    double withdraw; 

    // take credentials from user
    std::cout << "Enter username: \n";
    std::cin >> tryUserName;
    std::cout << "Enter password: \n";
    std::cin >> tryPassWord;

    // check if credentials match
    if (userName == tryUserName && passWord == tryPassWord) {
        std::cout << "Login successful!\n";
        
        // while loop to keep app running if user takes other option than 4
        while (choice != 4) {
        
        //menu
        std::cout << "Choose option: \n";
        std::cout << "1) Show balance\n";
        std::cout << "2) Deposit\n";
        std::cout << "3) Withdraw\n";
        std::cout << "4) Log out\n";
        std::cout << "Enter option: \n";
        std::cin >> choice;
        
        // if statements
        if (choice < 1 || choice > 4) {
            std::cout << "Invalid option!" << "\n";
            choice = 0;
        }

        else if (choice == 1) {
            std::cout << "Your account balance is: " << balance << "\n";
        }
        else if (choice == 2) {
            std::cout << "Enter deposit amount: ";
            std::cin >> deposit;
            balance = balance + deposit;
            std::cout << "New balance is: " << balance << "\n";
        }

        else if (choice == 3) {
            std::cout << "Enter withdrawal amount: ";
            std:: cin >> withdraw;
            if (balance >= withdraw) {
            balance = balance - withdraw;
            std::cout << "New balance is: " << balance << "\n";
            }
            else {
                std::cout << "Insufficent funds";
            }
        }
        else if (choice == 4) {
            std::cout << "Logged out.";
        }
    }
}
    // if user does not give right credentials, program stops
    else {
        std::cout << "Wrong credentials!\n";
    }
    

    return 0;
}
