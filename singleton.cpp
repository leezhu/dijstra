/*
 *单例模式
 *时间:20170803
 *
 */

#include<iostream>
using namespace std;

class Singleton{
	public:
		static Singleton* getInstance(){
			return instance;
		}
	private:	//防止被复制
		Singleton(){};
		Singleton(const Singleton&){}
		Singleton& operator=(const Singleton&){}
		static Singleton* instance;
	
};
	Singleton* Singleton::instance = new Singleton();
int main()
{
	Singleton* singleton1 = Singleton::getInstance();
	Singleton* singleton2 = Singleton::getInstance();

	if(singleton1 == singleton2)
		cerr<<"yes";
	return 0;
}

