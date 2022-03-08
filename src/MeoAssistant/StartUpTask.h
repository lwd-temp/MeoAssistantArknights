#pragma once
#include "PackageTask.h"

namespace asst
{
    class ProcessTask;

    class StartUpTask : public PackageTask
    {
    public:
        StartUpTask(AsstCallback callback, void* callback_arg);
        virtual ~StartUpTask() = default;

        virtual bool set_params(const json::value& params) override;

        static constexpr const char* TaskChain = "StartUp";
    protected:

        std::shared_ptr<ProcessTask> m_start_up_task_ptr = nullptr;
    };
}
