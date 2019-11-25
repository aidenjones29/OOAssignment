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
	void add(K, V);
	void printAll();
};

template<typename K, typename V>
CMap<K,V>::CMap<K,V>()
{
	maxSize = 100;
	arrSize = 0;
	mapArrPtr = new SPair<K,V>[maxSize];
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
}

template<typename K, typename V>
V CMap<K, V>::get(K key)
{

	for (int i = 0; i < arrSize; i++)
	{
		if (mapArrPtr[i].key == key)
		{
			std::cout << std::endl << key << " Found!" << std::endl;
			return mapArrPtr[i].value;
		}
	}
}

template<typename K, typename V>
void CMap<K, V>::add(K Key, V Value)
{
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


int main()
{
	//std::cout << "Hello World!\n";
	CMap<int, std::string>* map = new CMap<int, std::string>();
	map->add(1, "Test");
	map->add(2, "Who's sam?");
	map->add(3, "Test");
	map->printAll();
	std::string Test = map->get(2);
	std::cout << "The value found was: " << Test << std::endl;
	system("Pause");
}