#include <cstdlib>
// using rand
// using srand
#include <ctime>
// using time
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main (int argc, char*argv[]){
    //NOLINT
    srand(time(nullptr));

    // drawn random number of cards
    int test;
    cin >> test;
    
    for (int count =0; count < test ; ++count) {
        //suit conditions
        //NOLINT
        int suit_number = random() % 4;
        string suit;
        if (suit_number==0) {
            suit ="H";
        }else if(suit_number==1){
            suit ="D";
        }else if(suit_number==2){
            suit ="S";
        }else {
            suit="C";
        }
    //Declaration of values of each face of each card starting from 2 not 0
        //NOLINT
        int card_value = rand() %13+2;
        string face;
        
       if(card_value == 10) {
            face="J";
       }else if(card_value == 11){
           face="Q";
       }else if(card_value == 12){
           face="K";
       }else if(card_value == 13){
           face="A";
       }else if(card_value == 2){
           face="2";
       }else if(card_value == 3){
           face="3";
       }else if(card_value == 4){
           face="4";
       }else if(card_value == 5){
           face="5";
       }else if(card_value == 6){
           face="6";
       }else if(card_value == 7){
           face="7";
       }else if(card_value == 8){
           face="8";
       }else if(card_value == 9){
           face="9";
       } else {
           face="10";
       }
        
        cout << (face+""+suit)<<endl;
  }
    return 0;
}
    
