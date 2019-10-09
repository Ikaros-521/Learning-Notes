一、课程介绍
    UNIX /Linux环境C语言，借助学习操作系统的接口的方式来学习、理解操作系统的运行机制以及一些网络协议。 C / C++ 数据结构和算法 
与平台无关，重点是算法逻辑 UNIX / Linux / Android / iOS 平台相关，系统接口 嵌入式 / 驱动 / 移植 硬件相关，硬件接口 环境介绍 
内存管理 文件操作 文件管理 信号处理 进程管理 进程通信 网络信息 线程同步 线程管理

 二、UNIX操作系统 
    丹尼斯·里奇、肯·汤普逊于1971左右在美国贝尔实验室，使用C语言开发了这款操作系统。 系统的特点是多用户、多任务，支持多种处理器
架构，高安全性、高可靠性、高稳定性。 既可以构建大型关键业务系统的商用服务器，也可以构建面向移动终端的、手持设备的三大衍生版本 
System V : 银行、电信在使用的服务器系统 Berkley：MacOS、iOS带界面的 Hybrid：Minix、Linux

三、Linux操作系统 
    类UNIX系统，免费开源，它指的是系统的内核，凡是使用这种内核的操作系统都叫做Linux系统（发行版），严格意义上讲
Linux指的是内核， 隶属于GNU工程。（林纳斯·托瓦兹） 手机、平板电脑、路由器、视频游戏控制台、PC、大型计算机、超级计算机。 标志是
一只企鹅，因为企鹅是南极的标志性动物，根据国际公约南极为全人类共同所有，所以Linux使用企鹅作为标志也表明：开源的Linux 为全人类共
用所有，任何公司或个人无权将其私有。 Minix操作系统是一个微型的类UNIX系统、免费开源，而Linux之父就是在参照这款操作系统，才写出了
第一个版本的Linux内核代码。 GNU工程是自由软件基金会所创立的一个开源组织，基本原则就是共享，主旨是发展出一个有别于商业UNIX的免费
且完整的类UNIX系统———— GNU Not NUIX。目前Linux内核由它进行维护，所以Linux也叫GNU Linux。 GPL通用公共许可证： 允许对某些成果及
派生成果重用、修改、复制，对所有人都是自由的，但不能声明做了原始工作，或声明由他人所做。 POSIX标准：Portable Operating System 
Interface，缩写为POSIX，统一的系统编程接口规范，它规定了操作系统以接口形式提供的功能的 名字、参数、返回值，它保障了应用程序源码
级的可移植性，而Linux完全遵循了这个标准。 
    版本管理： 
        早期版本：0 .01、0.02、...、0.09、1.0 
        旧计划：
            A.B.C 1.0 -2.6 
            A 主版本号
            B 次版本号
            C 补丁序号
        新计划：A.B.C.D.E 2.6 -
            D 构建次数
            E 描述信息
        特点：
            多用户、多任务
            遵循GNU /GPL具有开放性
            设备独立性
            丰富的网络功能
            可靠的系统安全
            良好的可移植性
            发行版：
                Debian
                Ubuntu
                Fedora
                Redhat
                CentOS

四、GUN编译器 
    1、支持众多编程语言、平台 
    2、构建过程（C代码是如何变成可执行文件的）。

        第一步，预处理.这一步处理 头文件、条件编译指令和宏定义。

        第二步，编译.将第一步产生的文件连同其他源文件一起编译成汇编代码。

        第三步，汇编。将第二步产生的汇编源码转换为 object file.

        第四步，链接.将第三步产生的一些object file 连接成一个可执行的文件。

        预处理：把程序员所编译的C代码翻译成标准的C代码
        汇编：把预处理后的C代码翻译成汇编代码
        编译：把会标代码翻译成二进制指令
        链接：把若干个目标文件合并成一个可执行文件 
    3、gcc -v 查看版本 
    4、文件后缀
        .h 头文件
        .gch 头文件的编译结果，一般不要保留。
        .c 源文件
        .i 预处理文件
        .s 汇编文件
        .o 目标文件
        .a 静态库文件
        .so 共享库文件 
    5、参数 
        -E 预处理 
        - S 汇编 
        - c 编译（只生成目标文件） 
        - o 指定编译结果的名字 
        - Wall 产生尽可能多的警告 
        - Werror 把警告当作错误处理 
        - x 指定编译的语言 
        - g 生成调试信息 
        - On 优化等级 
        - D 编译时定义宏 
        - l 连接里加库 
        - I 指定头文件的查找路径，配置环境变量 
            1、打开 vim ~ /.bashrc 
            2、在文件末尾，添加一行 export C_INCLUDE_PATH = $C_INCLUDE_PATH : NEW_PATH 
            3、重新加载配置文件 source ~ /.bashrc 注意：如果要删除环境变量需要在 ~ /.bashrc文件中删除环境变量后， 退出终端重新打开。 
    考题1： #include<> / #include "" 区别？ 
    考题2：头文件中可以编写哪些内容？ 
    考题3：头文件的作用？ 
        1、说明对应的.c文件的内容有哪些（声明函数、全局变量）。 
        2、定义结构、联合、枚举、宏 
        3、类型重定义 虽然函数可以隐式声明，但并不一定准确，而且非常有可能造成严重错误。 
    6、预处理指令
        #include 文件包含，区别 ""和 < > 的区别
        #define 定义宏常量或宏函数
            #把标识符转换成字符串
            ##合并标识符
        #undef 删除宏
        #line 指定当前行的行号
        #if
        #ifndef
        #ifdef
        #elif
        #endif
        #error 在编译期间产生错误
        #warning 在编译期间产生警告
        #pragma
        #pragma GCC dependency "文件" 用于监控文件，防止所依赖的文件，修改后而不知道
        #pragma GCC poison 标识符 用于禁用某些标识符
        #pragma pack(n) 设置结构、联合的补齐和对齐字节数
                n的值必须比默认的要小 对齐边界必须是2的较小次方
                头文件的作用是什么？ 编译时头文件找不到怎么办。

五、库 
    库就是目标文件的集合，我们把不需要升级更新维护的代码打包合并在一起方便使用，也可以对源文件进行保密。 静态库在使用时是把
被调用的代码复制到调用模块中,然后再执行程序时，静态库就不需要了。

    静态库的执行速度快，但占用空间大，当库中的内容发生变化时，需要重新编译出新的程序，因此不能轻易修改库中的内容，而共享库只是
    在调用模块中嵌入调用代码的在库的相对位置的地址, 当执行程序时，共享库会把程序一起加载到内存中， 当执行到调用共享库中代码的指
    令时跳转到共享中执行，执行完毕后再跳转回来。
    占用空间小，方便更新（共享库发生变化后，程序不需要再次编译），相对于静态库执行效率略低。

    静态库的扩展名为.a，共享库（动态库）的扩展名为.so

    当静态库和动态库同时存在，优先调用动态库，调用静态库需要在编译时加 - static

六、静态库： 
    1、创建静态库
        编写源代码：vi.c /  .h
        编译源代码：gcc -c xxx.c->xxx.o
        打开生成静态库：ar -r libxxx.a x1.o x2.o... 
        ar命令的一些参数： 
            - r 把目标文件添加到静态库中，已经存在的更新 
            - q 将目标文件追加到静态库的末尾 
            - d 从静态库中删除目标文件 
            - t 显示静态库中有哪些目标文件 
            - x 把静态库拆分成目标文件 
    2、调用静态库 直接调用：调用者要和库在同一路径下 gcc main.c libxxx.a 
        设置环境：设置方法与C_INCLUDE_PATH类似 
            1、打开vim ~ /.bashrc 文件 
            2、在文件末尾，添加一行 export LIBRARY_PATH = $LIBRARY_PATH : 库文件的路径 
            3、重新加载配置文件 source ~ /.bashrc 
            4、编译时要指定库名 gcc main.c -lmath
        设置编译参数： -L路径gcc main.c -L路径 - lmath 
    3、运行 在编译时已经把被调函数的二进制复制到可执行文件中了，在执行时不在需要静态库文件。

七、共享库 
    1、创建共享库 
        编写源代码 : vi.c /.h 编译出位置无关目标文件： gcc -c - fpic xxx.c->xxx.o 
        连接生成共享库： gcc - shared x1.o x2.o... - o libxxx.so
    2、调用共享库 
        直接调用：调用者要和库在同一路径下 gcc main.c libxxx.so 
        设置环境：设置方法与C_INCLUDE_PATH类似 
            1、打开vim ~ /.bashrc 文件 
            2、在文件末尾，添加一行 export LIBRARY_PATH = $LIBRARY_PATH : 库文件的路径 
            3、重新加载配置文件 source ~ /.bashrc 
            4、编译时要指定库名 gcc main.c -lmath设置编译参数： -L路径gcc main.c -L路径 - lmath 
    3、运行 在使用共享库时，调用者只是记录了被调代码在库的位置，因此在执行时需要共享库同时被加载。 
    操作系统会根据LD_LIBRARY_PATH环境变量的设置来加载共享库 
八、动态加载共享库
    #include <dlfcn.h>
    1、加载共享库 
        void * dlopen(const char *filename, int flag);
        filename：共享库的库名，或路径
        flag : RTLD_LAZY 使用时才加载
               RTLD_NOW 立即加载
        返回值：共享库的句柄（类似文件指针）

    2、获取标识符地址并使用 
        void *dlsym(void *handle, const char *symbol);
        handle：共享库的句柄
        symbol：标识符的名字
        返回值：标识符在共享库中的位置（地址，可以解引用，或跳转过去）。 

    3、卸载共享库 
        int dlclose(void *handle);
        handle：共享库的句柄
        返回值：成功返回0，失败返回 -1

    4、获取错误信息 char *dlerror(void);
        返回值：会把在使用共享库的过程中出现的错误，以字符串形式返回

九、辅助工具
    nm：查看目标文件、可执行文件、静态库、共享库的中的符号列表
    ldd：查看可执行程序所依赖的共享库有哪些
    strip：减肥，去除掉目标文件、可执行文件、静态库和共享库中的符号列表、调试信息。 objdump 显示二进制模块的反汇编信息

十、作业
    把链表、栈、队列、有序二叉树、查找、排序封装成算法共享库。 把之前做项目常用的函数，封装成工具共享库(libtools.so)。


































内存管理

一、错误处理
    1、通过函数返回值表示错误
        返回值合法表示成功，非法表示失败
        返回有效指针表示成功，空指针（NULL/ 表示失败0xFFFFFFFF）
        返回0表示成功，- 1表示失败 永远成功，printf
    练习1：str_len 求字符串长度，若指针为空则报错。 
    练习2：str_cpy(char *dest, size_t dlen, char *src) 字符串拷贝函数，考虑目标的溢出问题,如果目标位置无效或超出则报错。 
    练习3：intmin 求两个整数的最小值，二者相等，则报错。 
    练习4：intagv 求两个整数的平均值，该函数永远成功。

    2、通过errno表示错误
        errno是一个全局变量，它的声明在errno.h文件中，是错误的编号，它的值随时可能发生变化。 可以将它转换成有意义的字符串，
        strerror(errno) <=> perror("msg");
        注意：在函数执行成功的情况下，不会修改errno的值。 因此不能以errno的值不等于0就判断函数执行出错了。 所以通常会和函数的返回值配合，通过返回值判断是否出错，而通过perror查询出了什么类型的错误。

