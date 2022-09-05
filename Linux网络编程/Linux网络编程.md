#   一、网络基础

## 协议的概念

### 什么是协议

协议：

  一组规则。

![image-20220228214408266](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220228214408266.png)

### 典型协议

应用层 常见的协议有HTTP协议，FTP协议。

传输层 常见协议有TCP/UDP协议。

网络层 常见协议有IP协议、ICMP协议、IGMP协议。

网络接口层 常见协议有ARP协议、RARP协议。

TCP[传输控制协议](http://baike.baidu.com/view/544903.htm)（Transmission Control Protocol）是一种面向连接的、可靠的、基于字节流的[传输层](http://baike.baidu.com/view/239605.htm)通信协议。

UDP用户数据报协议（User Datagram Protocol）是[OSI](http://baike.baidu.com/view/113948.htm)参考模型中一种无连接的[传输层](http://baike.baidu.com/view/239605.htm)协议，提供面向事务的简单不可靠信息传送服务。优点是快速，常用于视频通话等。

HTTP[超文本传输协议](http://baike.baidu.com/view/468465.htm)（Hyper Text Transfer Protocol）是[互联网](http://baike.baidu.com/view/6825.htm)上应用最为广泛的一种[网络协议](http://baike.baidu.com/view/16603.htm)。

FTP文件传输协议（File Transfer Protocol）

IP协议是[因特网](http://baike.baidu.com/view/1706.htm)互联协议（Internet Protocol）

ICMP协议是Internet控制[报文](http://baike.baidu.com/view/175122.htm)协议（Internet Control Message Protocol）它是[TCP/IP协议族](http://baike.baidu.com/view/2221037.htm)的一个子协议，用于在IP[主机](http://baike.baidu.com/view/23880.htm)、[路由](http://baike.baidu.com/view/18655.htm)器之间传递控制消息。

IGMP协议是 Internet 组管理协议（Internet Group Management Protocol），是因特网协议家族中的一个组播协议。该协议运行在主机和组播路由器之间。

[ARP](http://baike.baidu.com/view/32698.htm)协议是正向[地址解析协议](http://baike.baidu.com/view/149421.htm)（Address Resolution Protocol），通过已知的IP，寻找对应主机的[MAC地址](http://baike.baidu.com/view/69334.htm)。

[RARP](http://baike.baidu.com/view/32772.htm)是反向地址转换协议，通过MAC地址确定IP地址。

## 网络应用程序设计模式

### C/S模型

传统的网络应用设计模式，客户机(client)/服务器(server)模式。需要在通讯两端各自部署客户机和服务器来完成数据通信。

### B/S模型

浏览器()/服务器(server)模式。只需在一端部署服务器，而另外一端使用每台PC都默认配置的浏览器即可完成数据的传输。

### 优缺点

```
                 C/S                          B/S
  优点： 缓存大量数据、协议选择灵活、速度快   安全性、跨平台、开发工作量较小 
  缺点： 安全性、跨平台、开发工作量较大      不能缓存大量数据、严格遵守 http
```

## 分层模型

![image-20220228214950173](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220228214950173.png)

### OSI七层模型

OSI七层模型： 物、数、网、传、会、表、应

### TCP/IP四层模型

  TCP/IP 4层模型：网（链路层/网络接口层）、网、传、应			——编写程序常用

​    应用层：http、ftp、nfs、ssh、telnet。。。

​    传输层：TCP、UDP

​    网络层：IP、ICMP、IGMP

​    链路层：以太网帧协议、ARP

![image-20220228215510680](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220228215510680.png)

一般在应用开发过程中，讨论最多的是TCP/IP模型。

## 通信过程

两台计算机通过TCP/IP协议通讯的过程如下所示：

![image-20220228215530552](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220228215530552.png)

数据没有封装之前，是不能在网络中传递。数据每过一层就封装一次：数据-》应用层-》传输层-》网络层-》链路层 --- 网络环境

![image-20220228215852923](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220228215852923.png)

上图对应两台计算机在同一网段中的情况，如果两台计算机在不同的网段中，那么数据从一台计算机到另一台计算机传输过程中要经过一个或多个路由器，如下图所示：

![image-20220228215608186](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220228215608186.png)





## 协议格式

### 数据包封装

![image-20220301211055237](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220301211055237.png)

不同的协议层对数据包有不同的称谓，在传输层叫做段（segment），在网络层叫做数据报（datagram），在链路层叫做帧（frame）。数据封装成帧后发到传输介质上，到达目的主机后每层协议再剥掉相应的首部，最后将应用层数据交给应用程序处理。

### 以太网帧格式

首部：14字节	尾部：4字节

数据长度规定最小46字节，最大1500字节。不够46字节，要在后面补填充位。**最大值**1500称为以太网的最大传输单元（MTU）**，不同的网络类型有不同的MTU，如果一个数据包从以太网路由到拨号链路上，数据包长度大于拨号链路的MTU，则需要对数据包进行分片（fragmentation）。

![image-20220301211223530](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220301211223530.png)

![image-20220301211504526](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220301211504526.png)

  ARP协议：根据 Ip 地址获取 mac 地址。

  以太网帧协议：根据mac地址，完成数据包传输。

### ARP数据报格式

  ARP协议：根据 Ip 地址获取 mac 地址。

在网络通讯时，源主机的应用程序知道目的主机的IP地址和端口号，却不知道目的主机的硬件地址，而数据包首先是被网卡接收到再去处理上层协议的，如果接收到的数据包的硬件地址与本机不符，则直接丢弃。因此在通讯前必须获得目的主机的硬件地址。ARP协议就起到这个作用。源主机发出ARP请求，询问“IP地址是192.168.0.1的主机的硬件地址是多少”，并将这个请求广播到本地网段（以太网帧首部的硬件地址填FF:FF:FF:FF:FF:FF表示广播），目的主机接收到广播的ARP请求，发现其中的IP地址与本机相符，则发送一个ARP应答数据包给源主机，将自己的硬件地址填写在应答包中。

![image-20220301213317663](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220301213317663.png)

### IP段格式（IP协议）

![image-20220301214349132](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220301214349132.png)



IP数据报的首部长度和数据长度都是可变长的，但总是**4字节的整数倍**。

对于IPv4，4位版本字段是4。

4位首部长度的数值是以4字节为单位的，**最小单位值为5**，也就是说**首部长度最小是4x5=20字节**，也就是不带任何选项的IP首部，**4位能表示的最大值是15**，也就是说**首部长度最大是60字节**。

8位TOS字段有3个位用来指定IP数据报的优先级（目前已经废弃不用），还有4个位表示可选的服务类型（最小延迟、最大?吐量、最大可靠性、最小成本），还有一个位总是0。

总长度是整个数据报（包括IP首部和IP层payload）的字节数。

每传一个IP数据报，16位的标识加1，可用于分片和重新组装数据报。

3位标志和13位片偏移用于分片。

TTL（Time to live)是这样用的：源主机为数据包设定一个生存时间，比如64，每过一个路由器就把该值减1，如果减到0就表示路由已经太长了仍然找不到目的主机的网络，就丢弃该包，因此这个生存时间的单位不是秒，而是跳（hop）。

协议字段指示上层协议是TCP、UDP、ICMP还是IGMP。

然后是校验和，只校验IP首部，数据的校验由更高层协议负责。

I**Pv4的IP地址长度为32位。**



**版本**： IPv4、IPv6 -- 4位

**TTL**： time to live 。 设置数据包在路由节点中的跳转上限。每经过一个路由节点，该值-1， 减为0的路由，有义务将该数据包丢弃

**源IP**： 32位。--- 4字节   192.168.1.108 --- 点分十进制 IP地址（string） --- 二进制 

**目的IP**：32位。--- 4字节

![image-20220301220131863](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220301220131863.png)

### UDP数据报格式

![image-20220301215924701](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220301215924701.png)



![image-20220301220158408](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220301220158408.png)



UDP：

  16位：源端口号。 2^16 = 65536 

  16位：目的端口号。

**IP地址：可以在网络环境中，唯一标识一台主机。**

**端口号：可以网络的一台主机上，唯一标识一个进程。**

**ip地址+端口号：可以在网络环境中，唯一标识一个进程。**



### TCP数据报格式

![image-20220301220821620](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220301220821620.png)

TCP协议：

  16位：源端口号。 2^16 = 65536 

  16位：目的端口号。

  32序号;

  32确认序号。 

  6个标志位。

  16位滑动窗口大小。  2^16 = 65536



## ★TCP协议

### ★★★TCP通信时序—三次握手四次挥手

三次握手四次挥手

三次握手：

  主动发起连接请求端，发送 SYN 标志位，请求建立连接。 携带序号号、数据字节数(0)、滑动窗口大小。

  被动接受连接请求端，发送 ACK 标志位，同时携带 SYN 请求标志位。携带序号、确认序号、数据字节数(0)、滑动窗口大小。

  主动发起连接请求端，发送 ACK 标志位，应答服务器连接请求。携带确认序号。



四次挥手：

  主动关闭连接请求端， 发送 FIN 标志位。 

  被动关闭连接请求端， 应答 ACK 标志位。      ----- 半关闭完成。 

  被动关闭连接请求端， 发送 FIN 标志位

  主动关闭连接请求端， 应答 ACK 标志位。   ----- 连接全部关闭

  

滑动窗口：

  发送给连接对端，本端的缓冲区大小（实时），保证数据不会丢失。



![image-20220307220240605](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220307220240605.png)

建立连接（三次握手）的过程（establish connection）：

1. 客户端发送一个带SYN标志的TCP报文到服务器。这是三次握手过程中的段1。

客户端发出段1，SYN位表示连接请求。序号是1000，这个序号在网络通讯中用作临时的地址，每发一个数据字节，这个序号要加1，这样在接收端可以根据序号排出数据包的正确顺序，也可以发现丢包的情况，另外，规定SYN位和FIN位也要占一个序号，这次虽然没发数据，但是由于发了SYN位，因此下次再发送应该用序号1001。mss表示最大段尺寸，如果一个段太大，封装成帧后超过了链路层的最大帧长度，就必须在IP层分片，为了避免这种情况，客户端声明自己的最大段尺寸，建议服务器端发来的段不要超过这个长度。

2. 服务器端回应客户端，是三次握手中的第2个报文段，同时带ACK标志和SYN标志。它表示对刚才客户端SYN的回应；同时又发送SYN给客户端，询问客户端是否准备好进行数据通讯。

服务器发出段2，也带有SYN位，同时置ACK位表示确认，确认序号是1001，表示“我接收到序号1000及其以前所有的段，请你下次发送序号为1001的段”，也就是应答了客户端的连接请求，同时也给客户端发出一个连接请求，同时声明最大尺寸为1024。

3. 客户必须再次回应服务器端一个ACK报文，这是报文段3。

客户端发出段3，对服务器的连接请求进行应答，确认序号是8001。在这个过程中，客户端和服务器分别给对方发了连接请求，也应答了对方的连接请求，其中服务器的请求和应答在一个段中发出，因此一共有三个段用于建立连接，称为“三方握手（three-way-handshake）”。在建立连接的同时，双方协商了一些信息，例如双方发送序号的初始值、最大段尺寸等。

数据传输的过程（data transfer）：

1. 客户端发出段4，包含从序号1001开始的20个字节数据。

2. 服务器发出段5，确认序号为1021，对序号为1001-1020的数据表示确认收到，同时请求发送序号1021开始的数据，服务器在应答的同时也向客户端发送从序号8001开始的10个字节数据，这称为piggyback。

3. 客户端发出段6，对服务器发来的序号为8001-8010的数据表示确认收到，请求发送序号8011开始的数据。

关闭连接（四次挥手）的过程（close connection）：

由于TCP连接是**全双工**的，因此每个方向都必须单独进行关闭。这原则是当一方完成它的数据发送任务后就能发送一个FIN来终止这个方向的连接。收到一个 FIN只意味着这一方向上没有数据流动，一个TCP连接在收到一个FIN后仍能发送数据。首先进行关闭的一方将执行主动关闭，而另一方执行被动关闭。

1. 客户端发出段7，FIN位表示关闭连接的请求。

2. 服务器发出段8，应答客户端的关闭连接请求。

3. 服务器发出段9，其中也包含FIN位，向客户端发送关闭连接请求。

4. 客户端发出段10，应答服务器的关闭连接请求。

![image-20220307220254648](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220307220254648.png)



**客户端与服务器之间的数据传送并不是一次发送一个数据，一次应答一个数据。也可以批量应答**



**半关闭：服务器到客户端关闭或者客户端到服务器关闭**

**半关闭实质上是socket套接字内部的两个缓冲区（r/w）中的一个关闭了**

建立连接的过程是三方握手，而关闭连接通常需要4个段，服务器的应答和关闭连接请求通常不合并在一个段中，因为有连接半关闭的情况，这种情况下客户端关闭连接之后就不能再发送数据给服务器了，但是服务器还可以发送数据给客户端，直到服务器也关闭连接为止。

![image-20220307220329168](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220307220329168.png)



### ★滑动窗口（TCP流量控制）

介绍UDP时我们描述了这样的问题：如果发送端发送的速度较快，接收端接收到数据后处理的速度较慢，而接收缓冲区的大小是固定的，就会丢失数据。TCP协议通过“滑动窗口（Sliding Window）”机制解决这一问题。看下图的通讯过程：

![image-20220307223234628](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220307223234628.png)

1. 发送端发起连接，声明最大段尺寸是1460，初始序号是0，窗口大小是4K，表示“我的接收缓冲区还有4K字节空闲，你发的数据不要超过4K”。接收端应答连接请求，声明最大段尺寸是1024，初始序号是8000，窗口大小是6K。发送端应答，三方握手结束。

2. 发送端发出段4-9，每个段带1K的数据，发送端根据窗口大小知道接收端的缓冲区满了，因此停止发送数据。

3. 接收端的应用程序提走2K数据，接收缓冲区又有了2K空闲，接收端发出段10，在应答已收到6K数据的同时声明窗口大小为2K。

4. 接收端的应用程序又提走2K数据，接收缓冲区有4K空闲，接收端发出段11，重新声明窗口大小为4K。

5. 发送端发出段12-13，每个段带2K数据，段13同时还包含FIN位。

6. 接收端应答接收到的2K数据（6145-8192），再加上FIN位占一个序号8193，因此应答序号是8194，连接处于半关闭状态，接收端同时声明窗口大小为2K。

7. 接收端的应用程序提走2K数据，接收端重新声明窗口大小为4K。

8. 接收端的应用程序提走剩下的2K数据，接收缓冲区全空，接收端重新声明窗口大小为6K。

9. 接收端的应用程序在提走全部数据后，决定关闭连接，发出段17包含FIN位，发送端应答，连接完全关闭。

上图在接收端用小方块表示1K数据，实心的小方块表示已接收到的数据，虚线框表示接收缓冲区，因此套在虚线框中的空心小方块表示窗口大小，从图中可以看出，随着应用程序提走数据，虚线框是向右滑动的，因此称为滑动窗口。

从这个例子还可以看出，发送端是一K一K地发送数据，而接收端的应用程序可以两K两K地提走数据，当然也有可能一次提走3K或6K数据，或者一次只提走几个字节的数据。也就是说，应用程序所看到的数据是一个整体，或说是一个流（stream），在底层通讯中这些数据可能被拆成很多数据包来发送，但是一个数据包有多少字节对应用程序是不可见的，因此TCP协议是面向流的协议。而UDP是面向消息的协议，每个UDP段都是一条消息，应用程序必须以消息为单位提取数据，不能一次提取任意字节的数据，这一点和TCP是很不同的。

### ★★★TCP状态转换

这个图N多人都知道，它排除和定位网络或系统故障时大有帮助，但是怎样牢牢地将这张图刻在脑中呢？那么你就一定要对这张图的每一个状态，及转换的过程有深刻的认识，不能只停留在一知半解之中。下面对这张图的11种状态详细解析一下，以便加强记忆！不过在这之前，先回顾一下TCP建立连接的三次握手过程，以及 关闭连接的四次握手过程。

![image-20220313165323425](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220313165323425.png)

**CLOSED**：表示初始状态。

**LISTEN**：该状态表示服务器端的某个SOCKET处于监听状态，可以接受连接。

**SYN_SENT**：这个状态与SYN_RCVD遥相呼应，当客户端SOCKET执行CONNECT连接时，它首先发送SYN报文，随即进入到了SYN_SENT状态，并等待服务端的发送三次握手中的第2个报文。SYN_SENT状态表示客户端已发送SYN报文。

**SYN_RCVD:** 该状态表示接收到SYN报文，在正常情况下，这个状态是服务器端的SOCKET在建立TCP连接时的三次握手会话过程中的一个中间状态，很短暂。此种状态时，当收到客户端的ACK报文后，会进入到ESTABLISHED状态。

**ESTABLISHED**：表示连接已经建立。

**FIN_WAIT_1:**  FIN_WAIT_1和FIN_WAIT_2状态的真正含义都是表示等待对方的FIN报文。区别是：

FIN_WAIT_1状态是当socket在ESTABLISHED状态时，想主动关闭连接，向对方发送了FIN报文，此时该socket进入到FIN_WAIT_1状态。

FIN_WAIT_2状态是当对方回应ACK后，该socket进入到FIN_WAIT_2状态，正常情况下，对方应马上回应ACK报文，所以FIN_WAIT_1状态一般较难见到，而FIN_WAIT_2状态可用netstat看到。

**FIN_WAIT_2**：**主动关闭链接的一方，发出FIN收到ACK以后进入该状态。** **称之为半连接或半关闭状态。**该状态下的socket只能接收数据，不能发。

**TIME_WAIT:** 表示收到了对方的FIN报文，并发送出了ACK报文，等2MSL后即可回到CLOSED可用状态。如果FIN_WAIT_1状态下，收到对方同时带 FIN标志和ACK标志的报文时，可以直接进入到TIME_WAIT状态，而无须经过FIN_WAIT_2状态。

**CLOSING:** 这种状态较特殊，属于一种较罕见的状态。正常情况下，当你发送FIN报文后，按理来说是应该先收到（或同时收到）对方的 ACK报文，再收到对方的FIN报文。但是CLOSING状态表示你发送FIN报文后，并没有收到对方的ACK报文，反而却也收到了对方的FIN报文。什么情况下会出现此种情况呢？如果双方几乎在同时close一个SOCKET的话，那么就出现了双方同时发送FIN报文的情况，也即会出现CLOSING状态，表示双方都正在关闭SOCKET连接。

**CLOSE_WAIT:** 此种状态表示在等待关闭。当对方关闭一个SOCKET后发送FIN报文给自己，系统会回应一个ACK报文给对方，此时则进入到CLOSE_WAIT状态。接下来呢，察看是否还有数据发送给对方，如果没有可以 close这个SOCKET，发送FIN报文给对方，即关闭连接。所以在CLOSE_WAIT状态下，需要关闭连接。

**LAST_ACK:** 该状态是被动关闭一方在发送FIN报文后，最后等待对方的ACK报文。当收到ACK报文后，即可以进入到CLOSED可用状态。

![image-20220316193803098](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220316193803098.png)



详解：

#### 主动发起连接

![image-20220316191515798](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220316191515798.png)

主动发起连接请求端： CLOSE -- 发送SYN -- SEND_SYN -- 接收 ACK、SYN -- SEND_SYN -- 发送 ACK -- ESTABLISHED（数据通信态）

#### 主动关闭连接

![image-20220316192250862](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220316192250862.png)

主动关闭连接请求端： ESTABLISHED（数据通信态） -- 发送 FIN -- FIN_WAIT_1 -- 接收ACK -- FIN_WAIT_2（半关闭）-- 接收对端发送 FIN -- FIN_WAIT_2（半关闭）-- 回发ACK -- TIME_WAIT（**只有主动关闭连接方，会经历该状态**）-- 等 2MSL时长 -- CLOSE 

#### 被动接收连接

![image-20220316193327317](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220316193327317.png)

 被动接收连接请求端： CLOSE -- LISTEN -- 接收 SYN -- LISTEN -- 发送 ACK、SYN -- SYN_RCVD -- 接收ACK -- ESTABLISHED（数据通信态）

#### 被动关闭连接

![image-20220316193747959](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220316193747959.png)

被动关闭连接请求端： ESTABLISHED（数据通信态） -- 接收 FIN -- ESTABLISHED（数据通信态） -- 发送ACK -- CLOSE_WAIT (说明对端【主动关闭连接端】处于半关闭状态) -- 发送FIN -- LAST_ACK -- 接收ACK -- CLOSE



**重点：** ESTABLISHED、FIN_WAIT_2 <--> CLOSE_WAIT、TIME_WAIT（2MSL）

  netstat -apn | grep 端口号



### 半关闭

当TCP链接中A发送FIN请求关闭，B端回应ACK后（A端进入FIN_WAIT_2状态），B没有立即发送FIN给A时，A方处在半链接状态，此时A可以接收B发送的数据，但是A已不能再向B发送数据。

通信双方中，只有一端关闭通信。 --- FIN_WAIT_2

```cpp
close(fd);
shutdown(int fd, int how); 
how:  SHUT_RD  关读端
      SHUT_WR  关写端
      SHUT_RDWR 关读写
```

  shutdown在关闭多个文件描述符应用的文件时，采用全关闭方法。close，只关闭一个。

![image-20220317202126290](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220317202126290.png)

### 2MSL

#### 程序设计中的问题

2MSL时长：

  一定出现在【主动关闭连接请求端】。 --- 对应 TIME_WAIT 状态。

  保证，最后一个 ACK 能成功被对端接收。（等待期间，对端没收到我发的ACK，对端会再次发送FIN请求。）

#### 端口复用

在server的TCP连接没有完全断开之前不允许重新监听是不合理的。因为，TCP连接没有完全断开指的是connfd（127.0.0.1:6666）没有完全断开，而我们重新监听的是lis-tenfd（0.0.0.0:6666），虽然是占用同一个端口，但IP地址不同，connfd对应的是与某个客户端通讯的一个具体的IP地址，而listenfd对应的是wildcard address。解决这个问题的方法是使用setsockopt()设置socket描述符的选项SO_REUSEADDR为1，表示允许创建端口号相同但IP地址不同的多个socket描述符。

也就是当server主动断开连接时等2MSL是不合理的（若此时打开新的server就会提示端口被占用），解决这一问题的办法就是端口复用

在server代码的socket()和bind()调用之间插入如下代码：

```cpp
int opt = 1;	// 设置端口复用。
setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (void *）&opt, sizeof(opt));
//成功0，失败-1
```



### TCP异常断开



#### 心跳检测机制



#### 设置TCP属性

## 网络名词术语解析

### 路由(route)

### 路由器工作原理

### 路由表（Routing Table)

### 路由条目

### 缺省路由条目

### 路由节点

### 以太网交换机工作原理

### hub工作原理

### 半双工/全双工

### DNS服务器

### 局域网(LAN)

### 广域网(WAN)

### 端口

### MTU

## 常见网络知识面试题

# 二、Socket编程

## 套接字概念

网络套接字： socket

  一个文件描述符指向一个套接字（该套接字内部由内核借助两个缓冲区实现。）

  在通信过程中， 套接字一定是成对出现的。

![image-20220302204550470](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220302204550470.png)

TCP/IP协议中，“IP地址+TCP或UDP端口号”唯一标识网络通讯中的一个进程。“IP地址+端口号”就对应一个socket。欲建立连接的两个进程各自有一个socket来标识，那么这两个socket组成的socket pair就唯一标识一个连接。因此可以用Socket来描述网络连接的一对一关系。

套接字通信原理如下图所示：

![image-20220302205013108](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220302205013108.png)

**在网络通信中，套接字一定是成对出现的。**一端的发送缓冲区对应对端的接收缓冲区。我们使用同一个文件描述符索发送缓冲区和接收缓冲区。





## 预备知识

### ★网络字节序

网络字节序：

  小端字节序：（**pc本地存储**）  高位存高地址。地位存低地址。  int a = 0x12345678

  大端字节序：（**网络存储**） 高位存低地址。地位存高地址。

| 内存地址 | 小端模式存放内容 | 大端模式存放内容 |
| -------- | ---------------- | ---------------- |
| 0x4000   | 0x78             | 0x12             |
| 0x4001   | 0x56             | 0x34             |
| 0x4002   | 0x34             | 0x56             |
| 0x4003   | 0x12             | 0x78             |

**网络字节序与主机字节序的转换：**

  htonl --> 本地--》网络 （IP）     192.168.1.11 --> string --> atoi --> int --> htonl --> 网络字节序

  htons --> 本地--》网络 (port)

  ntohl --> 网络--》 本地（IP）

  ntohs --> 网络--》 本地（Port）

```cpp
#include <arpa/inet.h>

uint32_t htonl(uint32_t hostlong);//h:host,本地	n：net，网络   l：long—早期的int，4字节32位，对应IP地址
uint16_t htons(uint16_t hostshort);//h:host,本地	n：net，网络   s：short,2字节16位，对应端口号port
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);
```

### ★IP地址转换函数

```cpp
#include <arpa/inet.h>
int inet_pton(int af, const char *src, void *dst);		//本地字节序（string IP） ---> 网络字节序
		af：AF_INET、AF_INET6
		src：传入，IP地址（点分十进制）
		dst：传出，转换后的 网络字节序的 IP地址。 
		返回值：
			成功： 1
			异常： 0， 说明src指向的不是一个有效的ip地址。
			失败：-1，errno
```

```cpp
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);	//网络字节序 ---> 本地字节序（string IP）
		af：AF_INET、AF_INET6
		src: 网络字节序IP地址
		dst：本地字节序（string IP）
		size： dst 的大小。
		返回值： 成功：dst。 	
			失败：NULL
```



### ★sockaddr数据结构

![image-20220302214831613](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220302214831613.png)

![image-20220302214215064](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220302214215064.png)

sockaddr地址结构：  IP + port --> 在网络环境中唯一标识一个进程。

```cpp
//ipv4的sockaddr
struct sockaddr_in addr;
//ipv4的sockaddr的三个成员变量	man 7 ip
addr.sin_family = AF_INET/AF_INET6  //ipv4    
addr.sin_port = htons(9527);  //网络端口号
 int dst;	
 inet_pton(AF_INET, "192.157.22.45", (void *)&dst);
addr.sin_addr.s_addr = dst;		//IP地址

★addr.sin_addr.s_addr = htonl(INADDR_ANY);    取出系统中有效的任意IP地址。二进制类型 

 bind(fd, (struct sockaddr *)&addr, size);
```





## ★★网络套接字函数

### socket模型创建流程图

![image-20220303214858949](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220303214858949.png)

一共需要创建3个套接字，一个服务器一个客户端一个监听。

![image-20220303220156054](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220303220156054.png)



### socket函数

创建一个套接字

```cpp
#include <sys/socket.h>
int socket(int domain, int type, int protocol);		创建一个 套接字
参数：
    domain：AF_INET、AF_INET6、AF_UNIX
    type：SOCK_STREAM、SOCK_DGRAM
    protocol: 0 
返回值：	
成功： 新套接字所对应文件描述符
失败: -1 errno

```

socket()打开一个网络通讯端口，如果成功的话，就像open()一样返回一个文件描述符，应用程序可以像读写文件一样用read/write在网络上收发数据，如果socket()调用出错则返回-1。对于IPv4，domain参数指定为AF_INET。对于TCP协议，type参数指定为SOCK_STREAM，表示面向流的传输协议。如果是UDP协议，则type参数指定为SOCK_DGRAM，表示面向数据报的传输协议。protocol参数的介绍从略，指定为0即可。

### bind函数

给socket绑定一个 地址结构 (IP+port)

```cpp
#include <sys/socket.h>
#include <arpa/inet.h>
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);		给socket绑定一个 地址结构 (IP+port)
参数：		
    	sockfd: socket 函数返回值（文件描述符）
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(8888);
		addr.sin_addr.s_addr = htonl(INADDR_ANY);
		addr: 传入参数(struct sockaddr *)&addr   需要强转！！！
		addrlen: sizeof(addr) 地址结构的大小。
返回值：
			成功：0
			失败：-1 errno

```

### listen函数

设置同时与服务器建立连接的上限数。（同时进行3次握手的客户端数量）

```cpp
int listen(int sockfd, int backlog);		设置同时与服务器建立连接的上限数。（同时进行3次握手的客户端数量）
		sockfd: socket 函数返回值
		backlog：上限数值。最大值 128.
		返回值：
			成功：0
			失败：-1 errno
```

典型的服务器程序可以同时服务于多个客户端，当有客户端发起连接时，服务器调用的accept()返回并接受这个连接，如果有大量的客户端发起连接而服务器来不及处理，尚未accept的客户端就处于连接等待状态，listen()声明sockfd处于监听状态，并且最多允许有backlog个客户端处于连接待状态，如果接收到更多的连接请求就忽略。listen()成功返回0，失败返回-1。

### accept函数

阻塞等待客户端建立连接，成功的话，返回一个与客户端成功连接的socket文件描述符。

```cpp
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);	阻塞等待客户端建立连接，成功的话，返回一个与客户端成功连接的socket文件描述符。
		sockfd: socket()函数返回值,即监听套接字
		addr：传出参数。成功与服务器建立连接的那个客户端的地址结构（IP+port）	注意：返回的是客户端的sockaddr!!
			socklen_t clit_addr_len = sizeof(addr);
		addrlen：传入传出。 &clit_addr_len
			 入：传入的addr的大小。 出：客户端addr实际大小。	入的是addr的原大小，出的是客户端的addr大小
		返回值：
			成功：能与客户端进行数据通信的 socket 套接字对应的文件描述符。
			失败： -1 ， errno

```

三方握手完成后，服务器调用accept()接受连接，如果服务器调用accept()时还没有客户端的连接请求，就阻塞等待直到有客户端连接上来。addr是一个传出参数，accept()返回时传出客户端的地址和端口号。addrlen参数是一个传入传出参数（value-result argument），传入的是调用者提供的缓冲区addr的长度以避免缓冲区溢出问题，传出的是客户端地址结构体的实际长度（有可能没有占满调用者提供的缓冲区）。如果给addr参数传NULL，表示不关心客户端的地址。

我们服务器的程序结构是这样的：

```cpp
while (1) {
	cliaddr_len = sizeof(cliaddr);
	connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
	n = read(connfd, buf, MAXLINE);
	......
	close(connfd);
}
```

整个是一个while死循环，每次循环处理一个客户端连接。由于cliaddr_len是传入传出参数，每次调用accept()之前应该重新赋初值。accept()的参数listenfd是先前的监听文件描述符，而accept()的返回值是另外一个文件描述符connfd，之后与客户端之间就通过这个connfd通讯，最后关闭connfd断开连接，而不关闭listenfd，再次回到循环开头listenfd仍然用作accept的参数。accept()成功返回一个文件描述符，出错返回-1。

### connect函数

```cpp
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);	  使用现有的 socket 与服务器建立连接
		sockfd： socket 函数返回值，即客户端套接字
			struct sockaddr_in srv_addr;			// 服务器地址结构！！！
			srv_addr.sin_family = AF_INET;
			srv_addr.sin_port = 9527 	跟服务器bind时设定的 port 完全一致。
			inet_pton(AF_INET, "服务器的IP地址"，&srv_adrr.sin_addr.s_addr);
		addr：传入参数。服务器的地址结构			
		addrlen：服务器的地址结构的大小
		返回值：
			成功：0
			失败：-1 errno
		如果不使用bind绑定客户端地址结构, 采用"隐式绑定"（系统自动分配）.
```

客户端需要调用connect()连接服务器，connect和bind的参数形式一致，区别在于bind的参数是自己的地址，而connect的参数是对方的地址。connect()成功返回0，出错返回-1。

## C/S模型-TCP

TCP通信流程分析:

###  server

​    \1. socket()  创建socket

​    \2. bind() 绑定服务器地址结构

​    \3. listen()  设置监听上限

​    \4. accept()  阻塞监听客户端连接

​    \5. read(fd)  读socket获取客户端数据

​    \6. 小--大写  toupper()

​    \7. write(fd)

​    \8. close();

###   client

​    \1. socket()  创建socket

​    \2. connect(); 与服务器建立连接

​    \3. write() 写数据到 socket

​    \4. read() 读转换后的数据。

​    \5. 显示读取结果

​    \6. close()

### ★★★server的实现代码

```cpp
#include <stdio.h>  
#include <ctype.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
#define SERV_PORT 9527  
  
  
void sys_err(const char *str)  
{  
    perror(str);  
    exit(1);  
}  
  
int main(int argc, char *argv[])  
{  
    int lfd = 0, cfd = 0;  
    int ret, i;  
    char buf[BUFSIZ], client_IP[1024];  
  
    struct sockaddr_in serv_addr, clit_addr;  // 定义服务器地址结构 和 客户端地址结构  
    socklen_t clit_addr_len;                  // 客户端地址结构大小  
  
    serv_addr.sin_family = AF_INET;             // IPv4  
    serv_addr.sin_port = htons(SERV_PORT);      // 转为网络字节序的 端口号  
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // 获取本机任意有效IP  
  
    lfd = socket(AF_INET, SOCK_STREAM, 0);      //创建一个 socket  
    if (lfd == -1) {  
        sys_err("socket error");  
    }  
  
    bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));//给服务器socket绑定地址结构（IP+port)  
  
    listen(lfd, 128);                   //  设置监听上限  
  
    clit_addr_len = sizeof(clit_addr);  //  获取客户端地址结构大小  
  
    cfd = accept(lfd, (struct sockaddr *)&clit_addr, &clit_addr_len);   // 阻塞等待客户端连接请求  
    if (cfd == -1)  
        sys_err("accept error");  
  
    printf("client ip:%s port:%d\n",   
            inet_ntop(AF_INET, &clit_addr.sin_addr.s_addr, client_IP, sizeof(client_IP)),   
            ntohs(clit_addr.sin_port));         // 根据accept传出参数，获取客户端 ip 和 port  
  
    while (1) {  
        ret = read(cfd, buf, sizeof(buf));      // 读客户端数据  
        write(STDOUT_FILENO, buf, ret);         // 写到屏幕查看  
  
        for (i = 0; i < ret; i++)                // 小写 -- 大写  
            buf[i] = toupper(buf[i]);  
  
        write(cfd, buf, ret);                   // 将大写，写回给客户端。  
    }  
  
    close(lfd);  
    close(cfd);  
  
    return 0;  
}  
```

![image-20220305104703583](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220305104703583.png)

```cpp
cfd = accept(lfd, (struct sockaddr *)&clit_addr, &clit_addr_len);
```

accept函数中的clit_addr传出的就是客户端地址结构，IP+port

于是，在代码中增加此段代码，可获取客户端信息：

```cpp
printf("client ip:%s port:%d\n", 

     inet_ntop(AF_INET,&clit_addr.sin_addr.s_addr, client_IP, sizeof(client_IP)), 

     ntohs(clit_addr.sin_port)); 
```

   



### ★★★client代码实现

```c
#include <stdio.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
#define SERV_PORT 9527  
  
void sys_err(const char *str)  
{  
    perror(str);  
    exit(1);  
}  
  
int main(int argc, char *argv[])  
{  
    int cfd;  
    int conter = 10;  
    char buf[BUFSIZ];  
      
    struct sockaddr_in serv_addr;          //服务器地址结构  
  
    serv_addr.sin_family = AF_INET;  
    serv_addr.sin_port = htons(SERV_PORT);  
    //inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr.s_addr);  
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);  
  
    cfd = socket(AF_INET, SOCK_STREAM, 0);  
    if (cfd == -1)  
        sys_err("socket error");  
  
    int ret = connect(cfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));  
    if (ret != 0)  
        sys_err("connect err");  
  
    while (--conter) {  
        write(cfd, "hello\n", 6);  
        ret = read(cfd, buf, sizeof(buf));  
        write(STDOUT_FILENO, buf, ret);  
        sleep(1);  
    }  
  
    close(cfd);  
  
    return 0;  
}  
```

![image-20220305104831499](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220305104831499.png)

这里遇到过一个问题，如果之前运行server，用Ctrl+z终止进程，ps aux列表里会有服务器进程残留，这个会影响当前服务器。解决方法是kill掉这些服务器进程。不然端口被占用，当前运行的服务器进程接收不到东西，没有回显。

### 基于TCP协议的客户端/服务器程序一般流程

![image-20220308222908822](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220308222908822.png)



## 出错处理函数封装函数

把与socket相关的一些系统函数加上错误处理代码包装成新的函数，做成一个模块wrap.c

原函数和包裹函数的函数名差异只有首字母大写，这是因为man page对字母大小写不敏感，同名的包裹函数一样可以跳转至man page

### wrap.c

```cpp
//只截取一个函数
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
int Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	int n;
	if ((n = bind(fd, sa, salen)) < 0)
		perr_exit("bind error");
	return n;
}
```



### wrap.h

```cpp
#ifndef __WRAP_H_
#define __WRAP_H_
void perr_exit(const char *s);
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
int Bind(int fd, const struct sockaddr *sa, socklen_t salen);
int Connect(int fd, const struct sockaddr *sa, socklen_t salen);
int Listen(int fd, int backlog);
int Socket(int family, int type, int protocol);
ssize_t Read(int fd, void *ptr, size_t nbytes);
ssize_t Write(int fd, const void *ptr, size_t nbytes);
int Close(int fd);
ssize_t Readn(int fd, void *vptr, size_t n);
ssize_t Writen(int fd, const void *vptr, size_t n);
ssize_t my_read(int fd, char *ptr);
ssize_t Readline(int fd, void *vptr, size_t maxlen);
#endif
```



# 三、高并发服务器

![image-20220310211729994](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220310211729994.png)



## 多进程并发服务器

![image-20220310212257696](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220310212257696.png)

使用多进程并发服务器时要考虑以下几点：

1. 父进程最大文件描述个数(父进程中需要close关闭accept返回的新文件描述符)

2. 系统内创建进程个数(与内存大小相关)

3. 进程创建过多是否降低整体服务性能(进程调度)



### server

**具体思路**

  1. Socket();   创建 监听套接字 lfd

  2. Bind() 绑定地址结构 Strcut scokaddr_in addr;

  3. Listen(); 

4. 多进程accept读写

```cpp
    while (1) {
	cfd = Accpet();   		//接收客户端连接请求。
    pid = fork();
    if (pid == 0){     		// 子进程：read(cfd) --- 小-》大 --- write(cfd)
      close(lfd)  			//关闭用于建立连接的套接字 lfd
      read()
     小--大
      write() 
    } 
    else if （pid > 0） { 
      close(cfd);  			//关闭用于与客户端通信的套接字 cfd  
      contiue;
    }
   }
```

5. 子进程：

```c
    close(lfd)
    read()
    小--大
    write()  
```

​    父进程：

```c
    close(cfd);
    注册信号捕捉函数：  SIGCHLD
    在回调函数中， 完成子进程回收
    while （waitpid()）;
```

### client

略

## 多线程并发服务器

在使用线程模型开发服务器时需考虑以下问题：

1. 调整进程内最大文件描述符上限

2. 线程如有共享数据，考虑线程同步(锁)

3. 服务于客户端线程退出时，退出处理。（退出值，分离态pthread_detach）

4. 系统负载，随着链接客户端增加，导致其它线程不能及时得到CPU

### server

**具体思路**

1. Socket();   创建 监听套接字 lfd

  2. Bind()   绑定地址结构 Strcut scokaddr_in addr;

  3. Listen();   

4. Accept等待连接

```cpp
while (1) {    
    cfd = Accept(lfd, );
    pthread_create(&tid, NULL, tfn, (void *)cfd);
    pthread_detach(tid);       // pthead_join(tid, void **); 新线程---专用于回收子线程。
   }
```

5. 子线程：

```cpp
void *tfn(void *arg) 
{
    // close(lfd)    不能关闭。 主线程要使用lfd
    read(cfd)
    小--大
    write(cfd)
    pthread_exit（(void *)10）; 
}
```

具体代码:

```cpp
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

#include "wrap.h"

#define MAXLINE 8192
#define SERV_PORT 8000

struct s_info {                     //定义一个结构体, 将地址结构跟cfd捆绑
    struct sockaddr_in cliaddr;
    int connfd;
};

void *do_work(void *arg)
{
    int n,i;
    struct s_info *ts = (struct s_info*)arg;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];      //#define INET_ADDRSTRLEN 16  可用"[+d"查看

    while (1) {
        n = Read(ts->connfd, buf, MAXLINE);                     //读客户端
        if (n == 0) {
            printf("the client %d closed...\n", ts->connfd);
            break;                                              //跳出循环,关闭cfd
        }
        printf("received from %s at PORT %d\n",
                inet_ntop(AF_INET, &(*ts).cliaddr.sin_addr, str, sizeof(str)),
                ntohs((*ts).cliaddr.sin_port));                 //打印客户端信息(IP/PORT)

        for (i = 0; i < n; i++) 
            buf[i] = toupper(buf[i]);                           //小写-->大写

        Write(STDOUT_FILENO, buf, n);                           //写出至屏幕
        Write(ts->connfd, buf, n);                              //回写给客户端
    }
    Close(ts->connfd);

    return (void *)0;
}

int main(void)
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    pthread_t tid;

    struct s_info ts[256];      //创建结构体数组.
    int i = 0;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);                     //创建一个socket, 得到lfd

    bzero(&servaddr, sizeof(servaddr));                             //地址结构清零
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);                               //指定本地任意IP
    servaddr.sin_port = htons(SERV_PORT);                                       //指定端口号 

    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));             //绑定

    Listen(listenfd, 128);                                                      //设置同一时刻链接服务器上限数

    printf("Accepting client connect ...\n");

    while (1) {
        cliaddr_len = sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);   //阻塞监听客户端链接请求
        ts[i].cliaddr = cliaddr;
        ts[i].connfd = connfd;

        pthread_create(&tid, NULL, do_work, (void*)&ts[i]);
        pthread_detach(tid);                                                    //子线程分离,防止僵线程产生.
        i++;
    }

    return 0;
}
```

### client

```cpp
/* client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, n;

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr.s_addr);
	servaddr.sin_port = htons(SERV_PORT);

	Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	while (fgets(buf, MAXLINE, stdin) != NULL) {
		Write(sockfd, buf, strlen(buf));
		n = Read(sockfd, buf, MAXLINE);
		if (n == 0)
			printf("the other side has been closed.\n");
		else
			Write(STDOUT_FILENO, buf, n);
	}

	Close(sockfd);

	return 0;
}
```

## 多路I/O转接服务器

![image-20220317204226193](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220317204226193.png)

### ★select 

原理：  借助内核， select 来监听， 客户端连接、数据通信事件。

```cpp
#include <sys/select.h>
/* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
		nfds：监听的所有文件描述符中，最大文件描述符+1
	 	readfds： 读事件 文件描述符监听集合。	传入、传出参数
		writefds：写事件 文件描述符监听集合。	传入、传出参数		NULL
		exceptfds：异常事件 文件描述符监听集合	传入、传出参数		NULL
		timeout： 	> 0: 	设置监听超时时长， 微秒。
					NULL:	阻塞监听
					0：	非阻塞监听，轮询
		返回值：
			>· 0:	所有监听集合（3个）中， 满足对应事件的总数。
			0：	没有满足监听条件的文件描述符
			-1： 	errno
```

传入传出的三个参数集合的理解：传入的是对应的事件要监听的socket描述符，传出的是实际发生该事件（满足对应事件）的socket描述符。

![image-20220317210706032](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220317210706032.png)

因为实际向这三个fd_set参数集合中添加文件描述符需要用到位操作，所以还要学习一些位操作函数

```cpp
void FD_ZERO(fd_set *set);	--- 清空一个文件描述符集合。
		fd_set rset;
		FD_ZERO(&rset);

void FD_SET(int fd, fd_set *set);	--- 将待监听的文件描述符，添加到监听集合中
		FD_SET(3, &rset);	FD_SET(5, &rset);	FD_SET(6, &rset);

void FD_CLR(int fd, fd_set *set);	--- 将一个文件描述符从监听集合中 移除。
		FD_CLR（4， &rset）;

int  FD_ISSET(int fd, fd_set *set);	--- 判断一个文件描述符是否在监听集合中。
		返回值： 在：1；不在：0；
		FD_ISSET（4， &rset）;
```

编程中先进行位操作，再调用select()



#### 思路分析

```c
	int maxfd = 0；
	lfd = socket() ;			//创建套接字
	maxfd = lfd；
	bind();						//绑定地址结构
	listen();					//设置监听上限
	fd_set rset， allset;		//创建r监听集合
	FD_ZERO(&allset);			//将r监听集合清空
	FD_SET(lfd, &allset);		//将 lfd 添加至读集合中。
	while（1） {
		rset = allset；			//保存监听集合	
		ret  = select(lfd+1， &rset， NULL， NULL， NULL);		//监听文件描述符集合对应事件。
		if（ret > 0） {							//有监听的描述符满足对应事件
			if (FD_ISSET(lfd, &rset)) {				// 1 在。 0不在。
				cfd = accept（）；				//建立连接，返回用于通信的文件描述符
				maxfd = cfd；
				FD_SET(cfd, &allset);				//添加到监听通信描述符集合中。
			}
			for （i = lfd+1； i <= 最大文件描述符; i++）{
				FD_ISSET(i, &rset)				//有read、write事件
				read（）
				小 -- 大
				write();
			}	
		}
	}

```

![image-20220317215343822](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220317215343822.png)

#### server

```CPP
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <ctype.h>

#include "wrap.h"

#define SERV_PORT 6666

int main(int argc, char *argv[])
{
    int i, j, n, nready;

    int maxfd = 0;

    int listenfd, connfd;

    char buf[BUFSIZ];         /* #define INET_ADDRSTRLEN 16 */

    struct sockaddr_in clie_addr, serv_addr;
    socklen_t clie_addr_len;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);  
    int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family= AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port= htons(SERV_PORT);
    Bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    Listen(listenfd, 128);
    

    fd_set rset, allset;                            /* rset 读事件文件描述符集合 allset用来暂存 */

    maxfd = listenfd;

    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);                                  /* 构造select监控文件描述符集 */

    while (1) {   
        rset = allset;                                          /* 每次循环时都从新设置select监控信号集 */
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);
        if (nready < 0)
            perr_exit("select error");

        if (FD_ISSET(listenfd, &rset)) {                        /* 说明有新的客户端链接请求 */

            clie_addr_len = sizeof(clie_addr);
            connfd = Accept(listenfd, (struct sockaddr *)&clie_addr, &clie_addr_len);       /* Accept 不会阻塞 */

            FD_SET(connfd, &allset);                            /* 向监控文件描述符集合allset添加新的文件描述符connfd */

            if (maxfd < connfd)
                maxfd = connfd;

            if (0 == --nready)                                  /* 只有listenfd有事件, 后续的 for 不需执行 */
                continue;
        } 

        for (i = listenfd+1; i <= maxfd; i++) {                 /* 检测哪个clients 有数据就绪 */

            if (FD_ISSET(i, &rset)) {

                if ((n = Read(i, buf, sizeof(buf))) == 0) {    /* 当client关闭链接时,服务器端也关闭对应链接 */
                    Close(i);
                    FD_CLR(i, &allset);                        /* 解除select对此文件描述符的监控 */

                } else if (n > 0) {

                    for (j = 0; j < n; j++)
                        buf[j] = toupper(buf[j]);
                    Write(i, buf, n);
                }
            }
        }
    }

    Close(listenfd);

    return 0;
}
```



#### client

```CPP
/* client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 6666

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr.s_addr);
    servaddr.sin_port = htons(SERV_PORT);

    Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("------------connect ok----------------\n");

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        Write(sockfd, buf, strlen(buf));
        n = Read(sockfd, buf, MAXLINE);
        if (n == 0) {
            printf("the other side has been closed.\n");
            break;
        }
        else
            Write(STDOUT_FILENO, buf, n);
    }
    Close(sockfd);

    return 0;
}
```



#### select优缺点

  缺点： 监听上限受文件描述符限制。 最大 1024.

​    		  检测满足条件的fd， 自己添加业务逻辑提高小。 提高了编码难度。

  优点： **跨平台**。win、linux、macOS、Unix、类Unix、mips   就是因为可以跨平台select才一直没有被淘汰

select代码里有个可以优化的地方，用数组存下文件描述符，这样就不需要每次扫描一大堆无关文件描述符了

#### pselect

此模型应用较少

```cpp
#include <sys/select.h>
int pselect(int nfds, fd_set *readfds, fd_set *writefds,
			fd_set *exceptfds, const struct timespec *timeout,
			const sigset_t *sigmask);
	struct timespec {
		long tv_sec; /* seconds */
		long tv_nsec; /* nanoseconds */
	};
	用sigmask替代当前进程的阻塞信号集，调用返回后还原原有阻塞信号集
```



### poll

poll是对select的改进，但是它是个半成品，相对select提升不大。最终版本是epoll，所以poll了解一下就完事儿，**重点掌握epoll。**

优点：

​    自带数组结构。 可以将 监听事件集合 和 返回事件集合 分离。

​    拓展 监听上限。 超出 1024限制。

缺点：

​    不能跨平台。 Linux

​    无法直接定位满足监听事件的文件描述符， 编码难度较大。

poll：

```cpp
#include <poll.h>
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
	struct pollfd {
		int fd; /* 文件描述符 */
		short events; /* 监控的事件 */
		short revents; /* 监控事件中满足条件返回的事件，传入时， 给0。如果满足对应事件的话， 返回 非0 --> POLLIN、POLLOUT、POLLERR */
	};
	fds：监听的文件描述符【数组】
	事件：
   ★POLLIN			普通或带外优先数据可读,即POLLRDNORM | POLLRDBAND
	POLLRDNORM		数据可读
	POLLRDBAND		优先级带数据可读
	POLLPRI 		高优先级可读数据
   ★POLLOUT		普通或带外数据可写
	POLLWRNORM		数据可写
	POLLWRBAND		优先级带数据可写
   ★POLLERR 		发生错误
	POLLHUP 		发生挂起
	POLLNVAL 		描述字不是一个打开的文件

	nfds 			监控数组中有多少文件描述符需要被监控
	timeout 		毫秒级等待
		-1：阻塞等，#define INFTIM -1 				Linux中没有定义此宏
		0：立即返回，不阻塞进程
		>0：等待指定毫秒数，如当前系统时间精度不够毫秒，向上取值
    返回值：返回满足对应监听事件的文件描述符 总个数。
```

  优点：

​    自带数组结构。 可以将 监听事件集合 和 返回事件集合 分离。

​    拓展 监听上限。 超出 1024限制。

  缺点：

​    不能跨平台。 Linux

​    无法直接定位满足监听事件的文件描述符， 编码难度较大。

#### server

```cpp
/* server.c */  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <poll.h>  
#include <errno.h>  
#include "wrap.h"  
  
#define MAXLINE 80  
#define SERV_PORT 6666  
#define OPEN_MAX 1024  
  
int main(int argc, char *argv[])  
{  
    int i, j, maxi, listenfd, connfd, sockfd;  
    int nready;  
    ssize_t n;  
    char buf[MAXLINE], str[INET_ADDRSTRLEN];  
    socklen_t clilen;  
    struct pollfd client[OPEN_MAX];  
    struct sockaddr_in cliaddr, servaddr;  
  
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);  
  
    bzero(&servaddr, sizeof(servaddr));  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  
    servaddr.sin_port = htons(SERV_PORT);  
  
    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));  
  
    Listen(listenfd, 20);  
  
    client[0].fd = listenfd;  
    client[0].events = POLLRDNORM;                  /* listenfd监听普通读事件 */  
  
    for (i = 1; i < OPEN_MAX; i++)  
        client[i].fd = -1;                          /* 用-1初始化client[]里剩下元素 */  
    maxi = 0;                                       /* client[]数组有效元素中最大元素下标 */  
  
    for ( ; ; ) {  
        nready = poll(client, maxi+1, -1);          /* 阻塞 */  
        if (client[0].revents & POLLRDNORM) {       /* 有客户端链接请求 */  
            clilen = sizeof(cliaddr);  
            connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);  
            printf("received from %s at PORT %d\n",  
                    inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),  
                    ntohs(cliaddr.sin_port));  
            for (i = 1; i < OPEN_MAX; i++) {  
                if (client[i].fd < 0) {  
                    client[i].fd = connfd;  /* 找到client[]中空闲的位置，存放accept返回的connfd */  
                    break;  
                }  
            }  
  
            if (i == OPEN_MAX)  
                perr_exit("too many clients");  
  
            client[i].events = POLLRDNORM;      /* 设置刚刚返回的connfd，监控读事件 */  
            if (i > maxi)  
                maxi = i;                       /* 更新client[]中最大元素下标 */  
            if (--nready <= 0)  
                continue;                       /* 没有更多就绪事件时,继续回到poll阻塞 */  
        }  
        for (i = 1; i <= maxi; i++) {            /* 检测client[] */  
            if ((sockfd = client[i].fd) < 0)  
                continue;  
            if (client[i].revents & (POLLRDNORM | POLLERR)) {  
                if ((n = Read(sockfd, buf, MAXLINE)) < 0) {  
                    if (errno == ECONNRESET) { /* 当收到 RST标志时 */  
                        /* connection reset by client */  
                        printf("client[%d] aborted connection\n", i);  
                        Close(sockfd);  
                        client[i].fd = -1;  
                    } else {  
                        perr_exit("read error");  
                    }  
                } else if (n == 0) {  
                    /* connection closed by client */  
                    printf("client[%d] closed connection\n", i);  
                    Close(sockfd);  
                    client[i].fd = -1;  
                } else {  
                    for (j = 0; j < n; j++)  
                        buf[j] = toupper(buf[j]);  
                        Writen(sockfd, buf, n);  
                }  
                if (--nready <= 0)  
                    break;              /* no more readable descriptors */  
            }  
        }  
    }  
    return 0;  
}  
```



#### client

```cpp
/* client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 6666

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, n;

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	while (fgets(buf, MAXLINE, stdin) != NULL) {
		Write(sockfd, buf, strlen(buf));
		n = Read(sockfd, buf, MAXLINE);
		if (n == 0)
			printf("the other side has been closed.\n");
		else
			Write(STDOUT_FILENO, buf, n);
	}
	Close(sockfd);
	return 0;
}
```

#### ppoll

NU定义了ppoll（非POSIX标准），可以支持设置信号屏蔽字，此模型应用较少

```cpp
#define _GNU_SOURCE /* See feature_test_macros(7) */
#include <poll.h>
int ppoll(struct pollfd *fds, nfds_t nfds,
		   const struct timespec *timeout_ts, const sigset_t *sigmask);
```



### ★★epoll

epoll是Linux下多路复用IO接口**select/poll的增强版本**，它能显著提高程序在**大量并发连接中只有少量活跃的情况下**的系统CPU利用率，因为它会**复用文件描述符**集合来传递结果而不用迫使开发者每次等待事件之前都必须重新准备要被侦听的文件描述符集合，另一点原因就是获取事件的时候，它无须遍历整个被侦听的描述符集，只要遍历那些被内核IO事件异步唤醒而加入Ready队列的描述符集合就行了。

目前epoll是linux大规模并发网络程序中的热门首选模型。

epoll除了提供select/poll那种IO事件的**电平触发（Level Triggered）**外，还提供了**边沿触发（Edge Triggered）**，这就使得用户空间程序有可能缓存IO状态，减少epoll_wait/epoll_pwait的调用，提高应用程序效率。

可以使用cat命令查看一个进程可以**打开的socket描述符上限**。

```shell
cat /proc/sys/fs/file-max	//当前计算机所能打开的文件描述符的个数，与硬件相关
ulimit -a  	//当前用户进程下，open files:默认打开的文教描述符个数
ulimit -n 1024 	//需要注销用户才生效
```

如有需要，可以通过修改配置文件的方式修改该上限值。

```shell
sudo vi /etc/security/limits.conf

  在文件尾部写入以下配置,soft软限制，hard硬限制。如下图所示。

* soft nofile 65536
* hard nofile 100000
```

#### 基础API

![image-20220321214325076](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220321214325076.png)

1.创建一个epoll句柄，参数size用来告诉内核监听的文件描述符的个数，跟内存大小有关。

```cpp
#include <sys/epoll.h>
int epoll_create(int size)   //创建监听红黑树。size：创建的红黑树的监听节点数目（仅供内核参考，实际可能比这大——连接的客户端数目比设置的size大时会自动扩容）
//成功返回新创建的红黑树的根节点 fd，失败-1 errno
```

2.控制某个epoll监控的文件描述符上的事件：注册、修改、删除。

```cpp
#include <sys/epoll.h>
	int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)	//操作监听红黑树节点
		epfd：	为epoll_creat的句柄（返回值）
		op：		表示动作，用3个宏来表示：
			EPOLL_CTL_ADD (注册新的fd到监听红黑树)，
			EPOLL_CTL_MOD (修改已经注册的fd在监听红黑树上的监听事件)，
			EPOLL_CTL_DEL (从监听红黑树上删除一个fd，即取消监听)；
        fd:	待监听的fd
            
		event：监听事件	本质 struct epoll_event //结构体 地址 
            events: EPOLLIN/EPOLLOUT/EPOLLERR/EPOLLET
            data: 联合体
		struct epoll_event {
			__uint32_t events; /* Epoll events */
			epoll_data_t data; /* User data variable */
		}; 
		typedef union epoll_data {
			void *ptr;		//epoll反应堆模型（回调函数）:epoll ET模式 + 非阻塞、轮询 + void *ptr
			int fd;			//对应监听事件的fd
			uint32_t u32;	// 不用
			uint64_t u64;	// 不用
		} epoll_data_t;		

		★EPOLLIN ：	表示对应的文件描述符可以读（包括对端SOCKET正常关闭）
		★EPOLLOUT：	表示对应的文件描述符可以写
		EPOLLPRI：	表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）
		★EPOLLERR：	表示对应的文件描述符发生错误
		EPOLLHUP：	表示对应的文件描述符被挂断；
		★EPOLLET： 	将EPOLL设为边缘触发(Edge Triggered)模式，这是相对于水平触发(Level Triggered)而言的
		EPOLLONESHOT：只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里
            //返回值：成功0，失败-1 errno
```

3.等待所监控文件描述符上有事件的产生，类似于select()调用。

```cpp
struct epoll_event events[1024];
#include <sys/epoll.h>
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout)//阻塞监听。
    	epfd：		//为epoll_creat的句柄（返回值）
		events：		//用来存内核得到事件的集合，【数组】，传出参数，传出满足监听条件的fd结构体
		maxevents：	//数组 元素总个数 1024。告之内核这个events有多大，这个maxevents的值不能大于创建epoll_create()时的size，
		timeout：	//超时时间
			-1：	//阻塞
			0：	//立即返回，非阻塞
			>0：	//指定毫秒
		返回值：	
    		>0: 成功返回有多少文件描述符就绪（满足监听的总个数），可以用作循环上限。
            0: 时间到时返回0
            -1: 出错返回-1
```

#### server

```cpp
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <errno.h>
#include <ctype.h>

#include "wrap.h"

#define MAXLINE 8192
#define SERV_PORT 8000

#define OPEN_MAX 5000

int main(int argc, char *argv[])
{
    int i, listenfd, connfd, sockfd;
    int  n, num = 0;
    ssize_t nready, efd, res;
    char buf[MAXLINE], str[INET_ADDRSTRLEN];
    socklen_t clilen;

    struct sockaddr_in cliaddr, servaddr;


    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));      //端口复用，2MSL
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    Listen(listenfd, 20);

    efd = epoll_create(OPEN_MAX);               //创建epoll模型, efd指向红黑树根节点
    if (efd == -1)
        perr_exit("epoll_create error");

    struct epoll_event tep, ep[OPEN_MAX];       //tep: epoll_ctl参数  ep[] : epoll_wait参数

    tep.events = EPOLLIN; 
    tep.data.fd = listenfd;           //指定lfd的监听事件为"读"

    res = epoll_ctl(efd, EPOLL_CTL_ADD, listenfd, &tep);    //将lfd及对应的结构体设置到树上,efd可找到该树
    if (res == -1)
        perr_exit("epoll_ctl error");

    for ( ; ; ) {
        /*epoll为server阻塞监听事件, ep为struct epoll_event类型数组, OPEN_MAX为数组容量, -1表永久阻塞*/
        nready = epoll_wait(efd, ep, OPEN_MAX, -1); 
        if (nready == -1)
            perr_exit("epoll_wait error");

        for (i = 0; i < nready; i++) {
            if (!(ep[i].events & EPOLLIN))      //如果不是"读"事件, 继续循环
                continue;

            if (ep[i].data.fd == listenfd) {    //判断满足事件的fd是不是lfd            
                clilen = sizeof(cliaddr);
                connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);    //接受链接

                printf("received from %s at PORT %d\n", 
                        inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), 
                        ntohs(cliaddr.sin_port));
                printf("cfd %d---client %d\n", connfd, ++num);

                tep.events = EPOLLIN; tep.data.fd = connfd;
                res = epoll_ctl(efd, EPOLL_CTL_ADD, connfd, &tep);      //加入红黑树
                if (res == -1)
                    perr_exit("epoll_ctl error");

            } else {                                                    //不是lfd, 
                sockfd = ep[i].data.fd;
                n = Read(sockfd, buf, MAXLINE);

                if (n == 0) {                                           //读到0,说明客户端关闭链接
                    res = epoll_ctl(efd, EPOLL_CTL_DEL, sockfd, NULL);  //将该文件描述符从红黑树摘除
                    if (res == -1)
                        perr_exit("epoll_ctl error");
                    Close(sockfd);                                      //关闭与该客户端的链接
                    printf("client[%d] closed connection\n", sockfd);

                } else if (n < 0) {                                     //出错
                    perror("read n < 0 error: ");
                    res = epoll_ctl(efd, EPOLL_CTL_DEL, sockfd, NULL);  //摘除节点
                    Close(sockfd);

                } else {                                                //实际读到了字节数
                    for (i = 0; i < n; i++)
                        buf[i] = toupper(buf[i]);                       //转大写, 

                    Write(STDOUT_FILENO, buf, n);
                    Writen(sockfd, buf, n);
                }
            }
        }
    }
    Close(listenfd);
    Close(efd);

    return 0;
}
```

#### client

```cpp
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "wrap.h"

#define MAXLINE 8192
#define SERV_PORT 8000

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);

    Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        Write(sockfd, buf, strlen(buf));
        n = Read(sockfd, buf, MAXLINE);
        if (n == 0) {
            printf("the other side has been closed.\n");
            break;
        }
        else
            Write(STDOUT_FILENO, buf, n);
    }
    Close(sockfd);

    return 0;
}
```

## epoll进阶

### 事件模型

#### ET模式

Edge Triggered (ET) 边缘触发只有数据到来才触发，不管缓存区中是否还有数据。只有子进程（客户端）发数据才会触发，缓冲区剩余未读尽的数据不会导致 epoll_wait 返回。 新的事件满足，才会触发。

```cpp
struct epoll_event event;
event.events = EPOLLIN | EPOLLET;
```

#### LT模式

水平触发模式，只要缓冲区有数据就触发。

Level Triggered (LT) 水平触发只要有数据都会触发。默认模式。缓冲区剩余未读尽的数据会导致 epoll_wait 返回。

#### 比较

LT是**缺省**（默认）的工作方式，并同时支持block和no-block socket。在这种做法中，内核告诉你一个文件描述符是否就绪了，然后你可以对这个就绪的fd进行IO操作。如果你不做任何操作，内核还是会继续通知你的，所以这种模式编程出错可能性要小一些。**传统的select/poll都是这种模式的代表。**

**ET是高速工作方式，只支持no-block socket。**在这种模式下，当描述符从未就绪变为就绪时，内核通过epoll告诉你。然后他会假设你知道文件描述符已经就绪，并且不会再为那个文件描述符发送更多的就绪通知。请注意，如果一直不对这个fd作IO操作（从而导致它再次变成未就绪），内核不会发送更多的通知。

### 实例一

基于管道epoll ET触发模式

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <errno.h>
#include <unistd.h>

#define MAXLINE 10

int main(int argc, char *argv[])
{
	int efd, i;
	int pfd[2];
	pid_t pid;
	char buf[MAXLINE], ch = 'a';

	pipe(pfd);
	pid = fork();
	if (pid == 0) {
		close(pfd[0]);
		while (1) {
			for (i = 0; i < MAXLINE/2; i++)
				buf[i] = ch;
			buf[i-1] = '\n';
			ch++;

			for (; i < MAXLINE; i++)
				buf[i] = ch;
			buf[i-1] = '\n';
			ch++;

			write(pfd[1], buf, sizeof(buf));
			sleep(2);
		}
		close(pfd[1]);
	} else if (pid > 0) {
		struct epoll_event event;
		struct epoll_event resevent[10];
		int res, len;
		close(pfd[1]);

		efd = epoll_create(10);
		/* event.events = EPOLLIN; */
		event.events = EPOLLIN | EPOLLET;		/* ET 边沿触发 ，默认是水平触发 */
		event.data.fd = pfd[0];
	epoll_ctl(efd, EPOLL_CTL_ADD, pfd[0], &event);

		while (1) {
			res = epoll_wait(efd, resevent, 10, -1);
			printf("res %d\n", res);
			if (resevent[0].data.fd == pfd[0]) {
				len = read(pfd[0], buf, MAXLINE/2);
				write(STDOUT_FILENO, buf, len);
			}
		}
		close(pfd[0]);
		close(efd);
	} else {
		perror("fork");
		exit(-1);
	}
	return 0;
}

```



### 实例二

基于网络C/S模型的epoll ET触发模式

#### server

```cpp
/* server.c */
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <unistd.h>

#define MAXLINE 10
#define SERV_PORT 8080

int main(void)
{
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int listenfd, connfd;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int i, efd;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	listen(listenfd, 20);

	struct epoll_event event;
	struct epoll_event resevent[10];
	int res, len;
	efd = epoll_create(10);
	event.events = EPOLLIN | EPOLLET;		/* ET 边沿触发 ，默认是水平触发 */

	printf("Accepting connections ...\n");
	cliaddr_len = sizeof(cliaddr);
	connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
	printf("received from %s at PORT %d\n",
			inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
			ntohs(cliaddr.sin_port));

	event.data.fd = connfd;
	epoll_ctl(efd, EPOLL_CTL_ADD, connfd, &event);

	while (1) {
		res = epoll_wait(efd, resevent, 10, -1);
		printf("res %d\n", res);
		if (resevent[0].data.fd == connfd) {
			len = read(connfd, buf, MAXLINE/2);
			write(STDOUT_FILENO, buf, len);
		}
	}
	return 0;
}
```



#### client

```c
/* client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define MAXLINE 10
#define SERV_PORT 8080

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, i;
	char ch = 'a';

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	while (1) {
		for (i = 0; i < MAXLINE/2; i++)
			buf[i] = ch;
		buf[i-1] = '\n';
		ch++;

		for (; i < MAXLINE; i++)
			buf[i] = ch;
		buf[i-1] = '\n';
		ch++;

		write(sockfd, buf, sizeof(buf));
		sleep(10);
	}
	Close(sockfd);
	return 0;
}

```



### ★★★实例三

基于网络C/S非阻塞模型的epoll ET触发模式

#### server

```cpp
/* server.c */
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXLINE 10
#define SERV_PORT 8080

int main(void)
{
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int listenfd, connfd;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int i, efd, flag;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	listen(listenfd, 20);

	struct epoll_event event;
	struct epoll_event resevent[10];
	int res, len;
	efd = epoll_create(10);
	/* event.events = EPOLLIN; */
	event.events = EPOLLIN | EPOLLET;		/* ET 边沿触发 ，默认是水平触发 */

	printf("Accepting connections ...\n");
	cliaddr_len = sizeof(cliaddr);
	connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
	printf("received from %s at PORT %d\n",
			inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
			ntohs(cliaddr.sin_port));

	flag = fcntl(connfd, F_GETFL);
	flag |= O_NONBLOCK;
	fcntl(connfd, F_SETFL, flag);
	event.data.fd = connfd;
	epoll_ctl(efd, EPOLL_CTL_ADD, connfd, &event);

	while (1) {
		printf("epoll_wait begin\n");
		res = epoll_wait(efd, resevent, 10, -1);
		printf("epoll_wait end res %d\n", res);

		if (resevent[0].data.fd == connfd) {
			while ((len = read(connfd, buf, MAXLINE/2)) > 0)
				write(STDOUT_FILENO, buf, len);
		}
	}
	return 0;
}
```

#### client

```c
/* client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define MAXLINE 10
#define SERV_PORT 8080

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, i;
	char ch = 'a';

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	while (1) {
		for (i = 0; i < MAXLINE/2; i++)
			buf[i] = ch;
		buf[i-1] = '\n';
		ch++;

		for (; i < MAXLINE; i++)
			buf[i] = ch;
		buf[i-1] = '\n';
		ch++;

		write(sockfd, buf, sizeof(buf));
		sleep(10);
	}
	Close(sockfd);
	return 0;
}
```



### 结论

epoll 的 ET模式， 高效模式，但是只支持 非阻塞模式。 --- 忙轮询。

```cpp
struct epoll_event event;
event.events = EPOLLIN | EPOLLET;
epoll_ctl(epfd, EPOLL_CTL_ADD, cfd， &event);	
int flg = fcntl(cfd, F_GETFL);	
flg |= O_NONBLOCK;
fcntl(cfd, F_SETFL, flg);
```

### epoll优缺点

优点：

​	高效。突破1024文件描述符。

缺点：
	不能跨平台。 Linux。



### ★★epoll反应堆模型

epoll ET模式 + 非阻塞、轮询 + void *ptr。

  原来： socket、bind、listen -- epoll_create 创建监听 红黑树 -- 返回 epfd -- epoll_ctl() 向树上添加一个监听fd -- while（1）-- -- epoll_wait 监听 -- 对应监听fd有事件产生 -- 返回 监听满足数组。 -- 判断返回数组元素 -- lfd满足 -- Accept -- cfd 满足 -- read() --- 小->大 -- write回去。

反应堆：不但要监听 cfd 的读事件、还要监听cfd的写事件。

​    socket、bind、listen -- epoll_create 创建监听 红黑树 -- 返回 epfd -- epoll_ctl() 向树上添加一个监听fd -- while（1）-- -- epoll_wait 监听 -- 对应监听fd有事件产生 -- 返回 监听满足数组。 -- 判断返回数组元素 -- lfd满足 -- Accept -- cfd 满足 -- read() --- 小->大 -- cfd从监听红黑树上摘下 -- EPOLLOUT -- 回调函数 -- epoll_ctl() -- EPOLL_CTL_ADD 重新放到红黑上监听写事件-- 等待 epoll_wait 返回 -- 说明 cfd 可写 -- write回去 -- cfd从监听红黑树上摘下 -- EPOLLIN -- epoll_ctl() -- EPOLL_CTL_ADD 重新放到红黑上监听读事件 -- epoll_wait 监听

**反应堆的理解：加入IO转接之后，有了事件，server才去处理，这里反应堆也是这样，由于网络环境复杂，服务器处理数据之后，可能并不能直接写回去，比如遇到网络繁忙或者对方缓冲区已经满了这种情况，就不能直接写回给客户端。反应堆就是在处理数据之后，监听写事件，能写回客户端了，才去做写回操作。写回之后，再改为监听读事件。如此循环。**

	eventset函数：
		设置回调函数。lfd --》 acceptconn()
					cfd --> recvdata();
					cfd --> senddata();
	eventadd函数：
		将一个fd， 添加到 监听红黑树。  设置监听 read事件，还是监听写事件。


	网络编程中：  read --- recv()
				write --- send();

**看懂源码剖析**





## ★★★线程池并发服务器

1. 预先创建阻塞于accept多线程，使用互斥锁上锁保护accept
2. 预先创建多线程，由主线程调用accept

![image-20220401104711583](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220401104711583.png)

```cpp
//描述线程池相关信息
struct threadpool_t {

    pthread_mutex_t lock;               /* 用于锁住本结构体 */    
    pthread_mutex_t thread_counter;     /* 记录忙状态线程个数的锁 -- busy_thr_num */

    pthread_cond_t queue_not_full;      /* 当任务队列满时，添加任务的线程阻塞，等待此条件变量 （服务器阻塞在此条件变量上）*/
    pthread_cond_t queue_not_empty;     /* 任务队列里不为空时，通知等待任务的线程 （上图的任务队列，线程阻塞在此条件变量上）*/

    pthread_t *threads;                 /* 存放线程池中每个线程的tid。数组 */
    pthread_t adjust_tid;               /* 存管理线程tid */
    threadpool_task_t *task_queue;      /* 任务队列(数组首地址)，结构体数组 */

    int min_thr_num;                    /* 线程池最小线程数 */
    int max_thr_num;                    /* 线程池最大线程数 */
    int live_thr_num;                   /* 当前存活线程个数 */
    int busy_thr_num;                   /* 忙状态线程个数 */
    int wait_exit_thr_num;              /* 要销毁的线程个数 */

    int queue_front;                    /* task_queue队头下标 */
    int queue_rear;                     /* task_queue队尾下标 */
    int queue_size;                     /* task_queue队中实际任务数 */
    int queue_max_size;                 /* task_queue队列可容纳任务数上限 （容量）*/

    int shutdown;                       /* 标志位，线程池使用状态，true或false */
};

typedef struct {

    void *(*function)(void *);          /* 函数指针，回调函数 */
    void *arg;                          /* 上面函数的参数 */

} threadpool_task_t;                    /* 各子线程任务结构体 */
```

线程池模块分析：

1. main();  

​    创建线程池。

​    向线程池中添加任务。 借助回调处理任务。

​    销毁线程池。

2. pthreadpool_create();

  创建线程池结构体 指针。

  初始化线程池结构体 {  N 个成员变量 }

  创建 N 个任务线程。

  创建 1 个管理者线程。

  失败时，销毁开辟的所有空间。（释放）

3. threadpool_thread（）

​	进入子线程回调函数。

​	接收参数 void *arg  --》 pool 结构体

​	加锁 --》lock --》 整个结构体锁

​	判断条件变量 --》 wait  -------------------170

4. adjust_thread（）

​	循环 10 s 执行一次。

​	进入管理者线程回调函数

​	接收参数 void *arg  --》 pool 结构体

​	加锁 --》lock --》 整个结构体锁

​	获取管理线程池要用的到 变量。	task_num, live_num, busy_num

​	根据既定算法，使用上述3变量，判断是否应该 创建、销毁线程池中 指定步长的线程。

5. threadpool_add ()

总功能：

​	模拟产生任务。   num[20]

​	设置回调函数， 处理任务。  sleep（1） 代表处理完成。

内部实现：

​	加锁

​	初始化 任务队列结构体成员。   回调函数 function， arg

​	利用环形队列机制，实现添加任务。 借助队尾指针挪移 % 实现。

​	唤醒阻塞在 条件变量上的线程。

​	解锁

6. 从 3. 中的wait之后继续执行，处理任务。

​	加锁

​	获取 任务处理回调函数，及参数

​	利用环形队列机制，实现处理任务。 借助队头指针挪移 % 实现。

​	唤醒阻塞在 条件变量 上的 server。

​	解锁

​	加锁 

​	改忙线程数++

​	解锁

​	执行处理任务的线程

​	加锁 

​	改忙线程数——

​	解锁

7. 创建 销毁线程

​	管理者线程根据 task_num, live_num, busy_num  

​	根据既定算法，使用上述3变量，判断是否应该 创建、销毁线程池中 指定步长的线程。

​	如果满足 创建条件

​	pthread_create();   回调 任务线程函数。		live_num++

​	如果满足 销毁条件

​	wait_exit_thr_num = 10;  

​	signal 给 阻塞在条件变量上的线程 发送 假条件满足信号    

​	跳转至  --170 wait阻塞线程会被 假信号 唤醒。判断： wait_exit_thr_num  > 0 pthread_exit();     

## UDP服务器

传输层主要应用的协议模型有两种，一种是TCP协议，另外一种则是UDP协议。TCP协议在网络通信中占主导地位，绝大多数的网络通信借助TCP协议完成数据传输。但UDP也是网络通信中不可或缺的重要通信手段。

相较于TCP而言，UDP通信的形式更像是发短信。不需要在数据传输之前建立、维护连接。只专心获取数据就好。省去了三次握手的过程，通信速度可以大大提高，但与之伴随的通信的稳定性和正确率便得不到保证。因此，我们称UDP为“无连接的不可靠报文传递”。

么与我们熟知的TCP相比，UDP有哪些优点和不足呢？由于无需创建连接，所以UDP开销较小，数据传输速度快，实时性较强。多用于对实时性要求较高的通信场合，如视频会议、电话会议等。但随之也伴随着数据传输不可靠，传输数据的正确率、传输顺序和流量都得不到控制和保证。所以，通常情况下，使用UDP协议进行数据传输，为保证数据的正确性，我们需要在应用层添加辅助校验协议来弥补UDP的不足，以达到数据可靠传输的目的。

与TCP类似的，UDP也有可能出现缓冲区被填满后，再接收数据时丢包的现象。由于它没有TCP滑动窗口的机制，通常采用如下两种方法解决：

1) 服务器应用层设计流量控制，控制发送数据速度。

2) 借助setsockopt函数改变接收缓冲区大小。如：

```c
#include <sys/socket.h>
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
	int n = 220x1024
	setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &n, sizeof(n));
```

TCP通信和UDP通信各自的优缺点：

  **TCP： 面向连接的，可靠数据包传输。**对于不稳定的网络层，采取完全弥补的通信方式。 丢包重传。

​    优点：

​      稳定。   

​       数据流量稳定、速度稳定、顺序

​    缺点：

​      传输速度慢。效率低。开销大。

​    使用场景：数据的完整型要求较高，不追求效率。

​     				  大数据传输、文件传输。



  **UDP： 无连接的，不可靠的数据报传递。**对于不稳定的网络层，采取完全不弥补的通信方式。 默认还原网络状况

​    优点：

​      传输速度块。相率高。开销小。

​    缺点：

​      不稳定。

​       数据流量。速度。顺序。

​    使用场景：对时效性要求较高场合。稳定性其次。

​      				 游戏、视频会议、视频电话。    腾讯、华为、阿里 --- 应用层数据校验协议，弥补udp的不足。

## C/S模型-UDP

![image-20220402152921917](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220402152921917.png)

由于UDP不需要维护连接，程序逻辑简单了很多，但是UDP协议是不可靠的，保证通讯可靠性的机制需要在应用层实现。

编译运行server，在两个终端里各开一个client与server交互，看看server是否具有并发服务的能力。用Ctrl+C关闭server，然后再运行server，看此时client还能否和server联系上。和前面TCP程序的运行结果相比较，体会无连接的含义。

### 模型

```c
recv()/send() 只能用于 TCP 通信。 替代 read、write
accpet(); ---- Connect(); ---被舍弃

server：
lfd = socket(AF_INET, STREAM, 0);	SOCK_DGRAM --- 报式协议。
bind();
listen();  --- 可有可无
while（1）{
    read(cfd, buf, sizeof) --- 被替换 --- recvfrom（） --- 涵盖accept传出地址结构。
    小-- 大
    write();--- 被替换 --- sendto（）---- connect
}
close();

client：
connfd = socket(AF_INET, SOCK_DGRAM, 0);
sendto（‘服务器的地址结构’， 地址结构大小）
recvfrom（）
写到屏幕
close();
```

### 主要函数

```c
#include<socket.h>
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr *src_addr, socklen_t *addrlen);
					sockfd： 套接字
					buf：缓冲区地址
					len：缓冲区大小
					flags： 0
					src_addr：（struct sockaddr *）&addr 传出。 对端地址结构
					addrlen：传入传出。
				返回值： 成功接收数据字节数。 失败：-1 errn。 0： 对端关闭。

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen);
					sockfd： 套接字
					buf：存储数据的缓冲区
					len：数据长度
					flags： 0
					src_addr：（struct sockaddr *）&addr 传入。 目标地址结构
					addrlen：地址结构长度。
				返回值：成功写出数据字节数。 失败 -1， errno		
```

### server

```c
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define SERV_PORT 8000

int main(void)
{
    struct sockaddr_in serv_addr, clie_addr;
    socklen_t clie_addr_len;
    int sockfd;
    char buf[BUFSIZ];
    char str[INET_ADDRSTRLEN];
    int i, n;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SERV_PORT);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Accepting connections ...\n");
    while (1) {
        clie_addr_len = sizeof(clie_addr);
        n = recvfrom(sockfd, buf, BUFSIZ,0, (struct sockaddr *)&clie_addr, &clie_addr_len);
        if (n == -1)
            perror("recvfrom error");

        printf("received from %s at PORT %d\n",
                inet_ntop(AF_INET, &clie_addr.sin_addr, str, sizeof(str)),
                ntohs(clie_addr.sin_port));

        for (i = 0; i < n; i++)
            buf[i] = toupper(buf[i]);

        n = sendto(sockfd, buf, n, 0, (struct sockaddr *)&clie_addr, sizeof(clie_addr));
        if (n == -1)
            perror("sendto error");
    }

    close(sockfd);

    return 0;
}
```

### client

```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define SERV_PORT 8000

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    int sockfd, n;
    char buf[BUFSIZ];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    while (fgets(buf, BUFSIZ, stdin) != NULL) {
        n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if (n == -1)
            perror("sendto error");

        n = recvfrom(sockfd, buf, BUFSIZ, 0, NULL, 0);         //NULL:不关心对端信息
        if (n == -1)
            perror("recvfrom error");

        write(STDOUT_FILENO, buf, n);
    }

    close(sockfd);

    return 0;
}
```

## 多播（组播）



## socket IPC（本地套接字domain）

socket API原本是为网络通讯设计的，但后来在socket的框架上发展出一种IPC机制，就是UNIX Domain Socket。虽然网络socket也可用于同一台主机的进程间通讯（通过loopback地址127.0.0.1），但是UNIX Domain Socket用于IPC更有效率：不需要经过网络协议栈，不需要打包拆包、计算校验和、维护序号和应答等，只是将应用层数据从一个进程拷贝到另一个进程。这是因为，IPC机制本质上是可靠的通讯，而网络协议是为不可靠的通讯设计的。UNIX Domain Socket也提供面向流和面向数据包两种API接口，类似于TCP和UDP，但是面向消息的UNIX Domain Socket也是可靠的，消息既不会丢失也不会顺序错乱。

UNIX Domain Socket是全双工的，API接口语义丰富，相比其它IPC机制有明显的优越性，目前已成为使用最广泛的IPC机制，比如X Window服务器和GUI程序之间就是通过UNIXDomain Socket通讯的。

使用UNIX Domain Socket的过程和网络socket十分相似，也要先调用socket()创建一个socket文件描述符，address family指定为AF_UNIX，type可以选择SOCK_DGRAM或SOCK_STREAM，protocol参数仍然指定为0即可。

UNIX Domain Socket与网络socket编程最明显的不同在于地址格式不同，用结构体sockaddr_un表示，网络编程的socket地址是IP地址加端口号，而UNIX Domain Socket的地址是一个socket类型的文件在文件系统中的路径，这个socket文件由bind()调用创建，如果调用bind()时该文件已存在，则bind()错误返回。

对比网络套接字地址结构和本地套接字地址结构：

```c
struct sockaddr_in {
    __kernel_sa_family_t sin_family; /* Address family */  	地址结构类型
    __be16 sin_port;				 /* Port number */		端口号
    struct in_addr sin_addr;		 /* Internet address */	IP地址
};
struct sockaddr_un {
    __kernel_sa_family_t sun_family; /* AF_UNIX */			地址结构类型
    char sun_path[UNIX_PATH_MAX];   /* pathname */	socket文件名(含路径)
};
```

以下程序将UNIX Domain socket绑定到一个地址。

```c
  size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
  \#define offsetof(type, member) ((int)&((type *)0)->MEMBER)
