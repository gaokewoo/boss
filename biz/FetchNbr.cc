#include "FetchNbr.hh"
#include "libconfparser/confparser.hpp"

FetchNbr::FetchNbr(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "FetchNbr::FetchNbr start");

    srand( (unsigned)time( NULL ) );

    LOG_DEBUG(logId, "Parse boss.cfg");
    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    string db_user = CONF_PARSER_GET_VAL("DB", "user");
    string db_passwd = CONF_PARSER_GET_VAL("DB", "passwd");
    string db_instance = CONF_PARSER_GET_VAL("DB", "instance");
    LOG_DEBUG(logId, "DB User:"<<db_user);
    LOG_DEBUG(logId, "DB Passwd:"<<db_passwd);
    LOG_DEBUG(logId, "DB Instance:"<<db_instance);

    m_db = new OracleDB(db_user,db_passwd,db_instance);
    m_db->connectToDB();

    lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_create(&threadId,NULL,loadingData,this);

    LOG_DEBUG(m_logId, "FetchNbr::FetchNbr end");
}

FetchNbr::~FetchNbr()
{
    LOG_DEBUG(m_logId, "FetchNbr::~FetchNbr start");
    pthread_cancel(threadId);
    pthread_join(threadId,NULL);
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "FetchNbr::~FetchNbr end");
}

void * FetchNbr::loadingData(void *owner)
{
    ((FetchNbr*)owner)->loadingData();
}

void FetchNbr::loadingData()
{
    //get serv_identification info
    ServIdentification m_serv_ident;
    m_serv_ident.setConnection(m_db->getConnection());
   
    while(true)
    {
        LOG_INFO(m_logId, "FetchNbr::loadingData begin");

        vector<ST_SERV_IDENTIFICATION> v_data_tmp;
        v_data_tmp = m_serv_ident.getMultiRandomServIdentInfo();

        if(v_data_tmp.size()<10000)
        {
            LOG_INFO(m_logId, "FetchNbr::loadingData data size too small, sleep 1 seconds, then try again.");
            sleep(1);
            continue;
        }

        pthread_rwlock_wrlock(&lock);
        v_data=v_data_tmp;
        pthread_rwlock_unlock(&lock);

        LOG_INFO(m_logId, "FetchNbr::loadingData end");

        sleep(3600);
    }

}

string FetchNbr::doBiz()
{
    LOG_DEBUG(m_logId, "FetchNbr::doBiz start");

    while(true)
    {
        pthread_rwlock_rdlock(&lock);
        if(v_data.empty())
        {
            LOG_INFO(m_logId,"vector is empty, wait 1 seconds");

            pthread_rwlock_unlock(&lock);
            sleep(1);
        }
        else
        {
            pthread_rwlock_unlock(&lock);
            break;
        }
    }

    pthread_rwlock_rdlock(&lock);
    string nbr=v_data[rand()%v_data.size()].m_acc_nbr;
    pthread_rwlock_unlock(&lock);

    LOG_INFO(m_logId,"The random nbr is:"<<nbr);

    LOG_DEBUG(m_logId, "FetchNbr::doBiz end");

    return nbr;
}


