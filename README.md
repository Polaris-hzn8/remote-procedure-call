# 分布式网络通信框架myrpc

---

优秀参考：

- C++实现轻量级RPC分布式网络通信框架：https://blog.csdn.net/asdfadafd/article/details/126801651
- 施磊：基于protobuf与muduo的rpc框架

### 一、主要技术点

1. 集群与分布式概念以及理论
2. RPC远程过程调用原理以及实现
3. Protobuf数据序列化和反序列化协议
4. Zookeeper分布式一致性协调服务应用以及编程
5. muduo网络库编程
6. conf配置文件读取
7. Cmake构建项目集成编译环境

### 二、集群和分布式

集群：每一台服务器独立运行一个工程的所有模块

分布式：一个工程拆分了很多模块，每一个模块独立部署运行在一个服务器主机上，所有服务器协同工作共同提供服务，每一台服务器称为分布式的一个结点，根据结点的并发要求，对一个结点可以再做结点模块集群部署。

RPC通信原理：Remote Procedure Call Protocal远程过程调用协议，

![image-20230426200652519](https://s2.loli.net/2023/04/26/BIKyRpa53wmOfsN.png)

- 黄色部分：设计rpc方法参数的打包和解析，即数据的序列化和反序列化，使用protobuf
- 绿色部分：网络部分，包括寻找rpc服务主机，发起rpc调用请求和响应rpc调用结果，使用netty网络库。













































