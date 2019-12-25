#ifndef __PLATFORMDEF_H
#define __PLATFORMDEF_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <sstream>

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
	#include <io.h>
	#define __XT(x)      L ## x
	typedef  wchar_t XCHAR;
	typedef  __int64 XINT64;
	typedef unsigned __int64 XUINT64;

	typedef  std::wstring XString;


	#define XFSeek _fseeki64
	#define XFTell _ftelli64
	#define XPreferredSeparator L"\\"
	#define  _XFUNCTION_ __FUNCTIONW__
	#define  _XFILE_ __FILEW__
	#define XStrLen wcslen
	#define XStrncmp wcsncmp
	typedef std::wstringstream XStringStream;
	std::string Unicode_to_UTF8(const wchar_t* in, int len);
	std::string Unicode_to_Local(const wchar_t* in, int len);
	XString UTF8_to_Unicode(const char* in, int len);
	XString Local_to_Unicode(const char* in, int len);
#define  XStringToUTF8(str) Unicode_to_UTF8(str.c_str(),str.length()) 
#define  UTF8TOXString(str) UTF8_to_Unicode(str.c_str(),str.length())
#define  XStringToLocal(str) Unicode_to_Local(str.c_str(),str.length()) 
#define  LocalToXString(str) Local_to_Unicode(str.c_str(),str.length())
#define  UTF8TOXString2(str) UTF8_to_Unicode(str,strlen(str))

#else
	#define __XT(x)      x
	typedef  std::string XString;		
	typedef char XCHAR;
	typedef long long XINT64;
	typedef unsigned long long XUINT64;
    typedef  void* HMODULE;
	#define XFSeek fseeko
	#define XFTell ftello
	typedef std::stringstream XStringStream;
	#define XPreferredSeparator "/"
	#define  _XFUNCTION_ __FUNCTION__
	#define  _XFILE_ __FILE__	
	#define  XStringToUTF8(str) str 
	#define  UTF8TOXString(str) str 
	#define  UTF8TOXString2(str) std::string(str)
	#define  XStringToLocal(str) str 
	#define LocalToXString(str) str
	#define XStrLen strlen
	#define XStrncmp strncmp
#endif
	//定义一个32，64 数字类型自适应类型，根据平台不同确定是int 还是int64

	typedef unsigned char byte;

    //参数二是元素的个数。包括0 结尾 xchar 对于windows 一个元素2字节
    //如： XCHAR char[100]={0};  参数2 填入100
    int XStrCpy_S(XCHAR* pszDest, int iDestElementCount, const XCHAR*pszSrc);
#endif
