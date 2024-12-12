#include <iostream>
#include <queue>
#include <string>

struct Job {
    int jobId;
    std::string jobName;

        Job(int id, const std::string& name) : jobId(id), jobName(name) {}
};

void addJob(std::queue<Job>& jobQueue, int jobId, const std::string& jobName) {
    Job newJob(jobId, jobName);
    jobQueue.push(newJob);
    std::cout << "Job added: ID = " << jobId << ", Name = " << jobName << "\n";
}

void deleteJob(std::queue<Job>& jobQueue) {
    if (jobQueue.empty()) {
        std::cout << "No jobs in the queue to delete.\n";
        return;
    }
    Job jobToDelete = jobQueue.front();
    jobQueue.pop();
    std::cout << "Job deleted: ID = " << jobToDelete.jobId << ", Name = " << jobToDelete.jobName << "\n";
}


void displayJobs(const std::queue<Job>& jobQueue) {
    if (jobQueue.empty()) {
        std::cout << "No jobs in the queue.\n";
        return;
    }

    std::queue<Job> tempQueue = jobQueue;
    std::cout << "Jobs in the queue:\n";
    while (!tempQueue.empty()) {
        Job job = tempQueue.front();
        std::cout << "ID: " << job.jobId << ", Name: " << job.jobName << "\n";
        tempQueue.pop();
    }
}

int main() {
    std::queue<Job> jobQueue; 
    int choice, jobId;
    std::string jobName;

    do {
        std::cout << "\n--- Job Queue Simulation ---\n";
        std::cout << "1. Add Job\n";
        std::cout << "2. Delete Job\n";
        std::cout << "3. Display Jobs\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Job ID: ";
                std::cin >> jobId;
                std::cout << "Enter Job Name: ";
                std::cin.ignore(); // To ignore leftover newline character
                std::getline(std::cin, jobName);
                addJob(jobQueue, jobId, jobName);
                break;
            case 2:
                deleteJob(jobQueue);
                break;
            case 3:
                displayJobs(jobQueue);
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}