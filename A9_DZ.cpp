
// homework.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "classes.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	

		cout << "enter numbers for needed commands" << endl;
		cout << " 1 - Create and Add home to library " << endl;
		cout << " 2 - Delete home from library" << endl;
		cout << " 3 - Save data" << endl;
		cout << " 4 - Switch on/off GKH in the house" << endl;
		cout << " 5 - change Amount of people in the house" << endl;
		cout << " 6 - bill for the month" << endl;
		cout << " 7 - get data" << endl;
		cout << " 8 - check fo rnot payed" << endl;
		cout << " 9 - show houses using GKH" << endl;
		cout << " 10 - EXIT" << endl;

		Library L1;
		enum comands { one = 1, two, three, four, five, six, seven, eight, nine, ten };
		int ent = 0;
		House H1;

		while (ent != ten)
		{
			cin >> ent;
			switch (ent)
			{
			case one://create home
			{
				cout << "Enter  House number  GKH  Amount of people  IF there is DOLG" << endl;
				int HN;
				bool gkh;
				int ap;
				int p;
				cin >> HN >> gkh >> ap >> p;
				H1(HN, gkh, ap, p);

				L1.addHouse(H1);
				{
					string change;
					change = "A new house was created with number " + to_string(HN) + " GKH is " + to_string(gkh) + "People amount is" + to_string(ap) + "Dolg is " + to_string(p);
					L1.changes.push_back(change);
				}
				break;
			}



			case two://delete home
			{
				try {
					cout << "Enter House Number to delete from library" << endl;
					int N;
					cin >> N;
					L1.delHouse(N);
					break;
					{
						string change;
						change = "A House with number " + to_string(N) + "was destroyed";
						L1.changes.push_back(change);
					}
				}
				catch (invalid_argument& e)
				{
					cerr << e.what() << endl;
					return -1;
				}
				break;
			}
			case three://save data
			{
				string S;
				ofstream F;
				cout << "write name of file " << endl;
				cin >> S;
				F.open(S);
				F << "CountHomes " << L1.GetVector().size() << endl << endl;
				for (int i = 0; i < L1.GetVector().size(); i++) {
					F << L1.GetVector()[i] << endl;
				}
				F.close();
				break;
			}
			case four://GKH
			{
				try {
					cout << "Enter house number GKH to change and mode" << endl;
					int N;
					int m;
					cin >> N >> m;
					L1.changeGkh(N, m);
					{
						string change;
						change = "A House with number " + to_string(N) + "Gkh was set to " + to_string(m);
						L1.changes.push_back(change);
					}
				}
				catch (invalid_argument& e)
				{
					cerr << e.what() << endl;
					return -1;
				}
				break;
			}
			case five://change people
			{try {
				cout << "Enter house number People amount to change and the amount" << endl;
				int N;
				int pl;
				cin >> N >> pl;
				L1.changePpl(N, pl);
				{
					string change;
					change = "A House with number " + to_string(N) + "amount of people was set to " + to_string(pl);
					L1.changes.push_back(change);
				}
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				return -1;
			}
				break;
			}
			case six://bill and if dolg
			{try {
				cout << "Enter house number bill to show and mode to change" << endl;
				int N;
				int p;
				cin >> N >> p;
				L1.showPrice(N, p);
				{
					string change;
					change = "A House with number " + to_string(N) + "Payment dolg was set to " + to_string(p);
					L1.changes.push_back(change);
				}
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				return -1;
			}
				break;
			}
			case seven://get data
			{
				int HouseNumber;
				bool GKH;
				int people;
				bool payed;
				int G, N, p;
				bool gkh, pay;
				string buff;
				string S;
				ifstream F;
				cout << "write name of file " << endl;
				cin >> S;
				F.open(S);
				if (F.is_open()) {
					F >> buff;
					F >> G;
					int i = 0;
					while (i < G)
					{
						F >> buff;
						F >> N;
						F >> buff;
						F >> gkh;
						F >> buff;
						F >> p;
						F >> buff;
						F >> pay;
						H1(N, gkh, p, pay);
						L1.addHouse(H1);
						i++;
						{
							string change;
							change = "A new house was created with number " + to_string(N) + " GKH is " + to_string(gkh) + "People amount is" + to_string(p) + "Dolg is " + to_string(pay);
							L1.changes.push_back(change);
						}
					}
					F.close();
				}
				break;
			}
			case eight://not payed
			{
				vector<int> dol;
				dol = L1.getDolg();
				for (int i = 0; i < dol.size(); i++)
				{
					cout << "House number " << dol[i] << " has Dolg ";
				}
				break;
			}
			case nine://show GKH houses
			{
				vector<int> usl;
				usl = L1.showUslugi();
				for (int i = 0; i < usl.size(); i++)
				{
					cout << "House number " << usl[i] << " using GKH ";
				}
			}

			}
		}
	
	
	cout << "Work is finished";
	system("pause");

	return 0;
}

