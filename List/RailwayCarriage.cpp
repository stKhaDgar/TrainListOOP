#include "RailwayCarriage.h"
#include <string>
#include <iostream>

RailwayCarriage::RailwayCarriage()
{}

RailwayCarriage::RailwayCarriage(std::string _Number, std::string _Type, bool _Conditioning, bool _WiFi)
{

	this->Number = _Number;
	this->Conditioning = _Conditioning;
	this->WiFi = _WiFi;
	this->TypeOfRC = _Type;
	if (_Type == "��������")
	{
		NofPS = 54; // ��������
		
	}
	else if (_Type == "����")
	{
		this->NofPS = 36; // ����
	}
	else if (_Type == "����")
	{
		NofPS = 20; // ����
	}
	else if (_Type == "�����-��������" || _Type == "��������" || _Type == "����� ��������")
	{
		NofPS = 00; // ����� ��������
	}
}

// Get-����
std::string RailwayCarriage::get_TypeOfRC()
{
	return TypeOfRC;
}
std::string RailwayCarriage::get_Number()
{
	return Number;
}
int RailwayCarriage::get_NofPS()
{
	return NofPS;
}
bool RailwayCarriage::get_Conditioning()
{
	return Conditioning;
}
bool RailwayCarriage::get_WiFi()
{
	return WiFi;
}

// Set-����
void RailwayCarriage::set_Number(std::string num)
{
	this->Number = num;
}
void RailwayCarriage::set_TypeOfRC(std::string torc)
{
	this->TypeOfRC = torc;
}
void RailwayCarriage::set_Conditioning(bool cond)
{
	this->Conditioning = cond;
}
void RailwayCarriage::set_WiFi(bool wifi)
{
	this->WiFi = wifi;
}
void RailwayCarriage::set_NofPS(int nofps)
{
	this->NofPS = nofps;
}

// ����� ������ �� �����
std::string RailwayCarriage::print()
{
	std::string print = "   ����: ";
		if(get_NofPS() == 0)
		{ 
			print = print + " " + std::to_string(get_NofPS());
		}
		else
		{
			print = print + std::to_string(get_NofPS());
		}
		
	print = print + ",  �����������: ";
	if (get_Conditioning() == 0)
	{
		print = print + "����";
	}
	else
	{
		print = print + "����";
	}
	print = print + ",  Wi-Fi: ";
	if (get_WiFi() == 0)
	{
		print = print + "����";
	}
	else
	{
		print = print + "����";
	}
	print = print + ". \n";

	return print;
}