#ifndef IDICTIONARY_H
#define IDICTIONARY_H

template<typename TKey, typename TValue>
class IDictionary
{
public:
    virtual ~IDictionary() = default;

    virtual const TValue& Get(const TKey& key) const = 0;
    virtual void Set(const TKey& key, const TValue& value) = 0;
    virtual bool IsSet(const TKey& key) const = 0;
};


#endif // DICTIONARY_H
