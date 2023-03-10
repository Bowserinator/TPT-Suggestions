#pragma once
#include "tasks/AbandonableTask.h"

#include <memory>

class GameSave;
class VideoBuffer;
class ThumbnailRendererTask : public AbandonableTask
{
	std::unique_ptr<GameSave> Save;
	int Width, Height;
	bool Decorations;
	bool Fire;
	bool AutoRescale;
	std::unique_ptr<VideoBuffer> thumbnail;

	static int queueSize;

public:
	ThumbnailRendererTask(GameSave *save, int width, int height, bool autoRescale = false, bool decorations = true, bool fire = true);
	virtual ~ThumbnailRendererTask();

	virtual bool doWork() override;
	std::unique_ptr<VideoBuffer> Finish();

	static int QueueSize();
};
