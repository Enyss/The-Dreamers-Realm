#include "xmlManager.h"

void XmlManager::init(std::string masterPath)
{
	xml["master"].load_file(masterPath.c_str());
	pugi::xml_node node = xml["master"].child("files");
	for (pugi::xml_node_iterator it = node.begin(); it != node.end(); ++it)
	{
		xml[it->name()].load_file(it->attribute("file").value());
	}
}

pugi::xml_node XmlManager::getNode(std::string path)
{
	pugi::xml_node node;
	std::vector<std::string> tokens = tokenize(path);

	if (tokens.size() > 0)
	{

		node = xml[tokens[0]].child(tokens[0].c_str());
		

		for (size_t i = 1; i < tokens.size(); i++)
		{
			node = node.child(tokens[i].c_str());
		}
	}
	return node;
}

std::vector<std::string> XmlManager::tokenize(std::string str)
{
	std::vector<std::string> tokens;
	size_t pos, lastPos = 0;

	while (true)
	{
		pos = str.find_first_of("/", lastPos);
		if (pos == std::string::npos)
		{
			pos = str.length();

			if (pos != lastPos)
				tokens.push_back(str.substr(lastPos, pos - lastPos));
			break;
		}
		else
		{
			if (pos != lastPos)
				tokens.push_back(str.substr(lastPos, pos - lastPos));
		}

		lastPos = pos + 1;
	}
	return tokens;
}
