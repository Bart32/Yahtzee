#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "dice_functions.h"
using namespace std;
int dices[4];
int already_used[13] = {0};
int score=0;
int dice_values[9] = {0};
string points_checker[5] = {" - "," - "," - "," - "," - "};
int draw_nr=2;
int dont_draw;
int main()
{
    while(already_used[0,1,2,3,4,5,6,7,8,9,10,11,12]!=1)
    {

        if (draw_nr>=2 && dont_draw!=1)
        {
            random_dices(dices);
        }
        int dice_nr=1;
        cout << "Your numbers are" << endl;
        for(int j=0; j<5; j++)
        {
            cout <<"Nr"<<dice_nr <<"[" << dices[j] << "]"<< " ";
            dice_nr++;
            if (dice_nr>5)
            {
                dice_nr-=5;
            }
        }
    cout <<""<< endl;
    cout << "----------------------------------------" << endl;
    cout << "0.Draw again (max 2 times!)" << endl;
    open_file(dice_values, points_checker);
    int choice;
    cout << "Choose you'r action" << endl;
    cin >> choice;
    if (!cin || choice > 13)
    {
        cin.clear();
        cin.sync();
        dice_nr=dice_nr-5;
        cout << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        cout << "!Wrong action, try something diffrent!" << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        cout << endl;
        continue;
    }
    dont_draw=0;
    switch( choice )
    {
        case 0:
            if(draw_nr<=0)
            {
                cout << "You cant draw again " << endl;
            }
            else
            {
                draw_again(dices);
                draw_nr--;
            }
        break;
        case 1:
            if(already_used[0]!=1)
            {
                score+=adding_dices(1,dices);
                dice_values[0]+=adding_dices(1,dices);
                show_score("ace's", score);
                already_used[0]=1;
                draw_nr=2;
            }
            else
            {
                dont_draw=1;
                cout << "You already used this action, try something diffrent"<< endl;
            }
        break;
        case 2:
            if (already_used[1]!=1)
            {
                score+=adding_dices(2,dices);
                dice_values[1]+=adding_dices(2,dices);
                show_score("two's", score);
                already_used[1]=1;
                draw_nr=2;
            }
            else
            {
                cout << "You already used this action, try something diffrent"<< endl;
                dont_draw=1;
            }
            break;
        case 3:
            if (already_used[2]!=1)
            {
                score+=adding_dices(3,dices);
                dice_values[2]+=adding_dices(3,dices);
                show_score("three's", score);
                already_used[2]=1;
                draw_nr=2;
            }
            else
            {
                cout << "You already used this action, try something diffrent"<< endl;
                dont_draw=1;
            }
        break;
        case 4:
            if (already_used[3]!=1)
            {
                score+=adding_dices(4,dices);
                dice_values[3]+=adding_dices(4,dices);
                show_score("four's", score);
                already_used[3]=1;
                draw_nr=2;
            }
            else
            {
                cout << "You already used this action, try something diffrent"<< endl;
                dont_draw=1;
            }
        break;
        case 5:
            if (already_used[4]!=1)
            {
                score+=adding_dices(5,dices);
                dice_values[4]+=adding_dices(5,dices);
                show_score("fives",score);
                already_used[4]=1;
                draw_nr=2;
            }
            else
            {
                cout << "You already used this action, try something diffrent"<< endl;
                dont_draw=1;
            }
        break;
        case 6:
            if (already_used[5]!=1)
            {
                score+=adding_dices(6,dices);
                dice_values[5]+=adding_dices(6,dices);
                show_score("sixes", score);
                already_used[5]=1;
                draw_nr=2;
            }
            else
            {
                cout << "You already used this action, try something diffrent"<< endl;
                dont_draw=1;
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
                draw_nr=2;
            }
            else
            {
                cout << "You already used this action, try something diffrent"<< endl;
                dont_draw=1;
            }
        break;
        case 8:
            if(already_used[7]!=1)
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
                draw_nr=2;
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
                dont_draw=1;
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
                    draw_nr=2;
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
                dont_draw=1;
            }
        break;
        case 10:
            if(already_used[9]!=1)
            {
                if(full(dices)==1)
                {
                    points_checker[0]=" V";
                    score+=25;
                    show_score("Full !", score);
                    already_used[9]=1;
                    draw_nr=2;
                }
                else
                {
                    if( adding_zero()==1);
                    {
                        already_used[9]=1;
                        points_checker[0]= "X";
                        draw_nr=2;
                    }
                }
            }
            else
            {
                cout << "You already used this action, try something diffrent"<< endl;
                dont_draw=1;
            }
        break;
        case 11:
            if(already_used[10]!=1)
            {
                if(straight(3,dices)==1)
                {
                    points_checker[1]=" V";
                    score+=25;
                    show_score("Small Straight !", score);
                    already_used[10]=1;
                    draw_nr=2;
                }
                else
                {
                    if( adding_zero()==1);
                    {
                        already_used[10]=1;
                        points_checker[1]= "X";
                        draw_nr=2;
                    }
                }
            }
            else
            {
                cout << "You already used this action, try something diffrent"<< endl;
                dont_draw=1;
            }
        break;
            case 12:
                if(already_used[11]!=1)
                {
                    if(straight(2,dices))
                    {
                        points_checker[2]=" V";
                        score+=35;
                        show_score("BIG Straight !", score);
                        already_used[11]=1;
                        draw_nr=2;
                    }
                else
                {
                    if( adding_zero()==1);
                    {
                    already_used[11]=1;
                    points_checker[2]= "X";
                    draw_nr=2;
                    }
                }
            }
            else
            {
                cout << "You already used this action, try something diffrent"<< endl;
                dont_draw=1;
            }
        break;
        case 13:
            if(already_used[12]!=1)
            {
                if (check(dices, 5)==1)
                {
                    points_checker[3]=" V";
                    score+=50;
                    show_score("Yahtzee !", score);
                    already_used[12]=1;
                    draw_nr=2;
                }
                else
                {
                    if(adding_zero()==1);
                    {
                        points_checker[3]= " X";
                        already_used[12]=1;
                        draw_nr=2;
                    }
                }
            }
            else
            {
                cout << "You already used this action, try something diffrent"<< endl;
                dont_draw=1;
            }
        break;
        }
    }
    cout << "The game is over, you'r score is : "<< score << endl;
}
