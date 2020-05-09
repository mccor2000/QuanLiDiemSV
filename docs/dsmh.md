### Class DanhSachMonHoc  
# Khởi tạo: 
```c++
#include "library.h"
DanhSachMonHoc ds;
```

# Thêm môn học:
```c++
// Khởi tạo  
// MAMH: char[10], TENMH: char[50], STCLT: int, STCTH: int 
MonHoc new_mh(<MAMH>, <TENMH>, <STCLT>, <STCTH>);
// Thêm môn học 
ds.insert(new_mh);
```

# Tìm môn học:
```c++
MonHoc * mh = new MonHoc();
// Tìm theo tên
mh = ds.search_name(<ten_mh>);
// Tìm theo mã 
mh = ds.search_code(<ma_mh>);
```
# Xóa môn học: 
```c++
//...Tìm môn học:
ds.remove(mh);
```
# Duyệt ds môn học:
```c++
ds.enumerate();
```
