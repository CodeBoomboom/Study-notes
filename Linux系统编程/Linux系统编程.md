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

sudo su或su+密码：切换成root用户		—不要随便用root用户   个人密码0107

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
	
	字符设备文件：c长度
	
	块设备文件：b
	
	软连接：l
	
	管道文件：p
	
	套接字：s
	
	未知文件。
	占磁盘空间：普通文件、目录、软链接
	其他的都是伪文件，不占磁盘空间

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

which [文件...]  	查找文件按

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

	-type 按文件类型搜索  d/p/s/c/b/l/ f:文件
	
	-name 按文件名搜索
	
		find ./ -name "*file*.jpg"		*通配符，找当前目录下名字中包含file的jpg文件
	
	-maxdepth 指定搜索深度(目录层级)。应作为第一个参数出现。
	
		find ./ -maxdepth 1 -name "*file*.jpg"


	-size 按文件大小搜索. 单位：k、M、G（k小写,MG大写）
	
		find /home/itcast -size +20M -size -50M
	
	-atime（最近访问时间）、mtime（最近属性更改时间）、ctime（最近内容改动时间） 天  amin、mmin、cmin 分钟。
	
	-exec：将find搜索的结果集执行某一指定命令。
	 
		find /usr/ -name '*tmp*' -exec ls -ld {} \;
	
	-ok: 以交互式的方式 将find搜索的结果集执行某一指定命令


	-xargs：将find搜索的结果集执行某一指定命令。  当结果集数量过大时，可以分片映射。
	
		find /usr/ -name '*tmp*' | xargs ls -ld 
		
	find ./ -maxdepth 1 -type f | xargs ls -l  若不加xargs，管道会无效。
	find ./ -maxdepth 1 -type f -exec ls -l 
	上述两条语句执行结果相同。区别：
	exec：不论得到的结果多少都会交给exec去执行		——性能慢
	xargs：若得到的结果较多时会分片再交给xargs执行，即分片映射	——性能快
	xargs默认用空格分片，若文件名中有空格则会出错，除非修改分片字符为null，命令为添加print0：
		find /usr/ -name '*tmp*' -print0 | xargs  -print0 ls -ld 

### 4.2. grep

grep命令：找文件内容

	grep -r 'copy' ./ -n
		-r:递归
		-n参数：:显示行号
	
	ps aux | grep 'cupsd'  -- 检索进程结果集。相当于windows任务管理器，若检索结果只有一条（就是grep命令自己），说明系统中没有与检索内容相关的进程

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

	1. tar -zcvf 要生成的压缩包名	压缩材料。
	
		tar zcvf  test.tar.gz  file1 dir2   使用 gzip方式压缩。
	
		tar jcvf  test.tar.gz  file1 dir2   使用 bzip2方式压缩。

tar解压：

	将 压缩命令中的 c --> x
	
		tar zxvf  test.tar.gz   使用 gzip方式解压缩。
	
		tar jxvf  test.tar.gz   使用 bzip2方式解压缩。

### 7.2 rar压缩：

	rar a -r  压缩包名（带.rar后缀） 压缩材料。
	
	rar a -r testrar.rar	stdio.h test2.mp3

rar解压：

	unrar x 压缩包名（带.rar后缀）

### 7.3 zip压缩：

	zip -r 压缩包名（带.zip后缀） 压缩材料。
	
		zip -r testzip.zip dir stdio.h test2.mp3

zip解压：

	unzip 压缩包名（带.zip后缀） 
	
		unzip  testzip.zip 

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

	1. 88G （命令模式）
	
	2. :88  (末行模式)

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

		命令模式下， 按 “/” 输入欲搜索关键字，回车。使用 n 检索下一个。
	
	2. 找 看到的内容：
	
		命令模式下，将光标置于单词任意一个字符上，按 “*”/ “#” 

单行替换：

	将光标置于待替换行上， 进入末行模式，输入 :s /原数据/新数据

通篇替换：

	末行模式， :%s /原数据/新数据/g   g:不加，只替换每行首个。   sed 

指定行的替换：

	末行模式， :起始行号，终止行号s /原数据/新数据/g   g:不加，只替换每行首个。
	
		:29,35s /printf/println/g

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

```c++
1. 将 .c 生成 .o 文件

	gcc -c add.c -o add.o

2. 使用 ar 工具制作静态库

	ar rcs  lib库名.a  add.o sub.o div.o

3. 编译静态库到可执行文件中：

	gcc test.c lib库名.a -o a.out
	gcc test.c ./lib/libmymath.a  -o test -I ./inc	//-I ./inc 在inc下查找头文件
    gcc test.c  -o test -I ./inc -l mymath -L ./lib
```

编译器隐式声明(只会声明这一种)：返回值为int，函数名，参数都为int。 如 int add(int, int);

头文件守卫：防止头文件被重复包含

	#ifndef _HEAD_H_
	
	#define _HEAD_H_
	
	......
	
	#endif

### 17.3 创建动态库

动态库制作及使用：

```C++
1.  将 .c 生成 .o 文件， （生成与位置无关的代码 -fPIC）

	gcc -c add.c -o add.o -fPIC/-fpic

2. 使用 gcc -shared 制作动态库

	gcc -shared -o lib库名.so	add.o sub.o div.o

3. 编译可执行程序时，指定所使用的动态库。  -l：指定库名(去掉lib前缀和.so后缀)  -L：指定库路径。

	gcc test.c -o a.out -l mymath -L ./lib
                           
4. 运行可执行程序 ./a.out 出错！！！！ --- ldd a.out --> "not found"

	error while loading shared libraries: libxxx.so: cannot open shared object file: No such file or directory

	原因：
		链接器：	工作于链接阶段， 工作时需要 -l 和 -L

		动态链接器：	工作于程序运行阶段，工作时需要提供动态库所在目录位置（动态库依赖关系）。（使用ldd命令可以检查动态库依赖关系）

	解决方式：				

		【1】 通过环境变量：  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:动态库路径	//$LD_LIBRARY_PATH的含义是先获取LD_LIBRARY_PATH之前的值，不同的值之间用:隔开
            用echo $LD_LIBRARY_PATH 查看环境变量内容

			./a.out 成功！！！  （临时生效， 终端重启环境变量失效）

		【2】 永久生效： 写入 终端配置文件。  .bashrc  建议使用绝对路径。

			1) vi ~/.bashrc

			2) 写入 export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:动态库路径  保存

			3）. .bashrc/  source .bashrc / 重启 终端  ---> 让修改后的.bashrc生效

			4）./a.out 成功！！！ 

		*【3】 拷贝自定义动态库 到 /lib (标准C库所在目录位置)

		*【4】 配置文件法

			1）sudo vi /etc/ld.so.conf

			2) 写入 动态库绝对路径  保存

			3）sudo ldconfig -v  使配置文件生效。

			4）./a.out 成功！！！--- 使用 ldd  a.out 查看
```

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
如下，表示$(obj)的模式规则是:%.o:%.c
	  						 gcc -c $< -o $@	
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



虚拟地址空间：进程中存在的虚拟的地址，由MMU（内存管理单元，虚拟内存映射单元）映射到实际存在的物理地址空间。其存在的意义就是好管理物理内存（使得进程内存地址连续，且节省物理内存，使得可以运行虚拟内存大于其物理内存的多个进程）

![image-20220204172920467](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220204172920467.png)



## 1. 文件IO

### ★1.1 open/close 函数

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

	printf("xxx error: %d\n", errno);
	
	char *strerror(int errnum);
	
		printf("xxx error: %s\n", strerror(errno));
	
	void perror(const char *s);
	
		perror("open error");



### ★1.2 文件描述符

文件描述符（整数），存在于虚拟地址空间（可执行程序运行期间即进程中存在，0-4G）中

![image-20220121174509511](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220121174509511.png)



``` C
PCB进程控制块：本质 结构体。

成员：文件描述符表（PCB控制块中的一个成员指向文件描述符表）。

文件描述符本质：指向一个文件结构体的指针（每个文件描述符都指向一个结构体）。
struct file{
}

文件描述符：0/1/2/3/4。。。。/1023     表中可用的最小的。
文件是从3开始计数，一个进程最多打开1024个文件，所以是0—1023
进程默认打开三个文件
0 - STDIN_FILENO	//标准输入

1 - STDOUT_FILENO	//标准输出

2 - STDERR_FILENO	//标准出错
```



### ★1.3 read/write函数



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

### 1.4 阻塞非阻塞

阻塞、非阻塞：  是设备文件、网络文件的属性。

	产生阻塞的场景： 读设备文件。读网络文件。（读常规文件无阻塞概念。）
	
	/dev/tty -- 终端文件。
	
	open("/dev/tty", O_RDWR|O_NONBLOCK)	--- 设置 /dev/tty 非阻塞状态。(默认为阻塞状态)

一个例子，从标准输入读，写到标准输出：

![image-20220122185630543](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122185630543.png)

执行程序，就会发现程序在阻塞等待输入

![image-20220122185645375](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122185645375.png)

下面是一段更改非阻塞读取终端的代码：

```c++
#include <unistd.h> 
#include <fcntl.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 

 #define MSG_TRY "try again\n" 
 #define MSG_TIMEOUT "time out\n"   

 int main(void) 
 {
   char buf[10]; 
   int fd, n, i; 
   fd = open("/dev/tty", O_RDONLY|O_NONBLOCK); 
     
   if(fd < 0){ 
     perror("open /dev/tty"); 
     exit(1); 
   } 

   printf("open /dev/tty ok... %d\n", fd); 

   for (i = 0; i < 5; i++){ 
    n = read(fd, buf, 10); 
    if (n > 0) {          //说明读到了东西 
       break; 
     } 

    if (errno != EAGAIN) {     //EWOULDBLOCK  
       perror("read /dev/tty"); 
       exit(1); 
     } else { 
       write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY)); 
       sleep(2); 
     } 
  } 
  
  if (i == 5) { 
    write(STDOUT_FILENO, MSG_TIMEOUT, strlen(MSG_TIMEOUT)); 
   } else { 
    write(STDOUT_FILENO, buf, n); 
 } 
     
  close(fd); 
   return 0; 
 }
```

执行，如图所示：

![image-20220122185816532](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122185816532.png)

 

### 1.5 lseek函数

移动文件内部“指针”（偏移位置）

	off_t lseek(int fd, off_t offset, int whence);
	
	参数：
		fd：文件描述符
		offset： 偏移量
		whence：起始偏移位置： SEEK_SET/SEEK_CUR/SEEK_END
	
	返回值：
	
		成功：较起始位置偏移量
		失败：-1 errno
	
	应用场景：	
		1. 文件的“读”、“写”使用同一偏移位置。
	
		2. 使用lseek获取文件大小（直接将lseek设置到END，返回值就是文件大小）
	
		3. 使用lseek拓展文件大小：要想使文件大小真正拓展，必须引起IO操作。
	
			使用 truncate 函数，直接拓展文件。	int ret = truncate("dict.cp", 250);





### ★1.6 fcntl函数

fcntl：改变一个已经打开了的文件的访问属性

```c++
int (int fd, int cmd, ...)
fd   文件描述符
cmd  命令，决定了后续参数个数

//设置文件为非阻塞
int flgs = fcntl(fd,  F_GETFL);
flgs |= O_NONBLOCK;
fcntl(fd,  F_SETFL, flgs);

重点掌握两个参数的使用， F_GETFL，F_SETFL
获取文件状态： F_GETFL
设置文件状态： F_SETFL

★位图思想（类似于嵌入式中的寄存器思想）
```

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

### 1.7 传入传出参数 

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



## 2. 文件系统

### ★2.1 文件系统(目录项dentry、inode)

<img src="/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220121214316519.png" alt="image-20220121214316519"  />

一个文件主要由两部分组成，dentry(目录项，包含文件名和inode号)和inode

**inode**本质是结构体，存储文件的属性信息，如：权限、类型、大小、时间、用户、盘块位置…

也叫做文件属性管理结构，大多数的inode都存储在磁盘上。

  少量常用、近期使用的inode会被缓存到内存中。

所谓的删除文件，就是删除inode，但是数据其实还是在硬盘上，以后会覆盖掉。

**dentry**本质也是结构体，主要存储文件名、inode号等...

### 2.2 文件操作

#### ★stat、lstat函数

```c
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

S_ISREG(buf.st_mode)
S_ISDIR(buf.st_mode)
...
获取文件大小： buf.st_size
获取文件类型： buf.st_mode
获取文件权限： buf.st_mode
符号穿透：stat会。lstat不会。
```

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

#### access、chmod、truncate、readlink、rename函数

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



#### ★ link和unlink隐式回收

硬链接数就是dentry数目

link就是用来创建硬链接的

link可以用来实现mv命令 

函数原型：

```c++
int link(const char *oldpath, const char *newpath)	//成功0，失败-1
```

用这个来实现mv，用oldpath来创建newpath，完事儿删除oldpath就行。

删除一个链接（目录项）  

```c++
int unlink(const char *pathname)	//成功0，失败-1
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
  
    ret = unlink("temp.txt");        //具备了被释放的条件  
    if(ret < 0){  
        perror("unlink error");  
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
  
    close(fd);  
    return 0;  
} 
```

**隐式回收**：

当进程结束运行时，所有进程打开的文件会被关闭，申请的内存空间会被释放。系统的这一特性称之为隐式回收系统资源。

比如上面那个 程序，要是没有在程序中关闭文件描述符，没有隐式回收的话，这个文件描述符会保留，多次出现这种情况会导致系统文件描述符耗尽。所以隐式回收会在程序结束时收回它打开的文件使用的文件描述符。



### 2.3 目录操作

#### getcwd、chdir函数

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



#### 文件目录rwx权限差异

vi 目录

会得到目录项的列表

![image-20220122172808542](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122172808542.png)

