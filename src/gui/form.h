#pragma once

#include <form.h>
#include <functional>

class Form: public FORM {
private:  
  WINDOW * current_window;
  FIELD ** fields;
  int type;
  int row, column;
public:
  Form(WINDOW *, int);
  void display();
  void submit(std::function<void>);
};
