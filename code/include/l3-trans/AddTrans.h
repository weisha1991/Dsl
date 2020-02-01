#ifndef INCLUDE_L3_TRANS_ADDTRANS_H_
#define INCLUDE_L3_TRANS_ADDTRANS_H_

#include <l0-infra/trans-dsl/sched/helper/FragmentHelper.h>
#include <l0-infra/trans-dsl/sched/helper/ThrowHelper.h>
#include <l0-infra/trans-dsl/sched/helper/WaitHelper.h>
#include <l0-infra/trans-dsl/TransactionDSL.h>
#include <l3-trans/TransactionHelper.h>
#include "l0-infra/event/impl/SimpleEventInfo.h"
#include "l0-infra/event/concept/Event.h"
#include "l0-infra/trans-dsl/sched/concept/TransactionInfo.h"
#include "l3-trans/MccContext.h"

USING_TSL_NS

#define EVENT(n) SimpleEventInfo(n)
#define TIMER_EVENT(n) EVENT(n + 400)


const ActionThreadId WAIT_CANCEL_THREAD         = 1;
const ActionThreadId X1_RECFG_THEAD             = 2;
const ActionThreadId X1_REESTAB_SRB_THEAD       = 3;
const ActionThreadId X2_SN_STATUS_THREAD        = 4;
const ActionThreadId RNLU_ENDMARK_THREAD        = 5;

const EventId X2_HO_REQ              = 1;
const EventId BRS_SETUP_TUNNEL_ACK   = 2;
const EventId RNLU_CFG_ACK           = 3;
const EventId BB_CFG_ACK             = 4;
const EventId S1_PATH_SWITCH_ACK     = 5;
const EventId EV_SN_STATUS           = 6;
const EventId EV_X1_RRC_REESTAB_REQ  = 7;
const EventId EV_X1_RECFG_CMP        = 8;
const EventId EV_CANCEL              = 9;
const EventId BRS_RELEASE_TUNNEL_ACK = 10;
const EventId EV_X1_REESTAB_RSP      = 11;

const TimerId BRS_TIMER             = 1;
const TimerId X1_RECFG_TIMER        = 2;
const TimerId ENDMARK_TIMER         = 3;
const TimerId S1_PATH_SWITCH_TIMER  = 4;

enum : Status
{
    ERROR1 = failStatus(200),
    ERROR2,
    ERROR3,
    ERROR4,
    E_CANCELED,
    E_REESTAB
};
__def(X1RrcConnRequest)    __as ( __nop() );
__def(RrmAdmit)            __as ( __nop() );
__def(RnluSrb1Cfg)         __as ( __wait(RNLU_CFG_ACK) );
__def(BbSrb1Cfg)           __as ( __wait(BB_CFG_ACK) );
__def(X1RrcConnSetup)      __as ( __wait(3) );
__def(RrmConfirm)          __as ( __nop() );
__def(RnluConfirm)         __as ( __nop() );
__def(BbConfirm)           __as ( __nop() );
__def(X1RrcConnReject)     __as ( __nop() );
__def(X1UeCapQuery)        __as ( __wait(4) );
__def(S1InitUeReq)         __as ( __nop() );
__def(CpmS1RouteSelectRsp) __as ( __wait(5) );
__def(S1InitUeContextReq)  __as ( __wait(6) );
__def(X1SecurityActivate)  __as ( __wait(7) );
__def(RnluSecurityActivate) __as ( __nop() );
__def(RrmInitUeContextDrbAdmit) __as ( __nop() );
__def(RnluDrbCfg)         __as ( __wait(RNLU_CFG_ACK) );
__def(BbDrbCfg)           __as ( __wait(BB_CFG_ACK) );
__def(DbReadDrbParams)    __as ( __nop() );
__def(BrsNormalTunnelSetup)   __as ( __wait(BRS_SETUP_TUNNEL_ACK));
__def(BrsNormalFwdTunnelSetup)   __as ( __wait(BRS_SETUP_TUNNEL_ACK));
__def(BrsReleaseNormalTunnel)       __as( __wait(BRS_SETUP_TUNNEL_ACK) );
__def(X1SendRecfg)                __as( __wait(11) );
__def(S1InitUeContextReqSave) __as( __wait(12) );

__def(Rollback) __as ( __nop() );

__def(SMC) __as
( __sequential
   ( __fork(2, __apply(X1SecurityActivate))
   , __apply(RnluSecurityActivate))
);

__def(S1InitUe) __as
( __sequential
   ( __apply(S1InitUeReq)
   , __concurrent(__apply(CpmS1RouteSelectRsp), __apply(S1InitUeContextReq)))
);
////////////////////////////////////////////////
__def(LocalCfg, __params(__action(RNLU_CFG), __action(BB_CFG))) __as
( __timer_prot(1, __concurrent(RNLU_CFG, BB_CFG))
);

