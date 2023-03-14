#pragma once

namespace cardinal_change {

	class Command {


	public:
		Command() {}

		virtual ~Command() {};

		virtual void Exit() {};
	};


}