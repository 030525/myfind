#include "MatchData.h"

int main(int argc, char** argv)
{
	MatchData a;
	std::vector<std::string> b = {"123","abc"};
	a.setMatch(std::move(b));
	a.getMatch();
	return 0;

}



