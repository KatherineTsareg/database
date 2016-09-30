#include "stdafx.h"
#include "EntityElement.h"

using namespace std;

vector<string> GetIdByName(vector<CEntityElement> const& database, string const& name)
{
	vector<string> result;
	for_each(begin(database), end(database), [&](auto element) 
	{
		if (element.GetUsername() == name)
		{
			result.push_back(element.GetId());
		}
	});
	return result;
}

void PrintSearchResults(vector<string> const& idList)
{
	size_t size = idList.size();
	if (size == 0)
	{
		cout << "no matches";
	}
	for (size_t i = 0; i < size; i++)
	{
		cout << idList[i];
		if ((size > 1) && (i != size - 1))
		{
			cout << ", ";
		}
	}
	cout << endl;
}

vector<CEntityElement> ReadInputFile(string const& fileName)
{
	vector<CEntityElement> database;
	ifstream fin;
	fin.open(fileName);

	string line;
	if (!fin.is_open())
	{
		cerr << "can't open" + fileName << endl;
	}
	else
	{
		getline(fin, line);
		while (getline(fin, line))
		{
			database.push_back(CEntityElement(line));
		}
	}
	return database;
}


int _tmain(int argc, char * argv[])
{
	vector<CEntityElement> database = ReadInputFile("db.csv");
	string commandLine;
	if (database.size() == 0)
	{
		return 1;
	}
	while (!cin.eof() && !cin.fail())
	{
		cout << "Enter username: ";
		getline(cin, commandLine);

		PrintSearchResults(GetIdByName(database, commandLine));
		cout << endl;
	}
    return 0;
}

