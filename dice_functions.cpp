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
///////////////////////////////////////////
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
///////////////////////////////////////////

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

///////////////////////////////////////////

void straight(int x, int y, int tab[], int score, string p_tab[])
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
            char adding_zero;
            cout << "There is no straight,do you want add 0? (Y/N)" << endl;
            cin >> adding_zero;
            if (adding_zero=='Y' || adding_zero=='y')
            {
                    p_tab[4-x]=" X";
            }
        break;
        }
        counter=1;
    }
    if(counter<x)
    {
        p_tab[4-x]=" V";
        score+=y;
        cout << "You have stragith" << endl;
        cout << "You'r score is"<< score << endl;
    }
}
///////////////////////////////////////////////////////
void full(int score, string p_tab[], int tab[])
{
    int checker;
    int counter=1;
    for (int k=0; k<= 4; k++)
    {
        for(int l=k+1; l<=4; l++)
        {
            if (tab[k]==tab[l])
            {
                checker=tab[k];
                counter++;
            }
        }
        if(counter==2 || counter==3)
        {
            break;
        }
        counter=1;
    }
        int s_counter=1;
        if(counter==2 || counter==3)

            for (int kk=0; kk<= 4; kk++)
            {
                for(int ll=kk+1; ll<=4; ll++)
                {
                    if (tab[kk]==tab[ll] && tab[kk]!=checker)
                    {
                    s_counter++;
                    }
                }
                if (s_counter+counter==5)
                {
                    break;
                }
                s_counter=1;
            }
            if (s_counter+counter==5)
            {
                cout << "You have full" << endl;
                p_tab[0]=" V";
                score+=25;
                cout << "You'r score is"<< score << endl;
            }
            else
            {
            char adding_zero;
            cout << "There is no straight,do you want add 0? (Y/N)" << endl;
            cin >> adding_zero;
            if (adding_zero=='Y' || adding_zero=='y')
            {
                     p_tab[0]=" X";
            }
            }
}
////////////////////////////////////
int check (int tab[], int x)
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
            return 1;
            break;
        }
    counter=1;
    }
    return 0;
}
int adding_zero()
{
    char adding_zero;
    cout << "You cant do this, do you want add 0? (Y/N)" << endl;
    cin >> adding_zero;
    if (adding_zero=='Y' || adding_zero=='y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void show_score(string category, int scr)
{
    cout << "You added "<< category <<" dice's " << endl;
    cout << "You'r score is "<< scr << endl;
}

