#include <string>
#ifndef BOOK_H
#define BOOK_H

class Book {
    private: //inital variables
            std::string Title; 
            int bookID; 
            bool checkedOut; 
    public:
            Book(); //default constructor
            Book(std::string title, int bookID, bool checkOut);
            Book(const Book &bookObject); //copy constructor 

            //getters
            std::string getTitle(); 
            int getBookID(); 
            bool isCheckedOut();

            //setters 
            void setTitle(std::string title); 
            void setBookID(int bookID);
            void borrowBook(); 
            void returnBook(); 
            std::string status();

};
#endif