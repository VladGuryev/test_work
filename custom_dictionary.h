#ifndef CUSTOM_DICTIONARY_H
#define CUSTOM_DICTIONARY_H
#include <map>
#include <dictionary.h>
#include <custom_not_found_exception.h>

template<class TKey, class TValue>
class CustomDictionary: public Dictionary<TKey, TValue>
{
private:
    std::map<TKey, TValue> dict;

public:
    CustomDictionary(){

    }
    const TValue& Get(const TKey& key) const override{
        if(!this->IsSet(key)){
            throw CustomNotFoundException<TKey>(key);
        }
        return dict.at(key);
    }
    void Set(const TKey& key, const TValue& value) override{
        dict[key] = value;
    }
    bool IsSet(const TKey& key) const override{
        return dict.count(key) ? true : false;
    }
};

#endif
