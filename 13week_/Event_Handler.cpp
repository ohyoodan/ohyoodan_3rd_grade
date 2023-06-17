#include "Event_Handler.h"

namespace GameEngine {

	typedef std::function<void()> EventHandlerFunc;
	void Event_Handler::RegisterEvent(const EventHandlerFunc& func) {
		
		eventFuncs.push_back(func);

	}

	void Event_Handler::TriggerEvent(const EventHandlerFunc& func) {
		auto it = std::find_if(eventFuncs.begin(), eventFuncs.end(), [&](const std::function<void()>& f) {
			return f.target<void()>() == func.target<void()>();
			});

		if (it != eventFuncs.end()) {
			(*it)();
		}
	}
	void Event_Handler::RemoveEvent(const EventHandlerFunc& func)
	{
		auto it = std::find_if(eventFuncs.begin(), eventFuncs.end(), [&](const std::function<void()>& f) {
			return f.target<void()>() == func.target<void()>();
			});

		if (it != eventFuncs.end()) {
			eventFuncs.erase(it);
		}
	}

	Event_Handler::Event_Handler() {

	}
}