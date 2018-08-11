// **********************************************************************
// This file was generated by a TAF parser!
// TAF version 2.1.5.0 by WSRD Tencent.
// Generated from `Role.jce'
// **********************************************************************

#ifndef __ROLE_H_
#define __ROLE_H_

#include <map>
#include <string>
#include <vector>
#include "jce/Jce.h"
using namespace std;
#include "DalMoDef.h"
#include "servant/ServantProxy.h"
#include "servant/Servant.h"


namespace ServerEngine
{
    enum enRoleRetCode
    {
        en_RoleRet_OK,
        en_RoleRet_NameDunplicated,
        en_RoleRet_PosConflict,
        en_RoleRet_NotExist,
        en_RoleRet_SysError,
    };
    inline string etos(const enRoleRetCode & e)
    {
        switch(e)
        {
            case en_RoleRet_OK: return "en_RoleRet_OK";
            case en_RoleRet_NameDunplicated: return "en_RoleRet_NameDunplicated";
            case en_RoleRet_PosConflict: return "en_RoleRet_PosConflict";
            case en_RoleRet_NotExist: return "en_RoleRet_NotExist";
            case en_RoleRet_SysError: return "en_RoleRet_SysError";
            default: return "";
        }
    }
    inline int stoe(const string & s, enRoleRetCode & e)
    {
        if(s == "en_RoleRet_OK")  { e=en_RoleRet_OK; return 0;}
        if(s == "en_RoleRet_NameDunplicated")  { e=en_RoleRet_NameDunplicated; return 0;}
        if(s == "en_RoleRet_PosConflict")  { e=en_RoleRet_PosConflict; return 0;}
        if(s == "en_RoleRet_NotExist")  { e=en_RoleRet_NotExist; return 0;}
        if(s == "en_RoleRet_SysError")  { e=en_RoleRet_SysError; return 0;}

        return -1;
    }


    /* callback of async proxy for client */
    class RolePrxCallback: public taf::ServantProxyCallback
    {
    public:
        virtual ~RolePrxCallback(){}
        virtual void callback_newRole(taf::Int32 ret)
        { throw std::runtime_error("callback_newRole() overloading incorrect."); }
        virtual void callback_newRole_exception(taf::Int32 ret)
        { throw std::runtime_error("callback_newRole_exception() overloading incorrect."); }

        virtual void callback_updateRole(taf::Int32 ret)
        { throw std::runtime_error("callback_updateRole() overloading incorrect."); }
        virtual void callback_updateRole_exception(taf::Int32 ret)
        { throw std::runtime_error("callback_updateRole_exception() overloading incorrect."); }

        virtual void callback_delRole(taf::Int32 ret)
        { throw std::runtime_error("callback_delRole() overloading incorrect."); }
        virtual void callback_delRole_exception(taf::Int32 ret)
        { throw std::runtime_error("callback_delRole_exception() overloading incorrect."); }

        virtual void callback_getRole(taf::Int32 ret,  const ServerEngine::PIRole& roleInfo)
        { throw std::runtime_error("callback_getRole() overloading incorrect."); }
        virtual void callback_getRole_exception(taf::Int32 ret)
        { throw std::runtime_error("callback_getRole_exception() overloading incorrect."); }

    public:
        int onDispatch(taf::ReqMessagePtr msg);
    };
    typedef taf::TC_AutoPtr<RolePrxCallback> RolePrxCallbackPtr;

    /* proxy for client */
    class RoleProxy : public taf::ServantProxy
    {
    public:
        typedef map<string, string> TAF_CONTEXT;
        taf::Int32 newRole(const std::string & strAccount,taf::Int32 nPos,taf::Int32 nWorldID,const std::string & strName,const ServerEngine::PIRole & roleInfo,const map<string, string> &context = TAF_CONTEXT());
        void async_newRole(RolePrxCallbackPtr callback,const std::string & strAccount,taf::Int32 nPos,taf::Int32 nWorldID,const std::string & strName,const ServerEngine::PIRole & roleInfo,const map<string, string> &context = TAF_CONTEXT());

        taf::Int32 updateRole(const ServerEngine::PKRole & keyData,const ServerEngine::PIRole & roleInfo,const map<string, string> &context = TAF_CONTEXT());
        void async_updateRole(RolePrxCallbackPtr callback,const ServerEngine::PKRole & keyData,const ServerEngine::PIRole & roleInfo,const map<string, string> &context = TAF_CONTEXT());

        taf::Int32 delRole(const ServerEngine::PKRole & keyData,const map<string, string> &context = TAF_CONTEXT());
        void async_delRole(RolePrxCallbackPtr callback,const ServerEngine::PKRole & keyData,const map<string, string> &context = TAF_CONTEXT());

        taf::Int32 getRole(const ServerEngine::PKRole & keyData,ServerEngine::PIRole &roleInfo,const map<string, string> &context = TAF_CONTEXT());
        void async_getRole(RolePrxCallbackPtr callback,const ServerEngine::PKRole & keyData,const map<string, string> &context = TAF_CONTEXT());

        RoleProxy* taf_hash(int64_t key);
    };
    typedef taf::TC_AutoPtr<RoleProxy> RolePrx;

    /* servant for server */
    class Role : public taf::Servant
    {
    public:
        virtual ~Role(){}
        virtual taf::Int32 newRole(const std::string & strAccount,taf::Int32 nPos,taf::Int32 nWorldID,const std::string & strName,const ServerEngine::PIRole & roleInfo,taf::JceCurrentPtr current) = 0;
        static void async_response_newRole(taf::JceCurrentPtr current, taf::Int32 _ret);

        virtual taf::Int32 updateRole(const ServerEngine::PKRole & keyData,const ServerEngine::PIRole & roleInfo,taf::JceCurrentPtr current) = 0;
        static void async_response_updateRole(taf::JceCurrentPtr current, taf::Int32 _ret);

        virtual taf::Int32 delRole(const ServerEngine::PKRole & keyData,taf::JceCurrentPtr current) = 0;
        static void async_response_delRole(taf::JceCurrentPtr current, taf::Int32 _ret);

        virtual taf::Int32 getRole(const ServerEngine::PKRole & keyData,ServerEngine::PIRole &roleInfo,taf::JceCurrentPtr current) = 0;
        static void async_response_getRole(taf::JceCurrentPtr current, taf::Int32 _ret, const ServerEngine::PIRole &roleInfo);

    public:
        int onDispatch(taf::JceCurrentPtr _current, vector<char> &_sResponseBuffer);
    };


}



#endif