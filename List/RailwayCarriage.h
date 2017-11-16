#ifndef RAILWAY_INCLUDED
#define RAILWAY_INCLUDED

#include <iostream>

class RailwayCarriage
{
private:
	std::string Number;
	int NofPS;
	bool Conditioning;
	bool WiFi;
	std::string TypeOfRC;
public:
	RailwayCarriage();
	RailwayCarriage(std::string, std::string, bool, bool);

	// get-теры
	std::string get_Number();
	std::string get_TypeOfRC();
	int get_NofPS();
	bool get_Conditioning();
	bool get_WiFi();
	// set-теры
	void set_Number(std::string num);
	void set_TypeOfRC(std::string torc);
	void set_Conditioning(bool cond);
	void set_WiFi(bool wifi);
	void set_NofPS(int nofps);

	std::string print();

	RailwayCarriage *next;
};

#endif