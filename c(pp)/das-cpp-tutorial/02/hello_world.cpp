#include<iostream>

int main()
{
	std::cout<<"Viel Spaß nun mit C++!\n";
	
	// original, funktioniert nur auf Windows
	//system("pause");
	
	// funktioniert auf Linux
	//system("read -p 'Drücken Sie bitte eine Taste, um fortzufahren...' var"); 
	
	// bessere Praxis
	std::cout<<"Drücken Sie bitte eine Taste, um fortzufahren:";
        std::getchar();	
	return 0;
}
