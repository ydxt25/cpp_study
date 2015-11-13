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
#include <assert.h>
void test_smart_ptr()
{
    boost::scoped_ptr<int> sp(new int);
    *sp = 999;
    boost::scoped_ptr<int> sp1;//sp;
    sp.swap(sp1);
    assert(!sp);
    std::unique_ptr<int> up,up1;

    assert(!up);
    up.reset(new int);
    *up = 8888;
    up.swap(up1);
    std::cout<<*up1<<std::endl;
}

void test_vector()
{
    std::vector<std::string> v = {"hello","world"},v1;
    v1.assign(v.cbegin(),v.cend());
    for(auto itm : v1)
    {
        std::cout<<itm<<std::endl;
    }
}


#include <chrono>

void test_chrono()
{
    std::chrono::milliseconds ms(1000);
    std::chrono::system_clock sc;
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    std::cout<<(now + ms).time_since_epoch().count()<<std::endl;
    std::cout<<std::chrono::system_clock::to_time_t(now + ms)<<std::endl;
}
#include <boost/regex.hpp>
void test_regex()
{
    try
    {
        boost::regex re("(\\d+).*");

        std::string str("123hello");

        boost::smatch res;

        if(boost::regex_match(str,res,re))
        {
            for(long i = 0;i<res.size() ; ++i)
            {
                std::cout<<res[i]<<std::endl;
            }
        }
        else
        {
            std::cout<<"not matched"<<std::endl;
        }
    }
    catch(boost::regex_error &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}


void test_find_file()
{
    try
    {
        boost::regex re("\\d{12}_\\d{4}-\\d{2}-\\d{2}.(\\w{3})");

        std::string str("55013630020106_2015-09-25.xls");

        boost::smatch res;

        if(boost::regex_search(str,res,re))
        {
            std::cout<<"matched"<<std::endl;
            for(long i = 0;i<res.size() ; ++i)
            {
                std::cout<<res[i]<<std::endl;
            }
        }
        else
        {
            std::cout<<"not matched"<<std::endl;
        }
    }
    catch(boost::regex_error &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}


void test_split_string()
{
    try
    {
        boost::regex re(" ");
        std::string str = "54  65 76 87 98 90";
        boost::sregex_token_iterator iter(str.begin(),str.end(),re);
        boost::sregex_token_iterator end;
        while(iter != end)
        {
            std::cout<<iter->str()<<std::endl;
            ++iter;
        }
    }
    catch(boost::regex_error & e)
    {
        std::cout<<e.what()<<std::endl;
    }
}


#include <boost/ref.hpp>
void test_ref()
{
    int age = 999;
    std::cout<<&age<<std::endl;
    auto _age = boost::ref(age);
    _age++;
    std::cout<<&_age<<std::endl;
}


class Node
{
public:
    Node(int aa)
    {
        a = new int;
        *a = aa;
    }
    ~Node()
    {
        delete a;
    }
    operator int & (){return *a;}
    int *a;
};

void foo1(Node n)
{
    std::cout<<"foo1"<<std::endl;
}

void test(int& a)
{
    std::cout<<"++++++++++"<<a<<std::endl;
}

void test_cast()
{
    Node node(3333);
    std::cout<<node<<std::endl;
    test(node);
    foo1(455);
}

template <typename T>
T func(T t)
{
    return t;
}

int add(int lhs,int rhs)
{
    return lhs + rhs;
}
void test_func_template()
{
    //std::cout<<func(add)(43,54)<<std::endl;
    std::plus<int> add;
    std::cout<<add(43564,6576)<<std::endl;
}

void test_lambda()
{
    auto add = [](int lhs,int rhs)->int{return lhs + rhs;};
    std::cout<<add(3333,4444)<<std::endl;
}

#define prefix(x) "tb_"#x
#define stringfy(x) __FILE__ #x
#define dstringfy(x,y) x##y

#define pre  tb_

void test_precompile()
{
    int tb_user = 999;
    std::cout<<prefix(pre)<<std::endl;
    std::cout<<stringfy(user)<<std::endl;
    std::cout<<dstringfy(tb_,user)<<std::endl;


    std::cout<<2e3<<std::endl;
    std::cout<<INT_MAX<<std::endl;

}


class Teacher
{
public:
    Teacher(int id,std::string name):
        _id(id),
        _name(name)
    {

    }
    int _id;
    std::string _name;
};
void test_initializer_list()
{
    Teacher teach = {32,"jianglh"};
    Teacher teach1 = {32,"jianglh"};
    std::cout<<teach._name<<std::endl;
}

int main()
{
    test_initializer_list();
    //test_precompile();
    //test_lambda();
    //test_func_template();
    //test_unorderd_set();
    //pnode pn = nullptr;
    //std::cout<<pn<<std::endl;
    //test_vector();
    //test_chrono();
    //test_regex();
    //test_find_file();

    //test_split_string();
    //test_smart_ptr();
    //test_ref();
    //test_cast();
    //foo(4354);
    //foo(User(std::move(User())));
    //foo(User());
    //const char p[] = u8"hello world!!!";

    //test_move();
    //usr = foo();
    return 0;
}

