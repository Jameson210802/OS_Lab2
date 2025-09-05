#include "round_robin.hpp"

#include<algorithm>
#include<queue>

namespace cse4733 {

void round_robin::run(std::vector<std::shared_ptr<cse4733::IProcess>> &processes, int quantum)
    {
        int completion_time = 0;

        int process_num = processes.size();

       std::queue<std::shared_ptr<cse4733::IProcess>> readyQueue;

        for (int i = 0; i < process_num; i++)
        {
            readyQueue.push(processes[i]);
        }

        while(!readyQueue.empty())
        {
            std::shared_ptr<cse4733::IProcess> process_current = readyQueue.front();

            int time_remaining = process_current->get_remaining_time();

            if(time_remaining < quantum)
            {
                //do code stuff
            }
            else
            {
                //do other code stuff 
            
            }

        }

        // TODO:
        //  Get number of processes
        //  Fill the ready queue
        //  Loop until all processes are removed from the ready queue
        //     Get the next process from the ready queue
        //     Get the remaining time for the process
        //     Execute the process for the quantum or remaining time, whichever is smaller
        //   Update the completion time and remaining time
        //   Add back to the queue if the process still has remaining time
        //     Else set the completion time, turnaround time, and waiting time
    }

    void round_robin::print_results(std::vector<std::shared_ptr<cse4733::IProcess>> &processes)
    {
        int total_waiting = 0;
        int total_turnaround = 0;
        int n = processes.size();

        std::cout << "Round Robin Scheduling:\n";
        std::cout << "Process ID\tCompletion Time\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
        for (const auto& item : processes)
        {
            std::cout << "  " << item->to_string() << std::endl;

            // Set the total turnaround time
            total_turnaround += item->get_turnaround_time();

            // Set the total waiting time
            total_waiting += item->get_waiting_time();
        }
        std::cout << "  Average Waiting Time: " << (double)total_waiting / n << std::endl;
        std::cout << "  Average Turnaround Time: " << (double)total_turnaround / n << std::endl;
    }

}

