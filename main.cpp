#include <Windows.h>
#include <sstream>

constexpr char FILE_NAME[] = "texture.png";

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int nCmdShow)
{
	std::stringstream ss;

	ss << "テクスチャファイル:" << FILE_NAME << "が読み込めませんでした";

	int msgboxID = 0;
	msgboxID = MessageBox(nullptr, ss.str().c_str(), "Window", MB_YESNOCANCEL | MB_ICONERROR | MB_DEFBUTTON1);

	if (msgboxID == IDYES)
	{
		MessageBox(nullptr, "OK", "OK", MB_OK);
	}
	else if (msgboxID == IDCANCEL)
	{
		MessageBox(nullptr, "CACEL", "CANCEL", MB_OK);
	}

	return 0;
}