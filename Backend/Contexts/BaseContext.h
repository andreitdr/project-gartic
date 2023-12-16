#pragma once

template <class RequestType, class ResponseType>
requires std::derived_from<ResponseType, BaseResponse>
class BaseContext
{
public:
	virtual ~BaseContext() = default;
	virtual ResponseType HandleRequest(const RequestType& request) = 0;

protected:
	virtual ResponseType ApplyChanges(const RequestType& request) = 0;
};