二、环境变量
    以字符串形式存在的，绝大多数记录的是路径信息，它表示了当前操作系统的资源配置，环境设置等相关信息。 
    1、环境变量表
        每个程序运行时，操作系统都会把所有的环境变量记录到一张表中，传给程序。 通过main函数参数获取 
        int main(int argc, char *argv[], char *environ[])
            通过声明为全局变量获取 extern char **environ

    2、环境变量函数
        char *getenv(const char *name);
        功能：根据环境变量名，获取环境变量的值

        int putenv(char *string);
        功能：以name = value形式设置环境变量，如果环境变量存在则更新，不存在则添加。 返回值：成功返回0，失败返回 - 1

        int setenv(const char *name, const char *value, int overwrite);
        功能：设置name环境变量的值为value，如果name存在且overwrite不为0则更新，否则不变。 返回值：成功返回0，失败返回 - 1

        int unsetenv(const char *name);
        功能：从环境变量表中删除name
        返回值：成功返回0，失败返回 -1

        int clearenv(void);
        功能：清空环境变量表
        操作系统记录的环境变量的数据一块特殊的存储空间，而在程序自己添加的环境变量需要自己准备存储空间。
        注意：对于环境变量的修改，只能影响自己，不能影响别人
        返回值：成功返回0，失败返回-1

    练习5、从文件中读取一个程序的配置信息
    ServerIP = 192.168.0.1
    Port = 8899
    MaxSize = 100
    ContinueSec = 3
    LogPath = /zhizhen/temp/
    DataPath = /zhizhen/data/    
    
    练习6、给LIBRARY_PATH添加一个路径(/home/zhizhen/lib)。
    LIBRARY_PATH = /home/zhizhen
    LIBRARY_PATH = /home/zhizhen:/home/zhizhen/lib

三、内存管理
    自动分配/释放内存（智能指针）  STL       调用标准C++中的new/delete
    new/delete 构造/析构         C++       标准C中的malloc/free
    malloc/free                  标准C     调用POSIX
    brk/sbrk                    POSIX      调用Linux系统接口
    mmap/munmap                 Linux      调用内核接口
    kmalloc/vmalloc             内核       调用驱动
    get_free_page               驱动       ......

四、进程映像
    程序是保存在磁盘上的可执行文件，加载到内存中被操作系统调用执行的程序叫进程（一个程序可以被同时执行多次形成身份不同的进程）。
    进程在内存空间中的分布情况叫进程映像，从低地址到高地址依次排列的是：
        代码段/只读段：
            二进制指令、字符串字面值，具有const属性且被初始化过的全局、静态变量
        数据段：被初始化过的全局变量和静态变量
        BSS段：没有初始化过的全局变量和静态变量，进程一旦加载成功就会把这段内存清理为零。
        堆：动态的分配、管理，需要程序员手动操作。从低地址向高地址扩展
        栈：非静态的局部变量，包括函数的参数、返回值
            从高地址向低地址使用，和堆内存之间存在一段空隙，
        命令行参数及环境变量表：命令行参数、环境变量

        练习7：在一个程序中打印各段内存的一个地址，然后与操作系统中的内存分配情况表比较，然后一一对应内存的分配情况。
            getpid() 可以获取进程的编号
            cat /proc/xxxx/maps
            size 程序名 查看text data bss各段的大小

五、虚拟内存
    每个进程都有各自独立的4G字节的虚拟地址空间，我们在编程时使用的永远都是这4G的虚拟地址空间中的地址，
永远无法对直接访问物理地址。

    操作系统不让程序直接访问物理内存而只能使用虚拟地址空间，一方面为了操作系统自身的安全，另一方面可以让
程序使用到比物理内存更大的地址空间（把硬盘上的特殊文件与虚拟地址空间进行映射)，操作系统动态维护。

    4G的虚拟地址空间被分为两个部分：
        0 ~ 3G    用户空间 [0,3G)
        3G ~ 4G   内核空间 [3G,4G)
        注意：用户空间的代码不能直接访问内核空间的代码和数据，但可以通过系统调用（不是函数。但以函数形式调用）
进入到内核态间接与内核交换数据。

    如果使用了没有映射过的或者访问没有权限的虚拟内存地址，就会产生段错误（非法内存访问）。

    一个进程对应一个用户空间，进程一旦切换，用户空间也会发生变化，但内核空间由操作系统管理，它不会随着进程
的切换而变化，内核空间由内核所管理的一张独立且唯一的init_mm表进行内存映射，而用户空间的表时每一个进程一张。

    注意：每个进程的内存空间完全独立，不同的进程间交换虚拟内存地址没有任何意义，所以进程之间不能直接进行通信，
需要由内核中转、协调。

    虚拟内存到物理内存的映射是以页为单位（1页=4K=4096字节）。
    malloc首次分配内存时，至少映射33页。即使通过free释放全部内存，最初映射的33页还存在

六、内存管理API
    它们都可以进行映射内存的取消映射（系统级的内存管理）。
    void *sbrk(intptr_t increment);
    increment：
        0       获取未分配前的内存首地址（也就是已经分配尾地址）
        >0      增加内存空间
        <0      释放内存空间
    返回值：未分配前的内存首地址，以字节为单位。

    int brk(void *addr);
    功能：设置未分配内存的首地址
    返回值：成功返回0，失败返回-1。

    它们都可以进行映射内存的取消映射（系统级的内存管理），它们背后维护着一个指针，该指针记录的是未分配的
内存的首地址（当前堆内存的最后一个字节的下一个位置）。
    它们都可以进行映射内存的取消映射的功能（系统级的内存管理），但为了方便起见，sbrk一般用于分配内存，brk
用于释放内存。
    注意：sbrk/brk分配和释放的都是使用权，真正的映射工作由其他系统调用完成（mmap/munmap）。
    练习8：计算1000以内的素数，存储到堆内存中，不要浪费内存（sbrk/brk）。
    练习9：使用sbrk和brk实现顺序栈，容量无限。

#include <sys/mman.h>
    void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
    功能：把虚拟内存地址与物理内存或者文件建立映射关系。
    addr:要映射的虚拟内存地址，如果为NULL操作系统会自动选择一个虚拟地址与物理内存映射。
    length:要映射的字节数
    prot：权限
    flags：映射标志
    fd：文件描述符（与内存映射没有关系）
    offset：文件映射偏移值
    返回值：映射成功后的虚拟内存地址，如果出错返回值是0xffffffff而不是NULL。

    int munmap(void *addr, size_t length);
    功能：取消映射
    addr：需要取消映射的内存首地址
    length：需要映射的字节数
    返回值：成功返回0，失败返回-1







































一、系统调用
    UNIX/Linux系统绝大部分功能都是通过系统调用实现，比如：open/close...
    UNIX/Linux把系统调用都封装成了C函数的形式，但他们不是标准C的一部分。
    标准库中的函数绝大部分时间都工作在用户态，但部分时间也需要切换到内核（进行了系统调用），比如：malloc/free/fread/fwirte
/malloc/free。
    我们自己所编写的代码也可以直接调用系统接口进入内核态（进行系统调用），比如：brk/sbrk/mmap/munmap   
    系统调用的功能代码存在于内核中，接口定义在C库中，该接口通过系统中断实现调用，而不是普通函数进行跳转。
    注意：从用户态切换到内核态或从内核态返回到用户态都会消耗时间。
    time a.out
    real    0m0.137s    总执行时间 = 用户态 + 内核态 + 切换消耗的时间
    user    0m0.092s    用户态执行时间
    sys     0m0.040s    内核态执行时间
    strace 程序 可以跟踪系统调用

二、一切皆文件
    在UNIX/Linux系统下，几乎所有资源都是以文件形式提供的，所以在UNIX/Linux系统下一切皆文件，操作系统把
它的服务、功能、设备抽象成简单的文件，提供一套简单统一的接口，这样程序就可以像访问磁盘上的文件一样访问串
口、终端、打印机、网络等功能。
    大多数情况下只需要 open/read/write/ioctl/close 就可以实现对各种设备的输入、输出、设置、控制等。
    UNIX/Linux下几乎任何对象都可以当作特殊类型的文件，可以以文件的形式访问。
    目录文件    里面记录的是一些文件信息，相关条目。
    设备文件    在系统的/dev目录下存储了所有的设置文件
        stderr  
        stdin
        stdout
    普通文件    
        连接文件
        管道文件
        socket文件

三、文件相关系统调用
    open        打开或创建文件 
    create      创建文件
    close       关闭文件
    read        读文件
    write       写文件
    lseek       设置文件读写位置
    unlink      删除连接
    remove      删除文件

四、文件描述符
    文件描述符是一个非负整数，表示一个打开的文件，由系统调用open/create/socket返回值。
    为什么使用文件描述符而不像标准库那样使用文件指针？
    因为记录文件相关信息的结构存储在内核中，为了不暴露内存的地址，因此文件结构指针不能直接给用户操作，内核
中记录一张表，其中一列是文件描述符，对应一列文件结构指针，文件描述符就相当于获取文件结构指针的下标。
    内核中已经有三个已经打开的文件描述符,它们的宏定义在：
        stdin  0    STDIN_FILENO
        stdout 1    STDOUT_FILENO
        stderr 2    STDERR_FILENO
    0,1,2 都代表的是终端

    dup 复制文件描述符

    dup2 复制指定的文件描述符

五、open/creat/close
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

    int open(const char *pathname, int flags);
    功能：打开文件
    pathname：文件的路径
    flags：打开的权限
        O_RDONLY, 只读
        O_WRONLY, 只写
        O_RDWR,   读写
        O_NOCTTY, 当打开的是终端设备文件，不要把该文件当作主控终端。 
        O_TRUNC,  清空
        O_APPEND, 追加
    返回值：成功则返回打开文件的描述符，失败则返回-1。

    int open(const char *pathname, int flags, mode_t mode);
    flags：打开的权限
        O_CREAT,  文件不存在则创建
        O_EXCL,   如果文件存在，则创建失败
    mode：设置文件的权限
        S_IRWXU  00700 user (file owner) has  read,  write  and  execute permission
        S_IRUSR  00400 user has read permission
        S_IWUSR  00200 user has write permission
        S_IXUSR  00100 user has execute permission
        S_IRWXG  00070 group has read, write and execute permission
        S_IRGRP  00040 group has read permission
        S_IWGRP  00020 group has write permission
        S_IXGRP  00010 group has execute permission
        S_IRWXO  00007 others have read, write and execute permission
        S_IROTH  00004 others have read permission
        S_IWOTH  00002 others have write permission
        S_IXOTH  00001 others have execute permission

    int close(int fd);
    功能：关闭打开的文件

六、read/write
#include <unistd.h>
    ssize_t read(int fd, void *buf, size_t count);
    功能：从文件中读取数据到内存
    fd：文件描述符，open函数的返回值
    buf：数据的存储位置
    count：读取的字节数
    返回值：成功读取到的字节数

    ssize_t write(int fd,const void *buf, size_t count);
    功能：把数据写入到文件
    fd：文件描述符，open函数的返回值
    buf：要写入的数据内存首地址
    count：要写入的字节数
    返回值：成功写入的字节数
    注意：如果把结构体以文本形式写入到文件，需要先把结构体转换成字符串
    
七、lseek
    off_t lseek(int fd, off_t o_fset, int whence);
    功能：设置文件位置指针
    返回值：文件指针的位置

    练习1：实现一个Linux系统下计算文件大小的函数，使用系统调用完成。
    练习2：实现带覆盖检查的cp命令。

八、dup/dup2
    int dup(int oldfd);
    功能：复制文件描述符，操作系统会从末的文件描述符中选择一个返回。
    oldfd:被复制的文件描述符

    int dup2(int oldfd, int newfd);
    功能：复制指定的文件描述符，如果newfd已经被使用，则先关闭，再复制。

九、标准IO与系统IO比较
    练习3：分别使用标准IO（文件读写open）比较系统IO（fopen等）随机写入1000000个整数到文件，比较哪一种更快，
为什么？
    因为标准IO使用了缓冲技术，当数据写入时并没有立即把数据交给内核，而是先存放在缓冲区中，当缓冲区满时，会
一次性把缓冲区中的数据交给内核写到文件中，这样就减少了内核态与用户态的切换次数。
    而系统IO每写一次数据就要进入一次内核态，这样就浪费了大量时间进行内核态与用户态的切换，因此用时更长
    如果为系统IO，设置更大的缓冲区，它会比标准IO更快


































