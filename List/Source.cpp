#include <iostream>
#include "RailwayCarriage.h"
#include "TrainList.h"
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;



int main()
{
	setlocale(0, "");
	TrainList Train;

	int menu = 1;
	RailwayCarriage *vagon1 = new RailwayCarriage("093da", "Suite", false, false);
	RailwayCarriage *vagon2 = new RailwayCarriage("065um", "Compartment", true, false);
	RailwayCarriage *vagon3 = new RailwayCarriage("034as", "Restaurant", false, true);
	RailwayCarriage *vagon4 = new RailwayCarriage("sm342", "Reserved", true, true);
	RailwayCarriage *vagon5 = new RailwayCarriage("fst22", "Suite", false, true);
	RailwayCarriage *vagon6 = new RailwayCarriage("fer27", "Reserved", true, false);

	Train.AddLast(vagon1);
	Train.AddLast(vagon2);
	Train.AddLast(vagon3);
	Train.AddLast(vagon4);
	Train.AddLast(vagon5);
	Train.AddLast(vagon6);

	string number;
	string typeofrc;
	string cond; bool bcond;
	string wifi; bool bwifi;
	int pos;

	while (menu != 7)
	{
		std::system("cls");
		cout << "\n------------------------------  ��� ������  ------------------------------\n\n";

		if (Train.size() < 1)
		{
			cout << "� ��������� ��� ������ ���� ��� ����.\n\n";
		}
		else
		{
			cout << Train.printTrain();
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
			cout << "6. ������������� �� ���� ������/������� ������������/������� wi-fi.\n";
			cout << "7. ����� �� ���������.\n\n";
			do
			{
				cout << "�������� ����������� ����� ����: ";
				cin >> menu;
				if (menu < 2 || menu > 7 || (menu == 5 && Train.size() == 0))
				{
					if (menu < 2 || menu > 7)
					{
						cout << "������ ������ ���� �� ����������, ���������� ��� ���.\n";
					}
					else if (menu == 5 && Train.size() == 0)
					{
						cout << "��� ������ ����. ������� �������� ������.\n";
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

			Train.AddFirst(new RailwayCarriage(number, typeofrc, bcond, bwifi));
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

			Train.AddLast(new RailwayCarriage(number, typeofrc, bcond, bwifi));
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
			} while (pos < 1 || pos > Train.size()+1);
			Train.AddPos(new RailwayCarriage(number, typeofrc, bcond, bwifi), pos);
			menu = 1;
			break;

		// 5. �������� ������ � �������
		case(5):
			cout << "---------------------- 5. �������� ������ � ������� ---------------------\n\n";

			do
			{
				cout << "������� ������� ������, ������� ���������� �������: ";
				cin >> pos;
				if (pos < 1 || pos > Train.size())
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
				}
			} while (pos < 1 || pos > Train.size());
			Train.RemovePos(pos);
			menu = 1;
			break;

		// 6. ������������� ������ ������
		case(6):
			cout << "---------------------- 6. ������ ����������� ������� ---------------------\n\n";

			int intCond;
			int intWifi;
			string filtertype, filtercond, filterwifi;
			do
			{
				cout << "�������� ������ �� ���� ������(Y/N): ";
				cin >> filtertype;
				if (filtertype != "Y" && filtertype != "N")
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
				}
				if (filtertype == "Y")
				{
					do
					{
						cout << "������� ��� ������(Reserved, Compartment, Suite, Restaurant): ";
						cin >> typeofrc;
						if (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1)
						{
							cout << "������ ���� � ��������� � ���� ��������� �� ����������(�� � �� ������� ��� �� �� ���� :)\n";
						}
					} while (!typeofrc.compare("Reserved") != 1 && !typeofrc.compare("Compartment") != 1 && !typeofrc.compare("Suite") != 1 && !typeofrc.compare("Restaurant") != 1);
				}
				else if (filtertype == "N")
				{
					typeofrc = "";
				}
			} while (filtertype != "Y" && filtertype != "N");		
			do
			{
				cout << "�������� ������ �� ������� ������������ � �������(Y/N): ";
				cin >> filtercond;
				if (filtercond != "Y" && filtercond != "N")
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
				}
				if (filtercond == "Y")
				{
					intCond = 1;
				}
				else if (filtercond == "N")
				{
					intCond = 2;
				}
			} while (filtercond != "Y" && filtercond != "N");
			do
			{
				cout << "�������� ������ �� ������� Wi-Fi � �������(Y/N): ";
				cin >> filterwifi;
				if (filterwifi != "Y" && filterwifi != "N")
				{
					cout << "������ �������� ������ �� ����������. ���������� ��� ���.\n";
				}
				if (filterwifi == "Y")
				{
					intWifi = 1;
				}
				else if (filterwifi == "N")
				{
					intWifi = 2;
				}
			} while (filtercond != "Y" && filtercond != "N");
			
			cout << "\n-------------------------  ��������������� ������  -------------------------\n\n";
			cout << Train.filter(typeofrc, intCond, intWifi);
			cout << "\n----------------------------------------------------------------------------\n\n";
			cout << "1. ������� ����.\n";
			cout << "2. ����� ������.\n";

			do
			{
				cout << "�������� ����������� ����� ����: ";
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