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
		cout << "\n------------------------------  ��� ������  ------------------------------\n\n";
		int count = 1;
		if (Train.size() < 1)
		{
			cout << "� ��������� ��� ������ ���� ��� ����.\n\n";
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
		// 1. ������� ����	
		case(1):
			cout << "----------------------------- 1. ������� ���� ----------------------------\n\n";
			cout << "2. �������� ����� � ������.\n";
			cout << "3. �������� ����� � �����.\n";
			cout << "4. �������� ����� � �������.\n";
			cout << "5. ������� ����� � �������.\n";
			cout << "6. ����� �� ���� ������.\n";
			cout << "7. ����� �� ���������.\n\n";
			do
			{
				cout << "�������� ����������� ����� ����: ";
				cin >> menu;
				if (menu < 2 || menu > 7 || (menu == 5 && Train.size() == 0))
				{
					if (menu < 1 || menu > 8)
					{
						cout << "������ ������ ���� �� ����������, ���������� ��� ���.\n";
					}
					else if (menu == 5 && Train.size() == 0)
					{
						cout << "��� ������ ����. ������� �������� ������.\n";
					}
					else if (menu == 1)
					{
						cout << "�� ��� � ������� ����.\n";
					}
				}
				
			} while (menu < 2 || menu > 7 || (menu == 5 && Train.size() == 0));
			
			break;

		// 2. ���������� ������ � ������
		case(2):
			cout << "---------------------- 2. ���������� ������ � ������ ---------------------\n\n";
			
			do
			{
				cout << "������� ����� ������(���� ��������): ";
				
				cin >> number;
				if (number.size() != 5)
				{
					cout << "���������� ��� ���.\n";
				}
			} while (number.size() != 5);
			do
			{
				cout << "������� ��� ������(Reserved, Compartment, Suite, Restaurant): ";
				cin >> typeofrc;
				if (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1)
				{
					cout << "������ ���� � ��������� � ���� ��������� �� ����������(�� � �� ������� ��� �� �� ���� :)\n";
				}
			} while (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1);
			do
			{
				cout << "������� ������� ������������ � ������(Yes/No): ";
				cin >> cond;
				if (!cond.compare("Yes") != 1 && !cond.compare("No") != 1)
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
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
				cout << "������� ������� Wi-Fi � ������(Yes/No): ";
				cin >> wifi;
				if (!wifi.compare("Yes") != 1 && !wifi.compare("No") != 1)
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
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

		// 3. ���������� ������ � �����
		case(3):
			cout << "---------------------- 3. ���������� ������ � ����� ---------------------\n\n";
			
			do
			{
				cout << "������� ����� ������(���� ��������): ";
				
				cin >> number;
				if (number.size() != 5)
				{
					cout << "���������� ��� ���.\n";
				}
			} while (number.size() != 5);
			do
			{
				cout << "������� ��� ������(Reserved, Compartment, Suite, Restaurant): ";
				cin >> typeofrc;
				if (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1)
				{
					cout << "������ ���� � ��������� � ���� ��������� �� ����������(�� � �� ������� ��� �� �� ���� :)\n";
				}
			} while (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1);
			do
			{
				cout << "������� ������� ������������ � ������(Yes/No): ";
				cin >> cond;
				if (!cond.compare("Yes") != 1 && !cond.compare("No") != 1)
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
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
				cout << "������� ������� Wi-Fi � ������(Yes/No): ";
				cin >> wifi;
				if (!wifi.compare("Yes") != 1 && !wifi.compare("No") != 1)
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
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

		// 4. ���������� ������ � �������
		case(4):
			cout << "---------------------- 4. ���������� ������ � ������� ---------------------\n\n";

			do
			{
				cout << "������� ����� ������(���� ��������): ";

				cin >> number;
				if (number.size() != 5)
				{
					cout << "���������� ��� ���.\n";
				}
			} while (number.size() != 5);
			do
			{
				cout << "������� ��� ������(Reserved, Compartment, Suite, Restaurant): ";
				cin >> typeofrc;
				if (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1)
				{
					cout << "������ ���� � ��������� � ���� ��������� �� ����������(�� � �� ������� ��� �� �� ���� :)\n";
				}
			} while (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1);
			do
			{
				cout << "������� ������� ������������ � ������(Yes/No): ";
				cin >> cond;
				if (!cond.compare("Yes") != 1 && !cond.compare("No") != 1)
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
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
				cout << "������� ������� Wi-Fi � ������(Yes/No): ";
				cin >> wifi;
				if (!wifi.compare("Yes") != 1 && !wifi.compare("No") != 1)
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
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
				cout << "������� �������, � ������� ���������� �������� �����: ";
				cin >> pos;
				if (pos < 1 || pos > Train.size()+1)
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
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

		// 5. �������� ������ � �������
		case(5):
			cout << "---------------------- 5. �������� ������ � ������� ---------------------\n\n";

			do
			{
				cout << "������� ��� ������(Reserved, Compartment, Suite, Restaurant): ";
				cin >> typeofrc;
				if (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1)
				{
					cout << "������ ���� � ��������� � ���� ��������� �� ����������(�� � �� ������� ��� �� �� ���� :)\n";
				}
			} while (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1);

			// STL

			advance(ptrs, pos-1);
			Train.erase(ptrs);

			menu = 1;
			break;
			
		// 6. ����� ������ �� ��� ����
		case(6):
			cout << "---------------------- 6. ����� ������ �� ��� ���� ---------------------\n\n";

			do
			{
				cout << "������� ��� ������(Reserved, Compartment, Suite, Restaurant): \n";
				cin >> typeofrc;
				if (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1)
				{
					cout << "������ ���� � ��������� � ���� ��������� �� ����������(�� � �� ������� ��� �� �� ���� :)\n";
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
				cout << "\n\n�������� ����������� ����� ����: ";
				cin >> menu;
				if (menu != 1 && menu != 2)
				{
					cout << "������ ������ ���� �� ����������, ���������� ��� ���.\n";
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