一、sync/fsync/fdatasync
    1、硬盘上一般都有一些缓冲区以此来提高数据的写入效率，操作系统写入数据其实只是写入缓冲区，直到缓冲区满才
排队写入硬盘中。
    2、这种操作降低了写入的次数，但是提高了数据写入的延时，导致缓冲区中的数据与磁盘中的内容不同步。
    void sync(void);
    功能：把所有缓冲区中的数据全部同步到磁盘
    注意：只是方便（发布）将数据同步到到磁盘的命令，并不等待执行完比才返回，而是命令发布后立即返回。

    int fsync(int fd);
    功能：指定fd文件的缓冲区数据同步到磁盘，只针对一个文件，数据同步到磁盘后才返回。

    int fdatasync(int fd);
    功能：指定fd文件的缓冲区数据同步到磁盘，但仅是文件的数据并不同步文件属性，数据同步到磁盘后才返回。
二、fcntl
    int fcntl(int fd, int cmd, ... /* arg */ );
    fd：文件描述符
    cmd：操作指令，不同的操作指令决定后续参数的个数和类型。
    注意：这是个变长参数的函数

    int fcntl(int fd, int cmd, long newfd)
    cmd:F_DUPFD
    功能：复制文件描述符，与fd操作同一个文件
    返回值：如果newfd没有使用则返回newfd，如果newfd已经被占用，则返回一个不小于nuewfd的文件描述符。

    int fcntl(int fd, int cmd, void/long）
    功能：设置或获取文件描述符标志
    cmd：
        F_GETFD void
        返回值：0新进程保持打开状态，1新进程中关闭该文件描述符。
        F_SETFD long
        目前只能设置FD_CLOEXEC标志位。
    返回值：0新进程保持打开状态，1新进程中关闭该文件描述符。

    int fcntl(int fd, int cmd, void/long）
    功能：获取文件状态标志（此文件打开的权限以及打开的方式）
    cmd：
        F_GETFL void
            O_CREAT，O_EXCL，O_NOCTTY，O_TRUNC 不能获取到
            返回值：带有文件状态标志的int类型变量，需要与各标志相与得到。
        F_SETFL long
            仅能设置的有
            O_APPEND，O_ASYNC，O_DIRECT，O_NOATIME，O_NONBLOCK
            返回值：成功返回0，失败返回-1。

    int fcntl(int fd, int cmd,struct* flock)
    功能：为文件加锁，能锁整个文件，或锁一部分内容。
        一旦进程结束或文件描述符关闭，会自动解锁。
    cmd：
        F_GETLK 获取锁的信息
        F_SETLK 设置锁或解除锁
        F_SETLKW 测试锁
        注意：加锁并不能让其他进程打不开文件或不能操作，而是使用者都要遵守锁的约定，确保文件不混乱（劝诫锁）
        多进程共享文件的一种操作方式

    struct flock {
    short l_type;   /* 锁的类型: F_RDLCK, F_WRLCK, F_UNLCK */
    short l_whence; /* How to interpret l_start: SEEK_SET, SEEK_CUR, SEEK_END */
    off_t l_start;  /* 偏移值Starting offset for lock */
    off_t l_len;    /* 锁的长度Number of bytes to lock */
    pid_t l_pid;    /* 加锁的进程号 PID of process blocking our lock (F_GETLK only) */
    ...
    };

    写锁：不许写，不许看
    读锁：可以看，不许写

    读锁 与 读锁 成功
    读锁 与 写锁 失败
    写锁 与 写锁 失败

三、stat/fstat/l_stat
#include <sys/stat.h>
    功能：用来获取文件属性，返回值：成功返回0，失败返回-1
    int stat(const char *path, struct stat *buf);
    path:需要文件路径
    int fstat(int fd, struct *buf);
    fd:需要打开后的文件描述符
    int lstat(const char *path, struct stat *buf);
    path:需要文件路径，根据路径获取软链接文件信息
    stat/fstat会跟踪连接目标，而lstat不跟踪连接目标。

    struct stat {
        dev_t st_dev;         // 设备id
        ino_t st_ino;         // 节点号
        mode_t st_mode;       // 文件类型和权限
        nlink_t st_nlink;     // 硬连接数
        uid_t st_uid;         // 用户ID
        gid_t st_gid;         // 组ID
        dev_t st_rdev;        // 特殊设备ID
        off_t st_size;        // 文件的总字节数
        blksize_t st_blksize; // IO块数
        blkcnt_t st_blocks;   // 占用块（512字节）数
        time_t st_atime;      // 最后访问时间
        time_t st_mtime;      // 最后修改时间
        time_t st_ctime;      // 最后的文件属性修改时间
    };

    S_ISREG(m) 测试是否是标准文件  is it a regular file?
    S_ISDIR(m)  目录  directory?
    S_ISCHR(m)  字符设备文件 character device?
    S_ISBLK(m)  块设备文件  block device? 
    S_ISFIFO(m)  管道文件 FIFO (named pipe)?
    S_ISLNK(m)  连接文件 symbolic link? (Not in POSIX.1-1996.)
    S_ISSOCK(m) socket文件 socket?

    S_IFMT     0170000   获取文件类型出错 bit mask for the file type bit fields
    S_IFSOCK   0140000   socket文件
    S_IFLNK    0120000   软连接 symbolic link
    S_IFREG    0100000   标准文件 regular file
    S_IFBLK    0060000   块设备 block device
    S_IFDIR    0040000   目录 directory
    S_IFCHR    0020000   字符设备 character device
    S_IFIFO    0010000   管道文件 FIFO
    S_ISUID    0004000   set UID bit
    S_ISGID    0002000   set-group-ID bit (see below)
    S_ISVTX    0001000   粘滞位 sticky bit (see below)
    S_IRWXU    00700     获取权限 mask for file owner permissions
    S_IRUSR    00400     读权限 owner has read permission
    S_IWUSR    00200     写权限 owner has write permission
    S_IXUSR    00100     属主的执行权限 owner has execute permission

    S_IRWXG    00070     属主的读写执行权限 mask for group permissions
    S_IRGRP    00040     group has read permission
    S_IWGRP    00020     group has write permission
    S_IXGRP    00010     group has execute permission
    S_IRWXO    00007     mask for permissions for others (not in group)
    S_IROTH    00004     others have read permission
    S_IWOTH    00002     others have write permission
    S_IXOTH    00001     others have execute permission
    练习2：

    struct tm *localtime(const time_t *timep);
    功能：使用一个记录秒数据的变量，获取当前时间

四、access
    int access(const char *pathname, int mode);
    功能：测试当前用户对文件的访问权限，或文件是否存在
    mode:
        R_OK 是否有读权限  
        W_OK 写权限
        X_OK 执行权限
        F_OK 是否存在
    返回值：0表示有，-1表示没有

五、umask
    mode_t umask(mode_t mask);
    功能：设置并获取权限屏蔽码，功能与umask命令一样
    返回值：旧的权限屏蔽码
    注意：该权限屏蔽码只对当前进程有效,进程结束后就会变成默认的，一旦设置成功，新创建的文件
就不会具有mask中的权限。

六、chmod/fchmod
    功能:修改文件的权限，返回值：成功返回0，失败返回-1
    int chmod(const char *path,mode_t mode);
    int fchmod(int fd, mode_t mode);
    注意：它们不受权限屏蔽码的干扰

七、truncate/ftruncate
    功能：修改文件的大小，如果文件的，成功返回0，失败返回-1
    int truncate(const char *path, ooff_t length);
    int ftruncate(int fd, off_t length);

八、link/unlink/remove/rename
    int link(const char *oldpath,const char *newpath);
    功能：创建硬链接文件，硬链接指向的是文件的内存，因此当链接目标被删除后，依然可以访问文件的内容。
    int unlink(const char *pathname);
    功能：删除硬链接文件
    注意：普通文件就是硬链接数量为1的文件，当把一个文件的硬链接数删除到0个时，这个文件就被删除了。
    int remove(const char *pathname);
    功能：删除文件，该函数是标准库中的删除文件函数，底层调用了unlink系统调用。
    int remame(const char *oldpath, const char *newpath);
    功能：文件重命名

九、symlink/readlink
    int symlink(const char *oldpath, const char *new-path);
    功能：创建软链接（目录文件只能创建软链接）
    oldpath:链接目标 
    new-path:链接文件 
    返回值：成功返回0，失败返回-1
    注意：可以跨文件系统，目标文件可以不存在，也可以位于另一个文件系统中

    ssize_t readlink(const char *path, char *buf, size_t bufsiz);
    功能：读取软链接文件的内容而非链接目标（open打开软链接文件，打开的是目标文件）
    path：链接文件的路径
    buf：读取数据的存储位置
    bufsiz:读取多少个字节
    返回值：成功读取到的字节数

十、mkdir/rmdir
    int mkdir(const char *pathname, mode_t mode);
    功能：创建目录，目录一定要有执行权限，否则无法进入
    返回值：成功返回0，失败返回-1
    
    int rmdir(const char *pathname);
    功能：删除空目录（只能删除空目录）

十一、chdir/fchdir/getcwd
    char *getcwd(char *buf, size_t size);
    功能：获取当前进程的工作目录，工作目录是指当不加路径信息时，创建/打开时从那个目录下查找，工作目录默认是
程序所在的目录。

    int chdir(const char *path);
    功能：修改进程的工作目录
    返回值：成功返回0，失败返回-1

    int fchdir(int fd)
    功能：修改进程的工作目录
    fd：被open打开的目录文件的fd
    返回值：成功返回0，失败返回-1

十二、opendir/fdopendir/closedir/readdir/rewinddir/telldir/seekdir
#include <dirent.h>
#include <sys/types.h>

    DIR *opendir(const char *name);
    功能：打开一个目录流
    返回值：目录流（链表）

    DIR *fdopendir(int fd);
    功能：使用文件描述获取目录流，fd必须是目录流

    struct dirent *readdir(DIR *dirp);
    功能:从目录流中读取一个文件结点信息
    返回值：成功则返回下个目录进入点. 有错误发生或读取到目录文件尾则返回NULL.
    struct dirent {
        ino_t d_ino; /* inode number */ i节点号
        off_t d_off; /* offset to the next dirent */下一个文件结点信息的偏移量
        unsigned short d_reclen; /* length of this record */当前文件结点信息的长度
        unsigned char d_type; /* type of file; not supported by all file system types */文件类型
        char d_name[256]; /* filename */文件的名字
    };

    DT_BLK      This is a block device.
    DT_CHR      This is a character device.
    DT_DIR      This is a directory.
    DT_FIFO     This is a named pipe (FIFO).
    DT_LNK      This is a symbolic link.
    DT_REG      This is a regular file.
    DT_SOCK     This is a UNIX domain socket.
    DT_UNKNOWN  The file type is unknown.

    void rewinddir(DIR *dirp);
    功能：把目录流的位置指针调整到开头

    long telldir(DIR *dirp);
    功能：获取当前目录流的位置指针在第几个结点

    void seekdir(DIR *dirp, long offset);
    功能：调整当前目录流的位置指针
    offset:telldir(dir)的返回值

    int closedir(DIR *dirp);
    功能:关闭目录流

作业1：实现ls -l的功能，高仿
    struct passwd *getpwuid(uid_t uid);

    struct group *getgrgid(gid_t gid);

作业2：实现rm -rf的功能删除非空目录






























****信号处理****
一、信号的基本概念
    1、中断：中止（注意不是终止）当前正在执行的任务，转而执行其他任务（可能返回也可能不返回），中断分为硬件中断
（硬件设备产生的中断）和软件中断（其他程序产生的中断）。
    2、信号：是一种软件中断，提供了一种异步执行任务的机制。
    3、常见的信号
        SIGINT(2) 终端中断符信号 用户按中断键(Ctrl+C)，产生此信号，并送至前台进程组的所有进程 
        SIGQUIT(3) 终端退出符信号 用户按退出键(Ctrl+\)，产生此信号，并送至前台进程组的所有进程 
        SIGABRT(6) 异常终止信号 调用abort函数，产生此信号 
        SIGFPE(8) 算术异常信号 表示一个算术运算异常，例如除以0、浮点溢出等 
        SIGKILL(9) 终止信号 不能被捕获或忽略。常用于杀死进程 
        SIGSEGV(11) 段错误信号 试图访问未分配的内存，或向没有写权限的内存写入数据 
        SIGTSTP(20) 终端停止符信号 用户按停止键(Ctrl+Z)，产生此信号，并送至前台进程组的所有进程 
        SIGCHLD(17) 子进程状态改变信号 在一个进程终止或停止时，将此信号发送给其父进程 
        注意：在终端中执行 kill -l 可以显示出所有信号
    4、不可靠信号
        建立在早期机制上的信号被称为不可靠信号，SIGHUP（1）~SIGSYS（31）,不支持排队，可能会丢失，同一个
信号产生多次，进程可能只接收到一次。
    5、可靠信号
        采用新的机制产生的信号，SIGRTMIN（34）~SIGRTMAX（64）
        支持排队，不会丢失
    6、信号的来源
        硬件产生：除0，非法内存访问。
        这些异常是硬件（驱动）检查到，并通知内核，然后内核再向引发这些异常的进程发送相应信号。
        软件产生：通过kill/raise/alarm/setitmer/sigqueue函数产生。
    7、信号的处理
        1、忽略
        2、终止进行
        3、终止进程并产生core文件
        4、捕获信号并处理

    补充:由代码产生的信号，当信号处理函数执行完成后，会再回到产生信号的代码，如果错误没有解决，会再次触发信号。
    

二、信号的捕获
#include <signal.h>
    typedef void (*sighandler_t)(int)
    sighandler_t signal(int signum, sighandler_t handler);
    功能：信号处理注册函数
    signum：信号的编号，1~31, 也可以是宏
    handler：
        SIG_IGN 忽略该信号
        SIG_DFL 默认处理
        函数指针
    返回值：成功返回原来信号函数处理指针，或者返回SIG_IGN、SIG_DFL，失败返回SIG_ERR
    注意：在某些UNIX系统上，signal注册的函数只执行一次，执行完后就恢复成默认处理方式，如果长期使用该函数处理
信号，可以在函数结束前再注册一次。
    SIGSTOP/SIGKILL 既不能被捕获（注册），也不能被处理
    SIGTSTP 可以捕获不能处理
    SIGSTOP信号会让进程暂停，当再次受到SIGCONT信号时会继续执行。
    普通用户只能给自己的进程发送信号，而root可以给任何进程发送信号。
    练习1：实现一个“死不掉的进程”，当收到信号后，给出信号产生的原因。

三、子进程信息的处理
四、发送信号
    1、键盘
        Ctrl+c SIGINT(2)
        Ctrl+\ SIGQUIT(3)
        Ctrl+z SIGTSTP(20)
    2、错误
        除零 SIGFPE(8)
        非法访问内存 SIGSEGV(11)
    3、命令
        kill -signum pid
        终端发送ps -aux查看所有进程
    4、函数
        int kill(pid_t pid, int sig);
        功能：向指定的进程发送信号
        pid:进程id
            pid > 0 向进程号为pid的进程发送信号
            pid = 0 向同组的进程发送信号
            pid = -1 向所有（有权利发送信号的）进程发送信号
            pid < -1 向进程号为abs（pid）的进程组发送信号
        sig：信号的编号
            sig值为0时，kill不会发送信号，但会进行错误检查（检查进程号或进程组id号是否存在）。
            1<=sig&&sig<=64 发送指定信号
            sig>64 不会发送，检查非法信号

        int raise(int sig);
        功能：向当前进程发送信号   

五、暂停和休眠
    int pause(void);
    功能：一旦执行，进程就会进入无限的休眠（暂停），直到遇到信号。被信号中断返回-1。
        先执行信号处理函数才会从休眠中醒来。

    unsigned int sleep(unsigned int seconds);
    功能：休眠指定的秒数，当有信号来临时会提前醒来，提前醒来会返回剩余的秒数，或者睡够了，返回0。

六、闹钟
    unsigned int alarm(unsigned int seconds);
    功能：告诉内核在seconds秒之后，向当前进程发送SIGALRM（14）信号。进程处理时钟信号默认是终止
    返回值：如果之前设定的时间还没有到，则会重新设置（覆盖），并返回之前设置的剩余秒数。

七、信号集与信号屏蔽
    信号集：信号的集合，由128位二进制组成，每一位代表一个信号。
    int sigemptyset(sigset_t *set);
    功能：清空信号集，把所有位设置为0。

    int sigfillset(sigset_t *set);
    功能：填满信号集，把所有位设置为1。
    
    int sigaddset(sigset_t *set, int signum);
    功能：往信号集中添加一个信号。置为1
    
    int sigdelset(sigset_t *set, int signum);
    功能：从信号集中删除一个信号。置为0
    
    int sigismember(const sigset_t *set, int signum);
    功能：判断信号集中是否存在该信号。存在返回1

    信号屏蔽：当做一些特殊操作时，会希望有些信号来，而有些信号不要来，而与设置信号忽略不同的是，信号屏蔽只是暂时不来，而可以获取到
这段时间发生了哪些信号。
    每个进程都有一个信号掩码（信号集），其中包括了需要屏蔽的信号，可以通过sigprocmask函数，检查、修改进程的信号掩码。
    int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
    功能：检查、修改进程的信号掩码。
    how：
        SIG_BLOCK
            设置当前信号集与set的并集为新的信号掩码，添加。
        SIG_UNBLOCK
            新的信号掩码是当前掩码与set补集的交集，删除。
        SIG_SETMASK
            把set当作新的信号掩码，重新设置
    set：可以为空，则获取信号掩码。
    oldset：旧的信号屏蔽掩码

    int sigpending(sigset_t *set);
    功能：获取信号屏蔽期间未决（未处理）的信号，当信号屏蔽解除后就没有了。

    注意：在信号屏蔽期间发生的信号，无论多少次（不可靠信号），只能捕获一次。可靠信号依照先后顺序排队，依次排队处理

    练习2：学生信息管理系统，在保存数据和加载数据时，屏蔽Ctrl+c和Ctrl+\，等数据加载、保存完成后再处理该信号。


八、带附加信息的信号
    int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
    功能：向内核注册信号处理函数
    signum：信号编码
    act：信号处理方式
    oldact：获取到此信号旧的处理方式，可以为NULL。
    struct sigaction {
    void (*sa_handler)(int);                        // 简单的信号处理函数指针
    void (*sa_sigaction)(int, siginfo_t *, void *); // 可以带附加信息的信号处理函数指针
    sigset_t sa_mask;                               // 当执行信号处理函数时，需要屏蔽的信号
    int sa_flags;
    void (*sa_restorer)(void); // 保留，暂不使用
    }
        SA_NOCLDSTOP 当子进程暂停时，不用通知父进程
        SA_NOCLDWAIT
        SA_NODEFER 当执行信号处理函数时，不屏蔽正常的处理信号。 
        SA_ONSTACK  使用第二个函数指针
        SA_RESETHAND 表示信号只处理一次，就恢复到默认处理方式。 
        SA_RESTART 系统调用如果被signum信号中断，自行重启
        SA_SIGINFO 使用第二个函数指针处理信号
    

    int sigqueue(pid_t pid, int sig, const union sigval value);
    功能：信号发送函数，与kill不同的是可以附加一些额外数据
    pid：目标进程号
    sig：要发送的信号
    value：联合，成员可以是整数或指针。
        union sigval{
    int sival_int;
    void *sival_ptr;
        }

九、计时器
    1、系统为每个进程维护三个计时器
        ITIMER_REAL 真实计时器,程序运行的实际所用时间
        ITIMER_VIRTUAL 虚拟计时器，程序运行在用户态所消耗的时间
        ITIMER_PROF 实用计时器，程序在用户态在内核态所消耗的时间
        实际时间（真实计算器） = 用户时间（虚拟）+ 内核时间 + 睡眠时间

    int getitimer(int which, struct itimerval *curr_value);
    功能：获取当前进程的定时器
    which：选择使用哪些计时器
    curr_value:
        struct timeval it_value; 第一次触发时钟信号所需要的时间
        struct timeval it_interval; 每一次触发时钟信号所需的时间 
    int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);
    功能：给当前进程设置定时器，与alarm的区别是更精确，可以选择以那个时间段计算

    struct itimerval {
    struct timeval it_interval; /* next value */
    struct timeval it_value;    /* current value */
    };

    struct timeval {
    long tv_sec;  /* seconds */
    long tv_usec; /* microseconds */
    };

由于文件读写时为了提高效率，增加了缓冲区，所以当进行写操作时，数据中并没有立即写入文件，而好似暂时存储在缓冲区中，只有达到某些条
件时才写入文件：
    1、由写入状态切换到读取状态
    2、遇到\n符
    3、缓冲区满4k
    4、手动刷新 fflush(FILE*)
    5、文件关闭



































一、基本概念
    1、进程与程序
    程序：存储在磁盘上的文件，包含可执行指令和数据的静态实体。
    进程：运行中的程序（一个程序可以执行多次，加载出多个进程）。
        进入就是处于活动状态的计算机程序。

    2、进程的分类：
        交互进程：有输入、有输出，用户可以根据自己的情况输入数据，得到想要的结果（一般进程）
        批处理进程：由脚本加载执行的程序（Linux下的shell，Windows下的bat）。
        守护进程：总是活跃的、后台运行，一般由系统开机时加载执行或root用户手动加载执行
    3、查看进程
        简单方式：ps，显示当前用户有终端控制权的进程信息
        列表形式：ps aux，以列表形式显示详细信息
        a 所有用户的终端控制进程
        u 详细方式显示
        x 所有用户的无终端控制的进程
    4、进程的详细信息列表
        USER  进程的用户名      
        PID   进程id
        %CPU  CPU使用率
        %MEM  内存使用率  
        VSZ   占用虚拟内存的大小
        RSS   占用物理内存的大小
        TTY   有终端控制的显示终端的次设备号，如果无终端控制时显示？
        STAT  进程的状态
            O 就绪态，等待被系统调度
            R 运行态，Linux系统没有就绪态，就绪态也用R表示
            S 休眠态，可以被系统中断（信号）唤醒转入运行态
            T 暂停态，是被SIGSTOP信号暂停的，当收到SIGCONT信号时才能再转入运行态。
            Z 僵尸态，已经结束停止运行，但父进程还没有回收
            < 高优先级进程
            N 低优先级进程
            l 多线程化的进程
            + 在前台进程组中的进程
            s 会话首进程
        START TIME 进程的开始时间
        COMMAND 进程的程序名
    5、父进程与子进程，孤儿进程与僵尸进程
        一个进程A可以创建出另一个进程B，创建者叫父进程，被创建进程叫子进程，父进程启动子进程后，在操作系统的调用下父进程同时执行
（同步）。
        如果子进程先于父进程结束，会向父进程发送SIGCHLD信号，父进程收到信号后，就应该去回收子进程的相关资源，但在默认情况下，父
进程忽略该信号。
        也就是说，当子进程结束后，父进程没有回收子进程的资源，那么子进程就变成了僵尸进程。
        如果父进程先于子进程结束，子进程就变成了孤儿进程，同时被孤儿院收养（init），然后就变成了init的子进程。

二、进程标识符
    操作系统会为每个进程分配一个唯一的标识符，采用无符号整数表示，即进程ID。
    进程ID在任何时候都是唯一的，但是可以重用，当一进程结束，新创建的进程才可以使用它的进程ID（延时重用）。
    pid_t getpid(void);
    功能：获取进程ID
    pid_t getppid(void);
    功能：获取父进程ID
    uid_t getuid(void);
    功能：获取当前进程的用户ID
    uid_t getgid(void);
    功能：获取当前进程的组ID
    
    getpgid(pid)
    功能：获取pid进程的进程组ID
    setpgid(pid，pgid)
    功能：设置进程pid的进程组ID

三、fork
    pid_t fork(void)
    功能：创建一个新进程
    返回值：一次调用两次返回，失败返回-1（当进程数超出系统的限制，进程创建就会失败）。

    1、两次返回分别是进程ID和0，父进程会拿到子进程的ID，子进程返回0，借此可以分别出父子进程，编写不同的处理分支。
    2、通过fork创建的子进程就是父进程的副本（拷贝）
        子进程会获取父进程数据段、bss段、堆、栈、IO流（共享文件指针和文件描述符）、缓冲区的拷贝，与父进程共享代码段。
    3、子进程会继承父进程的信号处理方式
    4、fork函数调用后，父子进程各自进行，谁先返回不一定，但可以使用一些手法来确定谁先执行
    练习1：实现一个程序来验证，子进程会获取父进程数据段、bss段、堆、栈、IO流（共享文件指针和文件描述符）、缓冲区的拷贝。
    练习2：为一个父进程创建5个子进程，一共6个进程
    5、僵尸进程与孤儿进程的实现（如：pause）
    6、子进程和父进程是同步（并发）执行的，一般用于解决多任务。

四、进程的正常退出
    1、从main函数中return。
    2、调用标准库中的exit函数。（exit(0)相当于main函数中的return 0)
        void exit(int status)
        功能：调用者立即结束该进程。
        status：退出状态码，可以在父进程中获取到，子进程留给父进程的遗言。
        退出前做的事情：
        1）先调用事先注册的函数的（通过atexit/on_exit）。
            int on_exit(void (*function)(int , void *), void *arg);
            功能：注册一个函数，当进程通过exit函数开始结束时调用
            function：函数指针，无返回值，参数1为exit函数的菜蔬，参数2为on_exit函数的第二个参数
            arg：当function函数被调用时传递给它的第二参数
            
            int atexit(void (*function)(void));
            功能：注册一个函数，当进程通过exit函数结束时调用。
            function：函数指针，无返回值无参数
            
        2）冲刷所有处在未关闭状态的标准IO流
        3）返回一整数/宏常量（EXIT_SUCCESS  0/EXIT_FAILURE  1）给操作系统
        4）该函数不会返回，它的功能实现借助了_exit/_Exit
    3、调用_exit/_Exit函数退出
        注意：这两个函数的功能是一样的
