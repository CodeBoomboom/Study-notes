---
                                                                                                                                                                                                                                            typora-root-url: 图

---

# 一、 Linux基础

## 1. shell -命令解析器

cat /etc/shells

echo $SHELL

命令路径补齐：tab

ctrl+a 移动至第一个字符

ctrl+e 移动至最后一个字符

ctrl+u 清空输入



## 2. 目录和文件

### 2.1 类Unix系统目录结构以及文件格式

#### 2.1.1 目录结构

pwd 当前目录

cd 切换路径

cd ..  切换上一个路径

sudo su或su+密码：切换成root用户		—不要随便用root用户

ctrl+d或exit退回到普通用户

mkdir  创建目录

touch	创建文件

sudo apt-get install +软件名

根目录：

![image-20211228152315597](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20211228152315597.png)

bin：存放二进制可执行文件	./date  运行可执行文件

boot：开机启动例程（程序）

dev：设备文件	Linux系统中“所见皆文件”

etc： 用户信息以及相关配置文件   vi passwd 查看文件 :q 退出  :wq 保存后退出

home：用户

lib：库(操作系统使用的库)

media：磁盘（了解）

opt、proc：进程相关

root：管理员宿主目录（家目录），只能root用户进入

usr：用户资源管理目录，用户应用相关的文件

#### 2.1.2 Linux系统文件类型格式： 7/8 种

	普通文件：-
	
	目录文件：d
	
	字符设备文件：c
	
	块设备文件：b
	
	软连接：l
	
	管道文件：p
	
	套接字：s
	
	未知文件。

#### 2.1.3 文件权限rwx

用户对文件的权限

r—4		w—2		x—1

rwx|r-x|r-x	所有者u、同组用户g、其他o

使用chown 一次修改所有者和所属组：

### 2.2 目录

#### 2.2.1 相对路径和绝对路径

绝对路径： 从目录描述位置

cd /home

cd /usr

相对路径：从当前位置

cd . 	相对于当前目录

cd ./home

cd ..  相对于当前目录上一级目录，只用cd .. 相当于返回上一级目录

cd ../

cd -  返回上一~~级~~次目录

cd ~ 返回家目录

### 2.3 ls

ls 查看信息

ls-l(ll)：列出当前文件或目录的详细信息(含有文件创建时间、读写权限、大小、时间等信息)

ls -ld xiao/  查看目录详细信息

### 2.4 cd

切换目录，详见2.2.1

### 2.5 which

which [文件...]  	查找文件

参数：

-n<文件名长度> 　指定文件名长度，指定的长度必须大于或等于所有文件中最长的文件名。
-p<文件名长度> 　与-n参数相同，但此处的<文件名长度>包括了文件的路径。
-w 　指定输出时栏位的宽度。
-V 　显示版本信息。

### 2.6 pwd

显示所在当前目录

### 2.7 mkdir

创建目录

### 2.8 rmdir

删除空的目录

```
rmdir [-p] dirName
```

- -p 是当子目录被删除后使它也成为空目录的话，则顺便一并删除。

### 2.9 touch

创建文件

touch abc xyz

创建两个文件abc和xyz

touch abc\ xyz

touch 'abc xyz'

 以两种方法都是创建一个文件abc xyz

若创建的文件已存在，则为修改文件访问时间 

### 2.10 rm

删除，“不能”恢复

rm-r：递归删除(递归就是你想删一个文件夹，而这个文件夹下还有其它的东西，它就会先把其它的东西删掉，再删这个文件夹，就好像递归的访问树的结点一样。)

rm-i:删除时询问

rm-f：强制删除 

### 2.11 mv

移动或重命名文件

mv 文件名 目录名

mv ./inc ~/		移动inc目录到home路径下（~相当于home路径）

### 2.12 cp

复制文件和目录到当前目录

cp /usr/include/stdio.h ./ 

cp -a 递归复制

cp -r 递归持续复制

### 2.13 cat

cat+文件名 查看文件里内容，输出到终端

读终端

tac+文件名 文件内容按行倒着显示 ——常用于服务器日志显示

### 2.14 more

more+文件名，读大文件 分屏显示 %进度显示

### 2.15 less

读大文件 

### 2.16  head

读大文件	显示默认前十行，可指定参数

### 2.17 tail

读大文件	显示默认后十行，可指定参数

### 2.18 ln

给文件或目录创建软链接和硬链接

#### 2.18.1 软链接

ln -s xiao xiao.s	用相对路径给xiao文件或者目录创建一个软链接xiao.s

软链接相当于快捷方式，有大小，大小为访问路径，相对路径创建的软链接大小为4字节

相对路径创建的软链接不可以像windows快捷方式那样剪贴到别的路径

ln -s ./xiao xiao.soft  绝对路径创建软链接xiao.soft

绝对路径创建的软链接大小为6字节

绝对路径创建的软链接可以像windows快捷方式那样剪贴到别的路径（用什么路径创建的就可以在什么路径中访问，建议用/home/xiaodexin/桌面/main/xiao，这个路径大小为36字节）

