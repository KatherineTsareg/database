#pragma once
#include "stdafx.h"

class CEntityElement
{
public:
	CEntityElement(std::string const& input);
	std::string GetId();
	std::string GetUsername();
	~CEntityElement();
private:
	std::string m_id;
	std::string m_file;
	std::string m_description;
	std::string m_autor;
	std::string m_platform;
	std::string m_type;
	std::string m_date;
	std::string m_port;
};

