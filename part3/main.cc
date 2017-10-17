// **************************************************************************
// Jacob Ramsey    April 24, 2017    CS2401    Project 6
// This program lets the user play checkers against the computer.
// **************************************************************************

#include "checkers.h"
#include "game.h"
#include "colors.h"
#include<iostream>

using namespace main_savitch_14;
using namespace std;

int main(){
    Checkers game1;

    for(int i = 0; i < 50; i++)
	cout << endl;

    cout << "   "
	/* C */ << B_RED << "        " << RESET << "  "
	/* H */ << B_RED << "  " << RESET << "    " << B_RED << "  " << RESET << "  "
	/* E */ << B_RED << "        " << RESET << "  "
	/* C */ << B_RED << "        " << RESET << "  "
	/* K */ << B_RED << "  " << RESET << "    " << B_RED << "  " << RESET << "  "
        /* E */ << B_RED << "        " << RESET << "  "
	/* R */ << B_RED << "      " << RESET << "    "
	/* S */ << "  " << B_RED << "      " << RESET
	<< endl


	<< "   "
	/* C */ << B_RED << "  " << RESET << "        "
	/* H */ << B_RED << "  " << RESET << "    " << B_RED << "  " << RESET << "  "
	/* E */  << B_RED << "  " << RESET << "        "
	/* C */ << B_RED << "  " << RESET << "        "
	/* K */ << B_RED << "  " << RESET << "  " << B_RED << "  " << RESET << "    "
        /* E */  << B_RED << "  " << RESET << "        "
	/* R */ << B_RED << "  " << RESET << "    " << B_RED << "  " << RESET << "  "
	/* S */ <<  B_RED << "  " << RESET
	<< endl


	<< "   "
	/* C */ << B_RED << "  " << RESET << "        "
	/* H */ << B_RED << "        " << RESET << "  "
	/* E */ << B_RED << "      " << RESET << "    "
	/* C */ << B_RED << "  " << RESET << "        "
	/* K */ << B_RED << "    " << RESET << "      "
        /* E */ << B_RED << "      " << RESET << "    "
        /* R */ << B_RED << "      " << RESET << "    "
	/* S */ << "  " << B_RED << "    " << RESET
	<< endl


        << "   "
        /* C */ << B_RED << "  " << RESET << "        "
        /* H */ << B_RED << "  " << RESET << "    " << B_RED << "  " << RESET << "  "
        /* E */ << B_RED << "  " << RESET << "        "
        /* C */ << B_RED << "  " << RESET << "        "
        /* K */ << B_RED << "  " << RESET << "  " << B_RED << "  " << RESET << "    "
        /* E */ << B_RED << "  " << RESET << "        "
        /* R */ << B_RED << "  " << RESET << "   " << B_RED << "  " << RESET << "   "
	/* S */ << "      " << B_RED << "  " << RESET
	<< endl


        << "   "
        /* C */ << B_RED << "        " << RESET << "  "
        /* H */ << B_RED << "  " << RESET << "    " << B_RED << "  " << RESET << "  "
        /* E */ << B_RED << "        " << RESET << "  "
        /* C */ << B_RED << "        " << RESET << "  "
        /* K */ << B_RED << "  " << RESET << "    " << B_RED << "  " << RESET << "  "
        /* E */ << B_RED << "        " << RESET << "  "
        /* R */ << B_RED << "  " << RESET << "    " << B_RED << "  " << RESET << "  "
	/* R */ << B_RED << "      " << RESET
	<< endl;

    cout << endl << BOLD
	<< "   ------------------------------------------------------------------------------" << endl
        << "   |                                                                            |" << endl
	<< "   | RULES: Each player  starts with  12 pieces, or  checkers, placed  in three |" << endl
	<< "   | rows. The object of the  game is to capture all of your  opponent's pieces |" << endl
	<< "   | or position your pieces so that your opponent has no available moves.      |" << endl
	<< "   |                                                                            |" << endl
	<< "   | You may move a  checker one space  forward,  diagonally. If an  opponent's |" << endl
	<< "   | piece  is on a forward  diagonal to  one of your pieces, and  there is  an |" << endl
	<< "   | empty space beyond  the opponent's piece, then your checker must  jump the |" << endl
	<< "   | opponent's piece and land in the space  beyond. Your opponent's checker is |" << endl
	<< "   | removed from the board. You must take a jump if one is available.          |" << endl
	<< "   |                                                                            |" << endl
	<< "   | After making the jump, your piece may have another jump available. This is |" << endl
	<< "   | called double jumping. You may even have triple or quadruple jumps.        |" << endl
	<< "   |                                                                            |" << endl
	<< "   | When one of your  checkers reaches the  opponent's back row, it  becomes a |" << endl
	<< "   | king and may now move forward or backward.                                 |" << endl
        << "   |                                                                            |" << endl
	<< "   | - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|" << endl
	<< "   |                                                                            |" << endl
	<< "   | Enter your moves by coordinates ex.(a6b5) to move your piece from A6 to B5 |" << endl
	<< "   | If you  are double  jumping, enter each  space your  checker will  land on |" << endl
	<< "   | ex. (a6c4a2)                                                               |" << endl
        << "   |                                                                            |" << endl
	<< "   ------------------------------------------------------------------------------" << endl;

    string junk;
    cout << "   Enter anything to start: ";
    getline(cin, junk);


    bool done = false;
    char answer;
    while(!done){
        game1.play();
	while(toupper(answer) != 'Y' && toupper(answer) != 'N'){
	    cout << "   Would you like to play again? Y or N\n";
	    cin >> answer;
	    if(toupper(answer) == 'Y');
	    else if(toupper(answer) == 'N')
	        done = true;
	    else
	        cout << "      Invalid choice\n";
	}
	answer = '0';
    }

    return 0;
}