ln -s /home/xiaodexin/桌面/main/xiao xiao.soft

注意：为保证软链接可以随意搬移，最好用绝对路径创建软连接

#### 2.18.2 硬链接

ln xiao.txt xiao.h  硬连接不加-s

大小等于源文件大小

对创建的硬链接文件进行修改，与之相链接的文件（包括源文件以及其他硬链接文件）也会发生改变，两者是同步的

大概相当于指针的思想   有相同的Inode

### 2.19 tree

按结构树的形式显示目录和文件

需要安装，安装命令sudo snap install tree  # version 1.8.0+pkg-3fd6

常用于嵌入式开发

### 2.20 wc

计算文件的byte数、字数、列数等

### 2.21 od

指定数据显示格式（二、八、十六进制等等）

### 2.22 du

显示磁盘大小

常用于嵌入式开发（挂载磁盘时）

### 2.23 df

显示磁盘剩余空间

常用于嵌入式开发（挂载磁盘时）

## 3. 用户和组



创建用户：

	sudo adduser 新用户名		

修改文件所属用户：

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

使用chown 一次修改所有者和所属组：

	sudo chown 所有者：所属组  待操作文件。

## 4. find

### 4.1 find命令：找文件

	-type 按文件类型搜索  d/p/s/c/b/l/ f:文件-name 按文件名搜索	find ./ -name "*file*.jpg"		*通配符，找当前目录下名字中包含file的jpg文件-maxdepth 指定搜索深度(目录层级)。应作为第一个参数出现。	find ./ -maxdepth 1 -name "*file*.jpg"


	-size 按文件大小搜索. 单位：k、M、G（k小写,MG大写）	find /home/itcast -size +20M -size -50M-atime（最近访问时间）、mtime（最近属性更改时间）、ctime（最近内容改动时间） 天  amin、mmin、cmin 分钟。-exec：将find搜索的结果集执行某一指定命令。 	find /usr/ -name '*tmp*' -exec ls -ld {} \;-ok: 以交互式的方式 将find搜索的结果集执行某一指定命令


	-xargs：将find搜索的结果集执行某一指定命令。  当结果集数量过大时，可以分片映射。	find /usr/ -name '*tmp*' | xargs ls -ld 	find ./ -maxdepth 1 -type f | xargs ls -l  若不加xargs，管道会无效。find ./ -maxdepth 1 -type f -exec ls -l 上述两条语句执行结果相同。区别：exec：不论得到的结果多少都会交给exec去执行		——性能慢xargs：若得到的结果较多时会分片再交给xargs执行，即分片映射	——性能快xargs默认用空格分片，若文件名中有空格则会出错，除非修改分片字符为null，命令为添加print0：	find /usr/ -name '*tmp*' -print0 | xargs  -print0 ls -ld 

### 4.2. grep

grep命令：找文件内容

	grep -r 'copy' ./ -n	-r:递归	-n参数：:显示行号ps aux | grep 'cupsd'  -- 检索进程结果集。相当于windows任务管理器，若检索结果只有一条（就是grep命令自己），说明系统中没有与检索内容相关的进程

## 5. 软件安装卸载

### 5.1 apt-get

sudo apt-get update

sudo apt-get install 软件名

sudo apt-get remove 软件名

### 5.2 deb包安装

使用软件包（.deb） 安装	

安装安装包：sudo dpkg -i 安装包名

删除安装包：sudo dpkg -r  安装包名

### 5.3 原码安装

......

## 6. 磁盘管理

......

## 7. 压缩包管理

### 7.1 tar压缩：

	1. tar -zcvf 要生成的压缩包名	压缩材料。	tar zcvf  test.tar.gz  file1 dir2   使用 gzip方式压缩。	tar jcvf  test.tar.gz  file1 dir2   使用 bzip2方式压缩。

tar解压：

	将 压缩命令中的 c --> x	tar zxvf  test.tar.gz   使用 gzip方式解压缩。	tar jxvf  test.tar.gz   使用 bzip2方式解压缩。

### 7.2 rar压缩：

	rar a -r  压缩包名（带.rar后缀） 压缩材料。rar a -r testrar.rar	stdio.h test2.mp3

rar解压：

	unrar x 压缩包名（带.rar后缀）

### 7.3 zip压缩：

	zip -r 压缩包名（带.zip后缀） 压缩材料。	zip -r testzip.zip dir stdio.h test2.mp3

zip解压：

	unzip 压缩包名（带.zip后缀） 	unzip  testzip.zip 

## 8. 进程管理

who

ps		ps aux | grep "xiao"

jobs	显示当前shell下正在运行哪些后台作业

fg		前台切换

bg       后台切换

kill		杀死进程，需加pid

env		查看环境变量		 env | grep SHELL 相当于 echo	$SHELL 

top		

## 9. 用户管理

创建用户 	sudo useradd -s xiaodexin 

设置用户名 sudo groupadd xiaodexin 

设置密码	sudo passwd xiaodexin

切换用户	su xiaodexin

