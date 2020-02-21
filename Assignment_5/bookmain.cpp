#include <iostream>
#include "book.h"

int main(){
    //book 1 object
    Book b1; 
    
    //initial variables
    int bookID; 
    std::string title; 

    //user inputs 
    std::cout << "Enter a book title: " << std::endl; //title
    std::cin >> title;
    b1.setTitle(title);

    std::cout << "Enter book ID: " <<std::endl; //bookID
    std::cin >> bookID; 
    b1.setBookID(bookID);

    std::cout << "Title: " << b1.getTitle() <<std::endl; 
    std::cout << "Book ID: " << b1.getBookID() <<std::endl; 
    std::cout << "Status: " <<b1.status() << std::endl; 

    //book 2 object 
    Book b2("Strange Case of Dr. Jekyll an Mr. Hyde",23,true);
    std::cout<<"Title: " << b2.getTitle() << std::endl;
    std::cout<<"Book ID: " <<b2.getBookID()<<std::endl; 
    std::cout<<"Status: " <<b2.status() <<std::endl;

    //book 3 object
    Book b3(b1); //passes b1 object 
    std::cout << "Title: " << b3.getTitle() <<std::endl;
	std::cout << "Book ID: " << b3.getBookID() <<std::endl;
	std::cout << "Status:  " << b3.status() <<std::endl;



    return 0; 



}