////////////////////////////////////////////////
__def(LocalConfirm) __as
( __sequential
   ( __apply(RrmConfirm)
   , __apply(RnluConfirm)
   , __apply(BbConfirm))
);

////////////////////////////////////////////////
__def(RrcConnPrepare) __as_procedure
( __sequential
  ( __apply(X1RrcConnRequest)
  , __apply(RrmAdmit)
  , __apply(LocalCfg, __with(__apply(RnluSrb1Cfg), __apply(BbSrb1Cfg))))
, __finally
  ( __on_fail(__sequential
				( __apply(X1RrcConnReject)
				, __apply(Rollback))))
);

////////////////////////////////////////////////
__def(RrcConnExecute) __as
( __sequential
  ( __apply(X1RrcConnSetup)
  , __fork(1, __apply(X1UeCapQuery))
  , __apply(RrmConfirm))
);

////////////////////////////////////////////////
__def(RrcConn) __as_procedure
( __sequential
   ( __apply(RrcConnPrepare)
   , __apply(RrcConnExecute))
);

__def(DrbSetupPrepare) __as_procedure
( __sequential
   ( __apply(RrmInitUeContextDrbAdmit)
   , __apply(DbReadDrbParams)
   , __apply(BrsNormalTunnelSetup)
   , __apply(LocalCfg, __with(__apply(RnluDrbCfg), __apply(BbDrbCfg))))
, __finally( __on_fail(__apply(Rollback)) )
);

__def(DrbSetupExecute) __as
( __sequential
   ( __apply(X1SendRecfg)
   , __apply(LocalConfirm))
);

__def(DrbSetup) __as_procedure
( __sequential
   ( __apply(DrbSetupPrepare)
   , __apply(DrbSetupExecute))
);

__def(S1InitUeContextRsp) __as( __nop() );

__def(InitUeContextSetup) __as_procedure
( __sequential
   ( __apply(S1InitUeContextReqSave)
   , __apply(SMC)
   , __apply(DrbSetup))
, __finally
   ( __apply(S1InitUeContextRsp) )
);

__mt_transaction
( __sequential
   ( __apply(RrcConn)
   , __timer_prot(2, __apply(S1InitUe))
   , __apply(InitUeContextSetup))
) trans;

///////////////////////////////////////////////////////////
__def(S1ErabSetupReq) __as(__nop());

__def(ErabSetupPrepare) __as_procedure
( __sequential
   ( __apply(S1ErabSetupReq)
   , __apply(RrmAdmit)
   , __apply(DbReadDrbParams)
   , __timer_prot(1, __apply(BrsNormalTunnelSetup))
   , __apply(LocalCfg, __with(__apply(RnluDrbCfg), __apply(BbDrbCfg))))
, __finally(__apply(Rollback))
);

__def(X1RecfgCmp) __as ( __wait(EV_X1_RECFG_CMP) );



__def(ErabSetupExecute) __as
( __sequential
   ( __apply(X1SendRecfg)
   , __fork(X1_RECFG_THEAD, __timer_prot(2, __apply(X1RecfgCmp)))
   , __apply(LocalConfirm))
);

__def(S1ErabSetupRsp) __as ( __nop() );

__mt_transaction
( __sequential
   ( __apply(ErabSetupPrepare)
   , __apply(ErabSetupExecute))
, __finally
   ( __sequential
	   ( __apply(S1ErabSetupRsp)
	   , __join(X1_RECFG_THEAD)))
) erabSetup;


__def(X2HodReq)        __as ( __wait(X2_HO_REQ) );
__def(X2HodAck)        __as ( __nop() );
__def(WaitX2HosCancel) __as ( __wait(EV_CANCEL));

__def(SnUpdate)     __as ( __wait(EV_SN_STATUS) );
__def(S1PathSwitch) __as ( __wait(S1_PATH_SWITCH_ACK) );
__def(RnluUlSwitch) __as ( __nop() );
__def(BrsReleaseFwdTunnel) __as ( __nop() );
__def(X2ReleaseSrc) __as ( __nop() );
__def(RnluWaitEndmark) __as ( __wait(20) );
__def(BrsAddrUpdate)   __as ( __wait(20) );
__def(RnluAddrUpdate)  __as ( __nop() );
__def(TransDataConfirm)  __as ( __nop() );


/////////////////////////////////////////////////////////////
__def(X2HodPrepare) __as_procedure
( __sequential
   ( __apply(X2HodReq)
   , __apply(RrmAdmit)
   , __apply(DbReadDrbParams)
   , __timer_prot(BRS_TIMER, __apply(BrsNormalFwdTunnelSetup))
   , __apply(LocalCfg, __with(__apply(RnluDrbCfg), __apply(BbDrbCfg))))
, __finally(__on_fail_except(E_CANCELED, __apply(X2HodAck)))
);

