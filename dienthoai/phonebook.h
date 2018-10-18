#ifndef phonebook_h
#define phonebook_h
#include <string.h>
#include "list.h"
#include <fstream>
class PhoneBook
{
private:
	string name;
	string number;
public:
	PhoneBook()
	{
		name = "";
		number = "";
	};
	PhoneBook(string a, string b)
	{
		name = a;
		number = b;
	};
	~PhoneBook(){};
	string GetName()
	{
		return name;
	};
	string GetNumber()
	{
		return number;
	};
	bool operator == (PhoneBook a)
	{
		if( name != a.name && number != a.number)
			return false;
		return true;
	};
};

void AddContact( List<PhoneBook> &p )
{
	string na; string nu;
	cout<<"Name: ";
	cin.ignore();
	getline(cin,na);
	cout<<"Number: ";
	cin>>nu;
	p.PushBack(PhoneBook(na,nu));
};

void ShowContact(List<PhoneBook> &p)
{
	int k = p.Len();
	for(int i = 1;i<=k;i++)
	{
		PhoneBook a = p.GetAnItem(i);
		cout<<i<<"\t";
		cout<<a.GetName()<<"\t";
		cout<<a.GetNumber()<<"\t"<<endl;
	}
};
void Save(List<PhoneBook> p)
{
	ofstream fout("data.txt");
	int k = p.Len();
	fout<<k<<endl;
	for(int i = 1;i<=k;i++)
	{
		PhoneBook a = p.GetAnItem(i);
		fout<<a.GetName()<<endl;
		fout<<a.GetNumber()<<endl;	
	}
	fout.close();
	cout<<"->Completed"<<endl;
};
void Edit(List<PhoneBook> &p)
{
	cout<<"Please enter the contact you want to change. "<<endl;
	ShowContact(p);
	cout<<"Edit position: "; int pos; cin>>pos;
	string na; string nu;
	cout<<"Name: ";
	cin.ignore();
	getline(cin,na);
	cout<<"Number: ";
	cin>>nu;
	PhoneBook a(na,nu);
	p.Change(a,pos);

};
void OpenFromFile(List<PhoneBook> &p)
{
	ifstream fin("data.txt");
	int k;
	fin>>k;
	for(int i =1;i<=k;i++)
	{
		string na; string nu;
		fin.ignore();
		getline(fin,na);
		fin>>nu;
		p.PushBack(PhoneBook(na,nu));		
	}
	fin.close();
};
void DeleteContact(List<PhoneBook> &p)
{
	cout<<"Please enter the contact you want to delete. "<<endl;
	ShowContact(p);
	string na; string nu;
	cout<<"Name: ";
	cin.ignore();
	getline(cin,na);
	cout<<"Number: ";
	cin>>nu;
	
	PhoneBook a(na,nu);

	p.DeleteByValue1(a);
};

void ExportHTML(List<PhoneBook> p)
{
	char fileName[100];
	cout<<"Enter the file containing data: ";
	cin.ignore();
	cin.getline(fileName,100);
	ofstream fout(fileName);

	int k = p.Len();

	fout<<"<!DOCTYPE html>"<<endl;
	fout<<"	<html>"<<endl;
	fout<<"	<head>"<<endl;
	fout<<"		<title>PHONEBOOK MANAGEMENT PROGRAM</title> "<<endl;
	fout<<"		<style type=\"text/css\"> \n";
    fout<<" 			th{ \n";
    fout<<"      			text-align: center; \n";
    fout<<"  			} \n";
    fout<<"  			td{ \n";
    fout<<"      				text-align: center;  \n";
    fout<<" 					}\n";
  	fout<<"			</style> \n";
	fout<<"	</head>"<<endl;
	fout<<"	<body>"<<endl;
	fout<<"		<h2>PHONEBOOK MANAGEMENT PROGRAM</h2>\n";
	fout<<"		<table style=\"width:70%\" border = \"1\" >\n";
	fout<<"			<tr>\n";
	fout<<"					<th>STT</th>\n";
	fout<<"					<th>Name</th>\n";
	fout<<"					<th>Number</th>\n";
	fout<<"			</tr>\n";
	for(int i = 1;i<=k;i++)
	{
		PhoneBook a = p.GetAnItem(i);
		fout<<"			<tr>\n";
		fout<<"				<td>"<<i<<"</td>\n";
		fout<<"				<td>"<<a.GetName()<<"</td>\n";
		fout<<"				<td>"<<a.GetNumber()<<"</td>\n";
		fout<<"			</tr>\n";
	}
	fout<<"		</table>\n";
	fout<<"	</body>\n";
	fout<<"	</html>\n";
	fout.close();

};

#endif