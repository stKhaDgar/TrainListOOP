#include <iostream>
#include "RailwayCarriage.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <list>
#include <algorithm>
using namespace std;



int main()
{
	setlocale(0, "");

	// STL

	list<RailwayCarriage*> Train;

	int menu = 1;
	RailwayCarriage *vagon1 = new RailwayCarriage("093da", "Suite", false, false);
	RailwayCarriage *vagon2 = new RailwayCarriage("065um", "Compartment", true, false);
	RailwayCarriage *vagon3 = new RailwayCarriage("034as", "Restaurant", false, true);
	RailwayCarriage *vagon4 = new RailwayCarriage("sm342", "Reserved", true, true);
	RailwayCarriage *vagon5 = new RailwayCarriage("fst22", "Suite", false, true);
	RailwayCarriage *vagon6 = new RailwayCarriage("fer27", "Reserved", true, false);

	// STL

	Train.push_back(vagon1);
	Train.push_back(vagon2);
	Train.push_back(vagon3);
	Train.push_back(vagon4);
	Train.push_back(vagon5);
	Train.push_back(vagon6);

	string number;
	string typeofrc;
	string cond; bool bcond;
	string wifi; bool bwifi;
	int pos;
	
	while (menu != 7)
	{
		// STL

		list<RailwayCarriage*>::iterator ptrs = Train.begin();

		std::system("cls");
		cout << "\n------------------------------  Ваш состав  ------------------------------\n\n";
		int count = 1;
		if (Train.size() < 1)
		{
			cout << "К сожалению ваш состав пока что пуст.\n\n";
		}
		else
		{

			//STL

			for (auto ptr = Train.begin(); ptr != Train.end(); ++ptr)
			{
				cout << count << ". " << (*ptr)->print();
				count++;
			}
		}
		
		cout << endl;
		switch (menu)
		{
		// 1. Главное меню	
		case(1):
			cout << "----------------------------- 1. Главное меню ----------------------------\n\n";
			cout << "2. Добавить вагон в начало.\n";
			cout << "3. Добавить вагон в конец.\n";
			cout << "4. Добавить вагон в позицию.\n";
			cout << "5. Удалить вагон в позиции.\n";
			cout << "6. Поиск по типу вагона.\n";
			cout << "7. Выход из программы.\n\n";
			do
			{
				cout << "Выберите необходимый пункт меню: ";
				cin >> menu;
				if (menu < 2 || menu > 7 || (menu == 5 && Train.size() == 0))
				{
					if (menu < 1 || menu > 8)
					{
						cout << "Такого пункта меню не существует, попробуйте ещё раз.\n";
					}
					else if (menu == 5 && Train.size() == 0)
					{
						cout << "Ваш состав пуст. Сначала добавьте вагоны.\n";
					}
					else if (menu == 1)
					{
						cout << "Вы уже в главном меню.\n";
					}
				}
				
			} while (menu < 2 || menu > 7 || (menu == 5 && Train.size() == 0));
			
			break;

		// 2. Добавление вагона в начало
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

			// STL

			Train.push_front(new RailwayCarriage(number, typeofrc, bcond, bwifi));

			menu = 1;
			break;

		// 3. Добавление вагона в конец
		case(3):
			cout << "---------------------- 3. Добавление вагона в конец ---------------------\n\n";
			
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

			// STL

			Train.push_back(new RailwayCarriage(number, typeofrc, bcond, bwifi));

			menu = 1;
			break;

		// 4. Добавление вагона в позицию
		case(4):
			cout << "---------------------- 4. Добавление вагона в позицию ---------------------\n\n";

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
			do
			{
				cout << "Укажите позицию, в которую необходимо добавить вагон: ";
				cin >> pos;
				if (pos < 1 || pos > Train.size()+1)
				{
					cout << "Такого варианта ответа не существует. Попробуйте ещё раз.\n";
				}
				else
				{
					//STL

					RailwayCarriage *help = new RailwayCarriage(number, typeofrc, bcond, bwifi);
					advance(ptrs, pos - 1);
					Train.emplace(ptrs, help);
				}
			} while (pos < 1 || pos > Train.size()+1);
			
			

			menu = 1;
			break;

		// 5. Удаление вагона в позиции
		case(5):
			cout << "---------------------- 5. Удаление вагона в позиции ---------------------\n\n";

			do
			{
				cout << "Введите тип вагона(Reserved, Compartment, Suite, Restaurant): ";
				cin >> typeofrc;
				if (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1)
				{
					cout << "Такого типа к сожалению в моей программе не существует(та и по заданию как бы не было :)\n";
				}
			} while (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1);

			// STL

			advance(ptrs, pos-1);
			Train.erase(ptrs);

			menu = 1;
			break;
			
		// 6. Поиск вагона по его типу
		case(6):
			cout << "---------------------- 6. Поиск вагона по его типу ---------------------\n\n";

			do
			{
				cout << "Введите тип вагона(Reserved, Compartment, Suite, Restaurant): \n";
				cin >> typeofrc;
				if (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1)
				{
					cout << "Такого типа к сожалению в моей программе не существует(та и по заданию как бы не было :)\n";
				}
			} while (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1);

			// STL
			int num = 1;
			for (auto ptrType = Train.begin(); ptrType != Train.end(); ++ptrType)
			{
				if ((*ptrType)->get_TypeOfRC() == typeofrc)
				{
					cout << num << ". " << (*ptrType)->print();
				}
				num++;
			}

			do
			{
				cout << "\n\nВыберите необходимый пункт меню: ";
				cin >> menu;
				if (menu != 1 && menu != 2)
				{
					cout << "Такого пункта меню не существует, попробуйте ещё раз.\n";
				}
			} while (menu != 1 && menu != 2);
			if (menu == 2)
			{
				menu = 6;
			}
			break;
		}
	}

	exit(0);
	cout << endl << endl;
	std::system("pause");
	return 0;
}