#include "HashTable.h"

bool HashT::Add(string key, string value)
{
	if (double(size / capacity) > reHashIndex)
	{
		ReHash();
	}
	int hash = HashF(key);
	List* temp = new List;
	if (hashArr[hash] == nullptr)
	{
		temp->element = value;
		temp->key = key;
		temp->state = true;
		hashArr[hash] = temp;
	}
	else
	{
		List* lastIn = new List;
		lastIn = hashArr[hash];
		while (lastIn->next != nullptr)
		{
			if (lastIn->key == key && lastIn->element == value)
			{
				if (lastIn->state == true)
				{
					return false;
				}
			}
			if (lastIn->key == key)
			{
				lastIn->duplicate = true;
				temp->duplicate = true;
			}
			lastIn = lastIn->next;
		}
		if (lastIn->key == key && lastIn->element == value)
		{
			if (lastIn->state == true)
			{
				return false;
			}
		}
		if (lastIn->key == key && lastIn->state == true)
		{
			lastIn->duplicate = true;
			temp->duplicate = true;
		}
		temp->element = value;
		temp->key = key;
		temp->state = true;
		lastIn->next = temp;
	}
	size++;
	return true;
}

HashT::HashT()
{
	int i;
	table = new int[capacity];
	hashArr = new List * [capacity];
	for (i = 0; i < capacity; i++)
	{
		hashArr[i] = nullptr;
		table[i] = rand() % capacity;
	}
}

string HashT::Search(string key)
{
	string result = " ";
	int hash = HashF(key);
	if (hashArr[hash] != nullptr)
	{
		List* temp = new List;
		temp = hashArr[hash];
		while (temp->next != nullptr)
		{
			if (temp->state)
			{
				if (temp->duplicate)
				{
					if (temp->key == key)
					{
						result += temp->element;
						result += ', ';
					}
				}
				else
				{
					if (temp->key == key)
					{
						result += temp->element;
						break;
					}
				}
			}
			temp = temp->next;
		}
		if (temp->state)
		{
			if (temp->duplicate)
			{
				if (temp->key == key)
				{
					result += temp->element;
					result += ', ';
				}
			}
			else
			{
				if (temp->key == key)
				{
					result += temp->element;
				}
			}
		}
	}
	if (result == " ")
	{
		result = "Wrong key";
	}
	return result;
}

int HashT::HashF(string key)
{
	int hash = key.length() % capacity;
	int i;
	for (i = 0; i <= key.length(); i++)
	{
		hash = table[(hash + int(key[i])) % capacity];
	}
	return hash;
}

void HashT::Delete(string key)
{
	int hash = HashF(key);
	List* temp = new List;
	temp = hashArr[hash];
	if (hashArr[hash] != nullptr)
	{
		while (temp->next != nullptr)
		{
			if (temp->state)
			{
				if (temp->duplicate == true)
				{
					if (temp->key == key)
					{
						temp->state = false;
						size--;
					}
				}
				else
				{
					if (temp->key == key)
					{
						temp->state = false;
						size--;
						break;
					}
				}
			}
			temp = temp->next;
		}
		if (temp->state)
		{
			if (temp->duplicate == true)
			{
				if (temp->key == key)
				{
					temp->state = false;
					size--;
				}
			}
			else
			{
				if (temp->key == key)
				{
					temp->state = false;
					size--;
				}
			}
		}
	}
}

void HashT::ReHash()
{
	int pastCapacity = capacity;
	capacity *= 2;
	int i;
	List** swaper;
	List** supArr = new List * [capacity];
	int* newtable = new int[capacity];
	for (i = 0; i < capacity; i++)
	{
		supArr[i] = nullptr;
		newtable[i] = rand() % capacity;
	}
	delete[] table;
	table = newtable;
	swaper = hashArr;
	hashArr = supArr;
	supArr = swaper;
	for (i = 0; i < pastCapacity; i++)
	{
		if (supArr[i] != nullptr)
		{
			if (supArr[i]->state == true)
			{
				while (supArr[i]->next != nullptr)
				{
					Add(supArr[i]->key, supArr[i]->element);
					supArr[i] = supArr[i]->next;
				}
				Add(supArr[i]->key, supArr[i]->element);
			}
		}
	}
	for (int i = 0; i < pastCapacity; i++)
	{
		if (supArr[i])
		{
			delete supArr[i];
		}
	}
	delete[] supArr;
}


void HashT::PrintMap()
{
	int couter = 0;
	int i;
	List* temp = new List;
	for (i = 0; i < capacity; i++)
	{
		if (hashArr[i] != nullptr)
		{

			temp = hashArr[i];
			while (temp->next != nullptr)
			{
				if (temp->state == true)
				{
					cout << temp->key << " - " << temp->element << endl;
					couter++;
				}
				temp = temp->next;
			}
			if (temp->state == true)
			{
				couter++;
				cout << temp->key << " - " << temp->element << endl;
			}
		}
	}
	if (couter == 0)
	{
		cout << "Map is empty";
	}
}
