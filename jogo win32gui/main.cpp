#include <windows.h>
#include <math.h>
#include <conio.h>
#include <tchar.h>
static int i;
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow){
    static TCHAR szAppName[] = TEXT ("Connect") ;
    HWND janela ;
    MSG msg ;
    WNDCLASS wndclass ;
    wndclass.style = CS_HREDRAW | CS_VREDRAW ;
    wndclass.lpfnWndProc = WndProc ;
    wndclass.cbClsExtra = 0 ;
    wndclass.cbWndExtra = 0 ;
    wndclass.hInstance = hInstance ;
    wndclass.hIcon = LoadIcon (NULL, IDI_APPLICATION) ;
    wndclass.hCursor = LoadCursor (NULL, IDC_ARROW) ;
    wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
    wndclass.lpszMenuName = NULL ;
    wndclass.lpszClassName = szAppName ;
    if (!RegisterClass (&wndclass)){
        MessageBox (NULL, TEXT ("Program requires Windows NT!"),
        szAppName, MB_ICONERROR) ;
        return 0 ;
    }
    janela = CreateWindow (szAppName, TEXT ("Desenhar Uma Estrela"),
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT,
    CW_USEDEFAULT, CW_USEDEFAULT,
    NULL, NULL, hInstance, NULL) ;
    ShowWindow (janela, iCmdShow) ;
    UpdateWindow (janela) ;
    while (GetMessage (&msg, NULL, 0, 0)){
        TranslateMessage (&msg) ;
        DispatchMessage (&msg) ;
    }
    return msg.wParam ;
}
LRESULT CALLBACK WndProc (HWND janela, UINT message, WPARAM wParam, LPARAM lParam){
    HDC tela ;
    static TCHAR frase[] = _T("Tecle ESC Para Sair !");
    PAINTSTRUCT ps ;
    int j,x,y;
    float f;
    tela = GetDC (janela) ;
    switch (message){
        case WM_COMMAND:
            return 0;
        case WM_KEYDOWN:
            if (wParam == VK_ESCAPE){
                PostQuitMessage (0) ;
                return 0 ;
            }
        return 0;
        case WM_PAINT :
            tela = BeginPaint (janela, &ps) ;
            TextOut(tela, 650, 50, frase, _tcslen(frase));
            f = i*3.141615/180;
            x = (int)(cos(f)*200+300) ;
            y = (int)(sin(f)*200+250) ;
            MoveToEx(  tela,x,y,0) ;//posição de inicio da estrela
            for(j=0;j<5;j++){
                x = (int)(cos((i+ j*72+36)*3.141615/180)*100+300) ;
                y = (int)(sin((i+ j*72+36)*3.141615/180)*100+250) ;
                LineTo(tela,x , y);//vai para essas posições
                x = (int)(cos((i+(j+1)*72)*3.141615/180)*200+300) ;
                y = (int)(sin((i+(j+1)*72)*3.141615/180)*200+250) ;
                LineTo(tela,x , y);
            }
            x = (int)(sin(i*3.141615/180)*100+700) ;
            y = (int)(cos(i*3.141615/180)*100+250) ;
            MoveToEx(  tela,x, y,NULL) ;//posição de inicio do quadrado
            for(j=1;j<5;j++){
                x = (int)(sin((i+ j*90+00)*3.141615/180)*100+700) ;
                y = (int)(cos((i+ j*90+00)*3.141615/180)*100+250) ;
                LineTo(tela,x , y);//vai para essas posições
            }
            i++;
            if(i>360)i=0;
            Sleep(50);
            InvalidateRect (janela, NULL, TRUE) ;//limpa a tela
            EndPaint (janela, &ps) ;
            return 0 ;
        case WM_DESTROY:
            PostQuitMessage (0) ;
            return 0 ;
    }
    return DefWindowProc (janela, message, wParam, lParam) ;
}
