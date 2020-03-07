#include <iostream>
#include <string>

class Account {
    protected:
        std::string ownerName; 
        int acctNum;
        double balance; 
        double deposit; 
        double withdraw; 
        // double intRate; 

    public:
        //default constructor
        Account(){
            ownerName = "";
            acctNum = 0;
            balance = 0; 
            deposit = 0;
            withdraw = 0; 

        }

        Account(std::string name, int actNum, int bal, double depo, double withdraw){
            ownerName = name; 
            acctNum = actNum; 
            balance = bal; 
            deposit = depo;
            withdraw = withdraw; 

        }

    //getters
        std::string getOwnerName(){
            return ownerName;
        }

        int getAcctNum(){
            return acctNum; 
        }

        double getBalance(){
            return balance;
        }

        //setters
        void setOwnerName(std::string name){
            ownerName = name; 
        }
        void setAcctNum(int num){
            acctNum = num;
        }
        void setBalance(int bal){
            balance = bal;
        }
        void setDeposit(double d){
            deposit = d; 
        }
        void setWithdraw(double w){
            withdraw = w; 
        }

};

//Derived Checking Account class
class CheckingAcct: public Account {
    public: 
        double getDeposit(){ // new deposit total
            balance = balance + deposit; 
            return balance; 
        }
    
        double getWithdraw(){ //new total after withdrawing 
            balance = balance - withdraw;
            return balance; 
        }
        
};

//Derived Loan Account Class
class LoanAcct: public Account {
    protected: 
        double intRate; 
    public: 
        void setIntRate(double i){
            intRate = i; 
        }

        double payBalance() {
            balance = balance - withdraw;
            return balance; 
        }

        double calcInterest() {
            balance = balance * intRate;
            return balance; 
        }

};



//MAIN DRIVER 
int main(void){

    //Checking Account
    CheckingAcct account;
    account.setOwnerName("Michael");
    std::cout << "Name: " << account.getOwnerName() << std::endl; // Account name

    account.setAcctNum(12345);
    std::cout << "Account Number: " << account.getAcctNum() << std::endl; // account number

    account.setBalance(100);
    std::cout << "Current Balance: " << account.getBalance() << std::endl; // current balance

    account.setDeposit(300);// adds to current balance
    std::cout << "New Balance: " << account.getDeposit() << std::endl; //new balance
    
    account.setWithdraw(55);
    std::cout << "New balance w/ withdrawal: " << account.getWithdraw() << std::endl; 


    //Loan Account
    LoanAcct account2; 
    account2.setOwnerName("Michael B");
    std::cout << "Name of Loan Account: " << account2.getOwnerName() << std::endl;

    account2.setBalance(2000);
    std::cout << "Current loan balance: " << account2.getBalance() << std::endl; 

    account2.setIntRate(5); //setting interest rate
    account2.setWithdraw(250); // using withdraw to set amount to deduct from balance instead creaing new function

    std::cout << "New loan balance: " << account2.payBalance() << std::endl; 

    std::cout << "Interest added to current loan balance: " <<  account2.calcInterest() << std::endl; 


    return 0;
}