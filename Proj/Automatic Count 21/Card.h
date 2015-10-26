/* 
 * File:   Card.h
 * Author: Cristian Aguirre
 * Created on October 23, 2015, 2:14 PM
 * Purpose: Specification for the Card Class
 */

#ifndef CARD_H
#define	CARD_H

//Card Class
class Card{
    //Private Variables
    private:                    
        int face;               //Variable for card face
        char suit;              //Variable for card suit
    //Public Variables    
    public:                     
        Card(int=0, char=' ');  //Constructor
        void display();         //Displays function for displaying cards.
        void swap(Card&);       //Swap function for swapping cards
        void setCard(int, char);//Setter Function to set card properties
        //Getters for Face and Suit
        int getFace();
        char getSuit();
};

//Constructor
Card::Card(int f, char s){
    face=f;
    suit=s;
}

//Swap Function
void Card::swap(Card& c){
    Card temp;          //Temporary class variable used to swap correctly.
    temp.face=c.face;
    temp.suit=c.suit;
    
    c.face=this->face;
    c.suit=this->suit;
    
    this->face=temp.face;
    this->suit=temp.suit;
}

//Displays Cards
void Card::display(){
    switch(face){           //Switch used to display Ace, Jack, Queen, and King
        case 1: cout <<'A';
            break;
        case 11: cout <<'J';
            break;
        case 12: cout <<'Q';
            break;
        case 13: cout<< 'K';
            break;
        default: cout <<face;
            break;     
    }
    //Suit can be displayed due to it being a char
    cout <<suit;
}

//Setter function for face and suit
void Card::setCard(int f, char s){
    face=f;
    suit=s;
}

//Getter function for face
int Card::getFace(){
    return face;
}

//Getter Function for suit
char Card::getSuit(){
    return suit;
}

#endif	/* CARD_H */