#include "./form.h"

char * LOPTC_FORM_LABEL[] = {
  "Ma MH: ",
  "Nien khoa: ",
  "Hoc ki: ",
  "Nhom: ",
  "Min SV: ",
  "Max SV: ",
};

char * LOPCQ_FORM_LABLE[] = {
  "Ma lop: ",
};

char * MONHOC_FORM_LABEL[] = {
  "Ma MH: ",
  "Ten MH: ",
  "STCLT: ",
  "STCTH: ",
};

char * SV_FORM_LABEL[] = {
  "Ma SV: ",
  "Ho: ",
  "Ten: ",
  "Gioi tinh: ",
  "SDT: ",
  "Ma lop: ",
};

char * SVDK_FORM_LABEL[] = {
  "Ma SV: ",
  "Diem: ",
};

char * NHAP_DIEM_FORM_LABEL[] = {
  "Nien khoa: ",
  "Hoc ki: ",
  "Nhom: ",
  "Mon hoc: ",
};

char * DANG_KY_FORM_LABEL[] = {
  "Nien khoa: ",
  "Hoc ki: ",
};

Form::Form(WINDOW * w) {
  current_window = w;
}

char ** Form::get_label() {
  switch (type) {
    case 1:
      return LOPTC_FORM_LABEL;
    case 2:
      return LOPCQ_FORM_LABLE;
    case 3:
      return MONHOC_FORM_LABEL;
    case 4:
      return SV_FORM_LABEL;
    case 5:
      return NHAP_DIEM_FORM_LABEL;
    case 6:
      return DANG_KY_FORM_LABEL;
    default: 
      return NULL;
  }  
}

void Form::display() {
  wclear(current_window);
  char ** label = get_label();
  fields = new FIELD*[len+1];

  for (int i = 0; i < len; i++) {
    fields[i] = new_field(1, 16, i+1, 16, 0, 0);
    set_field_back(fields[i], A_UNDERLINE);
    field_opts_off(fields[1], O_AUTOSKIP);
  }
  fields[len] = NULL;
  form = new_form(fields);
  keypad(current_window, TRUE); 
  set_form_win(form, current_window);
  set_form_sub(form, derwin(current_window, 0, 0, 1, 1));
  post_form(form);
  for (int i = 0; i < len; i++) {
    mvwprintw(current_window, i+2, 1, label[i]);
  }
  box(current_window, 0, 0);
  wrefresh(current_window);
}

bool Form::process_input() {
  int input;
  bool cancel = false;
  while(!cancel) {
    input = wgetch(current_window);
    switch (input) {
		  case KEY_DOWN:
			  form_driver(form, REQ_NEXT_FIELD);
			  form_driver(form, REQ_END_LINE);
			  break;

		  case KEY_UP:
			  form_driver(form, REQ_PREV_FIELD);
			  form_driver(form, REQ_END_LINE);
			  break;

		  case KEY_LEFT:
			  form_driver(form, REQ_PREV_CHAR);
			  break;

		  case KEY_RIGHT:
			  form_driver(form, REQ_NEXT_CHAR);
			  break;

		  case KEY_BACKSPACE:
		  case 127:
			  form_driver(form, REQ_DEL_PREV);
			  break;

		  case KEY_DC:
			  form_driver(form, REQ_DEL_CHAR);
			  break;
         
      case 10: {
        char * form_data[len];
        for (int i = 0; i < len; i++) {
          form_data[i] = field_buffer(fields[i], 0);
        }

        submit(form_data);
        return true;
      }
      case 27: 
        cancel = true;
        return false;

      default:
			  form_driver(form, input);
			  break;
	  } 
  }
}
