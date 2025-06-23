#pragma once
#include <string>
#include <vector>


class Util
{
public:
	static bool ContinueOperation(std::string msg = "\nAre You Sure To Perform This Operation (y / n) : ");

	static std::string ConvertVectorDataToLine(std::vector<std::string> myData, std::string delimiter = "|");

	static std::vector<std::string> SplitRecord(std::string str, std::string delimiter = "|");

};
