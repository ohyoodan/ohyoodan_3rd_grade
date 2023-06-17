#include <iostream>
#include <functional>
#include <vector>

class Event {
public:
    using EventHandlerFunc = std::function<void()>;

    void Subscribe(const EventHandlerFunc& handler) {
        eventHandlers.push_back(handler);
    }

    void Trigger() {
        for (const auto& handler : eventHandlers) {
            handler();
        }
    }

private:
    std::vector<EventHandlerFunc> eventHandlers;
};

class MyClass {
public:
    Event myEvent;

    void DoSomething() {
        // 특정 동작 수행

        // 이벤트 발생
        myEvent.Trigger();
    }
};

class EventHandler {
public:
    void HandleEvent() {
        // 이벤트 핸들러 동작
        // ...
        std::cout << "hi" << std::endl;
    }
    
};

int main() {
    MyClass obj;
    EventHandler handler;

    // 이벤트 핸들러 등록
    obj.myEvent.Subscribe([&]() {
        handler.HandleEvent();
        });

    // MyClass의 동작 수행 시 이벤트 발생
    obj.DoSomething();

    return 0;
}
