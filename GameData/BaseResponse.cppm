export module BaseResponse;

import <string>;
import <vector>;
export class BaseResponse
{
public:
	BaseResponse(const std::string& message, bool isSuccess);
	const std::vector<std::string> GetResponseMessages() const;
	const bool GetResponseState() const;
	void SetResponseState(bool state);
	void AppendMessage(const std::string& message);
private:
	bool m_isSuccess;
	std::vector<std::string> m_responseMessages;
};


BaseResponse::BaseResponse(const std::string& message, bool isSuccess) :
	m_isSuccess(isSuccess) {
	AppendMessage(message);
}

void BaseResponse::AppendMessage(const std::string& message)
{
	m_responseMessages.emplace_back(message);
}

const bool BaseResponse::GetResponseState() const
{
	return m_isSuccess;
}

const std::vector<std::string> BaseResponse::GetResponseMessages() const
{
	return m_responseMessages;
}

void BaseResponse::SetResponseState(bool state)
{
	if (!m_isSuccess)
		return;
	m_isSuccess = state;
}
