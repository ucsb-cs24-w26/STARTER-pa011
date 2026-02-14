// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  set<Card> aliceHand;
  set<Card> bobHand;

  string tempSuit;
  string tempVal;


  while (cardFile1 >> tempSuit >> tempVal) 
  {
    Card c(tempSuit[0], tempVal);
    aliceHand.insert(c);
  }
  cardFile1.close();
  while (cardFile2 >> tempSuit >> tempVal) 
  {
      Card c(tempSuit[0], tempVal);
       bobHand.insert(c);
  }
  cardFile2.close();
  while (true) {
    bool aliceMatched = false;
    bool bobMatched = false;

      for (set<Card>::iterator it = aliceHand.begin(); it != aliceHand.end(); ++it) 
      {
        Card currentCard = *it;
        if (bobHand.count(currentCard)) {
          cout << "Alice picked matching card " << currentCard << endl;
          bobHand.erase(currentCard);
          aliceHand.erase(it);
          aliceMatched = true;
          break; 
        }
      }

      for (set<Card>::reverse_iterator it = bobHand.rbegin(); it != bobHand.rend(); ++it) 
      {
        Card currentCard = *it;
   
        if (aliceHand.count(currentCard)) 
        {
        cout << "Bob picked matching card " << currentCard << endl;
        aliceHand.erase(currentCard);
        bobHand.erase(currentCard);
        bobMatched = true;
        break; 
        }
      }

        if (!aliceMatched && !bobMatched) {break;}
    }

    cout << endl << "Alice's cards:" << endl;
    for (set<Card>::iterator it = aliceHand.begin(); it != aliceHand.end(); ++it) {cout << *it << endl;}

    cout << endl << "Bob's cards:" << endl;
    for (set<Card>::iterator it = bobHand.begin(); it != bobHand.end(); ++it) 
    {cout << *it << endl;}
  return 0;
}
