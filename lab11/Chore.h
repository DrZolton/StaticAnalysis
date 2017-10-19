/*******************************************
	Alya ElGamal
	4/6/2017
	Chore.h
	Creates a single chore element
*******************************************/
#include<queue>
#include<iostream>
#include<fstream>
using namespace std;
//#ifndef CHORE_H;
//#define CHORE_H;

class Chore{
	public:
		Chore(){priorityNum=0;choreName="";}
		std::string getName (Chore c1)const{return choreName;}
		int getPriorityNum(Chore c1)const{return priorityNum;}
		bool operator <(const Chore c1)const;
		std::ostream& output(std::ostream& cout)const;
		std::istream& input(std::istream& cin);
	private:
		std::string choreName;
		int priorityNum;
};
//#endif
