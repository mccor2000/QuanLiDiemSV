#include "./form.h"

char * LOPTC_FORM_LABEL[] = {
  (char *)"Ma MH: ",
  (char *)"Nien khoa: ",
  (char *)"Hoc ki: ",
  (char *)"Nhom: ",
  (char *)"Min SV: ",
  (char *)"Max SV: ",
};

char * LOPCQ_FORM_LABLE[] = {
  (char *)"Ma lop: ",
};

char * MONHOC_FORM_LABEL[] = {
  (char *)"Ma MH: ",
  (char *)"Ten MH: ",
  (char *)"STCLT: ",
  (char *)"STCTH: ",
};

char * SV_FORM_LABEL[] = {
  (char *)"Ma SV: ",
  (char *)"Ho: ",
  (char *)"Ten: ",
  (char *)"Gioi tinh: ",
  (char *)"SDT: ",
};

char * NHAP_DIEM_FORM_1_LABEL[] = {
  (char *)"Nien khoa: ",
  (char *)"Hoc ki: ",
  (char *)"Nhom: ",
  (char *)"Mon hoc: ",
};

char * NHAP_DIEM_FORM_2_LABEL[] = {
  (char *)"Diem: ",
};

char * DANG_KY_FORM_1_LABEL[] = {
  (char *)"Ma SV: ",
};

char * DANG_KY_FORM_2_LABEL[] = {
  (char *)"Nien khoa: ",
  (char *)"Hoc ki: ",
};

char * XEM_DIEM_FORM_LABLE[] = {
  (char *)"Ma lop: ",
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
      return NHAP_DIEM_FORM_1_LABEL;
    case 6:
      return NHAP_DIEM_FORM_2_LABEL;
    case 7:
      return DANG_KY_FORM_1_LABEL;
    case 8:
      return DANG_KY_FORM_2_LABEL;
    case 9:
      return XEM_DIEM_FORM_LABLE;
    default: 
      return NULL;
  }  
}

void Form::display() {
  wclear(current_window);
  char ** label = get_label();
  fields = new FIELD*[len+1];

  for (int i = 0; i < len; i++) {
    fields[i] = new_field(1, 50, i+1, 50, 0, 0);
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
          form_driver(form, REQ_NEXT_FIELD);
      	  form_driver(form, REQ_PREV_FIELD);
      	  form_data[i] = Trim(field_buffer(fields[i], 0));
        }
        if (validate(form_data)) return submit(form_data);
        return false;
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

void Form::set_buffer_loptc(LopTC curr_loptc) {
  set_field_buffer(fields[0], 0, curr_loptc.maMH);
  set_field_buffer(fields[1], 0, curr_loptc.nienkhoa);
  set_field_buffer(fields[2], 0, std::to_string(curr_loptc.hocki).c_str());
  set_field_buffer(fields[3], 0, std::to_string(curr_loptc.nhom).c_str());
  set_field_buffer(fields[4], 0, std::to_string(curr_loptc.sv_min).c_str());
  set_field_buffer(fields[5], 0, std::to_string(curr_loptc.sv_max).c_str());
}

void Form::set_buffer_lopcq(LopCQ curr_lopcq) {
  set_field_buffer(fields[0], 0, curr_lopcq.MALOP);
}

void Form::set_buffer_mh(MonHoc curr_mh) {
  set_field_buffer(fields[0], 0, curr_mh.MAMH);
  set_field_buffer(fields[1], 0, curr_mh.TENMH);
  set_field_buffer(fields[2], 0, std::to_string(curr_mh.STCLT).c_str());
  set_field_buffer(fields[3], 0, std::to_string(curr_mh.STCTH).c_str());
}

void Form::set_buffer_sv(SinhVien curr_sv) {
  set_field_buffer(fields[0], 0, curr_sv.get_MASV());
  set_field_buffer(fields[1], 0, curr_sv.get_HO());
  set_field_buffer(fields[2], 0, curr_sv.get_TEN());
  set_field_buffer(fields[3], 0, curr_sv.get_PHAI() == 1 ? "NAM" : "NU");
  set_field_buffer(fields[4], 0, curr_sv.get_SDT());
}

void Form::set_buffer_svdk(SinhVienDK curr_svdk) {
  set_field_buffer(fields[0], 0, curr_svdk.get_MASV());
}
