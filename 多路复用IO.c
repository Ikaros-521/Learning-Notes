
一、IO模型介绍（读取数据的模式）
	1、阻塞IO，常用的scanf、printf、read、write、cout、cin
	2、非阻塞IO，recv、send和Qt中read、write
	3、多路复用IO
	4、信号驱动IO
	5、异步IO
	
二、多路复用IO
	在不创建新的进程和线程的情况下监控多个文件描述符，多应用于网络编程时一个服务端程序为多个客户端程序提供服务，多用于在业务逻辑
简单，客户端需要的服务时间短，响应时间无太高要求的场景。
	
三、使用select函数实现多路复用IO
	int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
	功能：监控多个文件描述符的 读、写、异常 操作
	nfds：最大文件描述符+1
	readfds：监控读操作文件描述符集合
	writefds：监控写操作文件描述符集合
	exceptfds：监控异常操作文件描述符集合
	timeout：设置超时时间
	返回值：监控到文件描述符的个数,超时返回0，出错返回-1

	void FD_CLR(int fd, fd_set *set); 
	功能：从集合中删除文件描述符
	int  FD_ISSET(int fd, fd_set *set);
	功能：测试集合中是否有文件描述符存在
	void FD_SET(int fd, fd_set *set);
	功能：向集合中添加文件描述符
	void FD_ZERO(fd_set *set); 
	功能：清空文件描述符集合
	
	select设计不合理的地方：
		1、所有被监视的文件描述符都需要检查（效率不高）。
		2、每次调用select都需要向它传递新的监视对象信息	
	select的优点是：
		程序的兼容性高
	
	
	int pselect(int maxfdp1, fd_set *readset, fd_set *writeset, fd_set *exceptset, const struct timespec *timeout, const sigset_t *sigmask);
	功能：与select的功能大致类似
	区别：
		1、select函数用的timeout参数，是一个timeval的结构体（包含秒和微秒），然而pselect用的是一个timespec结构体（包含秒和纳秒）
		2、select函数可能会为了指示还剩多长时间而更新timeout参数，然而pselect不会改变timeout参数
		3、select函数没有sigmask参数，当pselect的sigmask参数为null时，两者行为时一致的。有sigmask的时候，pselect相当于如下的
select()函数，在进入select()函数之前手动将信号的掩码改变，并保存之前的掩码值；select()函数执行之后，再恢复为之前的信号掩码值。

四、使用poll函数实现多路复用IO
	int poll(struct pollfd *fds, nfds_t nfds, int timeout);
	fds：所有被监控的文件描述符结构体数组
	nfds：数组的长度
	timeout：超时时间，毫秒单位
	
	struct pollfd
	{
		int fd; 	//被监控文件描述符
		short events; // 等待的需要监控事件
		short revents; // 实际发生了的事件，也就是返回结果
	};
	events:
		POLLIN		普通或优先级带数据可读
        POLLPRI		高优先级数据可读
        POLLOUT		普通数据可写
		POLLRDHUP	对方socket关闭
		POLLERR		发生错误
		POLLHUP		发生挂起
		POLLNVAL	描述字不是一个打开的文件
	
	poll特点：
		1.文件描述符没有最大限制 -数据结构：链表
        2.每次调用都需要将fd集合从用户态拷贝到内核态
        3.内核需要遍历所有fd，效率低
	

五、使用epoll函数实现多路复IO
	int epoll_create(int size);
	功能：创建用于保存被监控文件描述符的空间
	int epoll_ctl(int epfd, int  op,  int  fd,  struct
       epoll_event *event);
    功能：向文件中添加、删除，文件描述符
    int epoll_wait(int epfd, struct epoll_event *events,
                      int maxevents, int timeout);
    功能：监控文件描述符
    
	
	1.文件描述符没有最大限制 --数据结构：红黑树
    2.只需拷贝一次fd到内核态
    3.内核只需判断就绪链表是否为空，不需要遍历所有fd，效率高，并把就绪fd拷贝到用户空间
	
	
	
