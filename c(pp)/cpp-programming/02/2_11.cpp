//2_11.cpp
#include<iostream>
using namespace std;
enum game_result {WIN, LOSE, TIE, CANCEL};
int main()
{
	game_result result;   //when declaring the variable,
		              //you can omit the keyword enum
	enum game_result omit = CANCEL; //you can also write enum before
	                                //type name
	int count;
	for(count = WIN; count <= CANCEL; count++)
	{
		result = (game_result)count;
		if(result == omit)
		{
			cout << "The game was cancelled.\n";
		}
		else
		{
			cout << "The game was played ";
			if(result == WIN)
				cout << "and we won!";
			else if(result == LOSE)
				cout << "and we lost.";
			else
				cout << "\b.";
			cout << "\n";
		}
	}
}
