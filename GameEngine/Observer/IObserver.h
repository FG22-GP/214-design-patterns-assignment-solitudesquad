#pragma once
#include <string>

class IObserver
{
public:
      // virtual void Update(const std::string &message_from_subject) = 0;
      virtual void UpdateCounter(const int &counterValue) = 0;
      
};

class ISubject
{
public:
      virtual void Attach(IObserver *observer) = 0;
      virtual void Detach(IObserver *observer) = 0;
      // virtual void Notify() = 0;
      virtual void NotifyCounter() = 0;
};