#### ★目录操作函数opendir、closedir、readdir

目录操作函数：

```C
#include <sys/types>
#include <dirent.h>
DIR *opendir(char *name); //打开一个目录，成功返回目录指针，失败返回NULL，DIR*：目录结构体指针，相当于文件操作中的FILE*

int closedir(DIR *dp); //关闭一个目录，成功返回0失败返回-1，设置errno

struct dirent *readdir(DIR * dp);//读取目录,返回目录项dentry，成功返回结构体dentry，每次返回一个，到最后一个后返回NULL，失败返回NULL，设置errno

struct dirent {
		inode
		char d_name[256];
}
```

没有写目录操作，因为目录写操作就是创建文件。可以用touch

下面用目录操作函数实现一个ls操作：

![image-20220122173449534](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122173449534.png)

编译执行，如下：

![image-20220122173506035](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220122173506035.png)

要隐藏这个.和..的话，在输出文件名的时候判定一下，只输出不是.和..的就行了

#### ★实战-递归遍历目录

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





### 2.4 重定向（dup和dup2）

用来做重定向，本质就是复制文件描述符：

#### dup 和 dup2：

​    `int dup(int oldfd);`   文件描述符复制。

​    oldfd: 已有文件描述符

​    返回：新文件描述符，这个描述符和oldfd指向相同内容。

  ★  `int dup2(int oldfd, int newfd);` 

​	文件描述符复制，oldfd拷贝给newfd。返回newfd 

​	失败返回-1，设置errno

一个小例子，给一个旧的文件描述符，返回一个新文件描述符：

![image-20220205102140759](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205102140759.png)

![image-20220205102252196](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205102252196.png)

dup基本就这样，后续使用也就起个保存作用。



下面讲dup2（dupto）：

下面这个例子，将一个已有文件描述符fd1复制给另一个文件描述符fd2，然后用fd2修改fd1指向的文件：

![image-20220205104321693](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205104321693.png)

![image-20220205104339477](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205104339477.png)

查看hello.c

![image-20220205104353870](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205104353870.png)

上面这个例子，fd1是打开hello.c的文件描述符，fd2是打开hello2.c的文件描述符

用dup2将fd1复制给了fd2，于是在对fd2指向的文件进行写操作时，实际上就是对fd1指向的hello.c进行写操作。

这里需要注意一个问题，由于hello.c和hello2.c都是空文件，所以直接写进去没关系。但如果hello.c是非空的，写进去的内容默认从文件头部开始写，会覆盖原有内容。

dup2也可以用于标准输入输出的重定向。

下面这个例子，将输出到STDOUT的内容重定向到文件里：

![image-20220205104521464](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205104521464.png)

![image-20220205104544030](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205104544030.png)

这个程序，将fd1的内容复制给了fd2，使得原来指向hello2.c的fd2也指向了hello.c

并通过fd2向hello.c里写入了惠惠是我老婆。完事儿将标准输出重定向至fd1，就是将要显示在标准输出的内容，写入了fd1指向的文件，就是hello.c中

这里有一点和上面程序不同，就是hello.c是处于打开状态的，连续写入两段话，写入小忍是我老婆的时候，读写指针在这句话末尾，就不会覆盖惠惠是我老婆这句话，所以，都是我老婆，没有问题的。

这里再强调一下，打开一个文件，读写指针默认在文件头，如果文件本身有内容，直接写入会覆盖原有内容。



#### fcntl 函数实现 dup：

  int fcntl(int fd, int cmd, ....)

  cmd: F_DUPFD

  参3:  被占用的，返回最小可用的。

  未被占用的， 返回=该值的文件描述符。

下面这个代码用fcntl来实现描述符的复制：

![image-20220205105700508](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205105700508.png)

对于fcntl中的参数0，这个表示文件描述符0被占用，fcntl使用文件描述符表中的最小文件描述符返回

假设不传入0，传一个7，且7未被占用，则会返回7

所以这个参数可以这样理解，你传入一个文件描述符k，如果k没被占用，则直接用k复制fd1的内容。如果k被占用，则返回描述符表中最小可用描述符，也就是自己指定一个一志愿，如果行，就返回这个。如果不行，国家给你分配一个最小的。

编译执行，如下：

 ![image-20220205110457387](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205110457387.png)                              

如图可知，原来指向hello.c的文件描述符是3，复制了一个，新的文件描述符4也指向hello.c

 

下面这个例子，用fcntl复制2次文件描述符，第一次使用默认分配，就是传0，第二次使用自己选定文件描述符复制，完事儿向文件里写入内容

 ![image-20220205110441007](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205110441007.png)

编译执行，结果如下：

 ![image-20220205110431539](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205110431539.png)

可见上述说明都是没有问题的。





## 3. 进程



### 3.1进程相关概念

#### 程序和进程

进程：

  程序：死的。编译好的二进制文件，只占用磁盘空间，不占用系统资源（cpu、内存、打开的文件、设备、锁......）    ——剧本。

  进程；活的。是一个抽象概念，运行起来的程序。占用内存、cpu等系统资源，在内存中执行。  ——戏（舞台、演员、灯光、道具......）。

同一个剧本可以在多个舞台上演——同一个程序可以加载为不同的进程（彼此之间互不影响），如：同时开两个终端，各自都有一个bash但彼此ID不同。

#### 并发

在操作系统中，一个时间段中有多个进程都处于已启动运行到运行完毕之间的状态。但，任一时刻点上仍只有一个进程在运行。

例如，我们使用计算机时可以边听音乐边聊天边上网，若笼统的将它们均看做一个进程的话，为什么可以同时运行的，就是因为并发，各个进程分时复用CPU。

![image-20220205182827981](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205182827981.png)



#### 单道程序设计

所有程序一个一个排队执行，若A阻塞，B只能等待。相当于嵌入式系统中的程序循环遍历执行（串行）。

#### 多道程序设计

相当于嵌入式系统中的实时操作系统UCOS，**时钟中断**为多到程序设计模型提供理论基础，每个时间上实际只有一个进程运行，但是各个进程运行时间极短，宏观看起来就是各个进程在同时运行。（进程就相当于嵌入式实时操作系统中的任务）

以上是单核（一个CPU）计算机实现并发的过程（嵌入式大部分都是单核），现在很多计算机都4核、8核了，其实现4、8进程以下时直接用不同CPU就可以完成并发。

#### CPU和MMU（虚拟内存映射单元）

![image-20220205184756721](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205184756721.png)

MMU（虚拟内存映射单元）：用户空间相互独立，内核空间共享（但是PCB是独立的）

MMU还会给内存空间分级，Linux系统下分为0级（内核级）和3级（用户级），Windows中分为0、1、2、3级

![image-20220205191025289](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205191025289.png)

![image-20220205190618443](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205190618443.png)





#### 进程控制块PCB

task struct结构体，用来控制一个进程。每个进程都有一个PCB控制块，用来维护进程相关的信息。

如：

**进程id（PID）**  	ps aux | 			ps aux 返回结果里，第二列是进程id

ps ajx 返回ppid、gid等

top 实时显示进程动态

kill 杀死进程

**进程状态**：初始态、就绪态、运行态、挂起态（阻塞态）、终止态。

![image-20220205195636328](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205195636328.png)

![image-20220210153809693](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220210153809693.png)

进程切换时需要保存和恢复的一些CPU寄存器

描述虚拟地址空间的信息

描述控制终端的信息  

**当前进程工作目录位置**

umask掩码 （进程的概念）——默认文件权限

**文件描述符表**

**信号相关信息资源。**

**用户id和组id**

会话（Session）和进程组

进程可以使用的资源上限

#### 进程状态 

### 3.2 环境变量

指在操作系统中用来指定操作系统运行环境的一些参数。通常具备以下特征：

①字符串（本质）	②有统一的格式：名=值[:值]	③值用来描述进程环境信息

![image-20220205200915718](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205200915718.png)

#### 常见环境变量

env 查看所有环境变量 

echo $环境变量名 查看某一环境变量

PATH		可执行文件目录位置	echo $PATH

LD_LIBRARY_PATH	动态链接器

SHELL	当前所使用的环境变量 	echo $SHELL

TERM	当前终端类型

LANG	语言和locale

HOME	当前用户主目录路径

#### getenv函数

 char \*getenv(const char \*name) 搜索 name 所指向的环境字符串，并返回相关的值给字符串。

#### setenv函数

int setenv(const char *name,const char * value,int overwrite);

函数说明 setenv()用来改变或增加环境变量的内容。参数name为环境变量名称字符串。参数 value则为变量内容，参数overwrite用来决定是否要改变已存在的环境变量。如果没有此环境变量则无论overwrite为何值均添加此环境变量。若环境变量存在，当overwrite不为0时，原内容会被改为参数value所指的变量内容；当overwrite为0时，则参数value会被忽略。返回值 执行成功则返回0，有错误发生时返回-1。

### 3.3 进程控制

#### ★fork函数

```c++
 pid_t fork(void)
```

  创建子进程。父子进程各自返回。父进程返回子进程pid， 子进程返回 0。 失败父进程返回-1，不返回子进程。

fork之后，是父进程先执行还是子进程先执行不确定，取决于内核所使用的调度算法。



![image-20220205202317032](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205202317032.png)

下面是一个fork函数的例子，代码如下：

![image-20220205203229791](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205203229791.png)

![image-20220205203244916](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205203244916.png)

关于这里为啥终端提示符和输出信息混在了一起，循环创建多个子进程（后面第二节）那一节会进行分析，现在先不用管。

fork之前的代码，父子进程都有，但是只有父进程执行了，子进程没有执行，fork之后的代码，父子进程都有机会执行。

两个函数：

pid_t getpid()    获取当前进程id

pid_t getppid()   获取当前进程的父进程id

#### getpid函数

```c++
   #include <unistd.h>

   pid_t getpid(void);
```

获取自己的进程id

#### getppid函数

```c++
   #include <unistd.h>

   pid_t getppid(void);
```

获取父进程id

#### ★使用getpid和getppid出现的问题—进程孤儿院

来个小例子，就是在上面一个fork例子里面加入这两个函数：

![image-20220205215334680](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205215334680.png)

编译运行，如下：

![image-20220205215352012](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205215352012.png)

这里，问题出现了。视频里，父进程子进程id能相互对应上，但这里没有对应上。

先看图里子进程的输出：

子进程pid=3140， 父进程pid=1630

再看图里父进程的输出：

子进程pid=3140， 自己进程pid=3139， 父进程pid=2911

这很有问题，3139作为父进程创建了3140这个子进程，然而3140这个子进程说1630是它的父进程。这里感受到了一股老王的气息。

于是，为了搞清楚这是不是个例，再运行了几次程序，结果如下：

![image-20220205215409501](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205215409501.png)

从这个图可以看到，所有父进程的子进程pid=父进程pid+1，而子进程的父进程均为1630，这个1630多次出现，显然不是偶然。

这里做出一个推测，假设**图中所有进程都是父进程先结束，导致子进程成孤儿，于是回收到孤儿院，看起来合情合理。**

修改一下代码，给父进程增加一个等待命令，这样能保证子进程完成时，父进程处于执行状态，子进程就不会成孤儿。同时，这里也解决了终端提示符和输出混在一起的问题，这个问题会在下一节分析，不用管，代码如下：

![image-20220205215434855](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205215434855.png)

编译运行，如下：

![image-20220205215456883](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205215456883.png)

2477子进程是2478,2478父进程是2477，没有问题。

错怪1630了，它不是老王。

再看，**父进程的父进程pid=2259，查看一下这是个啥**：

![image-20220205215517385](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205215517385.png)

如图，**这是bash**，其实我们写的所有进程都是bash的子进程

那么疯狂收孤儿的1630呢，如下：

![image-20220205215534247](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205215534247.png)

这里的**upstart，就是进程孤儿院**。



#### ★循环创建n个子进程

![image-20220205220350631](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205220350631.png)

所以，直接用个for循环是要出事情的，因为子进程也会fork新的进程

这里，对调用fork的进程进行判定，只让父进程fork新的进程就行，代码如下：

![image-20220205220658786](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205220658786.png)

![image-20220205220715604](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205220715604.png)

出现了问题：进程多了一个，而且不是按顺序来的。这里多出的一个，是父进程，因为父进程才有i=5跳出循环这一步。所以，对父进程进行判定并处理

修改代码如下：

![image-20220205220829216](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205220829216.png)

![image-20220205220849625](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205220849625.png)

现在还有两个问题，

一个就是包括父进程在内的所有进程**不是按顺序出现**，多运行几次，发现是随机序列出现的。这是要因为，**对操作系统而言，这几个子进程几乎是同时出现的，它们和父进程一起争夺cpu，谁抢到，谁打印，所以出现顺序是随机的**。

第二问题就是**终端提示符混在了输出里，这个是因为，loop_fork是终端的子进程，一旦loop_fork执行完，终端就会打印提示符。就像之前没有子进程的程序，一旦执行完，就出现了终端提示符。**这里也就是这个道理，l**oop_fork执行完了，终端提示符出现，然而loop_fork的子进程还没执行完，所以输出就混在一起了**。

下面通过sleep延时来解决父进程先结束这个问题。代码如下，就是给父进程加了个sleep：

![image-20220205221032663](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205221032663.png)

![image-20220205221255914](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205221255914.png)

可以看到，更改之后，父进程在所有子进程后结束，所以终端提示符最后出现。

这里和视频里有一点差异，我这里“I’m parent”是先于子进程的输出的，因为我这里是父进程在sleep之前就打印信息了，视频里是sleep之后打印。这个不是大问题，怎么写都行，因为父进程虽然在打印之前fork了子进程，照理来说子进程会和父进程抢cpu，打印顺序会乱。但是由于父进程已经处于执行状态，所以一般来说父进程一定会先于子进程打印。当然这个对于不同操作系统不太一样，万一时间片再短点，父进程在打印之前，时间片到了，子进程抢到cpu就开始打印了，那么父进程打印信息就不一定在第一位了。道理是这么个道理，**最好还是先sleep再打印吧，这样父进程一定是最后输出的**。

