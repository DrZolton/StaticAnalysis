/******************************************
	Alya ElGamal
	4/6/2017
	Chore.cc
	Desription: implementation of the 
		fucntions in Chore.h
******************************************/
#include<queue>
#include<iostream>
#include"Chore.h"
using namespace std;

bool Chore::operator <(const Chore c1)const{
	int c1Num=c1.getPriorityNum(c1);
	return priorityNum<c1Num;
}

std::ostream& Chore::output(std::ostream& cout)const{
	cout<<endl<<"Chore: "<<choreName<<endl;
	cout<<"chore Priority: "<<priorityNum; 
}

std::istream& Chore::input(std::istream& cin){
	cout<<endl<< "Enter chore name:";
	cin >>choreName;
	cout<<endl<<"Enter priority number:";
	cin >>priorityNum;
}
