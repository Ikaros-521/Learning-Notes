一、Qt简介
    1、Qt是什么
        Qt图形用户程序框架，是对底层应用编程接口API面向对象的封装。
        是一套基于C++语言的类库，专注但不局限于图形用户界面的开发，也可以进行系统调用、网络编程、数据库、2D/3D图形处理。
        特点：跨平台，支持Linux、Windows、MacOS、iOS、Android等操作系统。
    2、为什么选择Qt
        基于C++语言，简单、易用、面向对象（针对GTK）
        优良的跨平台特性（针对MFC），工控、嵌入式。

二、Qt环境与编译工具
    1、工具
        Qt助手：Qt参考文档，涉及了Qt中的每一个类和函数，是Qt开发的必备手册，在终端可以通过assistant命令启动。
        Qt构建器：他负责对源文件、头文件、界面文件进行解析生成编译脚本。
            qmake -project 工具当前目录里的文件，生成项目配置文件 xxx.pro
            qmake 根据xxx.pro文件生成Makefile脚本
        Qt设计师：对于带界面应用程序来说，最纯粹的方式就是通过C/C++代码来编写整个项目，但这种方式费时费力，所以我们一般不这样做界面，
而是采用一种画图的方式，自动生成对应的代码，所见即所得。
        Qt界面编译器：它负责把Qt设计师设计出的界面文件编译成C++代码。
            uic xxx.ui -o xxx.h 把界面文件编译成C++类。
        Qt创造器：Qt助手+Qt构建器+Qt设计师+Qt界面编译器+文本编辑器就等于Qt创建器，集成开发环境。
    2、头文件和库
        Qt安装好之后会在安装目录下创建一个/usr/include/qt4目录，我们所使用的头文件都在这个目录下。
        共享库安装在/usr/lib/i386-linux-gnu/qt4和/usr/lib/qt4目录下。
        静态库需要重新下载源手动编译。

三、第一个Qt程序
    1、Hello，Qt。
        编译源代码
        生成项目文件：qmake -project -> hello.pro
        生成编译脚本：qmake -> Makefile
        编译：make
        运行：./hello
    2、帮助手册
        Public Types：访问权限是 public 的成员。
        Properties：访问权限是 private 的，这一类的成员都有get/set函数。
        Public Functions：访问权限是 public 的成员函数。
        Public Slots：访问权限是 public 的槽函数，它可以像成员函数一样使用，但它可以与信号连接（与signal函数绑定一个信号与函数
一样），区别是Qt的信号可以自定义。
        Signals：信号，注意：不是函数，通过emit发送，会自动执行与它连接的槽函数。
        Static Public Members：静态公有成员函数，这类函数与对象无关，管理的是对象的公有资源。
        Protected Functions：访问权限是 protected 的成员函数
        Macros：与本类相关的宏定义
        Detailed Description：对本类的详细说明，使用方法，调用的上下文注意事项，有些类会有使用dome。

四、中文处理
    注意：在Qt4.8中默认不支持 utf-8 字符编码，因此使用中文时会出现乱码。
    内部编码与外部编码：
        Qt的应用程序的控件内部所使用的都是utf-16，这叫做应用程序的内部编码，而我们通过终端，控制输入的字符串叫外部编码。
    #include <QTextCodec>

    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    // 告诉Qt本地系统字符编码
    QTextCodec::setCodecForLocale(codec);
    // 告诉Qt程序中所使用的字符串的字符编码
    QTextCodec::setCodecForCStrings(codec);
    // 告诉Qt外部的字符编码
    QTextCodec::setCodecForTr(codec);

五、信号和槽
    1、信号
    当用户或系统触发一个动作，导致某个窗口发送变化，该空间就会发射一个信号，信号就可以调用一个函数，必要时还可以附加参数。
    如：QPushButton 控件中就有 clicked(void) 信号。
    2、槽
    槽就一个普通的类成员函数，它可以是公有的、私有的、保护的，可以被重载也可以被覆盖，其参数、返回值可以是任意类型，可以被直接调用。
    与普通函数的区别就是它可以被信号触发，自动执行。
    如：窗口控件QWidget中默认就有 close(void) 槽函数。
    3、信号和槽的连接
    bool connect ( 
        const QObject * sender, // 信号发送者 
        const char * signal,    // 信号签名字符串
        const QObject * receiver, // 信号的接收者
        const char * method);   // 槽函数签名字符串

        SIGNAL() 将信号函数签名转换成字符串
        SLOT() 将槽函数签名转换成字符串