```



### 本地套接字实现流程

  IPC： pipe、fifo、mmap、信号、本地套（domain）--- CS模型

  对比网络编程 TCP C/S模型， 注意以下几点：

1. `int socket(int domain, int type, int protocol);` 

   参数 `domain：AF_INET --> AF_UNIX/AF_LOCAL` 

​                `type: SOCK_STREAM/SOCK_DGRAM` 都可以。  

2. 地址结构： `sockaddr_in --> sockaddr_un`

​    `struct sockaddr_in srv_addr; --> struct sockaddr_un srv_adrr;`

​    `srv_addr.sin_family = AF_INET; --> srv_addr.sun_family = AF_UNIX;`

​    `srv_addr.sin_port = htons(8888);  strcpy(srv_addr.sun_path, "srv.socket")`

​    `srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);    len = offsetof(struct sockaddr_un, sun_path) + strlen("srv.socket");`

​      `bind(fd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)); -->   bind(fd, (struct sockaddr *)&srv_addr, len);` 

3. bind()函数调用成功，会创建一个 socket。因此为保证bind成功，通常我们在 bind之前， 可以使用 unlink("srv.socket");（先删除一下"srv.socket"）

4. 客户端不能依赖 “隐式绑定”。并且应该在通信建立过程中，创建且初始化2个地址结构：

​    1） client_addr --> bind()

​    2) server_addr --> connect();



### server

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <stddef.h>

#include "wrap.h"

#define SERV_ADDR  "serv.socket"

int main(void)
{
    int lfd, cfd, len, size, i;
    struct sockaddr_un servaddr, cliaddr;
    char buf[4096];

    lfd = Socket(AF_UNIX, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_UNIX;
    strcpy(servaddr.sun_path, SERV_ADDR);

    len = offsetof(struct sockaddr_un, sun_path) + strlen(servaddr.sun_path);     /* servaddr total len */

    unlink(SERV_ADDR);                              /* 确保bind之前serv.sock文件不存在,bind会创建该文件 */
    Bind(lfd, (struct sockaddr *)&servaddr, len);           /* 参3不能是sizeof(servaddr) */

    Listen(lfd, 20);

    printf("Accept ...\n");
    while (1) {
        len = sizeof(cliaddr);  //AF_UNIX大小+108B

        cfd = Accept(lfd, (struct sockaddr *)&cliaddr, (socklen_t *)&len);

        len -= offsetof(struct sockaddr_un, sun_path);      /* 得到文件名的长度 */
        cliaddr.sun_path[len] = '\0';                       /* 确保打印时,没有乱码出现 */

        printf("client bind filename %s\n", cliaddr.sun_path);

        while ((size = read(cfd, buf, sizeof(buf))) > 0) {
            for (i = 0; i < size; i++)
                buf[i] = toupper(buf[i]);
            write(cfd, buf, size);
        }
        close(cfd);
    }
    close(lfd);

    return 0;
}
```