最后来解决子进程乱序输出的问题，解决方法很简单，让第1个子进程少等，第二个子进程多等，后面子进程等待时间依次增加，这样就能实现有序输出。

代码如下：

![image-20220205221445331](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205221445331.png)

![image-20220205221458407](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220205221458407.png)

#### getuid函数

```c++
uid_t getuid(void);
```

获取当前进程的实际用户ID

```c++
uid_t geteuid(void);
```

获取当前进程的有效用户ID

#### getgid函数

```c++
gid_t getgid(void);
```

获取当前进程的使用用户组ID

```c++
gid_t getegid(void);
```

获取当前进程的有效用户组ID

#### 进程共享

**父子进程相同：**

  刚fork后。 data段、text段、堆、栈、环境变量、全局变量、宿主目录位置、进程工作目录位置、信号处理方式

**父子进程不同：**

  进程id、返回值、各自的父进程、进程创建时间、闹钟（定时器）、未决信号集

似乎看上去是子进程复制了父进程0-3G用户空间内容，以及父进程的PCB，但pid不同，实际上每fork一个子进程都要将父进程0-3G地址空间完全拷贝一份然后再映射到物理内存吗？当然不是，父子进程之间遵循**读时共享写时复制**的原则，这样设计，无论子进程执行父进程的逻辑还是执行自己的逻辑都能节省内存开销。

**父子进程共享：**

  **读时共享、写时复制**。———————— 全局变量。

真正共享：

1. 文件描述符 2. mmap映射区（进程间通信详解）。

#### gdb调试

gdb只能跟踪一个进程。可以在fork函数调用之前，通过指令设置gdb是跟踪父进程还是子进程。默认跟踪父进程。

```gdb
设置父进程调试路径：set follow-fork-mode parent (默认)
设置子进程调试路径：set follow-fork-mode child
```

### 3.4 exec函数族

fork创建子进程后执行的是和父进程相同的程序（但有可能是不同的代码分支），子进程往往要调用一种exec函数以执行另一个程序。**当进程调用一种exec函数时，该进程的用户空间代码和数据完全被新程序替换，从新程序的启动例程开始执行。**调用exec并不创建新进程，所以调用前后该进程的id并未改变。

将当前进程的.text、.data替换为所要加载程序的.text、.data，然后让进程从新的.text第一条指令开始执行，但进程ID不变，换核不换壳。

![image-20220207113648529](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220207113648529.png)

```c++
exec函数族：

	使进程执行某一程序。成功无返回值，失败返回 -1，设置errno
    头文件：#include <unistd.h>

	int execlp(const char *file, const char *arg, ...);		借助 PATH 环境变量找寻待执行程序（常用于调用系统执行程序）

		参1： 程序名

		参2： argv0

		参3： argv1

		...： argvN

		哨兵：NULL

	int execl(const char *path, const char *arg, ...);		自己指定待执行程序路径。

	int execvp();

ps ajx --> pid ppid gid sid

```

#### ★execlp函数

```c++
	int execlp(const char *file, const char *arg, ...);		借助 PATH 环境变量找寻待执行程序，常用来调用系统程序

		参1： 程序名

		参2： argv0

		参3： argv1c++

		...： argvN

		哨兵：NULL
例：
        execlp("ls", "ls", "-l", "-h", NULL);
		execlp("date", "date", NULL);
```

#### ★execl函数

```c++
	int execl(const char *path, const char *arg, ...);		自己指定待执行c++程序路径。
例：
    execl("./a.out", "./a.out", NULL);
	execl("/bin/ls", "ls", "-l", NULL);	//也可以是系统程序，第一个参数是路径
```

#### execvp函数

加载一个进程，使用自定义环境变量env

```c++
	int execvp(const char *file, const char *argv[]);
例：
    char *argv[] = {"ls", "-l", "-h", NULL};
	execvp("ls", argv);
```

实际上与ececlp一样，只是参数形式不一样了。

#### 练习：将进程信息打印到文件中

写一个程序，使用execlp执行进程查看，并将结果输出到文件里。

要用到open, execlp, dup2

![image-20220207141311791](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220207141311791.png)

![image-20220207141321509](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220207141321509.png)

#### exec函数族特性

exec函数一旦调用成功，即执行新的程序，**不返回。只有失败才返回，错误值-1**，所以通常我们直接在exec函数调用后直接调用perror()，和exit()，无需if判断。

l(list)       命令行参数列表

p(path)       搜索file时使用path变量

v(vector)      使用命令行参数数组

e(environment)    使用环境变量数组，不适用进程原有的环境变量，设置新加载程序运行的环境变量

事实上，**只有execve是真正的系统调用，其他5个函数最终都调用execve**，是库函数，所以execve在man手册第二节，其它函数在man手册第3节。



### 3.5 回收子进程

#### 孤儿进程

**父进程先于子进程终止**，子进程沦为“孤儿进程”，会被 init 进程领养。

ps ajx 	在进程表中显示ppid、pgid、sid

#### 僵尸进程

**子进程终止，父进程尚未对子进程进行回收**，在此期 间，子进程为“僵尸进程”。 **kill 对其无效**。这里要注意，**每个进程结束后都必然会经历僵尸态**，时间长短的差别而已。

子进程终止时，子进程残留资源PCB存放于内核中，PCB记录了进程结束原因，**进程回收就是回收PCB**。回收僵尸进程，得kill它的父进程，让孤儿院去回收它。

#### ★wait函数

一个进程终止时会关闭所有文件描述符，释放在用户空间分配的内存，但它的PCB还保留着，内核在其中保存了一些信息：如果是正常终止则保存着退出状态，如果是异常终止则保存着导致该进程终止的信号是哪个。这个进程的父进程可以调用wait或者waitpid获取这些信息，然后彻底清除掉这个进程。我们知道一个进程的退出状态可以在shell中用特殊变量$？查看，因为shell是它的父进程，当它终止时，shell调用wait或者waitpid得到它的退出状态，同时彻底清除掉这个进程。

wait函数：  回收子进程退出资源， 阻塞回收任意一个。

```c++
pid_t wait(int *status) 
    
  头文件：#include <sys/wait.h>
  参数：（传出） 回收进程的状态。
  返回值：成功： 回收进程的pid
  		失败： -1， errno
  函数作用1：  阻塞等待子进程退出
  函数作用2：  清理子进程残留在内核的 pcb 资源
  函数作用3：  通过传出参数，得到子进程结束状态
获取子进程正常终止值：
     WIFEXITED(status) --》 为真 --》调用 WEXITSTATUS(status) --》 得到 子进程 退出值。

获取导致子进程异常终止信号：
	WIFSIGNALED(status) --》 为真 --》调用 WTERMSIG(status) --》 得到 导致子进程异常终止的信号编号。
获取导致子进程挂起信号：
    WIFSTOPPED(status) --》 得到 导致子进程挂起的信号编号。
获取导致子进程恢复的信号：
    WIFCONTINUED(status) --》 得到 导致子进程恢复的信号编号。
```

#### ★waitpid函数

waitpid函数： 指定某一个进程进行回收。可以设置非阻塞。     

waitpid(-1, &status, 0)  == wait(&status);

```c++
  pid_t waitpid(pid_t pid, int *status, int options)

  参数：
 	pid：指定回收某一个子进程pid
 		>0: 待回收的子进程pid
    	-1：任意子进程 
    	0：同组的所有子进程。
        <-1:指定进程组内的任意子进程
    status：（传出） 回收进程的状态。
    options：WNOHANG 指定回收方式为，非阻塞。
  返回值：
	> 0 : 表成功回收的子进程 pid
	0 : 函数调用时， 参3 指定了WNOHANG， 并且，没有子进程结束。
	-1: 失败。errno
```

**总结：一次wait/waitpid函数调用，只能回收一个子进程，且只能回收子进程。上一个例子，父进程产生了5个子进程，wait会随机回收一个，捡到哪个算哪个。若想回收多个，用while循环依次回收** 

#### 练习：父子进程回收

父进程fork3个子进程，三个子进程一个调用ps命令，一个调用自定义程序1（正常），一个调用自定义程序2（会出现段错误）。父进程使用waitpid对其子进程进行回收。

代码：

```c++
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

//父进程fork3个子进程，三个子进程一个调用ps命令，一个调用自定义程序1（正常），一个调用自定义程序2（会出现段错误）。父进程使用waitpid对其子进程进行回收。

int main(void)
{
    int i;
    pid_t pid, wpid;

    for(i = 0; i<3; i++)
     {
         if(i == 0)
         {
             pid = fork();
             if(pid == 0)
             {
                 sleep(1);
                 printf("i am %dth child, pid = %d\n", i+1, getpid());
                 execlp("ps","ps",NULL);
                 perror("exec0 error");
                 exit(1);
             }
         }
         if(i == 1)
         {
             pid = fork();
             if(pid == 0)
             {
                 sleep(2);
                 printf("i am %dth child, pid = %d\n", i+1, getpid());
                 execl("./code1", "./code1", NULL);
                 perror("exec1 error");
                 exit(1);
             } 
         }
         if(i == 2)
         {
             pid = fork();
             if(pid == 0)
             {
                 sleep(3);
                 printf("i am %dth child, pid = %d\n", i+1, getpid());
                 execl("./code2", "./code2", NULL);
                 perror("exec2 error");
                 exit(1);
             } 
         }

     }

	if(3 == i){
		// while((wpid = waitpid(-1, NULL, 0))){
		// 	printf("wait childe %d \n", wpid);	//使用阻塞方式回收子进程
		// }
        sleep(4);
		while((wpid = waitpid(-1, NULL, WNOHANG)) != -1){
			if(wpid > 0){
				printf("wait childe %d \n", wpid);	//使用非阻塞方式回收子进程
			}
		} 
    }    
    return 0;
}
```

输出：

![image-20220207213448134](/C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20220207213448134.png)





## 4. 进程间通信

### 4.1 IPC（进程间通信）方法

![image-20220207215234357](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220207215234357.png)

★进程间通信的常用方式，特征：

  管道：使用最简单 （血缘关系进程）

  FIFO：非血缘关系间	—mkfifo f1

  信号：开销最小，快

  mmap共享映射：非血缘关系进程间，最快的

  socket（本地套接字）：稳定最好，但实现最复杂 



### 4.2 管道

![image-20220207220112305](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220207220112305.png)

#### 管道的概念

管道是一种最基本的IPC机制，作用于有血缘关系的进程之间，完成数据传递。调用pipe函数就可以创建一个管道。

实现原理： 内核借助环形队列机制，使用内核缓冲区实现。

 特质：

1） 本质是一个伪文件（实为内核缓冲区）

2）有两个文件描述符引用，一个表示读端，一个表示写端

3）规定数据从管道的写端流入，读端流出。 

4） 数据在管道中，只能单向流动。 

  局限性：

1）自己写，不能自己读。 

2） 管道中的数据只能一次读取，数据不可以反复读。 

3） 半双工通信。

4）血缘关系进程间可用，即只能在有公共祖先的进程间使用管道。

#### ★pipe函数

pipe函数：  **创建，并打开管道**。

```c++
 int pipe(int fd[2]); 

  参数： fd[0]: 读端。
	    fd[1]: 写端。

  返回值： 成功： 0    失败： -1 errno
```

管道通信原理：

![image-20220207231556696](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220207231556696.png)

先在父进程创建管道，此时管道的读端和写端都是指向父进程，然后fork一个子进程，子进程中也有相同的管道，其读端和写端都指向子进程，此时去掉父进程的读端和子进程的写端，就建立了一个父进程写、子进程读的管道。

代码：

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char *argv[])
{
    int ret;
    int fd[2];
    pid_t pid;

    char *str = "hello pipe\n";
    char buf[1024];

    ret = pipe(fd);
    if (ret == -1)
        sys_err("pipe error");

    pid = fork();
    if (pid > 0) {
        close(fd[0]);       // 关闭读段
        sleep(3);
        write(fd[1], str, strlen(str));
        close(fd[1]);
    } else if (pid == 0) {
        close(fd[1]);       // 子进程关闭写段
        ret = read(fd[0], buf, sizeof(buf));
        printf("child read ret = %d\n", ret);
        write(STDOUT_FILENO, buf, ret);

        close(fd[0]);
    }
	return 0;
}
```

执行结果

```
child read ret = 11
hello pipe
```

#### ★管道的读写行为

  读管道read：

​    1）管道有数据，read返回实际读到的字节数。

​    2） 管道无数据：  

​			 ①无写端，read返回0 （类似读到文件尾）

​       	  ②有写端，read阻塞等待。 

  写管道write：

​    1） 无读端， 异常终止。 （SIGPIPE导致的） 

​    2） 有读端：  

​			 ① 管道已满， write阻塞等待 （少见）

​             ② 管道未满， write返回写出的字节个数。

#### ★练习：父子进程通过管道实现ls|wc -l 或兄弟进程实现ls|wc -l

1.父子进程实现ls|wc -l

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

//此答案是将ls通过父进程与子进程的管道从父进程传输到子进程，子进程执行wc -l
//这种方法的问题：无法保证父进程最后关闭，父进程如果早于子进程关闭，子进程会变成孤儿进程，只能依赖隐式回收，这样会造成终端早于结果输出之前刷新
//正确写法  1.是在两个子进程中实现，父进程wait回收这两个子进程
         //2.让父进程执行wc-l,子进程执行ls（已改为这个写法）

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char *argv[])
{
    int ret;
    int fd[2];
    pid_t pid;

    // char *str = "hello pipe\n";
    char buf[1024];     //读缓冲区，1024/4096都可

    ret = pipe(fd);
    if (ret == -1)
        sys_err("pipe error");

    pid = fork();
    if(pid == -1)
    {
        sys_err("pipe error");
    }

    if (pid > 0) { 
        close(fd[1]);       // 子进程关闭写段 
        dup2(fd[0], STDIN_FILENO);  //由于wc -l默认是标准输入，所以需要将标准输入重定向到读
        execlp("wc", "wc", "-l", NULL);
        close(fd[0]); 

    } else if (pid == 0) {
        //父进程中将ls写到子进程中
        close(fd[0]);       // 关闭读段
        int dup = dup2(fd[1], STDOUT_FILENO);   //由于ls是输出到标准输出，所以需要将标准输出重定向到写
        execlp("ls", "ls" ,NULL);   //直接执行ls，就会向管道写入ls命令
        close(fd[1]);

    }
	return 0;
}
```

