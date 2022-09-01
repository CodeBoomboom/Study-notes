

# 1.基础命令

## 基础

cd：切换目录； cd ..返回到上一级目录

ls-l(ll)：列出当期文件或目录的详细信息(含有文件创建时间、读写权限、大小、时间等信息)

ls:显示当前所在目录内的所有内容

ls-p:显示所有内容，若有文件夹则也显示其子目录内容

touch：创建文件

mkdir：创建目录

cat：查看文件内容

mv：移动或重命名  mv 文件名 目录名

rm-r：递归删除(递归就是你想删一个文件夹，而这个文件夹下还有其它的东西，它就会先把其它的东西删掉，再删这个文件夹，就好像递归的访问树的结点一样。) 常用于删除文件夹

rm-f：强制删除

rm -i: 删除前询问

rmdir: 删除空目录（文件夹）

tree：显示目录结构

chmod:修改文件或目录权限  chmod 777 文件名

pwd:显示当前所在目录

which    查看可执行文件的位置

cp：复制文件和目录到指定目录  cp 要复制的文件/目录  复制到的目标目录

ln 给文件或目录创建软/硬链接   

​			ln -s xiao xiao.s 用相对路径给xiao文件或者目录创建一个软链接xiao.s

​			ln xiao.txt xiao.h  硬连接不加-s

find命令：找文件  find ./ -name "*xin.c"

grep: 找文件内容  ps aux | grep 'cupsd'  -- 检索进程结果集。  ls | grep 'x'  检索ls结果集

apt-get：软件安装

sudo dpkg -i 安装包名： deb包安装

clear		清屏，Ctrl+L

umask	指定用户创建文件时的掩码   如 022 为 777-022 = 755，但是linux默认新建的文件没有执行x 权限，故755 = 644，即-rw-r--r--

## 用户和组

创建用户：

	sudo adduser 新用户名		

修改文件所属用户： change own

	sudo chown 新用户名 待修改文件。
	
	sudo chown wangwu a.c

删除用户：

	sudo deluser 用户名

创建用户组：

	sudo addgroup 新组名

修改文件所属用户组：

	sudo chgrp 新用户组名 待修改文件。
	
	sudo chgrp g88 a.c

删除组：

	sudo delgroup 用户组名

用户对文件的权限

r—4		w—2		x—1

rwx|r-x|r-x	属主、属组、其他

chmod:修改文件或目录权限  chmod 777 文件名   change mode

使用chown 一次修改指定文件所有者和所属组： 

	sudo chown 所有者：所属组  待操作文件。

创建用户 	sudo useradd -s xiaodexin 

设置用户名 sudo groupadd xiaodexin 

设置密码	sudo passwd xiaodexin

切换用户	su xiaodexin

root用户	sudo su		—不要随便使用root用户  exit 退出root

删除用户	sudo userdel -r xiaodexin 

##  压缩包管理

###  tar压缩：

	 tar -zcvf 要生成的压缩包名	压缩材料。
	
		tar zcvf  test.tar.gz  file1 dir2   使用 gzip方式压缩。
	
		tar jcvf  test.tar.gz  file1 dir2   使用 bzip2方式压缩。

tar解压：

	将 压缩命令中的 c --> x
	
		tar zxvf  test.tar.gz   使用 gzip方式解压缩。
	
		tar jxvf  test.tar.gz   使用 bzip2方式解压缩。

### rar压缩：

	rar a -r  压缩包名（带.rar后缀） 压缩材料。
	
	rar a -r testrar.rar	stdio.h test2.mp3

rar解压：

	unrar x 压缩包名（带.rar后缀）

### zip压缩：

	zip -r 压缩包名（带.zip后缀） 压缩材料。
	
		zip -r testzip.zip dir stdio.h test2.mp3

zip解压：

	unzip 压缩包名（带.zip后缀） 
	
		unzip  testzip.zip 





# 2.网络编程命令

主要是ifconfig、ping、netstate

### (1)ping

##### 1.ping的使用

ping：测试某一个网络是否连通。

命令格式：ping 主机名/ping 域名/ping IP地址 

![ping](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\ping.jpg)

画红处是一个关键信息，表示数据包丢失的比例

##### 2.ping的原理

ping命令是基于ICMP协议开发的，ICMP是一种基于IP协议的控制协议。ping程序在使用时，会组装成一个IP报文。报文的目的地址为ping 的目标地址，源地址就是发送ping命令时的主机地址，按照ICMP报文格式在IP报文后填上更多数据，IP报文通过ARP协议（数据链路层协议），将源地址和目的地址翻译成MAC地址（硬件地址），经过数据链路层后，报文被传输出去。当报文到达目的地址之后，目的地址所对应的主机也按照ICMP协议进行应答。

