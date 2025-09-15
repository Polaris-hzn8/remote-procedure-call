rm -rf pbgen
mkdir pbgen
protoc test.proto --cpp_out ./pbgen
g++ main.cc ./pbgen/*.cc \
    -I/opt/protobuf3/include \
    -L/opt/protobuf3/lib \
    -lprotobuf -pthread \
    -o a.out
    