#include <unistd.h>
        void _exit(int status);
#include <stdlib.h>
        void _Exit(int status);//调用系统的_exit
        功能：调用的进程会结束，没有返回值。
        status：会被父进程获取到（低八位，一个字节）
        1）进程结束前会关闭所有处于打开状态的文件描述符。
        2）把所有子进程托付给孤儿院（init）
        3）向它的父进程发送SIGCHLD信号。
        注意：exit函数也会执行以上操作，因此它底层调用了_exit/_Exit。
    4、进程的最后一个线程执行最后一条语句。
    5、进程的最后一个线程调用了pthread_exit函数。

五、进程的异常退出
    1、调用了abort函数，该函数会产生SIGABRT信号。
    2、进程接收到一些信号（没有捕获处理，或无法捕获处理）
    3、进程的最后一线程收到“取消”请求，并做出响应，相当于线程收到了结束“信号”。

六、wait/waitpid
    pid_t wait(int *status);
    功能：等待所有子进程结束，并获取到最终的状态码，只要有一个进程结束就立即返回。
    1、应该是父进程收到子进程发送来的SIGCHLD信号时，调用wait函数回收子进程的资源并获取结束状态。
    2、如果所有子进程都在运行，则wait阻塞。
    3、如果已有僵尸进程，wait也会立即返回，回收资源获取结束状态码。
    4、如果没有子进程，则返回失败-1。

    pid_t waitpid(pid_t pid,int *status, int options);
    功能：等待指定的进程结束，并获取到最终的状态码。
    pid:
        <-1 等待的是进程组id是pid的绝对值中的任一子进程结束，此时等待的是整个进程组。
        =-1 等待任一子进程结束，此时与wait等价
        =0 等待同组的任一子进程结束，此时等待的是整个进程组
        >0 等待进程号为pid的进程结束，此时只等待一个进程结束
    options:
        WNOHANG 非阻塞模式，如果没有子进程结束则立即退出
        WUNTRACED 如果子进程处于暂停，则返回它的状态
        WCONTINUED 如果子进程从暂停转为继续，则返回它的状态
    1、wait函数只能孤独的等待子进程结束，而waitpid可以有更多的选择。
    2、waitpid不光可以等待子进程，也可以等待同组进程。
    3、waitpid可以阻塞也可以不阻塞。
    4、也可以监控子进程的暂停或结束状态。

