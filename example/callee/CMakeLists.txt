
# 源文件
set(SRC_LIST user_service.cc ../protobuff/pbgen/*.cc)

# 头文件
include_directories(../protobuff/pbgen)

# 可执行文件
add_executable(rpc_provider ${SRC_LIST})