2. 兄弟进程实现ls|wc -l

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int fd[2];
    pid_t  pid;
    int i;

    int ret = pipe(fd);
    if (ret == -1) {
        perror("pipe error:");
        exit(1);
    }

    for (i = 0; i < 2; i++){
        pid = fork();
        if (pid == -1) {
            perror("pipe error:");  //ls | wc -l
            exit(1);
        }
        if (pid == 0)
            break;
    }

    if (i == 0) {  //兄  ls 
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execlp("ls", "ls", NULL);
    } else if (i == 1) { // 弟 wc -l 
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("wc", "wc", "-l", NULL);
    } else if (i == 2) {  //父 
        close(fd[0]);
        close(fd[1]);
        for(i = 0; i < 2; i++)
            wait(NULL);
    }

    return 0;
}
```



#### 管道缓冲区大小

4096

使用ulimit -a命令查看当前系统中创建管道文件所对应的内核缓冲区大小

通常为:	pipe	(512 byetes, -p)8

也可用fpathconf函数，借助参数选项来查看，需引入头文件<unistd.h>

`long fpathconf(int fd, int name);`	成功：返回管道大小 	失败：-1，设置errno

#### 管道的优劣

优点：简单，相比信号，套接字实现进程通信，简单很多

  缺点：1.只能单向通信，双向通信需建立两个管道

​     2.只能用于有血缘关系的进程间通信。该问题后来使用fifo命名管道解决。

### 4.3 FIFO

FIFO常被成为命名管道（有名管道），常用于无血缘关系的进程间通信。

FIFO是linux的一种文件

![image-20220210161318837](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220210161318837.png)

 命令： mkfifo+文件名

函数：

```c++
#include<sys/types>
#include<sys/stat.h>
int mkfifo(const char *payhname, mode_t mode);
//成功返回0，失败返回-1，设置errno
```

下面的代码创建一个fifo：

![image-20220210162250369](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220210162250369.png)

![image-20220210162257950](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220210162257950.png)

无血缘关系进程间使用FIFO通信

  无血缘关系进程间通信：

​    读端，open fifo O_RDONLY 

​    写端，open fifo O_WRONLY

fifo操作起来像文件

FIFO实现非血缘关系进程间通信：

![image-20220219134339701](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220219134339701.png)

![image-20220219134351567](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220219134351567.png)

![image-20220219134358363](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220219134358363.png)

​                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

### 4.4 文件进程通信

打开的文件是内核中的一块缓冲区。多个无血缘关系的进程，可以同时访问该文件。

![image-20220219140249805](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220219140249805.png)

文件通信这个，有没有血缘关系都行，只是有血缘关系的进程对于同一个文件，使用的同一个文件描述符，没有血缘关系的进程，对同一个文件使用的文件描述符可能不同。这些都不是问题，打开的是同一个文件就行。



### 4.5 共享存储映射

共享内存映射是所有进程间通信的方式中最快的

#### ★存储映射IO

存储映射I/O(Memory-mapped I/O) **使一个磁盘文件（物理内存）与存储空间中的一个缓冲区（虚拟内存）相映射**。于是从缓冲区中取数据，就相当于读文件中的相应字节。与此类似，将数据存入缓冲区，则相应的字节就自动写入文件。这样，就可**在不使用read和write函数的情况下，使地址指针完成I/O操作**。

![image-20220219214906744](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220219214906744.png)

  使用这种方法，首先应该通知内核，将一个指定文件映射到存储区域中。这个映射工作可以通过**mmap函数**来实现。

```c++
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);    创建共享内存映射

  参数：
   addr：   指定映射区的首地址。通常传NULL，表示让系统自动分配
   length：共享内存映射区的大小。（<= 文件的实际大小）
   prot： 共享内存映射区的读写属性。PROT_READ、PROT_WRITE、PROT_READ|PROT_WRITE
   flags：  标注共享内存的共享属性。MAP_SHARED、MAP_PRIVATE
    		flags里面的shared意思是修改会反映到磁盘 private表示修改不反映到磁盘上
   fd: 用于创建共享内存映射区的那个文件的 文件描述符。
   offset：默认0，表示映射文件全部。偏移位置。需是 4k 的整数倍。 

  返回值：
   成功：映射区的首地址。
   失败：MAP_FAILED (void*(-1))， 设置errno
```

```c++
int munmap(void *addr, size_t length);  释放映射区。

  addr：mmap 的返回值

  length：大小
  成功返回0，失败返回-1
```

示例：

![image-20220221145001714](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220221145001714.png)

![image-20220221145014072](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220221145014072.png)

★mmap注意事项：

  \1. 用于创建映射区的文件大小为 0，实际指定非0大小创建映射区，出 “总线错误”。

  \2. 用于创建映射区的文件大小为 0，实际制定0大小创建映射区， 出 “无效参数”。

  \3. 用于创建映射区的文件读写属性为，只读。映射区属性为 读、写。 出 “无效参数”。

  \4. 创建映射区，需要read权限。当访问权限指定为 “共享”MAP_SHARED时， mmap的读写权限，应该 <=文件的open权限。  只写不行 

  \5. 文件描述符fd，在mmap创建映射区完成即可关闭。后续访问文件，用 地址访问。

  \6. offset 必须是 4096的整数倍。（MMU 映射的最小单位 4k ）

  \7. 对申请的映射区内存，不能越界访问。 

  \8. munmap用于释放的 地址，必须是mmap申请返回的地址。

  \9. 映射区访问权限为 “私有”MAP_PRIVATE, 对内存所做的所有修改，只在内存有效，不会反应到物理磁盘上。

  \10. 映射区访问权限为 “私有”MAP_PRIVATE, 只需要open文件时，有读权限，用于创建映射区即可。



mmap函数的保险调用方式：

1. fd = open（"文件名"， O_RDWR）;

2. mmap(NULL, 有效文件大小， PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);



★mmap总结：

\1. 创建映射区的过程中，隐含着一次对映射文件的读操作

\2. 当MAP_SHARED时，要求：映射区的权限应该<=文件打开的权限（出于对映射区的保护）。而MAP_PRIVATE则无所谓，因为mmap中的权限是对内存的限制

\3. 映射区的释放与文件关闭无关。只要映射建立成功，文件可以立即关闭

\4. 特别注意，当映射文件大小为0时，不能创建映射区。所以：用于映射的文件必须要有实际大小！！mmap使用时常常会出现总线错误，通常是由于共享文件存储空间大小引起的。如，400字节大小的文件，在简历映射区时，offset4096字节，则会报出总线错误

\5. munmap传入的地址一定是mmap返回的地址。坚决杜绝指针++操作

\6. 文件偏移量必须为4K的整数倍

\7. mmap创建映射区出错概率非常高，一定要检查返回值，确保映射区建立成功再进行后续操作。



#### mmap父子进程通信

父子进程使用 mmap 进程间通信：

  父进程 先 创建映射区。 open（ O_RDWR） mmap( MAP_SHARED );

  指定 MAP_SHARED 权限

  fork() 创建子进程。

  一个进程读， 另外一个进程写。

下面这段代码，父子进程mmap通信，共享内存是一个int变量：

```c++
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <sys/mman.h>  
#include <sys/wait.h>  
  
int var = 100;  
  
int main(void)  
{  
    int *p;  
    pid_t pid;  
  
    int fd;  
    fd = open("temp", O_RDWR|O_CREAT|O_TRUNC, 0644);  
    if(fd < 0){  
        perror("open error");  
        exit(1);  
    }  
    ftruncate(fd, 4);  
  
    p = (int *)mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);  
    //p = (int *)mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);  
    if(p == MAP_FAILED){        //注意:不是p == NULL  
        perror("mmap error");  
        exit(1);  
    }  
    close(fd);                  //映射区建立完毕,即可关闭文件  
  
    pid = fork();               //创建子进程  
    if(pid == 0){  
       *p = 7000;               // 写共享内存  
        var = 1000;  
        printf("child, *p = %d, var = %d\n", *p, var);  
    } else {  
        sleep(1);  
        printf("parent, *p = %d, var = %d\n", *p, var);     // 读共享内存  
        wait(NULL);  
  
        int ret = munmap(p, 4);             //释放映射区  
        if (ret == -1) {  
            perror("munmap error");  
            exit(1);  
        }  
    }  
  
    return 0;  
}  
```

编译运行：

![image-20220222141539246](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220222141539246.png)

如图，子进程修改p的值，也反映到了父进程上，这是因为共享内存定义为shared的。

如果将共享内存定义为private，运行结果如下：

![image-20220222141603767](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220222141603767.png)



#### ★mmap无血缘关系进程间通信

无血缘关系进程间 mmap 通信：       【会写】

  两个进程 打开同一个文件，创建映射区。

  指定flags 为 MAP_SHARED。

  一个进程写入，另外一个进程读出。

  【注意】：无血缘关系进程间通信。mmap：普通文件，数据可以重复读取。

​     														   fifo：管道文件，数据只能一次读取。

 

下面是两个无血缘关系的通信代码，先是写进程：

```c++
#include <stdio.h>  
#include <sys/stat.h>  
#include <sys/types.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <sys/mman.h>  
#include <string.h>  
  
struct STU {  
    int id;  
    char name[20];  
    char sex;  
};  
  
void sys_err(char *str)  
{  
    perror(str);  
    exit(1);  
}  
  
int main(int argc, char *argv[])  
{  
    int fd;  
    struct STU student = {10, "xiaoming", 'm'};  
    char *mm;  
  
    if (argc < 2) {  
        printf("./a.out file_shared\n");  
        exit(-1);  
    }  
  
    fd = open(argv[1], O_RDWR | O_CREAT, 0664);  
    ftruncate(fd, sizeof(student));  
  
    mm = mmap(NULL, sizeof(student), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);  
    if (mm == MAP_FAILED)  
        sys_err("mmap");  
  
    close(fd);  
  
    while (1) {  
        memcpy(mm, &student, sizeof(student));  
        student.id++;  
        sleep(1);  
    }  
  
    munmap(mm, sizeof(student));  
  
    return 0;  
}  
```

然后是读：

```c++
#include <stdio.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <sys/mman.h>  
#include <string.h>  
  
struct STU {  
    int id;  
    char name[20];  
    char sex;  
};  
  
void sys_err(char *str)  
{  
    perror(str);  
    exit(-1);  
}  
  
