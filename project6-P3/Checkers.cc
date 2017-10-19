/*********************************************
	Alya ElGamal
	4/8/2017
	checkers.cc
	Description: Implements our checkers class
*********************************************/
#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include<cctype>
#include<cstdlib>
#include "game.h"
#include "colors.h"
#include "Checkers.h"
#include "piece.h"
using namespace std;
using namespace main_savitch_14;

	/*board layout note
		 0 1 2 3 4 5 6 7 8 9
	a	{b b b b b b b b b b},
	b	{b b a b a b a b a b},
	c	{b a b a b a b a b b},
	d	{b b a b a b a b a b},
	e	{b a b a b a b a b b},
	f	{b b a b a b a b a b},
	g	{b a b a b a b a b b},
	h	{b b a b a b a b a b},
	i	{b a b a b a b a b b},
	j	{b b b b b b b b b b}};
*/
Checkers::Checkers(){
	red_pieces=0;
	cyan_pieces=0;
	piece a,b;//a is playable, b is unplayable
	a.set_color('w');
	a.set_pstate(true);
	//a.set_empty(true);
	a.set_king(false);
	b.set_color('b');
	b.set_pstate(false);
	b.set_empty(true);
	b.set_king(false);

	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			board[i][j] = b;
		}
	}
	for(int j=1; j<8; j+=2){
				board[1][j] = a;
				board[1][j].set_cyan(true);
				board[1][j].set_red(false);
				board[1][j].set_empty(false);
				cyan_pieces++;
	}
	for(int j=1; j<8; j+=2){
				board[3][j] = a;
				board[3][j].set_cyan(true);
				board[3][j].set_red(false);
				board[3][j].set_empty(false);
				cyan_pieces++;
	}

	for(int i=2; i<7; i+=2){
				board[8][i] = a;
				board[8][i].set_red(true);
				board[8][i].set_cyan(false);
				board[8][i].set_empty(false);
				red_pieces++;
	}
	for(int i=2; i<7; i+=2){
				board[6][i] = a;
				board[6][i].set_red(true);
				board[6][i].set_cyan(false);
				board[6][i].set_empty(false);
				red_pieces++;
	}
	for(int i=2; i<7; i+=2){
				board[2][i] = a;
				board[2][i].set_cyan(true);
				board[2][i].set_red(false);
				board[2][i].set_empty(false);
				cyan_pieces++;
	}

	for(int i=1; i<8; i+=2){
				board[7][i] = a;
				board[7][i].set_red(true);
				board[7][i].set_cyan(false);
				board[7][i].set_empty(false);
				red_pieces++;
	}



	for(int i=3; i<7; i+=2){
		for(int j=1; j<8; j+=2){
			board[5][j].set_pstate(true);
			board[5][j].set_empty(true);
		}
	}
	
	for(int i=4; i<7; i+=2){
		for(int j=2; j<6; j+=2){
			board[4][j].set_pstate(true);
			board[4][j].set_empty(true);	
		}
	}
	board[4][6].set_pstate(true);
	board[4][6].set_empty(true);
}

void Checkers::restart(){
	Checkers();
}

