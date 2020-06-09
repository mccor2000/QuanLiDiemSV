#pragma once

class Validator {
public:
  Validator() {;}

  bool validate_ltc(char **);
  bool validate_lcq(char **);
  bool validate_mh(char **);
  bool validate_sv(char **);
  bool validate_nhap_diem_1(char **);
  bool validate_nhap_diem_2(char **);
  bool validate_dang_ki_1(char **);
  bool validate_dang_ki_2(char **);
};
