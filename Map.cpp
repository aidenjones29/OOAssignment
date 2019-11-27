#include <iostream>

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
	V get(K);
	K search(V);
	void add(K, V);
	void printAll();
	void empty();
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
			std::cout << key << " Found! - value is: " << mapArrPtr[i].value << std::endl;
			return mapArrPtr[i].value;
		}
	}
	std::cout << "The value was NOT found " << std::endl;
	return "NULL";
}

template<typename K, typename V>
K CMap<K, V>::search(V Value)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (mapArrPtr[i].value == Value)
		{
			std::cout << Value << " Found! - key is: " << mapArrPtr[i].key << std::endl;
			return mapArrPtr[i].key;
		}
	}
}

template<typename K, typename V>
void CMap<K, V>::add(K Key, V Value)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (mapArrPtr[i].key == Key)
		{
			std::cout << "ERROR: Key already exists" << std::endl;
			return;
		}
	}

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
		std::cout << "Key: " << mapArrPtr[i].key << " Value: " << mapArrPtr[i].value << std::endl;
	}
}

template<typename K, typename V>
void CMap<K, V>::empty()
{
	SPair<K, V>* mapArrPtrTmp = new SPair<K, V>[100];
	mapArrPtr = mapArrPtrTmp;
	arrSize = 0;
}