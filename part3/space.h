// **************************************************************************
// Jacob Ramsey    April 24, 2017    CS2401    Project 6
// This class makes up the squares of a checkers board. It holds the state of
// each square(red piece, black piece, empty, etc.) and contains accessor and
// mutator functions.
// **************************************************************************


#ifndef SPACE_H
#define SPACE_H

namespace main_savitch_14{

class Space{
    public:
	//mutator functions
	void make_non_play(){state = 'a';}
	void make_empty(){state = 'b';}
	void make_black(){state = 'c';}
	void make_black_king(){state = 'd';}
	void make_red(){state = 'e';}
	void make_red_king(){state = 'f';}

	//accessor function
	char get_state()const{return state;}
	bool is_non_play()const{return state == 'a';}
        bool is_empty()const{return state == 'b';}
        bool is_black()const{return state == 'c';}
        bool is_black_king()const{return state == 'd';}
        bool is_red()const{return state == 'e';}
        bool is_red_king()const{return state == 'f';}

    private:
	char state;
	/*
	possible states
	a = non-playable
	b = empty
	c = black
	d = black king
	e = red
	f = red king
	*/
};
}

#endif
