#ifndef NOT_FOUND_EXCEPTION_H
#define NOT_FOUND_EXCEPTION_H
#include <exception>

template<typename TKey>
class NotFoundException : public std::exception
{
public:
    virtual const TKey& GetKey() const noexcept = 0;
};


#endif
