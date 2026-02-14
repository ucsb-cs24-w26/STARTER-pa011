// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

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

  CardList aliceHand;
  CardList bobHand;

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

  bool end = false;

  while (!end) 
  {
    bool aliceMatched = false;
    bool bobMatched = false;

    for (CardList::Iterator it = aliceHand.begin(); it != aliceHand.end(); ++it) 
    {
      Card c = *it;
      if (bobHand.contains(c)) 
      {
        cout << "Alice picked matching card " << c << endl;
        bobHand.remove(c);
        aliceHand.remove(c);
        aliceMatched = true;
        break;
      }
    }

    for (CardList::Iterator it = bobHand.rbegin(); it != bobHand.rend(); --it) 
    {
      Card c = *it;
      if (aliceHand.contains(c)) 
      {
        cout << "Bob picked matching card " << c << endl;
        aliceHand.remove(c);
        bobHand.remove(c);
        bobMatched = true;
        break;
      }
    }

    if (!aliceMatched && !bobMatched) 
    {
      end = true;
    }
  }
  cout << endl << "Alice's cards:" << endl;
  for (CardList::Iterator it = aliceHand.begin(); it != aliceHand.end(); ++it) 
    {
      cout << *it << endl;
    }
  cout << endl << "Bob's cards:" << endl;
  for (CardList::Iterator it = bobHand.begin(); it != bobHand.end(); ++it) 
  {
    cout << *it << endl;
  }  
  return 0;
}
