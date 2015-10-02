/* 
 * File:   main.cpp
 * Author: Cristian Aguirre
 * Created on October 2, 2015, 7:56 AM
 * Purpose: Rainfall Statistics
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const int NUM_MONTHS = 12;

//Function Prototypes
float getTOT(float []);
float getAVG(float []);
float getLAR(float [], int &);
float getSMA(float [], int &);

//Execution Begins Here
int main()
{
    float rainFALL[NUM_MONTHS];
    for (int month = 0; month <NUM_MONTHS; month++)
    {
        //Month's Rainfall Data
        cout <<"Enter the rainfall (in inches) for month #";
        cout <<(month +1) <<": ";
        cin >> rainFALL[month];
        //Number Validation
        while(rainFALL[month] < 0)
        {
            cout << "Rainfall must be 0 or more.\n"
                    <<"Please re-enter data: ";
            cin >> rainFALL[month];
        }
    }
    cout << fixed <<showpoint << setprecision(2) <<endl;
    
    //Display Total Rainfall.
    cout << "The total rainfall for the year is " << getTOT(rainFALL)
            <<" inches." << endl;
    //Display Average Rainfall.
    cout << "The average rainfall for the year is " << getAVG(rainFALL)
            <<" inches." << endl;
    
    //Subscript variable to be passed by reference
    int subSCPT = 0;
    
    //Display Largest amount of rainfall.
    cout << "The largest amount of rainfall was ";
    cout << getLAR(rainFALL, subSCPT)
         << " inches in month ";
    cout << (subSCPT + 1) << "." << endl;
    //Display Smallest amount of rainfall
    cout << "The smallest amount of rainfall was ";
    cout << getSMA(rainFALL, subSCPT)
            << " inches in month "; 
    cout << (subSCPT + 1) << "." << endl << endl;
    return 0;
}

//Rainfall Total Calculation
float getTOT(float rainFALL[])
{
    float total = 0;
    for (int count = 0; count < NUM_MONTHS; count++)
        total += rainFALL[count];
    return total;
}

//Rainfall Average Calculation
float getAVG(float rainFALL[])
{
    float avg = 0.0;
    avg = getTOT(rainFALL)/NUM_MONTHS;
    return avg;
}

//Largest Amount of Rainfall
float getLAR(float rainFALL[], int &subSCPT)
{
    float large;
    large = rainFALL[0];
    for(int month = 0; month < NUM_MONTHS; month++)
    {
        if (rainFALL[month] > large)
        {
            large = rainFALL[month];
            subSCPT = month;
        }
    }
    return large;
}

//Smallest Amount of Rainfall
float getSMA(float rainFALL[], int &subSCPT)
{
    float small;
    small = rainFALL[0];
    for(int month = 0; month < NUM_MONTHS; month++)
    {
        if (rainFALL[month] < small)
        {
            small = rainFALL[month];
            subSCPT = month;
        }
    }
    return small;
}