#include "Deque.hpp"
#include <iostream>

int main() {
    Deque** cores = nullptr;
    int num_cores = 0;
    bool initialized = false;
    std::string command;

    while (std::cin >> command) {
        if (command == "ON") {
            std::cin >> num_cores;
            if (initialized || num_cores <= 1) {
                std::cout << "failure\n";
            } else {
                cores = new Deque*[num_cores];
                for (int i = 0; i < num_cores; i++) {
                    cores[i] = new Deque(4); // Initial capacity as specified
                }
                initialized = true;
                std::cout << "success\n";
            }
        }  else if (command == "SPAWN" && initialized) {
    int P_ID;
    std::cin >> P_ID;
    if (P_ID > 0) {
        // Find the core with the least number of tasks.
        int min_index = 0;
        int min_size = cores[0]->get_size();

        // Iterate through all cores to find the one with the smallest queue.
        for (int i = 1; i < num_cores; ++i) {
            int current_size = cores[i]->get_size();
            if (current_size < min_size) {
                min_index = i;
                min_size = current_size;
            }
        }

        // Assign the task to the core with the smallest queue.
        cores[min_index]->push_back(P_ID);
        std::cout << "core " << min_index << " assigned task " << P_ID << "\n";
    } else {
        std::cout << "failure\n";
    }
}
else if (command == "RUN" && initialized) {
    int C_ID;
    std::cin >> C_ID;
    if (C_ID >= 0 && C_ID < num_cores) {
        if (!cores[C_ID]->is_empty()) {
            int task_id = cores[C_ID]->pop_front();
            std::cout << "core " << C_ID << " is running task " << task_id << "\n";
        } else {
            // Attempt to steal a task if this core is empty.
            int max_index = -1;
            int max_size = -1;
            for (int i = 0; i < num_cores; ++i) {
                if (i != C_ID && cores[i]->get_size() > max_size) {
                    max_index = i;
                    max_size = cores[i]->get_size();
                }
            }
            if (max_index != -1 && !cores[max_index]->is_empty()) {
                int stolen_task = cores[max_index]->pop_back();
                cores[C_ID]->push_back(stolen_task);
                
                // Run the stolen task immediately.
                int task_id = cores[C_ID]->pop_front();
                std::cout << "core " << C_ID << " is running task " << task_id << "\n";
            } else {
                // Output when no tasks can be stolen and the core itself has no tasks.
                std::cout << "core " << C_ID << " has no tasks to run\n";
            }
        }
    } else {
        std::cout << "failure\n";
    }
}

 else if (command == "SLEEP" && initialized) {
    int C_ID;
    std::cin >> C_ID;
    if (C_ID >= 0 && C_ID < num_cores) {
        if (!cores[C_ID]->is_empty()) {
            while (!cores[C_ID]->is_empty()) {
                int task_id = cores[C_ID]->pop_back();
                int min_index = -1;
                int min_size = INT_MAX;
                for (int i = 0; i < num_cores; ++i) {
                    if (i != C_ID && cores[i]->get_size() < min_size) {
                        min_index = i;
                        min_size = cores[i]->get_size();
                    }
                }

                if (min_index != -1) {
                    cores[min_index]->push_back(task_id);
                    std::cout << "task " << task_id << " assigned to core " << min_index << "\n";
                }
            }
        } else {
            std::cout << "core " << C_ID << " has no tasks to assign\n";
        }
    } else {
        std::cout << "failure\n";
    }
}
 if (command == "SHUTDOWN" && initialized) {
            for (int i = 0; i < num_cores; ++i) {
                while (!cores[i]->is_empty()) {
                    int task_id = cores[i]->pop_front();
                    std::cout << "deleting task " << task_id << " from core " << i << "\n";
                }
            }
        } else if (command == "SIZE" && initialized) {
            int C_ID;
            std::cin >> C_ID;
            if (C_ID >= 0 && C_ID < num_cores) {
                std::cout << "size is " << cores[C_ID]->get_size() << "\n";
            } else {
                std::cout << "failure\n";
            }
        } else if (command == "CAPACITY" && initialized) {
            int C_ID;
            std::cin >> C_ID;
            if (C_ID >= 0 && C_ID < num_cores) {
                std::cout << "capacity is " << cores[C_ID]->get_capacity() << "\n";
            } else {
                std::cout << "failure\n";
            }
        } else if (command == "EXIT") {
            break;
        }
    }

    // Clean up memory
    if (initialized) {
        for (int i = 0; i < num_cores; ++i) {
            delete cores[i];
        }
        delete[] cores;
    }

    return 0;
}