六、窗口容器
    从心上案例中可以看出，一个控制就一个窗口，要把所有控件集合在同一个窗口中，需要把这些控件束缚在同一个容器中，这种容器就叫
窗口容器。
    1、QManWindows
    主窗口容器，通常由标题栏、菜单栏、工具条、状态栏以及中央显示区组成。
    2、QDialog
    对话框窗口容器，管理多个不同的交互式控件
    3、QWidget
    纯粹的窗口容器，它是QManWindow和QDialog父类。

    常用的设置有：
        resize(w,h) 设置窗口的大小
        move(x,y) 设置窗口的位置
    
    创建控件时把容器对象的地址给控件，就可以把控件放入到容器中。

七、Qt创造器的使用
    1、打开Qt创造器
        在终端执行：qtcreator，右键锁定到启动器。
    2、创建项目
        文件 -> 新建文件或工程 -> Qt控件项目 -> QtGUI应用 -> 填写项目名称(不要使用中文) -> 桌面 -> 选择窗口容器 -> 设置类名、
头文件名、源文件名 -> 选择是否创建界面(设置界面文件名)
    3、窗口类的构成：
        mainwindow.ui 文件会自动生成 ui_mainwindow.h(在Qt创造器中不可见)。
        ui_mainwindow.h 头文件中会自动生成 Ui_MainWindow类，该类中会包含所有mainwindow.ui文件中所画的控件。
        在ui_mainwindow.h头文件中会在Ui名字空间中自动创建MainWindow类，Ui_MainWindow会被MainWindow类继承。
        mainwindow.h头文件中会自动创建MainWindow类，默认继承QMainWindow，会有一个默认的成员Ui::MainWindow *ui，它里面有所有
界面文件中的控件。

八、Qt常用控件
    QLabel：标签控件，同来显示简单的文本，在界面上只读的
        setText 设置显示内容
        text 获取标签上的字符串，返回值是QString
    QPushButton：按钮控件
        同样具有setText、text
        重要的功能是 单击信号 clicked()，也有双击、悬停、按下、弹起信号。
    QRadioButton：单选按键，同窗口下只能有一个被选中
        重要功能是选中和取消选中信号
    QLineEdit：单行输入文本框
        常用操作时获取它的输入内容
    QTextEdit：多行输入文本框
        常用于输入大段文字，输入的内容可以换行，自带滚动条。
    QComboBox：下拉输入框
        它输入的内容只能通过下拉按键选择，是防止用户输入错误常用解决方法。
    QTextBrower：多行文本显示，支持富文本显示。
        在界面上只读，文字可以设置字号、字体、颜色、加粗、对齐等操作。
    QGroupBox：分组框，可以放入一个控制统一管理。
        最常用的是放入：QRadioButton按钮，一组的按钮只能有一个被选中。
    QxxxSilder：滑块
        有水平、垂直滑块，也可以当进度条使用。
    QSpinBox：数字滑块
        与Silder的用法基本一致，只不过它是以数字显示。
        Silder和SpinBox主要操作时：初值、最大值、进步值。
        即可以用来显示，也可以用来设置。

九、Qt创造器常用快捷键及操作
    快捷键：
        Alt+0：显示/隐藏侧边栏
        Ctrl+e 松开后按0：删除所有的分割窗口
        Ctrl+e 松开后按1：删除多余的分割窗口
        Ctrl+e 松开后按2：水平分割窗口
        Ctrl+e 松开后按3：垂直分割窗口
        Ctrl+B+S：保存所有文件并编译执行
        Ctrl+B：编译执行
        Ctrl+R：运行项目
        Ctrl+/：注释/取消注释
        Ctrl+I：自动缩进选中的代码
        Ctrl+Shift+R：批量修改变量名
        Ctrl+F：搜索、替换
        Ctrl+单击：跳转到定义位置
        Shift+F2：声明与定义之间进行切换
        Alt+Shift+u：小写转换成大写
        Alt+u：大写转换成小写
        F1：光标定位在类或对象上，打开其帮助手册
        F4：头文件与源文件之间快速切换

































