#include <iostream>
#include "RailwayCarriage.h"
#include "TrainList.h"
#include <string>
#include <sstream>
using namespace std;



int main()
{
	setlocale(0, "");

	TrainList Train;

	RailwayCarriage *vagon = new RailwayCarriage("065um", "��������", false, false);
	RailwayCarriage *vagon1 = new RailwayCarriage("093ap", "����", true, false);
	RailwayCarriage *vagon2 = new RailwayCarriage("048yn", "����", true, true);
	RailwayCarriage *vagon3 = new RailwayCarriage("071um", "��������", false, true);
	RailwayCarriage *vagon4 = new RailwayCarriage("033tm", "�����-��������", false, false);
	RailwayCarriage *vagon5 = new RailwayCarriage("023um", "��������", true, false);
	RailwayCarriage *vagon6 = new RailwayCarriage("023um", "��������", true, true);

	
	Train.AddLast(vagon);
	Train.AddLast(vagon1);
	Train.AddLast(vagon2);
	Train.AddLast(vagon3);
	Train.AddLast(vagon4);
	Train.AddLast(vagon5);
	Train.AddLast(vagon6);
	
	cout << endl;

	cout << Train.printTrain();


	cout << endl << endl;
	system("pause");
	return 0;
}