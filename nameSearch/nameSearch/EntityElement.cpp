#include "stdafx.h"
#include "EntityElement.h"
#include <ostream>

using namespace std;


CEntityElement::CEntityElement(std::string const& input)
{
	string var;
	size_t variableCount = 1;
	auto pos = input.find(",");
	auto oldPos = 0;
	while (pos != string::npos)
	{
		var = input.substr(oldPos, pos - oldPos);
		oldPos = pos + 1;
		pos = input.find(",", oldPos);
		switch (variableCount++)
		{
		case 1:
			m_id = var;
			break;
		case 2:
			m_file = var;
			break;
		case 3:
			m_description = var;
			break;
		case 4:
			m_date = var;
			break;
		case 5:
			if (var[0] == '"' && var.back() == '"')
			{
				var.erase(0, 1);
				var.erase(var.size() - 1, 1);
			}
			m_autor = var;
			break;
		case 6:
			m_platform = var;
			break;
		case 7:
			m_type = var;
			break;
		case 8:
			m_port = var;
			break;
		}

	}
}

std::string CEntityElement::GetId()
{
	return m_id;
}

std::string CEntityElement::GetUsername()
{
	return m_autor;
}


CEntityElement::~CEntityElement()
{
}