int main(int argc, char *argv[])  
{  
    int fd;  
    struct STU student;  
    struct STU *mm;  
  
    if (argc < 2) {  
        printf("./a.out file_shared\n");  
        exit(-1);  
    }  
  
    fd = open(argv[1], O_RDONLY);  
    if (fd == -1)  
        sys_err("open error");  
  
    mm = mmap(NULL, sizeof(student), PROT_READ, MAP_SHARED, fd, 0);  
    if (mm == MAP_FAILED)  
        sys_err("mmap error");  
      
    close(fd);  
  
    while (1) {  
        printf("id=%d\tname=%s\t%c\n", mm->id, mm->name, mm->sex);  
        sleep(2);  
    }  
    munmap(mm, sizeof(student));  
  
    return 0;  
}  
```

编译运行：

![image-20220222150856379](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220222150856379.png)

如图，一读一写，问题不大。

多个写端一个读端也没问题，打开多个写进程即可，完事儿读进程会读到所有写进程写入的内容。

这里要注意一个，内容被读走之后不会消失，所以如果读进程的读取时间间隔短，它会读到很多重复内容，就是因为写进程没来得及写入新内容。

#### 匿名映射

通过使用我们发现，使用映射区来完成文件读写操作十分方便，父子进程间通信也比较容易。但是缺陷是，每次创建映射区一定要依赖一个文件才能实现，通常为了建立映射区要open一个temp文件，创建好了再unlink、close掉，比较麻烦，可以直接使用匿名映射来代替。其实Linux系统给我们提供了创建匿名映射区的方法，无需依赖一个文件即可创建映射区，同样需要借助标志位参数flags来指定。

使用MAP_ANONYMOUS

匿名映射：只能用于血缘关系进程间通信。

```c++
  p = (int *)mmap(NULL, 40, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
```

## 5. 信号

### 5.1 信号的概念

#### 信号的机制

信号共性：

  简单、不能携带大量信息、满足条件才发送。

信号的特质：

  信号是软件层面上的“中断”。一旦信号产生，无论程序执行到什么位置，必须立即停止运行，处理信号，处理结束，再继续执行后续指令。

  所有信号的产生及处理全部都是由【内核】完成的。

#### 与信号相关的事件和状态

信号相关的概念：

  **产生信号**：

​    1. 按键产生 ，如：ctrl+c、ctrl+z

​    2. 系统调用产生，如：kill、raise、abort

​    3. 软件条件产生，如：定时器alarm

​    4. 硬件异常产生，如：非法访问内存（段错误）、除0、内存对齐出错（总线错误）

​    5. 命令产生，如：kill命令

  概念：

​    **未决**：产生与递达之间状态。 

​    **递达**：产生并且送达到进程。直接被内核处理掉。

​    **信号处理方式**：

​				1.执行默认处理动作

​				2.忽略

​				3.捕捉（自定义）

​	PCB进程控制块是一个结构体(task struct)，除了包含进程id、状态、工作目录、用户id、组id、文件描述符表，还包含了信号相关的信息，主要是阻塞信号集和未决信号集。

​    **阻塞信号集（信号屏蔽字）mask**： 本质：位图。用来记录信号的屏蔽状态。将某些信号设置屏蔽（阻塞），当屏蔽x信号后，再接收到该信号，该信号的处理将推后（解除屏蔽后）。**一旦被屏蔽的信号，在解除屏蔽前，一直处于未决态。**

​    **未决信号集pending**：本质：位图。用来记录信号的处理状态。该信号集中的信号，表示，**已经产生，但尚未被处理。**

​		1.信号产生，未决信号集中描述该信号的位立即翻转为1，表示信号处于未决状态，当信号被处理后对应位翻转为0，这一时刻往往非常短暂。

​		2.信号产生后由于某些原因（主要是阻塞）不能递达。这类信号的集合称之为未决信号集。在屏蔽解除前一直处于未决状态。

![image-20220225110157762](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225110157762.png)

#### 信号的编号

```
使用kill -l 命令列出所有信号
1-31号是常规信号
31-64号是实时信号
 1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
 6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3
38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8
43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13
48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12
53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7
58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2
63) SIGRTMAX-1	64) SIGRTMAX
```

#### 信号4要素

  信号使用之前，应先确定其4要素，而后再用！！！

  编号、名称、对应事件、默认处理动作。

```
Signal     Value     Action   Comment
──────────────────────────────────────────────────────────────────────
SIGHUP        1       Term    Hangup detected on controlling terminal or death of controlling process
SIGINT        2       Term    Interrupt from keyboard
SIGQUIT       3       Core    Quit from keyboard
SIGILL        4       Core    Illegal Instruction
SIGABRT       6       Core    Abort signal from abort(3)
SIGFPE        8       Core    Floating-point exception
SIGKILL       9       Term    Kill signal
SIGSEGV      11       Core    Invalid memory reference
SIGPIPE      13       Term    Broken pipe: write to pipe with no readers; see pipe(7)
SIGALRM      14       Term    Timer signal from alarm(2)
SIGTERM      15       Term    Termination signal
SIGUSR1   30,10,16    Term    User-defined signal 1
SIGUSR2   31,12,17    Term    User-defined signal 2
SIGCHLD   20,17,18    Ign     Child stopped or terminated
SIGCONT   19,18,25    Cont    Continue if stopped
SIGSTOP   17,19,23    Stop    Stop process
SIGTSTP   18,20,24    Stop    Stop typed at terminal
SIGTTIN   21,21,26    Stop    Terminal input for background process
SIGTTOU   22,22,27    Stop    Terminal output for background process
The signals SIGKILL and SIGSTOP cannot be caught, blocked, or ignored.
```

![image-20220225111157376](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225111157376.png)

#### ★Linux常规信号一览表

常用的：1、2、3、7、8、9、10、11、12、13、14、15、17

![image-20220225111251073](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225111251073.png)

![image-20220225111350489](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225111350489.png)

![image-20220225111414620](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225111414620.png)

### 5.2 信号的产生

#### 终端按键产生信号

ctrl+c		2) SIGINT(终止/中断)				”INT“—interrupt

ctrl+\		20) SIGTSTP（暂停/停止）	T—”Terminal“ 终端

ctrl+z		3) SIGQUIT(退出)

#### 硬件异常产生信号

除0 		8）SIGFPE(浮点数例外)

非法访问内存	11）SIGSEGV(段错误)

总线错误	7）SIGBUS

#### kill函数/命令产生信号

kill实际是发送信号的意思，并不是杀死的意思。

kill命令 和 kill函数：

```c++
#include<signal.h>
int kill（pid_t pid, int signum）
```

  参数：

​    pid:  > 0:发送信号给指定进程

​      = 0：发送信号给跟调用kill函数的那个进程处于同一进程组的进程。

​      < -1: 取绝对值，发送信号给该绝对值所对应的进程组的所有组员。

​      = -1：发送信号给，有权限发送的所有进程。

​    signum：待发送的信号

  返回值：

​    成功： 0

​    失败： -1 errno

小例子，子进程发送信号kill父进程：

![image-20220225113305838](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225113305838.png)

![image-20220225113311229](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225113311229.png)

这里子进程不发送kill信号，发其他信号也行，比如段错误什么的。

kill -9 -groupname 杀一个进程组

#### ★软件条件产生信号

alarm函数

alarm 函数：使用自然计时法。

 使用定时器（闹钟），在指定seconds后，内核会给当前进程发送14）SIGALRM信号，进程收到该信号，默认动作终止。

**每个进程都有且只有一个定时器。**

 定时发送SIGALRM给当前进程。

```c++
#include <unistd.h>  
unsigned int alarm(unsigned int seconds);

	seconds：定时秒数
	返回值：上次定时剩余时间。
	无错误现象。
time 命令 ： 查看程序执行时间。  实际时间 = 用户时间 + 内核时间 + 等待时间。 --》 程序运行的瓶颈在于IO，优化程序首先优化IO
```

小例子，使用alarm函数计时，打印变量i的值。

```c++
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i;
	alarm(1);

	for(i = 0; ; i++)
		printf("%d\n", i);

	return 0;
}
```



setitimer函数：

可以实现周期定时。

```c++
 int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);

  参数：

    which：  ITIMER_REAL： 采用自然计时。 ——> 14）SIGALRM，计算自然时间

      ITIMER_VIRTUAL: 采用虚拟（用户空间）计时 ---> 26）SIGVTALRM，只计算进程占用cpu的时间

      ITIMER_PROF: 采用内核+用户空间计时 ---> 27）SIGPROF，计算占用cpu及系统调用的时间

    new_value：定时秒数
          类型：struct itimerval {
               struct timeval {
                 time_t   tv_sec;     /* seconds */
                 suseconds_t tv_usec;    /* microseconds */
             }it_interval;---> 周期定时秒数，即两次定时任务之间间隔的时间

                struct timeval {
                 time_t   tv_sec;     
                 suseconds_t tv_usec;    
             }it_value; ---> 定时时长 
            };

    old_value：传出参数，上次定时剩余时间。

    e.g.：
      struct itimerval new_t; 
      struct itimerval old_t; 
      new_t.it_interval.tv_sec = 0;
      new_t.it_interval.tv_usec = 0;
      new_t.it_value.tv_sec = 1;
      new_t.it_value.tv_usec = 0;
      int ret = setitimer(&new_t, &old_t); 定时1秒

  返回值：
    成功： 0
    失败： -1 errno
```

小例子，使用setitimer定时，向屏幕打印信息：

![image-20220225144019088](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225144019088.png)

![image-20220225144024713](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225144024713.png)



第一次信息打印是两秒间隔，之后都是5秒间隔打印一次。可以理解为第一次是有个定时器，什么时候触发打印，之后就是间隔时间



其他几个发信号函数：

```c++
int raise(int sig);//给自己发

void abort(void);
```

### ★5.3 信号集操作函数

![image-20220225150434621](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225150434621.png)





#### 信号集设定

```c++
//信号集操作函数：操作阻塞信号集。通过操作阻塞信号集进而影响未决信号集。

  sigset_t set; 自定义信号集。

 int sigemptyset(sigset_t *set); //清空信号集		成功0 失败-1
 int sigfillset(sigset_t *set);  //全部置1		成功0 失败-1
 int sigaddset(sigset_t *set, int signum); //将一个信号添加到信号集中		成功0 失败-1
 int sigdelset(sigset_t *set, int signum); //将一个信号从信号集中移除		成功0 失败-1
 int sigismember(const sigset_t *set，int signum); //判断一个信号是否在集合中。 在--》1， 不在--》0
```

#### sigprocmask函数

```c++
设置信号屏蔽字和解除屏蔽：

  int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

    how:  SIG_BLOCK: 设置阻塞
          SIG_UNBLOCK: 取消阻塞
          SIG_SETMASK: 用自定义set替换mask。
    set： 自定义set 
    oldset：旧有的 mask。
```

#### sigpending函数

```c++
读取查看未决信号集：
  int sigpending(sigset_t *set);	//成功0 失败-1
    set： 传出的 未决信号集。
```



例：

```c++
#include <stdio.h>  
#include <signal.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
void sys_err(const char *str)  
{  
perror(str);  
    exit(1);  
}  
  
void print_set(sigset_t *set)  
{  
    int i;  
    for (i = 1; i<32; i++) {  
        if (sigismember(set, i))   
            putchar('1');  
        else   
            putchar('0');  
    }  
    printf("\n");  
}  
int main(int argc, char *argv[])  
{  
    sigset_t set, oldset, pedset;  
    int ret = 0;  
  
    sigemptyset(&set);  
    sigaddset(&set, SIGINT);  
    sigaddset(&set, SIGQUIT);  
    sigaddset(&set, SIGBUS);  
    sigaddset(&set, SIGKILL);  
  
    ret = sigprocmask(SIG_BLOCK, &set, &oldset);  
    if (ret == -1)  
        sys_err("sigprocmask error");  
  
    while (1) {  
        ret = sigpending(&pedset);  
        print_set(&pedset);  
        sleep(1);  
    }  
  
    return 0;  
}  
```

![image-20220225152940846](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225152940846.png)

可以看到，在输入Ctrl+C之后，进程捕捉到信号，但由于设置阻塞，没有处理，未决信号集对应位置变为1.

### ★5.4 信号捕捉

#### signal函数

**注册**一个信号捕捉函数

```c++
#include <signal.h>
typedef void (*sighandler_t)(int);	//定义一个名为sighandler_t的类型，其指针指向返回值为空，参数为int的函数。（函数指针）
sighandler_t signal(int signum, sighandler_t handler);//回调handler
//该函数由ANSI定义，由于历史原因在不同的版本的Unix和Linux中可能有不同的行为，因此应该尽量避免使用signal函数，取而代之的是sigaction函数
```

例子：

![image-20220225154715772](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225154715772.png)

![image-20220225154723795](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225154723795.png)

#### sigaction函数

**注册**一个信号捕捉函数

```c++
#include <signal.h>
int sigaction(int signum, const struct sigaction *act,
              struct sigaction *oldact);
			signum:信号编号
            act：新的处理状态
            oldact：旧有的处理状态，传出参数
 struct sigaction {
 		void     (*sa_handler)(int);//跟signal函数差不多，回调
        void     (*sa_sigaction)(int, siginfo_t *, void *);//一般不用
        sigset_t   sa_mask; //在信号捕捉函数运行期间代替mask，只工作于信号捕捉函数运行期间
        int        sa_flags;//一些设置参数
        void     (*sa_restorer)(void);	//废弃
};

                
Feature Test Macro Requirements for glibc (see feature_test_macros(7)):
    sigaction(): _POSIX_C_SOURCE
    siginfo_t: _POSIX_C_SOURCE >= 199309L

```

例子：

```c++
#include <stdio.h>  
#include <signal.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
void sys_err(const char *str)  
{  
    perror(str);  
    exit(1);  
}  
  
void sig_catch(int signo)                   // 回调函数  
{  
    if (signo == SIGINT) {  
        printf("catch you!! %d\n", signo);  
        sleep(10);  
    }  
      
    else if (signo == SIGQUIT)  
        printf("-----------catch you!! %d\n", signo);  
      
    return ;  
}  
  
int main(int argc, char *argv[])  
{  
    struct sigaction act, oldact;  
  
    act.sa_handler = sig_catch;         // set callback function name       设置回调函数  
    sigemptyset(&(act.sa_mask));        // set mask when sig_catch working. 清空sa_mask屏蔽字, 只在sig_catch工作时有效  
    //sigaddset(&act.sa_mask, SIGQUIT);  
    act.sa_flags = 0;                   // usually use.                     默认值  
      
    int ret = sigaction(SIGINT, &act, &oldact);     //注册信号捕捉函数  
    if (ret == -1)  
        sys_err("sigaction error");  
    ret = sigaction(SIGQUIT, &act, &oldact);     //注册信号捕捉函数  
  
    while (1);  
  
    return 0;  
}  
```

![image-20220225155001205](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225155001205.png)



如图，两个信号都捕捉到了，并且输出了对应字符串。

#### 信号捕捉特性

  1. 捕捉函数执行期间，信号屏蔽字 由 mask --> sa_mask , 捕捉函数执行结束。 恢复回mask

  2. 捕捉函数执行期间，本信号自动被屏蔽(sa_flgs = 0).

  3. 捕捉函数执行期间，被屏蔽信号多次发送，解除屏蔽后只处理一次！

#### 内核实现信号捕捉

![image-20220225220945462](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225220945462.png)









### 5.5 SIGCHLD信号

子进程的状态发生变化时，父进程会收到这个信号，默认动作为**忽略**这个信号。

#### SIGCHLD的产生条件

**子进程的状态发生变化**：

子进程终止时

子进程接收到SIGSTOP信号停止时

子进程处在停止态，接收到SIGCONT后唤醒时

#### ★★借助SIGCHLD信号回收子进程

```c++
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <signal.h>  
#include <sys/wait.h>  
#include <errno.h>  
#include <pthread.h>  
  
void sys_err(const char *str)  
{  
    perror(str);  
    exit(1);  
}  
  
void catch_child(int signo)  
{  
    pid_t wpid;  
  
    wpid = wait(NULL);  
    printf("-----------catch child id %d\n", wpid);  
  
    return ;  
}  
  