root用户	sudo su		—不要随便使用root用户

删除用户	sudo userdel -r xiaodexin 

## 10. 网络管理

查看网卡信息		ifconfig

关闭网卡				sudo ifconfig eth0 down

开启网卡				sudo ifconfig eth0 up

给eth0配置临时IP sudo ifconfig eth0 IP

查看网络上的主机是否在工作	ping

查看网络状态		netstat

查询一台机器的IP地址及其对应域名  nslookup

查询用户信息		finger

## 11. 常用服务器构建

......

ftp、nfs、ssh、scp、telnet

## 12. 其他命令

终端翻页

man		每个命令或系统函数都有自己的man page（用户手册）

man read	查看read命令的man page

man man 

![image-20220102131625857](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220102131625857.png)

man 3 printf	查看手册第三章的printf

clear		清屏，Ctrl+L

alias		起别名？

echo		回显

date		时间

umask	指定用户创建文件时的掩码   如 022 为 777-022 = 755，但是linux默认新建的文件没有执行x 权限，故755 = 644，即-rw-r--r--

创建终端	ctrl+shift+T、ctrl+shift+T

## 13. 关机重启

......

## 14. vim编辑器

### 14.1 vim简介

相当于Edit在DOS中的作用一样，主要各种对文本的操作

三种基本工作模式

命令模式

文本输入模式

末行模式

![image-20220102154424229](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220102154424229.png)

### 14.2 vim基础操作

i		光标后插入

a		光标前插入

o		光标下一行插入

I		光标所在行行首插入

A		光标所在行行尾插入

O		光标所在行上一行插入

hjkl	光标移动

跳转到指定行：

	1. 88G （命令模式）2. :88  (末行模式)

跳转文件首：

	gg （命令模式）

跳转文件尾：

	G（命令模式）

自动格式化程序：

	gg=G（命令模式）

大括号对应：

	% （命令模式）

光标移至行首：

	0 （命令模式）执行结束，工作模式不变。

光标移至行尾：

	$ （命令模式）执行结束，工作模式不变。

删除单个字符：

	x （命令模式）执行结束，工作模式不变。

替换单个字符：

	将待替换的字符用光标选中， r （命令模式），再按欲替换的字符

删除一个单词：

	dw（命令模式）光标置于单词的首字母进行操作。

删除光标至行尾：

	D 或者 d$（命令模式）

删除光标至行首：

	d0 （命令模式）

删除指定区域：

	按 V （命令模式）切换为 “可视模式”，使用 hjkl挪移光标来选中待删除区域。  按 d 删除该区域数据。

删除指定1行：

	在光标所在行，按 dd （命令模式）


删除指定N行：

	在光标所待删除首行，按 Ndd （命令模式）

复制一行：

	yy

粘贴：
	p：向后、P：向前。


查找：
	1. 找 设想 内容：

		命令模式下， 按 “/” 输入欲搜索关键字，回车。使用 n 检索下一个。2. 找 看到的内容：	命令模式下，将光标置于单词任意一个字符上，按 “*”/ “#” 

单行替换：

	将光标置于待替换行上， 进入末行模式，输入 :s /原数据/新数据

通篇替换：

	末行模式， :%s /原数据/新数据/g   g:不加，只替换每行首个。   sed 

指定行的替换：

	末行模式， :起始行号，终止行号s /原数据/新数据/g   g:不加，只替换每行首个。	:29,35s /printf/println/g

撤销、反撤销：

	u、ctrl+r（命令模式）

分屏：
	sp：横屏分。 Ctrl+ww 切换。

	vsp：竖屏分。Ctrl+ww 切换。

跳转至 man 手册：

	将光标置于待查看函数单词上，使用 K（命令模式）跳转。 指定卷， nK

