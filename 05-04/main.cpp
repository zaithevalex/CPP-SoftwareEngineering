#include <iostream>

struct AggressiveStrategy {
    void execute() const {
        std::cout << "Aggressive strategy: Attack with full power!" << std::endl;
    }
};

struct DefensiveStrategy {
    void execute() const {
        std::cout << "Defensive strategy: Hold position and shield up!" << std::endl;
    }
};

struct ResourceStrategy {
    void execute() const {
        std::cout << "Resource strategy: Gathering supplies." << std::endl;
    }
};

template <typename Strategy>
class Entity : public Strategy {
public:
    void performAction() {
        std::cout << "Entity acting: ";
        this->execute(); 
    }
};

int main() {
    std::cout << "--- Unit 1 ---" << std::endl;
    Entity<AggressiveStrategy> warrior;
    warrior.performAction();
    
    std::cout << "\n--- Unit 2 ---" << std::endl;
    Entity<DefensiveStrategy> guard;
    guard.performAction();

    std::cout << "\n--- Unit 3 ---" << std::endl;
    Entity<ResourceStrategy> worker;
    worker.performAction();

    return 0;
}
