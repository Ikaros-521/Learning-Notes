一、烧写Linux系统到inand
    1、烧写u-boot到inand
        tftp 30008000 u-boot.bin
        movi write u-boot 30008000
    2、烧写Linux内核到inand
        tftp 30008000 zImage-qt
        movi write kernal 30008000
    3、烧写文件系统到inand
        开发板中已经有文件系统，无须再烧，设置启动参数即可。
    4、设置启动环境变量
    setenv bootcmd "movi read kernel 30008000;bootm 30008000"
    setenv bootargs "console=ttySAC2,115200 root=/dev/mmcblk0p2 rw init=/linuxrc rootfstype=ext3"

二、挂载ubuntu系统的文件夹到开发板
    目的：是为了把编译好驱动程序下载到共享目下。
    1、进入开发板系统 root 123456
    2、检查开板的ip地址
    3、在启动脚本添加以下内容：vi /etc/init.d/rcS
        mount -t nfs -o nolock 192.168.1.66:/nfs /mnt

三、Linux内核下的C语言编程
    1、命名习惯
        普通代码：
            #define PI 3.14159
            int minVal,maxVal;
            void sendData(void);
        内核代码：
            #define PI 3.14159
            int min_val,max_val;
            void send_data(void);

    2、GNU C与ANSI C
        GNU编译器是专门为Linux内核所设计的一款编译器，而且Linux内核中也使用大量只有GNU编译才支持的C语言语法，因此只有GNU编译器才能编译内核代码和Linux驱动程序。
        a、零长数组
            typedef struct {
                int len;
                char data[0];
            }Data;

            Data* dp = malloc(sizeof(Data)+1024);
            dp->len = 1024;

            send(sockfd,dp,sizeof(dp->len+sizeof(*dp)),0);
        b、case范围
            switch(n)
            {
                case 1 ... 5: break;
                case 6 ... 9: break;
            }
        c、typeof
            定义一个宏求两个变量的最大值。
            #define MIN(a,b) ((a)>(b)?(a):(b))
            #define MIN(type,a,b) ({type _a=num1++;type _b=num2++;_a>_b?_a:_b;})

            MIN(int,num1++,num2++) => num1++ > num2++ ? num1++ : num2++;
            #define MIN(a,b) ({typeof(a) _a=a; typeof(b) _b=b; _a>_b?_a:_b;})

            定义一个宏交换两个变量值。
            #define swap(a,b) ({typeof(a) t=a; a=b; b =t;})
            
        d、可变参长数宏
            int printf(const char *format, ...);
            #define debug(ftm,arg,...) printf(ftm,##arg)
        e、标号元素
            ANSI C
            struct Student stu = {
                name:"hehe",
                sex:'m',
                age:18
            };

            GNU C
            struct Student stu = {
                .name = "hehe",
                .sex = 'm',
                .age = 18
            };
    
    3、do{ } while(0)
        定义一个宏函数，用来释放堆内存。
        #define FREE_HEAP(p) do{free(p); p = NULL;}while(0)

        int func(void)
        {
            if(NULL != p)
                FREE_HEAP(p)
            else
                return -1;
        }

    4、goto语句
        一般的企业代码中禁止使用goto语句，因为goto可以跳转到函数内的任意位置，会打破原有分支、循环结构、或业务逻辑，所以goto是应用层代码中是一种非常危险的语句，但在内核中却有它独到的功能。
        int example(void)
        {
            if(!register_a())
            {
                goto err1;
            }
        
            if(!register_b())
            {
                goto err2:
            }

            if(!register_c())
            {
                goto err3:
            }

            // work

        err3:
            unregister_c();
        err2:
            unregister_b();
        err1:
            unretister_a();
        err:
            return ret;
        }
        在内核中，资源的申请与释放必须是逆序，而goto语句能够把错误处理的代码写的安全、严谨而有简洁。

四、内核模块
    通过分析Linux内核的编译过程，了解到一个实事：Linux内核是由很多模块组成了。
    1、内核以模块的形式组成的好处
        a、可以灵活的进行裁剪
        b、可以动态加载或卸载
        c、可以尽量控制内核的大小
    2、内核模块的特点
        a、内核模块代码最终是要加入内核中的
        b、内核模块代码工作在内核态。
        c、内核模块代码一旦出错，可能会导致整个内核（操作）崩溃。
        d、在Linux系统中驱动程序是一个内核模块，它按照内核模块的格式进行编写。
    3、内核模块的结构
        a、模块加载函数（必须）
            模块加载内核时自动执行此函数，相当于内核模块的入口函数。
            此函数一般要做些初始化工作、申请内存、资源，注册相关信息。
        b、模块卸载函数（必须）
            模块被卸载时自动执行。
            此函数一般要做些资源的释放、销毁的工作。
        c、模块声明许可证（必须）
        d、模块作者信息声明（可选）
        e、其它一些自定义函数，可以被模块加载函数调用。
    4、内核模块的加载与卸载
        insmod hello.ko
        rmmod hello.ko