### (2)ifconfig

ifconfig用来显示目前本地机器的网络设置或设置网络设备的状态，其实就是网卡列表。（显示网卡信息）

直接输入ifconfig命令，就可以显示机器上有哪些网口，和网口对应的状态信息，包括：连接类型(以太网)、网卡的物理地址、网卡的IP地址、掩码、接收和发送数据包情况统计等。

Linux在一台主机上可以有多个网卡设备，这就需要确定网络连接是从哪一个网卡设备上出去的？通过设置Metric参数来确定多块网卡的优先级的，数值越小，优先级越高，1 为最高级。

设置网络设备状态：

```c++
//启动/关闭指定网卡
# ifconfig eth0 down
# ifconfig eth0 up
//修改MAC地址
# ifconfig eth0 hw ether 00:AA:BB:CC:DD:EE 
//给eth0网卡配置IP地址
# ifconfig eth0 192.168.1.56 
```

### (3)netstat

netstat命令用于显示网络状态。

netstat：显示网络状态信息，可看到各个端口状态

-a或--all 显示所有连线中的Socket。

-p或--programs 显示正在使用Socket的程序名称。

-u或--udp 显示UDP传输协议的连线状况。

-t或--tcp 显示TCP传输协议的连线状况。                                                    (可以清楚地看到一条 TCP 连接的四元组（源地址、源端口、目的地地址和目的端口）)

![tcp](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\tcp.jpg)

state 描述的是当前 TCP 连接处于的状态

netstate -ntlp | grep 80(端口号)：查看某一端口的状态

![netstate](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\netstate.jpg)

80 端口被http进程占用了，最末尾的信息也能看到这个进程对应的 pid。

### (4)tcpdump

tcpdump是用在linux下的网络抓包工具。

-i:表示抓取指定网络接口(网卡)的数据包

![tcpdump](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\tcpdump.jpg)

### 端口号：

端口号的主要作用是表示一台计算机中的特定进程所提供的服务。网络中的计算机是通过IP地址来代表其身份的，它只能表示某台特定的计算机，但是一台计算机上可以同时提供很多个服务，如数据库服务、FTP服务、Web服务等，我们就通过端口号来区别相同计算机所提供的这些不同的服务，如常见的端口号21表示的是FTP服务，端口号23表示的是Telnet服务端口号25指的是SMTP服务等。



| 是管道命令，通常要借助管道命令 实现多个命令的组合，grep是linux下的文本过滤工具，所以要查找某个具体的端口信息通常组合| grep 端口号

# 3.系统编程命令（进程）

进程管理最主要的工作就是判断服务器当前运行是否健康，是否需要人为干预。如果服务器的CPU占用率、内存占用率过高，就需要人为介入解决问题了

man：查看帮助文档

kill pid：杀死某一进程，kill+进程id号

top：动态显示进程信息，cpu占用和内存占用

ps、top、free、lsof

### (1)ps命令

查看系统中当前运行进程的详细信息(显示的信息是执行ps命令那一时刻的，不具有实时性)

Linux查看所有进程信息：ps aux                                                                                                                           Linux查看所有某个进程信息：ps aux | grep xxx，就会列出xxx进程详细信息

![ps-aux1](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\ps-aux1.jpg)

USER:进程所属用户                                                                                                                                                                       PID:进程的ID号                                                                                                                                                                           %CPU:进程占用CPU资源百分比                                                                                                                                                   %MEM:进程占用物理内存百分比                                                                                                                                                VSZ:进程占用虚拟内存的大小                                                                                                                                                    RSS:进程占用物理内存的大小                                                                                                                                                              TTY:该进程是在哪个终端运行的                                                                                                                                       STAT:进程的状态                                                                                                                                                                      START:该进程的启动时间                                                                                                                                                  TIME:该进程占用CPU的运算时间                                                                                                                    COMMAND:进程对应的实际程序(产生此进程的命令名)

### (2)top命令

可以动态地持续监听进程地运行状态包括cpu和内存的占用情况                                                                                                           和ps命令的输出类似，只是如果在终端执行top命令，不能看到所有进程，只能看到占比靠前的进程

![top](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\top.jpg)

### (3)free命令

显示系统内存状态，包括系统物理内存、虚拟内存(swap交换分区)、共享内存和系统缓存的使用情况

-g:以GB为单位，显示内存使用情况                                                                                                                                                   -m:以MB为单位，显示内存使用情况。

![free](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\free.jpg)

