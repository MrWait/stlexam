#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>
#include <map>
#include <algorithm>


// #progma comment(lib, "pthreadVC2.lib")
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void *thread_up(void *)
{
    return NULL;
}

void *thread_down(void *)
{
    return NULL;
}
void test1(void)
{

    int i;
    sem_t s;
    pthread_t t1, t2;
    cout<<"hello world!"<<endl;
    //  cin>>i;
    //  getchar();
    pthread_create(&t1, NULL, thread_up, 0);
    pthread_create(&t2, NULL, thread_down, 0);

}
////////////////////////////////
template<class I, class O>
class testClass
{
public:
    testClass()
        {
            cout<<"I, O"<<endl;
        }
};
template<class T>
class testClass<T*, T*>
{
public:
    testClass()
        {
            cout<<"T*, T*"<<endl;
        }
};
template<class T>
class testClass<const T*, T*>
{
public:
    testClass()
        {
            cout<<"const T*, T*"<<endl;
        }
};

void test2(void)
{
    testClass<int, char> obj1;
    testClass<int *, int *> obj2;
    testClass<const int *, int *> obj3;
}
////////////////////////////////
template<typename T>
class print
{
public:
    void operator()(const T& elem)
        {
            cout<<elem<<endl;
        }
};

void test3(void)
{
    int ia[6] = {1, 2, 3, 4, 5, 6};
    vector<int> iv(ia, ia + 6);
    for_each(iv.begin(), iv.end(), print<int>());
}
////////////////////////////////
template <typename T>
class testClass1
{
public:
    static const int _datai = 5;
    static const long _datal = 3L;
    static const char _datac = 'c';
};

void test4()
{
    cout<<testClass1<int>::_datai<<endl;
    cout<<testClass1<int>::_datal<<endl;
    cout<<testClass1<int>::_datac<<endl;
}
////////////////////////////////
class INT
{
    friend ostream& operator<<(ostream& os, const INT& i);
public:
    INT(int i):m_i(i)
        {

        };
    INT& operator++()
        {
            ++(this->m_i);
            return *this;
        }
    const INT operator++(int)
        {
            INT temp = *this;
            ++(*this);
            return temp;
        }

    INT& operator--()
        {
            --(this->m_i);
            return *this;
        }
    const INT operator--(int)
        {
            INT temp = *this;
            --(*this);
            return temp;
        }
    int& operator*() const
        {
            return (int&)m_i;
        }

private:
    int m_i;
};

ostream& operator<<(ostream& os, const INT& i)
{
    os << '[' << i.m_i << ']';
    return os;
}
////////////////////////////////
void test5()
{
    INT I(5);
    cout << I++;
    cout << ++I;
    cout << I--;
    cout << --I;
    cout << *I;
}
////////////////////////////////

int fcmp(const void *elem1, const void *elem2);

void test6()
{
    int ia[10] = {32, 92, 67, 58, 10, 4, 25, 52, 59, 54};
    for(int i = 0; i < 10; i++)
    {
        cout << ia[i] << " ";
    }
    qsort(ia, sizeof(ia)/sizeof(ia[0]), sizeof(int), fcmp);
    for(int i = 0; i < 10; i++)
    {
        cout << ia[i] << " ";
    }

}
int fcmp(const void *elem1, const void *elem2)
{
    const int *i1 = (const int*)elem1;
    const int *i2 = (const int*)elem2;
    if(*i1 < *i2)
    {
        return -1;
    }
    else if(*i1 == *i2)
    {
        return 0;
    }
    else if(*i1 > *i2)
    {
        return 1;
    }
}

////////////////////////////////

////////////////////////////////
int main(int argc, char** argv)
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
    getchar();
    return 0;
}
