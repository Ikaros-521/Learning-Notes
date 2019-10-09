一、为什么使用模板
    1、C/C++是一种静态类型语言（预处理->汇编->编译->链接），好处是速度快，缺点是实现通用代码麻烦。例如：实现支持所有类型的快速排序。
    2、借助函数重载实现通用代码，好处是实现简单，但代码段会增加。
    3、借助宏函数实现通用代码，类型检查不严格。
    4、借助回调函数实现通用代码，使用麻烦。
    5、由于以上原因C++之父在C++实现了模板技术，让C++能够支持泛型编程。

二、函数模板
    1、函数模板的定义
        template <typename 类型参数1,typename 类型参数2,...>
        类型参数1 函数名(参数类型2 参数名)
        {
            return 返回值;
        }

        template <typename T>
        T find(T* arr,size_t len)
        {
            return val;
        }

        可以用任何标识符作为类型参数名，但使用‘T’ 是约定俗成的，它表示调用这个函数时所指定的任意类型。

    2、函数模板的使用
        C++编译的编译器并不是把模板编译成一个可以处理任何类型的单一实体，而是根据模板的使用者的参数，产生不同的函数的实体。
        根据具体类型代表模板参数生成函数实体过程叫实例化。

        模板是在使用时才实例化，可以自动实例化，也可以手动实例化（在函数调用时函数名与小括号之间加<类型参数>)。

        每个函数模板都会进行二次编译，第一次编译在实例化之前，检查模板代码本身是否正确，第二次是实例化过程中，结合所使用类型参数，再
次检查模板代码，是否所有的代码都有效。  
        注意：第二次编译才会生成二进制指令，第一次编译仅仅是在编译器内部生成一个用于描述模板的数据结构。

    3、函数模板的隐式推断
        函数模板虽然可以手动实例化，但使用麻烦，因此一般都根据参数类型进行隐式推断模板的参数。
        注意：不能隐式推断的三种情况
        1、函数参数与模板参数类型没有关系
        2、不允许隐式类型转换
        3、返回值类型不能隐式推断
    
    4、函数模板与默认形参之间有冲突。

    5、普通函数与同名的模板函数构成重载，编译器会优先调用普通函数，如果实现一个与模板函数功能一致的普通函数，那么这叫做模板函数的
特化。
    注意：一般char*类型都需要特化。

    练习1：实现冒泡、选择、插入、快速、归并、堆等排序算法的函数模板。

三、类模板
    1、类模板的定义
    template <typename M,typename R,typename A,typename O...>
    class Test
    {
    public:
        M val;
        Test(A a)
        {
            O var;
        }
        R func(void)
        {
        
        }
    };

    2、类模板的使用
        类模板的参数不支持隐式推断，必须显示指定类型参数。
        类名<类型...> 对象;

        类模板分为两步进行实例化：
        编译期：编译器将类模板实例化类，并生成类对象创建指令。
        运行期：处理器执行类对象创建指令，将类实例化为对象。
        类模板也是一种静态多态。

        类模板中，只有那些被调用的成员函数才实例化出代码，即产生二进制指令（调用谁实例化谁）。

    3、类模板中的静态成员
        静态成员需要在类外定义，这一点不改变，但与普通类的定义不同。
        template <typename ...> 类型 类名<...>::成员名;
    
    4、递归实例化
        类模板的参数可以是任何类型，只有该类型提供类模板所需要的功能。
        类模板的实例化已经是一个有效的类型了，因此它也可以当作类模板的参数，这种叫作递归实例化。
        Vectors<Vectors<int>> //二维数组
        Test<Test<int>>

        练习2：实现一个顺序栈的模板类。
    5、类的局部特化
        当类的某个成员函数不能通用，需要对特殊类型(char*)实现一个特殊版本，这叫类的局部特化。
        template<> 类型 返回值类型 类名<类型>::函数名(参数)
        {

        }
        注意：在类外实现
    6、全类特化
        当需要针对某种类型对类全部实现一个特殊版本，这种叫类的全类特化。
        template <> 类名<类型>
        {
            ...
        };

    7、类模板的缺省值
        类模板的类型参数可以设置默认值类型，规则与函数的默认形参基本一致（设置缺省值类型靠右）。
        后面的类型参数可以使用前面的类型，但前面不能使用后面的。

    8、普通数据也可以作为模板参数
        template <typename T,类型 B>
        {
            int arr[B];
        }

        给类模板一个数据，在类中就可以像使用宏明一样使用参数。
        注意：实例化类中提供的数据必须是常量。
    作业：实现List模板类


1、模板的技巧
    1、typename可以用class代替
    2、不能直接使用模板父类的成员
#include <iostream>
using namespace std;

template <class T>
class Base
{
public: 
	void func(void)
	{
		cout << "bbbb" << endl;
	}
};

template <typename T>
class Test:public Base<T>
{
public:
	Test(void)
	{
		Base<T>::func();
	}
};

