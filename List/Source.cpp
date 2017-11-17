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
		// ������� ����	
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
				if (menu < 2 || menu > 7)
				{
					cout << "������ ������ ���� �� ����������, ���������� ��� ���.\n";
				}
			} while (menu < 2 || menu > 7);
			break;
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