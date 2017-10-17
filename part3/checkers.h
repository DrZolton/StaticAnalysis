// **************************************************************************
// Jacob Ramsey    April 24, 2017    CS2401    Project 6
// This class is a child of the "game" class within the main_savitch_14
// namespace. It contains an array of spaces(space.h) that represent a
// checkers board and the functions to play through a checkers game.
// **************************************************************************

#ifndef CHECKERS_H
#define CHECKERS_H

#include "space.h"
#include "game.h"
#include <queue>
#include <string>

namespace main_savitch_14{

class Checkers:public game{
    public:
	Checkers(){;}
	Checkers(const Checkers& original){
	    *this = original;
	}

	bool is_game_over()const;
        void make_move(const std::string& move);
        void restart();
	void display_status()const;
	bool is_legal(const std::string& move)const;

	//helper functions for is_legal()
	bool is_on_board(const std::string& move)const;
	bool is_playable_space(const std::string& move)const;
	bool is_empty_start(const std::string& move)const;//is the starting position empty
        bool is_empty_end(const std::string& move)const;//is the ending position empty
	bool is_direction(const std::string& move)const;//is the piece traveling in a legal direction
        bool is_your_piece(const std::string& move)const;
	bool is_jump(const std::string& move)const;
        bool is_double_jump(const std::string& move)const;
        bool is_triple_jump(const std::string& move)const;
        bool is_adjacent(const std::string& move)const;
        bool is_jump_available()const;

        bool needs_kinging(const std::string& move)const;
        bool is_move_available()const;
	game* clone()const;
	void compute_moves(std::queue<std::string>& moves)const;
	int evaluate()const;
    private:
	Space board[8][8];
};
}

#endif
