#include <iostream>
#include <vector>
#include <string>
class Bank
        {
        private:
    std::string name;
    std::string address;
    char type;
    double balance;

        public:
            void open_account();
            void deposit_money();
            void withdraw_money();
            void display_account();
        };

void Bank::open_account()
{
   std::cout << "Enter your full name: ";
   getline(std::cin,name);
   std::cout << "Enter your address: ";
   getline(std::cin,address);
   std::cout << "Type of account: saving(s) cashing(c) \n";
   std::cin >> type;
   std::cin.ignore();
   std::cout << "Enter first amount of deposit: ";
   std::cin >> balance;
   std::cout << "Account is created \n";
}
void Bank::deposit_money()
{
    int value;
    std::cout << "Enter amount of deposit: ";
    std::cin >> value;
    balance += value;
    std::cout << "Total balance: " << balance << std::endl;
}
void Bank::withdraw_money()
{
    int value;
    std::cout << "Enter amount of withdraw: ";
    std::cin >> value;
    if((balance-value) <0)
    {
        std::cout << "ERROR! \n";
    }
    else
    {
        balance -= value;
        std::cout << "Total balance: " << balance << std::endl;
    }
}
void Bank::display_account()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    if(type == 's')
    {
        std::cout << "Account type: Saving" << std::endl;
    }
    else
    {
        std::cout << "Account type: Checking" << std::endl;
    }
    std::cout << "Balance: " << balance << std::endl;

}
int main()
{
    std::vector<Bank> customers;
     int ch;
     char c;
     int stat = 0,id;
     do
     {
         std::cout << "1- Open Account \n";
         std::cout << "2- Deposit Money\n";
         std::cout << "3- Withdraw Money\n";
         std::cout << "4-Display Account\n";
         std::cout << "5- Exit\n";
         std::cout << "-> ";
         std::cin >> ch;
         std::cin.ignore();
         if(ch != 1)
         {
             std::cout << "Enter acc no: ";
             std::cin >> id;
             std::cin.ignore();
         }


         switch(ch)
         {
             case 1:
             {
                 Bank* new_acc = new Bank();
                 new_acc->open_account();
                 customers.push_back(*new_acc);
                 std::cout << "Acc no : " << stat << std::endl;
                 stat++;
             }

                 break;
             case 2:
                 customers[id].deposit_money();
                 break;
             case 3:
                 customers[id].withdraw_money();
                 break;
             case 4:
                 customers[id].display_account();
                 break;
             case 5:
                 exit(1);
                 break;
             default:
                 std::cout << "Error, try again!";
                 break;

         }
         std::cout <<  "Continue (y)\n Exit (n)\n->";
         std::cin >> c;
         std::cin.ignore();
         if(c== 'n' ||c=='N')
             exit(0);
     }while(c=='Y'||c=='y');



}