int main(int argc, char *argv[])  
{  
    pid_t pid;  
//阻塞  
    int i;   
    for (i = 0; i < 5; i++)  
        if ((pid = fork()) == 0)                // 创建多个子进程  
            break;  
  
    if (5 == i) {  
        struct sigaction act;  
  
        act.sa_handler = catch_child;           // 设置回调函数  
        sigemptyset(&act.sa_mask);              // 设置捕捉函数执行期间屏蔽字  
        act.sa_flags = 0;                       // 设置默认属性, 本信号自动屏蔽  
  
        sigaction(SIGCHLD, &act, NULL);         // 注册信号捕捉函数  
//解除阻塞  
  
        printf("I'm parent, pid = %d\n", getpid());  
  
        while (1);  
  
    } else {  
        printf("I'm child pid = %d\n", getpid());  
        return i;  
    }  
  
    return 0;  
}  
```

![image-20220225221934097](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220225221934097.png)

如图，只回收到1个子进程，多次执行，会发现回收到的子进程数量不是固定的。

原因分析：

  问题出在，一次回调只回收一个子进程这里。同时出现多个子进程死亡时，其中一个子进程死亡信号被捕捉，父进程去处理这个信号，此时其他子进程死亡信号发送过来，由于相同信号的不排队原则（相同信号只记录一次），就只会回收累积信号中的一个子进程。

解决方案：修改代码，回调函数中添加循环，一次回调可以回收多个子进程：

```c++
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <signal.h>  
#include <sys/wait.h>  
#include <errno.h>  
#include <pthread.h>  
  
void sys_err(const char *str)  
{  
    perror(str);  
    exit(1);  
}  
  
void catch_child(int signo)  
{  
    pid_t wpid;  
  
    while((wpid = wait(NULL)) != -1){  
        printf("-----------catch child id %d\n", wpid);  
    }  
    return ;  
}  
  
int main(int argc, char *argv[])  
{  
    pid_t pid;  
//阻塞  
    int i;   
    for (i = 0; i < 5; i++)  
        if ((pid = fork()) == 0)                // 创建多个子进程  
            break;  
  
    if (5 == i) {  
        struct sigaction act;  
  
        act.sa_handler = catch_child;           // 设置回调函数  
        sigemptyset(&act.sa_mask);              // 设置捕捉函数执行期间屏蔽字  
        act.sa_flags = 0;                       // 设置默认属性, 本信号自动屏蔽  
  
        sigaction(SIGCHLD, &act, NULL);         // 注册信号捕捉函数  
//解除阻塞  
  
        printf("I'm parent, pid = %d\n", getpid());  
  
        while (1);  
  
    } else {  
        printf("I'm child pid = %d\n", getpid());  
        return i;  
    }  
  
    return 0;  
}  
```

![image-20220226092157354](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226092157354.png)

这下就是回收了所有子进程，很强势。

  还有一个问题需要注意，这里有可能父进程还没注册完捕捉函数，子进程就死亡了，解决这个问题的方法，首先是让子进程sleep，但这个不太科学。在fork之前注册也行，但这个也不是很科学。

最科学的方法是在int i之前设置屏蔽，等父进程注册完捕捉函数再解除屏蔽。这样即使子进程先死亡了，信号也因为被屏蔽而无法到达父进程。解除屏蔽过后，父进程就能处理累积起来的信号了。



### 5.6 中断系统调用

系统调用可分为两类，慢速系统调用和其他系统调用

1）慢速系统调用：

  		可能会使进程永久阻塞的一类。如果在阻塞期间收到一个信号，该系统调用就被中断，不再继续执行(早期)，也可以设定系统调用是否重启。如read, write, pause…

2）其他系统调用：

​		getpid、getppid、fork...

/*结合pause，回顾慢速系统调用

慢速系统调用被中断的相关行为，实际上就是pause的行为，如read

​	①想中断pause，信号不能屏蔽

​	②信号的处理方式必须是捕捉（默认、忽略都不可以）

​	③中断后返回-1，设置errno为EINTR（表“被信号中断）*/

**可修改sa_flags参数来设置被信号中断后系统调用是否重启。SA_INTERRURT不重启。SA_RESTART重启。**





## 6. 守护进程、线程

### 6.1 进程组和会话

#### 概念和特性

进程是操作系统的一个核心概念。每个进程都有自己唯一的标识：进程ID，也有自己的生命周期。一个典型的进程的生命周期如图4-1所示

![image-20220226102046590](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226102046590.png)

![image-20220226102848132](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226102848132.png)

进程都有父进程，父进程也有父进程，这就形成了一个以init进程为根的家族树。除此以外，进程还有其他层次关系：进程、进程组和会话。
进程组和会话在进程之间形成了两级的层次：**进程组是一组相关进程的集合，会话是一组相关进程组的集合。**
这样说来，一个进程会有如下ID：
·PID：进程的唯一标识。对于多线程的进程而言，所有线程调用getpid函数会返回相同的值。
·PGID：进程组ID。每个进程都会有进程组ID，表示该进程所属的进程组。默认情况下新创建的进程会继承父进程的进程组ID。
·SID：会话ID。每个进程也都有会话ID。默认情况下，新创建的进程会继承父进程的会话ID。

可以调用如下指令来查看所有进程的层次关系：

```cpp
ps -ejH
ps axjf 
```

#### 创建会话

创建会话的6点注意事项：

1. 调用进程不能是进程组组长，该进程变成新会话首进程

2. 该进程成为一个新进程组的组长进程

3. 需要root权限（ubuntu不需要）

4. 新会话丢弃原有的控制终端，该会话没有控制终端（即没有与用户交互的窗口，无法与用户交互）

5. 该调用进程是组长进程，则出错返回

6. 建立新会话时，先调用fork，父进程终止，子进程调用setsid

#### getsid函数

getsid函数：获取会话id

```c++
pid_t getsid(pid_t pid)  //获取当前进程的会话id

//成功返回调用进程会话ID，失败返回-1，设置error
```

#### setsid函数

setsid函数：

```c++
pid_t setsid(void)  //创建一个会话，并以自己的ID设置进程组ID，同时也是新会话的ID

//成功返回调用进程的会话ID，失败返回-1，设置error
```

### 6.2 守护进程

守护进程：

  daemon进程。通常运行于操作系统后台，是Linux中的后台服务进程，脱离控制终端。一般不与用户直接交互。周期性的等待某个事件发生或周期性执行某一动作。通常采用以d结尾的命名方式。

  不能直接和用户交互、不受用户登录注销影响、一直在运行着。如：预读入缓输出机制的实现；ftp服务器；nfs服务器等。

  创建守护进程，最关键的一步是调用setsid函数创建一个新的Session，并成为Session Leader

#### 创建守护进程模型

守护进程创建步骤：

1. fork子进程，让父进程终止。

   所有工作在子进程中进行形式上脱离了控制终端。

2. 子进程调用 setsid() 创建新会话

   setsid()函数

   使子进程完全独立出来，脱离控制

3. 通常根据需要，改变当前工作目录位置 chdir()， 放在一个不可被卸载的目录下，防止目录被卸载。

   `int chdir(const char *path);`

4. 通常根据需要，重设umask文件权限掩码，影响新文件的创建权限，增加守护进程灵活性。 

   `mode_t umask(mode_t mask);`

   022 -- 755 0345 --- 432  r---wx-w-  422

5. 通常根据需要，关闭/重定向到dev/null 文件描述符

   继承的打开文件不会用到，浪费系统资源，无法卸载

6. 守护进程 业务逻辑。while（）

   开始执行守护进程核心工作守护进程退出处理程序模型

示例，创建守护进程：

```cpp
#include <stdio.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
void sys_err(const char *str)  
{  
    perror(str);  
    exit(1);  
}  
  
int main(int argc, char *argv[])  
{  
    pid_t pid;  
    int ret, fd;  
  
    pid = fork();  
    if (pid > 0)                // 父进程终止  
        exit(0);  
  
    pid = setsid();           //创建新会话  
    if (pid == -1)  
        sys_err("setsid error");  
  
    ret = chdir("/home/zhcode/Code/code146");       // 改变工作目录位置  
    if (ret == -1)  
        sys_err("chdir error");  
  
    umask(0022);            // 改变文件访问权限掩码  
  
    close(STDIN_FILENO);    // 关闭文件描述符 0  
  
    fd = open("/dev/null", O_RDWR);  //  fd --> 0  
    if (fd == -1)  
        sys_err("open error");  
  
    dup2(fd, STDOUT_FILENO); // 重定向 stdout和stderr  
    dup2(fd, STDERR_FILENO);  
  
    while (1);              // 模拟 守护进程业务.  
  
    return 0;  
} 
```

![image-20220226111124981](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226111124981.png)

查看进程列表:

![image-20220226111141378](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226111141378.png)

这个daemon进程就不会受到用户登录注销影响。

要想终止，就必须用kill命令

### 6.3 线程概念

#### 什么是线程

线程概念：LWP：light weight process 轻量级进程，其本质仍为进程（在linux环境下）

  进程：有独立的 进程地址空间。有独立的pcb。  分配资源的最小单位。

  线程：**有独立的pcb。没有独立的进程地址空间。** 最小的执行单位。

  ps -Lf 进程id   ---> 线程号。LWP --》cpu 执行的最小单位。

![image-20220226112625167](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226112625167.png)

![image-20220226112631663](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226112631663.png)

ps -Lf 进程号   查看进程的线程

#### Linux内核线程实现原理

![image-20220226114229203](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226114229203.png)

三级页表：进程PCB—>页目录（可看成数组，首地址位于PCB中）—>页表—>物理页面—>内存单元（下图页表页目录画反了）

![image-20220226142550541](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226142550541.png)

#### 线程共享资源

1. 文件描述符表
2. 每种信号的处理方式
3. 当前工作目录
4. 用户ID和组ID
5. 内存地址空间（.text/.data/.bss/heap/共享库）

#### 线程非共享资源

1. 线程id
2. 处理器现场（寄存器的值）和栈指针（内核栈）
3. 独立的栈空间（用户空间栈）
4. errno变量
5. 信号屏蔽字
6. 调度优先级

#### 线程优、缺点

优点：提高程序并发性、开销小、数据通信及共享数据方便

缺点：库函数，不稳定、调试编写困难、gdb不支持、对信号支持不好

### 6.4 线程控制原语

#### pthread_self函数

```cpp
#include<pthread.h>
pthread_t pthread_self(void);	获取线程id。 线程id是在进程地址空间内部，用来标识线程身份的id号，与LWP线程号不一样。
		返回值：本线程id
		
检查出错返回：  线程中。
    fprintf(stderr, "xxx error: %s\n", strerror(ret));
```



#### pthread_create函数

```cpp
int pthread_create(pthread_t *tid, const pthread_attr_t *attr, void *(*start_rountn)(void *), void *arg); 创建子线程。
		参1：传出参数，表新创建的子线程的线程id
		参2：线程属性。传NULL表使用默认属性。
		参3：子线程回调函数。创建成功，ptherad_create函数返回时，该函数会被自动调用，返回值void*，参数void*。	
		参4：参3的参数。没有的话，传NULL
		返回值：成功：0
			   失败：errno
    注意：编译的时候要加-pthread表示引入线程库
```

下面这个例子，创建一个子线程去执行其他任务： 

```cpp
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
void sys_err(const char *str){  
    perror(str);  
    exit(1);  
}  
  
void *tfn(void *arg){  
    printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());  
  
    return NULL;  
}  
  
int main(int argc, char *argv[]){  
    pthread_t tid;  
      
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());  
  
    int ret = pthread_create(&tid, NULL, tfn, NULL);  
    if (ret != 0) {  
        perror("pthread_create error");  
    }  
  
    return 0;  
}  
```

![image-20220226150656826](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226150656826.png)

可以看到，子线程的打印信息并未出现。原因在于，主线程执行完之后，就销毁了整个进程的地址空间，于是子线程就无法打印。简单粗暴的方法就是让主线程睡1秒，等子线程执行。

 代码变化如下：

![image-20220226150716210](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226150716210.png)

![image-20220226150724171](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226150724171.png)



#### ★循环创建多个子线程

下面的例子，循环创建多个子线程：

```cpp
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
void sys_err(const char *str){  
    perror(str);  
    exit(1);  
}  
  
void *tfn(void *arg){  
    int i = (int)arg;  
    sleep(i);  
    printf("--I'm %dth thread: pid = %d, tid = %lu\n",i+1, getpid(), pthread_self());  
  
    return NULL;  
}  
  
int main(int argc, char *argv[]){  
    int i;  
    int ret;  
    pthread_t tid;  
      
    for(i=0;i<5;i++){  
        ret = pthread_create(&tid, NULL, tfn, (void *)i);  
        if (ret != 0) {  
            sys_err("pthread_create error");  
        }  
    }  
    sleep(i);  
    printf("I'm main, pid = %d, tid = %lu\n", getpid(), pthread_self());  
  
    return 0;  
}  
```

![image-20220226150839063](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226150839063.png)

编译时会出现类型强转的警告，指针4字节转int的8字节，不过不存在精度损失，忽略就行。

在上述代码中，如果将i取地址后再传入线程创建函数里，就是说

当前传的是：(void *)i

改成：    (void *)&i

相应的，修改回调函数：int i = *((int *)arg)

运行代码，会出现如下结果：

![image-20220226150920255](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226150920255.png)

如果多次运行都只有主线程的输出，将主线程等待时长从i改为大于6的数即可。因为子线程等待时间i是不定的，但都小于等于6秒，由于抢cpu时没抢过主线程，导致没有子线程的输出。

错误原因在于，**子线程如果用引用传递i，会去读取主线程里的i值，而主线程里的i是动态变化的，不固定。所以，应该采用值传递，不用引用传递。**



#### pthread_exit函数

```cpp
void pthread_exit(void *retval);  退出当前线程。 
		retval：退出值。 无退出值时，NULL