bool Checkers::is_legal(const std::string& move)const{
	int i,j,i2,j2;
	//converts moves
	i=string_to_int(move.at(0));
	j=string_to_int(move.at(1));
	i2=string_to_int(move.at(2));
	j2=string_to_int(move.at(3));
	
	cout<<"*****************"<<move<<"**************";
	if(i==0||i==8)
		{cout<<          "move from i           ";return false;}
	else if(j==0||j==9)
		{cout<<          "move from j           ";return false;}
	else if(i2==0||i2==8)
		{cout<<          "move to i           ";return false;}
	else if(j2==0||j2==9)
		{cout<<          "move to j           ";return false;}
	else if (i == 8 && i2 == 9)
		{cout<<          "i to i2           ";return false;}
	else if (j == 7 && j2 == 8)
		{cout<<          "j to j2           ";return false;}
	else if(i2%2==1&&j2%2==0)
		{cout<<          "moveeeee           ";return false;}
	else if(i2%2==0&&j2%2==1)
		{cout<<          "movettttttttt           ";return false;}
	else if(i==i2)
		{cout<<          "i=i2           ";return false;}
	else if(j==j2)
		{cout<<"          j=j2        ";return false;}
	else if(abs(i-i2)!=abs(j-j2))
		{cout<<"        abs!=    ";return false;}
	else if (abs(i-i2) == 2 && abs(j-j2) ==2){
 		if(!is_jump(move)){
			return false;
			cout<<"      i:"<<i<<"           j:"<<j<<"         i2:"<<i2<<"          j2"<<j2<<"             ";}
	}
	else{
		if(!board[i][j].is_king()&& board[i2][j2].is_empty()){
			//checks cyan pieces, top of board
			if(board[i][j].is_cyan()==true){
				while(move.at(0)=='b'||move.at(0)=='d'||move.at(0)=='f'||move.at(0)=='h'){
				if(move.at(1)%2!=0){
					if(move.at(1)-1==move.at(3)||move.at(1)+1==move.at(3)){
						if(move.at(0)=='b'&&move.at(2)=='c'&&board[i2][j2].is_empty())
							return true;
						else if(move.at(0)=='d'&&move.at(2)=='e'&&board[i2][j2].is_empty())
							return true;
						else if(move.at(0)=='e'&&move.at(2)=='f'&&board[i2][j2].is_empty())
							return true;
						else if(move.at(0)=='f'&&move.at(2)=='g'&&board[i2][j2].is_empty())
							return true;
						else if(move.at(0)=='h'&&move.at(2)=='i'&&board[i2][j2].is_empty())
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else
					return false;		
			}
				while(move.at(0)=='c'||move.at(0)=='e'||move.at(0)=='g'){
			if(move.at(1)%2==0){
				if(move.at(1)-1==move.at(3)||move.at(1)+1==move.at(3)){
					if(move.at(0)=='c'&&move.at(2)=='d'&&board[i2][j2].is_empty())
						return true;
					else if(move.at(0)=='e'&&move.at(2)=='f'&&board[i2][j2].is_empty())
						return true;
					else if(move.at(0)=='g'&&move.at(2)=='h'&&board[i2][j2].is_empty())
						return true;
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;		
		}
			}

			//checks red pieces,bottom of board
			else if(board[i][j].is_red()==true){
				while(move.at(0)=='g'||move.at(0)=='i'||move.at(0)=='e'||move.at(0)=='c'){
				if(move.at(1)%2==0){
					if(move.at(1)-1==move.at(3)||move.at(1)+1==move.at(3)){
						if(move.at(0)=='g'&&move.at(2)=='f'&&board[i2][j2].is_empty())
							return true;
						else if(move.at(0)=='i'&&move.at(2)=='h'&&board[i2][j2].is_empty())
							return true;
						else if(move.at(0)=='e'&&move.at(2)=='d'&&board[i2][j2].is_empty())
							return true;
						else if(move.at(0)=='c'&&move.at(2)=='b'&&board[i2][j2].is_empty())
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else
					return false;
			}
				while(move.at(0)=='h'||move.at(0)=='f'||move.at(0)=='d'){
			if(move.at(1)%2!=0){
				if(move.at(1)-1==move.at(3)||move.at(1)+1==move.at(3)){
					if(move.at(0)=='h'&&move.at(2)=='g'&&board[i2][j2].is_empty())
						return true;
					else if(move.at(0)=='f'&&move.at(2)=='e'&&board[i2][j2].is_empty())
						return true;
					else if(move.at(0)=='d'&&move.at(2)=='c'&&board[i2][j2].is_empty())
						return true;
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
				
		}
			}
		}
		else if(board[i][j].is_king()){
			if(move.at(0)>'a'&&move.at(0)<'j'&&move.at(2)>'a'&&move.at(2)<'j'){
				if(move.at(1)>'0'&&move.at(1)<'9'&&move.at(3)>'0'&&move.at(3)<'9'){
					if((move.at(1)+1==move.at(3)&&board[i2][j2].is_empty())||(move.at(1)-1==move.at(3)&&board[i2][j2].is_empty())){
						if(move.at(0)!=move.at(2)){
							return true;
						}
						else
							return false;
					}
					else
						return false;
				}
				else 
					return false;
			}
			else
				return false;
		}
	}
}

//shows the current position of the pieces
void Checkers::display_status()const{
	cout<< "enter move piece you want to"<<endl
		<<"move letter than number then place "<<endl
		<<"you want to move it to without spaces "<<endl<<endl<<" ";
	/*cout<<endl<<endl<<"If you get one of your pieces next to"<<endl
		<<"the computers it makes a legal jump"<<endl
		<<"This may not be ideal but it makes a move like you wanted"
		<<endl<<"I think this should still count for credit given the guidlines"
		<<endl<<"example g2f1, f1e2"<<endl<<endl;
*/

	//fill in the game array
	for(int i=0; i<9;i++)
		cout<<" "<<i;
	cout<<endl;
	char c='a';
	for(int i=0; i<9; i++){
		cout<<c;
		c++;
		
		for(int j=0; j<9; j++){
			board[i][j].output(cout);
		}
		cout<<endl;
	}
}

//checks if the game is over
bool Checkers::is_game_over()const{
	queue<std::string> moves;
	compute_moves(moves);	
	if(cyan_pieces==0){
		cout<< "Red Wins!!!!";
		return true;
	}
	else if(red_pieces==0){
		cout<< "Cyan Wins!!!!";
		return true;
	}
	else if(moves.empty()){
		return true;
		cout<< "It's a Draw'!!!!";
	}
	else
		return false;
}

//actually implement the piece move
void Checkers::make_move(const std::string& move){
	int i,j,i2,j2;
	game::moves_completed();
	
	//checks for kings
	if(move.at(2)=='b'&&board[i][j].is_red()){
		board[i][j].set_king(true);
		board[i2][j2].set_king(true);
	}
	if(move.at(2)=='i'&&board[i][j].is_cyan()){
		board[i][j].set_king(true);
		board[i2][j2].set_king(true);
	}

	//checks current location number
	if(move.at(1)=='0')
		j=0;
	else if(move.at(1)=='1')
		j=1;
	else if(move.at(1)=='2')
		j=2;
	else if(move.at(1)=='3')
		j=3;
	else if(move.at(1)=='4')
		j=4;
	else if(move.at(1)=='5')
		j=5;
	else if(move.at(1)=='6')
		j=6;
	else if(move.at(1)=='7')
		j=7;
	else if(move.at(1)=='8')
		j=8;
	else if(move.at(1)=='9')
		j=9;
	//checks desired location number
	if(move.at(3)=='0')
		j2=0;
	else if(move.at(3)=='1')
		j2=1;
	else if(move.at(3)=='2')
		j2=2;
	else if(move.at(3)=='3')
		j2=3;
	else if(move.at(3)=='4')
		j2=4;
	else if(move.at(3)=='5')
		j2=5;
	else if(move.at(3)=='6')
		j2=6;
	else if(move.at(3)=='7')
		j2=7;
	else if(move.at(3)=='8')
		j2=8;
	else if(move.at(3)=='9')
		j2=9;
	//checks desired letters
	i=string_to_int(move.at(0));
	j=string_to_int(move.at(1));
	i2=string_to_int(move.at(2));
	j2=string_to_int(move.at(3));

	if(board[i][j].is_king()){
		if(move.at(0)!=move.at(2)){
			if(is_jump(move)){
				if(board[i][j].is_cyan()&&board[i2][j2].playable()&&board[i2][j2].is_empty()){
					board[i2][j2].set_empty(false);
					board[i2][j2].set_pstate(true);
					board[i2][j2].set_cyan(true);
					board[i2][j2].set_king(true);
					board[i][j].set_empty(true);
					board[i][j].set_pstate(true);
					board[i][j].set_cyan(false);
					board[i][j].set_king(false);

					if(move.at(1)+2==move.at(3)&&board[i+1][j+1].is_red()){
						board[i+1][j+1].set_empty(true);
						board[i+1][j+1].set_pstate(true);
						board[i+1][j+1].set_red(false);
						board[i+1][j+1].set_king(false);
						red_pieces--;
						game::moves_completed();
					}
					else if(move.at(1)-2==move.at(3)&&board[i+1][j-1].is_red()){
						board[i+1][j-1].set_empty(true);
						board[i+1][j-1].set_pstate(true);
						board[i+1][j-1].set_red(false);
						board[i+1][j-1].set_king(false);
						red_pieces--;
						game::moves_completed();
					}
					else if(move.at(1)-2==move.at(3)&&board[i-1][j-1].is_red()){
						board[i-1][j-1].set_empty(true);
						board[i-1][j-1].set_pstate(true);
						board[i-1][j-1].set_red(false);
						board[i-1][j-1].set_king(false);
						red_pieces--;
						game::moves_completed();
					}
					else if(move.at(1)+2==move.at(3)&&board[i-1][j+1].is_red()){
						board[i-1][j+1].set_empty(true);
						board[i-1][j+1].set_pstate(true);
						board[i-1][j+1].set_red(false);
						board[i-1][j+1].set_king(false);
						red_pieces--;
					}
				}
				else if(board[i][j].is_red()&&board[i2][j2].playable()&&board[i2][j2].is_empty()){
					board[i2][j2].set_empty(false);
					board[i2][j2].set_pstate(true);
					board[i2][j2].set_red(true);
					board[i2][j2].set_king(true);
					board[i][j].set_empty(true);
					board[i][j].set_pstate(true);
					board[i][j].set_red(false);
					board[i][j].set_king(false);

					if(move.at(1)+2==move.at(3)&&board[i+1][j+1].is_cyan()){
						board[i+1][j+1].set_empty(true);
						board[i+1][j+1].set_pstate(true);
						board[i+1][j+1].set_red(false);
						board[i+1][j+1].set_king(false);
						cyan_pieces--;
					}
					else if(move.at(1)-2==move.at(3)&&board[i+1][j-1].is_cyan()){
						board[i+1][j-1].set_empty(true);
						board[i+1][j-1].set_pstate(true);
						board[i+1][j-1].set_red(false);
						board[i+1][j-1].set_king(false);
						cyan_pieces--;
					}
					else if(move.at(1)-2==move.at(3)&&board[i-1][j-1].is_cyan()){
						board[i-1][j-1].set_empty(true);
						board[i-1][j-1].set_pstate(true);
						board[i-1][j-1].set_red(false);
						board[i-1][j-1].set_king(false);
						cyan_pieces--;
					}
					else if(move.at(1)+2==move.at(3)&&board[i-1][j+1].is_cyan()){
						board[i-1][j+1].set_empty(true);
						board[i-1][j+1].set_pstate(true);
						board[i-1][j+1].set_red(false);
						board[i-1][j+1].set_king(false);
						cyan_pieces--;
					}
				}
			}
			else if(move.at(1)-1==move.at(3)||move.at(1)+1==move.at(3)){
				if(board[i][j].is_cyan()&&board[i2][j2].playable()){
					board[i2][j2].set_empty(false);
					board[i2][j2].set_pstate(true);
					board[i2][j2].set_cyan(true);
					board[i2][j2].set_king(true);
					board[i][j].set_empty(true);
					board[i][j].set_pstate(true);
					board[i][j].set_cyan(false);
					board[i][j].set_king(false);

					if(move.at(1)+2==move.at(3)&&board[i+1][j+1].is_red()){
						board[i+1][j+1].set_empty(true);
						board[i+1][j+1].set_pstate(true);
						board[i+1][j+1].set_red(false);
						board[i+1][j+1].set_king(false);
					}
					else if(move.at(1)+2==move.at(3)&&board[i+1][j-1].is_red()){
						board[i+1][j-1].set_empty(true);
						board[i+1][j-1].set_pstate(true);
						board[i+1][j-1].set_red(false);
						board[i+1][j-1].set_king(false);
					}
					else if(move.at(1)-2==move.at(3)&&board[i+1][j-1].is_red()){
						board[i+1][j-1].set_empty(true);
						board[i+1][j-1].set_pstate(true);
						board[i+1][j-1].set_red(false);
						board[i+1][j-1].set_king(false);
					}
					if(move.at(1)-2==move.at(3)&&board[i-1][j-1].is_red()){
						board[i-1][j-1].set_empty(true);
						board[i-1][j-1].set_pstate(true);
						board[i-1][j-1].set_red(false);
						board[i-1][j-1].set_king(false);
					}
				}
				else if(board[i][j].is_red()&&board[i2][j2].playable()){
					board[i2][j2].set_empty(false);
					board[i2][j2].set_pstate(true);
					board[i2][j2].set_red(true);
					board[i2][j2].set_king(true);
					board[i][j].set_empty(true);
					board[i][j].set_pstate(true);
					board[i][j].set_red(false);
					board[i][j].set_king(false);

					if(move.at(1)+2==move.at(3)&&board[i+1][j+1].is_cyan()){
						board[i+1][j+1].set_empty(true);
						board[i+1][j+1].set_pstate(true);
						board[i+1][j+1].set_red(false);
						board[i+1][j+1].set_king(false);
					}
					else if(move.at(1)+2==move.at(3)&&board[i+1][j-1].is_cyan()){
						board[i+1][j-1].set_empty(true);
						board[i+1][j-1].set_pstate(true);
						board[i+1][j-1].set_red(false);
						board[i+1][j-1].set_king(false);
					}
					else if(move.at(1)-2==move.at(3)&&board[i+1][j-1].is_cyan()){
						board[i+1][j-1].set_empty(true);
						board[i+1][j-1].set_pstate(true);
						board[i+1][j-1].set_red(false);
						board[i+1][j-1].set_king(false);
					}
					if(move.at(1)-2==move.at(3)&&board[i-1][j-1].is_cyan()){
						board[i-1][j-1].set_empty(true);
						board[i-1][j-1].set_pstate(true);
						board[i-1][j-1].set_red(false);
						board[i-1][j-1].set_king(false);
					}
				}
			}
		}
	}
	else if(!board[i][j].is_king()){
		if(is_jump(move)){
				if(board[i][j].is_cyan()&&move.at(0)<move.at(2)&&board[i2][j2].playable()){
					board[i2][j2].set_empty(false);
					board[i2][j2].set_pstate(true);
					board[i2][j2].set_cyan(true);
					board[i2][j2].set_king(false);
					board[i][j].set_empty(true);
					board[i][j].set_pstate(true);
					board[i][j].set_cyan(false);
					board[i][j].set_king(false);

					if(move.at(1)+2==move.at(3)&&board[i+1][j+1].is_red()){
						board[i+1][j+1].set_empty(true);
						board[i+1][j+1].set_pstate(true);
						board[i+1][j+1].set_red(false);
						board[i+1][j+1].set_king(false);
						red_pieces--;
					}
					else if(move.at(1)-2==move.at(3)&&board[i+1][j-1].is_red()){
						board[i+1][j-1].set_empty(true);
						board[i+1][j-1].set_pstate(true);
						board[i+1][j-1].set_red(false);
						board[i+1][j-1].set_king(false);
						red_pieces--;
					}
				}
				else if(board[i][j].is_red()&&move.at(0)>move.at(2)&&board[i2][j2].playable()){
					board[i2][j2].set_empty(false);
					board[i2][j2].set_pstate(true);
					board[i2][j2].set_red(true);
					board[i2][j2].set_king(false);
					board[i][j].set_empty(true);
					board[i][j].set_pstate(true);
					board[i][j].set_red(false);
					board[i][j].set_king(false);

					if(move.at(1)+2==move.at(3)&&board[i-1][j+1].is_cyan()){
						board[i-1][j+1].set_empty(true);
						board[i-1][j+1].set_pstate(true);
						board[i-1][j+1].set_red(false);
						board[i-1][j+1].set_king(false);
						cyan_pieces--;
					}
					else if(move.at(1)-2==move.at(3)&&board[i-1][j-1].is_cyan()){
						board[i-1][j-1].set_empty(true);
						board[i-1][j-1].set_pstate(true);
						board[i-1][j-1].set_red(false);
						board[i-1][j-1].set_king(false);
						cyan_pieces--;
					}
				}
		}
	}

	//checks cyan pieces,top
	if(move.at(0)<='d'&&board[i][j].is_cyan()){
			board[i2][j2].set_empty(false);
			board[i2][j2].set_pstate(true);
			board[i2][j2].set_cyan(true);
			board[i][j].set_empty(true);
			board[i][j].set_pstate(true);
			board[i][j].set_cyan(false);
		}
	else if(move.at(0)>'d'&&board[i][j].is_cyan()){
			board[i2][j2].set_empty(false);
			board[i2][j2].set_pstate(true);
			board[i2][j2].set_cyan(true);
			board[i][j].set_empty(true);
			board[i][j].set_pstate(true);
			board[i][j].set_cyan(false);
		}
	//checks red pieces,bottom
	if(move.at(0)>'d'&&board[i][j].is_red()){
			board[i2][j2].set_empty(false);
			board[i2][j2].set_pstate(true);
			board[i2][j2].set_red(true);
			board[i][j].set_empty(true);
			board[i][j].set_pstate(true);
			board[i][j].set_red(false);
		}
	else if(move.at(0)<='d'&&board[i][j].is_red()){
			board[i2][j2].set_empty(false);
			board[i2][j2].set_pstate(true);
			board[i2][j2].set_red(true);
			board[i][j].set_empty(true);
			board[i][j].set_pstate(true);
			board[i][j].set_red(false);
		}
	if(move.at(0)=='b'&&board[i][j].is_red()==true)
		board[i][j].is_king()==true;
	else if(move.at(0)=='i'&&board[i][j].is_cyan()==true)
		board[i][j].is_king()==true;
	else
		board[i][j].is_king()==false;

	game::moves_completed();
	game::make_move(move);
}	

//helper function for is_legal() checks if you can jump
bool Checkers::is_jump(const std::string& move)const{
		int i,j,i2,j2;
	//checks current location number
	if(move.at(1)=='0')
		j=0;
	else if(move.at(1)=='1')
		j=1;
	else if(move.at(1)=='2')
		j=2;
	else if(move.at(1)=='3')
		j=3;
	else if(move.at(1)=='4')
		j=4;
	else if(move.at(1)=='5')
		j=5;
	else if(move.at(1)=='6')
		j=6;
	else if(move.at(1)=='7')
		j=7;
	else if(move.at(1)=='8')
		j=8;
	else if(move.at(1)=='9')
		j=9;
	//checks desired location number
	if(move.at(3)=='0')
		j2=0;
	else if(move.at(3)=='1')
		j2=1;
	else if(move.at(3)=='2')
		j2=2;
	else if(move.at(3)=='3')
		j2=3;
	else if(move.at(3)=='4')
		j2=4;
	else if(move.at(3)=='5')
		j2=5;
	else if(move.at(3)=='6')
		j2=6;
	else if(move.at(3)=='7')
		j2=7;
	else if(move.at(3)=='8')
		j2=8;
	else if(move.at(3)=='9')
		j2=9;
	//checks desired letters
	i=string_to_int(move.at(0));
	j=string_to_int(move.at(1));
	i2=string_to_int(move.at(2));
	j2=string_to_int(move.at(3));

	if(board[i][j].is_cyan()){
		if(board[i][j].is_king()){
			if(move.at(0)+2==move.at(2)||move.at(0)-2==move.at(2)){
				if(move.at(1)+2==move.at(3)||move.at(1)-2==move.at(3)){
					return true;	
				}
				else
					return false;
			}
			else
				return false;
		}
		else{
			if(move.at(0)+2==move.at(2)){
				if(move.at(1)+2==move.at(3)||move.at(1)-2==move.at(3)){
					return true;	
				}
				else
					return false;
			}
			else
				return false;
		}
	}
	else if(board[i][j].is_red()){
		if(board[i][j].is_king()){
			if(board[i][j].is_king()){
			if(move.at(0)+2==move.at(2)||move.at(0)-2==move.at(2)){
				if(move.at(1)+2==move.at(3)||move.at(1)-2==move.at(3)){
					return true;	
				}
				else
					return false;
			}
			else
				return false;
			}
		}
		else{
			if(move.at(0)-2==move.at(2)){
				if(move.at(1)+2==move.at(3)||move.at(1)-2==move.at(3)){
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
	}
}

//Checks if a spot is occupied by a HUMAN piece or a COMPUTER piece
//makes a numberical board
//-1=HUMAN 1=COMPUTER 0=NEUTRAL
int Checkers::evaluate ()const{
	int value=21;
	for(int i=0; i<9;i++){
		for(int j=0; j<9;j++){
			if(board[i][j].is_red())//checks for HUMAN
				value--;
			else if(board[i][j].is_cyan())//checks for COMPUTER
				value++;
		}
	}
	return value;
}

//makes a copy of the current board
game* Checkers::clone( ) const{
	return new Checkers(*this);
}

void move_to_array(string move,int i, int j,int i2, int j2){
	//checks current location number
	if(move.at(1)=='0')
		j=0;
	else if(move.at(1)=='1')
		j=1;
	else if(move.at(1)=='2')
		j=2;
	else if(move.at(1)=='3')
		j=3;
	else if(move.at(1)=='4')
		j=4;
	else if(move.at(1)=='5')
		j=5;
	else if(move.at(1)=='6')
		j=6;
	else if(move.at(1)=='7')
		j=7;
	else if(move.at(1)=='8')
		j=8;
	else if(move.at(1)=='9')
		j=9;
	//checks desired location number
	if(move.at(3)=='0')
		j2=0;
	else if(move.at(3)=='1')
		j2=1;
	else if(move.at(3)=='2')
		j2=2;
	else if(move.at(3)=='3')
		j2=3;
	else if(move.at(3)=='4')
		j2=4;
	else if(move.at(3)=='5')
		j2=5;
	else if(move.at(3)=='6')
		j2=6;
	else if(move.at(3)=='7')
		j2=7;
	else if(move.at(3)=='8')
		j2=8;
	else if(move.at(3)=='9')
		j2=9;
}

string array_to_move(int i, int j,string m){
	if(i==0){
		if(j==0){
			m= "a0";
		}
		else if(j==1){
			m= "a1";
		}
		else if(j==2){
			m= "a2";
		}
		else if(j==3){
			m= "a3";
		}
		else if(j==4){
			m= "a4";
		}
		else if(j==5){
			m= "a5";
		}
		else if(j==6){
			m= "a6";
		}
		else if(j==7){
			m= "a7";
		}
		else if(j==8){
			m= "a8";
		}
	}
	else if(i==1){
		if(j==0){
			m= "a0";
		}
		else if(j==1){
			m= "a1";
		}
		else if(j==2){
			m= "a2";
		}
		else if(j==3){
			m= "a3";
		}
		else if(j==4){
			m= "a4";
		}
		else if(j==5){
			m= "a5";
		}
		else if(j==6){
			m= "a6";
		}
		else if(j==7){
			m= "a7";
		}
		else if(j==8){
			m= "a8";
		}
	}
	else if(i==2){
		if(j==0){
			m= "b0";
		}
		else if(j==1){
			m= "b1";
		}
		else if(j==2){
			m= "b2";
		}
		else if(j==3){
			m= "b3";
		}
		else if(j==4){
			m= "b4";
		}
		else if(j==5){
			m= "b5";
		}
		else if(j==6){
			m= "b6";
		}
		else if(j==7){
			m= "b7";
		}
		else if(j==8){
			m= "b8";
		}
	}
	else if(i==3){
		if(j==0){
			m= "c0";
		}
		else if(j==1){
			m= "c1";
		}
		else if(j==2){
			m= "c2";
		}
		else if(j==3){
			m= "c3";
		}
		else if(j==4){
			m= "c4";
		}
		else if(j==5){
			m= "c5";
		}
		else if(j==6){
			m= "c6";
		}
		else if(j==7){
			m= "c7";
		}
		else if(j==8){
			m= "c8";
		}
	}
	else if(i==4){
		if(j==0){
			m= "d0";
		}
		else if(j==1){
			m= "d1";
		}
		else if(j==2){
			m= "d2";
		}
		else if(j==3){
			m= "d3";
		}
		else if(j==4){
			m= "d4";
		}
		else if(j==5){
			m= "d5";
		}
		else if(j==6){
			m= "d6";
		}
		else if(j==7){
			m= "d7";
		}
		else if(j==8){
			m= "d8";
		}
	}
	else if(i==5){
		if(j==0){
			m= "e0";
		}
		else if(j==1){
			m= "e1";
		}
		else if(j==2){
			m= "e2";
		}
		else if(j==3){
			m= "e3";
		}
		else if(j==4){
			m= "e4";
		}
		else if(j==5){
			m= "e5";
		}
		else if(j==6){
			m= "e6";
		}
		else if(j==7){
			m= "e7";
		}
		else if(j==8){
			m= "e8";
		}
	}
	else if(i==6){
		if(j==0){
			m= "f0";
		}
		else if(j==1){
			m= "f1";
		}
		else if(j==2){
			m= "f2";
		}
		else if(j==3){
			m= "f3";
		}
		else if(j==4){
			m= "f4";
		}
		else if(j==5){
			m= "f5";
		}
		else if(j==6){
			m= "f6";
		}
		else if(j==7){
			m= "f7";
		}
		else if(j==8){
			m= "f8";
		}
	}
	else if(i==7){
		if(j==0){
			m= "g0";
		}
		else if(j==1){
			m= "g1";
		}
		else if(j==2){
			m= "g2";
		}
		else if(j==3){
			m= "g3";
		}
		else if(j==4){
			m= "g4";
		}
		else if(j==5){
			m= "g5";
		}
		else if(j==6){
			m= "g6";
		}
		else if(j==7){
			m= "g7";
		}
		else if(j==8){
			m= "g8";
		}
	}
	else if(i==8){
		if(j==0){
			m= "h0";
		}
		else if(j==1){
			m= "h1";
		}
		else if(j==2){
			m= "h2";
		}
		else if(j==3){
			m= "h3";
		}
		else if(j==4){
			m= "h4";
		}
		else if(j==5){
			m= "h5";
		}
		else if(j==6){
			m= "h6";
		}
		else if(j==7){
			m= "h7";
		}
		else if(j==8){
			m= "h8";
		}
	}
	else if(i==9){
		if(j==0){
			m= "i0";
		}
		else if(j==1){
			m= "i1";
		}
		else if(j==2){
			m= "i2";
		}
		else if(j==3){
			m= "i3";
		}
		else if(j==4){
			m= "i4";
		}
		else if(j==5){
			m= "i5";
		}
		else if(j==6){
			m= "i6";
		}
		else if(j==7){
			m= "i7";
		}
		else if(j==8){
			m= "i8";
		}
	}
	return m;
}

//calculates all possible moves for HUMAN and stores then in a queue
void Checkers::compute_moves(std::queue<std::string>& moves) const{
	string m="";
	for(char a='b';a<='j';a++){
	 for(char i='1';i<='9';i++){
	  for(char b='b';b<='j';b++){
	   if((abs(a-b) >= '3')){continue;}
	   for(char j='1';j<='9';j++){
	    if (abs(i-j >= '3')){continue;}
		m=a;
		m+=i;
		m+=b;
		m+=j;
		cout<<"   "<<m<<"    ";
		if(is_legal(m)){moves.push(m);}
	   }
	  }
   	 }
	}
   }
/*board layout note so I don't 
			have to scroll all the way up

		 0 1 2 3 4 5 6 7 8 9
	a	{b b b b b b b b b b},
	b	{b b a b a b a b a b},
	c	{b a b a b a b a b b},
	d	{b b a b a b a b a b},
	e	{b a b a b a b a b b},
	f	{b b a b a b a b a b},
	g	{b a b a b a b a b b},
	h	{b b a b a b a b a b},
	i	{b a b a b a b a b b},
	j	{b b b b b b b b b b}};
*/
