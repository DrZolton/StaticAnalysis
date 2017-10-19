/*********************************************
	Alya ElGamal
	4/8/2017
	piece.h
	Description: Declares our piece class,
				 spaces class
*********************************************/
#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include "game.h"     // Provides definition of game class
#include "colors.h"
using namespace std;
using namespace main_savitch_14;

#ifndef PIECE_H
#define PIECE_H
class piece{
	public:
		piece(){king=false;state=true;red=false;cyan=false;empty=true;}
		//accessor functions
		bool is_king()const{return king;}
		bool playable()const{return state;}
		bool is_red()const{return red;}
		bool is_cyan()const{return cyan;}
		bool is_empty()const{return empty;}
		char get_color()const{return color;}//b=blue, w=white

		//mutator functions
		void set_king(bool n){king=n;}
		void set_pstate(bool n){state=n;}
		void set_red(bool n){red=n;}
		void set_cyan(bool n){cyan=n;}
		void set_empty(bool n){empty=n;}
		void set_color(char n){color=n;}//b=blue, w=white
		ostream& output(ostream& cout)const{
			
			if(!is_king()){
				if(is_empty()){
					if(playable())
						cout<<""<<B_WHITE<<"  "<<RESET;
					else if(!playable())
						cout<<""<<B_BLUE<<"  "<<RESET;
				}
				else if(is_red()==true)
	   				cout<<B_WHITE<<RED<<" #"<<RESET<<"";
				else if(is_cyan()==true)
	   				cout<<B_WHITE<<CYAN<<" #"<<RESET<<"";
			}
			if(is_king()){
				if(is_red())
   					 cout<<B_WHITE<<RED<<"K#"<<RESET<<"";//K means it's a king
				else if(is_cyan())
   					 cout<<B_WHITE<<CYAN<<"K#"<<RESET<<"";		
			}
		}
	private:
		bool king,state,red,cyan,empty;
		char color;
};
#endif
