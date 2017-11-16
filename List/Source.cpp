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

	RailwayCarriage *vagon = new RailwayCarriage("065um", "Плацкарт", false, false);
	RailwayCarriage *vagon1 = new RailwayCarriage("093ap", "Купе", true, false);
	RailwayCarriage *vagon2 = new RailwayCarriage("048yn", "Люкс", true, true);
	RailwayCarriage *vagon3 = new RailwayCarriage("033tm", "Вагон-ресторан", false, false);
	RailwayCarriage *vagon4 = new RailwayCarriage("023um", "Плацкарт", true, true);

	
	Train.AddLast(vagon);
	Train.AddLast(vagon1);
	Train.AddLast(vagon2);
	Train.AddLast(vagon3);
	Train.AddLast(vagon4);
	
	cout << endl;

	cout << Train.printTrain();

	cout << endl;

	cout << endl << endl;

	cout << Train.filter("Плацкарт", true, false);

	cout << endl;
	system("pause");
	return 0;
}