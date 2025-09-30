#include <iostream>
#include <jsoncpp/json/json.h>
#include <memory>
#include <sstream>

int main()
{
    Json::Value stu;
    stu["name"] = "Sheep";
    stu["age"] = 18;
    stu["score"].append(95);
    stu["score"].append(97);
    stu["score"].append(98);

    Json::StreamWriterBuilder builder;
    std::unique_ptr<Json::StreamWriter> sw(builder.newStreamWriter());
    std::stringstream ss;
    int ret = sw->write(stu, &ss);
    if (ret != 0)
    {
        std::cerr << "writ json failed" << std::endl;
        return -1;
    }
    std::cout << ss.str() << std::endl;
    return 0;
} 