#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "dice_functions.h"
using namespace std;
int dices[4];
int choose;
int draw_nr=2;
int moves=26;
int score=0;
int dice_values[8];
int quantity_of_changes;
string points_checker[5] = {" - "," - "," - "," - "," - "};
int main()
{
    srand( time( NULL ) );
    for (int d=0; d<5; d++)
    {
        dices[d] =( std::rand() % 6 ) +1;
    }
    dices[0]=5;
    dices[1]=5;
    dices[2]=5;
    dices[3]=5;
    dices[4]=5;
    int dice_nr=1;
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
        cout << "0.Draw again (" << draw_nr << " more times left)" << endl;
        open_file(dice_values, points_checker);
        int choice;
        cout << "Choose you'r action" << endl;
        cin >> choice;
        if (!cin || choice > 13)
        {
            cin.clear(); // czyœcimy flagi b³êdu strumienia
            cin.sync(); // czyœcimy bufor strumienia
            dice_nr=dice_nr-5;
            cout << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            cout << "!Wrong action, try something diffrent!" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            cout << endl;
            continue;
        }
        switch( choice )
        {
            case 0:
                dice_nr=dice_nr-5; // restarting numbers after the draw.
                if(draw_nr<=-100)
                {
                    cout << "You cant draw again" << endl;
                    break;
                }
                cout << "How many dices do you want to change?" <<endl;
                cin >> quantity_of_changes;
                draw_again(quantity_of_changes,dices);
                if(quantity_of_changes!=0)
                {
                    moves++;
                    draw_nr--;
                }
            break;
            case 1:
                adding_dices(1, dices, score, dice_values);
                cout << "You added ace's" << endl;
                cout << "You'r score is"<< score << endl;
                break;
            case 2:
                adding_dices(2, dices, score, dice_values);
                cout << "You added two's" << endl;
                cout << "You'r score is"<< score << endl;
            break;
            case 3:
                adding_dices(3, dices, score, dice_values);
                cout << "You added three's" << endl;
                cout << "You'r score is"<< score << endl;
            break;
            case 4:
                adding_dices(4, dices, score, dice_values);
                cout << "You added four's" << endl;
                cout << "You'r score is"<< score << endl;
            break;
            case 5:
               adding_dices(5, dices, score, dice_values);
                cout << "You added five's" << endl;
                cout << "You'r score is"<< score << endl;
            break;
            case 6:
                adding_dices(6, dices, score, dice_values);
                cout << "You added sixe's" << endl;
                cout << "You'r score is"<< score << endl;
            break;
            case 7:
                    for(int k=0; k<=4; k++)
                    {
                        score=score+dices[k];
                        dice_values[6]+=dices[k];
                    }
                cout << "You added all dice's " << endl;
                cout << "You'r score is"<< score << endl;
            break;
            case 8:
                same_dices(3, dices,score,dice_values,points_checker);
            break;
            case 9:
                same_dices(4, dices,score,dice_values, points_checker );
            break;
            case 10:
            break;
            case 11:
                straight(3,25,dices,score,points_checker);
            break;
            case 12:
                straight(2,35,dices,score,points_checker);
            break;
            case 13:
                same_dices(5, dices,score,dice_values, points_checker);
            break;
                }
    }
}
