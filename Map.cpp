#include <iostream>

class CTestClass //User defined class with operator overload.
{
private:

public:
	int testInt; //The test data holder.

	friend std::ostream& operator << (std::ostream& out, const CTestClass& test) //Overloading the output so the int value is given.
	{
		out << test.testInt;
		return out;
	}

	bool operator == (const CTestClass& test) //Comparason for the class data holder.
	{
		return testInt == test.testInt;
	}
};


template<typename K, typename V>
class CMap
{
private:
	template<typename K, typename V>
	struct SPair //Map data(Key & value).
	{
		K key;
		V value;
	};

	int arrSize; //Used for length of array.
	int maxSize; //Max size of the array currently.
	SPair<K, V>* mapArrPtr; //Main map pointer.
	void increaseArray(); //Function for increasing array size once full(Used in addition function)
public:
	CMap();
	~CMap() { delete[] mapArrPtr; }
	V get(K);       //Gets the value from a given key
	bool search(K); //Finds the key in the map
	void add(K, V); //Adds a data set to the map.
	void printAll();//Prints all data held in the map.
	void empty();   //Clears up the map & resets it.
	void remove(K); //Removes an item in the map with a key input.
	int arraySize() { return arrSize; } //Gets array current size.
};

template<typename K, typename V>
CMap<K, V>::CMap<K, V>() //Constructor for the map.
{
	maxSize = 100; //Default size for the map.
	arrSize = 0;   //Current "size" of the array.
	mapArrPtr = new SPair<K, V>[maxSize];
}

template<typename K, typename V>
void CMap<K, V>::increaseArray()
{
	SPair<K, V>* mapArrPtrTmp = new SPair<K, V>[maxSize * 2]; //Doubles the size in the array.
	maxSize *= 2;
	for (int i = 0; i < arrSize; i++) //Copies the data from the main array to the temp array.
	{
		mapArrPtrTmp[i] = mapArrPtr[i];
	}
	mapArrPtr = mapArrPtrTmp; //Overwrites the map pointer to the new data.
}

template<typename K, typename V>
V CMap<K, V>::get(K key)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (mapArrPtr[i].key == key) //Finds the key from the map.
		{
			std::cout << key << " value is: " << mapArrPtr[i].value << std::endl;
			return mapArrPtr[i].value; //Sends back the value from the key.
		}
	}
}

template<typename K, typename V>
bool CMap<K, V>::search(K Key)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (mapArrPtr[i].key == Key) //Finds if the value exists and sends back true if found.
		{
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
void CMap<K, V>::add(K Key, V Value)
{
	if (search(Key)) { return; } //Makes sure the key doesnt already exist.

	if (arrSize == (maxSize - 1)) //Checks if the map is full.
	{
		increaseArray();
	}

	if (arrSize < maxSize)
	{
		//Adds the data to the end of the map
		mapArrPtr[arrSize].key = Key;
		mapArrPtr[arrSize].value = Value;
		arrSize++;
	}
}

template<typename K, typename V>
void CMap<K, V>::printAll()
{
	for (int i = 0; i < arrSize; i++)
	{
		std::cout <<"["<< i <<"] " <<"Key: " << mapArrPtr[i].key << " Value: " << mapArrPtr[i].value << std::endl;
	}
}

template<typename K, typename V>
void CMap<K, V>::empty()
{
	delete[] mapArrPtr; //Deletes the map array.
	//Resets the map data.
	maxSize = 100;
	arrSize = 0;
	mapArrPtr = new SPair<K, V>[maxSize];
}

template<typename K, typename V>
void CMap<K, V>::remove(K key)
{
	SPair<K, V>* mapArrPtrTmp = new SPair<K, V>[maxSize]; //Temp array for copying over the map.
	int t = 0;
	if (search(key)) //Checks to make sure the key is valid.
	{
		for (int i = 0; i < arrSize; i++)
		{
			if (mapArrPtr[i].key == key) { t++; } //If the key you want removed skip it.
			mapArrPtrTmp[i] = mapArrPtr[t]; 
			t++;
		}
		arrSize--;
		mapArrPtr = mapArrPtrTmp;
	}
}