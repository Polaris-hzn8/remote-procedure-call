g++ main.cc test.pb.cc \
    -I/opt/protobuf3/include \
    -L/opt/protobuf3/lib \
    -lprotobuf -pthread \
    -o a.out
    