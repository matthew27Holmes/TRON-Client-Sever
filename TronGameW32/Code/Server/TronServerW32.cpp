#include"Sever.h"

int main()
{
	
	Sever*_sever = new Sever();
	_sever->runServer();
	

	while (true)
	{
		//std::cin.get();
		//_sever->connect();
	}

    return 0;
}


