#include <iostream>
#include <string>
#include "Map.cpp"

int main()
{
	//******************* KEY: STRING VALUE: STRING *******************//
	CMap<std::string, std::string>* map1 = new CMap<std::string, std::string>();
	
	for (int i = 0; i < 10; i++)
	{
		map1->add(std::to_string(i), "Who's sam?");
	}
	
	map1->add("69", "Who's sam? 1");

	map1->printAll();
	std::string Test0 = map1->search("Who's sam? 1");
	std::string Test1 = map1->get("8");

	std::cout << std::endl;

	map1->empty();

	for (int i = 0; i < 10; i++)
	{
		map1->add(std::to_string(i), "Who's sam after delete?");
	}
	map1->printAll();

	//******************* KEY: STRING VALUE: STRING *******************//
	CMap<int, std::string>* map2 = new CMap<int, std::string>();

	for (int i = 0; i < 10; i++)
	{
		map2->add(i, "Who's sam?");
	}

	map2->printAll();
	std::string Test2 = map1->search("Who's sam?");
	std::string Test3 = map2->get(8);

	system("Pause");
}