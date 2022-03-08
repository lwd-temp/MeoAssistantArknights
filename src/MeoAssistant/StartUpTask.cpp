#include "StartUpTask.h"

#include "ProcessTask.h"

asst::StartUpTask::StartUpTask(AsstCallback callback, void* callback_arg)
    : PackageTask(callback, callback_arg, TaskChain),
    m_start_up_task_ptr(std::make_shared<ProcessTask>(m_callback, m_callback_arg, TaskChain))
{
    m_start_up_task_ptr->set_tasks({ "StartUp" })
        .set_times_limit("ReturnToTerminal", 0)
        .set_times_limit("Terminal", 0);
}

bool asst::StartUpTask::set_params([[maybe_unused]] const json::value& params)
{
    if (!runned) {
        m_subtasks.clear();
        m_subtasks.emplace_back(m_start_up_task_ptr);
    }
    return true;
}
