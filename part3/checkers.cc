// **************************************************************************
// Jacob Ramsey    April 24, 2017    CS2401    Project 6
// This class is a child of the "game" class within the main_savitch_14
// namespace. It contains an array of spaces(space.h) that represent a
// checkers board and the functions to play through a checkers game.
// **************************************************************************

#include "checkers.h"
#include "game.h"
#include "space.h"
#include "colors.h"
#include<iostream>

using namespace std;
namespace main_savitch_14{

bool Checkers::is_game_over()const{
    if(!is_move_available())
	return true;
    else
        return false;
}

void Checkers::make_move(const string& move){
    int x_start, y_start, x_end, y_end;
    x_start = int(move[0] - 'a');
    y_start = int(move[1] - '1');
    x_end = int(move[2] - 'a');
    y_end = int(move[3] - '1');

    if(is_jump(move)){
	int x_mid, y_mid;

        x_mid = (x_start + x_end)/2;
        y_mid = (y_start + y_end)/2;

        board[x_mid][y_mid].make_empty();

        if(board[x_start][y_start].is_red()){
            board[x_start][y_start].make_empty();
	    if(needs_kinging(move))
		board[x_end][y_end].make_red_king();
	    else
                board[x_end][y_end].make_red();
        }
        else if(board[x_start][y_start].is_red_king()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_red_king();
        }
        else if(board[x_start][y_start].is_black()){
            board[x_start][y_start].make_empty();
	    if(needs_kinging(move))
		board[x_end][y_end].make_black_king();
	    else
                board[x_end][y_end].make_black();
        }
        else if(board[x_start][y_start].is_black_king()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_black_king();
        }
    }
    else{
        if(board[x_start][y_start].is_red()){
            board[x_start][y_start].make_empty();
            if(needs_kinging(move))
                board[x_end][y_end].make_red_king();
            else
                board[x_end][y_end].make_red();
        }
        else if(board[x_start][y_start].is_red_king()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_red_king();
        }
        else if(board[x_start][y_start].is_black()){
            board[x_start][y_start].make_empty();
            if(needs_kinging(move))
                board[x_end][y_end].make_black_king();
            else
                board[x_end][y_end].make_black();
        }
        else if(board[x_start][y_start].is_black_king()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_black_king();
        }
    }

    if(move.length() >= 6){
        x_start = int(move[2] - 'a');
        y_start = int(move[3] - '1');
        x_end = int(move[4] - 'a');
        y_end = int(move[5] - '1');

        int x_mid, y_mid;

        x_mid = (x_start + x_end)/2;
        y_mid = (y_start + y_end)/2;

        board[x_mid][y_mid].make_empty();

        if(board[x_start][y_start].is_red()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_red();
        }
        else if(board[x_start][y_start].is_red_king()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_red_king();
        }
        else if(board[x_start][y_start].is_black()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_black();
        }
        else if(board[x_start][y_start].is_black_king()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_black_king();
        }
    }

    if(move.length() >= 8){
        x_start = int(move[4] - 'a');
        y_start = int(move[5] - '1');
        x_end = int(move[6] - 'a');
        y_end = int(move[7] - '1');

        int x_mid, y_mid;

        x_mid = (x_start + x_end)/2;
        y_mid = (y_start + y_end)/2;

        board[x_mid][y_mid].make_empty();

        if(board[x_start][y_start].is_red()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_red();
        }
        else if(board[x_start][y_start].is_red_king()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_red_king();
        }
        else if(board[x_start][y_start].is_black()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_black();
        }
        else if(board[x_start][y_start].is_black_king()){
            board[x_start][y_start].make_empty();
            board[x_end][y_end].make_black_king();
        }

    }

    game::make_move(move);
}

void Checkers::restart(){
    Space non_playable, red, black, empty;
    non_playable.make_non_play();
    red.make_red();
    black.make_black();
    empty.make_empty();

    board[0][0] = board[2][0] = board[4][0] = board[6][0] = non_playable;
    board[1][1] = board[3][1] = board[5][1] = board[7][1] = non_playable;
    board[0][2] = board[2][2] = board[4][2] = board[6][2] = non_playable;
    board[1][3] = board[3][3] = board[5][3] = board[7][3] = non_playable;
    board[0][4] = board[2][4] = board[4][4] = board[6][4] = non_playable;
    board[1][5] = board[3][5] = board[5][5] = board[7][5] = non_playable;
    board[0][6] = board[2][6] = board[4][6] = board[6][6] = non_playable;
    board[1][7] = board[3][7] = board[5][7] = board[7][7] = non_playable;

    board[1][0] = board[3][0] = board[5][0] = board[7][0] = empty;
    board[0][1] = board[2][1] = board[4][1] = board[6][1] = empty;
    board[1][2] = board[3][2] = board[5][2] = board[7][2] = empty;
    board[5][2] = red;

    board[1][0] = board[3][0] = board[5][0] = board[7][0] = red;
    board[0][1] = board[2][1] = board[4][1] = board[6][1] = red;
    board[1][2] = board[3][2] = board[5][2] = board[7][2] = red;

    board[0][5] = board[2][5] = board[4][5] = board[6][5] = black;
    board[1][6] = board[3][6] = board[5][6] = board[7][6] = black;
    board[0][7] = board[2][7] = board[4][7] = board[6][7] = black;

    board[0][3] = board[2][3] = board[4][3] = board[6][3] = empty;
    board[1][4] = board[3][4] = board[5][4] = board[7][4] = empty;

    game::restart();
}

void Checkers::display_status()const{
//    if(!is_game_over()){
        for(int i = 0; i < 50; i++)
	    cout << endl;
//	cout << "Last move: " << move << endl;
        cout << BOLD << "     A     B     C     D     E     F     G     H" << endl
             << "   ------------------------------------------------" << RESET << endl;
        for(int y = 0; y < 8; y++){
	    for(int line = 0; line < 3; line++){
	        if(line == 1)
		    cout << BOLD << y + 1 << " |" << RESET;
	        else
		    cout << BOLD << "  |";
	        for(int x = 0; x < 8; x++){
		    if((x + y)%2 == 0)
		        cout << B_RED << "      " << RESET;
		    else if(line == 0 || line == 2)
		        cout << "      ";
		    else if(board[x][y].is_red())
		        cout << RED << BOLD << "  @   " << RESET;
		    else if(board[x][y].is_black())
		        cout << CYAN << BOLD << "  @   " << RESET;
		    else if(board[x][y].is_red_king())
		        cout << RED << BOLD << "  K   " << RESET;
                    else if(board[x][y].is_black_king())
                        cout << CYAN << BOLD << "  K   " << RESET;
		    else if(board[x][y].is_empty())
		        cout << "      ";
	        }
                cout << BOLD << "|" << RESET << endl;
	    }
        }
        cout << BOLD << "   ------------------------------------------------" << RESET << endl;
    if(!is_game_over()){
        if(last_mover() == COMPUTER)
	    cout << "Blue's Turn\n";
        else
	    cout << "Red's Turn\n";
    }
//    }
    else{
	cout << endl;
	if(last_mover() == COMPUTER && !is_move_available())
	    cout << "   Red Wins!\n";
	else if(last_mover() == HUMAN && !is_move_available())
	    cout << "   Blue Wins!\n";
    }

}

bool Checkers::is_legal(const string& move)const{
    if(!is_on_board(move))
	return false;
    else if(!is_playable_space(move))
    	return false;
    else if(is_empty_start(move))
    	return false;
    else if(!is_empty_end(move))
	return false;
    else if(!is_direction(move))
	return false;
    else if(!is_your_piece(move))
	return false;
    else if(!is_adjacent(move) && !is_jump(move))
	return false;
    else if(is_jump_available() && !is_jump(move)){
//	cout << "A jump is available\n";
	return false;
    }
    if(move.length() >= 6){
	if(is_adjacent(move))
	    return false;
        if(!is_on_board(move.substr(2, 4))){
//	    cout << "Not on board\n";
            return false;
	}
        else if(!is_playable_space(move.substr(2, 4))){
//	    cout << "Not playable\n";
            return false;
	}
        else if(!is_empty_end(move.substr(2, 4))){
//	    cout << "Not empty end\n";
            return false;
	}
        else if(!is_direction(move.substr(2, 4))){
//	    cout << "Wrong Direction\n";
            return false;
	}
        else if(!is_double_jump(move)){
//	    cout << "Not a double jump\n";
            return false;
	}
    }

    if(move.length() >= 8){
        if(!is_on_board(move.substr(4, 4))){
//            cout << "Not on board\n";
            return false;
        }
        else if(!is_playable_space(move.substr(4, 4))){
//            cout << "Not playable\n";
            return false;
        }
        else if(!is_empty_end(move.substr(4, 4))){
//            cout << "Not empty end\n";
            return false;
        }
        else if(!is_direction(move.substr(4, 4))){
//            cout << "Wrong Direction\n";
            return false;
        }
        else if(!is_triple_jump(move)){
//            cout << "Not a double jump\n";
            return false;
        }
    }
    return true;

}

bool Checkers::is_on_board(const string& move)const{
    int collumn, row;

    collumn = int(move[0] - 'a');
    row = int(move[1] - '1');
    if(collumn > 7 || collumn < 0 || row > 7 || row < 0)
	return false;

    collumn = int(move[2] - 'a');
    row = int(move[3] - '1');
    if(collumn > 7 || collumn < 0 || row > 7 || row < 0)
        return false;
    else
	return true;
}

bool Checkers::is_playable_space(const string& move)const{
    int collumn, row;

    collumn = int(move[0] - 'a');
    row = int(move[1] - '1');
    if((collumn + row)%2 == 0)
        return false;

    collumn = int(move[2] - 'a');
    row = int(move[3] - '1');
    if((collumn + row)%2 == 0)
        return false;
    else
        return true;
}

bool Checkers::is_empty_start(const string& move)const{
    int collumn, row;

    collumn = int(move[0] - 'a');
    row = int(move[1] - '1');
    if(board[collumn][row].is_empty())
	return true;
    else
	return false;
}

bool Checkers::is_empty_end(const string& move)const{
    int collumn, row;

    collumn = int(move[2] - 'a');
    row = int(move[3] - '1');
    if(board[collumn][row].is_empty())
        return true;
    else
	return false;
}

bool Checkers::is_direction(const string& move)const{
    int y1, y2, x;

    x = int(move[0] - 'a');
    y1 = int(move[1] - '1');
    y2 = int(move[3] - '1');
    if(board[x][y1].is_red_king() || board[x][y1].is_black_king())
	return true;

    if(last_mover() == HUMAN)
	return((y2 - y1) > 0);
    else
        return((y2 - y1) < 0);
}

bool Checkers::is_your_piece(const string& move)const{
    int collumn, row;

    collumn = int(move[0] - 'a');
    row = int(move[1] - '1');
    if(last_mover() == HUMAN)
        return(board[collumn][row].is_red() || board[collumn][row].is_red_king());
    else
        return(board[collumn][row].is_black() || board[collumn][row].is_black_king());
}

bool Checkers::is_jump(const string& move)const{
    int x_start, y_start, x_end, y_end, x_mid, y_mid;

    x_start = int(move[0] - 'a');
    y_start = int(move[1] - '1');
    x_end = int(move[2] - 'a');
    y_end = int(move[3] - '1');

    if(x_end - x_start == 2 || x_end - x_start == -2){
	if(y_end - y_start == 2 || y_end - y_start == -2){
	    x_mid = (x_start + x_end)/2;
	    y_mid = (y_start + y_end)/2;
	    if(board[x_start][y_start].is_red() || board[x_start][y_start].is_red_king())
		return(board[x_mid][y_mid].is_black() || board[x_mid][y_mid].is_black_king());
	    else
                return(board[x_mid][y_mid].is_red() || board[x_mid][y_mid].is_red_king());
	}
    }
    return false;
}

bool Checkers::is_double_jump(const string& move)const{
    int x_start, y_start, x_end, y_end, x_mid, y_mid;
    bool red; // true for red, false for black

    x_start = int(move[0] - 'a');
    y_start = int(move[1] - '1');
    if(board[x_start][y_start].is_red() || board[x_start][y_start].is_red_king())
	red = true;
    else
	red = false;

    x_start = int(move[2] - 'a');
    y_start = int(move[3] - '1');
    x_end = int(move[4] - 'a');
    y_end = int(move[5] - '1');

    if(x_end - x_start == 2 || x_end - x_start == -2){
        if(y_end - y_start == 2 || y_end - y_start == -2){
            x_mid = (x_start + x_end)/2;
            y_mid = (y_start + y_end)/2;
            if(red)
                return(board[x_mid][y_mid].is_black() || board[x_mid][y_mid].is_black_king());
            else
                return(board[x_mid][y_mid].is_red() || board[x_mid][y_mid].is_red_king());
        }
    }
    return false;
}

bool Checkers::is_triple_jump(const string& move)const{
    int x_start, y_start, x_end, y_end, x_mid, y_mid;
    bool red; // true for red, false for black

    x_start = int(move[0] - 'a');
    y_start = int(move[1] - '1');
    if(board[x_start][y_start].is_red() || board[x_start][y_start].is_red_king())
        red = true;
    else
        red = false;

    x_start = int(move[4] - 'a');
    y_start = int(move[5] - '1');
    x_end = int(move[6] - 'a');
    y_end = int(move[7] - '1');

    if(x_end - x_start == 2 || x_end - x_start == -2){
        if(y_end - y_start == 2 || y_end - y_start == -2){
            x_mid = (x_start + x_end)/2;
            y_mid = (y_start + y_end)/2;
            if(red)
                return(board[x_mid][y_mid].is_black() || board[x_mid][y_mid].is_black_king());
            else
                return(board[x_mid][y_mid].is_red() || board[x_mid][y_mid].is_red_king());
        }
    }
    return false;
}

bool Checkers::is_adjacent(const string& move)const{
    int x_start, y_start, x_end, y_end;

    x_start = int(move[0] - 'a');
    y_start = int(move[1] - '1');
    x_end = int(move[2] - 'a');
    y_end = int(move[3] - '1');

    if(x_end - x_start == 1 || x_end - x_start == -1){
	if(y_end - y_start == 1 || y_end - y_start == -1)
	    return true;
	else
	    return false;
    }
    else
	return false;
}

bool Checkers::is_jump_available()const{
    for(int y = 0; y < 8; y++){
	for(int x = 0; x < 8; x++){

            if(last_mover() == COMPUTER){
		if(board[x][y].is_black()){
		    if(board[x+1][y-1].is_red() || board[x+1][y-1].is_red_king()){
			if(board[x+2][y-2].is_empty())
			    return true;
		    }
                    if(board[x-1][y-1].is_red() || board[x-1][y-1].is_red_king()){
                        if(board[x-2][y-2].is_empty())
                            return true;
                    }
		}
                else if(board[x][y].is_black_king()){
                    if(board[x+1][y-1].is_red() || board[x+1][y-1].is_red_king()){
                        if(board[x+2][y-2].is_empty())
                            return true;
                    }
                    if(board[x-1][y-1].is_red() || board[x-1][y-1].is_red_king()){
                        if(board[x-2][y-2].is_empty())
                            return true;
                    }
                    if(board[x+1][y+1].is_red() || board[x+1][y+1].is_red_king()){
                        if(board[x+2][y+2].is_empty())
                            return true;
                    }
                    if(board[x-1][y+1].is_red() || board[x-1][y+1].is_red_king()){
                        if(board[x-2][y+2].is_empty())
                            return true;
                    }
                }
            }
            else{
                if(board[x][y].is_red()){
                    if(board[x+1][y+1].is_black() || board[x+1][y+1].is_black_king()){
                        if(board[x+2][y+2].is_empty())
                            return true;
                    }
                    if(board[x-1][y+1].is_black() || board[x-1][y+1].is_black_king()){
                        if(board[x-2][y+2].is_empty())
                            return true;
                    }
                }
                else if(board[x][y].is_red_king()){
                    if(board[x+1][y-1].is_black() || board[x+1][y-1].is_black_king()){
                        if(board[x+2][y-2].is_empty())
                            return true;
                    }
                    if(board[x-1][y-1].is_black() || board[x-1][y-1].is_black_king()){
                        if(board[x-2][y-2].is_empty())
                            return true;
                    }
                    if(board[x+1][y+1].is_black() || board[x+1][y+1].is_black_king()){
                        if(board[x+2][y+2].is_empty())
                            return true;
                    }
                    if(board[x-1][y+1].is_black() || board[x-1][y+1].is_black_king()){
                        if(board[x-2][y+2].is_empty())
                            return true;
                    }
                }
            }

	}
    }
    return false;

}

bool Checkers::needs_kinging(const string& move)const{
    int y_end;

//    y_end = int(move[3] - '1');
    y_end = int(move[move.length() - 1] - '1');

    if(last_mover() == COMPUTER){ //black piece
	if(y_end == 0)
	    return true;
    }
    else{ //red piece
	if(y_end == 7)
	    return true;
    }
    return false;
}

bool Checkers::is_move_available()const{
    if(!is_jump_available()){
        for(int y = 0; y < 8; y++){
            for(int x = 0; x < 8; x++){

                if(last_mover() == COMPUTER){
                    if(board[x][y].is_black()){
		        if(board[x + 1][y - 1].is_empty() || board[x - 1][y - 1].is_empty())
			    return true;
                    }
                    else if(board[x][y].is_black_king()){
		        if(board[x + 1][y - 1].is_empty() || board[x - 1][y - 1].is_empty() || board[x - 1][y + 1].is_empty() || board[x + 1][y + 1].is_empty())
                            return true;
                    }
                }
                else{
                    if(board[x][y].is_red()){
                        if(board[x + 1][y + 1].is_empty() || board[x - 1][y + 1].is_empty())
                            return true;
                    }
                    else if(board[x][y].is_red_king()){
                        if(board[x + 1][y - 1].is_empty() || board[x - 1][y - 1].is_empty() || board[x - 1][y + 1].is_empty() || board[x + 1][y + 1].is_empty())
                            return true;
                    }
                }

            }
        }
    }
    else
	return true;
    return false;
}

game* Checkers::clone()const{
    return new Checkers(*this);
}

void Checkers::compute_moves(queue<string>& moves)const{
    string move;

    for(int row1 = 0; row1 < 8; row1++){
	for(int collumn1 = 0; collumn1 < 8; collumn1++){
	    for(int row2 = 0; row2 < 8; row2++){
		for(int collumn2 = 0; collumn2 < 8; collumn2++){
                    move = char(row1 + 97);
                    move += char(collumn1 + 49);
                    move += char(row2 + 97);
                    move += char(collumn2 + 49);
                    if(is_legal(move))
                        moves.push(move);
		    for(int row3 = 0; row3 < 8; row3++){
			for(int collumn3 = 0; collumn3 < 8; collumn3++){
                    	    move += char(row3 + 97);
                    	    move += char(collumn3 + 49);
                    	    if(is_legal(move))
                        	moves.push(move);
			}
		    }
		}
	    }
	}
    }
/*
    for(int row1 = 0; row1 < 8; row1++){
        for(int collumn1 = 0; collumn1 < 8; collumn1++){
            for(int row2 = 0; row2 < 8; row2++){
                for(int collumn2 = 0; collumn2 < 8; collumn2++){
		    for(int row3 = 0; row3 < 8; row3++){
			for(int collumn3 = 0; collumn3 < 8; collumn3++){
                    	    move = char(row1 + 97);
                    	    move += char(collumn1 + 49);
                    	    move += char(row2 + 97);
                    	    move += char(collumn2 + 49);
                            if(is_legal(move))
                                moves.push(move);
                            move += char(row3 + 97);
                            move += char(collumn3 + 49);
                    	    if(is_legal(move))
                                moves.push(move);
			}
		    }
                }
            }
        }
    }
*/
}

int Checkers::evaluate()const{
    int red_count = 0, black_count = 0;

    for(int row = 0; row < 8; row++){
	for(int collumn = 0; collumn < 8; collumn++){
	    if(board[row][collumn].is_red())
		red_count++;
	    else if(board[row][collumn].is_red_king())
                red_count += 3;
	    else if(board[row][collumn].is_black())
		black_count++;
	    else if(board[row][collumn].is_black_king())
                black_count += 3;
	}
    }

    return red_count - black_count;
}

}
