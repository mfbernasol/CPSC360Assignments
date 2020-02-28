#include <iostream>
#include <cstdlib>
#include "book.h"

//default constructor
Book::Book(){
    Title = "No title";
    bookID = rand() % 1000 + 1; 
    checkedOut = false; 
}
Book::Book(std::string title, int bID, bool checkOut){
    Title = title; 
    bookID = bID; 
    checkedOut = checkOut;
}
//copy constructor 
Book::Book(const Book &bookObject){
    Title = bookObject.Title; 
    bookID = bookObject.bookID; 
    checkedOut = bookObject.checkedOut;
}
//getters
std::string Book::getTitle(){
    return Title; 
}

int Book::getBookID(){
    return bookID; 
}

bool Book::isCheckedOut(){
    return checkedOut; 
}

//setters
void Book::setTitle(std::string title){
    Title = title; 
}

void Book::setBookID(int bID){
    bookID = bID; 
}

//checks for availability for book, returns message
void Book::borrowBook(){
    if(isCheckedOut() == true ){
        std::cout << "Book is currently checked out. Not available" << std::endl; 
    }else{
        checkedOut = true; 
    }
}

void Book::returnBook(){
    checkedOut = false; 
}
//OPERATOR OVERLOAD for PLUS 
Book Book::operator+(const Book &right){
    Book temp;
    temp.Title = Title + "," + right.Title; 
    temp.bookID = rand() % 1000 +1; 
    temp.checkedOut = false; 
    return temp;
}
//OPERATOR OVERLOAD for MINUS
Book Book::operator-(Book& right){
    Title = right.Title; 
    bookID = right.bookID; 
    right.Title = "No Title";
    right.bookID = 0;
    return *this;

}
//OPERATOR OVERLOAD for Equals
bool Book::operator=(const Book& right){
    if (Title == right.Title){
        return true; 
    }else {
        return false;
    }
}

std::string Book::status(){
    std::string bookIsAvailable = "Book is avaiable";
    std::string bookNotAvailable = "Book is currently checked out";
    if(isCheckedOut() == false){
        return bookIsAvailable;
    }else{
        return bookNotAvailable;
    }
}