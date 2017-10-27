#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
int dices[5];
int dice_nr=1;
int choose;
int draw_nr=2;
string line;
int line_number=1;
int choice;
int moves=26;
int score=0;
int aces=0, twos=0,threes=0,fours=0,fives=0,siexes=0;
int quantity_of_changes;
void draw_again ()
{
    int dice_change;
                    if(quantity_of_changes==0)
                        {
                            cout <<"You can't do thing's like that !!!" << endl;
                        }
                    for(int i=0; i<quantity_of_changes; i++)
                    {
                        cout << "What dices you want to change? (Enter number)" <<endl;
                        cin>>dice_change;
                        dices[dice_change-1] =( std::rand() % 6 ) +1;
                    }
}
int main()
{
        srand( time( NULL ) );
        for (int d=0; d<5; d++)
        {
        dices[d] =( std::rand() % 6 ) +1;
        }
    for(int i=0; i<moves; i++)
    {
        cout << "Your numbers are" << endl;
        for(int j=0; j<5; j++)
        {
            cout <<"Nr"<<dice_nr <<"[" << dices[j] << "]"<< " ";
            dice_nr++;
        }
        cout <<""<< endl;
        cout << "----------------------------------------" << endl;
        string line;
        fstream file;
        cout << "0.Draw again (" << draw_nr << " more times left)" << endl;
        file.open("GameRules.txt", ios::in);
        if(file.good() == true)
        {
            while(!file.eof())
            {
                getline(file, line);
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout<<"File doesn't work!" << endl;
        }
        cout << "Choose you'r action" << endl;
        cin >> choice;
        switch( choice )
        {
        case 0:
            dice_nr=dice_nr-5; // restarting numbers after the draw
            if(draw_nr<=0)
            {
                cout << "You cant draw again" << endl;
                break;
            }
            cout << "How many dices do you want to change?" <<endl;
            cin >> quantity_of_changes;
            draw_again();
            if(quantity_of_changes!=0)
            {
            moves++;
            draw_nr--;
            }
        break;
        case 1:
            for(int k=0; k<=4; k++)
            {
                if(dices[k]==1)
                   {
                       score++;
                       aces++;
                   }
            }
        cout << "You'r score is"<< score << endl;
        break;
        case 2:
            for(int k=0; k<=4; k++)
            {
                if(dices[k]==2)
                   {
                        score=score+2;
                        twos=twos+2;
                   }
            }
        cout << "You'r score is"<< score << endl;
        break;
        case 3:
            for(int k=0; k<=4; k++)
            {
                if(dices[k]==3)
                   {
                        score=score+3;
                        threes=threes+3;
                   }
            }
        cout << "You'r score is"<< score << endl;
        break;
        case 4:
            for(int k=0; k<=4; k++)
            {
                if(dices[k]==4)
                   {
                       score=score+4;
                       fours=fours+2;
                   }
            }
        cout << "You'r score is"<< score << endl;
        break;
        case 5:
            for(int k=0; k<=4; k++)
            {
                if(dices[k]==5)
                   {
                       score=score+5;
                       fives=fives+5;
                   }
            }
        cout << "You'r score is"<< score << endl;
        break;
        }
    }
}