七、vfork
    pid_t vfork(void)
    功能：与fork的功能基本一致
    区别：通过vfork创建的进程不复制父进程的地址空间（数据段，bss段、堆、栈、IO流、缓冲区的拷贝），必须通过excl系列函数加载自己
的可执行程序。
    注意：先返回的是子进程，子进程先返回，此时它占用了父进程的地址空间，当子进程成功创建后（通过excl加载可执行程序），父进程才
返回。

八、exec
    功能：加载子进程的可执行文件。
    int execl(const char *path, const char *arg, ...);
    path：可执行文件的路径
    arg：第一个main函数的参数，最后一次必须以NULL结尾。

    int execlp(const char *file, const char *arg, ...);
    file：可执行文件的名字，会从PATH环境变量的路径中查找可执行文件并执行。
    arg：第一个main函数的参数，最后一次必须以NULL结尾。

    int execle(const char *path, const char *arg, ..., char * const envp[]);
    file：可执行文件的名字，会从PATH环境变量的路径中查找可执行文件并执行。
    arg：第一个main函数的参数，最后一次必须以NULL结尾。
    envp：父进程的环境变量表，传递给子进程。

    int execv(const char *path, char *const argv[]);
    int execvp(const char *file, char *const argv[]);
    int execvpe(const char *file, char *const argv[],  char *const envp[]);

九、system
    int system(const char *command)
    功能：执行系统命令的，也可以加载可执行程序。
        相当于创建一个子进程，但子进程不结束，该函数不返回，父子进程不会同时执行。
    该函数的实现应该调用了：vfork、exec、wait等函数

十、进程组
    进程组：是由一个或多个进程的集合，每个进程除有一个进程ID还有一个进程组ID，进程组中的进程归属同一个作业控制（负责完成同一个任务）。
    同一进程组的进程，会统一接收到终端的信号，由fork创建的子进程，默认就加入了父进程的进程组。
    每个进程都有一个组长，组长的进程ID就是组ID
    int setpgid(pid_t pid, pid_t pgid);
    功能：设置pid进程的进程组，就相当于加入pgid的进程组，pgid就是它的组长

    pid_t getpgid(pid_t pid);
    功能：获取pid进程的进程组ID

作业：实现system函数的功能
































一、基本概念
    什么叫进程间通信（IPC，Interprocess communication）：是指两个人或多个进程之间交换数据的过程叫进程间通信。
    进程之间为什么需要通信？
    当需要多个进程协同工作高效率完成任务时，因为每个进程都是个独立的个体（资源单位），进程之间就需要进行通信。
    进程间通信方式：
        1、简单进程间通信：命令行参数，环境变量表、信号、文件
        2、传统进程间通信：管道
        3、XSI进程间通信：共享内存、消息队列、信号量
        4、网络进程间通信：socket

二、传统的进程通信
    管道是UNIX系统最古老的进程间通信方式（基本不再使用），历史上的管道通常是半双工（只允许单向数据流动），现在的系统大都可以全双工，
数据可以双向流动。

    1、有名管道（创建实体文件）
        命令：mkfifo
        函数：int mkfifo(const char *pathname, mode_t mode);
        功能：创建管道文件
        pathname：文件路径
        mode：权限
        返回值：成功返回0，失败返回-1

        编程模型：
        进程A                   进程B
        创建管道（mkfifo）       。。。
        打开管道（open）         打开管道
        读/写数据（read/write）  读/写数据
        关闭管道（close）        关闭管道
        删除管道（unlink）       。。。

    2、无名管道（用于通过fork创建的父子进程间的通信）
    int pipe(int pipefd[2]);
    功能：创建无名管道
    pipefd: 用来存储内核返回的文件描述符
        pipefd[0]: 读操作
        pipefd[1]: 写操作

三、XSI进程间通信
    X/open组织为UNIX系统设计的一套进程间通信机制，有共享内存、消息队列、信号量。
    1、IPC标识
        内核会为每个进程间通信维护一个IPC对象（XSI对象）。
        该对象通过一个非负整数来引用（类似于文件描述符）。
        与文件描述符不同的是，每用一个IPC对象标识符就持续+1，达到最大值时再从零开始。
        IPC标识需要程序员自己创建（类似于创建文件）。
    2、IPC键值
        创建IPC键值的依据（类似创建文件的文件名），也是一个非负整数。
        1、自定义（不建议，可能会冲突）。
        2、自动生成（项目路径，项目编号）。
        key_t ftok(const char *pathname, int proj_id);
        注意：项目路径一定要是有效路径，生成IPC键值依靠的是路径而不是字符串。
    3、IPC对象的创建
        IPC_PRIVATE  创建IPC对象时永远创建成功
        IPC_CREAT    对象存在则获取，不存在则创建
        IPC_EXCL     如果对象已经创建，则创建失败。
    4、IPC对象销毁/控制用到的宏
        IPC_STAT    获取IPC对象的属性
        IPC_SET     设置IPC对象的属性
        IPC_RMID    删除IPC对象

四、共享内存
    共享内存就是内核中开辟一块内存由IPC对象管理内存，进程A和进程B都用自己的虚拟地址与它进程映射，这样他就共享了同一块内存，然后
就可以通信了。
    
    特点：
        1、不需要复制信息，是最快的一种进程间通信机制。
        2、需要考虑同步问题（必须借助其他的机制，如信号）。
    编程模型：
    进程A                                进程B
    生成IPC键值       ftok               生成IPC键值       ftok
    创建共享内存      shmget             创建共享内存      shmget
    映射共享内存      shmat              映射共享内存      shmat
    使用共享内存      *ptr               使用共享内存      *ptr
    取消映射          shmdt              取消映射          shmdt
    删除共享内存      shmctl

    int shmget(key_t key, size_t size, int shmflg);
    功能：创建/获取共享内存
    key：IPC键，有ftok函数生成
    size：共享内存的大小，最好是4096的整数倍，获取内存共享时，此值无效。
    shmflg：
        0 获取共享内存
        IPC_CREAT 创建
        IPC_EXCL  如果存在则创建失败
    返回值：成功返回共享内存标识（IPC标识），失败返回-1

    void *shmat(int shmid, const void *shmaddr, int shmflg);
    功能：映射共享内存
    shmid：共享内存标识符，shmget函数的返回值
    shmaddr：进程提供的虚拟地址，与内核中的内存映射用的，也可以是NULL（内核会自动选择一个地址映射）
    shmflag：
        0 自动分配
        SHM_RDONLY 只读权限
        SHM_RND    当shmaddr不为空时，shmaddr向下取整页
    返回值：映射成功后的虚拟地址

    int shmdt(const void *shmaddr);
    功能：取消虚拟地址与共享内存的映射
    shmaddr：被映射过的虚拟地址

    int shmctl(int shmid, int cmd, struct shmid_ds *buf);
    功能：删除共享内存，获取/设置共享内存的属性
    shmid：共享内存标识符，shmget的返回值
    cmd：
        IPC_STAT    获取共享内存的属性
        IPC_SET     设置共享内存的属性
        IPC_RMID    删除共享内存对象

    struct shmid_ds {
        struct ipc_perm shm_perm; /* Ownership and permissions */内存所有者及权限
        size_t shm_segsz; /* Size of segment (bytes) */内存的大小
        time_t shm_atime; /* Last attach time */最后的映射时间
        time_t shm_dtime; /* Last detach time */最后的取消映射时间
        time_t shm_ctime; /* Last change time */最后修改时间
        pid_t shm_cpid; /* PID of creator */创建者进程ID
        pid_t shm_lpid; /* PID of last shmat(2)/shmdt(2) */最后映射 / 取消映射的ID
        shmatt_t shm_nattch; /* No. of current attaches */映射的次数
        ...
    };

    struct ipc_perm {
        key_t __key; /* Key supplied to shmget(2) */IPC键值
        uid_t uid; /* Effective UID of owner */有效用户ID
        gid_t gid; /* Effective GID of owner */有效组ID
        uid_t cuid; /* Effective UID of creator */创建者的用户ID
        gid_t cgid; /* Effective GID of creator */创建者的组ID
        unsigned short mode; /* Permissions + SHM_DEST and SHM_LOCKED flags */ 权限
        unsigned short __seq; /* Sequence number */序列号 （IPC标识）
    };

