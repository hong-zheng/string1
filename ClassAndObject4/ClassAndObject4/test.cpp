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

	string str3(str2); // �������캯��
	for (int i = 0; i < str3.size(); i++)
		cout << str3[i] << " ";
	cout << endl;

	str1 = str3;// ��ֵ,�ı��Ѿ����ڵ�string
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
	//string�����֧��ֱ����cin��cout�����������
	//string str;
	//cin >> str;
	//cout << str;

	string s("hello");
	cout << "size = "<<s.size() << endl;
	cout << "length = " << s.length() << endl;
	cout << "capacity = " << s.capacity() << endl;
	cout << s << endl;

	// ��s�е��ַ�����գ�ע�����ʱֻ�ǽ� size �� 0 �� ���ı�ײ�ռ��С
	s.clear();
	cout << "size = " << s.size() << endl;
	cout << "length = " << s.length() << endl;
	cout << "capacity = " << s.capacity() << endl;
	cout << s << endl;

	// ��s����Ч���ַ��������ӵ�10�������λ����'a'�������
	s.resize(10, 'a');
	cout << "size = " << s.size() << endl;
	cout << "cap = " << s.capacity() << endl;

	// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
	// ע�⣺��ʱs����Ч�ַ������Ѿ����ӵ�15��
	s.resize(15);
	cout << "size = " << s.size() << endl;
	cout << "cap = " << s.capacity() << endl;
	cout << s << endl;

	// ��s����Ч���ַ�������С��5��
	s.resize(5);
	cout << "size = " << s.size() << endl;
	cout << "cap = " << s.capacity() << endl;
	cout << s << endl;
}
void test3(){
	string s;
	//����reserve�Ƿ��ı�string����ЧԪ�ظ���
	// �˴�����100�ֽڣ�ʵ�ʸ�������Ӧ�ô���100,���ٻ�Ҫһ���ֽڴ��'\0'
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl; // 101

	// ����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
	// ���ᣡ������!
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void test4(){
	// ����reserve ��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���
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
// ����ռ�֮�������Ͳ��ٸı䣬����ڲ�reserveЧ�ʻ�����
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
	// s2[0] = 'A' ; ���������ʧ�ܣ���Ϊconst���Ͷ������޸�
}
void test7(){
	string s("hello world!");
	// 3 �ֱ�����ʽ
	// ��Ҫע���������ֳ��˱���string���󣬻����Ա������޸�string�е��ַ�
	// �����������ַ�ʽ����string���ԣ���һ��ʹ�õ����
	// 1��for + operator[](i)
	for (size_t i = 0; i < s.size(); i++){
		cout << s[i] << " ";
	}
	cout << endl;

	// 2��������
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

	//3����Χfor,�޸���Ҫ�����ã��˴����޸���Ҫ��������
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
	// ��ͨ������ģ�溯������ʱ�������ͨ�����Ĳ��������Ϳ�����ȫƥ��
//��ִ����ͨ������������ģ�庯����ʵ����
	// ��ͨ������ģ�庯������ʱ����ͨ�����Ĳ������Ͳ�����ȫƥ��
	// ����ʵ�����ĺ���������ȫƥ��������ͣ������ʵ����
	// ��ͨ������ģ�溯������ʱ������ָ������Ҫʵ�����������ʵ����
	int a = 10;
	char b = 'a';
	char c = Add<int, char>(a, b);
	cout << c << endl;
	int d = Add(1, 2);
	cout << d << endl;
}

// ��ģ��
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
// ��������ⶨ����ģ��ĳ�Ա��������Ҫ���Ϸ��͵�����
// ������Ϊ"����<���Ͳ���>"
template<class T1,class T2,class T3>
void Date<T1, T2, T3>::showinfo(){
	cout << _year << "-" << _month << "-" << _day;
}
void test2(){
	// ��ģ�岻�ܽ�����ʽʵ����
	// ���ͺ�������ͬ
	// ���ͣ�����<ģ�����ʵ�������б�>
	Date<int, int, int> d(2020, 5, 31);
	d.showinfo();
}
void test3(){
	string str;
	string str2("123");
	string str3 = "abc";
	string str4("0123456789", 5);//"011234"
	string cpy(str3);//"abc"
	string str5(str4, 2, 3); // ��indxΪ2��ʼ��3��
	string str6(10, 'a'); //"aaaaaaaaaaa"

	// ��ֵ���������ǰ�����Ѿ�������
	str6 = str5;
	str6 = "lklj";
	str6 = 'A'; //"A"
}

void test4(){
	// ����������
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
//���������
void test5(){
	cout << "reverse iterator" << endl;
	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>::reverse_iterator rit = vec.rbegin();

	while (rit != vec.rend()){
		cout << *rit << " ";
		// �����������ǰ�ƶ�
		++rit;
	}
	cout << endl;
	cout << "const iterator" << endl;
	// Ȩ�޿�����С�����ǲ��ܷŴ�
	// const��������֧��д��������Ϊֻ��������
	vector<int>::const_iterator cit = vec.begin();
	// const����������ʹ��const�ӿڻ�ȡ
	vector<int>::const_iterator cit2 = vec.cbegin();
	while (cit != vec.end()){
		// ֻ��������д
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
	// size ; ������Ч�ַ��ĸ���
	int size = str.size();
	// ������Ч�ַ�����
	int len = str.length();
	// capacity: ���Դ��������Ч�ַ�����
	int cap = str.capacity();

	size_t maxSize = str.max_size(); // �޷�������

	str.clear(); // ������ݣ�ֻ������ݣ����ı�����
	size = str.size();
	cap = str.capacity();
}

void test8(){
	string str("01233");
	int size = str.size();
	int cap = str.capacity();
	// 1����n > size , �� n > capacity ; ���ݣ����ռ�+����+�ͷ�ԭ�пռ�+�µ�λ�ø�ֵ
	// ���ԭ��û�и�����ֵ��Ĭ��'\0'
	str.resize(20);
	size = str.size();
	cap = str.capacity();
	// 2���� n < size , ֻ�޸�size
	str.resize(10);
	size = str.size();
	cap = str.capacity();
	// �� n > size , �� n < capacity ; �µ�λ�ø�ֵ�������û�и���ֵ�ַ���Ĭ�ϸ�ֵ'\0'+�޸�size��
	str.resize(30, 'a');
	size = str.size();
	cap = str.capacity();
}

void test9(){
	// reserve : ������ӵ��
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();
	// reserve �������������޸�size , Ҳ����������
	// ���ӵ��� >= 20 �� ����С��20
	str.reserve(20);
	size = str.size();
	cap = str.capacity();

	str.reserve(5);
	size = str.size();
	cap = str.capacity();

}

void test10(){
	string s;
	// ������ʵ������Ŀռ���ܲ�ͬ���ַ����ص�:��'\0'��������Ҫ��'\0'��һ��λ��
	// PJ ��string ���ݹ��̣�����Կ��ַ������󣬳�ʼ����Ϊ15����һ������2������������1.5������
	int size = s.size();
	int cap = s.capacity();
	// ʹ��reserve��ǰ���ÿռ䣬�������Խ�ʡ���ݵĿ�������ߴ����Ч��
	s.reserve(200); // ��һ������200���ռ䣬����һ������200
	cout << "��ʼ����:" << cap << endl;
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
	// shrink_to_fit : ��СΪ���ʵĴ�С���ڵ�ǰ�ռ�
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
	// ������
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
	// str[100] �� Խ�籨��
	for (; i < str.size(); i++){
		cout << str[i] << " ";
	}

	cout << endl;
	// str.at(100) : Խ�����쳣
	i = 0;
	// at :  �ɶ���д�����ǿɶ��Բ�ǿ�����Խ�磬�����쳣
	for (; i < str.size(); i++){
		cout << str.at(i) << " ";
	}
	cout << endl;
	// ��Χ for ���� �� ����const֧�ֶ�д�������Ҫ�޸ģ���������Ϊ�������ͣ����ʱֵ�Ļ���ֻ�´��
	// �ײ�ͨ��������ʵ�֣�
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
// ��ʽʵ�������������л�����ʱ�����Ҫ��ʽʵ����
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

// ��������ⶨ����ģ��ĳ�Ա��������Ҫ���Ϸ��͵�����
// ������Ϊ"����<���Ͳ���>"
template <class T1, class T2, class T3 >
void Date<T1,T2,T3>::showinfo(){

}
void test(){
	// ��ģ�岻����ʽʵ����
	// ��ģ�壺���ͺ�������ͬ
	// ����=����+�����������
	// ����: ����<ģ��ʵ�ʲ�������>
	Date<int, int, int> d(2020, 5, 31);
}

void test1(){
	string str; // �޲ι��죬���ַ���
	string str2("123");// "123"
	string str3 = "abcdefg hi";
	string str4("0123456789", 5);// "01234"
	string cpy(str3); //"abcdefg hi"

	string str5(str4, 2, 2);// "23",������Ϊ2�ĵ�ַ��ȡ2���ַ�
	string str6(10, 'a');//��10��'a'����һ������-->"aaaaaaaaaa"
	// ��ֵ������������Ѿ����ڣ�ֻ�Ǹı��Ѿ����ڵ�ֵ

	str6 = str5;
	str6 = "abcd";
	str6 = 'A';
}

void test3(){
	string str = "123456789";
	// �������ı�����ʽ
	string::iterator it = str.begin();
	while (it != str.end()){
		cout << *it << " ";// ����������ƶ�
		++it;// ����������ƶ�
	}
	// ��������һ���ɶ���д�Ľӿ�
	//it = str.begin();
	//*it = 0;
	//cout << endl<<*it<<endl;
	cout << "reverse" << endl;
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend()){
		cout << *rit << " ";
		// �����������ǰ�ƶ�
		++rit;
	}
	cout << "end" << endl;

	// ֻ��������
	string::const_iterator cit = str.begin();// �����С
	// const����������ʹ��const�ӿڻ�ȡ:c...();
	string::const_iterator cit2 = str.cbegin();
	while (cit != str.end()){
		cout << *cit << " ";
		++cit;// ��֧�ָĶ�����һ��const����������֧��д����
	}
}
// ����const����ֻ��ʹ��const��������ͬʱҲ��֧���޸�
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
	int ret = str.size();// ������Ч�ַ��ĸ���
	ret = str.length(); // ������Ч�ַ��ĸ���
	ret = str.capacity(); // ���Դ�ŵ������Ч�ַ��ĸ���
	size_t maxSize = str.max_size(); // �����޷�������,��ǰ�ڴ浱�п��Դ�ŵ��ַ�����

	str.clear();//��գ�
	// clear : ֻ������ݣ����ı�����
	ret = str.size();
	ret = str.capacity();
}

void test6(){
	string str("1234567890");
	int size = str.size();
	int cap = str.capacity();
	// resize(n)
	// 1����n > size �� �� n > capacity �����ݣ������µĿռ�+����+�ͷ�ԭ���ռ䣩+�µ�λ�ø�ֵ�����û�и���ֵ�ַ���Ĭ��ֵΪ'\0'��
	str.resize(20);
	size = str.size();
	cap = str.capacity();
	// �� n < size , ֻ�޸�size
	str.resize(10);
	size = str.size();
	cap = str.capacity();
	// �� n > size , �� n < capacity ,�µ�λ�ø�ֵ�������û�и���ֵ�ַ���Ĭ��'\0'��+�޸�size
	str.resize(30, 'a');
	size = str.size();
	cap = str.capacity();
}

void test7(){
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();

	// reverse : �������� �� һ�����޸�size������ ����������������ǰ�����٣����Ҫ���ٵ�����С��size�������κβ�����������ٵ���������size������б�Ҫ�Ĳ���
	str.reserve(20);
	size = str.size();
	cap = str.capacity();

	str.reserve(5);
	size = str.size();
	cap = str.capacity();

}

void test8(){
	// ������ʵ������Ŀռ���ܲ�ͬ���ַ����ص㣺�ԡ���0����
	// PJ��string����;1.5��
	string s;
	int size = s.size();
	int cap = s.capacity();
	s.reserve(200);// ʹ��reverse��ǰ���ÿռ䣬�������Խ�ʡ���ݵĿ�����ߴ���Ч��
}

void test9(){
	string s;
	s.reserve(100);
	int size = s.size();
	int cap = s.capacity();

	// ���Լ�������
	s.shrink_to_fit();
}

void test10(){
	// ���������ʷ�ʽ
	string str("0123456789");
	// operator: ��һ���ɶ���д�Ľӿ�
	str.operator[](1); // �ɶ��Բ���ǿ
	str[1];// ����������غ����ȼ�
	int i = 0;
	for (; i < str.size(); i++){
		cout << str.operator[](i) << " ";
	}
	cout << endl;

	// at:Խ�����쳣��operator[] �Ƿ����ʳ���
	for (i = 0; i < str.size(); i++){
		cout << str.at(i) << " ";// at : Ҳ��һ���ɶ���д�Ľӿڣ��ɶ��Բ�ǿ
	}

	// ��Χfor : ��Χ ȷ��
	// ֧�ֶ�д���������ã�֧�ַ����ڴ汾��Ԫ��
	// �������þ���һ��ֵ�Ŀ������Ͳ���ı�ԭ�ڴ��ֵ
	// �����Ҫ�޸ģ����������Ϊ��������
	// �ײ�ͨ����������ʵ�֣���Ҫbegin,end�ṩ����
	cout << "��Χfor" << endl;
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

	// �������͵Ŀռ� �� new +������
	// �����ռ� �� new ����[����]
	// �������͵Ŀռ����� +����ʼ���� new + ����(��ʼ��ֵ)
	// ����������new���������ռ䣬���ܳ�ʼ��
	int* ptr3 = new int;
	int* ptr4 = new int[10]; // 
	// �����ռ�ĳ�ʼ��
	int* ptr5 = new int(5);

	// �ͷſռ�
	// �����ռ� delete ָ��
	// �����ռ� delete[] ָ��
	// ������ͷŵĲ���ƥ��ʹ��: malloc free
	// new delete
	// new delete[]
	delete ptr3;
	delete ptr5;
	delete[] ptr4;
}

void test4(){
	// ��̬�����Զ������Ͷ���
	// new : ��̬���ռ� + �ϰ��ù��캯����ʼ��
	// �Զ����ù��캯��
	// ���뵥���ռ� new �Զ������ͣ������б�
	Date* pd = new Date(2020);
	Date* pd1 = new Date(2030);

	// �Զ������ͣ�Ҫ���������ռ䣬��ҪĬ�Ϲ���
	// ���������ռ䣬�Զ�����Ĭ�Ϲ�����г�ʼ�������û��Ĭ�Ϲ��죬����������
	Date* ppdd = new Date[10];

	// �ͷ��Զ������͵Ŀռ�
	//delete : ������������������Դ+�ڴ��ͷ�
	delete pd;
	delete pd1;
	delete[] ppdd;
}

void test5(){
	// void*��operator new(size_t n)
	// ������������غ���������һ��ȫ�ֺ���
	// ʹ�÷�ʽ��malloc����
	//operator new : ��װmalloc+�쳣
	// �쳣������һ����������
	// new��ִ�й��̣�operator new --> malloc-->���캯��
	int* ptr = (int*)malloc(sizeof(int) * 209);
	int* ptr2 = (int*)operator new(sizeof(int));
	int* ptr3 = (int*)malloc(sizeof(int) * 0x3fffffff);

	// void operator delete(void* ptr) 
	// ������������أ�����һ��ȫ�ֺ���
	// ��װ��free
	// ����Ҫ��װ�쳣�����ռ������쳣����
	// deleteִ�й���(�Զ�������) ������--> operator delete -->free
	operator delete(ptr2);
	operator delete(ptr);
}
// �ڴ��
// ������һƬ�ڴ棬��߳���Ч��
// ���ڴ�ع���ռ�
struct Node{
public:
	Node(){ cout << "Node()" << endl; }
	// ���ƽڵ�Ŀռ�����뷽ʽ
	void* operator new(size_t n){
		// ��ʾ���ڴ�ص�������һ���ڵ�Ŀռ�
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
	// new ��λ���ʽ��new ����ַ�����ͣ������б�
	// : ���Ѿ����õĿռ�����ʽ���ù��캯��
	new (pd)Date(2020);

}
// ����ģ�� --> ��Ӧ��֮ǰ��ʵ��������
// ģ��ʵ���� --> ��ʵ�ʲ����������ɿ�ִ�к���
// ʵ����ͬ���벻ͬ���͵ĸ��ù���
// ���ͱ�̲�û�м���ʵ�ʵĴ�������ֻ�ǰ��ظ��Ĵ��뽻�������Զ�����
// ���ٿ�����Ա�Ĺ�����
// �ײ�ִ�в�ͬ�Ĵ���
// ��ʽʵ���������������ݲ����Զ��Ƶ�������ֱ�ӿ�ִ�еĴ���
// ��ʽʵ���� : swap<int>(a,b)
// ��ʽʵ������ ������ + <����> + �������б�
// ���Ͳ�ƥ����һ����ʽʵ����
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
//// ��̬�����Զ������new��̬���ٿռ�
//// new ��̬���ռ�+���ù��캯����ʼ��
//void test(){
//	Date* dd = new Date; // �Զ�����Ĭ�Ϲ��죬�ͷ��Զ������͵Ŀռ� delete dd;
//	Date d(2020); // ջ�ϴ���һ������
//	// û�г�ʼ�������ֵ��callocҲ��0�ĳ�ʼ�����޷��ﵽԤ�ڳ�ʼֵ
//	// �˴�������ù��캯����ʼ���������ṩһ��set�ӿ�
//	Date* pd = (Date*)malloc(sizeof(Date));// ���Ͽ��ٿռ䣬����û�г�ʼ��
//
//
//	// C++ �ṩ��һ�ֶ�̬�ڴ濪�ٷ�ʽ
//	int* ptr = (int*)malloc(sizeof(int));
//	int* ptr2 = (int*)malloc(sizeof(int)*10);
//
//	int* ptr3 = new int;
//	int* ptr4 = new int[10];
//	// new�����Ŀռ������ɵ����ռ�ĳ�ʼ��
//	int* ptr5 = new int(5);// ��ʼ��Ϊ5�������ռ䲻�ܳ�ʼ����ֻ�ܸ������ռ��ʼ�������ܳ�ʼ��
//
//	// �����ռ䣺new ����
//	// ���������ռ䣺 new+����[num]
//	// �������Ϳռ����� + ��ʼ���� new +����(��ʼ��ֵ)
//
//	// �ͷŵ����ռ�
//	delete ptr;
//	delete ptr3;
//	// �ͷ������ռ�
//	delete[] ptr4;
//
//	// ������ͷŵĲ���ƥ��ʹ�ã� malloc free
//	// new delete
//	// new [] delete[]
//
//	// new ���Զ����ù��캯��
//	// ���ù��캯��֮ǰ���ռ��Ѿ����ã���������this���ù��캯����
//	Date* pd = new Date(2020);
//	// ����Ҫ��Ĭ�Ϲ��캯�����Զ�����
//	// ���������ռ䣬�Զ�����Ĭ�Ϲ��캯�����г�ʼ�������û��Ĭ�Ϲ��죬����������
//	//
//	Date* pd2 = new Date[10];
//
//
//	// �ͷſռ��Զ�������������������Դ�����ͷſռ�
//	// ��һ����������ͻ����һ����������
//	// �����ռ�:����N������ + (һ��)�ͷſռ�
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
//	// �˴�������new���������
//	// �����Ǻ������Ƚ�����
//	//void* operator new(size_t n); // ������������غ���������һ��ȫ�ֺ���
//	// ���� new 10 �� ��malloc�÷�����
//
//	// new ��ִ�й��� : operator new -> malloc -> ���캯��
//	// ������ռ��ٹ��캯����ʼ��
//	int* ptr = (int*)operator new(sizeof(int));
//	// operator new : ��װ��malloc + �쳣������ʧ�ܣ��׳��쳣��
//
//	// void operator delete(void* ptr)
//	// ʹ�÷�ʽ�� free ����
//	// ��װ free(���в�û���쳣�����ڴ�һ�㲻��ܾ�)
//	// delete ִ�й���(�Զ�������):������-->operator delete->free
//	// �쳣���Դ���
//	operator delete(ptr);
//	free(ptr);
//
//	
//}
//
//
//void test7(){
//	Date* p = (Date*)malloc(sizeof(Date));
//	// new ��λ���ʽ��new (��ַ)����(�����б�)
//	// : ���Ѿ����õĿռ���ʽ���ù��캯��
//	new (p)Date(2030); // ����Ϊ�޲�
//
//	Date* p1 = (Date*)malloc(sizeof(Date));
//	new (p1)Date; // �˴�Ϊ�޲ι��캯��
//}
//
//// ���ͺ���
///* 
//template < typename / class ���Ͳ���1, typename / class ���Ͳ���2, .. > 
//��������{
//
//}
//*/
//
//// ���ͺ���
//// ģ��ʵ��������ʵ�ʲ����������ɿ�ִ�еĺ���
//// ����ģ���ʵ����
//// ���ͱ�̲�û�м���ʵ�ʵĴ�������ֻ�ǰ��ظ��Ĵ��뽻�������Զ�����
//// ���ٿ�����Ա�ظ��Ĺ���������߹���Ч��
//// ��ʽʵ���������������ݲ��������Զ��Ƶ�������ʵ�ʿ�ִ�еĴ���
//// ��ʽʵ������Swap<int>( a , b );
//// ������
//template <class T>
//void Swap(T& left, T& right){
//	T temp = left;
//	left = right;
//	right = temp;
//}
//class Node{
//public:
//	Node(){}
//	// ���ƽڵ�ռ����뷽ʽ
//	void* operator new (size_t n){
//		// �ڴ������
//		allocator<Node>().allocate(1);// ����һ��Node�Ŀռ���ڴ�ص���
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
//	// ֱ����ϵͳ����ռ�
//	// �������ڴ�أ�-->Ҫһ���ڴ汸�ã��Ȱ��ڴ��������������������������Ƶ�������ڴ�
//	// Ƶ�������ڴ�ƿ��
//	// �Ż����ڴ�ع���ռ�
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
//int cnt = 0; // ȫ���򣬲���ȫ
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
//	// ��̬��Ա����
//	// ��̬��Ա�������ܷ��ʷǾ�̬��Ա�����ͷǾ�̬��Ա����
//	// ��̬��Ա�����������ڲ�û�� this ָ��
//	// �ײ�û�� getCount( const Date* this ) : ֻ�� getCount()
//	// ��̬��Ա�������ܷ��ʷǾ�̬��Ա����/����
//	// ��Ϊ�Ǿ�̬��Ա��Ҫthisָ��,
//	// ���Ǿ�̬��Ա�����ڲ�ȱ��thisָ�룬���Բ��ܷ���
// 	static int getCount(){
//		return count;
//	}
//
//	// ��ͨ��Ա����ֻ��ͨ���������
//	// ����ͨ����������
//	// �Ǿ�̬��Ա�������Է��ʾ�̬��Ա�����;�̬��Ա����
//	void showinfo(){
//		cout << _year << endl;
//	}
//
//	// ֧������������������������
//	ostream& operator<<(ostream& _cout){
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}
//	friend ostream& operator<<(ostream& _cout, Date& d);
//	friend istream& operator>>(istream& _cin, Date& d); 
//	friend class B;
//private:
//	// C++11 ��ʼ����ʽ���൱�ڸ�һ��ȱʡֵ
//	// �˴���Ĭ��ֵ�����һ����ѡ��
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//	// ��̬��Ա���������ж�����˳�Ա���������Կ������Ա
//	// ��̬��Ա������������ʱ���Ĭ��ֵ
//	// �����ڳ�ʼ�������ʱ���ʼ��static����
//	// ��̬��Ա���ڶ���ģ���У�һ��������ݶΣ������ڳ�ʼ���б��г�ʼ��
//	// �������ʼ��
//	static int count ; // ���ж�����ı���
//};
//
//// ��̬��Ա�����������ʼ��
//int Date::count = 0;
//
//Date fun(Date d){ // ��������
//	return d; // ���ص�ʱ�����������������
//}
//
//
//void test1(){
//	Date d; // ����
//	Date d2 = fun(d); // �������죬�˴����Ż�������ֵû�����ã����ֱ���Ż���ֱ���þֲ�����d����������d2
//	cout <<"d = " << d.getCount() << endl;
//	cout << "d2 = "<<d2.getCount() << endl;
//	// ��̬��Ա�������ʷ�ʽ
//	// 1���������
//	// 2������+�������޶���
//	cout << "Date = " << Date::count << endl;
//	cout << "*&Date = " << *&Date::count << endl;
//
//	cout << "static getCount = " << Date::getCount() << endl;
//}
//
//// ��Ԫ�������Է������˽�г�Ա
//// ��Ԫ���������Ǳ���ĳ�Ա������������ͨ�ķǳ�Ա����
//// ��Ԫ����ֻ��Ҫ�����ж��壬����Ҫ�����ж���
//// �����������Ϊ��֧��������ֵ
//// �������ã���������������ڳ��ں���������Է�������
//// ��Ԫ�����������ã�����һ��ͻ���˷�װ�ĸ���
//// ��Ԫ������������������κεط����ƣ������޶�������
//// ��Ԫ��ϵ���ܴ��ݣ����������ѵ����Ѳ�һ�����Լ������ѣ�������ȷ��ʶ�������Կ��Ƶ��õ��õ���Ԫ��ϵ
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
//	// ������������
//	cin >> d3>>d3;
//	cout << d3;
//}
// 
////Ҫ��B����Date��˽�г�Ա����Ҫ����B��Ϊ��Date����Ԫ��
//class B{
//
//public:
//	// ��ǰ���Ϊ��Date���˽�г�Ա�Ϳ��Է���Date���˽�г�Ա
//	// ���һ��������һ�������Ԫ������������е����г�Ա����������һ�������Ԫ����
//	// friend �ǵ���ģ���Ҫ�໥���ʣ�����Ҫ˫������
//	// �ⲿ�಻�ܿ����ڲ������Ԫ�࣬�����ڲ���ĳ�Աû���������Ȩ�ޣ���Ҫ��ѭ�����޶���������
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
//	// �ڲ��࣬��һ�����ж���һ���µ���,�ڲ������������κεط�����
//	// �ڲ�����Ȼ����Ϊ�ⲿ�����Ԫ�� 
//public:
//	// �ڲ�������Ϊһ������������ڣ������������ⲿ��
//	class D{
//	public:
//		// �ڲ����еĳ�Ա��������ͨ���ⲿ���������ⲿ���˽�г�Ա
//		void showinfo(const C& c){
//			// ��̬��Ա����ֱ�ӷ��ʣ�������������
//			// ����ֱ�ӷ����ⲿ��ľ�̬��Ա
//			cout << _sc << endl;
//			cout << C::_sc << endl;
//			cout << c._a << endl;
//			// ö������Ҳֻ��ͨ�����������ʣ�����ֱ�ӷ���
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
////	// ��̬��Ա����
////	static int getCount(){
////		return cnt;
////	}
////
////	void operator<<(ostream& _cout){
////		_cout << _year << "-" << _month << endl;
////	}
////	// ��Ԫ�������ܷ����޶��������ƣ��������������е��κ�λ��
////	// ��Ԫ����: friend
////	// ��Ԫ�������Է������˽�г�Ա
////	// ��Ԫ�������ڶ���ģ�͵��У�������ĳ�Ա������������ͨ�ķǳ�Ա����
////	// ֻ��Ҫ������������Ԫ������Ҫ�����ж��壬
////	// ��Ԫ�����������ã�����һ��ͻ�Ʒ�װ���﷨
////	friend istream& operator>>(istream& _cin, Date& d);
////private:
////	// ��̬��Ա�������ܸ���ʼֵ�����ܳ�ʼ���б�
////	// ���Ա��ȫ�ֱ�������̬����û�з��ڶ���ģ�͵���
////	// ������������ʱ���Ĭ��ֵ��һ��������ݶΣ������ڳ�ʼ���б��г�ʼ����һ���������ʼ��
////	static int cnt;
////
////	int _year;
////	int _month;
////	int _day;
////
////	// ������Ԫ��
////	friend class A; // ��ʱ����A�ĺ����оͿ��Է��ʵ�ǰ���˽�г�Ա
////	// ���һ�����������һ�������Ԫ��
////	// ������еĳ�Ա����������Ԫ����
////	// ��Ԫ��ϵ�ǵ���ģ�˫����Ҫ˫������
////	// ��Ԫ��ϵ���ܴ��ݣ����������ѵ����Ѳ�һ�����Լ���friend
////	// ˭��˭��friendд�ú���ȷ�����ܿ��Ƶ�
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
////// �ڲ���
////class C{
////public:
////	// ��һ������ڲ�����һ���µ���
////	// ���Զ�����һ�����е��κεط�
////	// �ڲ�����Ȼ����Ϊ�ⲿ�����Ԫ��
////	// ���Է����ⲿ���˽�г�Ա
////	// ��Ȼ��ͨ���ⲿ��Ķ����Ա���ʣ���̬��Ա���Բ���,ֱ�ӷ��ʣ���������ʣ�
////	// ֱ�ӷ����ⲿ���static��Ա\
////
////	// �ڲ�������Ϊ����������ڵģ������������ⲿ��
////	// �ڲ���Ҳ�ǵ����ⲿ��Ӧ��
////
////	// �ⲿ�಻�ܿ����ڲ������Ԫ�࣬�����ڲ���ĳ�Աû������ķ���Ȩ��
////	class D{
////
////	};
////};
////void main(){
////	cout << "hongzheng" << endl;
////	Date::getCount(); // ��ͨ������֧�����ֲ�����ֻ�о�̬������֧�ִ˵Ȳ���
////	// ��̬��Ա�������ܷ��ʷǾ�̬��Ա�������߷Ǿ�̬��Ա����
////	// ��̬��Ա�����������ڲ�û�� this ָ��
////	// �Ǿ�̬��Ա������Ҫthisָ��
////	// ��̬������Ա�ڲ�ȱ�� this ָ�룬���Բ����Է���
////	// 
////	while (1);
////}
//
//* /