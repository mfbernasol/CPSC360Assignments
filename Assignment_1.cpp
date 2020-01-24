#include <iostream>
#include <cstdlib>
#include<cstring>


//MAIN
int main (){
int computerRoll(int compScore);
int playerRoll(int playerScore);
  srand(time(0));

  int randomPlayer = 1;
  int playerScore = 0; //shows and tracks players total score
  int compScore = 0;

  int diceRoll = 0; // represents number rolled die 
  std::string answer; //string for response 

  // srand(time(0));
  // randomPlayer = (rand() % 2);

  //Player 1 
  if(randomPlayer == 1) {
    std::cout << "It is Player 1's turn";

    playerRoll(playerScore);


  }else {
      std::cout << "Computer rolls first.";
      computerRoll(compScore);
    
  }
  
 return 0;


}

//function for Computer Roll
int computerRoll(int compScore) {
  int diceRoll;
  int playerRoll(int playerScore);
  int playerScore = 0;
  do{  

        diceRoll = (rand() % 7);

        if(diceRoll == 1){
          std::cout << "\nComputer rolled a 1. It has 0 points.";\
          compScore = 0;

        }else{ 
      
          compScore = compScore + diceRoll;
            
          }

        }while(compScore <=20);

 return 0;
}

//function for player roll
int playerRoll(int playerScore){
  int diceRoll;
  int computerRoll(int compScore);
  int compScore = 0;
  std::string response;
  do{  
     //Player 1 Score 
        diceRoll = ((rand() % 6) +1);
        if(diceRoll == 1){
          std::cout << "\nYou rolled a 1. You have 0 points.";
          playerScore = 0;
          
        }else{
          std::cout << "\n\nYou rolled a " << diceRoll << "\nRoll again or Hold? Press r or h: ";
          std::cin >> response;
          if( response == "r"){
            playerScore = playerScore + diceRoll;
            std::cout<<"\n\nPlayer scored a " << playerScore;
            
          }else if (response == "h"){
            computerRoll(compScore);
          }

        }
  }while(playerScore <=100);

 return 0;
}