int main()
{
	Test<int> t;
}
    3、在类模板中可以定义虚函数（多态），但虚函数不能是模板函数。

























一、STL介绍
    STL标准模板库，由惠普实验室提供，里面集成了常用的数据结构类模板和算法函数模板等。
    容器：用来存储各种类型数据的数据结构。
    迭代器：类似于专门用来指向容器成员的指针，用来遍历、操作、管理容器中的成员，可以大大提高容器的访问速度。
    算法：STL实现了常见的排序、查找算法。

    List：双端链表容器
    iterator：用来指向容器中的元素
        begin() 获取指向第一个元素的迭代器
        end() 获取指向最后一个元素的下一个位置
    相关使用参考：https://blog.csdn.net/Ikaros_521/article/details/100091859

    vector：向量容器，俗称数组
#include <iostream>
#include <vector>
using namespace std;

void show(vector<int>& arr)
{
	for(int i=0; i<arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	// 创建向量，设置容量并初始化
	vector<int> arr(12,0);
	show(arr);

	// 向量支持[]运算符，所以被称为数组
	for(int i=0; i<10; i++)
	{
		arr[i] = i;
	}
	show(arr);

	vector<int> arr1(10,0);	
	// 支持比较运算符
	cout << (arr[0]==arr1[0]) << endl;

	// at成员函数,相当于[]操作
	for(int i=0; i<arr.size(); i++)
	{
		cout << arr.at(i) << " ";
	}
	cout << endl;

	// 获取向量的容量 
	cout << arr.capacity() << endl;
}

    stack、queue：栈和队列
    deque：双端队列，用法与向量基本一致，但可以在头和尾快速插入和删除元素
#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> d(10,0);
	for(int i=0; i<d.size(); i++)
	{
		d[i] = i;
	}

	for(int i=0; i<d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}

    set：集合容器，集合中的数据会自动排序，不能重复（赋重复值也没用）。
#include <iostream>
#include <set>
using namespace std;

int main()
{
	int arr[5] = {4,3,2,2,5};
	set<int> s;
	// 在集合中插入元素
	s.insert(arr,arr+5);
	set<int>::iterator it;
	for(it=s.begin(); it!=s.end(); it++)
	{
		cout << *it << " ";
	}
	// 返回某个值元素的个数
	cout << endl << s.count(2) <<" "<<s.count(1)<< endl;
	// 返回指向大于（或等于）某值的第一个元素的迭代器
	cout << *s.lower_bound(1) << endl;
}
    
    map：是一种关联容器，在其他编程语言中叫字典，C++中叫映射，以key/value键值对的方式进行存储，key的值不能重复。
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int,string> m;
	// 插入元素
	m.insert(make_pair(10010,"hehe"));
	m.insert(make_pair(10011,"haaa"));
	m.insert(make_pair(10012,"xixi"));
	m.insert(make_pair(10013,"ohho"));
	m.insert(make_pair(10013,"ohho"));
	cout << m.size() << endl;
	cout << (*m.find(10011)).second << endl;

	map<int,string>::iterator it;
	for(it=m.begin(); it!=m.end(); it++)
	{
		cout<< (*it).first << " " << (*it).second << endl;
	}
}
    multimap：多重映射，它与map很像，区别是它的key的值可以重复。
#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int,string> mm;
	// 插入元素
	mm.insert(make_pair(10010,"ha1"));
	mm.insert(make_pair(10012,"ha2"));
	mm.insert(make_pair(10010,"ha3"));
	mm.insert(make_pair(10013,"ha4"));
	mm.insert(make_pair(10010,"ha5"));
	cout << mm.size() << endl;
	multimap<int,string>::iterator it;
	// 查找一个元素
	it = mm.find(10010);
	// 返回指定元素出现的次数
	for(int i=0; i<mm.count(10010); i++)
	{
		cout << (*it).second << endl;
		it++;
	}
}
    multiset：多重集合，它与set很像，区别是它的值可以重复。
#include <iostream>
#include <set>
using namespace std;

int main()
{
	int arr[10] = {1,3,5,3,2,5,7,6,3,9};
	multiset<int> ms(arr,arr+10);
	cout << ms.size() << endl;
	cout << ms.count(3) << endl;
	multiset<int>::iterator it;
	for(it=ms.begin(); it!=ms.end(); it++)
	{
		cout << (*it) << " ";
	}
}
    priority_queue：优先队列，它会根据元素的比较结果进行排序。

    总结：
    1、vector和deque是支持[]运算，因此基本不需要迭代器，其他容器一律使用迭代器进行遍历。
    2、stack、queue、priority_queue容器没有迭代器。
    3、set、multiset、priority_queue会对元素进行排序，因它存储元素要支持比较运算符。


    STL中常用的算法函数：
    使用时要加头文件：algorithm
        查找：find、search
        排序：sort
        复制：copy
        删除：remove
        比较：equal