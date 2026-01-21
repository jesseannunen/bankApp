#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class User
{
public:
    std::string userName;
    std::string passWord;
    double balance;

    // constructor
    User(std::string x, std::string y, double z)
    {
        userName = x;
        passWord = y;
        balance = z;
    }
    // method to check login
    bool checkLogin(std::string inputName, std::string inputPassword)
    {
        if (userName == inputName && passWord == inputPassword)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //method to show balance
    void showBalance()
    {
        std::cout << "Your account balance is : " << balance;
    }
    void deposit(double amount)
    {
        balance = balance + amount;
    }
    bool withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            return true;
        }
        else
        {
            std::cout << "Insufficent funds";
            return false;
        }
    }
};

int main()
{   
    std::vector<User> users;
    
    //open file
    std::ifstream myFile("users.txt");
    // does file open ?
    if (!myFile) {
        std::cout << "error\n";
        return 1;
    }

    std::string name, password;
    double balance;

     //add users from users.txt with push.back
    while (myFile >> name >> password >> balance) {
        users.push_back(User(name, password, balance));
    }
    myFile.close();


    // create variables
    std::string tryUserName;
    std::string tryPassWord;
    int choice = 0;
    double depositAmount;
    double withdrawAmount;

    // take credentials from user
    std::cout << "Enter username: \n";
    std::cin >> tryUserName;
    std::cout << "Enter password: \n";
    std::cin >> tryPassWord;

    // check if credentials match
    bool loggedIn = false;
    int currentUserIndex = -1;

    // check users with for loop 
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].checkLogin(tryUserName, tryPassWord))
        {
            loggedIn = true;
            currentUserIndex = i;
            break;
        }
    }

    if (loggedIn)
    {
        std::cout << "Login succesful! \n";
        
        // while loop to keep app running if user takes other option than 4
        while (choice != 4)
        {

            // menu
            std::cout << "Choose option: \n";
            std::cout << "1) Show balance\n";
            std::cout << "2) Deposit\n";
            std::cout << "3) Withdraw\n";
            std::cout << "4) Log out\n";
            std::cout << "Enter option: \n";
            std::cin >> choice;

            // if statements
            if (choice < 1 || choice > 4)
            {
                std::cout << "Invalid option!" << "\n";
                choice = 0;
            }

            else if (choice == 1)
            {
                users[currentUserIndex].showBalance();
                std::cout <<"\n";
            }
            else if (choice == 2)
            {
                std::cout << "Enter deposit amount: ";
                std::cin >> depositAmount;
                users[currentUserIndex].deposit(depositAmount);
                std::cout << "Deposit successful.\n"
                          << "New balance is: " << users[currentUserIndex].balance << "\n";
            }

            else if (choice == 3)
            {
                std::cout << "Enter withdrawal amount: ";
                std::cin >> withdrawAmount;
                if (users[currentUserIndex].withdraw(withdrawAmount))
                {
                    std::cout << "Withdrawal succesful.\n " << "New balance is: " << users[currentUserIndex].balance << "\n";
                }
                else
                {
                    std::cout << "Insufficent funds";
                }
            }
        }
    }
    else
    {
        std::cout << "Wrong credentials \n";
    }
    std::ofstream outFile("users.txt");

    if (!outFile) {
        std::cout << "Could not write to file\n";
        return 1;
    }

    for (int i = 0; i < users.size(); i++) {
        outFile << users[i].userName << " ";
        outFile << users[i].passWord << " ";
        outFile << users[i].balance << " \n";
    }
    outFile.close();
    std::cout << "Logged out.";

    return 0;
}
