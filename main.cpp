#include <bits/stdc++.h>
#include "numbers.hpp"
#include <unistd.h>

using namespace std;

int hours[2];
int minutes[2];
int seconds[2];

int counter[3];

void printOut(const int time[], int row, bool isSecond)
{
    cout << normalNumbers[time[0]][row]<<"    ";
    cout << normalNumbers[time[1]][row];

    if((row == (rows+2)/3 || row == (row+2)/3*2) && !isSecond) 
        cout << "   *   ";
    else 
        cout<< "       ";
}

void getTimeData()
{
    for(int i=0; i<2; i++)
    {
        if(counter[i]==60)
        {
            counter[i+1]++;
            counter[i] = 0;
        }
    }
    
    if(counter[2] == 24)
        counter[0]=counter[1]=counter[2]=0;



    hours[0] = counter[2] / 10;
    hours[1] = counter[2] % 10;

    minutes[0] = counter[1] / 10;
    minutes[1] = counter[1] % 10;
    
    seconds[0] = counter[0] / 10;
    seconds[1] = counter[0] % 10;
}

int main()
{  

    while(1 != 2)
    {
        system("cls");

        getTimeData();

        for(int i=0; i<rows; i++)
        {
            printOut(hours, i, false);
            printOut(minutes, i, false);
            printOut(seconds, i, true);
            cout << '\n';
        }
        sleep(1);
        counter[0]++;
    }
}
