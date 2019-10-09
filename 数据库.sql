一、数据库介绍
    1、为什么使用数据库
        计算机的资源有限，因此不可能把数据一直存储在内存中，而且内存一旦掉电数据就会不存在，我们需要所内存中的数据存储到文件中，
方便下次的编辑、拷贝。
        但随着程序越来越复杂，数据也就会越来越庞大，管理这些数据就会成为编程中最难、最重要的问题。
        使用文件保存不安全，可能会被误删，也可能被覆盖。
            而数据库的访问是需要用户名、密码、相应的权限及命令。
        文件读取数据并解析需要大量的重复代码，这种操作效率很低。
            从数据库中查询数据只需要提供条件即可。
        文件中删除一条记录异常麻烦，而且不同的程序对于文件的操作不同接口也不相似，因此访问文件的代码不能被复用。
        对于这个问题就有人提出一个设想，统一文件的访问接口和访问方法，对文件进行统一管理，背后再增强对于数据管理、读取的优化操作，
使用对数据的管理、使用方便又快捷。
    2、什么是数据库
        数据库，顾名思义就是数据的仓库（电子文件柜），而对数据进行增加、删除、修改、查询等操作由数据库管理系统（DBMS）进行，对于
数据库进行设计、维护、管理的人员叫DBA。
    3、数据库的类型
        层次型数据库：数据的存储类似一棵树，以上下层级关系来组织数据。
        网状型数据库：数据的存储类似一副图，各个数据节点和其他节点都连接关系。
        关系型数据库：关系模型就是一张二维表，任何数据都可以通过行号和列确定，容易理解、使用方便。
    4、目前主流的关系型数据库
        商用的：Oracle、SQL Server、DB2
        开源的：MySQL
        桌面的：Access
        嵌入式的：SQLite，适合于手机、桌面程序

二、SQL语言介绍
    1、什么是SQL
        SQL是结构化查询语言的缩写，用来操作数据库，主要对数据用来增、删、改、查，高级操作是对数据库进行管理、维护。
        目前所有的关系型数据库都支持SQL，因此我们只要学会SQL就能操作所有的数据库。
        虽然SQL已经被ANSI组织定义为标准，但不幸的是每个数据库对标准的支持都不太一致，大多数的数据库都对SQL进行了扩展。
        理论上SQL可以操作所有的数据库，但如果使用了某个数据库的扩展语句，换一个数据库后就不能再执行了。
        但是SQL的核心功能绝大数数据库都是支持。
    2、SQL语言的分类
        数据定义语言：用于建立、修改、删除数据库对象
            CREATE 用于创建表或其他对象结构
            ALTER 用于修改表或其他对象结构
            DROP 用于删除表或其他对象
            TRUNCATE 用于删除表中的数据，保留表结构

        数据操作语言：用于改变表中的数据
            INSERT 将数据插入到表中
            UPDATE 修改表中已经存在的数据
            DELETE 删除表中的数据
            表中数据改变后需要执行事务控制语言才能所改变应用到数据库中。

        事务控制语言：用来维护表中数据的一致性
            COMMIT 提交，确认已经进行修改的数据
            ROLLBACK 回滚，消除已经进行修改的数据改变
            SAVEPOINT 保存点，用于回滚操作

        数据控制语言：用于执行权限的授予和回收操作
            GRANT 用于给用户或角色授予权限
            REVOKE 用于回收用户或角色的权限
            
        数据查询语言
            SELECT
三、如何访问数据库
	1、远程登录
		ubuntu下开启telnet 
			sudo apt-get install openbsd-inetd
			sudo apt-get install telnetd
			sudo /etc/init.d/openbsd-inetd restart
			sudo netstat -a | grep telnet 检查是否安装成功	
			telnet 192.168.0.121 在windows下测试
				输入用户名
				输入密码
			mysql -utest -p123456
			
			telnet 192.168.6.66
			sqlplus student/123456 进入Oracle数据库
			
		ubuntu下开启ssh
			sudo apt-get install openssh-server
			sudo ps -e |grep ssh 检查是否安装成功
			ssh zhizhen@192.168.0.121 在windows下测试
			输入密码
			mysql -utest -p123456
	2、客户端连接
		连接名 自定义
		用户名 student
		密码 123456 
			保存口令
		地址：192.168.6.66
		端口：1521
		SID：orcl

