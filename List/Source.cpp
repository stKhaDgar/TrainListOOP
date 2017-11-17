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

	int menu = 1;
	RailwayCarriage *vagon325 = new RailwayCarriage("065um", "Suite", false, false);
	Train.AddLast(vagon325);
	Train.AddLast(vagon325);
	Train.AddLast(vagon325);

	string number;
	string typeofrc;
	string cond; bool bcond;
	string wifi; bool bwifi;

	while (menu != 9)
	{
		std::system("cls");
		cout << "\n------------------------------  Ваш состав  ------------------------------\n\n";

		if (Train.size() < 1)
		{
			cout << "К сожалению ваш состав пока что пуст.\n\n";
		}
		else
		{
			cout << Train.printTrain();
		}
		
		cout << endl;
		switch (menu)
		{
		// Главное меню	
		case(1):
			cout << "----------------------------- 1. Главное меню ----------------------------\n\n";
			cout << "2. Добавить вагон в начало.\n";
			cout << "3. Добавить вагон в конец.\n";
			cout << "4. Добавить вагон в позицию.\n";
			cout << "5. Удалить вагон в позиции.\n";
			cout << "6. Отфильтровать по типу вагона/наличии кондиционера/наличии wi-fi.\n";
			cout << "7. Выход из программы.\n\n";
			do
			{
				cout << "Выберите необходимый пункт меню: ";
				cin >> menu;
				if (menu < 2 || menu > 7)
				{
					cout << "Такого пункта меню не существует, попробуйте ещё раз.\n";
				}
			} while (menu < 2 || menu > 7);
			break;
		case(2):
			cout << "---------------------- 2. Добавление вагона в начало ---------------------\n\n";
			
			do
			{
				cout << "Введите номер вагона(пять символов): ";
				
				cin >> number;
				if (number.size() != 5)
				{
					cout << "Попробуйте ещё раз.\n";
				}
			} while (number.size() != 5);
			do
			{
				cout << "Введите тип вагона(Reserved, Compartment, Suite, Restaurant): ";
				cin >> typeofrc;
				if (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1)
				{
					cout << "Такого типа к сожалению в моей программе не существует(та и по заданию как бы не было :)\n";
				}
			} while (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1);
			do
			{
				cout << "Укажите наличие кондиционера в вагоне(Yes/No): ";
				cin >> cond;
				if (!cond.compare("Yes") != 1 && !cond.compare("No") != 1)
				{
					cout << "Такого варианта ответа не существует. Попробуйте ещё раз.\n";
				}
				else
				{
					if (cond == "Yes")
					{
						bcond = true;
					}
					else
					{
						bcond = false;
					}
				}
			} while (!cond.compare("Yes") != 1 && !cond.compare("No") != 1);

			do
			{
				cout << "Укажите наличие Wi-Fi в вагоне(Yes/No): ";
				cin >> wifi;
				if (!wifi.compare("Yes") != 1 && !wifi.compare("No") != 1)
				{
					cout << "Такого варианта ответа не существует. Попробуйте ещё раз.\n";
				}
				else
				{
					if (wifi == "Yes")
					{
						bwifi = true;
					}
					else
					{
						bwifi = false;
					}
				}
			} while (!wifi.compare("Yes") != 1 && !wifi.compare("No") != 1);

			RailwayCarriage *vagon = new RailwayCarriage(number, typeofrc, bcond, bwifi);
			Train.AddFirst(vagon);
			menu = 1;
			break;
		}
	}
	
	cout << endl << endl;
	std::system("pause");
	return 0;
}