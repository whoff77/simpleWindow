// simpleWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "simpleWindow.h"

#include <cstring>
#include <string>

#define MAX_LOADSTRING 100



// Global Variables:
MovieStore theStore;
HWND hWndMain, editCust1, editCust2, custList;
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

COLORREF bkgndcolor = 0x00FFFFFF;
COLORREF tempbkgndcolor = bkgndcolor;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	ColorSelection(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SIMPLEWINDOW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) {
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SIMPLEWINDOW));

	// Movie Store initialization
	theStore.uploadMovies("data3movies.txt");
	theStore.uploadCustomers("data3customers.txt");

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg) &&
			!IsDialogMessage(hWndMain, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance) {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SIMPLEWINDOW));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SIMPLEWINDOW);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable
   bkgndcolor=0x00FFFFFF;
   hWndMain = hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 360, 640, NULL, NULL, hInstance, NULL);

   if (!hWnd) {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void ChangeBkGnd(HWND hWnd, COLORREF bgColor) {
  bkgndcolor = bgColor;
  InvalidateRect(hWnd, NULL, TRUE);
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	HWND addCust, loadCusts; 
	LPCTSTR greeting = _T("Hello, World!");
	LPCTSTR instruction1 = _T("Left click to see what you did.");
	LPCTSTR instruction2 = _T("Right click to see the name of this program.");

	switch (message) {
	case WM_CREATE: {
		addCust = CreateWindow(_T("BUTTON"),_T("addCust"),
					   WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON,
					   70,70,95,25,hWnd,(HMENU)IDC_ADDCUST,NULL,NULL);
		loadCusts = CreateWindow(_T("BUTTON"),_T("loadCusts"),
					   WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_PUSHBUTTON,
					   175,70,95,25,hWnd,(HMENU)IDC_LOADCUSTS,NULL,NULL);
		editCust1 = CreateWindowEx(WS_EX_CLIENTEDGE,_T("EDIT"),_T(""),
						WS_CHILD|WS_VISIBLE|WS_TABSTOP|ES_AUTOHSCROLL,
						70,100,200,20,hWnd,(HMENU)IDC_EDITCUST1,NULL,NULL);
		editCust2 = CreateWindowEx(WS_EX_CLIENTEDGE,_T("EDIT"),_T(""),
						WS_CHILD|WS_VISIBLE|WS_TABSTOP|ES_AUTOHSCROLL,
						70,130,200,20,hWnd,(HMENU)IDC_EDITCUST2,NULL,NULL);
		custList = CreateWindowEx(WS_EX_CLIENTEDGE,_T("LISTBOX"),_T(""),
						WS_CHILD|WS_VISIBLE|WS_TABSTOP|ES_AUTOVSCROLL|WS_VSCROLL,
						20,160,250,400,hWnd,(HMENU)IDC_CUSTLIST,NULL,NULL);
		SendMessage(custList, LB_ADDSTRING, NULL, (LPARAM)_T("LAST NAME, FIRST NAME"));
		SendMessage(editCust1, EM_LIMITTEXT,24,0);
		SendMessage(editCust2, EM_LIMITTEXT,24,0);
		SendMessage(editCust1,WM_SETTEXT,NULL,(LPARAM)_T("first name"));
		SendMessage(editCust2,WM_SETTEXT,NULL,(LPARAM)_T("last name"));

		

		break;
	}
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId) {
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_COLORSELECTION:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_COLORSELECTBOX), hWnd, ColorSelection);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDM_MOVIESTORE:
			system("Assign3.exe");
			break;
		case IDM_COLORCHANGE:
			ChangeBkGnd(hWnd, 0x00555555);
			break;
		case IDC_ADDCUST: {

			TCHAR buff2[64] = {'\0'};
			TCHAR buff1[32] = {'\0'};
			char lastName[32] = {'\0'};
			char firstName[32] = {'\0'};

			int len2 = SendMessage(editCust2, WM_GETTEXTLENGTH, 0, 0);
			int len1 = SendMessage(editCust1, WM_GETTEXTLENGTH, 0, 0);
			SendMessage(editCust2, WM_GETTEXT, len2+1, (LPARAM)buff2);
			SendMessage(editCust1, WM_GETTEXT, len1+1, (LPARAM)buff1);

			size_t lastSize = wcstombs(NULL, buff2, 0);
			size_t firstSize = wcstombs(NULL, buff1, 0);
			wcstombs(lastName, buff2, lastSize);
			wcstombs(firstName, buff1, firstSize);
			theStore.addCustomer(lastName, firstName);

			_tcscat_s(buff2, 64, _T(", "));
			_tcscat_s(buff2, 64, buff1);
			SendMessage(custList, LB_ADDSTRING, 0, (LPARAM)buff2);
			theStore.saveAccounts();
			MessageBox(NULL, buff2, _T("Added Customer"), MB_ICONINFORMATION);
			break;
		}

		case IDC_LOADCUSTS: {
			//char *strtok_s(char *strToken,const char *strDelimit,char **context);
			const char custArray[] = "lastTest1;firstTest1;idnumTest1;lastTest2;firstTest2;idnumTest2\0";
			SendMessage(custList, LB_RESETCONTENT, 0, 0);
			stringstream custStream;
			theStore.getCustList(custStream);
			string combined = custStream.str();
			const char *charArray = combined.c_str();
			int charArraySize = MultiByteToWideChar(CP_ACP,0,charArray,-1,NULL,0);
			TCHAR *tcharArray = new TCHAR[charArraySize];
			MultiByteToWideChar(CP_ACP,0,charArray,-1,tcharArray,charArraySize);
			//theStore.getCustList(custStringPtr);
			TCHAR *delim = _T(";");
			TCHAR *context;
			TCHAR *token = _tcstok_s(tcharArray, delim, &context);
			TCHAR customer[64];
			while (token != NULL) {
				customer[0] = '\0';
				_tcscat_s(customer, 64, token);
				_tcscat_s(customer, 64, _T(", "));
				token = _tcstok_s(NULL, delim, &context);
				_tcscat_s(customer, 64, token);
				_tcscat_s(customer, 64, _T("     "));
				token = _tcstok_s(NULL, delim, &context);
				_tcscat_s(customer, 64, token);
				SendMessage(custList, LB_ADDSTRING, 0, (LPARAM)customer);
				token = _tcstok_s(NULL, delim, &context);	
			}
			delete token; token = NULL;
			//delete charArray; charArray = NULL;
			delete tcharArray; tcharArray = NULL;
			MessageBox(NULL, _T("Loaded Customers"), _T("Loaded Customers"), MB_ICONINFORMATION);
			break;
			}

		default: return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		SetBkColor(hdc, bkgndcolor);
		TextOut(hdc, 5, 5, greeting, _tcslen(greeting));
		TextOut(hdc, 5, 25, instruction1, _tcslen(instruction1));
		TextOut(hdc, 5, 45, instruction2, _tcslen(instruction2));
		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hWnd, _T("THE LEFT MOUSE BUTTON"), _T("You have clicked:"), MB_OK | MB_ICONINFORMATION);
        break;
	case WM_RBUTTONDOWN: {
		TCHAR szFileName[MAX_PATH] = { '\0' };
		HINSTANCE hInstance = GetModuleHandle(NULL);
		GetModuleFileName(hInstance, szFileName, MAX_PATH);
		MessageBox(hWnd, szFileName, _T("This program is:"), MB_OK | MB_ICONINFORMATION);
		}
        break;
	case WM_ERASEBKGND:
		//HPEN pen;
		HBRUSH brush;
		RECT rect;
	  	
		//pen=CreatePen(PS_SOLID, 1, bkgndcolor);
		brush=CreateSolidBrush(bkgndcolor);
		//SelectObject((HDC)wParam, pen);
		SelectObject((HDC)wParam, brush);
	  
		GetClientRect(hWnd, &rect);
		Rectangle((HDC)wParam, rect.left, rect.top, rect.right, rect.bottom);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (message) {
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

// Message handler for color selection box.
INT_PTR CALLBACK ColorSelection(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);

	switch (message) {
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:

		switch (LOWORD(wParam)) {
		case IDC_BLUE:
			tempbkgndcolor = 0x00FF0000;
			InvalidateRect(hDlg, NULL, TRUE);
			break;
		case IDC_GREEN:
			tempbkgndcolor = 0x0000FF00;
			InvalidateRect(hDlg, NULL, TRUE);
			break;
		case IDC_RED:
			tempbkgndcolor = 0x000000FF;
			InvalidateRect(hDlg, NULL, TRUE);
			break;

		case IDOK:
			bkgndcolor = tempbkgndcolor;
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	case WM_CTLCOLORDLG:
        return (INT_PTR)CreateSolidBrush(tempbkgndcolor);
	case WM_CTLCOLORSTATIC:
		SetBkMode((HDC)wParam, TRANSPARENT);
		return (INT_PTR)CreateSolidBrush(tempbkgndcolor);
	default:
		return DefWindowProc(hDlg, message, wParam, lParam);
	//case WM_DESTROY:
	//	PostQuitMessage(0);
	//	break;
	}
	return (INT_PTR)FALSE;
}