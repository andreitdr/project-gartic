export module BaseRequest;

import <string>;

class BaseRequest
{
public:
	BaseRequest(const std::string& jsonData);
private:
	std::string m_jsonData;

};

BaseRequest :: BaseRequest(const std::string& jsonData) : m_jsonData(jsonData) {
	// Empty ctor
}

