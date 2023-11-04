export module BaseResponse;

import <string>;
class BaseResponse
{
public:
	BaseResponse(const std::string& jsonData, bool isSuccess);
	const std::string GetJsonData() const;

private:
	bool m_isSuccess;
	std::string m_jsonData;
};


BaseResponse::BaseResponse(const std::string& jsonData, bool isSuccess) :
	m_isSuccess(isSuccess), m_jsonData(jsonData) {
	// Empty ctor
}

const std::string BaseResponse::GetJsonData() const
{
	return this->m_jsonData;
}