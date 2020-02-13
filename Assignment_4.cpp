
#include <iostream>
#include <fstream>
#include <string>
// using namespace std;

int main () {
  int wordCount = 0; //intial value to count words 
  int totalWord = 0; 
  int charCount = 0; 
  std::string line; //string for user input string 
  std::string word; //initalizes strings for text file 
  std::string longestWord; 

  std::cout << "Enter a file name: "; 
  std::cin  >> line;
  std::ifstream myfile(line); //takes in user input for file name 
  std::ofstream newFile("filestats.txt"); //writes out to text file 
  if (myfile.is_open()){ //checks to open file 
    while (myfile >> word){ 
    
      if(word.find("e") != std::string::npos){ //finds words with e 
        wordCount++; //counts words with e 
        if(word.size() > longestWord.size()) { //finds longest word with e 
          longestWord = word; 
        charCount = longestWord.length(); //counts characters in longest word
         }
        }

      }    
      newFile << "\nNumber of words with e: " << wordCount << std::endl; 
      newFile << "\nThe longest word with e is: " << longestWord << std::endl; 
      newFile << "\nNumber of characters in longest word with e: " << charCount << std::endl; 
      std::cout << "New file written!" << std::endl;
      myfile.close();
    }else{
      std::cout<< "Unable to open file" << std::endl;
    }


  return 0;
}




