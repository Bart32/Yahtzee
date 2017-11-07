#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "dice_functions.h"
draw_again ()
{
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
