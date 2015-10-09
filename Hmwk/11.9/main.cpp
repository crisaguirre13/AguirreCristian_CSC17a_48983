/* 
 * File:   main.cpp
 * Author: Cristian Aguirre
 * Created on October 8, 2015, 9:30 AM
 * Purpose: Speaker's Bureau
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

//User Library
#include "SpeakerInfo.h"

//Function prototypes
void getSPKER(speakerInfo *);
void prntSPKER(speakerInfo *);
void editSPKER(speakerInfo *);

//Execution Begins Here
int main()
{
        int NUM_SPEAKERS = 10; //# of speakers
        int index;             //Loop counter       
        speakerInfo infos[10]; //Array to hold speaker info
        
        //Choices for menu
        int submenu;
        const int Enter = 1,
                  Change = 2,
                  Print = 3,
                  leave = 4;
    
        //Menu display
        do{
        cout << "Please select a choice from this sub-menu.\n"
             << "1) Enter Speaker Information.\n"
             << "2) Change Speaker Information.\n"
             << "3) Print Speaker Information.\n"
             << "4) Exit program.\n"
             << "Choice: ";
        cin >> submenu;
        
        switch (submenu){
               case Enter:{
                    //Enter speaker information
                    getSPKER(infos);
                    }
                    break;
               case Change:{
                    //Change speaker information
                    editSPKER(infos);
                    }
                    break;
               case Print:{
                    //Print speaker information
                    prntSPKER(infos);
                    }
                    break;
                    }}
                    while (submenu != leave);

   system("pause");
   return 0;
}
void getSPKER(speakerInfo *p){
     int index=0;
     int size=10;
     for (index=0; index < size; index++){
     cout <<"Please enter the following information of speaker "<<index<< " : \n";
     cout <<"Speaker Name:";
     cin.ignore();
     getline (cin, p[index].name);
     cout<<"\nSpeaker Telephone #:";
     getline (cin, p[index].phone);
     cout<<"\nSpeaker Topic:";
     getline (cin, p[index].speakTopic);
     cout<<"\nFee Required:";
     cin>>p[index].feeReq;
     if (p[index].feeReq < 0)
     {
         cout <<"The fee entered cannot be a negative number, please reenter\n";
         cout <<"Fee Required: ";
         cin >>p[index].feeReq;
     }
     }}

void prntSPKER(speakerInfo *p){
     int index=0;
     int size=10;
     for (index=0; index < size; index++){
     cout <<"The information entered for each speaker is: \n";
     cout << "SPEAKER "<<index<<endl;
     cout << "Speaker Name: "<<p[index].name<<endl;
     cout << "Speaker Telephone #: "<<p[index].phone<<endl;
     cout << "Speaker Topic: "<<p[index].speakTopic<<endl;
     cout << "Speaker Fee Required: "<<p[index].feeReq<<endl;
     }}

     
void editSPKER(speakerInfo *p){
     int i;
     cout << "Please enter the number of the speaker you would like to edit."
          << "\nExample: 5\n";
     cin >> i;
     if (i <=9)
          {
     cout << endl;
     cout <<"Please enter the updated information of the speaker: \n";
     cout <<"Speaker Name:";
     cin.ignore();
     getline (cin, p[i].name);
     cout <<"\nSpeaker Telephone #:";
     getline (cin, p[i].phone);
     cout <<"\nSpeaker Topic:";
     getline (cin, p[i].speakTopic);
     cout <<"\nFee Required:";
     cin >>p[i].feeReq;}
     if (p[index].feeReq < 0)
     {
         cout <<"The fee entered cannot be a negative number, please reenter\n";
         cout <<"Fee Required: ";
         cin >>p[i].feeReq;
     }
     else
     {
         cout << "I'm sorry, that is an invalid selection.\n"
              << "The speakers range from 0-9.\n"
              << "Please select this option again.\n\n";
              }
     }