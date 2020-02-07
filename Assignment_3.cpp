
#include <iostream>
#include <string>
#include <iomanip>


//constants
const int ROWS = 15;
const int SEATS_PER_ROW = 30;
const int FRONT_ROW_COST = 50;
const int BACK_ROW_COST = 40;

//initalize functions
void showMenu();
void displaySeatingChart();
int buyTickets(int numOfTickets);
int main() {
    //declare and initialize seating array
    char concertSeats[ROWS][SEATS_PER_ROW];
    for(int i=0; i< ROWS; i++)
        for(int j=0; j<SEATS_PER_ROW; j++)
            concertSeats[i][j]='#';

    int totalSales = 0;  //tracks total sales
    int totalPrice = 0; //total price for user for option 'B'
    int totalSeats = 450; //total number of seats 
    int seatSold = 0; //number of seats sold
    int available[15];
    int priceOfTix = 0;

    char userChoice;


    do {
 		//display choices
        showMenu();
		std::cout << "\nEnter option: ";
		std::cin >> userChoice;
		userChoice = std::toupper(userChoice);		
		
		//switch statement for options
        switch (userChoice) {
            case 'D':
            displaySeatingChart();

                break;
            case 'B': //letting user buy tickets
              std::cout<< "Enter number of tickets: ";
              int numOfTickets;
              int tixTotal;
              std::cin >> numOfTickets;
              tixTotal = buyTickets(numOfTickets);
              std::cout<< "Your Total Cost is: $" << tixTotal << std::endl;
              break;
            case 'T':
				//displaying total sales
              std::cout << "Total Sales: $ " << totalSales;
                break;
            case 'S':
				//displays seat info
        std::cout << "\nTotal Seats Sold: " << seatSold;
        std::cout << "\nTotal Seats Available:  \n" << totalSeats << std::endl;
                break;
            case 'Q':
				//code to quit program
                std::cout << "Thank you for using Seat Charter";
                break;
                
            default:
                std::cout << "Invalid choice" << std::endl; //this should never happen
        }

    } while (userChoice != 'Q');
    return 0;
  }


// calls menu choices 
void showMenu(){
    std::cout<<"\nHere are your options:\n";
    std::cout<<"Display Seating Chart [D]\n";
    std::cout<<"Buy tickets [B]\n";
    std::cout<<"Show total sales [T]\n";
    std::cout<<"Display seating info [S]\n";
    std::cout<<"Quit program [Q]\n";
}

// displays seating charts 
void displaySeatingChart(){
    char concertSeats[ROWS][SEATS_PER_ROW];
        for(int i=0; i< ROWS; i++)
            for(int j=0; j<SEATS_PER_ROW; j++)
                concertSeats[i][j]='#';

       std::cout << "  \t" << "123456789012345678901234567890\n";
               for(int i = 0; i<ROWS; i++){
                 std::cout<<"Row " <<i+1<<"\t";
                 for(int j = 0; j<SEATS_PER_ROW;j++){
                   std::cout << concertSeats[i][j];
                 }
                 std::cout<< std::endl;
               }
              std::cout<< std::endl;
}

// buys tickets 
int buyTickets(int numOfTickets){
    int totalSales = 0;  //tracks total sales
    int totalPrice = 0; //total price for user for option 'B'
    int totalSeats = 450; //total number of seats 
    int seatSold = 0; //number of seats sold
    int available[15];
    int priceOfTix = 0;
   char concertSeats[ROWS][SEATS_PER_ROW];
    for(int i=0; i< ROWS; i++)
        for(int j=0; j<SEATS_PER_ROW; j++)
            concertSeats[i][j]='#';

    for(int i = 0; i<numOfTickets; i++){
        while(true){
            std::cout<< "Enter row: ";
            int row,column;
            std::cin >> row;
            std::cout << "Enter column: ";
            std::cin >> column;
            if(row < 1 || row > 15 || column < 1 || column > 30) { //checks for invalid row/column range
                 std::cout << "Cannot choose this row and/or column\n";
            }else if(concertSeats[row-1][column-1] == '*'){
                    std::cout << "Seat is Taken\n";
            }else{
                concertSeats[row-1][column-1] = '*';
                    if(row <= 7){
                    priceOfTix = priceOfTix + FRONT_ROW_COST;
                    }else if(row >=8){
                      priceOfTix = priceOfTix + BACK_ROW_COST;
                    }
                    totalSales = totalSales + priceOfTix;
                    seatSold++;
                    available[row-1]--; 
                    totalSeats--; //subtracts seats from total 
                    break;
                  }
               }
              }        
        // std::cout << "Total Cost: $ " << priceOfTix << std::endl;
    return (priceOfTix);
}