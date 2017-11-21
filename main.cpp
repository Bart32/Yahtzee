#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "dice_functions.h"
using namespace std;
int dices[4];
int already_used[12] = {0};
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
    dices[1]=4;
    dices[2]=4;
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
                if (already_used[0]!=1)
                {
                adding_dices(1, dices, score, dice_values);
                show_score("ace's", score);
                already_used[0]=1;
                }
                else
                {
                 cout << "You already used this action, try something diffrent"<< endl;
                }
                break;
            case 2:
                if (already_used[1]!=1)
                {
                adding_dices(2, dices, score, dice_values);
                show_score("two's", score);
                already_used[1]=1;
                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }

            break;
            case 3:
                if (already_used[2]!=1)
                {
                adding_dices(3, dices, score, dice_values);
                show_score("three's", score);
                already_used[2]=1;
                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }
            break;
            case 4:
                if (already_used[3]!=1)
                {
                                 adding_dices(4, dices, score, dice_values);
                show_score("four's", score);
                already_used[3]=1;
                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }
            break;
            case 5:
                if (already_used[4]!=1)
                {
                adding_dices(5, dices, score, dice_values);
                show_score("five's", score);
                already_used[4]=1;
                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }
            break;
            case 6:
                if (already_used[5]!=1)
                {
                adding_dices(6, dices, score, dice_values);
                show_score("sixes", score);
                already_used[5]=1;
                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }
            break;
            case 7:
                if(already_used[6]!=1)
                {
                    for(int k=0; k<=4; k++)
                    {
                        score=score+dices[k];
                        dice_values[6]+=dices[k];
                        already_used[6]=1;
                    }
                    show_score("all", score);
                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }
            break;
            case 8:
                if(already_used[7!=1])
                {
                    if (check(dices, 3)==1)
                    {
                        for(int k=0; k<=4; k++)
                        {
                            score=score+dices[k];
                            dice_values[7]+=dices[k];
                        }
                    already_used[7]=1;
                    show_score("Three of a kind ", score);
                    }
                    else
                    {
                           if( adding_zero()==1);
                           {
                            already_used[7]=1;
                           }
                    }
                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }
            break;
            case 9:
                if (already_used[8]!=1)
                {
                    if (check(dices, 4)==1)
                    {
                        for(int k=0; k<=4; k++)
                        {
                            score=score+dices[k];
                            dice_values[8]+=dices[k];
                        }
                    already_used[8]=1;
                    show_score("four of a kind ", score);
                    }
                    else
                       if( adding_zero()==1);
                       {
                        already_used[8]=1;
                       }
                }
                else
                {
                    cout << "You already used this action, try something diffrent"<< endl;
                }
            break;
            case 10:
                if(already_used[9]!=1)
                {

                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }
            break;
            case 11:
                if(already_used[10]!=1)
                {
                    straight(3,25,dices,score,points_checker);
                    already_used[10]=1;
                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }
            break;
            case 12:
                if(already_used[11]!=1)
                {
                    straight(2,35,dices,score,points_checker);
                    already_used[11]=1;
                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }
            break;
            case 13:
                if(already_used[12]!=1)
                {
                     if (check(dices, 5)==1)
                    {
                        points_checker[3]=" V";
                        score+=50;
                        show_score("Five !", score);
                        already_used[12]=1;
                    }
                    else
                    {
                        if(adding_zero()==1);
                        {
                        points_checker[3]= " X";
                        already_used[12]=1;
                        }
                    }
                }
                else
                {
                cout << "You already used this action, try something diffrent"<< endl;
                }
                break;
        }
    }
}