四、SQL中的数据类型
    MySQL     Oracle
    n/a     | byte      单字节数据，布尔类型 
    int     | Number    整数
    float   | Number    浮点型
    char    | char      定长字符串
    varchar | varchar2   变长字符串
    date    | date      日期

    char(n) 表示字符串长度
        char(10) 数据是“123”，依然存储10个字符
        适合存储字符串长度波动不大的字符串
        优点：是速度快，缺点：浪费空间
    varchar(n) 表示字符串长度
        varchar(10) 数据是“123”，依然存储4个字符
        适合存储字符串长度不确定，波动比较大的字符串
        优点：会根据字符串的长度进行存储，节约存储空间
        缺点：与char相比速度稍慢
    Oracle中的Number(P,S)
        P表示总位数，S表示小数点后面的位数
        Number(4) 表示四整数
        Number(4,2) 小数后最多两位

五、数据定义语言
    1、创建表
    CREATE TABLE 表名(字段名 字段类型,...);
    CREATE TABLE Student(
        name char(20),
        sex char(1),
        age int,
        id char(8));
    查表表结构：DESC 表名;
    查看数据库中所有表： show tables;

    2、修改表
        1.修改表名
        RENAME TABLE 旧表名 TO 新表名;
        RENAME TABLE student TO Teacher;
        
        2.增加列
        ALTER TABLE 表名 ADD (字段名 字段类型);
        ALTER TABLE Teacher ADD (id char(6));
        注意：只能增加到表的末尾，不能插入到中间。
        
        3.删除列
        ALTER TABLE 表名 DROP 字段名;
        ALTER TABLE Teacher DROP sex;

        4.修改列
        ALTER TABLE 表名 MODIFY id char(8);
        ALTER TABLE Teacher MODIFY id char(8);
    
    3、删除表
        1.删除表数据
        TRUNCATE 表名;

        2.删除表，数据和结构都不存在
        DROP 表名;

六、数据操作语言
    1、插入数据
    INSERT INTO 表名(字段名) VALUES(数据);
    INSERT INTO Student(name,sex,age,id) VALUES('hehehehehehe','m',18,1907123);
    注意：SQL中可以使用''表示字符串

    2、修改表数据
    UPDATE 表名 SET 字段名=数据,... where 条件;
    UPDATE Student SET sex='w',name='hehe' where not id=1907123;
    UPDATE Student SET age=17 where id=1907123 or id=1907124;

    3、删除表数据
    DELETE FROM 表名 where 条件;
    DELETE FROM Student where id=1907123;

七、事务控制语言
    注意：数据定义语言立即有效，不能进行事务控制，只有数据操作语言才能进行事务控制。
    1、COMMIT 提交
    在Oracle数据库，一个用户向表中插入数据（他自己能够查询到），其它用户并不能立即查询到，只有执行了 COMMIT 命令后其他用户才能
查询到。
    INSERT INTO Student(name,sex,age,id) VALUES('xixi','w',20,1907125);
    COMMIT;

    在MySQL数据库中，默认设置的 autocommit 一个用户插入的数据，其他用户也能立即查看到。
    set session autocommit=0; --开启当前连接的自动提交
    set global autocommit=0;  --开启所有连接的自动提交，需要root权限
    set session autocommit=1; --关闭当前连接的自动提交

    2、回滚
    当使用数据操作语言对数据进行更改后，如果没有进行COMMIT，那么就可以撤销（反悔），使用 ROLLBACK 命令，可以把数据还原到数据更改
前的样子。

    3、保存点
    如果向表中插入了四条记录，此时如果直接rollback，则四条记录都会消失，如果只想保留一条、两条或三条，需要在每插入一个记录后设置
一个保存点，使用 rollback to savepoint 保存点;可以回到任意一条记录后。

























--CREATE TABLE Teacher(id int,name char(20),subject char(20),salary float,start_time date,birth date);

