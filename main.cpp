#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
int dices[4];
int choose;
int draw_nr=2;
int moves=26;
int score=0;
int dice_values[5] = {0, 0, 0, 0, 0};
int quantity_of_changes;
void open_file()
{
        string line;
        fstream file;
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
}
void adding_dices(int x, int tab[])
{
    for(int k=0; k<=4; k++)
    {
    if(tab[k]==x)
    {
        score=score+x;
        tab[x-1]=tab[x-1]+x;
    }
    }
}
void in_row(int x)
{
    int counter=1;
    for (int k=0; k<= 4; k++)
    {
        for(int l=k+1; l<=4; l++)
    {
    if (dices[k]==dices[l])
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
                    for(int k=0; k<=4; k++)
                        {
                            score=score+dices[k];
                        }
                else
                {
                    cout << "There is no "<< x<<" this same dice's, try something difrent" << endl;
                }
}
void draw_again ()
{
    int dice_change;
                    if(quantity_of_changes==0)
                        {
                            cout <<"You can't do thing's like that !!!" << endl;
                        }
                    cout << "What dices you want to change? (Enter number)" <<endl;
                    for(int i=0; i<quantity_of_changes; i++)
                    {
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
//    dices[0]=2;
//    dices[1]=3;
//   dices[2]=4;
//   dices[3]=5;
//   dices[4]=6;
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
        open_file();
        int choice;
        cout << "Choose you'r action" << endl;
        cin >> choice;
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
                draw_again();
                if(quantity_of_changes!=0)
                {
                moves++;
                draw_nr--;
                }
            break;
            case 1:
                adding_dices(1, dice_values);
            cout << "You added ace's" << endl;
            cout << "You'r score is"<< score << endl;
            break;
            case 2:
                adding_dices(2,dice_values);
            cout << "You added two's" << endl;
            cout << "You'r score is"<< score << endl;
            break;
            case 3:
                adding_dices(3,dice_values);
            cout << "You added three's" << endl;
            cout << "You'r score is"<< score << endl;
            break;
            case 4:
                adding_dices(4,dice_values);
                cout << "You added four's" << endl;
            cout << "You'r score is"<< score << endl;
            break;
            case 5:
               adding_dices(5,dice_values);
            cout << "You added five's" << endl;
            cout << "You'r score is"<< score << endl;
            break;
            case 6:
                adding_dices(6,dice_values);
            cout << "You added sixe's" << endl;
            cout << "You'r score is"<< score << endl;
            break;
            case 7:
                in_row(3);
            cout << "You added Threes Of A Kind" << endl;
            cout << "You'r score is"<< score << endl;
            break;
            case 8:
                in_row(4);
                cout << "You added Fours Of A Kind" << endl;
                cout << "You'r score is"<< score << endl;
            break;
            case 9:
                break;
            case 10:
            break;
            case 11:
                break;
            case 12:
                in_row(5);
                cout << "Yahtzee !! You gain 50 points !" << endl;
                cout << "You'r score is"<< score << endl;
                break;
                case 13:
                    for(int k=0; k<=4; k++)
                    {
                        score=score+dices[k];
                    }
                    cout << "You added all dice's" << endl;
                    cout << "You'r score is"<< score << endl;
                break;
                }
    }
}
