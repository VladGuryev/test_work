#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H
#include "INotFoundException.h"

template<typename TKey>
class NotFoundException : public INotFoundException<TKey>
{
private:
    const TKey& exceptionKey;

public:
    explicit NotFoundException(const TKey& notFoundKey) :
        exceptionKey(notFoundKey){ }

    virtual ~NotFoundException() noexcept { }

    /*implemented INotFoundException interface
     * */
    const TKey& GetKey() const noexcept override{
        return exceptionKey;
    }

public:
    /*implemented std::exception interface
     * */
     const char* what() const noexcept override {
        return "Requested key is not found";
     }
};






#endif // CUSTOM_NOT_FOUND_EXCEPTION_H
