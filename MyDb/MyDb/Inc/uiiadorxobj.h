#ifndef _UIIADORXOBJ_H__
#define _UIIADORXOBJ_H__

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef TPM_ADOSERVER
#define TPM_ADOSERVER _T("TPM_ADOSERVER")
#endif

#ifndef TPM_ADOSERVEROBJ
#define TPM_ADOSERVEROBJ _T("TPM_ADOSERVEROBJ")
#endif

#if defined(_TGADOSERVER_)
#define TGADORX_API	__declspec(dllexport)
#else
#define TGADORX_API	__declspec(dllimport)
#endif // _TG_AS_EXPORT

#include "rxsrvice.h"

class CUIIADORXServer;
class TGADORX_API CUIIADORxService : public AcRxService  
{
public:

	ACRX_DECLARE_MEMBERS(CUIIADORxService);

			 CUIIADORxService();
	virtual ~CUIIADORxService();

public:

	BOOL InitADOServer(CString sConnect,bool bDisplayException);

	CUIIADORXServer* GetADOServer();

private:

	CUIIADORXServer* m_pADOSrv;
	BOOL			 m_bConnected;
};

#endif
