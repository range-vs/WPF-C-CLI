#include "GeneralCommand.h"

namespace WpfWindow
{
	GeneralCommand::GeneralCommand(Action<Object^>^ execute, Func<Object^, bool>^ canExecute)
	{
		this->execute = execute;
		this->canExecute = canExecute;
	}

	bool GeneralCommand::CanExecute(Object^ parameter)
	{
		return canExecute == nullptr || canExecute(parameter);
	}

	void GeneralCommand::Execute(Object^ parameter)
	{
		execute(parameter);
	}
}