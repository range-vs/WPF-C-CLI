#pragma once

#include "Window.h"
#include "ViewModel.h"

namespace WpfWindow
{
	using namespace System::Windows;
	using namespace System::Windows::Controls;
	using namespace System::Windows::Markup;
	using namespace System::IO;

	public ref class MainWindow : public Window
	{
	private:
		Button^ button1;
		Panel^ panel;

		ViewModel^ viewModel;

		void initializeComponent();
	public:
		MainWindow();


		~MainWindow();

	private: // events
		void OnClick(System::Object^ sender, System::Windows::RoutedEventArgs^ e);

	};
}