CREATE TABLE Teacher(id int,name char(20),subject char(20),salary float);
INSERT INTO Teacher VALUES(1001,'mage1','S1',6666.666);
INSERT INTO Teacher VALUES(1002,'mage2','S2',6677.666);
INSERT INTO Teacher VALUES(1003,'mage3','S3',6688.666);
INSERT INTO Teacher VALUES(1004,'mage4','S4',6699.666);
INSERT INTO Teacher VALUES(1005,'mage5','S5',1010.666);
INSERT INTO Teacher VALUES(1006,'mage6','S6',1111.666);
INSERT INTO Teacher VALUES(1001,'mage1','S1',6666.666);
INSERT INTO Teacher VALUES(1007,'mage7','S1',1212.666);
INSERT INTO Teacher VALUES(1008,'age','S1',6611.666);
INSERT INTO Teacher VALUES(1009,'bge','S1',6622.666);

CREATE TABLE Employee(id int,name char(20),post char(20),base_sal float,royalty float);
INSERT INTO Employee VALUES(19001,'xiu','SSS',6000,1.6);
INSERT INTO Employee VALUES(19002,'xie','SS',5500,1.4);
INSERT INTO Employee VALUES(19003,'pang','SSSSS',10000,1.8);
INSERT INTO Employee(id,name,post,base_sal) VALUES(19004,'sun','A',15000);
INSERT INTO Employee VALUES(19005,'xiu1','SSS',5000,1.4);
INSERT INTO Employee VALUES(19006,'xiu2','SS',7000,1.2);
INSERT INTO Employee VALUES(19007,'xiu3','SSS',4500,1.8);
INSERT INTO Employee VALUES(19008,'xiu4','SSS',4500,1.6);
INSERT INTO Employee VALUES(19009,'xiu4','SSS',4500,1.9);

CREATE TABLE emp(id int,dept_id int,name char(20),post char(20),base_sal float);
INSERT INTO emp VALUES(1001,101,'bob','S1',5000.0);
INSERT INTO emp VALUES(1002,101,'sam','S2',5000.0);
INSERT INTO emp VALUES(1003,102,'tom','S3',6000.0);
INSERT INTO emp VALUES(1004,102,'john','S4',6000.0);
INSERT INTO emp VALUES(1001,103,'mery','S5',7000.0);
INSERT INTO emp VALUES(1001,103,'jams','S6',7000.0);

CREATE TABLE dept(id int,name char(20),addr char(20));
INSERT INTO dept VALUES(101,'info','hangzhou');
INSERT INTO dept VALUES(102,'tele','shanghai');
INSERT INTO dept VALUES(103,'pers','beijing');

