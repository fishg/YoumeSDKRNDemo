// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from react.djinni

#pragma once

#include <memory>
#include <string>

class JavascriptArray;
class JavascriptMap;
class JobDispatcher;
class JobQueue;

class ReactBridge {
public:
    virtual ~ReactBridge() {}

    virtual std::shared_ptr<JavascriptMap> createMap() = 0;

    virtual std::shared_ptr<JavascriptArray> createArray() = 0;

    virtual std::shared_ptr<JavascriptMap> copyMap(const std::shared_ptr<JavascriptMap> & map) = 0;

    virtual std::shared_ptr<JavascriptArray> copyArray(const std::shared_ptr<JavascriptArray> & array) = 0;

    virtual void emitEventWithMap(const std::string & name, const std::shared_ptr<JavascriptMap> & params) = 0;

    virtual void emitEventWithArray(const std::string & name, const std::shared_ptr<JavascriptArray> & params) = 0;

    virtual std::shared_ptr<JobDispatcher> createJobDispatcher(const std::shared_ptr<JobQueue> & queue) = 0;
};
