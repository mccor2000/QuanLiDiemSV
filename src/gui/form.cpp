#include "./form.h"

Form::Form(WINDOW * w, int t) {
  current_window = w;
  getmaxyx(current_window, row, column);
  type = t;
  switch (type) {
    case 1:
      // Lop TC
      len = 7;
      label =  
      fields = new FIELD*[len];
      for (int i = 0; i < len; i++) {
        fields[i] = new_field(1, 5, i + 2, 32, 0, 0);   
      }
      break;
    case 2:
      // Mon hoc
      fields = new FIELD*[4];
      break;
    case 3:
      // Sinh vien
      fields = new FIELD*[6];
      break;
    case 4:
      // Dang ky:
      fields = new FIELD*[2];
      break;
    case 5:
      // Nhap diem
      fields = new FIELD*[4];
      break;

  }
}
