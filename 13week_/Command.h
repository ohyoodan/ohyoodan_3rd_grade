#pragma once
#include "Object_.h"
#pragma once
namespace GameEngine{

	class Command {
	protected:
		bool buttonPush;
	public :
		
		Command();
		virtual ~Command();

		virtual void execute(Object_& objcet);
		virtual void execute();
		void ButtonSet(bool t);
	};	
	

	class UpCommand : public Command {	
	public:
		void execute(Object_& object) override;
		void execute() override;
	};
	class RightCommand : public Command {
	public:
		void execute(Object_& object) override;
		void execute() override;
	};

	class DownCommand :public Command {
	public:
		void execute(Object_& object) override;
		void execute() override;
	};

	class LeftCommand : public Command {
	public:
		void execute(Object_& object) override;
		void execute() override;
	};

	class EnterCommand : public Command {
	public:
		void execute(Object_& object) override;
		void execute() override;

	};

	class ESCCommand : public Command {
	public:
		void execute(Object_& object) override;
		void execute() override;

	};

}