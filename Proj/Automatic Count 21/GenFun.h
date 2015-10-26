/* 
 * File:   GenFun.h
 * Author: Cristian Aguirre
 * Created on October 23, 2015, 2:40 PM
 * Purpose: Specification for the General Functions of the Program
 */

#ifndef GENFUN_H
#define	GENFUN_H

#include "Card.h"


//Card Creation
Card hand[52];      //Card amount array

//Constants
const int PLYNUM=2;         //Number of Players
const int GAMELIM=21;       //Value limit for hand
const int DEALER=20;        //Dealer hit limit
const int CARDPP=2;         //# of Cards for initial deal

//Prototypes
void dINFO();
void doEvery(string players[], int hit[], int i,
        int plyVAL[]);
void dHit(string players[], int hit[]);
void dResult(int plyVAL[],string players[]);
void fDEAL(string dealer[], int dealH[], int i);
void gCards(string players[], int plyVAL[]);
void rLim(string players[],int plyVAL[],int hit[]);
void shuffleCards(int counter);

//Functions
//Display Card Values
void dINFO(){
	cout << "Automatic Count 21 by Cristian Aguirre" << endl
		 << "Card Values:"  << endl;
        for(int i=1; i<=13; i++){
            if(i==1){cout <<"A = " <<i <<endl;}
            else if(i==11){cout <<"J = " <<i <<endl;}
            else if(i==12){cout <<"Q = " <<i <<endl;}
            else if(i==13){cout <<"K = " <<i <<endl;}
            else{cout <<i <<endl;}
        }
        
}

//Do Everything Function
void doEvery(string players[], int hit[], int i, int plyVAL[]){
    dINFO();                        //Displays Card value
    fDEAL(players, hit, i);         //Fills the dealer
    dHit(players, hit);             //Displays player name and hit limit
    gCards(players, plyVAL);        //Gives cards to each player
    rLim(players, plyVAL, hit);     //Gives more cards to each player is their are under hit limit
    dResult(plyVAL, players);       //Displays win or lose results
}

//Display Player Hit Limit
void dHit(string players[], int hit[]){
    //Column for player information
    cout <<"Player Name" <<"\t" <<"Hit Limit" <<endl;
    //Loop for displaying number of players(I was only able to get 1 player to work)
    for (int i=0; i<PLYNUM-1; i++){
        setfill(" ");
        //Displays player name and their hit limit
        cout <<right <<setw(11) <<players[i] <<" "
                <<right <<setw(9) <<hit[i] <<endl;
    }
    cout <<endl;
}

//Display Result Function-Displays Result of the game
void dResult(int plyVAL[],string players[]){
    cout <<"Results of Game\n\n";
    // Loop goes through all the players but the dealer(cant be himself)
    for(int i=0; i<PLYNUM -1; i++){
        if(plyVAL[PLYNUM-1] == GAMELIM){
            for(int x=0; x<PLYNUM -1; x++){
                cout <<"Dealer beats player " <<players[x] <<endl;
            }
            break;
        }
        //If the player goes over the limit of 21, the dealer wins
        if(plyVAL[i]>GAMELIM){
            cout <<"Dealer beats player " <<players[i] <<endl;
        }
        //Otherwise the following conditions are checked for
        else{
            //If the Dealer is less than the limit of 21
            if(plyVAL[PLYNUM -1] <= GAMELIM){
                //And if the dealers hand is greater than the player, the dealer wins
                if(plyVAL[PLYNUM -1] >= plyVAL[i]){
                    cout <<"Dealer beats player " <<players[i] <<endl;
                }
                //Otherwise, the player wins
                else{
                    cout <<"Player " <<players[i] << "beats the dealer!" <<endl;
                }
            }
            //The dealer loses because he is over the limit
            else{
                cout <<"Player " <<players[i] <<" beats the dealer!" <<endl;
            }
        }
    }
    cout <<endl;
}

//Fill Dealer cards
void fDEAL(string dealer[], int dealH[], int i){
    dealer[i+1] = "Dealer";     //Dealer will be the last player in array
    dealH[i+1]=DEALER;          //Hits the dealer his cards
}

//Give Cards Function-Amount of cards given to each player set by CARDPP
void gCards(string players[], int plyVAL[]){
    //Counts how many cards the players start with
    int handC=0;
    
    //Shows # of cards given to everyone
    cout <<"Deal everyone " <<CARDPP <<" cards\n\n";
    //Loops for the value of CARDPP
    for(int j=0; j<CARDPP; j++){
        //Loops for the number of players there are
        for(int i=0; i<PLYNUM; i++){
            //Add card value for player hand
            plyVAL[i] += hand[handC++].getFace();
        }
    }
    //Display Player Cards
    for(int x=0; x<PLYNUM; x++){
        cout <<"Hand for " <<players[x] <<" is: ";
        hand[x].display();
        cout <<" and ";
        hand[x + PLYNUM].display();
        cout <<" Value for hand is " <<plyVAL[x] <<endl;
    }
    cout <<endl <<endl;
}

//Reach Limit Function
void rLim(string players[],int plyVAL[],int hit[]){
    //Hit count is based on the number of players and the number of cards they are given
    int hitCount=PLYNUM*CARDPP;
    cout <<"Play the game - Who wants another card?\n\n";
    //Loops for the number of players
    for(int x=0; x<PLYNUM; x++){
        //If the player is under their hit limit, they get another card
        while(plyVAL[x] < hit[x]){
            plyVAL[x] +=hand[hitCount].getFace();
            cout <<"Player " << players[x] <<" is getting another card: ";
            hand[hitCount].display();
            cout <<endl;
            hitCount++;
        }
    cout <<"Value of hand for " <<players[x] <<" is now " <<plyVAL[x] <<"\n\n";
    }

}

//Shuffle Cards Function
void shuffleCards(int counter){
    //Loops for 3 to 6 because that is ASCII for card suits
    for(int s=3; s<=6; s++){
        //Loops from 1 to 13 for the amount of cards for each suit
        for(int f=1; f<=13; f++){
            //Makes cards using constructor in class
            hand[counter]=Card(f, char(s));
            counter++;
        }
    }
    //Loops all the cards and swaps them
    for(int i=0; i<52; i++){
        //Swaps using mod 52
        hand[i].swap(hand[rand()%52]);
    }
}

#endif	/* GENFUN_H */