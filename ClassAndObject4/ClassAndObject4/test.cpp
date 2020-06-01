#define _CRT_SECURE_NO_WARNGINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test(){
	string str;
	string str1("hong");
	for (auto e : str1){
		cout << e << " ";
	}
	cout << endl;
	string str2(10, 'A');
	for (int i = 0; i < str2.size(); i++)
		cout << str2.operator[](i) << " ";
	cout << endl;

	string str3(str2); // 拷贝构造函数
	for (int i = 0; i < str3.size(); i++)
		cout << str3[i] << " ";
	cout << endl;

	str1 = str3;// 赋值,改变已经存在的string
	for (int i = 0; i < str1.size(); i++)
		cout << str1.at(i) << " ";
	cout << endl;
}

void test1(){
	string str("1234");
	if (str.empty())
		cout << "str is empty" << endl;
	else
		cout << "str is not empty" << endl;
	string str1;
	if (str1.empty())
		cout << "str1 is empty" << endl;
	else
		cout << "str1 is not empty" << endl;
}

void test2(){
	//string类对象支持直接用cin和cout进行输入输出
	//string str;
	//cin >> str;
	//cout << str;

	string s("hello");
	cout << "size = "<<s.size() << endl;
	cout << "length = " << s.length() << endl;
	cout << "capacity = " << s.capacity() << endl;
	cout << s << endl;

	// 将s中的字符串清空，注意清空时只是将 size 清 0 ， 不改变底层空间大小
	s.clear();
	cout << "size = " << s.size() << endl;
	cout << "length = " << s.length() << endl;
	cout << "capacity = " << s.capacity() << endl;
	cout << s << endl;

	// 将s中有效的字符个数增加到10个，多出位置用'a'进行填充
	s.resize(10, 'a');
	cout << "size = " << s.size() << endl;
	cout << "cap = " << s.capacity() << endl;

	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
	// 注意：此时s中有效字符个数已经增加到15个
	s.resize(15);
	cout << "size = " << s.size() << endl;
	cout << "cap = " << s.capacity() << endl;
	cout << s << endl;

	// 将s中有效的字符个数缩小到5个
	s.resize(5);
	cout << "size = " << s.size() << endl;
	cout << "cap = " << s.capacity() << endl;
	cout << s << endl;
}
void test3(){
	string s;
	//测试reserve是否会改变string中有效元素个数
	// 此处申请100字节，实际给的容量应该大于100,至少还要一个字节存放'\0'
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl; // 101

	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
	// 不会！！！！!
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void test4(){
	// 利用reserve 提高插入数据的效率，避免增容带来的开销
	string s;
	size_t sz = s.capacity();
	for (int i = 0; i < 100; i++){
		s.push_back('c');
		if (sz != s.capacity()){
			sz = s.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
}
// 申请空间之后，容量就不再改变，相对于不reserve效率会增加
void test5(){
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	for (int i = 0; i < s.size(); i++){
		s.push_back('c');
		if (sz != s.capacity()){
			sz = s.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
}
void test6(){
	string s1("hello world!");
	const string s2("hello world!");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'A';
	cout << s1 << endl;
	// s2[0] = 'A' ; 代码编译器失败，因为const类型对象不能修改
}
void test7(){
	string s("hello world!");
	// 3 种遍历方式
	// 需要注意以下三种除了遍历string对象，还可以遍历是修改string中的字符
	// 另外以下三种方式对于string而言，第一种使用得最多
	// 1、for + operator[](i)
	for (size_t i = 0; i < s.size(); i++){
		cout << s[i] << " ";
	}
	cout << endl;

	// 2、迭代器
	string::iterator it = s.begin();
	while (it != s.end()){
		cout << *it << " ";
		++it;
	}

	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend()){
		cout << *rit<<" ";
		++rit;
	}

	//3、范围for,修改需要用引用，此处不修改需要拷贝构造
	for (auto e : s)
		cout << e << " ";
}
void main(){
	test7();
	//test6();
	//test4();
	//cout << endl<<endl;
	//test5();
	//test3();
	//test2();
	//test1();
	//test();
	cout << endl << "end of process" << endl;
	while (1);
}
/*
template <class T1,class T2>
T2 Add(const T1& a, const T2& b){
	return  a + b;
}
int Add(int a, int b){
	return a + b;
}
void test1(){
	// 普通函数与模版函数共存时，如果普通函数的采纳数类型可以完全匹配
//则执行普通函数，不进行模板函数的实例化
	// 普通函数与模板函数共存时，普通函数的参数类型不能完全匹配
	// 但是实例化的函数可以完全匹配参数类型，则进行实例化
	// 普通函数与模版函数共存时，但是指定了需要实例化，则进行实例化
	int a = 10;
	char b = 'a';
	char c = Add<int, char>(a, b);
	cout << c << endl;
	int d = Add(1, 2);
	cout << d << endl;
}

// 类模板
template <class T1,class T2,class T3>
class Date{

public:
	Date(T1 year, T2 month, T3 day)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}
	void showinfo();
private:
	T1 _year;
	T2 _month;
	T3 _day;
};
// 如果在类外定义类模板的成员函数，需要加上泛型的声明
// 作用域为"类名<泛型参数>"
template<class T1,class T2,class T3>
void Date<T1, T2, T3>::showinfo(){
	cout << _year << "-" << _month << "-" << _day;
}
void test2(){
	// 类模板不能进行隐式实例化
	// 类型和类名不同
	// 类型：类名<模板参数实际类型列表>
	Date<int, int, int> d(2020, 5, 31);
	d.showinfo();
}
void test3(){
	string str;
	string str2("123");
	string str3 = "abc";
	string str4("0123456789", 5);//"011234"
	string cpy(str3);//"abc"
	string str5(str4, 2, 3); // 从indx为2开始截3个
	string str6(10, 'a'); //"aaaaaaaaaaa"

	// 赋值运算符，当前对象已经存在了
	str6 = str5;
	str6 = "lklj";
	str6 = 'A'; //"A"
}

void test4(){
	// 迭代器遍历
	string str("0123456789");
	string::iterator it = str.begin();

	while (it != str.end()){
		*it = 'a';
		cout << *it << " ";
		++it;
	}
	cout << endl;
	vector<int> vec = { 0, 1, 2, 3, 4, 5 };
	vector<int>::iterator vit = vec.begin();

	while (vit != vec.end()){
		cout << *vit << " ";
		++vit;
	}
}
//反向迭代器
void test5(){
	cout << "reverse iterator" << endl;
	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>::reverse_iterator rit = vec.rbegin();

	while (rit != vec.rend()){
		cout << *rit << " ";
		// 反向迭代器向前移动
		++rit;
	}
	cout << endl;
	cout << "const iterator" << endl;
	// 权限可以缩小，但是不能放大
	// const迭代器不支持写操作，其为只读迭代器
	vector<int>::const_iterator cit = vec.begin();
	// const迭代器建议使用const接口获取
	vector<int>::const_iterator cit2 = vec.cbegin();
	while (cit != vec.end()){
		// 只读，不可写
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

}

void printstring(const string& str){
	string::const_iterator it = str.begin();
	while (it != str.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test6(){
	string str = "jsfdalilfss asdb ";
	string::const_reverse_iterator crvit = str.crbegin();
	while (crvit != str.crend()){
		cout << *crvit << " ";
		++crvit;
	}
}
void test7(){
	string str("0123456789");
	// size ; 返回有效字符的个数
	int size = str.size();
	// 返回有效字符个数
	int len = str.length();
	// capacity: 可以存放最大的有效字符数量
	int cap = str.capacity();

	size_t maxSize = str.max_size(); // 无符号整数

	str.clear(); // 清空内容，只清空内容，不改变容量
	size = str.size();
	cap = str.capacity();
}

void test8(){
	string str("01233");
	int size = str.size();
	int cap = str.capacity();
	// 1、当n > size , 且 n > capacity ; 增容，开空间+拷贝+释放原有空间+新的位置赋值
	// 如果原来没有给定赋值，默认'\0'
	str.resize(20);
	size = str.size();
	cap = str.capacity();
	// 2、当 n < size , 只修改size
	str.resize(10);
	size = str.size();
	cap = str.capacity();
	// 当 n > size , 且 n < capacity ; 新的位置赋值，（如果没有给赋值字符，默认赋值'\0'+修改size）
	str.resize(30, 'a');
	size = str.size();
	cap = str.capacity();
}

void test9(){
	// reserve : 储备，拥有
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();
	// reserve 增加容量，不修改size , 也不减少容量
	// 增加的量 >= 20 ， 不能小于20
	str.reserve(20);
	size = str.size();
	cap = str.capacity();

	str.reserve(5);
	size = str.size();
	cap = str.capacity();

}

void test10(){
	string s;
	// 容量和实际申请的空间可能不同：字符串特点:以'\0'结束，需要给'\0'留一个位置
	// PJ 版string 增容过程：如果以空字符串对象，初始容量为15，第一次增容2倍，后续按照1.5倍增容
	int size = s.size();
	int cap = s.capacity();
	// 使用reserve提前开好空间，后续可以节省增容的开销，提高代码的效率
	s.reserve(200); // 不一定开辟200个空间，但是一定大于200
	cout << "初始容量:" << cap << endl;
	for (int i = 0; i < 200; i++){
		s.push_back(i);
		if (cap != s.capacity()){
			cap = s.capacity();
			cout << cap << endl;
		}
	}
}

void test11(){
	string s;
	s.reserve(100);
	int size = s.size();
	int cap = s.capacity();

	s.reserve(10);
	size = s.size();
	cap = s.capacity();
	// shrink_to_fit : 缩小为合适的大小对于当前空间
	s.shrink_to_fit();
	size = s.size();
	cap = s.capacity();

	s.reserve(1000);
	s.shrink_to_fit();
	size = s.size();
	cap = s.capacity();
}

void test12(){
	string str("0123456789");
	// 迭代器
	string::iterator it = str.begin();
	while (it != str.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// operator
	int i = 0; 
	for (; i < str.size();i++){
		cout << str.operator[](i) << " ";
		//str.operator[](i) = 'a';
	}
	cout << endl;
	i = 0;
	// str[100] ： 越界报错
	for (; i < str.size(); i++){
		cout << str[i] << " ";
	}

	cout << endl;
	// str.at(100) : 越界抛异常
	i = 0;
	// at :  可读可写，但是可读性不强，如果越界，会抛异常
	for (; i < str.size(); i++){
		cout << str.at(i) << " ";
	}
	cout << endl;
	// 范围 for 遍历 ， 不加const支持读写，如果需要修改：接受类型为引用类型，如果时值的话就只会拷贝
	// 底层通过迭代器实现，
	for (const auto& ch : str){
		cout << ch << " ";
	}
	cout << endl;
}
void main(){
	test12();
	//test10();
	//test5();
	//test4();
	//test2();
	//test1();
	cout << "end of process" << endl;
	while (1);
}
*/

/*
// 显式实例化，编译器有混淆的时候就需要显式实例化
template <class T>
T add(const T& a, const T& b){
	return a + b;
}
//template<class T1 , class T2>


template < class T1, class T2, class T3 > 
class Date{
public:
	Date(T1 year, T2 month, T3 day)
	:_year(year)
	, _month(month)
	, _day(day)
	{

	}
	void showinfo();
private:
	T1 _year; 
	T2 _month;
	T3 _day;
};

// 如果在类外定义类模板的成员函数，需要加上泛型的声明
// 作用域为"类名<泛型参数>"
template <class T1, class T2, class T3 >
void Date<T1,T2,T3>::showinfo(){

}
void test(){
	// 类模板不能隐式实例化
	// 类模板：类型和类名不同
	// 类型=类名+具体参数类型
	// 类型: 类名<模板实际参数类型>
	Date<int, int, int> d(2020, 5, 31);
}

void test1(){
	string str; // 无参构造，空字符串
	string str2("123");// "123"
	string str3 = "abcdefg hi";
	string str4("0123456789", 5);// "01234"
	string cpy(str3); //"abcdefg hi"

	string str5(str4, 2, 2);// "23",从索引为2的地址截取2个字符
	string str6(10, 'a');//用10个'a'创建一个对象-->"aaaaaaaaaa"
	// 赋值运算符，对象已经存在，只是改变已经存在的值

	str6 = str5;
	str6 = "abcd";
	str6 = 'A';
}

void test3(){
	string str = "123456789";
	// 迭代器的遍历方式
	string::iterator it = str.begin();
	while (it != str.end()){
		cout << *it << " ";// 迭代器向后移动
		++it;// 迭代器向后移动
	}
	// 迭代器是一个可读可写的接口
	//it = str.begin();
	//*it = 0;
	//cout << endl<<*it<<endl;
	cout << "reverse" << endl;
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend()){
		cout << *rit << " ";
		// 反向迭代器向前移动
		++rit;
	}
	cout << "end" << endl;

	// 只读迭代器
	string::const_iterator cit = str.begin();// 需求减小
	// const迭代器建议使用const接口获取:c...();
	string::const_iterator cit2 = str.cbegin();
	while (cit != str.end()){
		cout << *cit << " ";
		++cit;// 不支持改动，是一个const迭代器，不支持写操作
	}
}
// 对于const对象只能使用const迭代器，同时也不支持修改
void printstring(const string& str){
	string::const_iterator sit = str.begin();
	while (sit != str.end()){
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
}
void test4(){
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int>::iterator it = vec.begin();
	while (it != vec.end()){
		cout << *it << " ";
		++it;
	}
}

void test5(){
	string str("1234567890");
	int ret = str.size();// 返回有效字符的个数
	ret = str.length(); // 返回有效字符的个数
	ret = str.capacity(); // 可以存放的最大有效字符的个数
	size_t maxSize = str.max_size(); // 返回无符号整型,当前内存当中可以存放的字符个数

	str.clear();//清空，
	// clear : 只清空内容，不改变容量
	ret = str.size();
	ret = str.capacity();
}

void test6(){
	string str("1234567890");
	int size = str.size();
	int cap = str.capacity();
	// resize(n)
	// 1、当n > size ， 且 n > capacity ：增容（开辟新的空间+拷贝+释放原来空间）+新的位置赋值（如果没有给赋值字符，默认值为'\0'）
	str.resize(20);
	size = str.size();
	cap = str.capacity();
	// 当 n < size , 只修改size
	str.resize(10);
	size = str.size();
	cap = str.capacity();
	// 当 n > size , 且 n < capacity ,新的位置赋值，（如果没有给赋值字符，默认'\0'）+修改size
	str.resize(30, 'a');
	size = str.size();
	cap = str.capacity();
}

void test7(){
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();

	// reverse : 调整容量 ， 一定不修改size和内容 ，如果减少容量，是按需减少，如果要减少的容量小于size，不做任何操作，如果减少的容量大于size，则进行必要的操作
	str.reserve(20);
	size = str.size();
	cap = str.capacity();

	str.reserve(5);
	size = str.size();
	cap = str.capacity();

}

void test8(){
	// 容量和实际申请的空间可能不同：字符串特点：以‘、0结束
	// PJ版string增容;1.5倍
	string s;
	int size = s.size();
	int cap = s.capacity();
	s.reserve(200);// 使用reverse提前开好空间，后续可以节省增容的开销提高代码效率
}

void test9(){
	string s;
	s.reserve(100);
	int size = s.size();
	int cap = s.capacity();

	// 尝试减少容量
	s.shrink_to_fit();
}

void test10(){
	// 迭代器访问方式
	string str("0123456789");
	// operator: 是一个可读可写的接口
	str.operator[](1); // 可读性并不强
	str[1];// 与上面的重载函数等价
	int i = 0;
	for (; i < str.size(); i++){
		cout << str.operator[](i) << " ";
	}
	cout << endl;

	// at:越界抛异常，operator[] 非法访问出错
	for (i = 0; i < str.size(); i++){
		cout << str.at(i) << " ";// at : 也是一个可读可写的接口，可读性不强
	}

	// 范围for : 范围 确定
	// 支持读写：给的引用，支持访问内存本身元素
	// 不给引用就是一个值的拷贝，就不会改变原内存的值
	// 如果需要修改，则接收类型为引用类型
	// 底层通过迭代器来实现：需要begin,end提供方法
	cout << "范围for" << endl;
	for (auto& e : str){
		cout << e << " ";
	}
}
void main(){
	test10();
	//test3();
	//test4();
	while (1);
}
*/
/*
class Date{
public:
	Date(int year = 1)
		:_year(year){

	}
	~Date(){
		++cnt;
		cout << "cnt="<<cnt<<"~Date" << endl;
	}
private:
	int _year;
	static int  cnt;
};

int Date::cnt = 0;
void test(){
	Date d(2020);
	Date* pd = (Date*)malloc(sizeof(Date));
	Date* pd2 = (Date*)calloc(1, sizeof(Date));
}

void test1(){
	int* ptr = (int*)malloc(sizeof(int));
	int* ptr2 = (int*)malloc(sizeof(int) * 10);

	// 单个类型的空间 ： new +　类型
	// 连续空间 ： new 类型[个数]
	// 单个类型的空间申请 +　初始化： new + 类型(初始化值)
	// 基本类型用new申请连续空间，不能初始化
	int* ptr3 = new int;
	int* ptr4 = new int[10]; // 
	// 单个空间的初始化
	int* ptr5 = new int(5);

	// 释放空间
	// 单个空间 delete 指针
	// 连续空间 delete[] 指针
	// 申请和释放的操作匹配使用: malloc free
	// new delete
	// new delete[]
	delete ptr3;
	delete ptr5;
	delete[] ptr4;
}

void test4(){
	// 动态创建自定义类型对象
	// new : 动态开空间 + 迪奥用构造函数初始化
	// 自动调用构造函数
	// 申请单个空间 new 自定义类型（参数列表）
	Date* pd = new Date(2020);
	Date* pd1 = new Date(2030);

	// 自定义类型，要申请连续空间，需要默认构造
	// 申请连续空间，自动调用默认构造进行初始化，如果没有默认构造，编译器报错
	Date* ppdd = new Date[10];

	// 释放自定义类型的空间
	//delete : 调用析构函数清理资源+内存释放
	delete pd;
	delete pd1;
	delete[] ppdd;
}

void test5(){
	// void*　operator new(size_t n)
	// 不是运算符重载函数，而是一个全局函数
	// 使用方式和malloc类似
	//operator new : 封装malloc+异常
	// 异常不处理一样崩溃程序
	// new的执行过程：operator new --> malloc-->构造函数
	int* ptr = (int*)malloc(sizeof(int) * 209);
	int* ptr2 = (int*)operator new(sizeof(int));
	int* ptr3 = (int*)malloc(sizeof(int) * 0x3fffffff);

	// void operator delete(void* ptr) 
	// 不是运算符重载，而是一个全局函数
	// 封装了free
	// 不需要封装异常，还空间无需异常处理
	// delete执行过程(自定义类型) ：析构--> operator delete -->free
	operator delete(ptr2);
	operator delete(ptr);
}
// 内存池
// 先申请一片内存，提高程序效率
// 用内存池管理空间
struct Node{
public:
	Node(){ cout << "Node()" << endl; }
	// 定制节点的空间的申请方式
	void* operator new(size_t n){
		// 表示从内存池当中申请一个节点的空间
		allocator<Node>().allocate(1);
		cout << "mem pool allocate" << endl;
	}

	void operator delete(void* ptr){
		allocator<Node>().deallocate((Node*)ptr, 1);
		cout << "mem pool deallocate" << endl;
	}
private:
	int _data;
	Node* _next;
};
void  test6(){
	Date* pd = (Date*)malloc(sizeof(Date));
	// new 定位表达式：new （地址）类型（参数列表）
	// : 在已经开好的空间上显式调用构造函数
	new (pd)Date(2020);

}
// 函数模版 --> 在应用之前会实例化函数
// 模版实例化 --> 用实际参数类型生成可执行函数
// 实现相同代码不同类型的复用功能
// 泛型编程并没有减少实际的代码量，只是把重复的代码交给机器自动生成
// 减少开发人员的工作量
// 底层执行不同的代码
// 隐式实例化：编译器根据参数自动推导，产生直接可执行的代码
// 显式实例化 : swap<int>(a,b)
// 显式实例化： 函数名 + <类型> + （参数列表）
// 类型不匹配整一个显式实例化
template <class T>
void swap(T& a.T& b){
	T tmp = a;
	a = b;
	b = tmp;
}
void main(){
	test5();

	while (1);
}
*/




//class Date{
//public:
//	Date(int year = 1)
//		:_year(year){
//
//	}
//private:
//	int _year;
//};
//// 动态创建自定义对象，new动态开辟空间
//// new 动态开空间+调用构造函数初始化
//void test(){
//	Date* dd = new Date; // 自动调用默认构造，释放自定义类型的空间 delete dd;
//	Date d(2020); // 栈上创建一个对象
//	// 没有初始化，随机值；calloc也是0的初始化，无法达到预期初始值
//	// 此处不会调用构造函数初始化，除非提供一个set接口
//	Date* pd = (Date*)malloc(sizeof(Date));// 堆上开辟空间，但是没有初始化
//
//
//	// C++ 提供了一种动态内存开辟方式
//	int* ptr = (int*)malloc(sizeof(int));
//	int* ptr2 = (int*)malloc(sizeof(int)*10);
//
//	int* ptr3 = new int;
//	int* ptr4 = new int[10];
//	// new出来的空间可以完成单个空间的初始化
//	int* ptr5 = new int(5);// 初始化为5，连续空间不能初始化，只能给单个空间初始化，不能初始化
//
//	// 单个空间：new 类型
//	// 申请连续空间： new+类型[num]
//	// 单个类型空间申请 + 初始化： new +类型(初始化值)
//
//	// 释放单个空间
//	delete ptr;
//	delete ptr3;
//	// 释放连续空间
//	delete[] ptr4;
//
//	// 申请和释放的操作匹配使用： malloc free
//	// new delete
//	// new [] delete[]
//
//	// new 会自动调用构造函数
//	// 调用构造函数之前，空间已经开好，这样才能this调用构造函数等
//	Date* pd = new Date(2020);
//	// 必须要有默认构造函数，自动调用
//	// 申请连续空间，自动调用默认构造函数进行初始化，如果没有默认构造，编译器报错
//	//
//	Date* pd2 = new Date[10];
//
//
//	// 释放空间自动调用析构函数清理资源，再释放空间
//	// 有一个对象产生就会调用一个析构函数
//	// 连续空间:调用N次析构 + (一次)释放空间
//	delete[] pd2;
//}
//
////void *_CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc){
////	// try to allocate size bytes
////	void* p;
////	while ((p = malloc(size)) == 0){
////		if ()
////	}
////}
//void test2(){
//	// 此处并不是new运算符重载
//	// 仅仅是函数名比较特殊
//	//void* operator new(size_t n); // 不是运算符重载函数，而是一个全局函数
//	// 不能 new 10 ， 与malloc用法类似
//
//	// new 的执行过程 : operator new -> malloc -> 构造函数
//	// 先申请空间再构造函数初始化
//	int* ptr = (int*)operator new(sizeof(int));
//	// operator new : 封装了malloc + 异常（申请失败，抛出异常）
//
//	// void operator delete(void* ptr)
//	// 使用方式和 free 相似
//	// 封装 free(其中并没有异常，还内存一般不会拒绝)
//	// delete 执行过程(自定义类型):析构，-->operator delete->free
//	// 异常可以处理
//	operator delete(ptr);
//	free(ptr);
//
//	
//}
//
//
//void test7(){
//	Date* p = (Date*)malloc(sizeof(Date));
//	// new 定位表达式：new (地址)类型(参数列表)
//	// : 在已经开好的空间显式调用构造函数
//	new (p)Date(2030); // 可以为无参
//
//	Date* p1 = (Date*)malloc(sizeof(Date));
//	new (p1)Date; // 此处为无参构造函数
//}
//
//// 范型函数
///* 
//template < typename / class 范型参数1, typename / class 范型参数2, .. > 
//函数定义{
//
//}
//*/
//
//// 泛型函数
//// 模版实例化，用实际参数类型生成可执行的函数
//// 函数模板的实例化
//// 泛型编程并没有减少实际的代码量，只是把重复的代码交给机器自动生成
//// 减少开发人员重复的工作量，提高工作效率
//// 隐式实例化：编译器根据参数进行自动推导，产生实际可执行的代码
//// 显式实例化：Swap<int>( a , b );
//// 函数名
//template <class T>
//void Swap(T& left, T& right){
//	T temp = left;
//	left = right;
//	right = temp;
//}
//class Node{
//public:
//	Node(){}
//	// 定制节点空间申请方式
//	void* operator new (size_t n){
//		// 内存池申请
//		allocator<Node>().allocate(1);// 申请一个Node的空间从内存池当中
//		cout << "mem pool allocate" <<endl;
//	}
//
//	void operator delete(void* ptr){
//		allocator<Node>().deallocate((Node*)ptr, 1);
//		cout << "mem pool deallocate" << endl;
//	}
//private:
//	int _data;
//	Node* _next;
//};
//void test3(){
//	Node* pn = new Node[10];
//	delete[] pn;
//
//	// 直接向系统申请空间
//	// 容器（内存池）-->要一大波内存备用，先把内存申请下来放在这儿，不以至于频繁申请内存
//	// 频繁申请内存瓶颈
//	// 优化：内存池管理空间
//
//
//}
//void main(void){
//
//	char i = 0;
//	for (i = 'a'; i < 'z' + 1; i++){
//		cout << i << " ";
//	}
//	
//	cout<<"end" << endl;
//	while (1);
//}


///*
//int cnt = 0; // 全局域，不安全
//class Date{
//
//	//Date(){
//
//	//}
//public:
//	Date(int year = 2020 , int month = 5, int day=27)
//	:_year(year)
//	,_month(month)
//	,_day(day){
//		++cnt;
//		++count;
//		cout << "Date(int , int , int)" << endl;
//	}
//
//	Date(const Date& d)
//		:_year(d._year)
//		,_month(d._month)
//		,_day(d._day){
//		cout << "Date(const Date& d)" << endl;
//		++cnt;
//		++count;
//	}
//
//	// 静态成员函数
//	// 静态成员函数不能访问非静态成员函数和非静态成员变量
//	// 静态成员函数：函数内部没有 this 指针
//	// 底层没有 getCount( const Date* this ) : 只有 getCount()
//	// 静态成员函数不能访问非静态成员函数/变量
//	// 因为非静态成员需要this指针,
//	// 但是静态成员函数内部缺少this指针，所以不能访问
// 	static int getCount(){
//		return count;
//	}
//
//	// 普通成员函数只能通过对象访问
//	// 不能通过类来访问
//	// 非静态成员函数可以访问静态成员函数和静态成员变量
//	void showinfo(){
//		cout << _year << endl;
//	}
//
//	// 支持连续的输出，从左向右输出
//	ostream& operator<<(ostream& _cout){
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}
//	friend ostream& operator<<(ostream& _cout, Date& d);
//	friend istream& operator>>(istream& _cin, Date& d); 
//	friend class B;
//private:
//	// C++11 初始化方式：相当于给一个缺省值
//	// 此处的默认值是最后一个候选的
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//	// 静态成员变量，所有对象共享此成员变量，可以看成类成员
//	// 静态成员不能在声明的时候给默认值
//	// 不能在初始化对象的时候初始化static变量
//	// 静态成员不在对象模型中，一般存在数据段，不能在初始化列表中初始化
//	// 在类外初始化
//	static int count ; // 所有对象共享的变量
//};
//
//// 静态成员必须在类外初始化
//int Date::count = 0;
//
//Date fun(Date d){ // 拷贝构造
//	return d; // 返回的时候给函数，拷贝构造
//}
//
//
//void test1(){
//	Date d; // 构造
//	Date d2 = fun(d); // 拷贝构造，此处有优化，返回值没有作用，因此直接优化，直接用局部对象d拷贝创建给d2
//	cout <<"d = " << d.getCount() << endl;
//	cout << "d2 = "<<d2.getCount() << endl;
//	// 静态成员变量访问方式
//	// 1、对象访问
//	// 2、类名+作用域限定符
//	cout << "Date = " << Date::count << endl;
//	cout << "*&Date = " << *&Date::count << endl;
//
//	cout << "static getCount = " << Date::getCount() << endl;
//}
//
//// 友元函数可以访问类的私有成员
//// 友元函数本身不是本类的成员函数，它是普通的非成员函数
//// 友元函数只需要在类中定义，不需要在类中定义
//// 返回输出流是为了支持连续赋值
//// 传入引用，则变量的生命周期长于函数，则可以返回引用
//// 友元函数尽量少用，这是一种突破了封装的概念
//// 友元函数可以声明在类的任何地方限制，不受限定符限制
//// 友元关系不能传递，类似于朋友的朋友不一定是自己的朋友，必须明确标识，不可以靠推导得到得到友元关系
//ostream& operator<<(ostream& _cout, Date& d){
//	_cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return _cout;
//}
//
//istream& operator>>(istream& _cin, Date& d){
//	_cin >> d._year >> d._month >> d._day;
//	return _cin;
//}
//void test3(){
//	Date d(2020, 5, 26);
//	d << cout;
//
//	operator<<(operator<<(cout, d), d); 
//
//	Date d3;
//	// 从左向右输入
//	cin >> d3>>d3;
//	cout << d3;
//}
// 
////要让B访问Date的私有成员，就要让类B成为类Date的友元类
//class B{
//
//public:
//	// 当前类成为了Date类的私有成员就可以访问Date类的私有成员
//	// 如果一个类是另一个类的友元函数，则此类中的所有成员函数就是另一个类的友元函数
//	// friend 是单向的，想要相互访问，必须要双向声明
//	// 外部类不能看作内部类的友元类，对于内部类的成员没有特殊访问权限，需要遵循访问限定符的限制
//	void display(const Date& d){
//		cout << d._year << "-" << d._month << "-" << d._day << endl;
//	}
//};
//
//enum Color{
//	GREEN,
//	YELLOW
//};
//class C{
//public:
//	// 内部类，在一个类中定义一个新的类,内部类可以在类的任何地方定义
//	// 内部类天然的作为外部类的友元类 
//public:
//	// 内部类是作为一个独立的类存在，并不附属于外部类
//	class D{
//	public:
//		// 内部类中的成员函数可以通过外部类对象访问外部类的私有成员
//		void showinfo(const C& c){
//			// 静态成员可以直接访问，或者类名访问
//			// 可以直接访问外部类的静态成员
//			cout << _sc << endl;
//			cout << C::_sc << endl;
//			cout << c._a << endl;
//			// 枚举类型也只能通过对象来访问，不能直接访问
//			cout << c.color << endl;
//		}
//	private:
//		int _da;
//		int _db;
//	};
//private:
//	int _a;
//	int _b;
//	static int _sc;
//	Color color;
//};
//void main(){
//	test3();
//	//test1();
//	//cout << cnt << endl;
//	cout << "end" << endl;
//	C c;
//	C::D dd;
//	dd.showinfo(c);
//	while (1);
//	system("pause");
//}
//
//
////class Date{
////
////public:
////	// 静态成员函数
////	static int getCount(){
////		return cnt;
////	}
////
////	void operator<<(ostream& _cout){
////		_cout << _year << "-" << _month << endl;
////	}
////	// 友元函数不受访问限定符的限制，可以声明在类中的任何位置
////	// 友元函数: friend
////	// 友元函数可以访问类的私有成员
////	// 友元函数不在对象模型当中，不是类的成员函数，它是普通的非成员函数
////	// 只需要在类中声明友元，不需要在类中定义，
////	// 友元函数尽量少用，这是一种突破封装的语法
////	friend istream& operator>>(istream& _cin, Date& d);
////private:
////	// 静态成员变量不能给初始值，不能初始化列表
////	// 类成员的全局变量，静态数据没有放在对象模型当中
////	// 不能在声明的时候给默认值，一般存在数据段，不能在初始化列表中初始化，一般在类外初始化
////	static int cnt;
////
////	int _year;
////	int _month;
////	int _day;
////
////	// 声明友元类
////	friend class A; // 此时在类A的函数中就可以访问当前类的私有成员
////	// 如果一个类是里尼过一个类的友元类
////	// 则此类中的成员函数就是友元函数
////	// 友元关系是单向的，双向需要双向声明
////	// 友元关系不能传递，类似于朋友的朋友不一定是自己的friend
////	// 谁是谁的friend写得很明确，不能靠推导
////};
////
////istream& operator>>(istream& _cin,  Date& d){
////	_cin >> d._year >> d._month >> d._day;
////	return _cin;
////}
////
////int Date::cnt = 0;
////
////
////// 内部类
////class C{
////public:
////	// 在一个类的内部定义一个新的类
////	// 可以定义在一个类中的任何地方
////	// 内部类天然的作为外部类的友元类
////	// 可以访问外部耒的私有成员
////	// 当然是通过外部类的对象成员访问，静态成员可以不用,直接访问，或者类访问，
////	// 直接访问外部类的static成员\
////
////	// 内部类是作为独立的类存在的，它不附属于外部类
////	// 内部类也是当作外部类应用
////
////	// 外部类不能看着内部类的友元类，对于内部类的成员没有特殊的访问权限
////	class D{
////
////	};
////};
////void main(){
////	cout << "hongzheng" << endl;
////	Date::getCount(); // 普通函数不支持这种操作，只有静态函数才支持此等操作
////	// 静态成员函数不能访问非静态成员函数或者非静态成员变量
////	// 静态成员函数：函数内部没有 this 指针
////	// 非静态成员访问需要this指针
////	// 静态函数成员内部缺少 this 指针，所以不可以访问
////	// 
////	while (1);
////}
//
//* /