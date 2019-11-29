#include <iostream>
#include <string>
#include "Map.cpp"

const int testLength = 26;
int testNumber = 1;
int intTestKey[testLength] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };
float floatTest[testLength] = { 1.5f,2.5f,3.5f,4.5f,5.5f,6.5f,7.5f,8.5f,9.5f,10.5f,11.5f,12.5f,13.5f,14.5f,15.5f,16.5f,17.5f,18.5f,19.5f,20.5f,21.5f,22.5f,23.5f,24.5f,25.5f,26.5f };
double doubleTest[testLength] = { 1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,10.5,11.5,12.5,13.5,14.5,15.5,16.5,17.5,18.5,19.5,20.5,21.5,22.5,23.5,24.5,25.5,26.5 };
int intTestValue[testLength] = { 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260 };
char charTest[testLength] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
bool boolTest[testLength] = { true, false, false, true, true, true, false, true, false, false, true, true, true, false, true, false, false, true, true, true, false,true, false, false, true, true};
std::string stringTest[testLength] =
{
	"Sam Whosthatason","Joe Bloggs", "Billy Jean","Beaux Boppings", "Leah Bigboi","Nikeh Ladyboi", "Bill Bob","Brian Blessed", "Flabby McGee"
	,"Daniel Karavan", "David Square","Jay Steward", "Jack Touchpeen","Matt Wheals", "Nick Meetchel","Harry Bollz", "Bed Dover","Jack Binboomboom", "Hilly Teen"
	,"FirstYearsSuckLmao", "Biggie Boobieson","Fat Al", "Sarah Gonzalez","Michelle Honote", "Gimmie Tires","ICantThinkOfNames"
};

template<typename K, typename V>
void testCase(K key[], V value[]);

int main()
{
	testCase(intTestKey, intTestValue);
	testCase(intTestKey, doubleTest);
	testCase(intTestKey, floatTest);
	testCase(intTestKey, charTest);
	testCase(intTestKey, stringTest);
	testCase(intTestKey, boolTest);

	testCase(doubleTest, intTestValue);
	testCase(doubleTest, doubleTest);
	testCase(doubleTest, floatTest);
	testCase(doubleTest, charTest);
	testCase(doubleTest, stringTest);
	testCase(doubleTest, boolTest);

	testCase(floatTest, intTestValue);
	testCase(floatTest, doubleTest);
	testCase(floatTest, floatTest);
	testCase(floatTest, charTest);
	testCase(floatTest, stringTest);
	testCase(floatTest, boolTest);

	testCase(charTest, intTestValue);
	testCase(charTest, doubleTest);
	testCase(charTest, floatTest);
	testCase(charTest, charTest);
	testCase(charTest, stringTest);
	testCase(charTest, boolTest);

	testCase(stringTest, intTestValue);
	testCase(stringTest, doubleTest);
	testCase(stringTest, floatTest);
	testCase(stringTest, charTest);
	testCase(stringTest, stringTest);
	testCase(stringTest, boolTest);
}


template<typename K, typename V>
void testCase(K key[], V value[])
{
	std::cout << "******************************************** TEST "<< testNumber <<" ********************************************" << std::endl << std::endl;
	std::cout << "****************** Initialising map ******************" << std::endl;

	CMap<K, V>* map = new CMap<K, V>();

	for (int i = 0; i < testLength; i++)
	{
		map->add(key[i], value[i]);
	}

	std::cout << "****************** Map initialised ******************" << std::endl << std::endl;
	std::cout << "****************** Printing ******************" << std::endl;
	map->printAll();
	std::cout << "****************** Printed ******************" << std::endl;
	std::cout << std::endl;
	std::cout << "****************** Removing key 4 ******************" << std::endl << std::endl;
	map->remove(key[3]);
	std::cout << "****************** Removed key 4 ******************" << std::endl << std::endl;
	std::cout << "****************** Printing ******************" << std::endl;
	map->printAll();
	std::cout << "****************** Printed ******************" << std::endl << std::endl;
	std::cout << "****************** searching for: "<< key[6] << " ******************" << std::endl;
	bool Test0 = map->search(key[6]);
	if (Test0) { std::cout << key[6] << " Found!" << std::endl << std::endl; }

	std::cout << "****************** Getting value from: " << key[6] << " ******************" << std::endl;
	V Test1 = map->get(key[6]);
	std::cout << std::endl;
	std::cout << "****************** Emptying map ******************" << std::endl;
	map->empty();
	std::cout << "****************** Map size: " << map->arraySize() << " ******************" << std::endl;
	delete map;
	testNumber++;
	system("Pause");
}