#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "dice_functions.h"
void open_file(int tab[], string p_tab[])
{
    string line;
    fstream file;
    file.open("GameRules.txt", ios::in);
    if(file.good() == true)
    {
        for(int i=0; i<9; i++)
        {
            getline(file, line);
            cout << line <<"  "<< tab[i]<<  endl;

        }
        for(int i=0; i<5; i++)
        {
            getline(file, line);
            cout << line << p_tab[i] << endl;
        }
        file.close();
    }
    else
    {
        cout<<"File doesn't work!" << endl;
    }
}
void straight(int x, int y, int tab[], int score)
{
    int counter=1;
    for (int k=0; k<= 4; k++)
    {
        for(int l=k+1; l<=4; l++)
        {
        if (tab[k]==tab[l])
            {
                counter++;
            }
        }
        if(counter==x)
        {
            cout << "There is no straight,try something difrent" << endl;
            break;
        }
        counter=1;
    }
    if(counter<x)
    {
        score+=y;
        cout << "You have stragith" << endl;
        cout << "You'r score is"<< score << endl;
    }
}
void adding_dices(int x, int tab[],int score, int d_tab[])
{
    for(int k=0; k<=4; k++)
    {
        if(tab[k]==x)
        {
            score=score+x;
            d_tab[x-1]+=x;
        }
    }
}
void draw_again (int changes, int tab[])
{
    int dice_change;
    if(changes==0)
    {
        cout <<"You can't do thing's like that !!!" << endl;
    }
    cout << "What dices you want to change? (Enter number)" <<endl;
    for(int i=0; i<changes; i++)
    {
        cin>>dice_change;
        tab[dice_change-1] =( std::rand() % 6 ) +1;
    }
}


void same_dices(int x,int tab[], int score)
{
    int counter=1;
    for (int k=0; k<= 4; k++)
    {
        for(int l=k+1; l<=4; l++)
        {
            if (tab[k]==tab[l])
            {
                counter++;
            }
        }
        if(counter==x)
        {
            break;
        }
        counter=1;
    }
    if(counter>=x)
    {
        for(int k=0; k<=4; k++)
        {
        cout << "You added "<< x <<" Of A Kind" << endl;
            score=score+tab[k];
        cout << "You'r score is"<< score << endl;
        }
    }
    else
    {
        cout << "There is no "<< x<<" this same dice's, try something difrent" << endl;
    }
}