五、消息队列
    消息队列就是由内核管理的一个管道，可以按顺序发送消息包（消息类型+消息内容），可以全双工工作，可以不按消息的顺序接收顺序
    int msgget(key_t key, int msgflg);
    功能：创建/获取消息队列
    key：IPC键值，由ftok函数自动生成
    msgflg：
        0 获取消息队列
        IPC_CREAT 创建消息队列
        IPC_EXCL 如果存在则创建失败
    返回值：消息队列标识

    int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
    功能：向消息队列发送消息
    msqid：消息队列标识，msgget函数的返回值
    msgp：结构指针
        struct msgbuf {
            long mtype; /* message type, must be > 0 */消息类型
            char mtext[1]; /* message data */消息内容
        };
    msgsz:消息的长度，不包括消息类型，sizeof(msgbuf)-4。
    msgflg:
        0 阻塞，当消息队列满时，等待
        1 不阻塞，当消息队列满时，不等待
    返回值：成功发送返回0，失败返回-1。

    ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
    功能：从消息队列中，按类型获取消息
    msqid：消息队列标识，msgget函数的返回值
    msgp：结构指针
        struct msgbuf {
            long mtype; /* message type, must be > 0 */消息类型
            char mtext[n]; /* message data */消息内容
        };
    msgsz:要接收的消息的长度，可以长一些
    msgtyp:要接收的消息类型
        0 接收任意类型的消息（接收队列中第一个消息）。
        >0 只接收msgtyp类型的消息
        <0 接收消息队列中小于等于msgtyp绝对值的消息，取小的那个。
    msgflg:
        0 阻塞，消息队列中是否有对应类型的消息，没有则等待
        1 不阻塞，消息队列中没有对应类型的消息，则返回
        MSG_NOERROR:
            消息类型正确，而消息的实际长度大于msgsz，则不接收消息并返回-1。
            如果msgflg带MSG_NOERROR标志，则把多余的消息截取，成功接收。
        IPC_NOWAIT：如果消息队列没有要接收的消息，则不等待，返回-1。
        MSG_EXCEPT:接收消息队列中第一个消息类型不是msgtyp的消息，编译时添加-D_GNU_SOURCE

    返回值：成功接收到消息的字节数。

    int msgctl(int msqid, int cmd, struct msqid_ds *buf);
    功能：删除消息队列，设置或获取消息队列属性
    msqid：消息队列标识，msgget函数的返回值
    cmd：
        IPC_STAT    获取消息队列的属性
        IPC_SET     设置消息队列的属性
        IPC_RMID    删除消息队列
    返回值：成功发送返回0，失败返回-1

    struct msqid_ds {
        struct ipc_perm msg_perm; /* Ownership and permissions */权限
        time_t msg_stime; /* Time of last msgsnd(2) */最后一个消息发送
        time_t msg_rtime; /* Time of last msgrcv(2) */最后一次消息接收时间
        time_t msg_ctime; /* Time of last change */最后一次修改时间
        unsigned long __msg_cbytes; /* Current number of bytes in queue (nonstandard) */消息队列中的字节数
        msgqnum_t msg_qnum; /* Current number of messages in queue */消息队列中消息的个数
        msglen_t msg_qbytes; /* Maximum number of bytes allowed in queue */消息队列中容纳的最大字节数
        pid_t msg_lspid; /* PID of last msgsnd(2) */最后一发送消息的进程
        pid_t msg_lrpid; /* PID of last msgrcv(2) */最后一次接收消息的进程
    };

    struct ipc_perm {
        key_t __key;          /* Key supplied to msgget(2) */
        uid_t uid;            /* Effective UID of owner */
        gid_t gid;            /* Effective GID of owner */
        uid_t cuid;           /* Effective UID of creator */
        gid_t cgid;           /* Effective GID of creator */
        unsigned short mode;  /* Permissions */
        unsigned short __seq; /* Sequence number */
    };

六、信号量
    内核维护的计数器，用于管理多进程之间共享资源。
    例如：有个变量n表示资源的数量，当有进程想要独占一个资源时，n的值要减1（可能减多个），如果n的值等于0（不够减），则进程阻塞，
直到n的值可以减再被唤醒，当资源使用完毕后n的值要加1（可能加多个）。

    int semget(key_t key, int nsems, int semflg);
    功能：创建/获取信号量
    key：IPC键值
    nsems：信号量的数量
    semflg：
        0 获取信号量
        IPC_CREAT 创建信号量，不存在则创建，存在则获取
        IPC_EXCL 如果已经存在则创建失败。
    返回值：信号量标识

    int semop(int semid, struct sembuf *sops, unsigned nsops);
    功能：操作信号量（对信号进行加/减操作）
    semid:信号量标识，semget的返回值
    sops：结构体数组
    nsops：数组的长度

    int semtimedop(int semid, struct sembuf *sops, unsigned nsops, struct timespec *timeout);
    功能：带时间限制的操作信号量

    struct sembuf{
        unsigned short sem_num; /* semaphore number */信号量的下标
        short sem_op; /* semaphore operation */操作
        short sem_flg; /* operation flags */标记
            IPC_NOWAIT 当信号量不够减是，不阻塞。 
            SET_UNDO 当进程结束时，信号量的值自动归还
    }

    struct timespec{
        __time_t tv_sec;//秒 
        long int tv_nsec;//纳秒 10 ^ 9 = 1s
    }

    int semctl(int semid, int semnum, int cmd, ...);
    功能：删除信号量，获取、设置信号量的属性

    cmd：
        GETALL   获取信号量的值
        GETNCNT  获取信号量的数量
        GETPID   获取进程的PID
        GETVAL   获取某个信号量的值
        SETALL   设置所有信号量的值
        SETVAL   设置某个信号量的值
        IPC_RMID 删除信号量

        IPC_STAT 获取信号量的属性 
        IPC_SET 设置信号量的属性

        struct ipc_perm {
            key_t __key;          /* Key supplied to semget(2) */
            uid_t uid;            /* Effective UID of owner */
            gid_t gid;            /* Effective GID of owner */
            uid_t cuid;           /* Effective UID of creator */
            gid_t cgid;           /* Effective GID of creator */
            unsigned short mode;  /* Permissions */
            unsigned short __seq; /* Sequence number */
        };

        
        IPC_INFO 获取信号量的信息
        SEM_INFO 设置信号量的信息
        struct  seminfo {
            int semmap; /* Number of entries in semaphore map; unused within kernel */
            int semmni; /* Maximum number of semaphore sets */
            int semmns; /* Maximum number of semaphores in all  semaphore sets */
            int semmnu; /* System-wide maximum number of undo structures; unused within kernel */
            int semmsl; /* Maximum number of semaphores in a set */
            int semopm; /* Maximum number of operations for semop(2) */
            int semume; /* Maximum number of undo entries per process; unused within kernel */
            int semusz; /* Size of struct sem_undo */
            int semvmx; /* Maximum semaphore value */
            int semaem; /* Max. value that can be recorded for semaphore adjustment (SEM_UNDO) */
        };

    //初始化信号量
    union semun {
        int val;               /* Value for SETVAL */
        struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
        unsigned short *array; /* Array for GETALL, SETALL */
        struct seminfo *__buf; /* Buffer for IPC_INFO (Linux-specific) */
    };

    编程模型：
    进程A                               进程B
    创建信号量          semget          获取信号量
    初始化信号量的值    semctl          。。。
    加减信号量          semop           加减信号量
    删除信号量          semctl          。。。
    注意：信号量是用来计数的，一定要与资源对应。

七、IPC命令
    显示IPC对象
        ipcs -m
        ipcs -q
        ipcs -s
        ipcs -a
    删除IPC对象
        ipcrm -m ID
        ipcrm -q ID
        ipcrm -s ID

































一、计算机网络
    1、什么是计算机网络
    计算机网络是指将地理位置不同的具有独立功能的多台计算机及其外部设备，通过通信线路连接起来，在网络操作系统，网络管理软件及
网络通信协议的管理和协调下，实现资源共享和信息传递的计算机系统。

    2、计算机网络的功能
        数据通信
        资源共享
        提高系统的可靠性
        分布式网络处理和负载均衡
    3、计算机网络的组成
        通信子网：网卡、线缆、集线器、中继器、交换机、路由器
        资源子网：网络中的计算机、打印机、电话等一些可以提供服务的设备。
        计算机网络软件：
            协议软件：它规定了计算机之间通信的规则，TCP/IP协议簇。
            网络通信软件：网络中实现计算机与设备之间通信的软件（网卡驱动）
            网络管理软件：防火墙、SELinux
            网络应用软件：浏览器、迅雷
            网络操作系统：可以提供网络服务的计算机操作系统，Windows server 2008、UNIX、Linux
    4、计算机网络的分类
        按网络作用范围划分：局域网、城域网、广域网
        按网络技术划分：广播式网络、点到点网络
        按传输介质划分：有线网、无线网、微波通信、卫星通信
    5、计算机网络拓扑结构
        星型：
        树型：
        总线型：
        环型：
        网状型：
    6、计算机网络的发展过程
        1、以计算机为中心的联机系统
        2、分组交换网络的诞生
        3、网络体系结构与协议标准化
            20世纪80年代ISO组织提出开放式系统互联参考模型（OSI参考模型）。
            但由于这个模型照顾到了各方的利益，所以太过庞大，因此至今都没有成熟的产品，目前我们所使用是一系列协议的集合，简称TCP/IP簇，
通常也叫TCP/IP模型。
            目前所有的计算机系统都按照这个协议（簇）进行通信，所以不同操作系统之间才可能进行网络通信。
            C/C++/Java/python -> Windows -> socket -> TCP/IP <-> TCP/IP -> socket -> Linux -> C/C++/Java/Python
        4、高速计算机网络（5G）
    7、网卡
        他负责将数据发送到网络上，也负责从网络中获取数据，每个网卡上都有一个独一无二MAC地址。
    8、OSI参考模型与TCP/IP参考模型
        网络协议是为网络数据交换而制定的规则、约束、标准，一个功能完备的计算机网络需要制定一整套复杂的协议集，目前的网络协议是按照
层次结构组织的，网络层次结构模型与各层协议的集合称为网络体系结构。
        OSI从下到上：物理层、数据链路层、网络层、传输层、会话层、表示层、应用层

        物理层：转发器、集线器；
        数据链路层：网桥、交换机；
        网络层：路由器、网关

        TCP/IP目前只实现了四层，从下到上：
            物理层：负责通信网络收发数据包
            网络层：选择、流量控制、网络拥塞、IP协议是该层的核心
            传输层：机器之间建立用于会话的端到端连接（用于数据传输），该层的核心是TCP/UDP。
            应用层：主要为用户提供针对性的服务，这一层的代表协议有：HTTP，SMTP，FTP，SNMP，TELNET。
            
            OSI             TCP
            ----------------------
            物理层
            数据链路层       物理层
            ----------------------
            网络层          网络层
            ----------------------
            传输层          传输层
            ----------------------
            会话层
            表示层          应用层
            应用层
            ----------------------
    9、IP地址
        在计算机网络中每一台计算机都必须有一个唯一的标识（MAC地址不容易记忆），它就是IP地址，目前在计算机以.分十进制表示（4个不超过
