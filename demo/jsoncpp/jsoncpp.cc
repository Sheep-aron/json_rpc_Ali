#include <iostream>
#include <jsoncpp/json/json.h>
#include <memory>
#include <sstream>
#include <string>

int main()
{
    Json::Value stu;
    stu["name"] = "Sheep";
    stu["age"] = 18;
    stu["score"].append(95);
    stu["score"].append(97);
    stu["score"].append(98);

    Json::StreamWriterBuilder swb;
    std::unique_ptr<Json::StreamWriter> sw(swb.newStreamWriter());
    std::stringstream ss;
    int ret = sw->write(stu, &ss);
    if (ret != 0)
    {
        std::cerr << "writ json failed" << std::endl;
        return -1;
    }
    std::cout << ss.str() << std::endl;

    std::cout << "================================================" << std::endl;

    std::string str = ss.str();
    Json::Value root;
    Json::CharReaderBuilder rb;
    std::unique_ptr<Json::CharReader> cr(rb.newCharReader());
    bool rat = cr->parse(str.c_str(), str.c_str() + str.size(), &root, nullptr);
    if (!rat)
    {
        std::cerr << "parse json failed" << std::endl;
        return -1;
    }
    std::cout << "age: " << root["age"].asInt() << "\nname: " << root["name"].asString();
    std::cout << "\nscores: ";
    for (const auto &s : root["score"])
        std::cout << s.asInt() << " ";
    std::cout << std::endl;

    return 0;
} 