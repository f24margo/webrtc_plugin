/**********************************************************\

  Auto-generated WebrtcPluginAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "WebrtcPlugin.h"
#include "WPLThreadSafeMessageQueue.h"
#include "ThreadSingle.h"

#ifndef H_WebrtcPluginAPI
#define H_WebrtcPluginAPI

class PluginNotificationsThread;

class PluginMainThread : public ThreadSingle
{
public:
    PluginMainThread(projectname::ThreadSafeMessageQueue* pMsgQ,
                     projectname::ThreadSafeMessageQueue* pEvtQ):
    m_pMsgQ(pMsgQ), m_pEvtQ(pEvtQ) {}
    
    virtual ~PluginMainThread() {}
    
protected:
    int workerBee(void);
    
protected:
    projectname::ThreadSafeMessageQueue* m_pMsgQ;
    projectname::ThreadSafeMessageQueue* m_pEvtQ;
};

class WebrtcPluginAPI : public FB::JSAPIAuto
{
public:
    WebrtcPluginAPI(const WebrtcPluginPtr& plugin, const FB::BrowserHostPtr& host);
    virtual ~WebrtcPluginAPI();

    WebrtcPluginPtr getPlugin();

    // Read/Write property ${PROPERTY.ident}
    std::string get_testString();
    void set_testString(const std::string& val);

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

    // Method echo
    FB::variant echo(const FB::variant& msg);
    void Signin(const std::string& peerName,
                const std::string& serverIP,
                const int serverPort);
    void Signout(void);
    void Call(const std::string& peerName);
    void Hangup(const std::string& peerName);
    
    // Event helpers
    FB_JSAPI_EVENT(fired, 3, (const FB::variant&, bool, int));
    FB_JSAPI_EVENT(echo, 2, (const FB::variant&, const int));
    FB_JSAPI_EVENT(notify, 0, ());
    
    FB_JSAPI_EVENT(SignedIn, 1, (const std::string&));
    FB_JSAPI_EVENT(PeerOnline, 1, (const std::string&));
    FB_JSAPI_EVENT(PeerOffline, 1, (const std::string&));
    FB_JSAPI_EVENT(RemotePeerCall, 1, (const std::string&));
    FB_JSAPI_EVENT(RemotePeerHangup, 1, (const std::string&));

    // Method test-event
    void testEvent(const FB::variant& s);

private:
    WebrtcPluginWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;
    PluginMainThread* m_pMainThread;
    PluginNotificationsThread* m_pNotificationsThread;
    projectname::ThreadSafeMessageQueue* m_pMsgQ;
    projectname::ThreadSafeMessageQueue* m_pEvtQ;
};

class PluginNotificationsThread : public ThreadSingle
{
public:
    PluginNotificationsThread(WebrtcPluginAPI* pPluginAPI,
                              projectname::ThreadSafeMessageQueue* pEvtQ):
    m_pPluginAPI(pPluginAPI), m_pEvtQ(pEvtQ) {}
    
    virtual ~PluginNotificationsThread() {}
    
protected:
    int workerBee(void);
    
protected:
    WebrtcPluginAPI* m_pPluginAPI;
    projectname::ThreadSafeMessageQueue* m_pEvtQ;
};

#endif // H_WebrtcPluginAPI
