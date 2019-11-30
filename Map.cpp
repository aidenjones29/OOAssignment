#include <iostream>

class CTestClass
{
private:

public:
	int testInt;

	friend std::ostream& operator << (std::ostream& out, const CTestClass& test)
	{
		out << test.testInt;
		return out;
	}

	bool operator == (const CTestClass& test)
	{
		return testInt == test.testInt;
	}
};


template<typename K, typename V>
class CMap
{
private:
	template<typename K, typename V>
	struct SPair
	{
		K key;
		V value;
	};

	int arrSize;
	int maxSize;
	SPair<K, V>* mapArrPtr;
	void increaseArray();
public:
	CMap();
	~CMap() { delete[] mapArrPtr; }
	V get(K);
	bool search(K);
	void add(K, V);
	void printAll();
	void empty();
	void remove(K);
	int arraySize() { return arrSize; }
};

template<typename K, typename V>
CMap<K, V>::CMap<K, V>()
{
	maxSize = 100;
	arrSize = 0;
	mapArrPtr = new SPair<K, V>[maxSize];
}

template<typename K, typename V>
void CMap<K, V>::increaseArray()
{
	SPair<K, V>* mapArrPtrTmp = new SPair<K, V>[maxSize * 2];
	maxSize *= 2;
	for (int i = 0; i < arrSize; i++)
	{
		mapArrPtrTmp[i] = mapArrPtr[i];
	}
	mapArrPtr = mapArrPtrTmp;
}

template<typename K, typename V>
V CMap<K, V>::get(K key)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (mapArrPtr[i].key == key)
		{
			std::cout << key << " value is: " << mapArrPtr[i].value << std::endl;
			return mapArrPtr[i].value;
		}
	}
}

template<typename K, typename V>
bool CMap<K, V>::search(K Key)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (mapArrPtr[i].key == Key)
		{
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
void CMap<K, V>::add(K Key, V Value)
{
	if (search(Key)) { return; }

	if (arrSize == (maxSize - 1))
	{
		increaseArray();
	}

	if (arrSize < maxSize)
	{
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
	delete[] mapArrPtr;
	maxSize = 100;
	arrSize = 0;
	mapArrPtr = new SPair<K, V>[maxSize];
}

template<typename K, typename V>
void CMap<K, V>::remove(K key)
{
	SPair<K, V>* mapArrPtrTmp = new SPair<K, V>[maxSize];
	int t = 0;
	if (search(key))
	{
		for (int i = 0; i < arrSize; i++)
		{
			if (mapArrPtr[i].key == key) { t++; }
			mapArrPtrTmp[i] = mapArrPtr[t];
			t++;
		}
		arrSize--;
		mapArrPtr = mapArrPtrTmp;
	}
}