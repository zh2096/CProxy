#include <sys/types.h>
#include "lib/Msg.h"
#include "Client.h"
#include "spdlog/spdlog.h"
int main() {
  // 初始化日志格式
  spdlog::set_pattern("[%@ %H:%M:%S:%e %z] [%^%L%$] [thread %t] %v");
  // 主线程loop：处理ctlConn的读写
  // eventloop线程池：处理proxyConn的读写+innerConn的读写
  Client client(1, "127.0.0.1", 8080, "127.0.0.1", 7777);
  client.start();
}