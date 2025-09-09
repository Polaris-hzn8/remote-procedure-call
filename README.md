# 分布式网络通信框架RPC

---

RPC：远程过程调用Remote Procedure Call Protocal

C++实现轻量级RPC分布式网络通信框架：https://blog.csdn.net/asdfadafd/article/details/126801651

### 1.技术点

1. 集群与分布式理论
2. RPC远程过程调用原理以及实现
3. 数据序列化与反序列化：Protobuf
4. 服务注册中心：Zookeeper分布式一致性协调服务
5. 网络库编程：muduo
6. conf配置文件读取
7. cmake构建项目集成编译环境

### 2.集群与分布式

- 集群：每台服务器独立运行工程项目的所有模块
- 分布式：工程项目被拆分多个模块，每个模块独立部署运行到一个服务器主机上，所有服务器协同工作共同提供服务。每台服务器称为分布式的一个结点，根据结点的并发要求，可对结点再做结点模块集群部署。

![image-20230426200652519](https://s2.loli.net/2023/04/26/BIKyRpa53wmOfsN.png)

- 黄色部分（序列化/反序列化）：设计rpc方法参数的打包和解析，即数据的序列化和反序列化，利用protobuf实现
- 绿色部分（数据传输网络部分）：网络部分，包括寻找rpc服务主机，发起rpc调用请求和响应rpc调用结果，使用netty网络库。

### 3.网络IO模型

1. accpet + read/write

2. accept + fork（process pre connection）

3. accept + thread（thread pre connection）

4. muduo：reactors in threads（one loop per thread）

   主反应堆负责accept连接然后分发到多个sub reactor中，该连接的所有操作都在sub reactor所处的线程中完成，多个连接可能被分派到多个线程中，以充分利用CPU资源。

5. nginx：reactors in process（one loop per process）

   nginx服务器的网络模块基于进程设计，采用多个Reactors充当IO进程和工作进程，通过accept锁解决多个Reactors的惊群现象。

### 4.RPC框架设计













### 5.第三方框架/工具

#### protobuff

protocal buffer是google的一种数据交换格式，其独立于平台语言。google提供了protobuff多种语言的实现：java、c#、c++、go以及python，每种实现都包含了相应语言的编译器以及库文件。

由于其为二进制格式，比使用xml\Json等格式进行数据交换快许多，可以将其用于分布式应用之间的数据通信或者，异构环境下的数据交换。作为一种效率和兼容性都非常优秀的二进制数据传输格式，可以用于诸如网络传输、配置文件、数据存储等诸多领域。

安装流程：

```shell
# 解压源码
unzip protobuf-master.zip
# 安装所需的工具
cd protobuf-master
sudo apt-get install autoconf automake libtool curl make g++ unzip
# 自动生成configure配置文件
./autogen.sh
# 配置环境
./configure
# 编译源代码并安装
make
sudo make install
# 刷新动态库
sudo ldconfig
```

安装多个版本的protobuf：

```shell
# 下载源码并安装 protobuf 2.x
# protoc2 安装在 /opt/protobuf2/bin/protoc
wget https://github.com/protocolbuffers/protobuf/releases/download/v2.6.1/protobuf-2.6.1.tar.gz
tar -xzf protobuf-2.6.1.tar.gz
cd protobuf-2.6.1
./configure --prefix=/opt/protobuf2
make -j$(nproc)
sudo make install
# 下载并安装 protobuf 3.x
# protoc3 安装在 /opt/protobuf3/bin/protoc
wget https://github.com/protocolbuffers/protobuf/releases/download/v3.20.3/protobuf-cpp-3.20.3.tar.gz
tar -xzf protobuf-cpp-3.20.3.tar.gz
cd protobuf-3.20.3
./configure --prefix=/opt/protobuf3
make -j$(nproc)
sudo make install
# 切换使用版本
# 临时切换
export PATH=/opt/protobuf2/bin:$PATH   # 使用 protoc 2.x
export PATH=/opt/protobuf3/bin:$PATH   # 使用 protoc 3.x
# 永久切换，可以写到 ~/.bashrc
# 或者用 update-alternatives：同时管理多个版本的 protoc
sudo update-alternatives --install /usr/bin/protoc protoc /opt/protobuf2/bin/protoc 20
sudo update-alternatives --install /usr/bin/protoc protoc /opt/protobuf3/bin/protoc 30
sudo update-alternatives --config protoc
```

```
wget https://github.com/protocolbuffers/protobuf/releases/download/v3.20.3/protobuf-cpp-3.20.3.tar.gz
tar -xzf protobuf-cpp-3.20.3.tar.gz
cd protobuf-3.20.3
./configure --prefix=/opt/protobuf3
make -j$(nproc)
sudo make install

```



#### zookeeper

Zookeeper在分布式环境中应用十分广泛，其优秀的功能很多，如分布式环境中全局命名服务注册中心，全局分布式锁等。参考：https://www.cnblogs.com/xinyonghu/p/11031729.html

几个问题：

1. zk的数据是如何组织的？znode节点
2. zk的watcher机制？

```shell
# 解压源码
unzip zookeeper-3.4.10.tar.gz
# 配置文件
cd conf
mv zoo_sample.cfg zoo.cfg
# 启动zookeeper
cd bin
./zkServer.sh start
# 通过 netstat 查看 zkServer 的端口
# 在bin目录启动zkClient.sh链接zkServer
# 熟悉zookeeper组织节点
```

zookeeper已经提供了原生的C/C++和JavaAPI开发的接口，需要通过源码编译生成：

```shell
# zk的原生开发api
# 进入解压后的src/c目录下
 sudo ./configure
 sudo make
 sudo make install
```

主要关注zookeeper如何管理节点：创建节点、获取节点，删除节点以及watcher机制的API编程。

znode节点存储格式：

![image-20250805141050032](assets/image-20250805141050032.png)





