各种形式退出线程的区别：
		exit();	退出当前进程。
		return: 返回到调用者那里去。
		pthread_exit(): 退出当前线程。
```

如果在回调函数里加一段代码：

```cpp
if(i == 2)
	exit(0);
```

看起来好像是退出了第三个子线程，然而运行时，发现后续的4,5也没了。这是因为，exit是退出进程。

一、修改一下，换成：

```cpp
if(i == 2)
	return NULL;
```

这样运行一下，发现后续线程不会凉凉，说明return是可以达到退出线程的目的。然而真正意义上，return是返回到函数调用者那里去，线程并没有退出。

二、再修改一下，再定义一个函数func，直接返回那种

```cpp
void *func(void){
  return NULL;
} 

if(i == 2)
	func();
```

运行，发现1,2,3,4,5线程都还在，说明没有达到退出目的。

三、再次修改：

```cpp
void *func(void){
  pthread_exit(NULL);
  return NULL;
} 

if(i == 2)
	func();
```

编译运行，发现3没了，看起来很科学的样子。pthread_exit表示将当前线程退出。放在函数里，还是直接调用，都可以。

回到之前说的一个问题，**由于主线程可能先于子线程结束，所以子线程的输出可能不会打印出来，当时是用主线程sleep等待子线程结束来解决的。现在就可以使用pthread_exit来解决了。方法就是将return 0替换为pthread_exit，只退出当先线程，不会对其他线程造成影响。**



#### pthread_join函数

```cpp
int pthread_join(pthread_t thread, void **retval);	//阻塞等待线程退出，获取线程退出状态。 回收线程。对应进程中的waitpid()
		thread: 待回收的线程id
		retval：传出参数。 回收的那个线程的退出值。
			线程异常结束，值为 -1。
		返回值：成功：0
			  失败：errno
```

**注意：兄弟线程间可以回收，即创建一个线程回收其他线程，而兄弟进程间不能回收！**

下面这个是回收线程并获取子线程返回值的小例子：

```cpp
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
struct thrd {  
    int var;  
    char str[256];  
};  
  
void sys_err(const char *str)  
{  
    perror(str);  
    exit(1);  
}  
  
void *tfn(void *arg)  
{  
    struct thrd *tval;  
  
    tval = malloc(sizeof(tval));  
    tval->var = 100;  
    strcpy(tval->str, "hello thread");  
  
    return (void *)tval;  
}  
  
int main(int argc, char *argv[])  
{  
    pthread_t tid;  
  
    struct thrd *retval;  
  
    int ret = pthread_create(&tid, NULL, tfn, NULL);  
    if (ret != 0)  
        sys_err("pthread_create error");  
  
    //int pthread_join(pthread_t thread, void **retval);  
    ret = pthread_join(tid, (void **)&retval);  
    if (ret != 0)  
        sys_err("pthread_join error");  
  
    printf("child thread exit with var= %d, str= %s\n", retval->var, retval->str);  
      
    pthread_exit(NULL);  
  
}  
```

![image-20220226151431554](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226151431554.png)

#### pthread_detach函数

实现线程分离。只有线程有这个机制，进程没有。

线程分离状态：指定该状态，线程主动与主控线程断开关系。线程结束后，其退出状态不由其他线程获取，而直接自己自动释放。**网络、多线服务器常用。**

进程若有这个机制，则将不会产生僵尸进程。僵尸进程的产生主要由于进程死后，大部分资源被释放，一点残留资源仍存于系统中，导致内核认为该进程仍存在。

也可使用pthread_create函数参2(线程属性)来设置线程分离。

```cpp
int pthread_detach(pthread_t thread);		设置线程分离
		thread: 待分离的线程id	
		返回值：成功：0
				失败：errno	
```

下面这个例子，使用detach分离线程，照理来说，分离后的线程会自动回收：

```cpp
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
  
void *tfn(void *arg)  
{  
    printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());  
  
    return NULL;  
}  
  
int main(int argc, char *argv[])  
{  
    pthread_t tid;  
  
    int ret = pthread_create(&tid, NULL, tfn, NULL);  
    if (ret != 0) {  
        perror("pthread_create error");  
    }  
    ret = pthread_detach(tid);              // 设置线程分离` 线程终止,会自动清理pcb,无需回收  
    if (ret != 0) {  
        perror("pthread_detach error");  
    }  
  
    sleep(1);  
  
    ret = pthread_join(tid, NULL);  
    printf("join ret = %d\n", ret);  
    if (ret != 0) {  
        perror("pthread_join error");  
    }  
  
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());  
  
    pthread_exit((void *)0);  
}  
```

![image-20220226210216945](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226210216945.png)

这里，问题出现了，join出错了，但是没打印错误原因。**之前的perror方法检查线程错误是有问题的。应该使用strerror**，修改代码如下：

```cpp
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
  
void *tfn(void *arg)  
{  
    printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());  
  
    return NULL;  
}  
  
int main(int argc, char *argv[])  
{  
    pthread_t tid;  
  
    int ret = pthread_create(&tid, NULL, tfn, NULL);  
    if (ret != 0) {  
        fprintf(stderr, "pthread_create error: %s\n", strerror(ret));  
        exit(1);  
    }  
    ret = pthread_detach(tid);              // 设置线程分离` 线程终止,会自动清理pcb,无需回收  
    if (ret != 0) {  
        fprintf(stderr, "pthread_detach error: %s\n", strerror(ret));  
        exit(1);  
    }  
  
    sleep(1);  
  
    ret = pthread_join(tid, NULL);  
    printf("join ret = %d\n", ret);  
    if (ret != 0) {  
        fprintf(stderr, "pthread_join error: %s\n", strerror(ret));  
        exit(1);  
    }  
  
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());  
  
    pthread_exit((void *)0);  
}  
```

编译运行结果如下：

![image-20220226210351092](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226210351092.png)



#### pthread_cancel函数

```cpp
int pthread_cancel(pthread_t thread);		杀死（取消）一个线程。  需要到达取消点（保存点）  
		thread: 待杀死的线程id
		返回值：成功：0
			   失败：errno
如果，子线程没有到达取消点， 那么 pthread_cancel 无效。
我们可以在程序中，手动添加一个取消点。使用 pthread_testcancel();
成功被 pthread_cancel() 杀死的线程，返回 -1.使用pthead_join 回收。
```

小例子，主线程调用pthread_cancel杀死子线程：

```cpp
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
  
void *tfn(void *arg){  
    while (1) {  
        printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());  
        sleep(1);  
    }  
  
    return NULL;  
}  
  
int main(int argc, char *argv[]){  
    pthread_t tid;  
  
    int ret = pthread_create(&tid, NULL, tfn, NULL);  
    if (ret != 0) {  
        fprintf(stderr, "pthread_create error:%s\n", strerror(ret));  
        exit(1);  
    }  
  
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());  
  
    sleep(5);  
  
    ret = pthread_cancel(tid);          // 终止线程  
    if (ret != 0) {  
        fprintf(stderr, "pthread_cancel error:%s\n", strerror(ret));  
        exit(1);  
    }  
  
    while (1);  
  
    pthread_exit((void *)0);  
}  
```

![image-20220226205043833](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226205043833.png)

可以看到，主线程确实kill了子线程。

这里要注意一点，**pthread_cancel工作的必要条件是进入内核，如果tfn真的奇葩到没有进入内核，则pthread_cancel不能杀死线程，此时需要手动设置取消点，就是`pthread_testcancel()`**



#### 进程、线程控制原语对比

|   线程控制原语   |    进程控制原语     |
| :--------------: | :-----------------: |
| pthread_create() |       fork()        |
|  pthread_self()  |      getpid();      |
|  pthread_exit()  | exit();    / return |
|  pthread_join()  |  wait()/waitpid()   |
| pthread_cancel() |       kill()        |
| pthread_detach() |                     |

​    

### 6.5 线程属性

![image-20220226214025471](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226214025471.png)

#### 线程属性初始化

注意：应先初始化线程属性，再pthread_create创建线程

初始化线程属性：

```cpp
int pthread_attr_init(pthread_attr_t *attr);	//成功0，失败errno
```

销毁线程属性所占用的资源：

```cpp
int pthread_attr_destroy(pthread_attr_t *attr);  	//成功0，失败errno
```

#### 线程的分离状态

```c++
设置分离属性。
	pthread_attr_t attr：  	创建一个线程属性结构体变量
	pthread_attr_init(&attr);	初始化线程属性
	pthread_attr_setdetachstate(&attr,  PTHREAD_CREATE_DETACHED);		设置线程属性为 分离态，参1为已经初始化好的线程属性结构体，参2为设置属性为PTHREAD_CREATE_DETACHED分离态（PTHREAD_CREATE_JOINABLE，非分离）
	pthread_create(&tid, &attr, tfn, NULL); 借助修改后的 设置线程属性 创建为分离态的新线程
	pthread_attr_destroy(&attr);	销毁线程属性
```

#### 线属性控制示例

调整线程状态，使线程创建出来就是分离态，代码如下：

```cpp
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
  
void *tfn(void *arg)  
{  
    printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());  
  
    return NULL;  
}  
  
int main(int argc, char *argv[])  
{  
    pthread_t tid;  
  
    pthread_attr_t attr;  
  
    int ret = pthread_attr_init(&attr);  
    if (ret != 0) {  
        fprintf(stderr, "attr_init error:%s\n", strerror(ret));  
        exit(1);  
    }  
  
    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);      // 设置线程属性为 分离属性  
    if (ret != 0) {  
        fprintf(stderr, "attr_setdetachstate error:%s\n", strerror(ret));  
        exit(1);  
    }  
  
    ret = pthread_create(&tid, &attr, tfn, NULL);  
    if (ret != 0) {  
        perror("pthread_create error");  
    }  
  
    ret = pthread_attr_destroy(&attr);  
    if (ret != 0) {  
        fprintf(stderr, "attr_destroy error:%s\n", strerror(ret));  
        exit(1);  
    }  
  
    ret = pthread_join(tid, NULL);  
    if (ret != 0) {  
        fprintf(stderr, "pthread_join error:%s\n", strerror(ret));  
        exit(1);  
    }  
  
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());  
  
    pthread_exit((void *)0);  
}  
```

![image-20220226220754888](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226220754888.png)

如图，pthread_join报错，说明线程已经自动回收，设置分离成功。



### 6.6 线程使用注意事项

![image-20220226221218926](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220226221218926.png)





## 7.  线程同步

### 7.1 同步概念

#### 线程同步

线程同步：

线程同步，指一个线程发出某一功能调用时，在没有得到结果之前，该调用不返回。同时其它线程为保证数据一致性，不能调用该功能。

即协同步调，对公共区域数据（共享数据）按序访问。防止数据混乱，产生与时间有关的错误。



![image-20220227133317627](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227133317627.png)



#### 数据混乱原因

数据混乱的原因：

1. 资源共享(独享资源则不会)

2. 调度随机(意味着数据访问会出现竞争)

3. 线程间缺乏必要同步机制

### 7.2 互斥量mutex

Linux中提供一把互斥锁mutex（也称为互斥量）。

每个线程在对资源操作前都尝试先加锁，成功加锁才能操作，操作结束解锁。

资源还是共享的，线程间也还是竞争的，但通过“锁”就将资源的访问变成互斥操作，而后与时间有关的错误也不会再产生了。

![image-20220227141512748](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227141512748.png)

![image-20220227141854267](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227141854267.png)

同一时刻，只能有一个线程持有该锁

当A线程对某个全局变量加锁访问，B在访问前尝试加锁，拿不到锁，B阻塞。C线程不去加锁而直接访问该全局变量依然能够访问，但会出现数据混乱。

所以，互斥锁实质上是操作系统提供的一把“建议锁”（又称“协同锁”），建议程序中有多线程访问共享资源的时候使用该机制。但，并没有强制限制。

因此，**即使有了mutex，如果有线程不按规则来访问数据，依然会造成数据混乱。**

因此，**所有线程【应该】在访问公共数据前先拿锁再访问。但，锁本身不具备强制性**

#### 主要应用函数

```cpp
主要应用函数：
	pthread_mutex_init		初始化函数
	pthread_mutex_destory	销毁函数
	pthread_mutex_lock		加锁函数
	pthread_mutex_trylock	尝试加锁函数
	pthread_mutex_unlock	解锁函数
 以上5个函数的返回值都是：成功返回0，失败返回错误号 

pthread_mutex_t 类型，其本质是一个结构体。为简化理解，应用时可忽略其实现细节，简单当成整数看待
pthread_mutex_t mutex；变量mutex只有两种取值：0,1
```



#### 加锁与解锁

![image-20220227143434338](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227143434338.png)

使用mutex(互斥量、互斥锁)一般步骤：

  pthread_mutex_t 类型。 

1. pthread_mutex_t lock; 创建锁
2. pthread_mutex_init; 初始化   1

3. pthread_mutex_lock;加锁   1-- --> 0

4. 访问共享数据（stdout)  

5. pthrad_mutext_unlock();解锁   0++ --> 1

6. pthead_mutex_destroy；销毁锁

```cpp
int pthread_mutex_init(pthread_mutex_t *restrict mutex, 
const pthread_mutexattr_t *restrict attr)
这里的restrict关键字，表示指针指向的内容只能通过这个指针进行修改
restrict关键字：
用来限定指针变量。被该关键字限定的指针变量所指向的内存操作，必须由本指针完成。
```

```c++
初始化互斥量：
    pthread_mutex_t mutex;
    1. pthread_mutex_init(&mutex, NULL);   			动态初始化。
    2. pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;	静态初始化。
```

#### 加锁步骤测试

```cpp
#include <stdio.h>  
#include <string.h>  
#include <pthread.h>  
#include <stdlib.h>  
#include <unistd.h>  
  
pthread_mutex_t mutex;      // 定义一把互斥锁  
  