查看宏定义：

	将光标置于待查看宏定义单词上，使用 [d 查看定义语句。


在末行模式执行shell命令：

	:!命令		:! ls -l 

## 15. gcc编译

gcc编译：

	4步骤： 预处理、编译、汇编、连接。
	
	-I：	指定头文件所在目录位置（头文件与源文件不在同一路径下）。
	
	-c：	只做预处理、编译、汇编。得到 二进制 文件！！！（看不懂）
	
	-g：	编译时添加调试语句。 主要支持 gdb 调试。
	
	-Wall： 显示所有警告信息。
	
	-E:		生成预处理文件.i
	
	-D：	向程序中“动态”注册宏定义。   #define NAME VALUE 	（相当于嵌入式中在设置中直接定义宏定义，即编译时注册宏定义）
	-l: 指定动态库名
	-L：指定动态库路径


​	
​	预编译（预处理）：gcc -E hello.c -o hello.i		去掉注释，导入头文件，展开宏定义
​		
​	编译：gcc -S hello.i -o hello.s								高级语言代码变为汇编代码
​	
​	汇编：gcc -c hello.s -o hello.o								汇编代码变为目标代码（二进制010101）
​	
​	链接：gcc hello.o -o hello.out								目标代码变为可执行文件

![image-20220102205047533](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220102205047533.png)



​      



数据段合并：

![image-20220109154129488](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220109154129488.png) 

## 16. toolchain

......

## 17. 静态库和共享库（动态库）

### 17.1 简介

静态库：

![image-20220102215218995](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220102215218995.png)

动态库：

![image-20220102215109007](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220102215109007.png)



### 17.2 创建静态库

静态库制作及使用步骤：

	1. 将 .c 生成 .o 文件
	
		gcc -c add.c -o add.o
	
	2. 使用 ar 工具制作静态库
	
		ar rcs  lib库名.a  add.o sub.o div.o
	
	3. 编译静态库到可执行文件中：
	
		gcc test.c lib库名.a -o a.out
		gcc test.c ./lib/libmymath.a  -o test -I ./inc

编译器隐式声明(只会声明这一种)：返回值为int，函数名，参数都为int。 如 int add(int, int);

头文件守卫：防止头文件被重复包含

	#ifndef _HEAD_H_#define _HEAD_H_......#endif

### 17.3 创建动态库

动态库制作及使用：

	1.  将 .c 生成 .o 文件， （生成与位置无关的代码 -fPIC）	gcc -c add.c -o add.o -fPIC2. 使用 gcc -shared 制作动态库	gcc -shared -o lib库名.so	add.o sub.o div.o3. 编译可执行程序时，指定所使用的动态库。  -l：指定库名(去掉lib前缀和.so后缀)  -L：指定库路径。	gcc test.c -o a.out -lmymath -L./lib                           4. 运行可执行程序 ./a.out 出错！！！！ --- ldd a.out --> "not found"	error while loading shared libraries: libxxx.so: cannot open shared object file: No such file or directory	原因：		链接器：	工作于链接阶段， 工作时需要 -l 和 -L		动态链接器：	工作于程序运行阶段，工作时需要提供动态库所在目录位置。	解决方式：						【1】 通过环境变量：  export LD_LIBRARY_PATH=动态库路径			./a.out 成功！！！  （临时生效， 终端重启环境变量失效）		【2】 永久生效： 写入 终端配置文件。  .bashrc  建议使用绝对路径。			1) vi ~/.bashrc			2) 写入 export LD_LIBRARY_PATH=动态库路径  保存			3）. .bashrc/  source .bashrc / 重启 终端  ---> 让修改后的.bashrc生效			4）./a.out 成功！！！ 		*【3】 拷贝自定义动态库 到 /lib (标准C库所在目录位置)		*【4】 配置文件法			1）sudo vi /etc/ld.so.conf			2) 写入 动态库绝对路径  保存			3）sudo ldconfig -v  使配置文件生效。			4）./a.out 成功！！！--- 使用 ldd  a.out 查看

## 18. gdb调试工具

gdb调试工具：   大前提：程序是你自己写的。  ---逻辑错误

基础指令：

gcc -g main.c -o main.o  		-g：使用该参数编译可以执行文件，得到调试表。

	gdb ./a.out
	
	list： list 1  列出源码。根据源码指定 行号设置断点。
	
	b：	b 20	在20行位置设置断点。
	
	run/r:	运行程序
	
	n/next: 下一条指令（会越过函数）
	
	s/step: 下一条指令（会进入函数）
	
	p/print：p i  查看变量的值。
	
	continue：继续执行断点后续指令。
	
	finish：结束当前函数调用。 
	
	quit：退出gdb当前调试。

其他指令：

	run：使用run查找段错误出现位置。
	
	set args： 设置main函数命令行参数 （在 start、run 之前）
	
	run 字串1 字串2 ...: 设置main函数命令行参数
	
	info b: 查看断点信息表
	
	b 20 if i = 5：	设置条件断点。
	
	ptype：查看变量类型。
	
	bt：列出当前程序正存活着的栈帧。
	
	frame： 根据栈帧编号，切换栈帧。
	
	display：设置跟踪变量
	
	undisplay：取消设置跟踪变量。 使用跟踪变量的编号。

![image-20220110191838331](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220110191838331.png)

栈帧：

![image-20220110195535644](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220110195535644.png)









## 19. makefile项目管理

makefile： 管理项目。

1个规则

2个函数

3个自动变量

