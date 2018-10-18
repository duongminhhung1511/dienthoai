#ifndef list_h
#define	list_h
#include "node.h"
//#include "phonebook.h"
#include <fstream>

template <class T>

class List
{
private:
	Node <T> *head;
public:
	List()
	{
		head = 0;
	};

	List(List<T> l, int from, int to)
	{
		head = 0;
		Node<T> *p = l.head;
		for(int i =1;i<from;i++)
			p = p->next;
		for(int i=from;i<=to;i++)
		{
			PushBack(p->data);
			p=p->next;
		}
	};
	void PushBack(T value)
	{
		Node <T> *n = new Node<T>;
		n->data = value;
		n->next = 0;

		if (head == 0)
			head = n;
		else
		{
			Node<T> *p = head;
			while(p->next != 0)
				p = p->next;
			p->next = n;
		}
	};
	void PrintAll() const
	{
		Node<T> *p = head;
		while(p != 0)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	};
	T GetAnItem(int pos)
	{
		if(pos-1 == 0)
			return head ->data;
		else
		{
			Node<T> *p = head;
			for(int i = 1;i<pos-1;i++)
				p=p->next;
			return p->next->data;
		}
	};
	void PushTop(T value)
	{
		Node<T> *n = new Node<T>;
		n->data = value;
		n->next = head;
		head = n;

	};
	void DeleteAtPos(int pos)
	{
		if (pos == 1)
		{
			Node<T> *q = head;
			head = head->next;
			delete q;
		}
		else
		{
			Node<T> *p = head;
			for(int i = 1; i<pos-1;i++)
				p= p->next;
			Node<T> *q = p->next;
			p->next = p->next->next;
			delete q;
		}
	};
	void DeleteByValue(T value)
	{
		Node<T> *p = head;
		if(head->data == value)
		{
			Node<T> *q = head;
			head = head ->next;
			delete q;
		}
		else
		{
			while(p->next != 0)
			{
				if(p->next->data == value)
				{
					Node<T> *q = p->next;
	 				p->next=p->next->next;
	 				delete q;
				}
				else
					p = p->next;
			}
		}
	};

	void DeleteByValue1(T value)
	{
		int i = 0;
		Node<T> *p = head;
		while(p != 0)
		{
			i++;
			if(p->data == value)
			{
				DeleteAtPos(i);
				i--;
			}
			p=p->next;
		}
	};
	void Change(T value, int pos) // chen vao vi tri pos, roi xoa pos cu; 
	{
		Node<T> *p = head;
		for(int i = 0;i<pos-1;i++)
			p=p->next;
		p->data = value;
	};
	
	void Insert(T value, int pos)
	{
		Node<T> *n = new Node<T>;
 		n->data = value;
 		Node<T> *p = head;
 		if(pos-1==0)
 			PushTop(value);
 		else
 		{
 			for(int i = 1;i<pos-1;i++)
	 		{
	 			p=p->next;
	 		}
	 		n->next = p->next;
			p->next = n; 
		}		
	};
	int Len() const
	{
		int len = 0;
		Node<T> *p = head;
		while(p != 0)
		{
			p=p->next;
			len++;
		} 
		return len;
	};
	void Search(T value) const
	{
		Node<T> *p = head;
		int i = 1;
		while(p !=0 )
		{
			if(p->data == value)
				cout<<i<<" ";
			p=p->next;
			i++;
		}
		cout<<endl;
	};
	bool Check(T value)
	{
		Node<T> *p = head;
		while(p!=0)
		{
			if(p->data == value)
			{
				return 1;
			}
			p = p->next;
		}
		return 0;
	};

	void Reverse()
	{
		Node<T> *t = 0;
		Node<T> *p = head;
		while(p != 0)
		{
			Node<T> *n = new Node<T>;
			n->data = p->data;
			n->next = t;
			t = n;
			Node<T> *q = p;
			p = p->next;
			delete q;

		}
	};

	void SaveFile()
	{
		/*
		char fileName[100];
		cout<<"Nhap ten file chua du lieu: ";
		cin.ignore();
		cin.getline(fileName,100);*/

		ofstream fout;
		fout.open("data.txt",ios::out|ios::app);
		Node<T> *p = head;
		
		int k = 1;
		while(p != 0)
		{
			k++;
			p=p->next;
		}
		fout<<k<<endl;
		while(p != 0)
		{
			fout<<p->data;
			p=p->next;
		}
		fout.close();
	};

	

}; 
#endif