255的整数），但在程序中它就是4字节的整数。
        IP地址的分类：
        A类：第一个二进制位必须是0
            0.0.0.0 ~ 127.255.255.255
        B类：前两位的二进制必须是10
            128.0.0.0 ~ 191.255.255.255
        C类：前三位二进制必须是110
            192.0.0.0 ~ 233.255.255.255
        D类：前四位二进制必须是1110
            224.0.0.0 ~ 239.255.255.255
        E类：前4位二进制必须是1111
            240.0.0.0 ~ 255.255.255.255
    10、公有IP和私有IP
        公有IP：在网络服务提供商登记过的叫公有IP。
        私有IP:由一些公司或组织自己分配的，不能在网络中公开直接访问的。
    11、子网掩码
        4个不超过255的整数，.分十进制表示。
        网络地址 = ip地址 按位与（&） 子网掩码
        只有在同一子网内的IP地址才可能直接进行通信，否则必须经过路由器。
    12、网关地址
        负责子网出口的计算机，一般由路由器担任（路由器就是一台具有路由功能的计算机）。
    13、端口号
        ip地址能决定我们与哪一台计算机通信，而端口号决定了我们与计算机上的哪个进程通信。
        1 ~ 1024基本上已经被操作系统预定完了，因此我们在编程时一般要使用1024以上的。
        http:80、ftp:21、ssh:22、telnet:23

二、网络通信的基本概念
    1、TCP和UDP的区别
        TCP（Transmission Control Protocol）：传输控制协议，面向连接的服务（类似打电话），安全、可靠（三次握手、响应+重传、
四次挥手），速度相对较慢，一般应用在对安全性、完整性有严格要求的场景：文件传输（ftp）、SMTP、HTTP
            三次握手：
                A要知道，A能到B,B能到A
                B要也要知道，A能到B，B能到A
                             A 你听得到吗 ->       B(此时B知道了A能到B)
            （A能到B且B能到A）A <- 我能听到，你叫   B
                             A 我也能听到->        B（此时B知道了B也能到A）

            四次挥手：
                目的是保证关闭前发送完所有未发送的数据包（应用层已经交给底层了，但底层还没有完全发送出去）。
                A 发送关闭请求 -> B
                A <- 发送请求相应 B
                    B检查 是否有未发送完成的数据
                    <- 可以关闭   B
                A 发送关闭消息->  B

        UDP（User Datagram Protocol）：用户数据报文协议，面向无连接的服务（发短信）0，不保证安全、可靠，但大多数情况下是可靠的，
相对较快，流媒体（在线视频、音频）。

    2、消息流
        应用层->表示层->会话层->网络层->传输层->数据链路层->物理层->数据链路层->传输层->网络层->会话层->表示层->应用层
    3、消息包
        当socket收到一个要发送的数据时，会先把数据进行拆分成bit流，然后再组成（防丢失）数据包（可能会丢包）。

三、套接字
    socket是一种接口机制，可以让程序无论使用什么端口、协议、都可以从socket进出数据，它负责了进程与协议之间的连接。
    1、编程模型
        点对点（p2p）：一对一通信
        客户机/服务器（C/S）：一对多通信
    2、函数
        int socket(int domain, int type, int protocol);
        功能：创建socket描述符，可以把socket当作文件来看待，发送数据就是写文件，接收数据就是读文件。
        domain:地址类型
            AF_UNIX/AF_LOCAL/AF_FILE    本地通信（进程间通信）
            AF_INET                     基本32IP地址通信，IPv4 Internet protocols
            AF_INET6                    基本128IP地址通信，IPv6，IPv6 Internet protocols
        type:通信协议
            SOCK_STREAM     数据流协议，TCP
            SOCK_DGRAM      数据报协议，UDP
        protocol：特别通信协议，给0即可。
        返回值：socket描述符，类似文件描述符
    3、通信地址
        注意：函数接口定义的是sockaddr，而实际提供的是sockaddr_un或sockaddr_in
        struct socketaddr{
            sa_family_t sa_family;
            char sa_data[14];
        }
        struct sockaddr_un {
            __SOCKADDR_COMMON(sun_); /* AF_UNIX */地址类型 参看domain参数 
            char sun_path[108]; /* pathname */socket文件的路径
        };
        struct sockaddr_in{
            __SOCKADDR_COMMON(sin_);
            in_port_t sin_port;     // 端口号 大端字节序 参看联合
            struct in_addr sin_addr // ip地址 大端4字节整数
        }
        struct in_addr{
            in_addr_t s_addr; // 
        }
    4、绑定
		socket描述符与物理通信载体（网卡或socket文件）绑定在一起。
		int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
		sockfd：socket描述符：socket函数的返回值
		addr：通信地址结构体，实际给的是sockaddr_un或sockaddr_in，需要强制类型转换。
		addrlen：通信地址结构体类型的字节数，使用sizeof计算。
	5、连接
		int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
		sockfd：socket描述符
		addr：通信目标地址
		addrlen：通信地址结构体类型的字节数，使用sizeof计算。
		返回值：在不同的编程模型下返回值意义不同，在本地通信
			返回加0，失败返回-1。
	6、数据接收与发送：read/write
		ssize_t recv(int sockfd, void *buf, size_t len, int flags);
		ssize_t send(int sockfd, const void *buf, size_t len, int flags);
		recv／send与read/write功能一样，flags多了是否阻塞的功能（0阻塞，1不阻塞）。
	7、关闭套接字：close
		如果是网络通信，端口号并不会立即回收，大概会占用3分钟左右。
    8、字节序转换
    #include <arpa/inet.h>

        uint32_t htonl(uint32_t hostlong);
        功能：把32位本机字节序转换成32位的网络字节序
        uint16_t htons(uint16_t hostshort);
        功能：把16位本机字节序转换成16位的网络字节序
        uint32_t ntohl(uint32_t netlong);
        功能：把32位网络字节序转换成32位的本机字节序
        uint16_t ntohs(uint16_t netshort);
        功能：把16位网络字节序转换成16位的本机字节序
    9、ip地址转换
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
        int inet_aton(const char *cp, struct in_addr *inp);
        功能：把点分十进制的ip地址（字符串）转换成32位无符号整数，使用指针获取。
        in_addr_t inet_addr(const char *cp);
        功能：把点分十进制的ip地址（字符串）转换成32位无符号整数，使用返回值直接返回。
        char *inet_ntoa(struct in_addr in);
        功能：32位无符号整数表示的ip地址，转换成点分十进制的ip地址（字符串）。
    10、本地通信编程模型
        进程A                      进程B
        创建套接字（AF_LOCAL）      创建套接字（AF_LOCAL） 
        准备地址（sockaddr_un）     准备地址（sockaddr_un）
        绑定（自己的socket/地址）    连接（connect，连接进程A的地址）
        接收数据                    发送数据
        关闭套接字

四、基于TCP协议的C/S模型
    int listen(int sockfd, int backlog);
    功能：设置等待连接的最大数量
    sockfd:被监听的socket描述符
    backlog:等待连接的最大数量（排队的数量）

    int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    功能：等待连接sockfd连接
    addr：获取连接的地址
    addrlen：设置连接地址结构体的长度
    返回值：专门用于通信的描述符

    编程模型：
        Server                                  Client
        创建socket套接字                         创建socket套接字
        准备地址（sockaddr_in,本机地址）          准备地址（服务器地址）
        绑定（bind）                             。。。
        监听（listen）                           。。。
        等待连接（accept、fork）                 连接（connect）
        接收请求(read/recv)                      发送请求（write/send）
        响应请求(write/send)                     接收响应（read/recv)                    
        关闭(close)                              关闭（close）

五、基于UDP协议的C/S模型
    ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,  const struct sockaddr *dest_addr, socklen_t addrlen);
    功能：UDP协议专用的数据发送函数
    sockfd：套接字描述符
    buf：待发送的缓冲区首地址
    len：待发送的数据字节数
    flags：0阻塞，1不阻塞
    dest_addr：目标计算机地址（发送）
    addrlen：地址结构体的字节数
    返回值：成功发送的字节数
    
    ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
    功能：UDP协议专用的数据接收函数
    sockfd：套接字描述符
    buf：数据存储位置 
    len：最大接收字节数
    flags：0阻塞，1不阻塞
    src_addr：获取发送者的地址
    addrlen：设置地址结构体的字节数
    返回值：成功接收的字节数。

    编程模型：
    Server                                  Client
    创建套接字（socket）                     创建套接字（socket）   
    准备地址（本机地址sockaddr_in）           准备地址（目标机地址sockaddr_in）
    绑定（bind（sockfd+addr））              。。。
    接收请求（recvfrom）                     发送请求（sendto）
    响应请求（sendto）                       接收响应（recvfrom）
    关闭套接字（close）                      关闭套接字（close）
    注意：从服务器到客户端返回的路线是UDP协议自己设计的。

练习1：获取当前计算机的ip地址和子网掩码。
    system("ifconfig > /tmp/ip.conf");
练习2:根据当前ip地址和子网掩码，遍历出所有同一局域网内的ip地址。

作业1：银行项目升级为网络版
作业2：实现网络聊天室
作业3：网络传输文件

七、Windows下的网络的编程
    一般的软件都是Linux/UNIX系统作为服务器，而Windows系统作为客户端，Windows下的socket编程的接口与Linux的基本一致，函数都声明
在winsock2.h头文件中。
    int WSAStartup(WORD,LPWSADATA);
    功能：初始化网络库
    WORD：设置网络库的版本
        MAKEWORD(1,2),第一位是主版本号，第二位是副版本号。
    LPWSADATA：WSADATA数据结构的指针，用来获取网络的相关信息

    SOCKET socket(int domain, int type, int protocol);
    功能：创建socket
    返回值：typedef 

    closesocket(sockfd);
    功能：关闭socket

    int WSACleanup(void);
    功能：卸载网络库

    注意：编译时加 -lws2_32,编译结果是a.exe

练习1：实现Windows下的TCP的C/S通信
    注意：在Windows下write/read与send/recv是有区别的
练习2：实现Windows下的UDP的C/S通信





























一、线程基本概念
    1、线程就是进程中的执行路线，即进程内部的控制序列，或者说是进程的子任务（进程就是正在运行的程序，它是一个资源单位）
    2、线程就是轻量级的，没有自己独立的内存资源，使用的是进程的代码段、数据段、bss段、堆（注意：没有栈）、环境变量表、命令行参数、
文件描述符、信号处理函数、工作目录、用户ID、组ID等资源。
    3、线程拥有自己独立的栈，也就是有自己独立的局部变量。
    4、一个进程中可以同时拥有多个线程，即同时被系统调度的多条执行路线，但至少有一个主进程。


二、线程基本特点
    1、线程是进程的实体，可以作为系统独立的调试和分派基本单位。
    2、线程有不同的状态，系统提供了多种线程控制的原语（控制方法），比如：创建线程、销毁线程。
    3、线程不拥有自己的资源（唯一拥有的就是自己的栈空间），只拥有从属于进程的全部资源，所有资源分配都是面向进程的。
    4、一个进程中可以有多个线程同时执行，它们可以执行相同的代码,也可以执行不同的代码。
    5、同一进程内的线程都在同一个地址空间下活动（0~4G），相对于多进程，多线程的系统开销小，任务切换快。
    6、多进程协同工作时需要通信，而多线程间的数据交换不需要依赖类似的IPC的特殊通信机制，简单而高效。
    7、每个线程拥有自己独立的线程ID、寄存器信息、函数栈等。
    8、线程之间也存在优先级。
    ***注意：线程与进程的区别？

