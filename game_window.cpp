/*================================================

		�E�B���h�E�\��[game_window.cpp]

					Author: aki hoeikoshi
					  data: 2025.6.6

================================================*/


#include "game_window.h"
#include <algorithm>


/*
�E�B���h�E���
*/
static constexpr char WINDOW_CLASS[] = "GameWindow"; //���C���E�B���h�E�N���X��
static constexpr char TITLE[] = "Game";	 //�^�C�g���o�[�̃e�L�X�g

static const constexpr int SCREEN_WIDTH = 1120;
static const constexpr int SCREEN_HEIGHT = 630;

/*
�E�B���h�E�v���V�[�W���@�v���g�^�C�v�錾
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


HWND GameWindow_Create(HINSTANCE hInstance)
{
	/*�@�E�B���h�E�N���X�̓o�^�@*/
	WNDCLASSEX wcex{};

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	//wcex.lpszMenuName = nullptr;	//���j���[����
	wcex.lpszClassName = WINDOW_CLASS;
	wcex.hCursor = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	RegisterClassEx(&wcex);


	/* ���C���E�B���h�E�쐬 */
	RECT WindowRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	DWORD WinStyle = WS_OVERLAPPEDWINDOW ^ (WS_MAXIMIZEBOX | WS_THICKFRAME);

	AdjustWindowRect(&WindowRect, WinStyle, FALSE);

	const int WINDOW_WIDTH = WindowRect.right - WindowRect.left;
	const int WINDOW_HEIGHT = WindowRect.bottom - WindowRect.top;

	//======================================================================================
	//6.6�ǉ���
	//�f�X�N�g�b�v�̃T�C�Y�擾
	//�v���C�}�����j�^�[�̉�ʉ𑜓x�擾
	int desktop_width = GetSystemMetrics(SM_CXSCREEN);
	int desktop_height = GetSystemMetrics(SM_CYSCREEN);

	//��ʃT�C�Y�̍ő傩��\�����������̂̃T�C�Y�������ā��Q����
	//��������Ε\�����������̂𒆐S�Ɏ����Ă��邽�߂̍�����W�����܂�
	const int WINDOW_X = std::max((desktop_width - WINDOW_WIDTH) / 2, 0);
	const int WINDOW_Y = std::max((desktop_height - WINDOW_HEIGHT) / 2, 0);
	//======================================================================================

	HWND hWnd = CreateWindow(WINDOW_CLASS,
		TITLE,
		WinStyle,
		WINDOW_X,
		WINDOW_Y,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		nullptr, nullptr, hInstance, nullptr);


	return hWnd;
}

/*
�E�B���h�E�v���V�[�W��
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		//======================================================================================
		//6.6�ǉ���
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		}
		break;
		//======================================================================================
	case WM_CLOSE:
		if (MessageBox(hWnd, "�I�����܂����H", "�m�F", MB_OKCANCEL | MB_DEFBUTTON2) == IDOK)
			DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}