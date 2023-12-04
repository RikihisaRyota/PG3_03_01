#pragma once
class IStageCommand {
public:
	virtual ~IStageCommand();
	virtual void Exec() = 0;
};