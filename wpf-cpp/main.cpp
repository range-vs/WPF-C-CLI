#include "Window.h"

#include <Windows.h>
#include <string>

using namespace std;

[System::STAThread]
int WinMain(HINSTANCE hInst, HINSTANCE prewHInst, LPSTR lpCmdLine, int nShowCmd)
{
	WpfWindow::Application^ app = gcnew WpfWindow::Application();

	app->MainWindow = gcnew WpfWindow::MainWindow();
	app->MainWindow->ShowDialog();
	return 0;
}