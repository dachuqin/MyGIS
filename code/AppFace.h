

#ifndef __APPFACE_H__
#define __APPFACE_H__


#define GTP_LOAD_FILE     1
#define GTP_LOAD_MEMORY   2
#define GTP_LOAD_RESOURCE 3

class CAppFace
{
public:

typedef bool (*APPFACE_START)(char*,char*,int,DWORD,char*);
typedef void (*APPFACE_REMOVE)();

	
	CAppFace(LPCTSTR DllPath = _T("AppFace.dll"))
	{
		pfnStart    = NULL ;
		pfnRemove   = NULL ;
		m_bValid    = FALSE; 
		m_hDll      = NULL ;
		Init(DllPath) ;
	};
	~CAppFace(){Release(); };

	bool Init(LPCTSTR DllPath)
	{
		if(m_hDll && m_bValid)	
			return true;
		m_hDll = ::LoadLibrary(DllPath);
		if(m_hDll == NULL)
			return false ;
		
		pfnStart = (APPFACE_START) GetProcAddress(m_hDll, "SkinStart"); 
		if(!pfnStart)	    return false; 
		pfnRemove= (APPFACE_REMOVE)GetProcAddress(m_hDll, "SkinRemove"); 
		if(!pfnRemove)	    return false; 

		m_bValid = true ;
		return true ;
	};

	bool IsValid(){return m_bValid;};

	//----------------------------
	//We'll call these functions.
	bool Start(void* SkinFile=NULL,  //Source buffer
				int Type = GTP_LOAD_FILE, //Loading type
				DWORD hInst= NULL,   //The HINSTANCE for the loaded module or the size of the memory block
				LPCTSTR szResType =NULL,  //Resource type ,only used when Type is GTP_LOAD_RESOURCE
				LPCTSTR szCheckSum= NULL  //Checksum string,not used for the free version
				)
	{
		if(pfnStart)
		{
			if(!SkinFile)
			{
				return pfnStart(NULL,NULL,NULL,NULL,NULL);
			}
			else
			{
				char  checksum[256] ;
				if(Type == GTP_LOAD_MEMORY)
				{
					T2C(szCheckSum,checksum,256) ;
					return pfnStart((char*)SkinFile,checksum,Type,hInst,NULL);
				}
				else
				{
					char  skinfile[256] ;
					char  type[256] ;
					T2C((LPCTSTR)SkinFile,skinfile,256) ;
					T2C(szResType,type,256) ;
					return pfnStart(skinfile,checksum,Type,hInst,type);
				}
			}
		}
		return false;
	};
	void Remove() { if(pfnRemove) pfnRemove() ;};
	//----------------------------

private:
	bool m_bValid  ;  
	HMODULE m_hDll ;

	APPFACE_START       pfnStart       ;
	APPFACE_REMOVE      pfnRemove      ;

	//Convert a TCHAR string to char string
	void T2C(IN LPCTSTR src,OUT char* dst,IN int dstlen)
	{
		memset(dst,0,dstlen);
		if(!src || !dst) return ;		
	//----------------------------
#ifdef UNICODE
		BOOL bRes= FALSE ;
		WideCharToMultiByte(CP_ACP,
			0,
			src,
			wcslen(src),
			dst,
			dstlen,
			NULL,
			&bRes);
#else
		strncpy(dst,src,dstlen-1) ;
#endif
	} ;

protected:
	void Release()
	{
		if(m_hDll)
		{
			FreeLibrary(m_hDll);
			m_hDll = NULL        ;
			m_bValid = false ;
			pfnStart = NULL ;
			pfnRemove= NULL ;
		}
	};
};

#endif  //__APPFACE_H__
