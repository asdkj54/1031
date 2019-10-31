
// 1031View.cpp: CMy1031View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "1031.h"
#endif

#include "1031Doc.h"
#include "1031View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1031View

IMPLEMENT_DYNCREATE(CMy1031View, CView)

BEGIN_MESSAGE_MAP(CMy1031View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy1031View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy1031View 构造/析构

CMy1031View::CMy1031View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy1031View::~CMy1031View()
{
}

BOOL CMy1031View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy1031View 绘图

void CMy1031View::OnDraw(CDC* /*pDC*/)
{
	CMy1031Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy1031View 打印


void CMy1031View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy1031View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy1031View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy1031View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMy1031View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy1031View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy1031View 诊断

#ifdef _DEBUG
void CMy1031View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1031View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1031Doc* CMy1031View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1031Doc)));
	return (CMy1031Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1031View 消息处理程序
