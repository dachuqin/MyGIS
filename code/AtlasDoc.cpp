// AtlasDoc.cpp : implementation of the CAtlasDoc class
//

#include "stdafx.h"
#include "Atlas.h"

#include "AtlasDoc.h"
#include "AtlasView.h"
#include "MainFrm.h"
#include "GeoAnno.h"
#include "GeoPolygon.h"
#include "GeoLayer.h"
#include "GeoMap.h"
#include "GeoObject.h"
#include "GeoLine.h"
#include "GeoPoint.h"

#include "Shlwapi.h"
#include <windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAtlasDoc

IMPLEMENT_DYNCREATE(CAtlasDoc, CDocument)

BEGIN_MESSAGE_MAP(CAtlasDoc, CDocument)
	//{{AFX_MSG_MAP(CAtlasDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_MENU_ADDATTRIBUTE, OnMenuAddattribute)
	ON_COMMAND(ID_MENU_ADDLAYER, OnMenuAddlayer)
	ON_COMMAND(ID_FILE_SAVEBMP, OnFileSavebmp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAtlasDoc construction/destruction

CAtlasDoc::CAtlasDoc()
{
	// TODO: add one-time construction code here
	m_InputFilePath.Empty();
	pLayer=NULL;
	pMap=NULL;
	LayerNum=0;
}

CAtlasDoc::~CAtlasDoc()
{
	m_InputFilePath.Empty();
	delete pMap;
	delete pLayer;
}

BOOL CAtlasDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
    SetTitle("�人��ѧ");
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAtlasDoc serialization

void CAtlasDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAtlasDoc diagnostics

#ifdef _DEBUG
void CAtlasDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAtlasDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAtlasDoc commands
//////////////////���ݸ�ʽת��//////////////////////////////////////////////////////////////////////////
BOOL CAtlasDoc::DataTransform(CString ImportPath,CString ExportPath,CRect &MapExtent)
{
	FILE *fp_ImportFile=fopen(ImportPath,"r");

	if (!fp_ImportFile) 
	{
		MessageBox(NULL,"�޷����ļ�",NULL,MB_OK);
		return FALSE;
	}
	//��ImportPath��ȡ��ͼ���ִ����map_name������
	CString map_name = ImportPath;
	map_name.MakeReverse();
	map_name.Delete(0,4);
	map_name = map_name.Left(map_name.Find("\\"));
	map_name.MakeReverse();

	CString FolderName=ExportPath+"\\"+map_name;//ȷ��ת���󵼳��ļ���ŵ��ļ���·�����ļ�����map_name����

	if(!PathIsDirectory(FolderName))
	{   
		CString   strMsg;   
		strMsg.Format("ָ��·��\"%s\"�����ڣ��Ƿ񴴽�?",FolderName);   
		if(AfxMessageBox(strMsg,MB_YESNO)==IDYES)   
		{   
			if(!CreateDirectory(FolderName,NULL))   
			{   
					return FALSE;   
            }   
		}   
	}  

	float xMin,yMin,xMax,yMax;
	char a[400],b[400];
	CString strEx;
	CString str;
	int VertexNum;//�ڵ���
	double x,y;//�ڵ�������ʱ��ű���
	double TextHeight;//�ı��ָ�
	int LayerNum=0;//ͼ����
	CString style;//Ŀ��ʵ�������point��line��polyline��spline
	CString FilePath;//�����ļ���·����ű���
	FILE *fp_layer=NULL;
	CString bb;//����b���ַ�����
	while (!feof(fp_ImportFile) && !ferror(fp_ImportFile))
	{
		fscanf(fp_ImportFile,"%s\n",a);
		fscanf(fp_ImportFile,"%s\n",b);
		strEx=CString(a)+CString(b);
// 		fgets(b,400,fp_ImportFile);
// 		bb=CString(b);
// 		bb.TrimRight();
// 		strEx=CString(a)+bb;

		if(strEx=="9$EXTMIN")
		{
			fgets(a,100,fp_ImportFile);
			fscanf(fp_ImportFile, "%f\n",&xMin);
			fgets(a,100,fp_ImportFile);
			fscanf(fp_ImportFile, "%f\n",&yMin);
		}
		if(strEx=="9$EXTMAX")
		{
			fgets(a,100,fp_ImportFile);
			fscanf(fp_ImportFile, "%f\n", &xMax);
			fgets(a,100,fp_ImportFile);
			fscanf(fp_ImportFile, "%f\n", &yMax);
			MapExtent.left= (LONG)(xMin * 1e6);
			MapExtent.top= (LONG)(yMin * 1e6);
			MapExtent.right= (LONG)(xMax * 1e6);
			MapExtent.bottom= (LONG)(yMax * 1e6);
			//���õ�ͼԭʼ��Χ
		}

		if(strEx=="2LAYER")
		{
			do 
 			{
				fscanf(fp_ImportFile,"%s\n",a);
 				fscanf(fp_ImportFile,"%s\n",b);
 			}while(strcmp(a,"70")!=0);

			LayerNum=atoi(b);

			do 
			{
				fscanf(fp_ImportFile,"%s\n",a);
				fscanf(fp_ImportFile,"%s\n",b);
				str = CString(a) + CString(b);
			} while(str!="0LAYER");

			for(int i=0;i<LayerNum;i++)
			{	
				do 
				{
					fscanf(fp_ImportFile,"%s\n",a);
					fgets(b,400,fp_ImportFile);//����ͼ����������п��ܺ��пո�������fgets������������fscanf����������
					str = CString(a) + CString(b);
					str.TrimRight();//ɾȥ�ַ����пո�
					bb=CString(b);
					bb.TrimRight();
					if ((strcmp(a,"2")==0)&&(bb!="0"))
					{
						CString temp(b);
						temp.TrimRight();
						//temp.TrimLeft();
					FilePath=FolderName+"\\"+temp+".cw";
					fp_layer=fopen(FilePath,"a");//����ͼ����������Ӧ��cw�����ļ�
//////////////////////////////д�ļ�ͷ����//////////////////////////////////
					fprintf(fp_layer,"%s\n","----------ATLAS CW FILE HEADER----------");
					fprintf(fp_layer,"%s%s\n","Map:",map_name);
					fprintf(fp_layer,"%s%d\n","Xmin:",MapExtent.left);
					fprintf(fp_layer,"%s%d\n","Ymin:",MapExtent.top);
					fprintf(fp_layer,"%s%d\n","Xmax:",MapExtent.right);
					fprintf(fp_layer,"%s%d\n","Ymax:",MapExtent.bottom);
					fprintf(fp_layer,"%s%s\n","Layer:",temp);
					fprintf(fp_layer,"%s%d\n","Key:",i);
					fprintf(fp_layer,"%s%d\n","Sum:",LayerNum-1);
					fprintf(fp_layer,"%s%d\n","Visible:",1);
					fprintf(fp_layer,"%s%d\n","Selectable:",1);
					fprintf(fp_layer,"%s%d\n","Editable:",1);
					fprintf(fp_layer,"%s\n","                                        ");
					fprintf(fp_layer,"%s\n","------------CW FILE ENTITIES------------");
//////////////////////////////�ļ�ͷд��////////////////////////////////////
					fclose(fp_layer);
					}
				}while(str!="0LAYER"&&str!="0ENDTAB");	//����ѭ����̵���©���������str!="0ENDTAB"�Դ˶�ȡ���ͼ�����Ϣ		
			}
		}

		if(strEx=="2ENTITIES")
		{
			while (str!="0ENDSEC")
			{
				do 
				{
					fscanf(fp_ImportFile,"%s\n",a);
					fgets(b,260,fp_ImportFile);
					bb=CString(b);
					bb.TrimRight();
					str=CString(a)+bb;
				} while (str!="0LINE"&&str!="0POLYLINE"&&str!="0POINT"&&
							str!="0SPLINE"&&str!="0TEXT"&&str!="0ENDSEC");
				//int object_num=0;			
				if (str=="0SPLINE")
				{
					do 
					{
						fscanf(fp_ImportFile,"%s\n",a);
						fgets(b,260,fp_ImportFile);
					} while (strcmp(a,"8")!=0);
					bb=CString(b);
					bb.TrimRight();
					if (bb!="")
					{
						FilePath=FolderName+"\\"+bb+".cw";
					}

					do 
					{
						fscanf(fp_ImportFile,"%s\n",a);
						fscanf(fp_ImportFile,"%s\n",b);
					} while (strcmp(a,"70")!=0);
					if (strcmp(b,"1")==0)
					{
						style="Polygon";
					}
					else
					{
						style="Polyline";
					}

					do 
					{
						fscanf(fp_ImportFile,"%s\n",a);
						fscanf(fp_ImportFile,"%s\n",b);
					} while (strcmp(a,"72")!=0);
					VertexNum=atoi(b);

					fp_layer=fopen(FilePath,"a+");

					fprintf(fp_layer,"%s\n","Entity Start");
					fprintf(fp_layer,"%s%s\n","Name:","0");
					fprintf(fp_layer,"%s%s\n","Shape:",str);
					fprintf(fp_layer,"%s%s\n","Style:",style);
					fprintf(fp_layer,"%s%d\n","Num:",VertexNum);
					fprintf(fp_layer,"%s\n","Vertex:");

					do 
					{
						fscanf(fp_ImportFile,"%s\n",a);
						fscanf(fp_ImportFile,"%s\n",b);
					} while (strcmp(a,"10")!=0);
					x=atof(b)*1e6;
					fscanf(fp_ImportFile,"%s\n",a);
					fscanf(fp_ImportFile,"%s\n",b);

					y=atof(b)*1e6;
					fprintf(fp_layer,"%f,%f\n",x,y);

					fscanf(fp_ImportFile,"%s\n",a);
					fscanf(fp_ImportFile,"%s\n",b);

					for (int i=0;i<VertexNum-5;i++)//-5��ԭ��ܸ��ӣ�ͬ������Ϊѭ�����Ʋ�����ԭ����Ҫ-5����ȡ������ĵ������ֵ
					{
						fscanf(fp_ImportFile,"%s\n",a);
						fscanf(fp_ImportFile,"%s\n",b);
						x=atof(b)*1e6;

						fscanf(fp_ImportFile,"%s\n",a);
						fscanf(fp_ImportFile,"%s\n",b);
						y=atof(b)*1e6;

						fscanf(fp_ImportFile,"%s\n",a);
						fscanf(fp_ImportFile,"%s\n",b);

						fprintf(fp_layer,"%f,%f\n",x,y);
					}
					fprintf(fp_layer,"%s\n","Entity End");
					fprintf(fp_layer,"%s\n"," ");
					str=CString(a)+CString(b);
					fclose(fp_layer);
				}

				if (str=="0LINE")
				{
				}

				if (str=="0POLYLINE")
				{
				}

				if (str=="0POINT")
				{
				}

				if (str=="0TEXT")
				{
					do 
					{
						fscanf(fp_ImportFile,"%s\n",a);
						fgets(b,260,fp_ImportFile);
					} while (strcmp(a,"8")!=0);
					bb=CString(b);
					bb.TrimRight();
					if (bb!="")
					{
						FilePath=FolderName+"\\"+bb+".cw";
					}

					fp_layer=fopen(FilePath,"a+");

					fprintf(fp_layer,"%s\n","Entity Start");
					fprintf(fp_layer,"%s\n","Name:0");
					fprintf(fp_layer,"%s%s\n","Shape:",str);
					fprintf(fp_layer,"%s\n","Vertex:");

					do 
					{
						fscanf(fp_ImportFile,"%s\n",a);
						fscanf(fp_ImportFile,"%s\n",b);
					} while (strcmp(a,"10")!=0);
					x=atof(b)*1e6;
					fscanf(fp_ImportFile,"%s\n",a);
					fscanf(fp_ImportFile,"%s\n",b);
					
					y=atof(b)*1e6;
					fprintf(fp_layer,"%f,%f\n",x,y);
					
					fscanf(fp_ImportFile,"%s\n",a);
					fscanf(fp_ImportFile,"%s\n",b);

					fscanf(fp_ImportFile,"%s\n",a);
					fscanf(fp_ImportFile,"%s\n",b);
					TextHeight=atof(b);

					fprintf(fp_layer,"%s%f\n","FontHeight:",TextHeight);

					fscanf(fp_ImportFile,"%s\n",a);
					fscanf(fp_ImportFile,"%s\n",b);
					fprintf(fp_layer,"%s%s\n","Text:",b);

					fscanf(fp_ImportFile,"%s\n",a);
					fscanf(fp_ImportFile,"%s\n",b);

					fscanf(fp_ImportFile,"%s\n",a);
					fscanf(fp_ImportFile,"%s\n",b);

					fprintf(fp_layer,"%s%s\n","FontName:",b);
					
					fprintf(fp_layer,"%s\n","Entity End");
					fprintf(fp_layer,"%s\n"," ");
					str=CString(a)+CString(b);
					fclose(fp_layer);
				}
			}			
		}
	}
	return TRUE;
}

void CAtlasDoc::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog dlg(TRUE,"*.cw",NULL,OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT|OFN_OVERWRITEPROMPT,
		"CW�ļ�(*.cw)|*.cw|AutoCAD�ļ�(*.dxf)|*.dxf|�����ļ�(*.*)|*.*||",NULL);

	dlg.m_ofn.lpstrTitle="��������ͼ��";
	//�����Դ�100���ļ�
	dlg.m_ofn.nMaxFile = 100 * MAX_PATH; 
	dlg.m_ofn.lpstrFile = new TCHAR[dlg.m_ofn.nMaxFile]; 
	ZeroMemory(dlg.m_ofn.lpstrFile, sizeof(TCHAR) * dlg.m_ofn.nMaxFile); 
	
	CRect MapExtent(0,0,0,0);
	if (dlg.DoModal()==IDOK)
	{
		pMap=new CGeoMap;
		m_InputFilePath=dlg.GetPathName();
		//��ʾ�ļ��Ի��򣬻���ļ�������
		POSITION pos_file;
		pos_file = dlg.GetStartPosition();
		CArray<CString, CString> ary_filename;
		while(pos_file != NULL)
			ary_filename.Add(dlg.GetNextPathName(pos_file));
		for(int i=0; i<ary_filename.GetSize(); i++)
		{
			CString str_ext;
			str_ext = ary_filename.GetAt(i).Right(3);

			if((str_ext == "DXF")||(str_ext == "dxf"))
			{
				FILE *fp;
				fp=fopen(ary_filename.GetAt(i),"r");
				OpenDXF(fp,MapExtent);
			}
			else if((str_ext == ".CW")||(str_ext == ".cw"))
			{
				OpenCW(ary_filename.GetAt(i),MapExtent);
			}
		}
		CAtlasView * pView = (CAtlasView *)(((CMainFrame *)AfxGetMainWnd())->GetActiveView());
		pView->m_rCurWinScope = pView->m_rtMapRange = MapExtent;
		pView->m_bIsLoadMap = TRUE;	

		pView->Invalidate();		
	}
}

