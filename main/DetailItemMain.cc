#include <iostream>
#include <string>
#include <signal.h>
#include "libconfparser/confparser.hpp"
#include "DetailItem.hh"
#include <queue>

using namespace std;

int frequence;
LoggerId logId;

void handler(int signo)
{
    cerr<<"Program terminated"<<endl;  
    exit(0);  
}

class DetailItemPool
{
    public:
        DetailItemPool(LoggerId logId, int poolNum=10)
        {
            qready = PTHREAD_COND_INITIALIZER;
            qlock = PTHREAD_MUTEX_INITIALIZER;

            for(int i=0; i<poolNum; i++)
            {
                m_queue.push(new DetailItem(logId));
            }
        }

        ~DetailItemPool()
        {
            while(!m_queue.empty())
            {
                DetailItem *p = m_queue.front();
                m_queue.pop();

                delete p;
            }
        }

        DetailItem* get()
        {
            pthread_mutex_lock(&qlock);

            while(m_queue.empty())
            {
                pthread_cond_wait(&qready, &qlock);
            }

            DetailItem *p = m_queue.front();
            m_queue.pop();

            pthread_mutex_unlock(&qlock);

            return p;
        }

        void put(DetailItem *p)
        {
            pthread_mutex_lock(&qlock);
            m_queue.push(p);
            pthread_mutex_unlock(&qlock);
            pthread_cond_signal(&qready);
        }

    private:
        queue<DetailItem*> m_queue;
        pthread_cond_t qready;
        pthread_mutex_t qlock;
};

DetailItemPool *m_detail_item_pool=NULL;

void *thread_func(void *)
{
    while(1)
    {
        //cout<<"----------thread_id:"<<pthread_self()<<"["<<++i<<"]----------"<<endl;
        DetailItem *p = m_detail_item_pool->get();
        p->doBiz();
        m_detail_item_pool->put(p);

        usleep(frequence*1000);
    }

    return 0;
}

void mkDaemon(void)
{
    pid_t pid;
    pid_t sid;

    pid = fork();
    if (pid == -1)
      printf("Failed to fork() ");

    if (pid) {
        exit(0);
    }

    sid = setsid();
    if (sid == -1)
      abort();
    return;
} 

int main(int argc, char** argv) {   

    mkDaemon();

    ILog4zManager::GetInstance()->Config("../conf/log.cfg");
    logId = ILog4zManager::GetInstance()->FindLogger("DetailItem");
    ILog4zManager::GetInstance()->Start();

    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    int thread_num = CONF_PARSER_GET_NUM_VAL("DetailItem", "thread_num");
    cout<<"Thread num:"<<thread_num<<endl;

    int frequence = CONF_PARSER_GET_NUM_VAL("DetailItem", "frequence");
    cout<<"The client send request each "<<frequence<<" milliseconds."<<endl;

    signal(SIGINT,handler);

    try 
    {
        m_detail_item_pool=new DetailItemPool(logId);

        pthread_t *threadArr=new pthread_t[thread_num];
        for(int i=0; i<thread_num; i++)
        {
            cout<<"Create thread:"<<i<<endl;
            pthread_create(&threadArr[i],NULL,thread_func,0);
        }

        for(int i=0; i<thread_num; i++)
        {
            pthread_join(threadArr[i],NULL);
        }

    }
    catch (...) 
    {   
        cerr<<"ERROR....."<<endl;
        exit(-1);
    }   

}
