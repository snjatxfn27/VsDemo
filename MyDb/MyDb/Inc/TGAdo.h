#ifndef __ADORX_H__
#define __ADORX_H__

#if defined(_TG_ADO_EXPORT)
#define TGADOSRV_API	__declspec(dllexport)
#else
#define TGADOSRV_API	__declspec(dllimport)
#endif // _TG_AS_EXPORT

#pragma warning(push)
#pragma warning(disable: 4146)

#pragma message ("     Compiling and linking TGAdoKernel.")

#if _MFC_VER == 0X0600
	#pragma comment(lib,"Tch_AdoKernel15.lib")
#elif _MFC_VER == 0X0700
	#pragma comment(lib,"Tch_AdoKernel16.lib")
#elif _MFC_VER == 0X0800
	#pragma comment(lib,"Tch_AdoKernel17.lib")
#elif _MFC_VER == 0X0900
	#if _WIN64
		#pragma comment(lib,"tch_AdoGlue18.lib")
		#pragma comment(lib,"Tch_AdoKernel18.lib")
	#else
		#pragma comment(lib,"Tch_AdoKernel18.lib")
	#endif
#elif _MFC_VER == 0X0A00
	#if _WIN64
		#pragma comment(lib,"tch_AdoGlue19.lib")
		#pragma comment(lib,"Tch_AdoKernel19.lib")
	#else
		#pragma comment(lib,"Tch_AdoKernel19.lib")
	#endif	
#else
	#error "Invalidate compile version!"
#endif // _MFC_VER

#include "UIIValueRecord.h"
#include "UIIValueTable.h"
#include "UIIPackageDbOper.h"
#include "BrowseForFolder.h"

#ifdef _WIN64
	#include "TGAdoKernelX64.h"
	#define CUIIADORXServer CTGAdoKernel
#else
	#include "UIIADORXServer.h"
#endif

#pragma warning(pop)

#endif