一、数据查询语言
    1、查询表中
    SELECT 字段1,字段2... FROM 表名;
        例：查询姓名与年龄
        SELECT name,age FROM Student;
        * 在SQL中也是通配符，代表所有字段
    2、SQL中的数学运算 + - * /
        例：查询每个教师的日薪，按每月30天计算
        SELECT name,salary/30 FROM Teacher;
        例：查询每个教师的年薪
        SELECT name,salary*12 FROM Teacher;
    3、字段别名
        为查询结果新取一个字段名
        例：查询每个教师的年薪，并为查询结果设置的字段名为yearsal
        SELECT name,salary*12 yearsal FROM Teacher;
    4、字符串操作
        Oracle中使用 || 连接字符串,而在MySQL它逻辑或运算。
        CONCAT(s1,s2,...)
        返回连接参数产生的字符串，一个或多个待拼接的内容，任意一个人为NULL则返回值为NULL。
        例：显示所有教师名和所教科目中间有下划线连接
        SELECT concat(name,'_',subject) FROM Teacher;

        CONCAT_WS(x,s1,s2,...)
        返回多个字符串拼接之后的字符串，每个字符串之间有一个x。
        例：连接字符串，并使用空格分隔。
        SELECT CONCAT_WS('_',name,subject,'HH') FROM Teacher;

        SUBSTRING(s,n,len)、MID(s,n,len)
        两个函数作用相同，从字符串s中返回一个第n个字符开始、长度为len的字符串。
        例：获取mage 编号
        SELECT SUBSTRING(NAME,5,1) FROM Teacher;
        SELECT MID(NAME,5,1) FROM Teacher;

        LEFT(s,n)、RIGHT(s,n)
        前者返回字符串s从最左边开始的n个字符，后者返回字符串s从最右边开始的n个字符。
        例：获取小马哥名字，不要编号
        SELECT LEFT(name,4) FROM Teacher;

        INSERT(s1,x,len,s2)
        返回字符串s1，其子字符串起始于位置x，用字符串s2取代s1的len个字符。
        "12345678" 3,2,"ABCDE"
        SELECT INSERT('12345678',3,2,'ABCDEF');

        REPLACE(s,s1,s2)
        返回一个字符串，用字符串s2替代字符串s中所有的字符串s1。
        SELECT REPLACE('12345678','345','ABC');

        LOCATE(str1,str)、POSITION(str1 IN str)、INSTR(str,str1) 三个函数作用相同，返回子字符串str1在字符串str中的开始位置
    （从第几个字符开始）。
        SELECT LOCATE('123','ABCDE123DEFWE');

        FIELD(s,s1,s2,...) 返回第一个与字符串s匹配的字符串的位置。

        SELECT FIELD('123','ABC','DEF','123','ADW');

        重点：SQL语言中下标从1开始

    5、排重显示
        SELECT DISTINCT 字段 FROM 表名;
        查询：学校一共开设多少科目
        SELECT DISTINCT subject FROM Teacher;
    
    6、条件查询
        SELECT 字段 FROM 表名 WHERE 条件;
        当WHERE条件为真时显示相关数据，配合相关比较运算符。
            > < >= <= = !=
        例：查询所有教S1科目的老师
        SELECT * FROM Teacher WHERE subject = 'S1';
        例：查询所有不教S1科目的老师
        SELECT * FROM Teacher WHERE subject != 'S1';
        SELECT * FROM Teacher WHERE not subject = 'S1';
        例：查询所有年薪超过8w的老师
        SELECT name,id,salary*12 FROM Teacher WHERE salary*12>=80000;

        注意：SQL中字符串可以直接使用 比较运算符，与strcmp比较规则一致。
        SELECT * FROM Teacher WHERE name > 'mage5';

        SELECT * FROM 表名 WHERE x BETWEEN n AND m;
        显示x值 在n到m之间的数据
        例：查询月薪在6667,6688之间的教师信息
        SELECT * FROM Teacher WHERE salary BETWEEN 6667 AND 6688;
        SELECT * FROM Teacher WHERE salary>6667 AND salary<6688;

        SELECT * FROM 表名 WHERE x in(n1,n2,n3);
        显示x值在(n1,n2,n3,...)列表中的相关数据
        例：
        SELECT * FROM Teacher WHERE subject in('S1','S4','S5');

        SELECT * FROM 表名 WHERE x LIKE str;
        SQL中字符串可以进行模糊查询，str中可以使用通配符
            %代表任意多个字符 _代表一个字符
        例：查询名字mage开头的相关老师信息
        SELECT * FROM Teacher WHERE name LIKE 'mage%';
        例：查询名字以1结尾的相关老师信息
        SELECT * FROM Teacher WHERE name LIKE '%1';
        例：查询名字以ge和任意一字符结尾的相关老师信息
        SELECT * FROM Teacher WHERE name LIKE '%ge_';

        注意：在SQL中也可使用逻辑运算，AND OR NOT(&& || !不一定支持)

    7、空值处理
        在SQL中空值是一种特殊数据，任何数据与空值进行计算结果为空。
        IFNULL(x,n) 如果x的值为空，则用n来替换（MySQL，Oracle使用nvl函数）。
        例：查询员工表中的年薪
        SELECT name,base_sal*IFNULL(royalty,1)*12 FROM Employee;
        例：查询有年终奖的员工
        SELECT * FROM Employee WHERE royalty IS NULL;
        例：查询有年终奖的员工
        SELECT * FROM Employee WHERE royalty IS NOT NULL;

    8、排序
        是对查询结果进行排序，而不是对数据库中表的数据进行排序。
        SELECT 数据 FROM ORDER BY 字段 类型;
        默认升序，DESC 降序
        例：按基本工资进行排序
        SELECT * FROM Employee ORDER BY base_sal;
        例：按年终奖系数进行降序
        SELECT * FROM Employee ORDER BY royalty desc;
        例：基本工资为第一个排序字段，年终奖系数为第二排序字段
        SELECT * FROM Employee ORDER BY base_sal,royalty;

    9、单行函数
        对表中的数据每处理一行就返回一个结果，这种函数叫单行函数。
        UPPER 小写转大写
            SELECT id,UPPER(name) FROM Employee;
        LOWER 大写转小写
            SELECT id,UPPER(name),LOWER(post) FROM Employee;
        INITCAP 首字母大写(MySQL不支持)
            SELECT id,INITCAP(name) FROM Employee;
        LENGTH 计算字符串长度
            SELECT id,LENGTH(name) FROM Employee;
        to_char 其他类型的数据转换成字符串(MySQL不支持)
    
    10、组函数
        一次查询只得到一个结果，如果在数据进行分组的情况下，一个分组得到一个结果。
        COUNT 计数 
        例：统计101部门的员工数量
        SELECT COUNT(id) FROM emp WHERE dept_id=101;
        
        MAX 求最大值
        例：求基本工资最高值
        SELECT MAX(base_sal) FROM Employee;

        MIN 求最小值
        例：求基本工资最低值
        SELECT MIN(base_sal) FROM Employee;

        SUM 求和
        例：求基本工资总支出
        SELECT SUM(base_sal) FROM Employee;

        AVG 求平均值
        例：求员工平均工资
        SELECT AVG(base_sal) FROM Employee;

    11、多表查询
        根据员工表，部门表查询出每个员工的上班地点。
        SELECT emp.name,addr FROM emp,dept WHERE dept_id=dept.id;

    12、分组查询
        SELECT 组函数(字段) FROM 表名 GROUP BY 分组条件;
        例：每个部门的平均工资
        SELECT dept.name,AVG(base_sal) FROM emp,dept WHERE emp.dept_id=dept.id GROUP BY dept_id;

        HAVING 筛选分组后的数据
        SELECT 组函数(字段) FROM 表名 GROUP BY 分组条件 HAVING 筛选;
        例：显示部门的平均工资>6000的部门
        SELECT dept.name,AVG(base_sal) FROM emp,dept WHERE emp.dept_id=dept.id GROUP BY dept_id HAVING AVG(base_sal) > 6000;



























