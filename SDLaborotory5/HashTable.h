#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;
struct List
{
	string key;
	string element;
	List* next = nullptr;
	bool state = false;
	bool duplicate = false;
};

class HashT
{
	int* table;
	double reHashIndex = 0.75;
	int size = 0;
	int capacity = 2;
	List** hashArr;
public:
	HashT();
	bool Add(string key, string value);
	string Search(string key);
	int HashF(string key);
	void Delete(string key);
	void ReHash();
	void PrintMap();
};