void *tfn(void *arg)  
{  
    srand(time(NULL));  
  
    while (1) {  
        pthread_mutex_lock(&mutex);     // 加锁  
        printf("hello ");  
        sleep(rand() % 3);  // 模拟长时间操作共享资源，导致cpu易主，产生与时间有关的错误  
        printf("world\n");  
        pthread_mutex_unlock(&mutex);   // 解锁  
        sleep(rand() % 3);  
    }  
  
    return NULL;  
}  
  
int main(void)  
{  
    pthread_t tid;  
    srand(time(NULL));  
    int ret = pthread_mutex_init(&mutex, NULL);    // 初始化互斥锁  
    if(ret != 0){  
        fprintf(stderr, "mutex init error:%s\n", strerror(ret));  
        exit(1);  
    }  
  
    pthread_create(&tid, NULL, tfn, NULL);  
    while (1) {  
        pthread_mutex_lock(&mutex);     // 加锁  
        printf("HELLO ");  
        sleep(rand() % 3);  
        printf("WORLD\n");  
        pthread_mutex_unlock(&mutex);   // 解锁  
        sleep(rand() % 3);  
    }  
    pthread_join(tid, NULL);  
      
    pthread_mutex_destory(&mutex);     // 销毁互斥锁  
  
    return 0;  
}  
```

![image-20220227145358510](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227145358510.png)

可以看到，主线程和子线程在访问共享区时就没有交叉输出（打印一半被打断）的情况（若不加锁会出现主线程子线程交叉输出，即两个线程不同步访问共享资源）

注意事项：

​    **尽量保证锁的粒度， 越小越好。（访问共享数据前，加锁。访问结束【立即】解锁。）**

​    互斥锁，本质是结构体。 我们可以看成整数。 初值为 1。（pthread_mutex_init() 函数调用成功。）

​    加锁： --操作， 阻塞线程。

​    解锁： ++操作， 唤醒阻塞在锁上的线程。

​    try锁：尝试加锁，成功--。失败，返回。同时设置错误号 EBUSY

### ★7.3 死锁

【死锁】：

  是使用锁不恰当导致的现象：   

​    1. 对一个锁反复lock。第一次lock，mutex-1变为0，再次lock，因为此时mutex已经被加锁（只不过加锁的线程是自身）所以会阻塞等待加锁的线程解锁，而加锁的线程是其自身，所以会进入无限期阻塞。

   2. 两个线程，各自持有一把锁，请求另一把。如线程1有A锁，线程2有B锁，线程1请求B锁，线程2请求A锁，由于这两把锁都被对方持有，因此两个线程都被阻塞，陷入无限期等待，造成死锁。

      ![image-20220227151943091](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227151943091.png)

### 7.4 读写锁

#### 读写锁状态

读写锁：

  **锁只有一把。**以读方式给数据加锁——读锁。以写方式给数据加锁——写锁。

  **读共享，写独占。**

  **写锁优先级高。**

  相较于互斥量而言，**当读线程多的时候，提高访问效率**

#### 读写锁特性

![image-20220227154508811](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227154508811.png)

![image-20220227153249295](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227153249295.png)

#### 主要应用函数

```cpp
pthread_rwlock_t  rwlock;			读写锁
pthread_rwlock_init(&rwlock, NULL);	初始化函数
pthread_rwlock_rdlock(&rwlock);		读加锁函数
pthread_rwlock_wrlock(&rwlock);		写加锁函数
pthread_rwlock_tryrdlock(&rwlock);	读try加锁函数
pthread_rwlock_trywdlock(&rwlock);	写try加锁函数
pthread_rwlock_unlock(&rwlock);		解锁函数
pthread_rwlock_destroy(&rwlock);	销毁函数

以上函数都是成功返回0，失败返回错误号。
pthread_rwlock_t 类型	用于定义一个读写锁变量
pthread_rwlock_t	rwlock
```

#### 读写锁示例

```cpp
/* 3个线程不定时 "写" 全局资源，5个线程不定时 "读" 同一全局资源 */  
  
#include <stdio.h>  
#include <unistd.h>  
#include <pthread.h>  
  
int counter;                          //全局资源  
pthread_rwlock_t rwlock;  
  
void *th_write(void *arg)  
{  
    int t;  
    int i = (int)arg;  
  
    while (1) {  
        t = counter;                    // 保存写之前的值  
        usleep(1000);  
  
        pthread_rwlock_wrlock(&rwlock);  
        printf("=======write %d: %lu: counter=%d ++counter=%d\n", i, pthread_self(), t, ++counter);  
        pthread_rwlock_unlock(&rwlock);  
  
        usleep(9000);               // 给 r 锁提供机会  
    }  
    return NULL;  
}  
  
void *th_read(void *arg)  
{  
    int i = (int)arg;  
  
    while (1) {  
        pthread_rwlock_rdlock(&rwlock);  
        printf("----------------------------read %d: %lu: %d\n", i, pthread_self(), counter);  
        pthread_rwlock_unlock(&rwlock);  
  
        usleep(2000);                // 给写锁提供机会  
    }  
    return NULL;  
}  
  
int main(void)  
{  
    int i;  
    pthread_t tid[8];  
  
    pthread_rwlock_init(&rwlock, NULL);  
  
    for (i = 0; i < 3; i++)  
        pthread_create(&tid[i], NULL, th_write, (void *)i);  
  
    for (i = 0; i < 5; i++)  
        pthread_create(&tid[i+3], NULL, th_read, (void *)i);  
  
    for (i = 0; i < 8; i++)  
        pthread_join(tid[i], NULL);  
  
    pthread_rwlock_destroy(&rwlock);            //释放读写琐  
  
    return 0;  
}  
```

![image-20220227160457110](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227160457110.png)

程序输出飞快，随便截个图，如上图。

由于读共享，写独占。写锁优先级高。前面5个read一定先于后面的write到达的，不然write会抢到锁先进行写操作。



### 7.5 条件变量

条件变量：

 本身不是锁！ 但是通常结合锁来使用。 mutex

#### 主要应用函数

```cpp
pthread_cond_init();	//初始化
pthread_cond_destory();	//销毁
pthread_cond_wait();	//等待，阻塞等待某一条件变量满足	
pthread_cond_timedwait();//等待，等待某一条件满足，设置超时时间
pthread_cond_signal();	//通知唤醒，一次唤醒阻塞在条件变量上的（至少）一个线程
pthread_cond_broadcast();//广播通知，一次唤醒阻塞在条件变量上的所有线程

以上6个函数的返回值都是成功返回0，失败直接返回错误号

pthread_cond_t 类型，用于定义条件变量
pthread_cond_t cond; 
  初始化条件变量：
   1. pthread_cond_init(&cond, NULL);       动态初始化。
   2. pthread_cond_t cond = PTHREAD_COND_INITIALIZER;  静态初始化。
```

pthread_cond_wait()：

阻塞等待条件：

​    pthread_cond_wait(&cond, &mutex);

​    作用： 

​		1） 阻塞等待条件变量满足

​		2） 解锁已经加锁成功的信号量 （相当于 pthread_mutex_unlock(&mutex)），**12两步为一个原子操作**

​		3）当条件满足，pthread_cond_wait()函数返回时，解除阻塞并重新申请获取互斥锁。重新加锁互斥 量 （相当于， pthread_mutex_lock(&mutex);）

![image-20220227164704679](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227164704679.png)

#### ★生产者消费者条件变量

生产者消费者模型分析

![image-20220227165348336](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227165348336.png)

★代码：

```cpp 
/*借助条件变量模拟 生产者-消费者 问题*/  
#include <stdlib.h>  
#include <unistd.h>  
#include <pthread.h>  
#include <stdio.h>  
  
/*链表作为公享数据,需被互斥量保护*/  
struct msg {  
    struct msg *next;  
    int num;  
};  
  
struct msg *head;  
  
/* 静态初始化 一个条件变量 和 一个互斥量*/  
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;  
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;  
  
void *consumer(void *p)  
{  
    struct msg *mp;  
  
    for (;;) {  
        pthread_mutex_lock(&lock);  
        while (head == NULL) {           //头指针为空,说明没有节点    可以为if吗  
            pthread_cond_wait(&has_product, &lock);   // 解锁，并阻塞等待 ，当其返回时重新加锁mutex 
        }  
        mp = head;        
        head = mp->next;                 //模拟消费掉一个产品  
        pthread_mutex_unlock(&lock);  
  
        printf("-Consume %lu---%d\n", pthread_self(), mp->num);  
        free(mp);  
        sleep(rand() % 5);  
    }  
}  
  
void *producer(void *p)  
{  
    struct msg *mp;  
  
    for (;;) {  
        mp = malloc(sizeof(struct msg));  
        mp->num = rand() % 1000 + 1;        //模拟生产一个产品  
        printf("-Produce ---------------------%d\n", mp->num);  
  
        pthread_mutex_lock(&lock);  
        mp->next = head;  
        head = mp;  
        pthread_mutex_unlock(&lock);  
  
        pthread_cond_signal(&has_product);  //将等待在该条件变量上的一个线程唤醒  
        sleep(rand() % 5);  
    }  
}  
  
int main(int argc, char *argv[])  
{  
    pthread_t pid, cid;  
    srand(time(NULL));  
  
    pthread_create(&pid, NULL, producer, NULL);  
    pthread_create(&cid, NULL, consumer, NULL);  
  
    pthread_join(pid, NULL);  
    pthread_join(cid, NULL);  
  
    return 0;  
}  
```

![image-20220227170604305](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227170604305.png)

可以看到，消费者按序消费，毕竟是链表。

注意：在只有一个消费者的时候，其线程函数中的条件变量的判断用while或if都可以

```c++
for (;;) {  
        pthread_mutex_lock(&lock);  
        if/while (head == NULL) {           //头指针为空,说明没有节点 
            pthread_cond_wait(&has_product, &lock);   // 解锁，并阻塞等待 ，当其返回时重新加锁mutex   
        }  
```

但是当有多个消费者时，只能用while，原因是若用if的话，当生产者给消费者发通知时，多个消费者pthread_cond_wait()会同时接受到并解除阻塞，但是只能有一个消费者线程再加锁mutex，其他线程会阻塞在mutex的加锁中，直到该消费者线程”消费掉产品后“解锁，其他消费者线程会加锁，且直接执行下面的代码，而此时并没有产品（产品被第一个消费者线程消费掉了），会造成错误。

```c++
for (;;) {  
        pthread_mutex_lock(&lock);  
        while (head == NULL) {           //头指针为空,说明没有节点 
            pthread_cond_wait(&has_product, &lock);   // 解锁，并阻塞等待 ，当其返回时重新加锁mutex   
        } 
```

#### 条件变量的优点

### 7.6 信号量

信号量： 

  应用于线程、进程间同步。

  **相当于 初始化值为 N 的互斥量。 N值，表示可以同时访问共享数据区的线程数。**

#### 主要应用函数

```cpp
#include<semaphore.h>
函数：
    sem_t sem;	定义类型。
    int sem_init(sem_t *sem, int pshared, unsigned int value);//初始化信号量
参数：
    sem： 信号量 
    pshared：  0： 用于线程间同步
    		   1： 用于进程间同步
    value：N值。（指定同时访问的线程数）

	sem_destroy();	//销毁信号量
	sem_wait();		//一次调用，做一次-- 操作， 当信号量的值为 0 时，再次 -- 就会阻塞。 （对比 pthread_mutex_lock）
	sem_trywait();
	sem_timedwait();//注意：为绝对计时。
	sem_post();		//一次调用，做一次++ 操作，同时唤醒阻塞在信号量上的线程，当信号量的值为 N 时, 再次 ++ 就会阻塞。（对比 pthread_mutex_unlock）

以上都是成功返回0，失败返回-1，设置errno
```



#### 生产者消费者信号量模型

![image-20220227211157080](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227211157080.png)

```cpp
/*信号量实现 生产者 消费者问题*/  
  
#include <stdlib.h>  
#include <unistd.h>  
#include <pthread.h>  
#include <stdio.h>  
#include <semaphore.h>  
  
#define NUM 5                 
  
int queue[NUM];                                     //全局数组实现环形队列  
sem_t blank_number, product_number;                 //空格子信号量, 产品信号量  
  
void *producer(void *arg)  
{  
    int i = 0;  
  
    while (1) {  
        sem_wait(&blank_number);                    //生产者将空格子数--,为0则阻塞等待  
        queue[i] = rand() % 1000 + 1;               //生产一个产品  
        printf("----Produce---%d\n", queue[i]);          
        sem_post(&product_number);                  //将产品数++  
  
        i = (i+1) % NUM;                            //借助下标实现环形  
        sleep(rand()%1);  
    }  
}  
  
void *consumer(void *arg)  
{  
    int i = 0;  
  
    while (1) {  
        sem_wait(&product_number);                  //消费者将产品数--,为0则阻塞等待  
        printf("-Consume---%d\n", queue[i]);  
        queue[i] = 0;                               //消费一个产品   
        sem_post(&blank_number);                    //消费掉以后,将空格子数++  
  
        i = (i+1) % NUM;  
        sleep(rand()%3);  
    }  
}  
  
int main(int argc, char *argv[])  
{  
    pthread_t pid, cid;  
  
    sem_init(&blank_number, 0, NUM);                //初始化空格子信号量为5, 线程间共享 -- 0  
    sem_init(&product_number, 0, 0);                //产品数为0  
  
    pthread_create(&pid, NULL, producer, NULL);  
    pthread_create(&cid, NULL, consumer, NULL);  
  
    pthread_join(pid, NULL);  
    pthread_join(cid, NULL);  
  
    sem_destroy(&blank_number);  
    sem_destroy(&product_number);  
  
    return 0;  
}  
```

![image-20220227211233891](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220227211233891.png)
