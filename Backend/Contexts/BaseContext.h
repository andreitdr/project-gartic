#pragma once

template <typename RequestType, typename ResponseType>
class BaseContext
{
public:
	virtual ~BaseContext() = default;
	virtual ResponseType HandleRequest(const RequestType& request) = 0;

protected:
	virtual void ApplyChanges(const RequestType& request) = 0;
};