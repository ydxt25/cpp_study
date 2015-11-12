#include <iostream>
#include <tuple>
#include <unordered_set>
#include <time.h>
#include <set>



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

    std::unordered_set<string> s;


    for(long i=0;i<10000000;++i)
    {
        s.insert("gfergreger");
    }


    time_t t1 = time(NULL);
    std::set<long> s1;
    for(long i=0;i<10000000;++i)
    {
        s1.insert(i);
    }
    std::cout<<time(NULL) - t1<<std::endl;
}

int main()
{
    test_unorderd_set();
    //foo(4354);
    //foo(User(std::move(User())));
    //foo(User());
    //const char p[] = u8"hello world!!!";

    //test_move();
    //usr = foo();
    return 0;
}

