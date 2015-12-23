#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "pugixml.hpp"

class XmlManager
{
public:
	void init( std::string masterPath );
	pugi::xml_node getNode(std::string path);
private:
	std::vector<std::string> tokenize(std::string str);

	std::map<std::string, pugi::xml_document> xml;
};