三、POSIX线程
    1、早期的UNIX操作系统中没有线程的，而是各计算机厂商提供了自己私有的线程库，不易移植。
    2、在1995年左右，定义了统一的线程编程接口，POSIX线程，即pthread。
    3、pthread包含一个头文件pthread.h，一个共享库libpthread.so
    4、功能：
        线程管理：创建/销毁、分离/联合、设置/获取属性
        线程同步（互斥）：互斥量（互斥锁），条件变量，信号量
四、线程函数
    1、线程创建
    int pthread_create(pthread_t *thread, const pthread_attr_t *attr,  void *(*start_routine) (void *), void *arg);
    功能：创建线程
    thread：获取线程ID
    attr：创建线程所需要的属性设置，如果为NULL按照默认方式创建线程。
    start routine：线程的入口函数
    arg：给线程入口函数传递的参数

    练习1：把TCP的S端的多进程改成多线程

    2、等待线程结束
    int pthread_join(pthread_t thread, void **retval);
    功能：等待线程结束获取线程入口函数的返回值，线程结束时该函数才返回。
    thread：线程ID
    retval：指针变量的地址，用于获取线程入口函数的返回值。
    注意：线程入口函数在返回数据时，不能返回指向私有栈空间的指针，如果获取到的是指向堆的指针，等待者要负责把该空间释放。
    注意：当主线程结束，子线程会全部结束。

    3、获取线程ID
    pthread_t pthread_self(void);
    功能：返回当前线程的ID

    4、比较两个线程ID
    int pthread_equal(pthread_t t1,pthread_t t2);
    功能：如果两个线程ID是同一个线程，则返回0，否则返回-1。
    注意：pthread_t不一定是 unsigned long类型，有些系统中它是结构体类型，所以无法使用==比较。

    5、线程终止
    void pthread_exit(void *retval);
    功能：调用者线程结束（从入口函数return）
    retval：会返回给pthread_join函数的第二个参数。
    注意：如果是进程的最后一个线程，当调用pthread_exit时进程也就结束了。

    6、线程分离
    非分离:线程可以被创建者调用pthread_join等待（回收资源）。
    分享状态：线程不需要创建者等待，结束后自动释放资源。
    int pthread_detach(pthread_t thread);
    功能：使用调用线程与线程ID为thread线程成为分离状态。

    7、线程取消
    int pthread_cancel(pthread_t thread);
    功能：向指定的线程发送取消操作
    注意：但对方不一定响应

    int pthread_setcancelstate(int state, int *oldstate);
    功能：设置调用者线程是否响应取消操作
    state：
        PTHREAD_CANCEL_ENABLE 允许响应
        PTHREAD_CANCEL_DISABLE 禁止响应
    oldstate：获取旧的取消状态

    8、线程属性
    typedef union
    {
        char __size[__SIZEOF_PTHREAD_ATTR_T];
        long int __align;
    }pthread_attr_t;
    猜测：不让手动修改各项线程的各大项属性，而使用pthread_attr_set/get系列函数来操作。

    int pthread_attr_init(pthread_attr_t *attr);
    功能：初始化线程属性

    int pthread_attr_destroy(pthread_attr_t *attr);
    功能：销毁线程属性

    int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
    功能：设置线程属性中分离标志
    detachstate：
        PTHREAD_CREATE_DETACHED 分离
        PTHREAD_CREATE_JOINABLE 不分离
    int pthread_attr_getdetachstate(pthread_attr_t *attr, int *detachstate);
    功能：获取线程属性中分离标志

    int pthread_attr_setscope(pthread_attr_t *attr, int scope);
    功能：设置线程属性中线程的竞争范围
    PTHREAD_SCOPE_SYSTEM
    PTHREAD_SCOPE_PROCESS
    int pthread_attr_getscope(pthread_attr_t *attr, int *scope);
    功能：获取线程属性中线程的竞争范围

    int pthread_attr_setinheritsched(pthread_attr_t *attr, int inheritsched);
    功能：设置线程属性中线程的调度策略来源
        PTHREAD_INHERIT_SCHED 继承创建者
        PTHREAD_EXPLICIT_SCHED 单独设置
    int pthread_attr_getinheritsched(pthread_attr_t *attr, int *inheritsched);

    int pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy);
    功能：设置线程属性中线程的调度策略
    SCHED_FIFO 先进先出策略
    SCHED_RR 轮转策略
    SCHED_OTHER 缺省
    int pthread_attr_getschedpolicy(pthread_attr_t *attr, int *policy);
    功能：获取线程属性中线程的调度策略

    int pthread_attr_setschedparam(pthread_attr_t *attr, const struct sched_param *param);
    功能：设置线程属性中线程的调度参数（优先级别）
    param：最高级别0
    int pthread_attr_getschedparam(pthread_attr_t *attr, struct sched_param *param);

    int pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize);
    功能：设置线程属性中栈尾的警戒区大小
    int pthread_attr_getguardsize(pthread_attr_t *attr, size_t *guardsize);
    功能：获取线程属性中栈尾的警戒区大小

    int pthread_attr_setstackaddr(pthread_attr_t *attr, void *stackaddr);
    功能：设置线程属性中线程的栈底地址
    int pthread_attr_getstackaddr(pthread_attr_t *attr, void **stackaddr);
    功能：获取线程属性中线程的栈底地址

    int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);
    功能：设置线程属性中线程的栈空间字节数
    int pthread_attr_getstacksize(pthread_attr_t *attr, size_t *stacksize);
    功能：获取线程属性中线程的栈空间字节数

    使用方法：
        1、定义线程属性结构体
        pthread_attr_t attr;
        2、初始化线程属性结构体
        pthread_attr_init(&attr);
        3、使用pthread_attr_set系列函数对结构体变量进行设置。
        4、在创建线程时（pthread_create函数的第二个参数）中使用线程属性结构变量创建线程。

        int pthread_getattr_np(pthread_t thread, pthread_attr_t *attr);
        功能：获取指定线程的属性

        int pthread_attr_setstack(pthread_attr_t *attr, void *stackaddr, size_t stacksize);
        int pthread_attr_getstack(pthread_attr_t *attr, void **stackaddr, size_t *stacksize);


        作业1：实现聊天室




























一、同步、竞争、互斥
    当多个线程同时访问其共享的资源时，需要相互协调，以防止出现数据不一致、不完整的问题，能达到这种状态叫线程同步。
    而有些资源在同一时刻只有一个线程访问，对于这种资源的访问需要竞争。
    当资源获取到后，能够防止资源被其他线程抢占（再次获取）的技术叫互斥。

二、互斥量（锁）
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITALIZER;
    int pthread_mutex_init (pthread_mutex_t *__mutex, __const pthread_mutexattr_t *__mutexattr)
    功能：初始化互斥量,使用第二互斥量来初始化第一个互斥量，如果第二个为空，则使用默认参数初始化互斥量,也可以使用宏来初始化。
    
    int pthread_mutex_destroy (pthread_mutex_t *__mutex)
    功能：销毁互斥量
    注意：互斥量是一个结构体，里面有成员是指针，指向了堆内存数据，需要显式初始化函数以及销毁函数。    
    如果使用堆内存存储互斥量，需要在调用了销毁函数后，再进行free。

    int pthread_mutex_lock (pthread_mutex_t *__mutex)
    功能：锁定互斥量，当互斥量是锁定状态，此函数则阻塞（直到互斥量在其他线程中解锁，调用者线程加锁成功才返回）。
    注意：互斥量一旦加锁，只有它自己能解。

    int pthread_mutex_trylock (pthread_mutex_t *__mutex)
    功能：尝试锁定互斥量，能锁就锁，不能锁就返回。

    int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex, __const struct timespec *__restrict __abstime) 
    功能：在指定时间内锁定一个互斥量(由于系统原因导致不可知锁的状态),而一旦获取锁的状态后立即做出抉择。
    struct timespec
    {
        __time_t tv_sec;
        long int tv_nsec;
    }

    int pthread_mutex_unlock (pthread_mutex_t *__mutex)
    功能：解锁

三、死锁
    多个线程进行等待对方的资源，在得到所有资源继续运行前，都不会释放自己的资源，这样造成的循环等待现象，称为死锁。
    构成死锁的四大必要条件：
    1、资源互斥
    2、占有，还想占有（请求与保持）
    3、资源不可剥夺
    4、环路等待（循环等待）

    防止死锁的方法：
        构成死锁的四个条件只要破坏其中一个就构不成死锁，死锁一旦形成就无法消除，因此最后的方法就是避免产生死锁。
        1、破坏互斥条件，让资源能够共享，但缺点是不通过，因为有些资源不能共享，如打印机。
        2、破坏请求并保持，采用预先分配的方法，在进行运行前一次申请好它所需要的所有资源，但缺点是浪费资源。
        3、破坏不可剥夺的条件，对已经占用资源的线程发送取消请求，但是实现比较复杂，而且还会破坏业务逻辑。
        4、破坏循环等待条件，为每个资源进行编号，采用顺序的资源分配方法，规定每个线程必须按照递增的顺序请求资源，缺点是编号必须
相对稳定，增加新资源时会比较麻烦，而且有些特殊的业务逻辑不能完全按照指定的顺序分配资源。
    避免产生死锁的算法（银行家算法）：
        1、申请资源的额度不能超过银行现有资源的总和。
        2、分批向银行，但是货款额度不能超过一开始最大需求量总和。
        3、银行如果不能满足客户的需要，必须及时给出答复
        4、客户必须在规定的时间内还款。
    如何检测死锁：
        1、画出资源分配图，并简化，模拟资源分析的过程。
        2、监控线程过程的栈内存使用情况。
        3、设计看门狗机制（TCP心跳包）

四、信号量
    线程的信号量与进程的信号量的机制是一样的，但使用方法不同，用于控制、管理线程间的共享资源。
    #include <semaphore.h>
    int sem_init(sem_t *sem, int pshared, unsigned int value);
    功能：初始化信号量（创建信号量）
    sem:信号量ID，输出
    pshared：一般为0（线程之间）进程中使用的。
        非零表示进程间使用，但Linux不支持。
    value：信号量的初始化

    int sem_wait(sem_t *sem);
    功能：信号量减1，不够减则阻塞（为0时）。

    int sem_trywait(sem_t *sem);
    功能：信号量减1，不够减则立即返回-1

    int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);
    功能：信号量减1，不够减则阻塞，直到abs_timeout超时返回-1。
    struct timespec
    {
        __time_t tv_sec;
        long int tv_nsec;
    }

    int sem_post(sem_t *sem);
    功能：信号量+1

    int sem_destroy(sem_t *sem);
    功能：销毁信号量

    int sem_getvalue(sem_t *sem, int *sval);
    功能：获取信号量的值

五、生产者与消费者模型
    见图

六、条件变量
    条件变量可以让线程在满足特定的条件下暂停（睡眠），需要与互斥量配合使用。
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
    int pthread_cond_init (pthread_cond_t *__restrict __cond,  __const pthread_condattr_t *__restrict  __cond_attr);
    功能：初始化条件变量
    cond:待初始化的条件变量
    cond_attr:条件变量的属性

    int pthread_cond_destroy (pthread_cond_t *__cond);
    功能：销毁条件变量

    int pthread_cond_wait (pthread_cond_t *__restrict __cond,  pthread_mutex_t *__restrict __mutex);
    功能：让调用者线程进入睡眠，并解锁一个互斥量
    cond：线程睡入的条件变量
    mutex：线程睡眠前的要解锁的互斥量（是不是锁定状态没有关系）

    int pthread_cond_signal (pthread_cond_t *__cond);
    功能：唤醒条件变量中的一个线程
    注意：线程醒的前提条件是互斥量必须是解锁状态的，线程醒前会再次加锁，如果不能加锁就不会醒来。

    int pthread_cond_timedwait (pthread_cond_t *__restrict __cond, pthread_mutex_t *__restrict __mutex, __const struct 
timespec *__restrict __abstime);
    功能：让调用者线程进入睡眠（指定睡眠时间），并解锁一个互斥量
    注意：使用的是系统时间。

七、哲学家就餐问题

参考资料：Linux下的user/include中的pthread.h文件