#pragma once

#include <form.h>
#include <functional>

class Form {
private:  
  WINDOW * current_window;
  FORM * form;
  FIELD ** fields;

  int type, len;
  std::function<void(char **)> submit;
  int row, column;
  
  char ** get_label();

public:
  Form(WINDOW *);
  Form() {;}

  void set_type(int t)                            { type = t; }
  void set_len(int l)                             { len = l; }
  void set_submit(std::function<void(char**)> f)  { submit = f; }

  bool process_input();
  void display();
};
