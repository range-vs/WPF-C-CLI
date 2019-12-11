#include "ViewModel.h"

namespace WpfWindow
{
	ViewModel::ViewModel()
	{
		List<System::String^>^ data = gcnew List<System::String^>();
		data->Add(L"Item #1");
		data->Add(L"Item #2");
		data->Add(L"Item #3");
		data->Add(L"Item #4");
		data->Add(L"Item #5");
		Data = gcnew ObservableCollection<System::String^>(data);

		BtnText = gcnew System::String(L"Click me!");
		BtnDel = gcnew System::String(L"Remove item");
	}

	void ViewModel::OnPropertyChanged(System::String^ prop)
	{
		if (prop)
			PropertyChanged(this, gcnew PropertyChangedEventArgs(prop));
	}
};
