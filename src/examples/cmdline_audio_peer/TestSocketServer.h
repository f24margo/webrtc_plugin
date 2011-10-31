//
//  TestSocketServer.h
//  TestPeerConnectionClient
//
//  Created by Manjesh Malavalli on 10/18/11.
//  Copyright 2011 XVDTH. All rights reserved.
//

#ifndef TestPeerConnectionClient_TestSocketServer_h
#define TestPeerConnectionClient_TestSocketServer_h

#include <deque>
#include <map>
#include <string>
#include <pthread.h>
#include "talk/base/thread.h"
#include "talk/base/physicalsocketserver.h"
#include "TestPeerConnectionClient.h"
#include "TestPeerConnectionObserver.h"

class ThreadSafeMessageQueue
{
public:
    typedef std::map<std::string, std::string> ParsedCommand;
    
private:
    std::deque<ParsedCommand*> cmdQ;
    pthread_mutex_t qMutex;
    
public:
    ThreadSafeMessageQueue();
    ~ThreadSafeMessageQueue();
    void PostMessage(ParsedCommand* pMsg);
    ParsedCommand* GetNextMessage(void);
};

class TestSocketServer : public talk_base::PhysicalSocketServer
{
protected:
    talk_base::Thread* m_pThread;
    TestPeerConnectionClient* m_pClient;
    ThreadSafeMessageQueue* m_pQueue;
    
public:
    TestSocketServer(ThreadSafeMessageQueue* pQueue);
    virtual ~TestSocketServer();
    void SetTestPeerConnectionClient(TestPeerConnectionClient* pClient);
    virtual bool Wait(int cms, bool process_io);
};

#endif
