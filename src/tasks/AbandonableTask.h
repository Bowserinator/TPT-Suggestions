#pragma once
#include "Task.h"
#include <condition_variable>

class AbandonableTask : public Task
{
	std::condition_variable done_cv;
	
public:
	void Finish();
	void Abandon();
	AbandonableTask();
	virtual ~AbandonableTask();

protected:
	void doWork_wrapper() override;
	bool thAbandoned;
};
