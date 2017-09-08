#include "ui.h"
#include "test.h"

int main()
{
   ui App;
   run_tests(App.cont);
   run_app(App);
   return 0;
}
