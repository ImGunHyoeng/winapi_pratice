// Client.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Client.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance/*실행 된 프로세스의 시작주소*/
                    ,_In_opt_ HINSTANCE hPrevInstance/*실행되기 전 프로세스의 시작주소*/
                    ,_In_ LPWSTR    lpCmdLine//추가 명령어를 실행하기 위해서 받아오는 문자열
                    ,_In_ int       nCmdShow)
 //동일한 프로그램을 여러개 실행시킨다면
 //윈도우가 가상메모리를 사용하기에 동일한 메모리 주소를 가진다
//실질적인 주소를 봤을때 본다면 주소가 다르지만
//가상으로 봤을때 다르다
//win의 운영체제 상에서 여러객체의 가상적인 주소에선 같지만 물리적인 주소는 다를수 있다
//이런이유로 현 시스템 상에서는 hPrev가 의미가 없어졌다.
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING);
    //테이블에 있는값을 가져와라
    
    //윈도우 정보 등록
    MyRegisterClass(hInstance);

    //윈도우 생성(창) //유저와 프로그램상의 접점
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    // 단축키파트
    //특정한 단축키를 눌러서 기능을 실행할것이 아니라면 사용할 필요 없다
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));

    MSG msg;//메시지를 넣어두는 구조체
    msg.hwnd;//메시지가 발생한 윈도우를 의미함
    //하나의 프로세스에서 여러개의 창을 가져올수도 있기에 창을 알려줌

    // 기본 메시지 루프입니다:
    //GetMessage는 해당하는 곳으로 온 명령이 있는지 확인하고 처리하는것
    //메세지큐에서 메세지 확인할때까지 대기
    //msg.mesage==WM_QUIT 이라는 메세지를 받는다면 false를 반환한다.->프로그램 종료 //먼저,윈도우가종료되고 해제되어야한다
    //이것은 게임을 만드는데 부적합하다.
    while (GetMessage(&msg, nullptr, 0, 0))//입력을 받는다
    {
        
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            //위에서 받아온 메시지들을 처리해주는것이다.
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    //창이 종료되는 프로그램도 끝나도록 설계되어있는것
    //이렇게 설계가 되어있는것이지 윈도우가 끝난다고 모든 프로세스가 종료 된다고 하는것은 아님
    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CLIENT);
    //윈도우의 메뉴의 형태를 잡아주는것을 의미한다.//파일 도움말 등 
    wcex.lpszClassName  = szWindowClass;//프로젝트의 이름을 대문자로 해놓은것
    //아니면 직접 변경하고서 키값을 가져올수 있음
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
    //window상에서 제공해주는 함수를 사용해야한다.
    //윈도우상에서 원하는 함수가 있다면 해당함수를 사용해야한다.
    //먼저 함수를 찾아보고 없다면은 만드는것을 선호해야한다
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
   //제목을 직접 바꾸고 싶다면 szTitle에다가 해당하는 값을 입력하면 된다
   //등록된 키값을 토대로 찾아오는것
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   //객체를 만들고 이벤트를 처리하기 위한 함수의 포인터까지 세팅해 준것이다
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            //윈도우 핸들
            //윈도우 좌표
            //HDC?

            Rectangle(hdc,10,10,110,110);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
