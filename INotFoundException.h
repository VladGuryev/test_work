#ifndef INOTFOUNDEXCEPTION_H
#define INOTFOUNDEXCEPTION_H
#include <exception>

template<typename TKey>
class INotFoundException : public std::exception
{
public:
    virtual const TKey& GetKey() const noexcept = 0;
};


#endif