BOOL CAtlasDoc::OpenCW(CString Path,CRect &MapExtent)//��ȡcw�ļ�������ʾ
{
	CString Buffer;
	CStdioFile *fp_OpenCW=new CStdioFile();
	BOOL IsSuc=fp_OpenCW->Open(Path,CFile::modeRead|CFile::shareDenyWrite|CFile::typeText);
	if (IsSuc)
	{
		fp_OpenCW->ReadString(Buffer);
		Buffer.TrimLeft();
		Buffer.TrimRight("\n");
		Buffer.TrimRight();

		if(Buffer == "----------ATLAS CW FILE HEADER----------")
		{			
			pLayer=new CGeoLayer;
		}
		pMap->SetLayer(pLayer);
		pMap->SetLayerNum(++LayerNum);

		fp_OpenCW->ReadString(Buffer);//��ȡ��ͼ��
		Buffer.TrimLeft("Map:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		pMap->SetMapName(Buffer);//��ȡ��ͼ��

		fp_OpenCW->ReadString(Buffer);//��ȡ��ͼ�߽�	
		Buffer.TrimLeft("Xmin:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		MapExtent.left=(long)atof(Buffer);
		fp_OpenCW->ReadString(Buffer);//��ȡ��ͼ�߽�	
		Buffer.TrimLeft("Ymin:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		MapExtent.top=(long)atof(Buffer);
		fp_OpenCW->ReadString(Buffer);//��ȡ��ͼ�߽�	
		Buffer.TrimLeft("Xmax:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		MapExtent.right=(long)atof(Buffer);
		fp_OpenCW->ReadString(Buffer);//��ȡ��ͼ�߽�	
		Buffer.TrimLeft("Ymax:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		MapExtent.bottom=(long)atof(Buffer);
		pMap->SetMapBoundary(MapExtent);

		fp_OpenCW->ReadString(Buffer);//��ȡ��ͼͼ����		
		Buffer.TrimLeft("Layer:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		pLayer->SetLayerName(Buffer);

		fp_OpenCW->ReadString(Buffer);//��ȡͼ���ʶ��
		Buffer.TrimLeft("Key:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		pLayer->SetLayerKeyNO(atoi(Buffer));

		fp_OpenCW->ReadString(Buffer);//��ȡͼ�������������CGeoMap��
		Buffer.TrimLeft("Sum:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		//pMap->SetLayerNum(atoi(Buffer));

		fp_OpenCW->ReadString(Buffer);//��ȡͼ�������
		Buffer.TrimLeft("Visible:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		pLayer->LayerVisible(atoi(Buffer));

		fp_OpenCW->ReadString(Buffer);//��ȡͼ���ѡ��
		Buffer.TrimLeft("Selectable:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		pLayer->LayerSelectable(atoi(Buffer));

		fp_OpenCW->ReadString(Buffer);//��ȡͼ��ɱ༭��
		Buffer.TrimLeft("Editable:");
		Buffer.TrimRight("\n");
		Buffer.TrimRight();
		pLayer->LayerEditable(atoi(Buffer));

		do 
		{
			fp_OpenCW->ReadString(Buffer);//��ȡͼ���е�����Ŀ��Ŀռ���������
		} while (Buffer!="------------CW FILE ENTITIES------------");

		while (!feof(fp_OpenCW->m_pStream))
		{
			fp_OpenCW->ReadString(Buffer);
			Buffer.TrimLeft();
			Buffer.TrimRight("\n");
			Buffer.TrimRight();
			if (Buffer=="Entity Start")
			{
				//CGeoObject *Object=NULL;

				fp_OpenCW->ReadString(Buffer);
				Buffer.TrimLeft("Name:");
				Buffer.TrimRight("\n");
				Buffer.TrimRight();
				CString ObjectName=Buffer;

				fp_OpenCW->ReadString(Buffer);
				Buffer.TrimLeft("Shape:");
				Buffer.TrimRight("\n");
				Buffer.TrimRight();

				if (Buffer=="0TEXT")
				{
					/*CPoint AnnoVertex;*/
					CGeoAnno *Annotation=new CGeoAnno;
					//Object=Annotation;
					pLayer->SetGeoObject(Annotation);

					fp_OpenCW->ReadString(Buffer);//��Vertex��

					fp_OpenCW->ReadString(Buffer);//������
					int pos1 = Buffer.Find(",");
					Annotation->m_AnnoVertex.x = (LONG)atof(Buffer.Mid(0,pos1));
					int pos2=Buffer.Find("\n");
					Annotation->m_AnnoVertex.y=(LONG)atof(Buffer.Mid(pos1+1,Buffer.GetLength()-pos1-1));//�����������
					Annotation->SetPoint(Annotation->m_AnnoVertex);

					fp_OpenCW->ReadString(Buffer);
					Buffer.TrimLeft("FontHeight:");
					Buffer.TrimRight("\n");
					Buffer.TrimRight();
					Annotation->m_FontHeight=(float)atof(Buffer);

					fp_OpenCW->ReadString(Buffer);
					Buffer.TrimLeft("Text:");
					Buffer.TrimRight("\n");
					Buffer.TrimRight();
					Annotation->m_AnnoText=Buffer;

					fp_OpenCW->ReadString(Buffer);
					Buffer.TrimLeft("FontName:");
					Buffer.TrimRight("\n");
					Buffer.TrimRight();
					Annotation->m_FontType=Buffer;

					fp_OpenCW->ReadString(Buffer);//��Entity End
					fp_OpenCW->ReadString(Buffer);//���ո���
				}
				else if (Buffer=="0SPLINE")
				{
					fp_OpenCW->ReadString(Buffer);
					Buffer.TrimLeft("Style:");
					Buffer.TrimRight("\n");
					Buffer.TrimRight();
				
					if (Buffer=="Polygon")
					{
						CGeoPolygon *Polygon=new CGeoPolygon();
						//Object=Polygon;
						pLayer->SetGeoObject(Polygon);

						fp_OpenCW->ReadString(Buffer);
						Buffer.TrimLeft("Num:");
						Buffer.TrimRight("\n");
						Buffer.TrimRight();
						int VertextNumber=atoi(Buffer);

						fp_OpenCW->ReadString(Buffer);//��Vertex:

						for (int i=0;i<VertextNumber-4;i++)
						{
							CPoint Vertex;
							fp_OpenCW->ReadString(Buffer);
							int pos1 = Buffer.Find(",");
							Vertex.x = (LONG)atof(Buffer.Mid(0,pos1));
							//int pos2=Buffer.Find("\n");
							Vertex.y=(LONG)atof(Buffer.Mid(pos1+1,Buffer.GetLength()-pos1-1));//�����������
							Polygon->SetPoint(Vertex);
						}

						fp_OpenCW->ReadString(Buffer);//��Entity End
						fp_OpenCW->ReadString(Buffer);//���ո���
					}
					else if (Buffer=="Polyline")
					{
						CGeoLine *PolyLine=new CGeoLine();
						//Object=PolyLine;
						pLayer->SetGeoObject(PolyLine);

						fp_OpenCW->ReadString(Buffer);
						Buffer.TrimLeft("Num:");
						Buffer.TrimRight("\n");
						Buffer.TrimRight();
						int VertextNumber=atoi(Buffer);

						fp_OpenCW->ReadString(Buffer);//��Vertex:

						for (int i=0;i<VertextNumber-4;i++)
						{
							CPoint Vertex;
							fp_OpenCW->ReadString(Buffer);
							int pos1 = Buffer.Find(",");
							Vertex.x = (LONG)atof(Buffer.Mid(0,pos1));
							//int pos2=Buffer.Find("\n");
							Vertex.y=(LONG)atof(Buffer.Mid(pos1+1,Buffer.GetLength()-pos1-1));//�����������
							PolyLine->SetPoint(Vertex);
						}
						
						fp_OpenCW->ReadString(Buffer);//��Entity End
						fp_OpenCW->ReadString(Buffer);//���ո���
					}
				}
				
			}
		}
	}	
	fp_OpenCW->Close();
	fp_OpenCW = NULL;
	return TRUE;
}

extern void RemoveChar(CString str,char ch);

BOOL CAtlasDoc::OpenDXF(FILE *Path,CRect &MapExtent)//��ȡdxf�ļ�������ʾ
{
	int c;//read
	char a[100],b[100];//read
	CString str;//compare
	CString s,t;//show

	float xMin,yMin,xMax,yMax;
	int LayerNum;
	while(!feof(Path)&&!ferror(Path))
		{
			fscanf(Path,"%s\n",a);
			fscanf(Path,"%s\n",b);
			str=CString(a)+CString(b);

			if(str=="9$EXTMIN")
			{
				fgets(a,100,Path);
				fscanf(Path,"%f\n",&xMin);
				fgets(a,100,Path);
				fscanf(Path,"%f\n",&yMin);			
			}
			if(str=="9$EXTMAX")
			{
				fgets(a,100,Path);
				fscanf(Path,"%f\n",&xMax);
				fgets(a,100,Path);
				fscanf(Path,"%f\n",&yMax);
				MapExtent.left= (LONG)(xMin * 1e6);
				MapExtent.top= (LONG)(yMin * 1e6);
				MapExtent.right= (LONG)(xMax * 1e6);
				MapExtent.bottom= (LONG)(yMax * 1e6);
				
				//���õ�ͼԭʼ��Χ
				pMap->SetMapBoundary(MapExtent);
			}

	
			//ȥ������
			if(str=="2LTYPE")
			{
				while(strcmp(a,"ENDTAB")!=0)
				{
					fscanf(Path,"%s\n",a);
				}
			}
			
			if(str=="2LAYER")
			{
				fgets(a,100,Path);
				fscanf(Path,"%d\n",&LayerNum);
				
				//��������Ϣ��m_strName,m_bIsVisible
				for(int i=0;i<LayerNum;i++)
				{
					CGeoLayer *layer=new CGeoLayer;
					
					fgets(a,100,Path);
					fgets(a,100,Path);
					
					fgets(a,100,Path);
					fscanf(Path,"%s\n",b);
					CString str=b;
					RemoveChar(str,'?');
					layer->m_LayerName=str;
					
					fgets(a,100,Path);
					fgets(a,100,Path);
					
					fgets(a,100,Path);
					fscanf(Path,"%d\n",&c);

// 					if(c<0)
// 						layer->m_LayerVisible=FALSE;
					
					fgets(a,100,Path);
					fscanf(Path,"%s\n",b);
					
					pMap->SetLayer(layer);
				
				}//END OF FOR
					
									
			}//END OF if(str=="2LAYER")
			
			
	
			
			if(str=="2ENTITIES")
			{
				do
				{
					fscanf(Path,"%s\n",a);
					fscanf(Path,"%s\n",b);
					str=CString(a)+CString(b);
					
					CGeoObject *obj=NULL;//ָ��Ŀ���ָ��
/*					int num;//��¼Ŀ������ͼ���*/

					if(str=="0POLYLINE")//������Ŀ���ȡ
					{
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%s\n",b);					
						//pLayer->SetLayerName(CString(b));
									
						CArray<CPoint*,CPoint*> pts;
						BOOL IsPolygon=false;
						while(str!="0SEQEND")//��ȡ������
						{
							fscanf(Path,"%s\n",a);
							fscanf(Path,"%s\n",b);
							str=CString(a)+CString(b);
							
							if(str=="701")
								IsPolygon=true;
							if(str=="0VERTEX")
							{
								float x,y;
								
								fscanf(Path,"%s\n",a);
								fscanf(Path,"%s\n",b);
								
								fscanf(Path,"%s\n",a);
								fscanf(Path,"%s\n",b);
								
								fscanf(Path,"%s\n",a);
								fscanf(Path,"%s\n",b);
								
								fscanf(Path,"%s\n",a);
								fscanf(Path,"%f\n",&x);
								
								fscanf(Path,"%s\n",a);
								fscanf(Path,"%f\n",&y);
								
								CPoint *pt=new CPoint(int(x*1e6),int(y*1e6));
								pts.Add(pt);							
							}						
						}//END OF WHILE

						int ptsNum=pts.GetSize();

						//��
						if( ptsNum == 2 )
						{
							CGeoPoint *point=new CGeoPoint;
							point->SetPoint(*pts[0]);
							obj=point;
							if(NULL!=pts[1])
							{
								delete pts[1];
								pts[1]=NULL;
							}
						}
											
						else
						{
							//��
							if( IsPolygon || *pts[0]==*pts[ptsNum-1] )//��DXF��701��־����ĩ�غϣ���Ϊ��
							{
								CGeoPolygon *polygon=new CGeoPolygon;
								for(int i=0; i<ptsNum; i++)
								polygon->SetPoint(*pts[i]);
								obj=polygon;
							}
							//��
							else
							{
								CGeoLine *polyline=new CGeoLine;
								for(int i=0; i<ptsNum;i++)
								polyline->SetPoint(*pts[i]);
								obj=polyline;
							}	
						}
						
					
						
					}//END OF if(str=="0POLYLINE")


					if(str=="0TEXT")
					{
						float d;

						fscanf(Path,"%s\n",a);
						fscanf(Path,"%s\n",b);
						
						//pLayer->SetLayerName(CString(b));
						CGeoAnno *anno=new CGeoAnno;
						obj=anno;
						
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%d\n",&c);
						anno->m_AnnoColor=c;
						
						CPoint pt;
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%f\n",&d);
						pt.x=(LONG)(d*1e6);
						
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%f\n",&d);
						pt.y=(LONG)(d*1e6);
						anno->SetPoint(pt);
						
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%f\n",d);
						anno->m_FontHeight=d;
						
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%s\n",b);
						anno->m_AnnoText=b;
						
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%f\n",&d);
						
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%s\n",b);
						anno->m_FontType=b;
						
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%s\n",b);
						
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%s\n",b);
						
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%f\n",&d);
						
						fscanf(Path,"%s\n",a);
						fscanf(Path,"%f\n",&d);

					}
				} while(str!="0ENDSEC");

			}//END OF if(str=="2ENTITIES")
			
			
		}//END OF while(!feof(fp)&&!ferror(fp))
	return TRUE;
}

void CAtlasDoc::OnFileSave() //�����ͼ�����޸ĺ������д����Ӧ���ļ���ȥ
{
	// TODO: Add your command handler code here
	
}

void CAtlasDoc::OnMenuAddattribute() //��������ļ�
{
	// TODO: Add your command handler code here
	
}

void CAtlasDoc::OnMenuAddlayer() //���ͼ�㣬�����cw�ļ�
{
	// TODO: Add your command handler code here
	
}

void CAtlasDoc::OnFileSavebmp() 
{
	// TODO: Add your command handler code here
	CFileDialog dlg(false,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"λͼ�ļ�(*.bmp)|*.bmp|",
		NULL);
		int structsize=0;
	DWORD dwVersion,dwWindowMajorVersion,dwWindowMinoVersion;
	dwVersion=GetVersion();
	dwWindowMajorVersion=(DWORD)(LOBYTE((WORD)(dwVersion)));
	dwWindowMinoVersion=(DWORD)(HIBYTE((WORD)(dwVersion)));
	if(dwVersion<0x80000000)
		structsize=88;
	else
		structsize=76;
	dlg.m_ofn.lStructSize=structsize;
	dlg.m_ofn.lpstrInitialDir="data\\";

	dlg.m_ofn.lpstrTitle="����ΪBMPͼƬ";
	if (dlg.DoModal()!= IDOK) return;
	CString filename = dlg.GetFileName()+".bmp";

	//����ͼ�δ�С
	CAtlasView * pView = (CAtlasView *)(((CMainFrame*)AfxGetMainWnd())->GetActiveView());
	CRect rect;
	pView->GetClientRect(&rect);
	int iWidth = rect.Width();
	int iHeight = rect.Height();
    int iPixel  = 32;
	//ͼ�θ�ʽ����
    LPBITMAPINFO lpbmih = new BITMAPINFO;
    lpbmih->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    lpbmih->bmiHeader.biWidth = iWidth;
    lpbmih->bmiHeader.biHeight = iHeight;
    lpbmih->bmiHeader.biPlanes = 1;
    lpbmih->bmiHeader.biBitCount = iPixel;
    lpbmih->bmiHeader.biCompression = BI_RGB;
    lpbmih->bmiHeader.biSizeImage = 0;
    lpbmih->bmiHeader.biXPelsPerMeter = 0;
    lpbmih->bmiHeader.biYPelsPerMeter = 0;
    lpbmih->bmiHeader.biClrUsed = 0;
    lpbmih->bmiHeader.biClrImportant = 0;


//	char * pColor = ((LPSTR)lpbmih + (WORD)(lpbmih->bmiHeader.biSize)); 

    //����λͼ����
    HDC hdc,hdcMem;
    HBITMAP hBitMap = NULL;
    CBitmap *pBitMap = NULL;
    CDC *pMemDC = NULL;
    BYTE *pBits;

    hdc = CreateIC(TEXT("DISPLAY"),NULL,NULL,NULL);
    hdcMem = CreateCompatibleDC(hdc);
	hBitMap = CreateDIBSection(hdcMem,lpbmih,DIB_PAL_COLORS,(void **)&pBits,NULL,0);
 //   hBitMap = CreateDIBSection(hdcMem,lpbmih,DIB_RGB_COLORS,(void **)&pBits,NULL,0);
    
	pBitMap = new CBitmap;
    pBitMap->Attach(hBitMap);
    pMemDC = new CDC;
    pMemDC->Attach(hdcMem);
    pMemDC->SelectObject(pBitMap);
   
	pMemDC->SetBkMode(TRANSPARENT);


    //����Ի�ͼ�� 

	pView->OnPrepareDC(pMemDC);
	pMap->Draw(pMemDC);


    //���浽�ļ�������λͼ�ṹ
    BITMAPFILEHEADER bmfh;
    ZeroMemory(&bmfh,sizeof(BITMAPFILEHEADER));
    *((char *)&bmfh.bfType) = 'B';
    *(((char *)&bmfh.bfType) + 1) = 'M';
    bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmfh.bfSize = bmfh.bfOffBits + (iWidth * iHeight) * iPixel / 8;

    TCHAR szBMPFileName[128];
    int iBMPBytes = iWidth * iHeight * iPixel / 8;
    strcpy(szBMPFileName,filename);
    CFile file;
    if(file.Open(szBMPFileName,CFile::modeWrite | CFile::modeCreate))
    {
        file.Write(&bmfh,sizeof(BITMAPFILEHEADER));
        file.Write(&(lpbmih->bmiHeader),sizeof(BITMAPINFOHEADER));

        file.Write(pBits,iBMPBytes);
        file.Close();
    }

	

    pMemDC->DeleteDC();
    delete pMemDC;	pMemDC  = NULL;
    delete pBitMap; pBitMap = NULL;
    delete lpbmih;  lpbmih  = NULL;
	
}
