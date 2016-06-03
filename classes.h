
#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;


#define PRICEGKH 100

class House
{

public:
	friend class Library;
	friend ostream& operator<<(ostream&, const House&);
	int getHouseNumber() const
	{
		return HouseNumber;
	}
	void setHouseNumber(int num)
	{
		if (num<0)
			throw "wrong number, plz try again";
		else
			HouseNumber = num;
	}
	int getNumPpl()
	{
		return people;
	}
	void setNumPpl(int num)
	{
		people = num;
	}
	bool getGkh()
	{
		return GKH;
	}
	void setGkh(bool m)
	{
		GKH = m;
	}
	bool getPayment()
	{
		return payed;
	}
	void setPayment(bool p)
	{
		payed = p;
	}
	House()
	{
		HouseNumber = 0;
		payed = 0;
		GKH = 0;
		people = 0;
	}
	/*House(House &h)
	{
	HouseNumber=h.HouseNumber;
	GKH=h.GKH;
	people=h.people;
	}*/
	House(int hn, bool gkh, int ppl, bool p)
	{
		HouseNumber = hn;
		GKH = gkh;
		people = ppl;
		payed = p;
	}
	void operator()(int hn, bool gkh, int ppl, bool p)
	{
		HouseNumber = hn;
		GKH = gkh;
		people = ppl;
		payed = p;
	}
	void  operator =(House &h)
	{
		HouseNumber = h.HouseNumber;
		GKH = h.GKH;
		people = h.people;
		payed = h.payed;
	}
	int bill()
	{
		return people*GKH*PRICEGKH;
	}
protected:
	int HouseNumber;
	bool GKH;
	int people;
	bool payed;

};

ostream& operator<<(ostream& out,  House& H) {

	out << "House_Number_is " << H.getHouseNumber() << endl;
	out << "USing_GKH?  " << H.getGkh() << endl;
	out << "Number_of_people_is_living_in_the_house_is " << H.getNumPpl()<< endl;
	
	out << "Dolg_is_payed?" << H.getPayment() << endl;
	return out;
}

class Library
{

public:
	friend class House;
	void addHouse(House& H1)
	{
		listH.push_back(H1);
	}
	void  delHouse(int Num)
	{
		int count = 0;
		for (int i = 0; i<listH.size(); i++)
			if (listH[i].getHouseNumber() == Num)
			{
				listH.erase(listH.begin() + i);
				count++;
			}
		if (!count)
		{
			throw invalid_argument("There is no House with such number");
		}
	}
	bool checkGkh(House h1)
	{
		return h1.GKH;
	}
	void changeGkh(int Num, bool m)
	{
		int count = 0;
		for (int i = 0; i<listH.size(); i++)
		{
			if (listH[i].getHouseNumber() == Num)
			{
				count++;
				cout << "House number " << listH[i].getHouseNumber() << " had GKH mode " << listH[i].getGkh() << " and now set to" << m << endl;
				listH[i].setGkh(m);
			}
		}
		if (!count)
		{
			throw invalid_argument("There is no House with such number");
		}
	}
	void changePpl(int Num, int np)
	{
		int count = 0;
		for (int i = 0; i<listH.size(); i++)
		{
			if (listH[i].getHouseNumber() == Num)
			{
				count++;
				cout << "House number " << listH[i].getHouseNumber() << " had people amount of " << listH[i].getNumPpl() << " and now set to" << np << endl;
				listH[i].setNumPpl(np);
			}
		}
		if (!count)
		{
			throw invalid_argument("There is no House with such number");
		}
	}
	void showPrice(int Num, bool p)
	{
		int count = 0;
		for (int i = 0; i<listH.size(); i++)
		{
			if (listH[i].getHouseNumber() == Num)
			{
				count++;
				cout << "House number " << listH[i].getHouseNumber() << " must to pay " << listH[i].bill() << " and mode of dolg was " << listH[i].getPayment();
				cout << "Now set to " << p;
				listH[i].setPayment(p);
			}
		}
		if (!count)
		{
			throw invalid_argument("There is no House with such number");
		}
	}
	vector<int> getDolg()
	{
		vector<int> dolg;
		for (int i = 0; i<listH.size(); i++)
		{
			if (listH[i].getPayment() == 1)
			{
				
				dolg.push_back(listH[i].getHouseNumber());
			}
		}
		return dolg;
	}
	vector<int> showUslugi()
	{
		vector<int> usl;
		for (int i = 0; i<listH.size(); i++)
		{
			if (listH[i].getGkh() == 1)
			{
				usl.push_back(listH[i].getHouseNumber());
			}
		}
		return usl;
	}
	vector<House>& GetVector() {
		return listH;
	}

	vector<string> changes;
protected:
	vector<House> listH;
};

