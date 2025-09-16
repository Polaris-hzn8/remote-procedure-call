// 提供rpc服务
// 远程方法名字、方法参数、方法返回值序列化与反序列化

#include <string>
#include <iostream>
#include "user.pb.h"

class UserService
{
public:
    bool Login(const std::string& user_name, const std::string& user_pwd) {
        std::cout << "do local service: login" << std::endl;
        std::cout << "user_name" << user_name << "user_pwd" << user_pwd << std::endl;
    }
};

int main()
{


}

