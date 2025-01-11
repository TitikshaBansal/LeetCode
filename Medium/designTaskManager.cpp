class TaskManager {
private:
    struct Task {
        int priority;
        int taskId;
        int userId;
    
        // Default constructor
        Task() : userId(0), taskId(0), priority(0) {}
    
        // Constructor with arguments
        Task(int userId, int taskId, int priority) : userId(userId), taskId(taskId), priority(priority) {}
    
        bool operator<(const Task& other) const {
            if (priority != other.priority) {
                return priority > other.priority; 
            }
            return taskId > other.taskId;
        }
    };

    map<Task, int> sortedTasks;  // max-heap to hold tasks
    unordered_map<int, Task> taskMap;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        Task newTask(userId, taskId, priority);
        sortedTasks[newTask] = userId;  
        taskMap[taskId] = newTask; 
    }
    
    void edit(int taskId, int newPriority) {
        auto taskIt = taskMap.find(taskId);
        if (taskIt != taskMap.end()) {
            Task task = taskIt->second;
            sortedTasks.erase(task);
            task.priority = newPriority;
            sortedTasks[task] = task.userId;
            taskMap[taskId] = task;
        }
    }
    
    void rmv(int taskId) {
        auto taskIt = taskMap.find(taskId);
        if (taskIt != taskMap.end()) {
            Task task = taskIt->second;
            sortedTasks.erase(task);
            taskMap.erase(taskId);
        }
    }
    
    int execTop() {
        if (sortedTasks.empty()) {
            return -1;
        }
        auto topTask = sortedTasks.begin();
        Task top = topTask->first;
        sortedTasks.erase(topTask);
        taskMap.erase(top.taskId);
        return top.userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

// https://leetcode.com/problems/design-task-manager/
