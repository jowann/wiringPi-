//
//  Queue.hpp
//  test
//
//  Created by johann Vandromme on 11/12/2017.
//  Copyright © 2017 Ineat-conseil. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <thread>
#include <mutex>
#include <vector>
#include <map>
#include "AbstractMessage.hpp"
#include "MessageBox.hpp"

class EventDispatcher;
class MainQueue;
class EventListener;

class Queue{
protected:
    static std::map<std::thread::id, Queue*> _processingQueues;
    
    std::vector<EventDispatcher *>eventDispatchers;
    MessageBox messageBox;
    int _delay;
    bool _finish = false;
    Queue(int delayInMs):_delay(delayInMs){};
    virtual void start() = 0;
    virtual void stop() = 0;
    void loop();
    virtual ~Queue();
    inline static std::thread::id currentThreadId(){
        return std::this_thread::get_id();
    }
public:
    static std::mutex queueMutex;
    virtual std::thread::id getId()const = 0 ;
    std::function<void()> idle;
    static MainQueue &main();
    void registerDispatcher(EventDispatcher *eventDispatcher);
    void addMessage(AbstractMessage *message);
    void addMessage(std::function<void()> message);
    bool isCurrentQueue();
    static Queue &currentQueue();
};

class MainQueue:public Queue{
private:
    std::thread::id _id;
protected:
    MainQueue(int delayInMs = 0);
public:
    void start();
    static MainQueue &instance();
    void stop();
    std::thread::id getId() const;
    virtual ~MainQueue();
private:
    
    static MainQueue *mainQueue;
};

class AsyncQueue:public Queue{
protected:
    std::thread *thread;
public:
    AsyncQueue(int delayInMs = 0):Queue(delayInMs), thread(0){}
    void start();
    void stop();
    std::thread::id getId() const;
    virtual ~AsyncQueue();
    
};
inline bool operator==(const Queue& lhs, const Queue& rhs){
    return lhs.getId() == rhs.getId();
}
#endif /* Queue_hpp */
