#include <iostream>
#include "book.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

int main(){
    //book array 
    Book bookLibrary[5];

    //book 1 object
    // Book b1; 
    
    //initial variables
    int bookID; 
    std::string title; 

    //ask user inputs 
    for(int i = 0; i < 5; i++){
        std::cout << "Enter a book title: " << std::endl; //title
        std::getline(std::cin,title);
        bookLibrary[i].setTitle(title);
        bookID = rand() % 1000 + 1;
        bool checkOut = false;
        bookLibrary[i] = Book(title,bookID,checkOut);
    }


    std::cout << "" <<std::endl;
// Loops through book library 
    for (int i = 0; i < 5; i++) {
		std::cout << "Title: " << bookLibrary[i].getTitle() << std::endl;
		std::cout << "Book ID: " << bookLibrary[i].getBookID() << std::endl;
		std::cout << "" << std::endl;
	}
    
//main driver function 
    bookLibrary[0] = bookLibrary[1];
	bookLibrary[3] = bookLibrary[4] + bookLibrary[2];
	bookLibrary[4] = bookLibrary[2] - bookLibrary[3];

    return 0; 



}