一、 自定义信号和槽
    1、信号和槽必须定义在类中
    2、自定义信号和槽类必须继承QObject
    3、在类的开头写上Q_OBJECT 没有分号，此标识符必须写在项目构建之前，如果是后加上的，必须重新构建项目。
    4、信号定义在 signals：关键字下面。
    5、通过emit发送信号

    6、一个信号可以连接多个槽，当该信号发射会触发多个槽函数。
    7、多个信号可同时连接一个槽，只要有一个信号发射就会触发槽函数。

二、界面布局 
    1、在设计界面时，一般不建议直接设计窗口或控件的大小（像素点数），除非容器固定大小，否则界面改变大小时布局会乱（丑）。
    2、如果不固定窗口的大小一般使用自动布局，前提是在窗口添加一个布局器，然后设置窗口为自动布局（在窗口的空白位置右击 -> 布局 
-> 水平、垂直、栅格）。
    3、在窗口内部想让某些控件自动排列及设置大小，可以选择使用布局器：
        水平布局：QHBoxLayout
        垂直布局：QVBOXLayout
        栅格布局：QGridLayout
        布局器中的控件会根据布局器的大小自动排列控件，自动设置控件的大小。
    4、设置窗口自动布局，控件会随窗口的大小而变化，可以使用“弹簧”来约束控件的位置。

三、项目资源
    1、项目的资源一般是指项目中使用到的图片、音频、视频等。
    2、使用图片文件有两种方式：
        1.使用QPainter和QImage类读取资源文件，然后绘制在窗口或控件上。
        2.创建Qt资源文件，统一管理图片等资源文件。
    3、在窗口或控件上绘制图片
        1.由于QPainter只能工作在paintEvent函数中，因此必须覆盖此函数。
        2.QImage控制图片文件的路径即可，创建QImage对象。
        3.QPainter创建时需要提供在窗口的地址。
        4.QPainter对象调用drawImage成员函数绘制图片。
        5.paintEvent会被update自动调用。
        注意：不建议使用此方法显示图片，更多的是进行绘制图形。
    4、Qt资源文件
        1.选中项目右击 -> 添加新文件 -> Qt -> Qt资源文件 -> 填写资源文件名
        2.双击打开创建好的资源文件 -> 添加 -> 添加前缀 -> 添加文件 -> 选择要添加的文件
        3.可以在设计师中使用资源文件，选择控件右击 -> 改变样式表 -> 添加资源 -> image等。
        4.也可以在代码中调用setStyleSheet函数，为控件设置样式。 

    5、设置控件样式表的技巧
        1、在为窗口设置样式表后，窗口中的控件也会继承这个样式，我的解决方法是为控件也设置样式表，覆盖窗口的样式表。
        QWidget
        {
            background-color: rgb(255, 255, 255);
        }

        QPushButton
        {
            background-color: rgb(255, 245, 66);
            // 设置按钮的边框
            border: 1px solid rgb(124, 124, 124);
            // 设置按钮的圆角弧度
            border-radius: 5px; // 设置按钮的圆角
        }
        2、设置控件的悬停样式
        QPushButton:hover
        {
        }
        3、设置按钮按下时的效果
        QPushButton:pressed
        {
        }

四、定时器
    Qt中的QTimer有两种使用方式：
    信号：
        start成员函数，开启定时器并设置定时器的时间间隔。
        事件到后会发出timeout信号，连接槽函数即可。
    事件：
        继承QTimer 类，对该类进行扩展，并覆盖 void timerEvent(QTimerEvent *e) 事件。
        void start(int msec)成员函数，开启定时器并设置定时器的时间间隔。
        时间到后会自动执行timerEvent函数。
        注意：时间函数被执行就会再产生timeout信号。

