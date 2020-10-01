#pragma once
#include"BTree.h"

class Lending
{
	int id;
	string client;
	string date;
	int code;
public:
	void set_date(string date_) { date = date_; }
	void set_client(string name) { client = name; }
	void set_code(int num) { code = num; }
	string getName() { return client; }
	bool operator ==(const Lending a)const;
	bool operator!=(const Lending a)const;
	bool operator>=(const Lending a)const;
	bool operator<=(const Lending a)const;
	bool operator>(const Lending a)const;
	bool operator<(const Lending a)const;
	friend istream& operator>>(istream& is, Lending& l)
	{

		cout << "enter id name date item ";
		is >> l.id >> l.client >> l.date >> l.code;

		return is;
	}

	friend ostream& operator<<(ostream& os, Lending& l)
	{
		os << endl << "Lending details: id: " << l.id << " name: " << l.client << " date: " << l.date << " item: " << l.code << endl;
		return os;
	}
};