五、printfk函数
    printfk是在内核中运行的向控制台输出显示信息的函数，与printf函数的用法基本一致。
    内核中的消息是分等级的，定义在include/linux/kernal.h
        #define	KERN_EMERG	"<0>"	/* system is unusable			*/
        #define	KERN_ALERT	"<1>"	/* action must be taken immediately	*/
        #define	KERN_CRIT	"<2>"	/* critical conditions			*/
        #define	KERN_ERR	"<3>"	/* error conditions			*/
        #define	KERN_WARNING	"<4>"	/* warning conditions			*/
        #define	KERN_NOTICE	"<5>"	/* normal but significant condition	*/
        #define	KERN_INFO	"<6>"	/* informational			*/
        #define	KERN_DEBUG	"<7>"	/* debug-level messages			*/
        printk 默认的等级是 KERN_NOTICE
    在操作系统中可以设置显示消息等级，数字越大，级别超低。
        cat  /proc/sys/kernel/printk 可以看当前系统设置的消息等级
        echo "5" > /proc/sys/kernel/printk
        


一、模块参数
    在加载模块时可以像应用程序一样附加一些参数。
    定义变量：用来存储数据。
    注册变量：让内核允许加载模块时变量被赋值。
        module_param(变量名，类型，权限)；
        类型:
            byte、short、ushort、int、uint、long、ulong、charp
        权限:
            #define S_IRUSR 00400
            #define S_IWUSR 00200
            #define S_IXUSR 00100
    传递参数：insmod xxx.ko 变量名=数据
    模块导出符号：
        EXPORT_SYMBOL_GPL(符号);
        导出的符号（变量名、函数名）可以被其他模块使用，使用前声明一下即可。

二、驱动概述
    什么是驱动：就是控制硬件工作的软件。
    在Linux系统下，驱动程序工作在内核中，以内核模块形式存在，它能能够控制硬件工作，或者提供控制硬件的接口。
    驱动程序提供接口归内核调用，然后内核再统一抽象成文件（设备文件），代应用的程序以操作文件式进行控制硬件。
    应用程序工作在用户态，驱动程序工作在内核态，它们之间不能直接联系，需要按照内核提供的接口（open/read/write/close）来传递数据。
    在Linux系统下一切皆文件。

三、驱动的类型
    字符设备：在IO过程中以字符或字节为单位进行数据传输，数据也要按照一定的顺序进行读写。
        操作这种设备的接口有：open/close/read/write
        常见的字符设备有：鼠标、键盘、串口、LED灯、温度传感器、湿度传感器等。
        字符设备由于功能杂乱，设备也混乱，一般都是小厂家生产的没有统一的接口，所以大多数据需要编写驱动的都是字符设备。
    块设备：以块为单位进行数据的读写，用记在读写数据时必须最少读一块，这种设备一般都带缓冲区，而且数据量一般都很大，数据在读写时一般不会立即到达硬件。
        操作这种设备的接口有：open/close/read/write/sync/fsync/fdatasync。
        常见的块设备有：硬盘、SD卡、Nand、iNand。
        虽然存储介质不同，但都有一个控制器不需要外部直接操作，只需要按照控制器的接口来操作即可。
    网络设备：具有网络通信协议的设备，网络设备没有设备文件,必须使用socket进行操作。
        操作这种设备的接口有：send/recv/sendto/recvfrom。
        网络设备都非常标准的、规范，所以有了万能的网卡驱动，顶多需要移植一下，也不需要编写驱动。

四、设备文件
    在Linux系统会把硬件抽象成文件来制作（网上除外）。
    查看设备文件：ls -l /dev
    每个字母表示文件的类型：
        -   普通文件
        d   目录文件
        l   链接文件
        c   字符设备文件
        b   块设备文件
        p   管道文件
        s   socket文件
    设备号：主设备号+从设备号组成
        主设备号：表示硬件的类型，1~254
        从设备号：硬件的编号，0~255
        它是在驱动程序中确定的，可以让内核自动生成，也可以手动确定，或者手动创建。
        注意：设备不能重复。

