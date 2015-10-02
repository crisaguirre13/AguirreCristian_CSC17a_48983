/* 
 * File:   main.cpp
 * Author: Cristian Aguirre
 * Created on October 2, 2015, 9:58 AM
 * Purpose: Quarterly Sales Statistics
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants
const int NUM_DIV = 6;
const int NUM_QUARTS = 4;
string divNAME[] = {"#1", "#2", "#3", "#4", "#5", "D#6"};
string quartNAME[] = {"1st Quarter", "2nd Quarter", "3rd Quarter",
            "4th Quarter"};
//Function Prototypes
void getIN(float sales[NUM_QUARTS][NUM_DIV]);
void prntST(float sales[NUM_QUARTS][NUM_DIV],
            float quartTOT[], ofstream& outFile);
void prntPI(float sales[NUM_QUARTS][NUM_DIV],
            float quartTOT[], ofstream& outFile);
void prntTD(float sales[NUM_QUARTS][NUM_DIV],
            ofstream& outFile);
//Execution Begins Here
int main()
{
    float sales[NUM_QUARTS][NUM_DIV];
    float quartTOT[NUM_QUARTS];
    getIN(sales);
    ofstream outFile;
    prntST(sales, quartTOT, outFile);
    prntPI(sales, quartTOT, outFile);
    prntTD(sales, outFile);
    return 0;
}

void getIN(float sales[NUM_QUARTS][NUM_DIV])
{
    cout << "Enter sales data for each division for each reporting quarter.\n";
    for(int div =0; div < NUM_DIV; div++)
    {
        cout << "Enter sales data for Division " <<divNAME[div] << "\n";
        for(int quarter = 0; quarter < NUM_QUARTS; quarter++)
        {
            cout << quartNAME[quarter] << " Sales:";
            cin >> sales[quarter][div];
            do 
            {
                cout << "You cannot have negative sales.\n";
                cout << "Please re-enter " << quartNAME[quarter] <<" Sales:";
                cin >> sales[quarter][div];
            }while(sales[quarter][div] < 0);
        }
    }
}
void prntST(float sales[NUM_QUARTS][NUM_DIV], float quartTOT[], 
        ofstream& outFile)
{
    outFile <<setw(50) <<"Sales for each division by reporting period\n\n"
            <<setw(50) <<left << "Division" <<right;
    for (int quarter = 0; quarter < NUM_QUARTS; quarter++)
    {
        outFile <<setw(16)<< quartNAME[quarter];
    }
    outFile <<setw(16) << "Total Sales\n\n";
    float gTOTAL = 0;
    for (int div = 0; div < NUM_DIV; div++)
    {
        outFile <<setw(50) <<left <<divNAME[div] <<right <<fixed 
                <<setprecision(2);
        float total = 0;
        for (int quarter = 0; quarter < NUM_QUARTS; quarter++)
        {
            outFile << sales[quarter][div];
            total += sales[quarter][div];
            quartTOT[quarter] += sales[quarter][div];
        }
        outFile <<setw(16) <<total <<endl;
        gTOTAL += total;
    }
    outFile <<"\n\n" <<setw(15) <<left <<"Quarter Totals" << right;
    for(int quarter = 0; quarter < NUM_QUARTS; quarter++)
    {
        outFile <<setw(16) << quartTOT[quarter];
    }
    outFile <<setw(16) << gTOTAL;
    outFile <<"\n\n" <<setw(15) <<left <<"Quarter Averages" <<right;
    for (int quarter =0; quarter < NUM_QUARTS; quarter++)
    {
        outFile <<setw(16) <<quartTOT[quarter]/NUM_DIV;
    }
    outFile <<setw(16) << gTOTAL/NUM_DIV;
}

void prntPI(float sales[NUM_QUARTS][NUM_DIV], float quartTOT[],
        ofstream& outFile)
{
    outFile <<setw(50) <<"\n\nPrecent increase in sale for each division "
            <<"by reporting quarter(except the first)\n\n"
            <<setw(15) <<left <<"Division" <<right;
    for(int quarter =1; quarter <NUM_QUARTS; quarter++)
    {
        outFile <<setw(16) << quartNAME[quarter];
    }
    for(int div = 0; div < NUM_DIV; div++)
    {
        outFile <<setw(15) <<left << divNAME[div] <<right <<fixed 
                <<setprecision(2);
        for(int quarter = 1; quarter < NUM_QUARTS; quarter++)
        {
            if(sales[quarter -1][div] ==0)
                outFile <<setw(16) << "Not Applicable";
            else
                outFile <<setw(15) <<(sales[quarter][div]/
                        sales[quarter -1][div] -1) *100 <<"%";
        }
    }
    outFile <<"\n\n" <<setw(15) <<left <<"Quarter Totals" <<right;
    for (int quarter = 1; quarter < NUM_QUARTS; quarter++)
    {
        if(total[quarter] == 0)
            outFile <<setw(16) << "Not Applicable";
        else
            outFile <<setw(15 << (total[quarter]/
                    total[quarter -1]-1) * 100 <<"%";
    }
}

void prntTD(float sales[NUM_QUARTS][NUM_DIV], ofstream& outFile)
{
    outFile <<"\n\n\n" <<setw(50) << "Top divisions by quarter\n\n";
    for(int quarter =0; quarter < NUM_QUARTS; quarter++)
    {
        int maxIDX = 0;
        for(div =1; div < NUM_DIV; div++)
        {
            if(sales[quarter][div] > sales[quarter][maxIDX])
                maxIDX = div;
        }
        outFile <<setw(20) <<right <<quartNAME[quarter] << ": "
                <<divNAME[maxIDX] <<endl <<endl;
    }
}