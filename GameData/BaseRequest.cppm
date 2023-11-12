export module BaseRequest;

import <string>;


export template <typename T>
class BaseRequest
{
public:
	BaseRequest(const T& RequestObject);
private:
	T m_requestObject;

};

template <typename T>
BaseRequest<T>::BaseRequest(const T& RequestObject) : m_requestObject(RequestObject)
{
}
