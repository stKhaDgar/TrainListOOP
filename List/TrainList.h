
#include <iostream>
#include <string>
#include <sstream>
#include "RailwayCarriage.h"

using namespace std;

class TrainList
{
protected:
	RailwayCarriage *first, *last;
public:
	TrainList()
	{
		last = NULL;
		first = NULL;
	}

	void AddFirst(RailwayCarriage* vagon);
	void AddLast(RailwayCarriage* vagon);
	void AddPos(RailwayCarriage* vagon, int pos);
	void RemovePos(int pos);
	int size();
	RailwayCarriage* begin();
	RailwayCarriage* end();
	string printTrain();
	string filter(string _type, bool _cond, bool _wifi);

	
};