五、线程
    Qt中的线程类不能直接使用，必须继承QThread并实现run函数。
    新的线程类对象调用start成员函数时会自动执行run函数。
    1、线程的终止
        线程对象调用 void terminate() 成员函数会终止线程，但并不会立即终止，这取决于线程的调度策略。
        terminate类似于线程的取消操作，而线程也可以回收
        线程真正终止时会发射 void terminated() 信号。
        也可以使用wait函数等待线程的终止，还可以回收线程的资源。
        类似POSIX线程里的pthread_join函数。
    2、线程ID
        static Qt::HANDLE currentThreadId()
        获取当前线程的id
        static QThread* currentThread()
        获取当前线程的句柄

六、鼠标与键盘事件
    空间其实一直都在监控鼠标与键盘，当鼠标与键盘发生操作时会调用控件中的事件函数，事件函数默认什么都不做，如果想让事件函数做一些
操作，需要继承控件并覆盖事件函数。
    // 鼠标按下
    void mousePressEvent(QMouseEvent *);
    // 鼠标弹起
    void mouseReleaseEvent(QMouseEvent *);
    // 鼠标双击
    void mouseDoubleClickEvent(QMouseEvent *);
    // 鼠标按下并移动
    void mouseMoveEvent(QMouseEvent *);
    // 键盘按下事件
    void keyPressEvent(QKeyEvent* e);
    成员函数 text 可以获取到按键的字符
    成员函数 key 可以获取到键值 与 Qt::Keyx 进行比较
    // 键盘弹起事件
    void keyReleaseEvent(QKeyEvent* e);




























一、线程同步
    互斥量（互斥锁）
    QMutex 就是POSIX中的pthread_mutex_的封装。
    有两个成员函数lock、unlock。

    读写锁
    QReadWriteLock它比QMutex更实用
    常用的三个成员函数lockForRead、lockForWrite、unlock
    A读 B读 OK
    A写 B读 No
    A写 B写 No

    信号量
    QSemaphore用于管理多个资源
    QSemaphore构造时设置资源数量
        acquire(n) 获取资源  减去资源数  如果不够减则等待
        release(n) 归还资源  加上资源数  

二、网络通信
    使用网络模块前要先在.pro文件中添加network
        QT += core gui network

    QUdpSocket类是Qt对UDP协议加socket的封装。
        1、创建QudpSocket类对象
        2、绑定ip地址和端口号
        3、链接readyRead()信号，当此信号发射后，就表示可以接收数据了。
        4、在槽函数中调用readDatagram函数接收数据
        qint64 readDatagram(char *data, qint64 maxlen, QHostAddress *host = 0, quint16 *port = 0);
        host：发送者的地址
        port：返回时的端口号
        5、返回数据
        qint64 writeDatagram(const char *data, qint64 len, const QHostAddress &host, quint16 port);
        host和port是readDatagram函数收到的。

        注意：每个QUdpSocket对象都需要绑定一个地址和端口号。

    练习1：使用QUdpSocket实现一个带界面的点对点程序（地址、端口、接收、发送、按钮）

    Qt中封装了TCP协议QTcpServer、QTcpClient
        QTcpServer负责服务端
            1、创建QTcpServer对象
            2、监听list需要的参数时地址和端口
            3、当有新的客户端连接成功时，会发射newConnection信号。
            4、在newConnection信号的槽函数中，调用nextPendingConnection函数，获取新连接QTcpSocket对象。
            5、连接QTcpSocket对象的readyRead信号
            6、在readyRead信号的槽函数使用read接收数据
            7、调用write成员函数发送数据

        QTcpSocket负责客户端
            1、创建QTcpSocket对象
            2、当对象与Server连接成功时，会发射connected信号
            3、调用成员函数connectToHost连接服务器，需要的参数地址和端口号
            4、connected信号的槽函数中开启发送数据
            5、使用write发送数据，read接收数据

    练习：实现Qt版的聊天室

    


        

