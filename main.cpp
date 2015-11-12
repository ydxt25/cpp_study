#include <iostream>
#include <tuple>
#include <unordered_set>
#include <time.h>
#include <set>
#include <array>




class User
{
public:
    User()
    {
        std::cout<<"cons"<<std::endl;
    }
    User(const User &usr)
    {
        std::cout<<"copy"<<std::endl;
    }
    User(const User &&usr)
    {
        std::cout<<"move cons"<<std::endl;
    }
    ~User()
    {
        std::cout<<"desc"<<std::endl;
    }
    User & operator =(const User && usr)
    {
        std::cout<<"move operator"<<std::endl;
        return *this;
    }
    char p[sizeof(float)];
    int age;
};

void foo(const int & a)
{
    std::cout<<"void foo(const int & a):"<<a<<std::endl;
}

void foo(int & a)
{
    std::cout<<"void foo(int a):"<<a<<std::endl;
}

//void foo(User  a)
//{
//    a.age = 1990;
//    std::cout<<"void foo(User && a):"<<std::endl;
//}


User foo(User &usr)
{

    return usr;
}

void test_move_operator()
{
    User usr;
    User usr1;

    usr = foo(usr1);
}

User foo()
{
    User usr;
    return usr;
}

void test_move()
{
    User usr = foo();
}


int _main()
{
    decltype(0) age = 999;
    char p[] = u8"jiang\u2018";
    char16_t p1[] = u"jiang";
    char32_t p2[] = U"jiang";
    auto pp = R"(jiang)";
    std::tuple<int,char*> t1(32,"jiang");

    auto tp = std::make_tuple(344,6576);

    long lv = 999;
    auto tp1 = std::tie(lv);

    std::cout<<std::get<0>(tp)<<std::endl;

//#error 1>4
    std::cout<<alignof(char)<<std::endl;
    std::cout<<sizeof(User::age)<<std::endl;

    std::cout<<pp<<std::endl;
    std::cout<<sizeof(p)<<std::endl;
    std::cout<<sizeof(p1)<<std::endl;
    std::cout<<sizeof(p2)<<std::endl;
}

void test_unorderd_set()
{

    std::unordered_set<std::string> s;


    for(long i=0;i<10;++i)
    {
        //s.insert("gfergreger");
        s.emplace("hello world!!!");
        //s.bucket()
    }
    std::array<int,10> arr();

    time_t t1 = time(NULL);
    std::set<long> s1;
    for(long i=0;i<10000000;++i)
    {
        s1.insert(i);
    }
    std::cout<<time(NULL) - t1<<std::endl;
}
void foo(bool bstatus)
{
    std::cout<<bstatus<<std::endl;
}

class Student
{
public:
    Student(char *name)
    {

    }
};
#include <vector>
#include <boost/smart_ptr.hpp>
void test_smart_ptr()
{
    boost::scoped_ptr<int> sp(new int);
    *sp = 999;
    boost::scoped_ptr<int> sp1;//sp;
    sp.swap(sp1);
    assert(sp);
    std::unique_ptr<int> up ;
}

void test_vector()
{
    std::vector<std::string> v = {"hello","world"},v1;
//    v.emplace_back("hello");
    v1.assign(v.cbegin(),v.cend());


//    v.emplace_back("world");
    for(auto itm : v1)
    {
        std::cout<<itm<<std::endl;
    }
}

typedef struct Node
{
    int data;
    Node *next;
}*pnode;

#include <chrono>

void test_chrono()
{
    std::chrono::milliseconds ms(1000);
    std::chrono::system_clock sc;
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    std::cout<<(now + ms).time_since_epoch().count()<<std::endl;
    std::cout<<std::chrono::system_clock::to_time_t(now + ms)<<std::endl;
}

int main()
{
    //test_unorderd_set();
    //pnode pn = nullptr;
    //std::cout<<pn<<std::endl;
    //test_vector();
    test_chrono();
    //test_smart_ptr();
    //foo(4354);
    //foo(User(std::move(User())));
    //foo(User());
    //const char p[] = u8"hello world!!!";

    //test_move();
    //usr = foo();
    return 0;
}

