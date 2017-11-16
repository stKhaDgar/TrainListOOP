#include "TrainList.h"
#include <iostream>
#include <string>

// ���������� ������ � ������
void TrainList::AddFirst(RailwayCarriage* vagon)
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
void TrainList::AddLast(RailwayCarriage* vagon)
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
void TrainList::AddPos(RailwayCarriage* vagon, int pos)
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

		for (int i = 1; i < pos - 1; i++)
		{
			help = help->next;
		}
		temp->next = help->next;
		help->next = temp;

	}
	else if (pos > 1 && pos == size() + 1)
	{
		AddLast(temp);
	}
	else
	{
		cout << "����� ������� �� ����������.";
	}
}

// �������� ������ �� �������
void TrainList::RemovePos(int pos)
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
int TrainList::size()
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
RailwayCarriage* TrainList::begin()
{
	return first;
}
RailwayCarriage* TrainList::end()
{
	return last->next;
}

// ����� ����� �������
string TrainList::printTrain()
{
	if (size() > 0)
	{
		string print = "";
		int numOfStr = 1;
		unsigned int maxOfElInStr = 0;

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
			string TypeOfRC = ptr->get_TypeOfRC();
			for (TypeOfRC.size(); TypeOfRC.size() < maxOfElInStr;)
			{
				TypeOfRC = TypeOfRC + " ";
			}
			print = print + " " + to_string(numOfStr) + ". " + "\"" + ptr->get_Number() + "\"  " + TypeOfRC + ptr->print();
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
string TrainList::filter(std::string _type, int _cond, int _wifi)
{
	if (size() > 0)
	{
		string print = "";
		int numOfStr = 1;
		unsigned int maxOfElInStr = 0;


		for (auto ptr = begin(); ptr != end();)
		{
			RailwayCarriage *temp = ptr;

			// ���������� �� ���� ������
			if (ptr->get_TypeOfRC() == _type)
			{
				
				temp = ptr;
			}
			else if(_type == "")
			{
				temp = ptr;
			}
			else
			{
				temp = NULL;
			}

			// ���������� �� ������� ������������
			if(_cond != 2 && temp != NULL)
			{
				if (ptr->get_Conditioning() == _cond)
				{
					temp = ptr;
				}
				else
				{
					temp = NULL;
				}
			}
			else if (_cond == 2 && temp != NULL)
			{
				temp = ptr;
			}

			// ���������� �� ������� wi-fi
			if(_wifi != 2 && temp != NULL)
			{
				if (ptr->get_WiFi() == _wifi)
				{
					temp = ptr;
				}
				else
				{
					temp = NULL;
				}
			}
			else if (_wifi == 2 && temp != NULL)
			{
				temp = ptr;
			}
			
			// ���������� ������������� ���������� ��������� � ������ ���� ������
			for (auto ptr = begin(); ptr != end();)
			{
				string numOfElInStr = ptr->get_TypeOfRC();
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
			if (temp != NULL)
			{
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