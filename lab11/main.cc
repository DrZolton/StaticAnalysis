/****************************************
	Alya ElGamal
	4/6/2017
	main.cc
	Description: The main function of
		the lab
****************************************/
#include<queue>
#include<iostream>
#include"Chore.h"
using namespace std;

int main(){
	std::priority_queue<Chore>myChores;
	Chore tmp;
	bool enterAnother=true;

	//input loop
	while(enterAnother){
		char c;//checks if they want to continue
		tmp.input(cin);
		myChores.push(tmp);
		cout<<endl<<"Want to enter another chore?(y for yes, n for no)";
		cin >>c;
		if(c=='y'|| c=='Y')
			enterAnother=true;
		else
			enterAnother=false;
	}

	//output loop
	while(!myChores.empty()){
		tmp = myChores.top();
		myChores.top().output(cout);
		myChores.pop();
	}
}
