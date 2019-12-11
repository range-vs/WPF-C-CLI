#include "Window.h"

namespace WpfWindow
{
	MainWindow::MainWindow()
	{
		this->initializeComponent();
	}

	void MainWindow::initializeComponent()
	{
		/* NO XAML
		panel = gcnew DockPanel();
		button1 = gcnew Button();
		button1->Content = L"Please, click me.";
		button1->Margin = Thickness(30);
		button1->Click += gcnew System::Windows::RoutedEventHandler(this, &MainWindow::OnClick);
		IAddChild^ conteiner = panel;
		conteiner->AddChild(button1);
		conteiner = this;
		conteiner->AddChild(panel);*/

		// View
		DependencyObject^ rootElement;
		FileStream^ fs = gcnew FileStream(L"Window.xaml", FileMode::Open);
		rootElement = (DependencyObject^)XamlReader::Load(fs);
		fs->Close();

		// copy all properties tmp window from this window
		Window^ tmp = (Window^)rootElement;
		this->Width = tmp->Width;
		this->Height = tmp->Height;
		this->Title = tmp->Title;
		this->WindowStartupLocation = tmp->WindowStartupLocation;

		panel = (Panel^)LogicalTreeHelper::FindLogicalNode(rootElement, L"rootPanel");
		this->Content = panel;

		button1 = (Button^)LogicalTreeHelper::FindLogicalNode(rootElement, L"button1");
		button1->Click += gcnew System::Windows::RoutedEventHandler(this, &MainWindow::OnClick);

		// MVVM
		viewModel = gcnew ViewModel();
		this->DataContext = viewModel;
	}

	void MainWindow::OnClick(System::Object^ sender, System::Windows::RoutedEventArgs^ e)
	{
		viewModel->BtnText = L"Thank you.";
	}

	MainWindow::~MainWindow()
	{

	}
}
