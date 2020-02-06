#include<bits/stdc++.h>
#include <string>
using namespace std;


template<typename k, typename n, typename b, typename m>

class Employee
{
	public:
	k key;
	n name;
	b bio;
	m manager_id;

	Employee(k key, n name, b bio, m manager_id)
	{
		this->name = name;
		this->key = key;
		this->bio = bio;
		this->manager_id = manager_id;
	}
};

template<typename k, typename n, typename b, typename m>

class HashMap
{
	Employee<k,n,b,m> **arr;
	int capacity;

	int size;

	public:
	HashMap()
	{
		capacity = 4096;
		size = 0;
		arr = new Employee<k,n,b,m>*[capacity];

		for(int i =0;i<capacity;i++)
			arr[i]=NULL;

	}

	int hashCode(k key)
	{
		return key % capacity;
	}

	void insertEmployee(k key, n name, b bio, m manager_id)
	{
		Employee<k,n,b,m> *temp = new Employee<k,n,b,m>(key, name, bio,manager_id);

		int hashIndex = hashCode(key);

		while(arr[hashIndex] != NULL && arr[hashIndex]->key != key
				&& arr[hashIndex]->key != -1)
		{
			hashIndex++;
			hashIndex %= capacity;
		}

		if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
			size++;
		arr[hashIndex] = temp;
	}

	n get (int key)
	{
		int hashIndex = hashCode(key);
		int counter=0;

		while(arr[hashIndex] != NULL)
		{
			int counter=0;
			if(counter++>capacity)
				return NULL;

			if(arr[hashIndex]->key == key)
				return arr[hashIndex]->name;
			hashIndex++;
			hashIndex %= capacity;
		}

		return NULL;
	}

	void display()
	{
		for(int i=0; i<capacity; i++)
		{
			if(arr[i] != NULL && arr[i]->key != -1)
				cout << "key = " << arr[i]->key
					<<" name = "<< arr[i]->name
					<<" bio = " << arr[i]->bio
					<<" manager_id = " <<arr[i]->manager_id<<endl;
		}
	}
};

int main()
{
	HashMap<int, string, string, string> *h = new HashMap<int, string, string, string>;
	h->insertEmployee(1,"1","my name is joe","5555");
	h->insertEmployee(2,"2","my name is bob","88888");
	h->insertEmployee(3,"3","myname is bob4","9");
	h->display();
}