total 是总内存数                                                                                                                                                                           used 是已经使用的内存数                                                                                                                                                            free 是空闲的内存数                                                                                                                                                                    shared 是多个进程共享的内存总数                                                                                                                                        buffers 是缓冲内存数                                                                                                                                                              cached 是缓存内存数。

### (4)lsof

通过该命令可以了解进程打开了哪些文件描述符，或者我们关注的文件描述符被哪些进程打开了。

-u 用户名：只列出某个用户的进程打开的文件                                                                                                                                   -p pid：列出某个 PID 进程打开的文件。

![lsof](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\lsof.jpg)



lsof还有一个用途。如果我们启动了一个服务器程序，发现这个服务器需要绑定的端口地址已经被占用，内核会报出“该地址已在使用”的出错信息，我们可以使用lsof找出正在使用该端口的那个进程。比如当前服务器所使用的端口为8080，通过lsof -i :8080，可以找到使用8080端口的进程，之后查看进程状态定位问题。

# 4. gdb相关命令

### 一. gdb基础命令

![img](http://pic.cr173.com/up/2014-9/2014090821310094045.gif)

![img](http://pic.cr173.com/up/2014-9/2014090821305677518.gif)

![img](http://pic.cr173.com/up/2014-9/2014090821305674582.gif)

![img](http://pic.cr173.com/up/2014-9/2014090821305633855.gif)



1.首先执行ll指令罗列出当前文件或目录的详细信息，含有时间、读写权限、大小、时间等信息 

2.看到其中包含一个test.c文件，执行vim命令打开该文件，查看源文件代码，

3.执行gcc命令并携带-g参数，表示生成可以调试的可执行程序test  gcc -g test.c -o test.o  

4.执行ls指令仅罗列当前文件名或目录名，查看到绿色的test文件(绿色表示可执行文件)。

打开gdb调试工具，后面跟上要调试的可执行文件：gdb test

调试完成退出gdb: q

打开gdb，

查看当前文件源代码:list/l(从默认位置显示)   

查看非当前文件源代码:list/l 文件名 :行号

list/l 行号 (从指定行显示)             list/l 文件名 :函数名

list/l 函数名(从指定函数显示)      设置显示行数:set list 行数

设置断点:b/break 行号                 查看断点:i b

b/break 函数名					删除断点:d 断点编号(程序停在断点处，该处代码还没有执行

b/break 文件名:行号		   设置断点无效:disable 断点编

b/break 文件名:函数		   设置断点生效:enable  断点编号 

设置条件断点:b 10 if(i==5) 表示i为5的时候才让断点停在10行

![gdb1](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\gdb1.jpg)

### 二.调试core文件

以上调试的都是源代码文件，但是现实中是程序挂掉的时候才需要调试，所以大多数调的不是源代码文件，而是根据core文件进行调试的。



![core1](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\图片\core1.jpg)

编译程序仍然带上-g参数，如上图中所示发生了段错误，通常是因为访问了非法地址所以发生段错误。

系统在默认情况下不生成core文件，所以要先用ulimit查看程序是否受到限制，如果发现core文件大小为0，使用ulimit -c unlimited进行修改，然后再次运行程序，通过ls命令可以查看到当前目录下含有一个core文件了，然后运行命令gdb+二进程文件名+core文件名，运行完可以看到core文件中的具体报错信息了，可以输入bt命令查看当前程序中存活的函数的调用栈(frame根据栈帧编号切换函数栈帧)。

栈帧：随着函数调用而在栈空间上开辟的一片内存空间，用于存放函数调用时产生的局部变量。

### 三.多线程调试

本质上讲，使用 GDB 调试多线程程序的过程和调试单线程程序类似，不同之处在于，调试多线程程序需要监控多个线程的执行过程，找到导致程序出现问题的Bug，而调试单线程程序只需要监控1个线程。

![gdb0](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\gdb0.jpg)

<img src="G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\gdb多线程2.jpg" alt="gdb多线程2" style="zoom: 33%;" />

<img src="G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\gdb多线程1.png" alt="gdb多线程1" style="zoom: 33%;" />

![多线程调试啊](G:\Git\GitProject\Study-notes\八股文\闫博面试整理\秋招复习\知识汇总\图片\多线程调试啊.png)

### 5、奇安信面经问题

判断服务器是否启动用什么命令，

方法一：查看服务器服务进程情况，这里拿MyServer服务举例,其他服务查询更改名字即可

```javascript
ps -ef|grep MyServer
```

方法二：查看6379（为redis的端口号）端口号是否被占用

```javascript
lsof -i :6379
```

方法三：显示tcp的端口和进程等相关情况

```javascript
netstat -tnlp
```