### client

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <stddef.h>

#include "wrap.h"

#define SERV_ADDR "serv.socket"
#define CLIE_ADDR "clie.socket"

int main(void)
{
    int  cfd, len;
    struct sockaddr_un servaddr, cliaddr;
    char buf[4096];

    cfd = Socket(AF_UNIX, SOCK_STREAM, 0);

    bzero(&cliaddr, sizeof(cliaddr));
    cliaddr.sun_family = AF_UNIX;
    strcpy(cliaddr.sun_path,CLIE_ADDR);

    len = offsetof(struct sockaddr_un, sun_path) + strlen(cliaddr.sun_path);     /* 计算客户端地址结构有效长度 */

    unlink(CLIE_ADDR);
    Bind(cfd, (struct sockaddr *)&cliaddr, len);                                 /* 客户端也需要bind, 不能依赖自动绑定*/

    
    bzero(&servaddr, sizeof(servaddr));                                          /* 构造server 地址 */
    servaddr.sun_family = AF_UNIX;
    strcpy(servaddr.sun_path, SERV_ADDR);

    len = offsetof(struct sockaddr_un, sun_path) + strlen(servaddr.sun_path);   /* 计算服务器端地址结构有效长度 */

    Connect(cfd, (struct sockaddr *)&servaddr, len);

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        write(cfd, buf, strlen(buf));
        len = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, len);
    }

    close(cfd);

    return 0;
}
```

### 本地套接字与网络套接字对比

见.txt文件

## 其他常用函数 



# 四、Libvent库

## 简介

libevent库

	开源。精简。跨平台（Windows、Linux、maxos、unix）。专注于网络通信。

libevent 是用于编写高速可移植非阻塞 IO 应用的库，  

事件驱动，高性能；
轻量级，专注于网络；
跨平台，支持	Windows、 Linux、 Mac	Os等；
支持多种	I/O多路复用技术， 	epoll、 poll、 dev/poll、 select	和kqueue	等；
支持	I/O，定时器和信号等事件；  

## 安装

源码包安装： 参考 README、readme

  ./configure    检查安装环境 生成 makefile

  make     生成 .o 和 可执行文件

  sudo make install 将必要的资源cp置系统指定目录。

  进入 sample 目录，运行demo验证库安装使用情况。

  编译使用库的 .c 时，需要加 -levent 选项。

  库名 libevent.so --> /usr/local/lib  查看的到。



.....................

(省略不学了)







# 五、简单Web服务器项目

B/S模型

写一个供用户访问主机文件的web服务器

## 超文本标记语言HTML

超文本标记语言是构成网页文档的主要语言。可以说明文字、图形、动画、声音、表格、链接等。在计算机中以.html、.htm作为扩展名，可以被浏览器访问。

### 简介

![image-20220412093710154](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412093710154.png)

![image-20220412093746745](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412093746745.png)

### ★常用标签

![image-20220412094112596](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412094112596.png)

![image-20220412094127608](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412094127608.png)

![image-20220412094141291](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412094141291.png)

![image-20220412100727464](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412100727464.png)

![image-20220412100752820](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412100752820.png)

![image-20220412100815481](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412100815481.png)

### 自学网址

www.w3school.com.cn

www.runoob.com

## HTTP协议基础

HTTP(超文本传输协议)。互联网应用最广泛的一种**网络应用层协议**。它可以减少网络传输，使浏览器更加高效。

通常HTTP消息包括客户机向服务器的请求消息和服务器向客户机的响应消息。

### ★请求消息

![image-20220412104103902](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412104103902.png)

每一行结束都是/r/n

### ★响应消息

![image-20220412104144679](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412104144679.png)

### HTTP请求方法

![image-20220412104336320](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412104336320.png)

![image-20220412104410205](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412104410205.png)

### HTTP常用状态码

![image-20220412104207009](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412104207009.png)

### 常见网络文件类型

![image-20220412105651592](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412105651592.png)

![image-20220412105711141](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412105711141.png)

![image-20220412105738866](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412105738866.png)

### 自学网址

https://www.runoob.com/http/http-tutorial.html

## 正则表达式

![image-20220412190432139](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412190432139.png)

![image-20220412190614744](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412190614744.png)

![image-20220412190638280](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412190638280.png)

![image-20220412190654894](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412190654894.png)

^放在最前面表示匹配字符开始，$放最后面表示匹配字符结束

![image-20220412200442225](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412200442225.png)

### sscanf函数

![image-20220412181458458](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412181458458.png)

### 自学网址

https://deerchao.cn/tutorials/regex/regex.htm

www.jb51.net/tools/regexsc.htm

https://www.runoob.com/regexp/regexp-tutorial.html





## 开发注意事项

### 浏览器请求ico

![image-20220412220000090](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412220000090.png)

### 容错处理

![image-20220412225430265](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412225430265.png)

### 快捷遍历目录scand

![image-20220412223532991](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412223532991.png)

![image-20220412223548585](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412223548585.png)

### 含有汉字的文件

![image-20220412224409723](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412224409723.png)

### 借助telnet调试

![image-20220412225048700](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220412225048700.png)
