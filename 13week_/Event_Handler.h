#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <functional>

typedef std::function<void()> EventHandlerFunc;
namespace GameEngine {
	class Event_Handler
	{
	private:
		std::vector<EventHandlerFunc> eventFuncs;

		


	public: 
		  void RegisterEvent(const EventHandlerFunc& func);

		  void TriggerEvent(const EventHandlerFunc& func);
		
		  void RemoveEvent(const EventHandlerFunc& func);
			
		  Event_Handler();
	};

	

}

