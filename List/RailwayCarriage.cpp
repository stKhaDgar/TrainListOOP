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
	if (_Type == "Плацкарт")
	{
		NofPS = 54; // Плацкарт
		
	}
	else if (_Type == "Купе")
	{
		this->NofPS = 36; // Купе
	}
	else if (_Type == "Люкс")
	{
		NofPS = 20; // Люкс
	}
	else if (_Type == "Вагон-ресторан" || _Type == "Ресторан" || _Type == "Вагон ресторан")
	{
		NofPS = 00; // Вагон ресторан
	}
}

// Get-теры
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

// Set-теры
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

// Вывод вагона на экран
std::string RailwayCarriage::print()
{
	std::string print = "   Мест: ";
		if(get_NofPS() == 0)
		{ 
			print = print + " " + std::to_string(get_NofPS());
		}
		else
		{
			print = print + std::to_string(get_NofPS());
		}
		
	print = print + ",  Кондиционер: ";
	if (get_Conditioning() == 0)
	{
		print = print + "Нету";
	}
	else
	{
		print = print + "Есть";
	}
	print = print + ",  Wi-Fi: ";
	if (get_WiFi() == 0)
	{
		print = print + "Нету";
	}
	else
	{
		print = print + "Есть";
	}
	print = print + ". \n";

	return print;
}