CREATE TABLE Emp(id int,dept_id int,mgr_id int,name char(20),post char(20),salary float,start_time date,birth date);
INSERT INTO Emp VALUES(2019003,1001,2019001,'sam','P1',5000,STR_TO_DATE('2019-9-16','%Y-%m-%d'),STR_TO_DATE('1999-9-16','%Y-%m-%d'));
INSERT INTO Emp VALUES(2019004,1001,2019003,'bob','P3',5500,sysdate(),STR_TO_DATE('1999-9-16','%Y-%m-%d'));



13、日期数据
    注意：数据库中的日期是一种特殊类型，需要一些函数进行转换。
    Oracle数据库
        TO_DATE(date_str,format_str) 把字符串按照一定的格式转换成日期数据            
            TO_DATE('2019-5-5','yyyy-mm-dd')
        TO_CHAR(date,format_str) 把日期数据按照一定的格式转换成字符串            
            TO_CHAR(date,'yyyy-mm-dd')

    yyyy    四位年份
    yy      两位年份
    mm      整数月份
    mon     月份简拼
    month   月份全拼
    dd      整数天数
    dy      周几简拼
    day     周几全拼
    hh12    12小时制
    hh24    24小时制
    mi      分钟
    ss      秒

    MySQL数据库
        STR_TO_DATE(str,format) 把字符串按照一定的格式转换成日期数据
        DATE_FORMAT(date,format) 把日期数据按照一定的格式转换成字符串   

    %Y      四位年份
    %y      两位年份
    %M      月份全拼
    %m      整数月份
    %D      带英文后缀的天数
    %d      整数天数
    
    sysdate() 获取当前系统时间

14、子查询
    把一个查询的结果当作另一个查询的数据源
    例：查询员工表汇中谁是领导
    SELECT empno,ename FROM emp WHERE empno IN (SELECT DISTINCT mgr FROM emp);
    例：查询普通员工信息
    SELECT empno,ename FROM emp WHERE empno NOT IN (SELECT DISTINCT mgr FROM emp WHERE mgr NOT IS NULL);
    注意：空值能和任意数据匹配

