/* 
 * File:   main.cpp
 * Author: Cristian Aguirre
 * Created on October 23, 2015, 2:00 PM
 * Purpose: Run Count 21 Game
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Card.h"
#include "GenFun.h"

//Execution begins here
int main(){
    //Variable Creation
    int hit[PLYNUM]={0}, cardVAL[PLYNUM]={0},   //Hit is players hand limit
            indx=0, i=0;                        //cardVAL is a hands value
    string players[PLYNUM];
    char limit = ' ';                           //Char to hold player hit limit
    
    //Opens and checks for input file
    ifstream fin("Input.txt");
    if(!fin){
        cout <<"The file is not opening correctly." <<endl;
        system("pause");
        //Exit Program
        exit(0);
    }
    //Random
    srand((unsigned)(time(0)));
    
    //Shuffle Cards
    shuffleCards(indx);
    
    //Inputs data from file
    fin >>players[i] >>hit[i];
    while(!fin.eof()){
        //Variable i is passed to know how many players and the hit limit of the player
        fin >>players[i] >>hit[i];
        i++;
    }
    
    //Do Everything.
    doEvery(players, hit, i,cardVAL);
    
    //Exit program
    return 0;
}