/*********************************************
	Alya ElGamal
	4/8/2017
	main.cc
	Description: Implements our main
*********************************************/
#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include "game.h"     // Provides definition of game class
#include "colors.h"
#include"Checkers.h"
using namespace std;
using namespace main_savitch_14;

int main(){
	Checkers mygame;
	mygame.play();
	return 0;
}
