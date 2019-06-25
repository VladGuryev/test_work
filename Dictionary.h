#ifndef CUSTOM_DICTIONARY_H
#define CUSTOM_DICTIONARY_H
#include <map>
#include <IDictionary.h>
#include <NotFoundException.h>

template<class TKey, class TValue>
class Dictionary : public IDictionary<TKey, TValue>
{
private:
    std::map<TKey, TValue> dict;

public:
    Dictionary() = default;
    virtual ~Dictionary() = default;

    /*implemented interface
     * */
    const TValue& Get(const TKey& key) const override{
        if(!this->IsSet(key)){
            throw NotFoundException<TKey>(key);
        }
        return dict.at(key);
    }
    void Set(const TKey& key, const TValue& value) override{
        dict[key] = value;
    }
    bool IsSet(const TKey& key) const override{
        return dict.count(key) ? true : false;
    }

    //std-like interface
    TValue& operator[](const TKey& key){
        return dict[key];
    }
    const TValue& operator[](const TKey& key) const {
        return dict[key];
    }

    using iterator = typename std::map<TKey, TValue>::iterator;
    using const_iterator = typename std::map<TKey, TValue>::const_iterator;

    iterator begin(){
      return dict.begin();
    }
    iterator end(){
      return dict.end();
    }
    const_iterator begin() const{
      return dict.begin();
    }
    const_iterator end() const{
      return dict.end();
    }
};

#endif
