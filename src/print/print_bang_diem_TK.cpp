#include "./print.h"

void print_bang_diem_TK(WINDOW * current_window, Table &current_table) {
  DanhSachSinhVien * current_dssv = database.get_current_dssv();
  
  LinkedList<char *> list_ma_mh;
  // Get list MonHoc
  Node<SinhVien> * current_sv = current_dssv->p_head_;
  while (current_sv != NULL) {
    // ......
    Node<int> * curr_malop = current_sv->get_data().DS_LOPTC->p_head_;
    while (curr_malop != NULL) {
      LopTC * curr_ltc = database.dsltc.node[database.dsltc.search(curr_malop->get_data())];
      if (!list_ma_mh.is_exist(curr_ltc->maMH))
        list_ma_mh.push_back(curr_ltc->maMH);
      
      curr_malop = curr_malop->get_next();
    }
    current_sv = current_sv->get_next();
  }
  
  // Print
  
  /*************** Print title, fields ******************/
  box(current_window, 0, 0);
  int current_xcoord = 0;
  // Print title
  mvwprintw(current_window, 1, (current_table.get_width() - strlen(current_table.get_title())) / 2, current_table.get_title());
  mvwhline(current_window, 2, 1, 0, current_table.get_width() - 2);
  
  // Print fields
  int average_width = current_table.get_width() / (list_ma_mh.count() + 4);
  char * static_fields[] = {
    "STT",
    "MA SV",
    "HO TEN",
  };
  for (int i = 0; i < 3; i++) {
    mvwprintw(current_window, 3, current_xcoord + 1, static_fields[i]);
    current_xcoord += average_width + 1;

    mvwaddch(current_window, 2, current_xcoord, ACS_TTEE);
    mvwaddch(current_window, 3, current_xcoord, ACS_VLINE);
    mvwaddch(current_window, 4, current_xcoord, ACS_PLUS);
  }

  Node<char *> * current_ma_mh = list_ma_mh.p_head_;
  while (current_ma_mh != NULL) {
    mvwprintw(current_window, 3, current_xcoord + 1, current_ma_mh->get_data());
    current_xcoord += average_width + 1;

    mvwaddch(current_window, 2, current_xcoord, ACS_TTEE);
    mvwaddch(current_window, 3, current_xcoord, ACS_VLINE);
    mvwaddch(current_window, 4, current_xcoord, ACS_PLUS);

    current_ma_mh = current_ma_mh->get_next();
  }
  mvwprintw(current_window, 3, current_xcoord + 1, "Diem TB");
  mvwhline(current_window, 4, 1, 0, current_table.get_width() - 2);
  
  /******************** Print data ******************/
  int current_ycoord = 5;
  current_sv = current_dssv->head(); // make pointer to the head_node of current_DSSV because in loop to get list_mh the current sv had been changed
  while (current_sv != NULL) {
    SinhVien process_sv = current_sv->get_data();

    /**** render Code , Name , Family *****/

                    // \\ 
    /**** ___________________________ ****/

    Node<int> *  process_LTC_code = process_sv.DS_LOPTC->head();
    float process_avg = 0; // the avg score.
    // Loop in DSLTC   
    while(process_LTC_code != NULL){
      // get LOPTC by code
      LopTC * process = database.dsltc.
                                    get_by_id(database.dsltc.
                                                      search(process_LTC_code->get_data()));
      DanhSachSinhVienDK * process_ds = process->dsdk;
      Node<char *> * mh = list_ma_mh.head();
      bool find_mh=0; // Did process SV register each Subject in list_ma_mh which rendered on the title
      while(mh != NULL && !find_mh){
        if(strcmp(mh->get_data(), process->maMH) == 0)
          find_mh=1;
        mh = mh->get_next();
      }
      if(find_mh){
        Node<SinhVienDK> * tmp_svdk = process_ds->head();
        // Loop in DSDK which belong LTC to get score of SV in this LTC.
        while(tmp_svdk!=NULL){
          if(tmp_svdk->get_data().get_MASV() == process_sv.get_MASV()){
            
            /**** render the Score ( subject by subject) *****/

                    // \\ 

            /**** ___________________________ ****/
            
            process_avg+=tmp_svdk->get_data().get_DIEM();
            break; // end loop when found SV.
          }
          tmp_svdk = tmp_svdk->get_next();
        }        
        process_LTC_code = process_LTC_code ->get_next();
      }
      else{
        // do something
        current_ycoord += 2; // go through out of the field.
      }
      /**** render the AVG Score *****/

                    // \\ 

      /**** ___________________________ ****/
    current_ycoord += 2;
    current_sv = current_sv->get_next();
    }
  }
  wrefresh(current_window);
}