struct MyTimerInfo : TimerInfo
{
   U32 getTimerLen(const TimerId) const
   {
      return 10;
   }
} timerInfo;

/////////////////////////////////////////////////////////////
__def(PathSwitch) __as
( __sequential
  ( __timer_prot(S1_PATH_SWITCH_TIMER, __apply(S1PathSwitch))
  , __apply(BrsAddrUpdate)
  , __apply(RnluAddrUpdate))
);

/////////////////////////////////////////////////////////////
__def(CfgSwitch) __as
(__sequential
  ( __fork(RNLU_ENDMARK_THREAD, __apply(RnluWaitEndmark))
  , __apply(PathSwitch)
  , __apply(RnluUlSwitch)
  , __void(__timer_prot(ENDMARK_TIMER, __join(RNLU_ENDMARK_THREAD))))
);

/////////////////////////////////////////////////////////////
__def(ResourceConfirm) __as
( __sequential
   ( __apply(RrmConfirm)
   , __apply(TransDataConfirm))
);

/////////////////////////////////////////////////////////////
__def(X1RrcReestabReq)    __as ( __wait(EV_X1_RRC_REESTAB_REQ) );
__def(X1ReestabReq)       __as ( __wait(EV_X1_REESTAB_RSP) );
__def(X1RrcReestabReject) __as ( __nop() );

/////////////////////////////////////////////////////////////
__def(ReestabSrbPrepare) __as_procedure
( __sequential
   ( __apply(X1RrcReestabReq)
   , __apply(RrmAdmit)
   , __apply(LocalCfg, __with(__apply(RnluDrbCfg), __apply(BbDrbCfg))))
, __finally(__on_fail(__apply(X1RrcReestabReject)))
);

/////////////////////////////////////////////////////////////
__def(ReestabSrbExecute) __as
( __sequential
   ( __timer_prot(X1_RECFG_TIMER, __apply(X1ReestabReq))
   , __apply(RrmConfirm))
);

/////////////////////////////////////////////////////////////
__def(ReestabSrb) __as
( __sequential
   ( __apply(ReestabSrbPrepare)
   , __apply(ReestabSrbExecute))
);

/////////////////////////////////////////////////////////////
__def(X1ReestabSrb) __as
( __sequential
   ( __peek(EV_X1_RRC_REESTAB_REQ)
   , __fork(X1_REESTAB_SRB_THEAD, __apply(ReestabSrb)))
);

/////////////////////////////////////////////////////////////
__def(X1WaitRecfgCmp) __as
(__exclusive
  ( __wait(EV_X1_RECFG_CMP)
  , __apply(X1ReestabSrb)));

/////////////////////////////////////////////////////////////
__def(X2HodExecute) __as_procedure
( __sequential
  ( __apply(ResourceConfirm)  // must confirm RRM & TransData First.
  , __fork(X2_SN_STATUS_THREAD,  __apply(SnUpdate))
  , __timer_prot(X1_RECFG_TIMER, __apply(X1WaitRecfgCmp))
  , __apply(CfgSwitch)
  , __apply(BrsReleaseFwdTunnel))
, __finally(__on_fail_except(E_CANCELED, __apply(X2ReleaseSrc)))
);

/////////////////////////////////////////////////////////////
__def(X1Recfg) __as
( __sequential
   ( __apply(X1SendRecfg)
   , __timer_prot(X1_RECFG_TIMER, __apply(X1WaitRecfgCmp)))
);

struct IsX1Connected
{
  bool operator()(const TransactionInfo& info)
  { return true; }
};

struct HasFailedErab
{
  bool operator()(const TransactionInfo& info)
  { return true; }
};

/////////////////////////////////////////////////////////////
__def(CleanupFailedErab) __as
( __sequential
   ( __apply(RrmAdmit)
   , __apply(BrsReleaseNormalTunnel)
   , __apply(LocalCfg, __with(__apply(RnluDrbCfg), __apply(BbDrbCfg)))
   , __optional(IsX1Connected, __apply(X1Recfg))
   , __apply(RnluConfirm)
   , __apply(BbConfirm)
   , __apply(TransDataConfirm))
);

/////////////////////////////////////////////////////////////
__def(X2HodCleanup) __as
( __optional(HasFailedErab, __apply(CleanupFailedErab)));

/////////////////////////////////////////////////////////////
__def(x2hodTrans) __as_procedure
( __sequential
   (
    __apply(X2HodPrepare)
   )
);


struct MccTimerManager: TimerInfo
{
    MccTimerManager(){}
    Status load(){ return USI_SUCCESS;}
private:
    OVERRIDE(U32 getTimerLen(const TimerId) const)
    {
        return USI_SUCCESS;
    }
};

DEF_SIMPLE_MT_TRANS(x2hod, x2hodTrans, MccContext, MccTimerManager, 1);

#endif /* INCLUDE_L3_TRANS_ADDTRANS_H_ */
