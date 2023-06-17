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
        // Ư�� ���� ����

        // �̺�Ʈ �߻�
        myEvent.Trigger();
    }
};

class EventHandler {
public:
    void HandleEvent() {
        // �̺�Ʈ �ڵ鷯 ����
        // ...
        std::cout << "hi" << std::endl;
    }
    
};

int main() {
    MyClass obj;
    EventHandler handler;

    // �̺�Ʈ �ڵ鷯 ���
    obj.myEvent.Subscribe([&]() {
        handler.HandleEvent();
        });

    // MyClass�� ���� ���� �� �̺�Ʈ �߻�
    obj.DoSomething();

    return 0;
}
