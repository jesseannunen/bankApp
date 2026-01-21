#include <iostream>
#include <string>

class User {
    public:
        std::string userName;        
        std::string passWord;        
        double balance;
        
        //constructor
        User(std::string x, std::string y, double z) {
            userName = x;
            passWord = y;
            balance = z;
        }
        // method to check login
        bool checkLogin (std::string inputName, std::string inputPassword) {
            if (userName == inputName && passWord == inputPassword) {
                return true;
            }
            else {
                return false;
            }

        }
        void showBalance () {
            std::cout << "Your account balance is : " << balance; 
        }
        void deposit (double amount) {
            balance = balance + amount;
        }
        bool withdraw(double amount) {
            if (amount <= balance) {
                balance = balance - amount;
                return true;
            }
            else {
                std::cout << "Insufficent funds";
                return false;
            }
        }
};

int main () {
  
    // create variables
    std::string tryUserName;
    std::string tryPassWord;
    int choice = 0;
    double depositAmount;
    double withdrawAmount; 

    User admin("admin", "1234", 100);

    // take credentials from user
    std::cout << "Enter username: \n";
    std::cin >> tryUserName;
    std::cout << "Enter password: \n";
    std::cin >> tryPassWord;

    // check if credentials match
    if (admin.checkLogin(tryUserName, tryPassWord)) {
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
            std::cout << "Your account balance is: " << admin.balance << "\n";
        }
        else if (choice == 2) {
            std::cout << "Enter deposit amount: ";
            std::cin >> depositAmount;
            admin.deposit(depositAmount);
            std::cout << "Deposit successful.\n" << "New balance is: " << admin.balance << "\n";
        }

        else if (choice == 3) {
            std::cout << "Enter withdrawal amount: ";
            std:: cin >> withdrawAmount;
            if (admin.withdraw(withdrawAmount)) {
            std::cout << "Withdrawal succesful.\n " << "New balance is: " << admin.balance << "\n";
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
