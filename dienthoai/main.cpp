
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "phonebook.h"
#include "menu.h"
#include "list.h"

int main()
{	int option;
	bool f = true;

	List<PhoneBook> p;
	do
	{
		system("clear");
		option = Menu();
		switch(option)
		{
			case 1:
				AddContact(p);
				break;
			case 2:
				ShowContact(p);
				break;
			case 3:
				Save(p);
				break;
			case 4:
				Edit(p);
				break;
			case 5:
				OpenFromFile(p);
				break;
			case 6:
				DeleteContact(p);
				break;
			case 7:
				ExportHTML(p);
				break;
			case 0:
				break;				
		};
		if(option == 0)
			f = false;
		else
		{
			cout<<"\n Press Enter to continue-> ";
			cin.ignore();
			cin.get();
		}
	}
	while(f);
	return 0;
}

