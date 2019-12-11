#pragma once


namespace WpfWindow
{
	using namespace System;
	using namespace System::Windows::Input;

	public ref class GeneralCommand : ICommand
	{
		Action<Object^>^ execute;
		Func<Object^, bool>^ canExecute;

	public:
		event EventHandler^ CanExecuteChanged
		{
			virtual void add(EventHandler^ d)
			{
				CommandManager::RequerySuggested += d;
			}
			virtual void remove(EventHandler^ d)
			{
				CommandManager::RequerySuggested -= d;
			}
		}

		GeneralCommand(Action<Object^>^ execute, Func<Object^, bool>^ canExecute);

		virtual bool CanExecute(Object^ parameter);

		virtual void Execute(Object^ parameter);
	};
}
