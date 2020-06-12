#ifndef _FORM_H
#define _FORM_H
#include <form.h>
#include <functional>
#include "../database/database.h"
#include "../helpers/helpers.h"

class Form {
private:  
  WINDOW * current_window;
  FORM * form;
  FIELD ** fields;

  int type, len;
  std::function<void(char **)> submit;
  std::function<bool(char **)> validate;

  char ** buffer;

  int row, column;
  
  char ** get_label();
public:
  Form(WINDOW *);
  Form() {;}

  void set_type(int t)                            { type = t; }
  void set_len(int l)                             { len = l; }
  void set_submit(std::function<void(char**)> f)  { submit = f; }
  void set_validate(std::function<bool(char**)> f)  { validate = f; }

  void set_buffer_loptc(LopTC);
  void set_buffer_lopcq(LopCQ);
  void set_buffer_mh(MonHoc);
  void set_buffer_sv(SinhVien);
  void set_buffer_svdk(SinhVienDK);

  bool process_input();
  void display();
};
#endif
