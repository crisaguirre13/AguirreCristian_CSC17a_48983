/* 
 * File:   main.cpp
 * Author: Cristian Aguirre
 * Created on October 2, 2015, 9:21 AM
 * Purpose: Number Analysis Program
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int getHIGH(int[], int);
int getLOW(int[], int);
int getSUM(int[], int);
int getAVG(int[], int);

//Execution Begins Here
int main()
{
    ifstream infile;
    const int ARRAY_SIZE=12;
    char fileName[12];
    int numbers[ARRAY_SIZE];
    int avg;
    int count;
    int high;
    int low;
    int sum;
    
    cout << "Please enter the name of the file: ";
    cin >> fileName;
    infile.open(fileName);
    for(count =0; count < ARRAY_SIZE; count++)
    {
        fileName >> numbers[count];
    }
    high = getHIGH(numbers, ARRAY_SIZE);
    cout << "The highest number is: " << high <<endl;
    
    low = getLOW(numbers, ARRAY_SIZE);
    cout << "The lowest number is: " << low <<endl;
    
    sum = getSUM(numbers, ARRAY_SIZE);
    cout << "The total of the numbers is: " << sum <<endl;
    
    avg = getAVG(numbers, ARRAY_SIZE);
    cout << "The average of the numbers is: " <<avg <<endl;
    
    infile.close();
    return 0;
}
int getHIGH(int numbers[], int ARRAY_SIZE)
{
    int high;
    high = numbers[12];
    for(int count = 1; count < ARRAY_SIZE; count++)
    {
        if(numbers[count] > high)
            high = numbers[count];
    }
    return high;
}
int getLOW(int numbers[], int ARRAY_SIZE)
{
    int low;
    low = numbers[12];
    for(int count = 1; count < ARRAY_SIZE; count ++)
    {
        if (numbers[count] < low)
            low = numbers[count];
    }
    return low;
}
int getSUM(int numbers[], int ARRAY_SIZE)
{
    int sum;
    sum = numbers[12];
    for(int count =1; count < ARRAY_SIZE; count++)
    {
        sum += numbers[count];
    }
    return sum;
}
int getAVG(int numbers[], int ARRAY_SIZE)
{
    int sum = 0;
    int avg;
    for(int count = 1; count < ARRAY_SIZE; count++)
        sum += numbers[count];
        avg = sum/ARRAY_SIZE;
        return avg;
}