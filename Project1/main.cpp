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
            if (initialized) {
                std::cout << "failure\n";
            } else {
                cores = new Deque*[num_cores];
                for (int i = 0; i < num_cores; i++) {
                    cores[i] = new Deque();
                }
                initialized = true;
                std::cout << "success\n";
            }
        } else if (command == "SPAWN" && initialized) {
            int P_ID;
            std::cin >> P_ID;
            if (P_ID > 0) {
                int min_index = 0;
                for (int i = 1; i < num_cores; ++i) {
                    if (cores[i]->get_size() < cores[min_index]->get_size()) {
                        min_index = i;
                    }
                }
                cores[min_index]->push_back(P_ID);
                std::cout << "core " << min_index << " assigned task " << P_ID << "\n";
            } else {
                std::cout << "failure\n";
            }
        } else if (command == "RUN" && initialized) {
            int C_ID;
            std::cin >> C_ID;
            if (C_ID >= 0 && C_ID < num_cores && !cores[C_ID]->is_empty()) {
                int task_id = cores[C_ID]->pop_front();
                std::cout << "core " << C_ID << " is running task " << task_id << "\n";
            } else {
                std::cout << "core " << C_ID << " has no tasks to run\n";
            }
        } else if (command == "SLEEP" && initialized) {
            int C_ID;
            std::cin >> C_ID;
            if (C_ID >= 0 && C_ID < num_cores && !cores[C_ID]->is_empty()) {
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
                    cores[min_index]->push_back(task_id);
                }
                std::cout << "core " << C_ID << " has no tasks to assign\n";
            } else {
                std::cout << "failure\n";
            }
        } else if (command == "SHUTDOWN" && initialized) {
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
        for (int i = 0; i < num_cores; i++) {
            delete cores[i];
        }
        delete[] cores;
    }

    return 0;
}
