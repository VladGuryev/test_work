#ifndef CUSTOM_NOT_FOUND_EXCEPTION_H
#define CUSTOM_NOT_FOUND_EXCEPTION_H
#include <not_found_exception.h>

template<typename TKey>
class CustomNotFoundException : public NotFoundException<TKey>
{
private:
    TKey& exceptionKey;

public:
    explicit CustomNotFoundException(TKey notFoundKey) :
        exceptionKey(notFoundKey){ }

    const TKey& GetKey() const noexcept override{
        return exceptionKey;
    }
    virtual ~CustomNotFoundException() noexcept { }

    // exception interface
public:
     const char* what() const noexcept override {
        return "Requested key not found";
     }
};






#endif // CUSTOM_NOT_FOUND_EXCEPTION_H
