#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "ComFile.h"
#include "ComDir.h"
using namespace std;

int main()
{
	try {
		/*cout << "Name of first directory is <d1> " << endl << "in <d1> there are <d1_2> directory and files <f1> and <f2> and <f3>" << endl;
		cout << "In <d1_2> file <f3>"<<endl<<endl;*/
		ComDir d1("d1");
		ComDir d2("d2");
		/*ComDir d1_2("d1_2");
		ComDir d1_3("d1_3");
		ComDir d2_1("d2_1");*/
		ComFile f1("f1", 1);
		ComFile f2("f2", 2);
		/*ComFile f3("f3", 3);
		ComFile f4("f3", 4);
		d1.addFile(f1);
		f1.setData(2);
		f1.reName("f1_2");
		d1.addFile(f1);
		d1.addFile(f2);
		d1.addFile(f3);
		d1_2.addFile(f3);
		d1_2.addFile(f4);
		d1_2.addDir(d2_1);
		d1.addDir(d1_2);
		d1.addDir(d1_3);
		cout << "after using seatch <f3> in <d1> direcroty and lower programm found ";
		d1.search(d1, "f3");
		cout << "files" << endl;
		cout << "after using seatch <f1> in <d1> direcroty and lower programm found ";
		d1.search(d1, "f1");
		cout << "files" << endl;
		cout << "checking d1.getname and f1.getdata" << endl;
		cout << d1.getName() << endl;
		cout << f1.getData() << endl;

		cout << endl << endl << endl;
		d1.ListDir(d1);
		cout << endl << endl;
		d1.LSR(d1);
		cout << endl << endl << endl << endl;


			cout << endl << endl << endl;*/

		string command = "start";
		ComDir* Uptr = new ComDir;
		ComDir* Stptr = new ComDir;
		ComFile* Fileptr = new ComFile;
		ComFile* NewFptr = new ComFile;
		ComDir* NewDptr = new ComDir;
		NewFptr = &f2;
		NewDptr = &d2;
		Uptr = &d1;
		Stptr = &d1;
		Fileptr = &f1;
		cout << "Your first direktory is <d1>" << endl;
		cout << "to come to d1 use command gotop" << endl;
		cout << "These are coomands to use" << endl << "list - to see what is in the directory" << endl << "ListALL - to see what is lower the directory" << endl << "cd - to go through direktories";
		cout << endl << "open - to use file" << endl << "write - to chande data on an opened file" << endl << "search - to see in what directories(that are lower or actually the using one) there are files with a needed name" << endl;
		cout << "newfile - to create new file in the current directory" << endl << "newdir - to create new dir in the curreant directory" << endl << "dname - to change current dir name" << endl << "fname - to change current file name" << endl; ;
		cout << "getdata - data of opened file" << endl<< "delfile - to delete file from current directory"<< endl;
		while (command != "end")
		{
			cin >> command;
			
			if (command == "delfile")
			{
				cout << "enter name of file"<<endl<<endl;
				string name;
				cin >> name;
				Uptr->delFile(name);
			}
			if (command == "getdata")
			{
				cout << Fileptr->getData() << endl << endl;

			}

			if (command == "dname")
			{
				cout << "enter name" << endl << endl;
				string name;
				cin >> name;
				Uptr->setName(name);
			}
			if (command == "fame")
			{
				cout << "enter name" << endl << endl;
				string name;
				cin >> name;
				Fileptr->reName(name);
			}
			if (command == "gotop")
			{
				Uptr = Stptr;
				cout << "we now at the top directory" << endl << endl;
			}
			if (command == "newfile")
			{
				int data;
				string name;
				cout << "Enter name and data" << endl << endl;
				cin >> name >> data;
				NewFptr->reName(name);
				NewFptr->setData(data);
				Uptr->addFile(*NewFptr);
				cout << "New File was created" << endl << endl;
			}
			if (command == "newdir")
			{
				string name;
				cout << "Enter name" << endl << endl;
				cin >> name;
				NewDptr->setName(name);
				Uptr->addDir(*NewDptr);
				cout << "New Directory were created" << endl << endl;
			}
			if (command == "ListALL")
			{
				Uptr->LSR(*Uptr);
			}
			if (command == "list")
			{
				Uptr->ListAll();
			}

			if (command == "cd")
			{
				cout << "enter name of directory" << endl << endl;
				ComDir* Tempptr = new ComDir;
				Tempptr = (Uptr->cd());
				Uptr = Tempptr;
			}
			if (command == "open")
			{
				cout << "enter name of file" << endl << endl;
				Fileptr = Uptr->open();
			}
			if (command == "write")
			{
				cout << endl << "cin int " << endl << endl;
				int k;
				cin >> k;
				Fileptr->setData(k);
			}
			if (command == "search")
			{
				string name;
				cout << "cin name of file" << endl << endl;
				cin >> name;
				Uptr->search(*Uptr, name);
			}
			/*else
			{
				cout << endl << "wrong command" << endl;
			}*/
		}
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << endl;
		return -1;
	}
	system("pause");
	return 0;
}
