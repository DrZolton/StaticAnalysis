/*********************************************
	Alya ElGamal
	4/8/2017
	checkers.h
	Description: Declares our checkers class
*********************************************/
#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include "game.h"     // Provides definition of game class
#include "colors.h"
#include"piece.h"
using namespace std;
using namespace main_savitch_14;
//82 evaluate
class Checkers:public game{
	public:
		Checkers();
		void restart();
		void display_status()const;
		bool is_legal(const std::string& move) const;
		void make_move(const std::string& move);
		bool is_game_over()const;
		bool is_jump(const std::string& move)const;
		void set_jump(bool j){jump=j;}

		int evaluate( ) const;
    	virtual game* clone( ) const;
    	virtual void compute_moves(std::queue<std::string>& moves) const;
		int string_to_int(const char in)const{
			if      (in == 'a' || in == 'A' || in == '0'){return 0;}
			else if (in == 'b' || in == 'B' || in == '1'){return 1;}
			else if (in == 'c' || in == 'C' || in == '2'){return 2;}
			else if (in == 'd' || in == 'D' || in == '3'){return 3;}
			else if (in == 'e' || in == 'E' || in == '4'){return 4;}
			else if (in == 'f' || in == 'F' || in == '5'){return 5;}
			else if (in == 'g' || in == 'G' || in == '6'){return 6;}
			else if (in == 'h' || in == 'H' || in == '7'){return 7;}
			else if (in == 'i' || in == 'I' || in == '8'){return 8;}
			else if (in == 'j' || in == 'J' || in == '9'){return 9;}
		}
	private:
		piece board[10][10];//[row][col]
		int red_pieces,cyan_pieces;
		bool jump;
		string lastMove;
};
