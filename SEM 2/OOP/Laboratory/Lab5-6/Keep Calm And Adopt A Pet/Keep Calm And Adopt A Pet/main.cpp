#include <iostream>
#include <fstream>
#include <vector>

#include "models/Dog.hpp"
#include "ui/Ui.hpp"
#include "tests/Tests.hpp"

int main() {
    
    Test test;
    test.test_everything();
    
    Ui ui;
    ui.run();
    
    return 0;
}
