#ifndef _UIIADO_H__
#define _UIIADO_H__

#if defined(_TG_ADO_EXPORT)
#define TGADOSRV_API	__declspec(dllexport)
#else
#define TGADOSRV_API	__declspec(dllimport)
#endif // _TG_AS_EXPORT

#if ADS<17
#ifndef _tstof
#define _tstof(x) atof(x)
#endif
#endif

#include "UIIValueRecord.h"
#include "UIIValueTable.h"

#ifdef _WIN64
#include "TGAdoKernelX64.h"
#define CUIIADORXServer CTGAdoKernel
#include <comdef.h>
#else
#include "UIIADORXServer.h"
#include "UIIPackageDbOper.h"
#include "BrowseForFolder.h"
#endif

#include "CUIIADOShell.h"

#endif