一、数据约束
    约束：对表中的数据加以限制，不允许非法数据插入
    注意：MySQL数据库不能很好的支持约束条件
        主键：非空且唯一
        PRIMARY KEY
        CREATE TABLE student(id int PRIMARY KEY,name char(20),sex char);
        INSERT INTO student VALUES(1,'TOM','M');

        唯一：数据不能重复
        UNIQUE
        CREATE TABLE student2(id int PRIMARY KEY,name char(20) UNIQUE,sex char);
        INSERT INTO student2 VALUES(1,'TOM','M');

        非空：数据不能为空，插入时不能省略
        NOT NULL
        CREATE TABLE student3(id int PRIMARY KEY,name char(20) UNIQUE,sex char NOT NULL);
        INSERT INTO student3 VALUES(1,'TOM','M');

        检查：设置检查条件
        CHECK
        CREATE TABLE student4(id int PRIMARY KEY,name char(20) UNIQUE,sex char NOT NULL,age int CHECK(age > 8));
        INSERT INTO student4 VALUES(1,'TOM','M',7);

        外键：与主键配合使用，用于表连接，外键的数据必须要在主键中能够找到。
        FOREIGN KEY

        先主键
        CREATE TABLE student(id int PRIMARY KEY,name char(20),sex char);
        INSERT INTO student VALUES(2,'mery','w');
        后外键
        CREATE TABLE report(
            id int,
            mr float,
            cr float,
            er float,
            CONSTRAINT fk_id FOREIGN KEY(id) REFERENCES student(id)
        );

        INSERT INTO report VALUES(1,80,90,100);
        此时在插入数据时，必须要确定主外键字段的值在主键中能够找到。
        注意：主键在删除数据时，必须把外键对应的数据先删除，才能删除主键。
        ON DELETE CASCADE
        CREATE TABLE report(
            id int,
            mr float,
            cr float,
            er float,
            CONSTRAINT fk_id FOREIGN KEY(id) REFERENCES student(id) ON DELETE CASCADE
        ); 

二、视图
    视图就是一张虚拟的表，它的本质是一个SQL语句。
    视图的优点就是使用方便，还不占用多余存储空间，缺点是效率低，不适合长期频繁查询。
    CREATE VIEW 视图名 as <SELECT>
    CREATE VIEW student_view as (SELECT student.id,name,sex,mr,cr,er FROM student,report);

三、索引
    是数据库为了提高查询速度所建立的一种优化机制。
    自动创建：当字段具有唯一性约束时，系统会自动为此字段创建索引
    手动创建：
        ALTER TABLE 表名 ADD INDEX index_name 字段名;
        创建索引时即耗费时间，又耗费空间。

四、关系型数据库三范式
    1、字段不可再拆分(原子)，所有的关系数据库必须满足第一范式。
    2、满足第一范式的前提下，当有重复列数据的前提下，应该再拆分一张表。
        房间ID  类型  单价  旅客ID
        1001      A   200  123001
        1001      A   200  123002
        1001      A   200  123003
    3、数据之间不应该有依赖性。
        学号 -> 院系 班级 姓名 性别 成绩

五、使用C++语言
    1、安装工具库
    sudo apt-get install libmysqlclient-dev
    安装完成后，需要的头文件安装在 /usr/include/mysql目录下

    2、打开/usr/include/mysql/mysql.h头文件，常用的函数接口都在此头文件中。
    MYSQL mysql;

    MYSQL* mysql_init(NULL);
    功能：初始化MYSQL结构

    // 连接到MySQL服务器
    MYSQL* mysql_real_connect(MYSQL *mysql, 
        const char *host,    // 主机名或ip地址
        const char *user,    // 用户名
        const char *passwd,  // 密码
        const char *db,      // 数据库
        unsigned int port,   // 端口号
        const char *unix_socket,   // NULL
        unsigned long clientflag   // 0
    );

    -- 设置当前连接使用的字符集
    int mysql_set_character_set(MYSQL *mysql, const char *csname);

    -- 执行指定的SQL查询语句
    int mysql_query(MYSQL *mysql, const char *q);

    -- 返回上次执行语句的结果列的数目
    int mysql_field_count(MYSQL *mysql);

    -- 检索完整的结果集至客户端
    MYSQL_RES* mysql_store_result(MYSQL *mysql);

    -- 从结果集中获取下一行
    MYSQL_ROW mysql_fetch_row(MYSQL_RES *result);

    -- 释放结果集使用的内存
    void mysql_free_result(MYSQL_RES *result);

    -- 关闭服务器连接
    void STDCALL mysql_close(MYSQL *sock);