#include <stdio.h>
#include "ui/ui.h"
#include "controllers/controller.h"
#include "repos/repository.h"
#include "models/medication.h"
#include "tests/test.h"

void run() {
    UI *ui = ui_create();
    test_everything();
    test_populate(ui->controller, "input");
    ui_run(ui);
}

int main() {
    run();
    return 0;
}
