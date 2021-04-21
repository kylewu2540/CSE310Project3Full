#include <iostream>
#include <string>
using namespace std;
  
int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		cout << "Not enough arguments. Program will terminate." << endl;
	}
	
	string file(argv[1]);
	string direction(argv[2]);
  
    return 0;
}
