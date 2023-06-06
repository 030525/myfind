#include <boost/thread.hpp>
#include <boost/asio.hpp>

#include <iostream>
void func1()
{
	for(int i = 0;i < 10;i++)
	{
		std::cout << "func1" << "\n";
	}
}

void func2()
{
	for(int i = 0;i < 10;i++)
	{
		std::cout << "func2" << "\n";
	}
}

void func3()
{
	for(int i = 0;i < 10;i++)
	{
		std::cout << "func3" << "\n";
	}
}

void func4()
{
	for(int i = 0;i < 10;i++)
	{
		std::cout << "func4" << "\n";
	}
}

int main(int argc, char** argv)
{
	boost::asio::thread_pool pool(2);

	boost::asio::post(pool,func1);
	boost::asio::post(pool,func2);
	boost::asio::post(pool,func3);
	boost::asio::post(pool,func4);

	pool.join();

	return 0;

}


