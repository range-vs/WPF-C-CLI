#pragma once

#include "ConverterString.h"
#include "GeneralCommand.h"

namespace WpfWindow
{
	using namespace System::Windows;
	using namespace System::Windows::Controls;
	using namespace System::Windows::Markup;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections::ObjectModel;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::CompilerServices;
	using namespace System::Runtime;

	public ref class ViewModel : INotifyPropertyChanged
	{
		System::String^ _btnText;
		System::String^ _btnDel;

		GeneralCommand^ _removeItemListBox;

	public:

		property ObservableCollection<System::String^>^ Data;

		property System::String^ BtnText
		{
			System::String^ get()
			{
				return _btnText;
			}

			void set(System::String^ v)
			{
				_btnText = v;
				OnPropertyChanged(nameof(BtnText));
			}
		}

		property System::String^ BtnDel
		{
			System::String^ get()
			{
				return _btnDel;
			}

			void set(System::String^ v)
			{
				_btnDel = v;

				OnPropertyChanged(nameof(BtnDel));
			}
		}


		property GeneralCommand^ RemoveItemListBox
		{
			GeneralCommand^ get()
			{
				if (_removeItemListBox == nullptr)
				{
					_removeItemListBox = gcnew GeneralCommand(gcnew Action<Object^>(this, &ViewModel::remoteItemListBox), nullptr);
				}
				return _removeItemListBox;
			}
		}

		void remoteItemListBox(Object^ obj)
		{
			if (Data->Count > 1)
				Data->RemoveAt(0);
			else if (Data->Count == 1)
			{
				if (Data[0] != L"All elements removed")
				{
					Data->RemoveAt(0);
					Data->Add(L"All elements removed");
				}
			}
		}


		ViewModel();

	public:
		virtual event System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

		void OnPropertyChanged(System::String^ prop);
	};
}
