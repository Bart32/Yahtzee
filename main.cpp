#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
int dices[5];
int choose;
int draw_nr=3;
string line;
int line_number=1;
int choice;
int moves=26;
    int quantity_of_changes;
void draw_again ()
{
    int dice_change;
                    if(quantity_of_changes==0)
                        {
                            cout <<"You can't do thing's like that !!!" << endl;
                        }
                    for(int j=0; j<quantity_of_changes; j++)
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
        cout << "Nr1."<<"["<<dices[0]<<"]"<<" Nr2."<<"["<<dices[1]<<"]"<<" Nr3."
        <<"["<<dices[2]<<"]"<<" Nr4."<<"["<<dices[3]<<"]"<<" Nr5."<<"["<<dices[4]<<"]"<<endl;
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
        }
    }
}