五、字符设备驱动
    1、字符设备驱动分析
        drivers\char\Cs5535_gpio.c
        a、按照内核模块格式编写
        b、创建设备号、初始化、添加
        c、实现文件操作函数
    2、设备号
        dev_t dev_id = MKDEV(主设备号，从设备号);
        功能：生成一个设备号
        返回值：主设备号+从设备号的合体
        注意：不一定能使用。

        int register_chrdev_region(dev_t from, unsigned count, const char *name)
        功能：注册希望使用的设备号，如果已经被占用则失败。
        from：希望使用的设备号，MKDEV的返回值
        count：设备的数量
        name：设备文件名
        返回值：成功返回0

        int alloc_chrdev_region(dev_t *dev, unsigned baseminor, unsigned count,const char *name)
        dev：内核分配的设备号，返回值
        baseminor：设备号的起始值
        count：设备的数量
        name：设备名
        返回值：成功返回0

        MAJOR(dev_id) 解析出主设备号
        MINOR(dev_id) 解析出从设备号

        void unregister_chrdev_region(dev_t from, unsigned count)
        功能：释放设备号
        from：设备号
        count：数量
    3、字符设备结构体
        struct cdev {
            struct kobject kobj;  // 内嵌的对象
            struct module *owner; // 模块名
            const struct file_operations *ops; // 文件操作结构体（函数指针）
            struct list_head list;
            dev_t dev; // 设备号
            unsigned int count; // 设备数量
        };

        void cdev_init(struct cdev *cdev, const struct file_operations *fops)；
        功能：初始化字符设备结构体
        cdev：字符设备结构体
        fops：文件操作结构体

        int cdev_add(struct cdev *p, dev_t dev, unsigned count)
        功能：添加字符设备到内核
        p：被初始化过的字符设备结构体
        dev：注册过的设备号
        count：设备数量

        struct file_operations {
            // 模块名
            struct module *owner; 
            // 设备文件位置指针
            loff_t (*llseek) (struct file *, loff_t, int);
            // read函数
            ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
            // write
            ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
            // poll
            unsigned int (*poll) (struct file *, struct poll_table_struct *);
            // ioctl
            int (*ioctl) (struct inode *, struct file *, unsigned int, unsigned long);
            // mmap
            int (*mmap) (struct file *, struct vm_area_struct *);
            // open
            int (*open) (struct inode *, struct file 
            // flush
            int (*flush) (struct file *, fl_owner_t id);
            // close
            int (*release) (struct inode *, struct file *);
        }
六、设备文件
    1、手动创建
        mknod 创建设备文件的命令。
        cat /proc/devices 查看内核分配的主设备号
        mknod /dev/char_v1 c 250 0

    2、自动创建
    内核提供一组函数用于自动创建设备文件，设备类对动对应的数据结构：struct class
        class_create->*__class_create
        struct class *__class_create(struct module *owner, const char *name,struct lock_class_key *key)
        功能：在内核中创建设备类 /sys/class/xxx
        owner：模块名
        key：设备类的名字
        返回值：设备类指针

        struct device *device_create(struct class *class, struct device *parent,dev_t devt, void *drvdata, const char *fmt, ...)
        功能：/sys/class/xxx/在dev目录下自动创建设备文件
        class：设备类指针，class_create函数的返回值
        parent：设备结构体指针，兼容各种类型的设备，此处填写字符设备结构指针。
        devt：设备号
        drvdata：创建设备文件时的附加信息
        fmt：设备文件名

    void device_destroy(struct class *class, dev_t devt)
    功能：删除设备
    class：设备类指针，class_create函数的返回值
    devt：设备号

    void class_destroy(struct class *cls)
    功能：从内核中删除设备类
    

        

一、驱动程序中操作GPIO
    在内核中已经把各个GPIO定义为宏，不需要再找地址了，在头文件 arch/arm/mach-sv5pv210/include/mach/gpio.h。
    int gpio_request(unsigned gpio, const char *label)
    功能：申请GPIO资源
    gpio：GPIO管脚的编号，在gpio.h头文件中有定义
    label：给GPIO管脚取个名字

    void gpio_free(unsigned gpio)
    功能：释放GPIO资源
    
    int gpio_direction_input(unsigned gpio)
    功能：设置GPIO管脚为输入模式

    int gpio_direction_output(unsigned gpio, int value)
    功能：设置GPIO管脚为输出模式
    
    int gpio_get_value(unsigned gpio)
    功能：从GPIO管脚读取数据

    void gpio_set_value(unsigned gpio, int value)
    功能：向GPIO管脚写入数据
二、ioctl
    int ioctl(int d, int request, ...);
    功能：从应用层来调用内核层的ioctl函数，对设备进行设置。
    d：文件描述符，open函数的返回值
    request：命令
    ...：附加参数，存储在用户层，以指针的方式交给内核层。
    返回值：成功返回0，失败返回-1。

    int (*ioctl) (struct inode *, struct file *, unsigned int cmd, unsigned long arg);
    功能：响应应用层的ioctl函数，对硬件进行设置。
    cmd：对应应用层request
    arg：实际上是一个指针，它第指向用户层的一段数据。

三、内核的内存管理
    unsigned long __must_check copy_from_user(void *to, const void __user *from, unsigned long n)
    功能：从用户层拷贝数据到内核层
    to：指向内核层空间的指针
    from：指向用户层空间的指针
    n：要拷贝的字节数据
    返回值：成功拷贝的字节数

    long copy_to_user(void __user *to,const void *from, unsigned long n)
    功能：从内核层拷贝数据到用户层
    to：指向用户层空间的指针
    from：指向内核层空间的指针
    n：要拷贝的字节数据
    返回值：成功拷贝的字节数

    void *kmalloc(int size)
    功能：与标准C中的用法一致，其实就是调用malloc，kmalloc只是一个宏名。

    void kfree(void *where)
    功能：释放内存

    



    
        

    
    

        