模式规则

	命名：makefile	 Makefile  --- make 命令
	
	1 个规则：
	
		目标：依赖条件
		（一个tab缩进）命令
	
		1. 目标的时间必须晚于依赖条件的时间，否则，更新目标（根据目标更改时间检测更新）
	
		2. 依赖条件如果不存在，找寻新的规则去产生依赖条件。
	
	ALL：指定 makefile 的终极目标。


	2 个函数：
	
		src = $(wildcard ./*.c): 匹配当前工作目录下的所有.c 文件。将文件名组成列表，赋值给变量 src。  src = add.c sub.c div1.c 
	
		obj = $(patsubst %.c, %.o, $(src)): 将参数3中，包含参数1的部分，替换为参数2。 obj = add.o sub.o div1.o
	
	clean:	(没有依赖)
	
		-rm -rf $(obj) a.out	“-”：作用是，删除不存在文件时，不报错。顺序执行结束。


```
$(变量名):获取变量的值
3 个自动变量：

	$@: 在规则的命令中，表示规则中的目标。

	$^: 在规则的命令中，表示所有依赖条件。

	$<: 在规则的命令中，表示第一个依赖条件。如果将该变量应用在模式规则中，它可将依赖条件列表中的依赖依次取出，套用模式规则。

模式规则：

	%.o:%.c
	   gcc -c $< -o $@

静态模式规则：（表示对哪一个模式规则运用）

	$(obj):%.o:%.c
	   gcc -c $< -o $@	

伪目标：

	.PHONY: clean ALL		防止当前目录有一个跟clean、ALL相同的文件存在导致规则不可用（也表明clean不会生成具体的目标文件）

参数：
	-n：模拟执行make、make clean 命令。

	-f：指定文件执行 make 命令。				xxxx.mk**
```





# 二、 Linux系统编程

系统调用（内核提供的函数）Linux2.6有270+内核函数

应用程序的系统调用过程

应用程序->标库函数->系统调用->驱动->硬件

![image-20220121120905140](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121120905140.png)

![image-20220121121249198](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121121249198.png)





##  文件

1.1 —1.7文件IO

1.8文件系统

1.9文件操作



系统函数/系统调用

### 1.文件IO

#### 1.1 open/close 函数

**open**

![image-20220121122015793](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121122015793.png)

头文件在Linux中可以简写为 **#include <unistd.h>**

作用：打开或创建一个文件/设备

形参：pathname路径，

​			flags文件打开方式（读写标志（w/r/rw）等等）	O_APPEND:追加	O_CREAT  O_EXCL:判断文件是否存在   O_TRUNC：把文件截断成0（清零）	O_NONBLOCK:阻塞 		**使用头文件：<fcntl.h>**

​			mode模式（8进制整型）设置权限（前提：创建文件时用到，即flags使用了O_CREAT）

​			**创建文件时，指定文件访问权限，权限同时受umask影响，结论为： 文件权限 = mode & ~umask**

​			使用头文件：<fcntl.h>

返回值：返回一个文件描述符（整数）或者是-1（错误发生），即成功返回一个整数，失败返回-1,设置errno

![image-20220121124436447](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121124436447.png)







**close**

关闭一个文件描述符

![image-20220121135424779](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121135424779.png)

成功返回0，失败返回-1



**错误处理函数：**		与 errno 相关。

#include<errno.h>

	printf("xxx error: %d\n", errno);char *strerror(int errnum);	printf("xxx error: %s\n", strerror(errno));void perror(const char *s);	perror("open error");



#### 1.2 文件描述符

文件描述符（整数）

![image-20220121174509511](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121174509511.png)



``` C
PCB进程控制块：本质 结构体。成员：文件描述符表（PCB控制块中的一个成员指向文件描述符表）。文件描述符本质：指向一个文件结构体的指针（每个文件描述符都指向一个结构体）。struct file{}文件描述符：0/1/2/3/4。。。。/1023     表中可用的最小的。文件是从3开始计数，一个进程最多打开1024个文件，所以是0—1023进程默认打开三个文件0 - STDIN_FILENO	//标准输入1 - STDOUT_FILENO	//标准输出2 - STDERR_FILENO	//标准出错
```



#### 1.3 read/write函数



**read函数：**

   ssize_t read(int fd, void *buf, size_t count); 

  参数：

​    fd：文件描述符 

​    buf：存数据的缓冲区 

​    count：缓冲区大小 

  返回值： 

​    0：读到文件末尾。 

​    成功； > 0 读到的字节数。 

​    失败： -1， 设置 errno 

​    -1： 并且 errno = EAGIN 或 EWOULDBLOCK, 说明不是read失败，而是read在以非阻塞方式读一个设备文件（网络文件），并且文件无数据。 

**write函数：** 

  ssize_t write(int fd, const void *buf, size_t count); 

  参数：

​    fd：文件描述符 

​    buf：待写出数据的缓冲区 

​    count：数据大小 

  返回值

​    成功； 写入的字节数。

​    失败： -1， 设置 errno

![image-20220121201849327](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121201849327.png)

![image-20220121201908592](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121201908592.png)

 

下面写两个文件拷贝函数，一个用read/write实现，一个用fputc/fgetc实现，比较速度

首先是fputc/fgetc

![image-20220121201931087](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121201931087.png)

编译一波

![image-20220121201942344](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121201942344.png)

运行一波

![image-20220121201955931](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121201955931.png)

很快就拷贝完成了。

下面修改read那边的缓冲区，一次拷贝一个字符。

![image-20220121202009691](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121202009691.png)

运行，如图：

![image-20220121202030246](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121202030246.png)

速度缓慢。

原因分析：

**read/write这块，每次写一个字节，会疯狂进行内核态和用户态的切换，所以非常耗时**。

**fgetc/fputc，有个缓冲区（标库IO函数自带用户级缓冲区），4096，所以它并不是一个字节一个字节地写，内核和用户切换就比较少**

预读入，缓输出机制。

所以系统函数并不是一定比库函数牛逼，能使用库函数的地方就使用库函数。

标准IO函数自带用户缓冲区，系统调用无用户级缓冲。系统缓冲区是都有的。

strace命令：查看程序在执行的时候所使用到的系统函数。

#### 1.4 阻塞非阻塞

阻塞、非阻塞：  是设备文件、网络文件的属性。

	产生阻塞的场景： 读设备文件。读网络文件。（读常规文件无阻塞概念。）/dev/tty -- 终端文件。open("/dev/tty", O_RDWR|O_NONBLOCK)	--- 设置 /dev/tty 非阻塞状态。(默认为阻塞状态)

一个例子，从标准输入读，写到标准输出：

![image-20220122185630543](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122185630543.png)

执行程序，就会发现程序在阻塞等待输入

![image-20220122185645375](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122185645375.png)

下面是一段更改非阻塞读取终端的代码：

```c++
#include <unistd.h> #include <fcntl.h> #include <stdlib.h> #include <stdio.h> #include <errno.h> #include <string.h>  #define MSG_TRY "try again\n"  #define MSG_TIMEOUT "time out\n"    int main(void)  {   char buf[10];    int fd, n, i;    fd = open("/dev/tty", O_RDONLY|O_NONBLOCK);         if(fd < 0){      perror("open /dev/tty");      exit(1);    }    printf("open /dev/tty ok... %d\n", fd);    for (i = 0; i < 5; i++){     n = read(fd, buf, 10);     if (n > 0) {          //说明读到了东西        break;      }     if (errno != EAGAIN) {     //EWOULDBLOCK         perror("read /dev/tty");        exit(1);      } else {        write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));        sleep(2);      }   }     if (i == 5) {     write(STDOUT_FILENO, MSG_TIMEOUT, strlen(MSG_TIMEOUT));    } else {     write(STDOUT_FILENO, buf, n);  }        close(fd);    return 0;  }
```

执行，如图所示：

![image-20220122185816532](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122185816532.png)

 

#### 1.5 lseek函数

移动文件内部“指针”（偏移位置）

	off_t lseek(int fd, off_t offset, int whence);参数：	fd：文件描述符	offset： 偏移量	whence：起始偏移位置： SEEK_SET/SEEK_CUR/SEEK_END返回值：	成功：较起始位置偏移量	失败：-1 errno应用场景：		1. 文件的“读”、“写”使用同一偏移位置。	2. 使用lseek获取文件大小（直接将lseek设置到END，返回值就是文件大小）	3. 使用lseek拓展文件大小：要想使文件大小真正拓展，必须引起IO操作。		使用 truncate 函数，直接拓展文件。	int ret = truncate("dict.cp", 250);





#### 1.6 fcntl函数

fcntl：改变一个已经打开了的文件的访问属性

	int (int fd, int cmd, ...)fd   文件描述符cmd  命令，决定了后续参数个数int flgs = fcntl(fd,  F_GETFL);flgs |= O_NONBLOCKfcntl(fd,  F_SETFL, flgs);重点掌握两个参数的使用， F_GETFL，F_SETFL获取文件状态： F_GETFL设置文件状态： F_SETFL★位图思想（类似于嵌入式中的寄存器思想）

终端文件默认是阻塞读的，这里用fcntl将其更改为非阻塞读

```c++
#include <unistd.h>
#include <fcntl.h> 
#include <errno.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#define MSG_TRY "try again\n" 

int main(void) 
{ 
  char buf[10]; 

  int flags, n;  

  flags = fcntl(STDIN_FILENO, F_GETFL); //获取stdin属性信息 

  if(flags == -1){ 
    perror("fcntl error"); 
    exit(1); 
  } 
  
  flags |= O_NONBLOCK; 

  int ret = fcntl(STDIN_FILENO, F_SETFL, flags); 

  if(ret == -1){ 
    perror("fcntl error"); 
    exit(1); 
  }  

tryagain: 
  n = read(STDIN_FILENO, buf, 10);
  if(n < 0){ 
    if(errno != EAGAIN){     
      perror("read /dev/tty"); 
      exit(1); 
    } 
    sleep(3); 
    write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY)); 
    goto tryagain; 
  } 
  write(STDOUT_FILENO, buf, n); 

  return 0;
} 
```

编译运行，结果如下：

![image-20220121190133665](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220121190133665.png)

可以看到，是非阻塞读取。

#### 1.7 传入传出参数 

传入参数：

	1. 指针作为函数参数。
	
	2. 同常有const关键字修饰。
	
	3. 指针指向有效区域， 在函数内部做读操作。
	
	如char *strcpy(char *dest, const char *src)中的src

传出参数：

	1. 指针作为函数参数。
	
	2. 在函数调用之前，指针指向的空间可以无意义，但必须有效。
	
	3. 在函数内部，做写操作。
	
	4。函数调用结束后，充当函数返回值。其实就是传出参数在函数中被改变，可以用来传出。而且传出参数数量不限，比单纯的返回值更灵活。
	
	如char *strcpy(char *dest, const char *src)中的dest

传入传出参数：

	1. 指针作为函数参数。
	
	2. 在函数调用之前，指针指向的空间有实际意义。
	
	3. 在函数内部，先做读操作，后做写操作。
	
	4. 函数调用结束后，充当函数返回值。
	
	如char *strtok(char *str, const char *delim, char **saveptr)中的saveptr



### 2. 文件系统(目录项dentry、inode)

<img src="/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220121214316519.png" alt="image-20220121214316519"  />

一个文件主要由两部分组成，dentry(目录项，包含文件名和inode号)和inode

**inode**本质是结构体，存储文件的属性信息，如：权限、类型、大小、时间、用户、盘块位置…

也叫做文件属性管理结构，大多数的inode都存储在磁盘上。

  少量常用、近期使用的inode会被缓存到内存中。

所谓的删除文件，就是删除inode，但是数据其实还是在硬盘上，以后会覆盖掉。

**dentry**本质也是结构体，主要存储文件名、inode号等...

### 3. 文件操作

#### 3.1 stat、lstat函数

	头文件：
	#include <unistd.h>
	#include <sys/stat.h>
	
	int stat(const char *path, struct stat *buf);//会穿透符号链接
	int lstat(const char *path, struct stat *buf);//不会穿透符号链接
	
	获取文件属性（从inode结构体中获取）
	
	参数：
		path： 文件路径
		buf：（传出参数） 存放文件属性。
	
	返回值：
		成功： 0
		失败： -1 errno
	
	获取文件大小： buf.st_size
	获取文件类型： buf.st_mode
	获取文件权限： buf.st_mode
	符号穿透：stat会。lstat不会。

下面这个例子是获取文件大小的正规军解法，用stat：

![image-20220122145853385](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122145853385.png)

编译运行，并查看mystat.c文件的大小，如下：

![image-20220122145912463](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122145912463.png)

用stat查看文件类型，代码如下： 

![image-20220122152317268](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122152317268.png)

编译运行，查看一波mystat.c文件：

![image-20220122152337319](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122152337319.png)

stat会拿到符号链接指向那个文件或目录的属性。（如软链接会指向其链接的文件或目录等）

不想穿透符号就用lstat

![image-20220122152542044](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122152542044.png)

#### 3.2 access、chmod、truncate、readlink、rename函数

access函数

测试指定文件是否存在/拥有某种权限

```
int access(const char *pathname, int mode );
```

成功/具备该权限返回0，否则返回-1，设置errno为相应值

参数2：R_OK  W_OK  X_OK

通常使用access判断某个文件是否存在：F_OK 



chmod函数

修改文件访问权限

```
int chmod(const char *path, mode_t mode);
```

成功：0， 失败：-1，设置errno

```
int fchmod(int fd, mode_t mode);
```



truncate函数

截断文件长度成指定长度（文件必须存在），常用来拓展文件大小，代替lseek

```
int truncate(const char *path, off_tlenth);
```

成功：0，失败：-1，设置errno

```
int ftruncate(int fd, off_t length);
```



readlink命令： 读符号链接本身

readlink函数

读符号链接本身，得到链接所指向的文件名

ssize_t readlink(const char *path, char *buf, size_t bufsiz)

成功：返回实际读到的字节数；失败：-1，设置errno



rename函数

重命名一个文件

int rename(const char *oldpath, const char *newpath)

成功：0.，失败-1，设置errno



#### 3.3 link和unlink隐式回收

硬链接数就是dentry数目

link就是用来创建硬链接的

link可以用来实现mv命令 

函数原型：

```
int link(const char *oldpath, const char *newpath)
```

用这个来实现mv，用oldpath来创建newpath，完事儿删除oldpath就行。

删除一个链接（目录项）  

```
int unlink(const char *pathname)
```

unlink是删除一个文件的目录项dentry，使硬链接数-1

unlink函数的特征：清除文件时，如果文件的硬链接数到0了，没有dentry对应，但该文件仍不会马上被释放，**要等到所有打开该文件的进程关闭该文件，系统才会挑时间将该文件释放掉。**

下面用一段代码来验证unlink是删除dentry：

```c
/* 
 *unlink函数是删除一个dentry 
 */  
#include <unistd.h>  
#include <fcntl.h>  
#include <stdlib.h>  
#include <string.h>  
#include <stdio.h>    
  
int main(void)  
{  
    int fd, ret;  
    char *p = "test of unlink\n";  
    char *p2 = "after write something.\n";  
  
    fd = open("temp.txt", O_RDWR|O_CREAT|O_TRUNC, 0644);  
    if(fd < 0){  
        perror("open temp error");  
        exit(1);  
    }  
  
    ret = write(fd, p, strlen(p));  
    if (ret == -1) {  
        perror("-----write error");  
    }  
  
    printf("hi! I'm printf\n");  
    ret = write(fd, p2, strlen(p2));  
    if (ret == -1) {  
        perror("-----write error");  
    }  
  
    printf("Enter anykey continue\n");  
    getchar();  
    
    ret = unlink("temp.txt");        //具备了被释放的条件  
    if(ret < 0){  
        perror("unlink error");  
        exit(1);  
    }  
  
    close(fd);  
    return 0;  
}  
```

编译程序并运行，程序阻塞，此时打开新终端查看临时文件temp.c如下：

​       ![image-20220122155848302](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122155848302.png)                       

可以看到，临时文件没有被删除，这是因为当前进程没结束。

输入字符使当前进程结束后，temp.txt就不见了

 ![image-20220122155855181](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122155855181.png)

下面开始搞事，在程序中加入段错误成分（向一个常量字符中写入字符），段错误在unlink之前，由于发生段错误，程序后续删除temp.txt的dentry部分就不会再执行，temp.txt就保留了下来，这是不科学的。

解决办法是检测fd有效性后，立即释放temp.txt，由于进程未结束，虽然temp.txt的硬链接数已经为0，但还不会立即释放，仍然存在，要等到程序执行完才会释放。这样就能避免程序出错导致临时文件保留下来。

因为文件创建后，硬链接数立马减为0，即使程序异常退出，这个文件也会被清理掉。**这时候的内容是写在内核空间的缓冲区**。 

修改后代码如下：

```c
/*  *unlink函数是删除一个dentry  */  #include <unistd.h>  #include <fcntl.h>  #include <stdlib.h>  #include <string.h>  #include <stdio.h>      int main(void)  {      int fd, ret;      char *p = "test of unlink\n";      char *p2 = "after write something.\n";        fd = open("temp.txt", O_RDWR|O_CREAT|O_TRUNC, 0644);      if(fd < 0){          perror("open temp error");          exit(1);      }        ret = unlink("temp.txt");        //具备了被释放的条件      if(ret < 0){          perror("unlink error");          exit(1);      }        ret = write(fd, p, strlen(p));      if (ret == -1) {          perror("-----write error");      }        printf("hi! I'm printf\n");      ret = write(fd, p2, strlen(p2));      if (ret == -1) {          perror("-----write error");      }        printf("Enter anykey continue\n");      getchar();        close(fd);      return 0;  } 
```

**隐式回收**：

当进程结束运行时，所有进程打开的文件会被关闭，申请的内存空间会被释放。系统的这一特性称之为隐式回收系统资源。

比如上面那个 程序，要是没有在程序中关闭文件描述符，没有隐式回收的话，这个文件描述符会保留，多次出现这种情况会导致系统文件描述符耗尽。所以隐式回收会在程序结束时收回它打开的文件使用的文件描述符。



### 4.目录操作

#### 4.1 getcwd、chdir函数

getcwd函数

获取进程当前工作目录（卷3， 标库函数）

```
char *getcwd(char *buf, size_t size);
```

成功：buf中保存当前进程工作目录位置，失败返回NULL



chdir函数

改变当前进程的工作目录

```
int chdi（const char *path);
```

成功：0， 失败：-1，设置errno



#### 4.2 文件目录rwx权限差异

vi 目录

会得到目录项的列表

![image-20220122172808542](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122172808542.png)

#### 4.3 目录操作函数opendir、closedir、readdir

目录操作函数：

```C
#include <sys/types>#include <dirent.h>DIR *opendir(char *name); //打开一个目录，成功返回目录指针，失败返回NULL，DIR*：目录结构体指针，相当于文件操作中的FILE*int closedir(DIR *dp); //关闭一个目录，成功返回0失败返回-1，设置errnostruct dirent *readdir(DIR * dp);//读取目录,返回目录项dentry，成功返回结构体dentry，每次返回一个，到最后一个后返回NULL，失败返回NULL，设置errnostruct dirent {		inode		char d_name[256];}
```

没有写目录操作，因为目录写操作就是创建文件。可以用touch

下面用目录操作函数实现一个ls操作：

![image-20220122173449534](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122173449534.png)

编译执行，如下：

![image-20220122173506035](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122173506035.png)

要隐藏这个.和..的话，在输出文件名的时候判定一下，只输出不是.和..的就行了

### 5.实战-递归遍历目录

任务需求：使用opendir  closedir  readdir  stat实现一个递归遍历目录的程序

输入一个指定目录，默认为当前目录。递归列出目录中的文件，同时显示文件大小。

思路分析

递归遍历目录：ls-R.c

```
1.判断命令行参数，获取用户要查询的目录名。  int argc, char *argv[1]

    argc == 1 --> ./

2.判断用户指定的是否是目录。 stat S_ISDIR(); --> 封装函数 isFile() {  }

3.读目录： read_dir() { 

    opendir（dir）

    while （readdir（））{

      普通文件，直接打印

      目录：

       拼接目录访问绝对路径。sprintf(path, "%s/%s", dir, d_name) 

       递归调用自己。--》 opendir（path） readdir closedir

    }

    read_dir() --> isFile() ---> read_dir()
```

