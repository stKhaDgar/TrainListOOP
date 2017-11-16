#include <iostream>
#include "RailwayCarriage.h"
#include <string>
#include <sstream>
using namespace std;

class List
{
protected:
	RailwayCarriage *first, *last;
public:
	List()
	{
		last = NULL;
		first = NULL;
	}

	// ���������� ������ � ������
	void AddFirst(RailwayCarriage* vagon)
	{
		RailwayCarriage *temp = new RailwayCarriage;
		if (first == NULL && last == NULL)
		{
			temp->set_Number(vagon->get_Number());
			temp->set_TypeOfRC(vagon->get_TypeOfRC());
			temp->set_Conditioning(vagon->get_Conditioning());
			temp->set_WiFi(vagon->get_WiFi());
			this->first = temp;
			this->last = temp;
		}
		else
		{
			temp->next = first;
			temp->set_Number(vagon->get_Number());
			temp->set_TypeOfRC(vagon->get_TypeOfRC());
			temp->set_Conditioning(vagon->get_Conditioning());
			temp->set_WiFi(vagon->get_WiFi());
			first = temp;
		}

	}

	// ���������� ������ � �����
	void AddLast(RailwayCarriage* vagon)
	{
		RailwayCarriage *temp = new RailwayCarriage;
		if (last == NULL && first == NULL)
		{
			temp->set_Number(vagon->get_Number());
			temp->set_TypeOfRC(vagon->get_TypeOfRC());
			temp->set_NofPS(vagon->get_NofPS());
			temp->set_Conditioning(vagon->get_Conditioning());
			temp->set_WiFi(vagon->get_WiFi());
			this->last = temp;
			this->first = temp;
		}
		else
		{
			this->last->next = temp;
			temp->set_Number(vagon->get_Number());
			temp->set_TypeOfRC(vagon->get_TypeOfRC());
			temp->set_NofPS(vagon->get_NofPS());
			temp->set_Conditioning(vagon->get_Conditioning());
			temp->set_WiFi(vagon->get_WiFi());
			temp->next = NULL;
			this->last = temp;
		}
	}

	// ���������� ������ � �������
	void AddPos(RailwayCarriage* vagon, int pos)
	{
		RailwayCarriage *temp = new RailwayCarriage;
		temp->set_Number(vagon->get_Number());
		temp->set_TypeOfRC(vagon->get_TypeOfRC());
		temp->set_Conditioning(vagon->get_Conditioning());
		temp->set_WiFi(vagon->get_WiFi());

		if (pos == 1)
		{
			AddFirst(temp);
		}
		else if (pos <= size())
		{
			RailwayCarriage *help = first;

			for (int i = 1; i < pos-1; i++)
			{
				help = help->next;
			}
			temp->next = help->next;
			help->next = temp;

		}
		else if (pos > 1 && pos == size()+1)
		{
			AddLast(temp);
		}
		else
		{ 
			cout << "����� ������� �� ����������.";
		}
	}

	// �������� ������ �� �������
	void RemovePos(int pos)
	{
		RailwayCarriage *help;
		if (pos == 1 && first != NULL)
		{
			help = first->next;
			delete first;
			first = help;
		}
		else if (pos < size() && pos > 1)
		{
			help = first;
			for (int i = 1; i < pos - 1; i++)
			{
				help = help->next;
			}
			RailwayCarriage *del = help->next;
			help->next = del->next;
			delete del;
		}
		else if (pos == size() && pos > 2)
		{
			help = first;
			for (int i = 1; i < pos - 1; i++)
			{
				help = help->next;
			}
			help->next = last->next;
			delete last;
			last = help;
		}
		else
		{
			cout << "����� ������� �� ����������" << endl;
		}
	}

	// ���������� ������� � ������
	int size()
	{
		int n = 0;
		RailwayCarriage *temp = first;
		while (temp != NULL)
		{
			temp = temp->next;
			n++;
		}
		return(n);
	}

	// ��������
	RailwayCarriage* begin()
	{
		return first;
	}
	RailwayCarriage* end()
	{
		return last->next;
	}

	// ����� ����� �������
	string printTrain()
	{
		if (size() > 0)
		{
			string print = "";
			int numOfStr = 1;
			int maxOfElInStr = 0;

			for (auto ptr = begin(); ptr != end();)
			{
				string numOfElInStr = ptr->get_TypeOfRC();
				if (maxOfElInStr < numOfElInStr.size())
				{ 
					maxOfElInStr = numOfElInStr.size();
				}
				ptr = ptr->next;
			}


			for (auto ptr = begin(); ptr != end();)
			{
				string TypeOfRC= ptr->get_TypeOfRC();
				for (TypeOfRC.size(); TypeOfRC.size() < maxOfElInStr;)
				{
					TypeOfRC = TypeOfRC + " ";
				}
				print = print + " " + to_string(numOfStr) + ". " + "\"" + ptr->get_Number() +"\"  " + TypeOfRC + ptr->print();
				ptr = ptr->next;
				numOfStr++;
			}
			return print;
		}
		else
		{
			return "� ������� ���� �������";
		}
	}

	// ������ �� ����/������� ������������/������� wi-fi
	string filter(std::string _type, bool _cond, bool _wifi)
	{
		if (size() > 0)
		{
			string print = "";
			int numOfStr = 1;
			int maxOfElInStr = 0;

			for (auto ptr = begin(); ptr != end();)
			{
				if (ptr->get_TypeOfRC() == _type)
				{
					// ���������� ������������� ���������� ��������� � ������ ���� ������
					for (auto ptr = begin(); ptr != end();)
					{
						string numOfElInStr = _type;
						if (maxOfElInStr < numOfElInStr.size())
						{
							maxOfElInStr = numOfElInStr.size();
						}
						ptr = ptr->next;
					}

					string TypeOfRC = ptr->get_TypeOfRC();
					for (TypeOfRC.size(); TypeOfRC.size() < maxOfElInStr;)
					{
						TypeOfRC = TypeOfRC + " ";
					}
					print = print + " " + to_string(numOfStr) + ". " + "\"" + ptr->get_Number() + "\"  " + TypeOfRC + ptr->print();
				}

				numOfStr++;
				ptr = ptr->next;
			}
			return print;
		}
		else
		{
			return "� ������� ���� �������";
		}
	}
};

int main()
{
	setlocale(0, "");

	List Train;

	RailwayCarriage *vagon = new RailwayCarriage("065um", "��������", false, false);
	RailwayCarriage *vagon1 = new RailwayCarriage("093ap", "����", true, false);
	RailwayCarriage *vagon2 = new RailwayCarriage("048yn", "����", true, true);
	RailwayCarriage *vagon3 = new RailwayCarriage("033tm", "�����-��������", false, false);
	RailwayCarriage *vagon4 = new RailwayCarriage("023um", "��������", true, true);

	Train.AddLast(vagon);
	Train.AddLast(vagon1);
	Train.AddLast(vagon2);
	Train.AddLast(vagon4);
	Train.AddLast(vagon1);



	
	cout << endl;

	cout << Train.printTrain();

	cout << endl;

	cout << endl << endl;

	cout << Train.filter("��������", true, false);

	cout << endl;
	system("pause");
	return 0;
}