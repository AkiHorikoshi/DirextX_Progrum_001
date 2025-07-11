#include <sdkddkver.h>
#define WIN32_LEANAND_MEAN
#include <Windows.h>
#include "game_window.h"
#include "direct3d.h"
#include "polygon.h"
#include "shader.h"


/*
���C��
*/
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int nCmdShow)
{
	HWND hWnd = GameWindow_Create(hInstance);


	Direct3D_Initialize(hWnd);
	Shader_Initialize(Direct3D_GetDevice(), Direct3D_GetContext());
	Polygon_Initialize(Direct3D_GetDevice(), Direct3D_GetContext());

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);


		Direct3D_Clear();

		Polygon_Draw();
		//Polygon_Draw2();

		Direct3D_Present();
	}

	Polygon_Finalize();
	Shader_Finalize();
	Direct3D_Finalize();


	return (int)msg.wParam;
}