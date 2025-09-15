
#include "pbgen/test.pb.h"
#include <iostream>
#include <string>
using namespace fixbug;

void test1()
{
    // 序列化
    LoginRequest req;
    req.set_user_id(10001);
    req.set_pass_word("1234560");
    std::string str_req;
    if (req.SerializeToString(&str_req)) {
        std::cout << str_req << std::endl;
    }

    // 反序列化
    LoginRequest reqX;
    if (reqX.ParseFromString(str_req)) {
        std::cout << reqX.user_id() << std::endl;
        std::cout << reqX.pass_word() << std::endl;
    }

    // 登陆请求响应
    LoginResponse rsp;
    ResultCode* rc = rsp.mutable_ret_code();
    rc->set_err_code(0);
    rc->set_err_msg("login_succeed.");
}

void test2()
{
    // 好友列表获取响应
    GetFriendListResponse rsp;
    ResultCode* rc = rsp.mutable_ret_code();
    rc->set_err_code(0);
    rc->set_err_msg("friend list succeed.");

    UserInfo* userInfo = nullptr;
    userInfo = rsp.add_friend_list();
    userInfo->set_id(10001);
    userInfo->set_name("luochenhao");
    userInfo->set_age(25);
    userInfo->set_sex(UserInfo::MAN);

    userInfo = rsp.add_friend_list();
    userInfo->set_id(10002);
    userInfo->set_name("lch");
    userInfo->set_age(27);
    userInfo->set_sex(UserInfo::MAN);
    
    std::cout << rsp.friend_list_size() << std::endl;
}

int main()
{
    test1();
    test2();

    return 0;
}
