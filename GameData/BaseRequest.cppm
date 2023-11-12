export module BaseRequest;

import <string>;


export template <typename T>
class BaseRequest
{
public:
	BaseRequest(const T& RequestObject);
	T GetObject() const;
private:
	T m_requestObject;

};

template <typename T>
BaseRequest<T>::BaseRequest(const T& RequestObject) : m_requestObject(RequestObject)
{
}

template <typename T>
T BaseRequest<T>::GetObject() const
{
	return m_requestObject;
}
