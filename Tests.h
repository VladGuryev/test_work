#include <random>
#include "Dictionary.h"
#include "NotFoundException.h"
#include "TestRunner.h"

using namespace std;

void ExceptionHandlingTest()
{
    Dictionary<int, string> dict;
    int keyNotFound = 3;
    try {
      auto value = dict.Get(keyNotFound);
    } catch (NotFoundException<int>& e) {
        ASSERT_EQUAL(e.GetKey(), keyNotFound);
        ASSERT_EQUAL(e.what(), "Requested key is not found");
    }

    int keyFound = 2;
    dict.Set(keyFound, "Dr.Web");
    ASSERT_EQUAL(dict.IsSet(keyFound), true);
    ASSERT_EQUAL(dict.IsSet(keyNotFound), false);
}

void InitializationTest()
{
    Dictionary<int, string> dict;
    dict.Set(1, "abcd");
    //copy ctor
    Dictionary<int, string> anotherDict(dict);
    ASSERT_EQUAL(anotherDict.Get(1), "abcd");
    //move ctor
    Dictionary<int, string> yetAnotherDict(move(dict));
    ASSERT_EQUAL(yetAnotherDict.Get(1), "abcd");
    try {
      ASSERT_EQUAL(dict.Get(1), "abcd");
    } catch (NotFoundException<int>& e) {
      ASSERT_EQUAL(e.GetKey(), 1);
      ASSERT_EQUAL(e.what(), "Requested key is not found");
    }
    //copy assigment
    dict = yetAnotherDict;
    ASSERT_EQUAL(dict.Get(1), "abcd");
}

void IteratingTest()
{
    Dictionary<int, string> dict;
    vector<int> keys = {1, 7, 12, 18};
    vector<string> values = {"xyz", "abc", "gwe", "fuh"};
    for(size_t i = 0; i < keys.size(); i++){
        dict.Set(keys[i], values[i]);
    }

    size_t kol = 0;
    for(const auto& keyValue : dict){
      ASSERT_EQUAL(keyValue.first, keys[kol]);
      ASSERT_EQUAL(keyValue.second, values[kol]);
      kol++;
    }
}

void DictionaryGetSetTests()
{
    //first attempt
    Dictionary<int, string> dict;
    int keyOne = 1;
    int keyTwo = 2;
    string valueOne = "a";
    string valueTwo = "b";
    dict.Set(keyOne, valueOne);
    dict.Set(keyTwo, valueTwo);

    auto expected1 = "a";
    ASSERT_EQUAL(dict.Get(keyOne), expected1);
    expected1 = "b";
    ASSERT_EQUAL(dict.Get(keyTwo), expected1);

    //second attempt
    Dictionary<string, set<int>> dict2;
    string key1 = "alpha";
    string key2 = "omega";
    string key3 = "epsilon";
    set<int> value1 {1, 5, 8, 9 ,12};
    set<int> value2 {0, 16, 3, 1};
    set<int> value3 {10, -1, 90, 8};
    dict2.Set(key1, value1);
    dict2.Set(key2, value2);
    dict2.Set(key3, value3);

    auto expected2 = value1;
    ASSERT_EQUAL(dict2.Get(key1), expected2);
    expected2 = value2;
    ASSERT_EQUAL(dict2.Get(key2), expected2);
    expected2 = value3;
    ASSERT_EQUAL(dict2.Get(key3), expected2);

    //third attempt
    Dictionary<long, long> dict3;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 100'000);
    int key;
    int value;
    for(int i = 0; i < 10'000; i++){
      key = i* dis(gen);
      value = i * i * dis(gen);
      dict3.Set(key, value);
      ASSERT_EQUAL(dict3.Get(key), value);
    }
}
